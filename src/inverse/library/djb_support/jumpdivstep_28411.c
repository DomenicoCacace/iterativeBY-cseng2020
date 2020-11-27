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

int jumpdivstep_28411(int n, int delta, int nf, DIGIT *f, DIGIT *g, DIGIT *t_00, DIGIT *t_01, DIGIT *t_10, DIGIT *t_11, float x) {
	DIGIT p_00[895];
	DIGIT p_01[895];
	DIGIT p_10[895];
	DIGIT p_11[895];
	
	DIGIT q_00[886];
	DIGIT q_01[886];
	DIGIT q_10[886];
	DIGIT q_11[886];
	
	DIGIT f_sum[2683];
	DIGIT g_sum[2683];
	
	DIGIT temp[1781];
	DIGIT temp2[1781];
	

	delta = divstepsx_256(255, delta, f+884, g+884, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f+880+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g+880+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+880+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g+880+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f+880+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g+880+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+880+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g+880+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f+872+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g+872+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f+872+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g+872+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f+872+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g+872+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f+872+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g+872+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f+860+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g+860+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f+860);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g+860);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f+860+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g+860+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f+860);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g+860);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(p_00+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, p_00+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+8, 8, p_00+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+4, 8, p_00+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+0, 8, p_00+839+0, 8, temp);
	memset(p_01+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, p_01+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+8, 8, p_01+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+4, 8, p_01+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+0, 8, p_01+839+0, 8, temp);
	memset(p_10+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, p_10+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+8, 8, p_10+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+4, 8, p_10+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+0, 8, p_10+839+0, 8, temp);
	memset(p_11+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, p_11+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+8, 8, p_11+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+4, 8, p_11+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+0, 8, p_11+839+0, 8, temp);
	

	// Calculating left operands: n: 3570, depth: 4
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f+832+28, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g+832+28, 28, p_01+839);
	gf2x_add(56, f_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f+832+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g+832+0, 28, p_01+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2514, 28, f_sum+2514, 28, temp+28);
	right_bit_shift_n(56, f_sum+2514, 57);
	GF2X_MUL(56, temp, 28, f+832+28, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g+832+28, 28, p_11+839);
	gf2x_add(56, g_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f+832+0, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g+832+0, 28, p_11+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2514, 28, g_sum+2514, 28, temp+28);
	right_bit_shift_n(56, g_sum+2514, 57);
	

	delta = divstepsx_256(255, delta, f_sum+2539, g_sum+2539, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, q_00+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+8, 8, q_00+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+4, 8, q_00+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+0, 8, q_00+834+0, 8, temp);
	memset(q_01+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, q_01+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+8, 8, q_01+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+4, 8, q_01+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+0, 8, q_01+834+0, 8, temp);
	memset(q_10+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, q_10+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+8, 8, q_10+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+4, 8, q_10+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+0, 8, q_10+834+0, 8, temp);
	memset(q_11+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, q_11+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+8, 8, q_11+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+4, 8, q_11+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+0, 8, q_11+834+0, 8, temp);
	

	// Recombining results: n: 3570, depth: 4
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_10+839);
	gf2x_add(56, p_00+783+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_11+839);
	gf2x_add(56, p_01+783+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_10+839);
	gf2x_add(56, p_10+783+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_11+839);
	gf2x_add(56, p_11+783+0, 56, temp, 56, temp2);
	

	// Calculating left operands: n: 7140, depth: 3
	// Digits to shift: 55
	// Displacement: 56
	GF2X_MUL(112, temp, 56, f+776+56, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, g+776+56, 56, p_01+783);
	gf2x_add(112, f_sum+2345+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, f+776+0, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, g+776+0, 56, p_01+783);
	gf2x_add(112, temp, 112, temp, 112, temp2);
	gf2x_add(56, f_sum+2345, 56, f_sum+2345, 56, temp+56);
	right_bit_shift_n(112, f_sum+2345, 50);
	GF2X_MUL(112, temp, 56, f+776+56, 56, p_10+783);
	GF2X_MUL(112, temp2, 56, g+776+56, 56, p_11+783);
	gf2x_add(112, g_sum+2345+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, f+776+0, 56, p_10+783);
	GF2X_MUL(112, temp2, 56, g+776+0, 56, p_11+783);
	gf2x_add(112, temp, 112, temp, 112, temp2);
	gf2x_add(56, g_sum+2345, 56, g_sum+2345, 56, temp+56);
	right_bit_shift_n(112, g_sum+2345, 50);
	

	delta = divstepsx_256(255, delta, f_sum+2398, g_sum+2398, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2394+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2394+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2394+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2394+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2386+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2386+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2386+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2386+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2374+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+2374+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+2374);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+2374);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+2374+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+2374+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+2374);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+2374);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(p_00+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, p_00+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+8, 8, p_00+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+4, 8, p_00+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+0, 8, p_00+839+0, 8, temp);
	memset(p_01+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, p_01+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+8, 8, p_01+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+4, 8, p_01+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+0, 8, p_01+839+0, 8, temp);
	memset(p_10+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, p_10+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+8, 8, p_10+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+4, 8, p_10+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+0, 8, p_10+839+0, 8, temp);
	memset(p_11+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, p_11+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+8, 8, p_11+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+4, 8, p_11+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+0, 8, p_11+839+0, 8, temp);
	

	// Calculating left operands: n: 3570, depth: 4
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+2346+28, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+28, 28, p_01+839);
	gf2x_add(56, f_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+2346+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+0, 28, p_01+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2514, 28, f_sum+2514, 28, temp+28);
	right_bit_shift_n(56, f_sum+2514, 57);
	GF2X_MUL(56, temp, 28, f_sum+2346+28, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+28, 28, p_11+839);
	gf2x_add(56, g_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+2346+0, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+0, 28, p_11+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2514, 28, g_sum+2514, 28, temp+28);
	right_bit_shift_n(56, g_sum+2514, 57);
	

	delta = divstepsx_256(255, delta, f_sum+2539, g_sum+2539, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, q_00+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+8, 8, q_00+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+4, 8, q_00+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+0, 8, q_00+834+0, 8, temp);
	memset(q_01+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, q_01+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+8, 8, q_01+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+4, 8, q_01+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+0, 8, q_01+834+0, 8, temp);
	memset(q_10+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, q_10+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+8, 8, q_10+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+4, 8, q_10+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+0, 8, q_10+834+0, 8, temp);
	memset(q_11+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, q_11+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+8, 8, q_11+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+4, 8, q_11+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+0, 8, q_11+834+0, 8, temp);
	

	// Recombining results: n: 3570, depth: 4
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_10+839);
	gf2x_add(56, q_00+778+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_11+839);
	gf2x_add(56, q_01+778+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_10+839);
	gf2x_add(56, q_10+778+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_11+839);
	gf2x_add(56, q_11+778+0, 56, temp, 56, temp2);
	

	// Recombining results: n: 7140, depth: 3
	GF2X_MUL(112, temp, 56, q_00+778+0, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, q_01+778+0, 56, p_10+783);
	gf2x_add(112, p_00+671+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, q_00+778+0, 56, p_01+783);
	GF2X_MUL(112, temp2, 56, q_01+778+0, 56, p_11+783);
	gf2x_add(112, p_01+671+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, q_10+778+0, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, q_11+778+0, 56, p_10+783);
	gf2x_add(112, p_10+671+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, q_10+778+0, 56, p_01+783);
	GF2X_MUL(112, temp2, 56, q_11+778+0, 56, p_11+783);
	gf2x_add(112, p_11+671+0, 112, temp, 112, temp2);
	

	// Calculating left operands: n: 14280, depth: 2
	// Digits to shift: 111
	// Displacement: 112
	GF2X_MUL(224, temp, 112, f+664+112, 112, p_00+671);
	GF2X_MUL(224, temp2, 112, g+664+112, 112, p_01+671);
	gf2x_add(224, f_sum+2008+0, 224, temp, 224, temp2);
	GF2X_MUL(224, temp, 112, f+664+0, 112, p_00+671);
	GF2X_MUL(224, temp2, 112, g+664+0, 112, p_01+671);
	gf2x_add(224, temp, 224, temp, 224, temp2);
	gf2x_add(112, f_sum+2008, 112, f_sum+2008, 112, temp+112);
	right_bit_shift_n(224, f_sum+2008, 36);
	GF2X_MUL(224, temp, 112, f+664+112, 112, p_10+671);
	GF2X_MUL(224, temp2, 112, g+664+112, 112, p_11+671);
	gf2x_add(224, g_sum+2008+0, 224, temp, 224, temp2);
	GF2X_MUL(224, temp, 112, f+664+0, 112, p_10+671);
	GF2X_MUL(224, temp2, 112, g+664+0, 112, p_11+671);
	gf2x_add(224, temp, 224, temp, 224, temp2);
	gf2x_add(112, g_sum+2008, 112, g_sum+2008, 112, temp+112);
	right_bit_shift_n(224, g_sum+2008, 36);
	

	delta = divstepsx_256(255, delta, f_sum+2117, g_sum+2117, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2113+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2113+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2113+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2113+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2113+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2113+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2113+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2113+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2105+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2105+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2105+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2105+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2105+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2105+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2105+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2105+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2093+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+2093+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+2093);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+2093);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+2093+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+2093+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+2093);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+2093);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(p_00+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, p_00+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+8, 8, p_00+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+4, 8, p_00+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+0, 8, p_00+839+0, 8, temp);
	memset(p_01+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, p_01+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+8, 8, p_01+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+4, 8, p_01+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+0, 8, p_01+839+0, 8, temp);
	memset(p_10+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, p_10+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+8, 8, p_10+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+4, 8, p_10+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+0, 8, p_10+839+0, 8, temp);
	memset(p_11+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, p_11+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+8, 8, p_11+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+4, 8, p_11+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+0, 8, p_11+839+0, 8, temp);
	

	// Calculating left operands: n: 3570, depth: 4
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+2065+28, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+2065+28, 28, p_01+839);
	gf2x_add(56, f_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+2065+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+2065+0, 28, p_01+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2514, 28, f_sum+2514, 28, temp+28);
	right_bit_shift_n(56, f_sum+2514, 57);
	GF2X_MUL(56, temp, 28, f_sum+2065+28, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+2065+28, 28, p_11+839);
	gf2x_add(56, g_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+2065+0, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+2065+0, 28, p_11+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2514, 28, g_sum+2514, 28, temp+28);
	right_bit_shift_n(56, g_sum+2514, 57);
	

	delta = divstepsx_256(255, delta, f_sum+2539, g_sum+2539, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, q_00+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+8, 8, q_00+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+4, 8, q_00+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+0, 8, q_00+834+0, 8, temp);
	memset(q_01+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, q_01+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+8, 8, q_01+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+4, 8, q_01+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+0, 8, q_01+834+0, 8, temp);
	memset(q_10+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, q_10+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+8, 8, q_10+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+4, 8, q_10+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+0, 8, q_10+834+0, 8, temp);
	memset(q_11+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, q_11+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+8, 8, q_11+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+4, 8, q_11+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+0, 8, q_11+834+0, 8, temp);
	

	// Recombining results: n: 3570, depth: 4
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_10+839);
	gf2x_add(56, p_00+783+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_11+839);
	gf2x_add(56, p_01+783+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_10+839);
	gf2x_add(56, p_10+783+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_11+839);
	gf2x_add(56, p_11+783+0, 56, temp, 56, temp2);
	

	// Calculating left operands: n: 7140, depth: 3
	// Digits to shift: 55
	// Displacement: 56
	GF2X_MUL(112, temp, 56, f_sum+2009+56, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, g_sum+2009+56, 56, p_01+783);
	gf2x_add(112, f_sum+2345+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, f_sum+2009+0, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, g_sum+2009+0, 56, p_01+783);
	gf2x_add(112, temp, 112, temp, 112, temp2);
	gf2x_add(56, f_sum+2345, 56, f_sum+2345, 56, temp+56);
	right_bit_shift_n(112, f_sum+2345, 50);
	GF2X_MUL(112, temp, 56, f_sum+2009+56, 56, p_10+783);
	GF2X_MUL(112, temp2, 56, g_sum+2009+56, 56, p_11+783);
	gf2x_add(112, g_sum+2345+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, f_sum+2009+0, 56, p_10+783);
	GF2X_MUL(112, temp2, 56, g_sum+2009+0, 56, p_11+783);
	gf2x_add(112, temp, 112, temp, 112, temp2);
	gf2x_add(56, g_sum+2345, 56, g_sum+2345, 56, temp+56);
	right_bit_shift_n(112, g_sum+2345, 50);
	

	delta = divstepsx_256(255, delta, f_sum+2398, g_sum+2398, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2394+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2394+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2394+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2394+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2386+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2386+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2386+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2386+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2374+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+2374+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+2374);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+2374);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+2374+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+2374+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+2374);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+2374);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(p_00+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, p_00+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+8, 8, p_00+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+4, 8, p_00+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+0, 8, p_00+839+0, 8, temp);
	memset(p_01+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, p_01+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+8, 8, p_01+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+4, 8, p_01+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+0, 8, p_01+839+0, 8, temp);
	memset(p_10+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, p_10+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+8, 8, p_10+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+4, 8, p_10+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+0, 8, p_10+839+0, 8, temp);
	memset(p_11+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, p_11+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+8, 8, p_11+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+4, 8, p_11+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+0, 8, p_11+839+0, 8, temp);
	

	// Calculating left operands: n: 3570, depth: 4
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+2346+28, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+28, 28, p_01+839);
	gf2x_add(56, f_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+2346+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+0, 28, p_01+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2514, 28, f_sum+2514, 28, temp+28);
	right_bit_shift_n(56, f_sum+2514, 57);
	GF2X_MUL(56, temp, 28, f_sum+2346+28, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+28, 28, p_11+839);
	gf2x_add(56, g_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+2346+0, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+0, 28, p_11+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2514, 28, g_sum+2514, 28, temp+28);
	right_bit_shift_n(56, g_sum+2514, 57);
	

	delta = divstepsx_256(255, delta, f_sum+2539, g_sum+2539, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, q_00+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+8, 8, q_00+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+4, 8, q_00+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+0, 8, q_00+834+0, 8, temp);
	memset(q_01+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, q_01+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+8, 8, q_01+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+4, 8, q_01+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+0, 8, q_01+834+0, 8, temp);
	memset(q_10+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, q_10+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+8, 8, q_10+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+4, 8, q_10+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+0, 8, q_10+834+0, 8, temp);
	memset(q_11+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, q_11+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+8, 8, q_11+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+4, 8, q_11+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+0, 8, q_11+834+0, 8, temp);
	

	// Recombining results: n: 3570, depth: 4
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_10+839);
	gf2x_add(56, q_00+778+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_11+839);
	gf2x_add(56, q_01+778+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_10+839);
	gf2x_add(56, q_10+778+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_11+839);
	gf2x_add(56, q_11+778+0, 56, temp, 56, temp2);
	

	// Recombining results: n: 7140, depth: 3
	GF2X_MUL(112, temp, 56, q_00+778+0, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, q_01+778+0, 56, p_10+783);
	gf2x_add(112, q_00+666+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, q_00+778+0, 56, p_01+783);
	GF2X_MUL(112, temp2, 56, q_01+778+0, 56, p_11+783);
	gf2x_add(112, q_01+666+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, q_10+778+0, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, q_11+778+0, 56, p_10+783);
	gf2x_add(112, q_10+666+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, q_10+778+0, 56, p_01+783);
	GF2X_MUL(112, temp2, 56, q_11+778+0, 56, p_11+783);
	gf2x_add(112, q_11+666+0, 112, temp, 112, temp2);
	

	// Recombining results: n: 14280, depth: 2
	GF2X_MUL(224, temp, 112, q_00+666+0, 112, p_00+671);
	GF2X_MUL(224, temp2, 112, q_01+666+0, 112, p_10+671);
	gf2x_add(224, p_00+447+0, 224, temp, 224, temp2);
	GF2X_MUL(224, temp, 112, q_00+666+0, 112, p_01+671);
	GF2X_MUL(224, temp2, 112, q_01+666+0, 112, p_11+671);
	gf2x_add(224, p_01+447+0, 224, temp, 224, temp2);
	GF2X_MUL(224, temp, 112, q_10+666+0, 112, p_00+671);
	GF2X_MUL(224, temp2, 112, q_11+666+0, 112, p_10+671);
	gf2x_add(224, p_10+447+0, 224, temp, 224, temp2);
	GF2X_MUL(224, temp, 112, q_10+666+0, 112, p_01+671);
	GF2X_MUL(224, temp2, 112, q_11+666+0, 112, p_11+671);
	gf2x_add(224, p_11+447+0, 224, temp, 224, temp2);
	

	// Calculating left operands: n: 28560, depth: 1
	// Digits to shift: 223
	// Displacement: 223
	GF2X_MUL(448, temp, 224, f+441+223, 224, p_00+447);
	GF2X_MUL(448, temp2, 224, g+441+223, 224, p_01+447);
	gf2x_add(448, f_sum+1336+0, 448, temp, 448, temp2);
	GF2X_MUL(446, temp, 223, p_00+447+1, 223, f+441);
	GF2X_MUL(446, temp2, 223, p_01+447+1, 223, g+441);
	gf2x_add(446, temp, 446, temp, 446, temp2);
	gf2x_add(224, f_sum+1336, 224, f_sum+1336, 224, temp+222);
	GF2X_MUL(2, temp, 1, f+441+222, 1, p_00+447);
	GF2X_MUL(2, temp2, 1, g+441+222, 1, p_01+447);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, f_sum+1336, 1, f_sum+1336, 1, temp+1);
	right_bit_shift_n(447, f_sum+1336, 8);
	GF2X_MUL(448, temp, 224, f+441+223, 224, p_10+447);
	GF2X_MUL(448, temp2, 224, g+441+223, 224, p_11+447);
	gf2x_add(448, g_sum+1336+0, 448, temp, 448, temp2);
	GF2X_MUL(446, temp, 223, p_10+447+1, 223, f+441);
	GF2X_MUL(446, temp2, 223, p_11+447+1, 223, g+441);
	gf2x_add(446, temp, 446, temp, 446, temp2);
	gf2x_add(224, g_sum+1336, 224, g_sum+1336, 224, temp+222);
	GF2X_MUL(2, temp, 1, f+441+222, 1, p_10+447);
	GF2X_MUL(2, temp2, 1, g+441+222, 1, p_11+447);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, g_sum+1336, 1, g_sum+1336, 1, temp+1);
	right_bit_shift_n(447, g_sum+1336, 8);
	

	delta = divstepsx_256(255, delta, f_sum+1557, g_sum+1557, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1553+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+1553+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1553+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+1553+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+1553+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+1553+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1553+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+1553+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1545+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+1545+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1545+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+1545+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+1545+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+1545+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1545+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+1545+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1533+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+1533+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+1533);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+1533);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+1533+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+1533+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+1533);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+1533);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(p_00+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, p_00+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+8, 8, p_00+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+4, 8, p_00+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+0, 8, p_00+839+0, 8, temp);
	memset(p_01+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, p_01+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+8, 8, p_01+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+4, 8, p_01+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+0, 8, p_01+839+0, 8, temp);
	memset(p_10+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, p_10+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+8, 8, p_10+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+4, 8, p_10+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+0, 8, p_10+839+0, 8, temp);
	memset(p_11+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, p_11+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+8, 8, p_11+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+4, 8, p_11+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+0, 8, p_11+839+0, 8, temp);
	

	// Calculating left operands: n: 3570, depth: 4
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+1505+28, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+1505+28, 28, p_01+839);
	gf2x_add(56, f_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+1505+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+1505+0, 28, p_01+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2514, 28, f_sum+2514, 28, temp+28);
	right_bit_shift_n(56, f_sum+2514, 57);
	GF2X_MUL(56, temp, 28, f_sum+1505+28, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+1505+28, 28, p_11+839);
	gf2x_add(56, g_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+1505+0, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+1505+0, 28, p_11+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2514, 28, g_sum+2514, 28, temp+28);
	right_bit_shift_n(56, g_sum+2514, 57);
	

	delta = divstepsx_256(255, delta, f_sum+2539, g_sum+2539, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, q_00+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+8, 8, q_00+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+4, 8, q_00+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+0, 8, q_00+834+0, 8, temp);
	memset(q_01+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, q_01+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+8, 8, q_01+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+4, 8, q_01+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+0, 8, q_01+834+0, 8, temp);
	memset(q_10+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, q_10+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+8, 8, q_10+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+4, 8, q_10+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+0, 8, q_10+834+0, 8, temp);
	memset(q_11+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, q_11+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+8, 8, q_11+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+4, 8, q_11+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+0, 8, q_11+834+0, 8, temp);
	

	// Recombining results: n: 3570, depth: 4
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_10+839);
	gf2x_add(56, p_00+783+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_11+839);
	gf2x_add(56, p_01+783+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_10+839);
	gf2x_add(56, p_10+783+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_11+839);
	gf2x_add(56, p_11+783+0, 56, temp, 56, temp2);
	

	// Calculating left operands: n: 7140, depth: 3
	// Digits to shift: 55
	// Displacement: 56
	GF2X_MUL(112, temp, 56, f_sum+1449+56, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, g_sum+1449+56, 56, p_01+783);
	gf2x_add(112, f_sum+2345+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, f_sum+1449+0, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, g_sum+1449+0, 56, p_01+783);
	gf2x_add(112, temp, 112, temp, 112, temp2);
	gf2x_add(56, f_sum+2345, 56, f_sum+2345, 56, temp+56);
	right_bit_shift_n(112, f_sum+2345, 50);
	GF2X_MUL(112, temp, 56, f_sum+1449+56, 56, p_10+783);
	GF2X_MUL(112, temp2, 56, g_sum+1449+56, 56, p_11+783);
	gf2x_add(112, g_sum+2345+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, f_sum+1449+0, 56, p_10+783);
	GF2X_MUL(112, temp2, 56, g_sum+1449+0, 56, p_11+783);
	gf2x_add(112, temp, 112, temp, 112, temp2);
	gf2x_add(56, g_sum+2345, 56, g_sum+2345, 56, temp+56);
	right_bit_shift_n(112, g_sum+2345, 50);
	

	delta = divstepsx_256(255, delta, f_sum+2398, g_sum+2398, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2394+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2394+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2394+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2394+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2386+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2386+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2386+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2386+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2374+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+2374+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+2374);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+2374);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+2374+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+2374+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+2374);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+2374);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(p_00+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, p_00+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+8, 8, p_00+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+4, 8, p_00+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+0, 8, p_00+839+0, 8, temp);
	memset(p_01+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, p_01+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+8, 8, p_01+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+4, 8, p_01+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+0, 8, p_01+839+0, 8, temp);
	memset(p_10+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, p_10+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+8, 8, p_10+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+4, 8, p_10+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+0, 8, p_10+839+0, 8, temp);
	memset(p_11+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, p_11+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+8, 8, p_11+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+4, 8, p_11+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+0, 8, p_11+839+0, 8, temp);
	

	// Calculating left operands: n: 3570, depth: 4
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+2346+28, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+28, 28, p_01+839);
	gf2x_add(56, f_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+2346+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+0, 28, p_01+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2514, 28, f_sum+2514, 28, temp+28);
	right_bit_shift_n(56, f_sum+2514, 57);
	GF2X_MUL(56, temp, 28, f_sum+2346+28, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+28, 28, p_11+839);
	gf2x_add(56, g_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+2346+0, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+0, 28, p_11+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2514, 28, g_sum+2514, 28, temp+28);
	right_bit_shift_n(56, g_sum+2514, 57);
	

	delta = divstepsx_256(255, delta, f_sum+2539, g_sum+2539, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, q_00+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+8, 8, q_00+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+4, 8, q_00+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+0, 8, q_00+834+0, 8, temp);
	memset(q_01+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, q_01+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+8, 8, q_01+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+4, 8, q_01+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+0, 8, q_01+834+0, 8, temp);
	memset(q_10+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, q_10+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+8, 8, q_10+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+4, 8, q_10+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+0, 8, q_10+834+0, 8, temp);
	memset(q_11+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, q_11+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+8, 8, q_11+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+4, 8, q_11+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+0, 8, q_11+834+0, 8, temp);
	

	// Recombining results: n: 3570, depth: 4
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_10+839);
	gf2x_add(56, q_00+778+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_11+839);
	gf2x_add(56, q_01+778+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_10+839);
	gf2x_add(56, q_10+778+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_11+839);
	gf2x_add(56, q_11+778+0, 56, temp, 56, temp2);
	

	// Recombining results: n: 7140, depth: 3
	GF2X_MUL(112, temp, 56, q_00+778+0, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, q_01+778+0, 56, p_10+783);
	gf2x_add(112, p_00+671+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, q_00+778+0, 56, p_01+783);
	GF2X_MUL(112, temp2, 56, q_01+778+0, 56, p_11+783);
	gf2x_add(112, p_01+671+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, q_10+778+0, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, q_11+778+0, 56, p_10+783);
	gf2x_add(112, p_10+671+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, q_10+778+0, 56, p_01+783);
	GF2X_MUL(112, temp2, 56, q_11+778+0, 56, p_11+783);
	gf2x_add(112, p_11+671+0, 112, temp, 112, temp2);
	

	// Calculating left operands: n: 14280, depth: 2
	// Digits to shift: 111
	// Displacement: 112
	GF2X_MUL(224, temp, 112, f_sum+1337+112, 112, p_00+671);
	GF2X_MUL(224, temp2, 112, g_sum+1337+112, 112, p_01+671);
	gf2x_add(224, f_sum+2008+0, 224, temp, 224, temp2);
	GF2X_MUL(224, temp, 112, f_sum+1337+0, 112, p_00+671);
	GF2X_MUL(224, temp2, 112, g_sum+1337+0, 112, p_01+671);
	gf2x_add(224, temp, 224, temp, 224, temp2);
	gf2x_add(112, f_sum+2008, 112, f_sum+2008, 112, temp+112);
	right_bit_shift_n(224, f_sum+2008, 36);
	GF2X_MUL(224, temp, 112, f_sum+1337+112, 112, p_10+671);
	GF2X_MUL(224, temp2, 112, g_sum+1337+112, 112, p_11+671);
	gf2x_add(224, g_sum+2008+0, 224, temp, 224, temp2);
	GF2X_MUL(224, temp, 112, f_sum+1337+0, 112, p_10+671);
	GF2X_MUL(224, temp2, 112, g_sum+1337+0, 112, p_11+671);
	gf2x_add(224, temp, 224, temp, 224, temp2);
	gf2x_add(112, g_sum+2008, 112, g_sum+2008, 112, temp+112);
	right_bit_shift_n(224, g_sum+2008, 36);
	

	delta = divstepsx_256(255, delta, f_sum+2117, g_sum+2117, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2113+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2113+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2113+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2113+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2113+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2113+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2113+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2113+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2105+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2105+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2105+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2105+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2105+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2105+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2105+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2105+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2093+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+2093+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+2093);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+2093);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+2093+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+2093+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+2093);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+2093);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(p_00+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, p_00+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+8, 8, p_00+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+4, 8, p_00+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+0, 8, p_00+839+0, 8, temp);
	memset(p_01+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, p_01+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+8, 8, p_01+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+4, 8, p_01+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+0, 8, p_01+839+0, 8, temp);
	memset(p_10+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, p_10+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+8, 8, p_10+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+4, 8, p_10+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+0, 8, p_10+839+0, 8, temp);
	memset(p_11+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, p_11+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+8, 8, p_11+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+4, 8, p_11+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+0, 8, p_11+839+0, 8, temp);
	

	// Calculating left operands: n: 3570, depth: 4
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+2065+28, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+2065+28, 28, p_01+839);
	gf2x_add(56, f_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+2065+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+2065+0, 28, p_01+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2514, 28, f_sum+2514, 28, temp+28);
	right_bit_shift_n(56, f_sum+2514, 57);
	GF2X_MUL(56, temp, 28, f_sum+2065+28, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+2065+28, 28, p_11+839);
	gf2x_add(56, g_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+2065+0, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+2065+0, 28, p_11+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2514, 28, g_sum+2514, 28, temp+28);
	right_bit_shift_n(56, g_sum+2514, 57);
	

	delta = divstepsx_256(255, delta, f_sum+2539, g_sum+2539, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, q_00+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+8, 8, q_00+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+4, 8, q_00+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+0, 8, q_00+834+0, 8, temp);
	memset(q_01+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, q_01+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+8, 8, q_01+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+4, 8, q_01+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+0, 8, q_01+834+0, 8, temp);
	memset(q_10+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, q_10+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+8, 8, q_10+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+4, 8, q_10+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+0, 8, q_10+834+0, 8, temp);
	memset(q_11+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, q_11+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+8, 8, q_11+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+4, 8, q_11+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+0, 8, q_11+834+0, 8, temp);
	

	// Recombining results: n: 3570, depth: 4
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_10+839);
	gf2x_add(56, p_00+783+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_11+839);
	gf2x_add(56, p_01+783+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_10+839);
	gf2x_add(56, p_10+783+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_11+839);
	gf2x_add(56, p_11+783+0, 56, temp, 56, temp2);
	

	// Calculating left operands: n: 7140, depth: 3
	// Digits to shift: 55
	// Displacement: 56
	GF2X_MUL(112, temp, 56, f_sum+2009+56, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, g_sum+2009+56, 56, p_01+783);
	gf2x_add(112, f_sum+2345+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, f_sum+2009+0, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, g_sum+2009+0, 56, p_01+783);
	gf2x_add(112, temp, 112, temp, 112, temp2);
	gf2x_add(56, f_sum+2345, 56, f_sum+2345, 56, temp+56);
	right_bit_shift_n(112, f_sum+2345, 50);
	GF2X_MUL(112, temp, 56, f_sum+2009+56, 56, p_10+783);
	GF2X_MUL(112, temp2, 56, g_sum+2009+56, 56, p_11+783);
	gf2x_add(112, g_sum+2345+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, f_sum+2009+0, 56, p_10+783);
	GF2X_MUL(112, temp2, 56, g_sum+2009+0, 56, p_11+783);
	gf2x_add(112, temp, 112, temp, 112, temp2);
	gf2x_add(56, g_sum+2345, 56, g_sum+2345, 56, temp+56);
	right_bit_shift_n(112, g_sum+2345, 50);
	

	delta = divstepsx_256(255, delta, f_sum+2398, g_sum+2398, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2394+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2394+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2394+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2394+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2386+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2386+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2386+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2386+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2374+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+2374+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+2374);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+2374);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+2374+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+2374+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+2374);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+2374);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(p_00+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, p_00+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+8, 8, p_00+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+4, 8, p_00+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+0, 8, p_00+839+0, 8, temp);
	memset(p_01+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, p_01+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+8, 8, p_01+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+4, 8, p_01+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+0, 8, p_01+839+0, 8, temp);
	memset(p_10+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, p_10+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+8, 8, p_10+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+4, 8, p_10+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+0, 8, p_10+839+0, 8, temp);
	memset(p_11+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, p_11+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+8, 8, p_11+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+4, 8, p_11+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+0, 8, p_11+839+0, 8, temp);
	

	// Calculating left operands: n: 3570, depth: 4
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+2346+28, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+28, 28, p_01+839);
	gf2x_add(56, f_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+2346+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+0, 28, p_01+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2514, 28, f_sum+2514, 28, temp+28);
	right_bit_shift_n(56, f_sum+2514, 57);
	GF2X_MUL(56, temp, 28, f_sum+2346+28, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+28, 28, p_11+839);
	gf2x_add(56, g_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+2346+0, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+0, 28, p_11+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2514, 28, g_sum+2514, 28, temp+28);
	right_bit_shift_n(56, g_sum+2514, 57);
	

	delta = divstepsx_256(255, delta, f_sum+2539, g_sum+2539, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, q_00+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+8, 8, q_00+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+4, 8, q_00+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+0, 8, q_00+834+0, 8, temp);
	memset(q_01+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, q_01+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+8, 8, q_01+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+4, 8, q_01+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+0, 8, q_01+834+0, 8, temp);
	memset(q_10+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, q_10+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+8, 8, q_10+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+4, 8, q_10+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+0, 8, q_10+834+0, 8, temp);
	memset(q_11+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, q_11+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+8, 8, q_11+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+4, 8, q_11+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+0, 8, q_11+834+0, 8, temp);
	

	// Recombining results: n: 3570, depth: 4
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_10+839);
	gf2x_add(56, q_00+778+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_11+839);
	gf2x_add(56, q_01+778+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_10+839);
	gf2x_add(56, q_10+778+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_11+839);
	gf2x_add(56, q_11+778+0, 56, temp, 56, temp2);
	

	// Recombining results: n: 7140, depth: 3
	GF2X_MUL(112, temp, 56, q_00+778+0, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, q_01+778+0, 56, p_10+783);
	gf2x_add(112, q_00+666+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, q_00+778+0, 56, p_01+783);
	GF2X_MUL(112, temp2, 56, q_01+778+0, 56, p_11+783);
	gf2x_add(112, q_01+666+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, q_10+778+0, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, q_11+778+0, 56, p_10+783);
	gf2x_add(112, q_10+666+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, q_10+778+0, 56, p_01+783);
	GF2X_MUL(112, temp2, 56, q_11+778+0, 56, p_11+783);
	gf2x_add(112, q_11+666+0, 112, temp, 112, temp2);
	

	// Recombining results: n: 14280, depth: 2
	GF2X_MUL(224, temp, 112, q_00+666+0, 112, p_00+671);
	GF2X_MUL(224, temp2, 112, q_01+666+0, 112, p_10+671);
	gf2x_add(224, q_00+442+0, 224, temp, 224, temp2);
	GF2X_MUL(224, temp, 112, q_00+666+0, 112, p_01+671);
	GF2X_MUL(224, temp2, 112, q_01+666+0, 112, p_11+671);
	gf2x_add(224, q_01+442+0, 224, temp, 224, temp2);
	GF2X_MUL(224, temp, 112, q_10+666+0, 112, p_00+671);
	GF2X_MUL(224, temp2, 112, q_11+666+0, 112, p_10+671);
	gf2x_add(224, q_10+442+0, 224, temp, 224, temp2);
	GF2X_MUL(224, temp, 112, q_10+666+0, 112, p_01+671);
	GF2X_MUL(224, temp2, 112, q_11+666+0, 112, p_11+671);
	gf2x_add(224, q_11+442+0, 224, temp, 224, temp2);
	

	// Recombining results: n: 28560, depth: 1
	GF2X_MUL(448, temp, 224, q_00+442+0, 224, p_00+447);
	GF2X_MUL(448, temp2, 224, q_01+442+0, 224, p_10+447);
	gf2x_add(447, p_00+0, 447, temp+1, 447, temp2+1);
	GF2X_MUL(448, temp, 224, q_00+442+0, 224, p_01+447);
	GF2X_MUL(448, temp2, 224, q_01+442+0, 224, p_11+447);
	gf2x_add(447, p_01+0, 447, temp+1, 447, temp2+1);
	GF2X_MUL(448, temp, 224, q_10+442+0, 224, p_00+447);
	GF2X_MUL(448, temp2, 224, q_11+442+0, 224, p_10+447);
	gf2x_add(447, p_10+0, 447, temp+1, 447, temp2+1);
	GF2X_MUL(448, temp, 224, q_10+442+0, 224, p_01+447);
	GF2X_MUL(448, temp2, 224, q_11+442+0, 224, p_11+447);
	gf2x_add(447, p_11+0, 447, temp+1, 447, temp2+1);
	

	// Calculating left operands: n: 56821, depth: 0
	// Digits to shift: 446
	// Displacement: 446
	GF2X_MUL(894, temp, 447, f+0+441, 447, p_00+0);
	GF2X_MUL(894, temp2, 447, g+0+441, 447, p_01+0);
	gf2x_add(889, f_sum+0, 889, temp+5, 889, temp2+5);
	GF2X_MUL(882, temp, 441, p_00+0+6, 441, f+0);
	GF2X_MUL(882, temp2, 441, p_01+0+6, 441, g+0);
	gf2x_add(882, temp, 882, temp, 882, temp2);
	gf2x_add(442, f_sum+0, 442, f_sum+0, 442, temp+440);
	GF2X_MUL(12, temp, 6, f+0+435, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, g+0+435, 6, p_01+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(1, f_sum+0, 1, f_sum+0, 1, temp+11);
	right_bit_shift_n(888, f_sum+0, 16);
	GF2X_MUL(894, temp, 447, f+0+441, 447, p_10+0);
	GF2X_MUL(894, temp2, 447, g+0+441, 447, p_11+0);
	gf2x_add(889, g_sum+0, 889, temp+5, 889, temp2+5);
	GF2X_MUL(882, temp, 441, p_10+0+6, 441, f+0);
	GF2X_MUL(882, temp2, 441, p_11+0+6, 441, g+0);
	gf2x_add(882, temp, 882, temp, 882, temp2);
	gf2x_add(442, g_sum+0, 442, g_sum+0, 442, temp+440);
	GF2X_MUL(12, temp, 6, f+0+435, 6, p_10+0);
	GF2X_MUL(12, temp2, 6, g+0+435, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(1, g_sum+0, 1, g_sum+0, 1, temp+11);
	right_bit_shift_n(888, g_sum+0, 16);
	

	delta = divstepsx_256(255, delta, f_sum+439, g_sum+439, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+435+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+435+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+435+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+435+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+435+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+435+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+435+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+435+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+427+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+427+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+427+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+427+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+427+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+427+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+427+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+427+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+415+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+415+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+415);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+415);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+415+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+415+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+415);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+415);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(p_00+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, p_00+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+8, 8, p_00+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+4, 8, p_00+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+0, 8, p_00+839+0, 8, temp);
	memset(p_01+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, p_01+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+8, 8, p_01+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+4, 8, p_01+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+0, 8, p_01+839+0, 8, temp);
	memset(p_10+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, p_10+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+8, 8, p_10+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+4, 8, p_10+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+0, 8, p_10+839+0, 8, temp);
	memset(p_11+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, p_11+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+8, 8, p_11+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+4, 8, p_11+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+0, 8, p_11+839+0, 8, temp);
	

	// Calculating left operands: n: 3570, depth: 4
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+387+28, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+387+28, 28, p_01+839);
	gf2x_add(56, f_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+387+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+387+0, 28, p_01+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2514, 28, f_sum+2514, 28, temp+28);
	right_bit_shift_n(56, f_sum+2514, 57);
	GF2X_MUL(56, temp, 28, f_sum+387+28, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+387+28, 28, p_11+839);
	gf2x_add(56, g_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+387+0, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+387+0, 28, p_11+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2514, 28, g_sum+2514, 28, temp+28);
	right_bit_shift_n(56, g_sum+2514, 57);
	

	delta = divstepsx_256(255, delta, f_sum+2539, g_sum+2539, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, q_00+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+8, 8, q_00+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+4, 8, q_00+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+0, 8, q_00+834+0, 8, temp);
	memset(q_01+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, q_01+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+8, 8, q_01+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+4, 8, q_01+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+0, 8, q_01+834+0, 8, temp);
	memset(q_10+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, q_10+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+8, 8, q_10+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+4, 8, q_10+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+0, 8, q_10+834+0, 8, temp);
	memset(q_11+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, q_11+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+8, 8, q_11+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+4, 8, q_11+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+0, 8, q_11+834+0, 8, temp);
	

	// Recombining results: n: 3570, depth: 4
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_10+839);
	gf2x_add(56, p_00+783+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_11+839);
	gf2x_add(56, p_01+783+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_10+839);
	gf2x_add(56, p_10+783+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_11+839);
	gf2x_add(56, p_11+783+0, 56, temp, 56, temp2);
	

	// Calculating left operands: n: 7140, depth: 3
	// Digits to shift: 55
	// Displacement: 56
	GF2X_MUL(112, temp, 56, f_sum+331+56, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, g_sum+331+56, 56, p_01+783);
	gf2x_add(112, f_sum+2345+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, f_sum+331+0, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, g_sum+331+0, 56, p_01+783);
	gf2x_add(112, temp, 112, temp, 112, temp2);
	gf2x_add(56, f_sum+2345, 56, f_sum+2345, 56, temp+56);
	right_bit_shift_n(112, f_sum+2345, 50);
	GF2X_MUL(112, temp, 56, f_sum+331+56, 56, p_10+783);
	GF2X_MUL(112, temp2, 56, g_sum+331+56, 56, p_11+783);
	gf2x_add(112, g_sum+2345+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, f_sum+331+0, 56, p_10+783);
	GF2X_MUL(112, temp2, 56, g_sum+331+0, 56, p_11+783);
	gf2x_add(112, temp, 112, temp, 112, temp2);
	gf2x_add(56, g_sum+2345, 56, g_sum+2345, 56, temp+56);
	right_bit_shift_n(112, g_sum+2345, 50);
	

	delta = divstepsx_256(255, delta, f_sum+2398, g_sum+2398, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2394+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2394+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2394+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2394+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2386+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2386+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2386+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2386+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2374+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+2374+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+2374);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+2374);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+2374+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+2374+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+2374);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+2374);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(p_00+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, p_00+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+8, 8, p_00+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+4, 8, p_00+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+0, 8, p_00+839+0, 8, temp);
	memset(p_01+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, p_01+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+8, 8, p_01+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+4, 8, p_01+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+0, 8, p_01+839+0, 8, temp);
	memset(p_10+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, p_10+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+8, 8, p_10+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+4, 8, p_10+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+0, 8, p_10+839+0, 8, temp);
	memset(p_11+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, p_11+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+8, 8, p_11+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+4, 8, p_11+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+0, 8, p_11+839+0, 8, temp);
	

	// Calculating left operands: n: 3570, depth: 4
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+2346+28, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+28, 28, p_01+839);
	gf2x_add(56, f_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+2346+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+0, 28, p_01+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2514, 28, f_sum+2514, 28, temp+28);
	right_bit_shift_n(56, f_sum+2514, 57);
	GF2X_MUL(56, temp, 28, f_sum+2346+28, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+28, 28, p_11+839);
	gf2x_add(56, g_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+2346+0, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+0, 28, p_11+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2514, 28, g_sum+2514, 28, temp+28);
	right_bit_shift_n(56, g_sum+2514, 57);
	

	delta = divstepsx_256(255, delta, f_sum+2539, g_sum+2539, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, q_00+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+8, 8, q_00+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+4, 8, q_00+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+0, 8, q_00+834+0, 8, temp);
	memset(q_01+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, q_01+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+8, 8, q_01+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+4, 8, q_01+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+0, 8, q_01+834+0, 8, temp);
	memset(q_10+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, q_10+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+8, 8, q_10+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+4, 8, q_10+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+0, 8, q_10+834+0, 8, temp);
	memset(q_11+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, q_11+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+8, 8, q_11+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+4, 8, q_11+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+0, 8, q_11+834+0, 8, temp);
	

	// Recombining results: n: 3570, depth: 4
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_10+839);
	gf2x_add(56, q_00+778+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_11+839);
	gf2x_add(56, q_01+778+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_10+839);
	gf2x_add(56, q_10+778+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_11+839);
	gf2x_add(56, q_11+778+0, 56, temp, 56, temp2);
	

	// Recombining results: n: 7140, depth: 3
	GF2X_MUL(112, temp, 56, q_00+778+0, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, q_01+778+0, 56, p_10+783);
	gf2x_add(112, p_00+671+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, q_00+778+0, 56, p_01+783);
	GF2X_MUL(112, temp2, 56, q_01+778+0, 56, p_11+783);
	gf2x_add(112, p_01+671+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, q_10+778+0, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, q_11+778+0, 56, p_10+783);
	gf2x_add(112, p_10+671+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, q_10+778+0, 56, p_01+783);
	GF2X_MUL(112, temp2, 56, q_11+778+0, 56, p_11+783);
	gf2x_add(112, p_11+671+0, 112, temp, 112, temp2);
	

	// Calculating left operands: n: 14280, depth: 2
	// Digits to shift: 111
	// Displacement: 112
	GF2X_MUL(224, temp, 112, f_sum+219+112, 112, p_00+671);
	GF2X_MUL(224, temp2, 112, g_sum+219+112, 112, p_01+671);
	gf2x_add(224, f_sum+2008+0, 224, temp, 224, temp2);
	GF2X_MUL(224, temp, 112, f_sum+219+0, 112, p_00+671);
	GF2X_MUL(224, temp2, 112, g_sum+219+0, 112, p_01+671);
	gf2x_add(224, temp, 224, temp, 224, temp2);
	gf2x_add(112, f_sum+2008, 112, f_sum+2008, 112, temp+112);
	right_bit_shift_n(224, f_sum+2008, 36);
	GF2X_MUL(224, temp, 112, f_sum+219+112, 112, p_10+671);
	GF2X_MUL(224, temp2, 112, g_sum+219+112, 112, p_11+671);
	gf2x_add(224, g_sum+2008+0, 224, temp, 224, temp2);
	GF2X_MUL(224, temp, 112, f_sum+219+0, 112, p_10+671);
	GF2X_MUL(224, temp2, 112, g_sum+219+0, 112, p_11+671);
	gf2x_add(224, temp, 224, temp, 224, temp2);
	gf2x_add(112, g_sum+2008, 112, g_sum+2008, 112, temp+112);
	right_bit_shift_n(224, g_sum+2008, 36);
	

	delta = divstepsx_256(255, delta, f_sum+2117, g_sum+2117, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2113+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2113+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2113+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2113+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2113+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2113+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2113+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2113+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2105+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2105+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2105+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2105+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2105+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2105+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2105+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2105+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2093+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+2093+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+2093);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+2093);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+2093+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+2093+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+2093);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+2093);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(p_00+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, p_00+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+8, 8, p_00+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+4, 8, p_00+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+0, 8, p_00+839+0, 8, temp);
	memset(p_01+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, p_01+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+8, 8, p_01+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+4, 8, p_01+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+0, 8, p_01+839+0, 8, temp);
	memset(p_10+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, p_10+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+8, 8, p_10+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+4, 8, p_10+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+0, 8, p_10+839+0, 8, temp);
	memset(p_11+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, p_11+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+8, 8, p_11+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+4, 8, p_11+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+0, 8, p_11+839+0, 8, temp);
	

	// Calculating left operands: n: 3570, depth: 4
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+2065+28, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+2065+28, 28, p_01+839);
	gf2x_add(56, f_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+2065+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+2065+0, 28, p_01+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2514, 28, f_sum+2514, 28, temp+28);
	right_bit_shift_n(56, f_sum+2514, 57);
	GF2X_MUL(56, temp, 28, f_sum+2065+28, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+2065+28, 28, p_11+839);
	gf2x_add(56, g_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+2065+0, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+2065+0, 28, p_11+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2514, 28, g_sum+2514, 28, temp+28);
	right_bit_shift_n(56, g_sum+2514, 57);
	

	delta = divstepsx_256(255, delta, f_sum+2539, g_sum+2539, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, q_00+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+8, 8, q_00+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+4, 8, q_00+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+0, 8, q_00+834+0, 8, temp);
	memset(q_01+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, q_01+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+8, 8, q_01+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+4, 8, q_01+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+0, 8, q_01+834+0, 8, temp);
	memset(q_10+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, q_10+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+8, 8, q_10+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+4, 8, q_10+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+0, 8, q_10+834+0, 8, temp);
	memset(q_11+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, q_11+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+8, 8, q_11+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+4, 8, q_11+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+0, 8, q_11+834+0, 8, temp);
	

	// Recombining results: n: 3570, depth: 4
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_10+839);
	gf2x_add(56, p_00+783+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_11+839);
	gf2x_add(56, p_01+783+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_10+839);
	gf2x_add(56, p_10+783+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_11+839);
	gf2x_add(56, p_11+783+0, 56, temp, 56, temp2);
	

	// Calculating left operands: n: 7140, depth: 3
	// Digits to shift: 55
	// Displacement: 56
	GF2X_MUL(112, temp, 56, f_sum+2009+56, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, g_sum+2009+56, 56, p_01+783);
	gf2x_add(112, f_sum+2345+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, f_sum+2009+0, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, g_sum+2009+0, 56, p_01+783);
	gf2x_add(112, temp, 112, temp, 112, temp2);
	gf2x_add(56, f_sum+2345, 56, f_sum+2345, 56, temp+56);
	right_bit_shift_n(112, f_sum+2345, 50);
	GF2X_MUL(112, temp, 56, f_sum+2009+56, 56, p_10+783);
	GF2X_MUL(112, temp2, 56, g_sum+2009+56, 56, p_11+783);
	gf2x_add(112, g_sum+2345+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, f_sum+2009+0, 56, p_10+783);
	GF2X_MUL(112, temp2, 56, g_sum+2009+0, 56, p_11+783);
	gf2x_add(112, temp, 112, temp, 112, temp2);
	gf2x_add(56, g_sum+2345, 56, g_sum+2345, 56, temp+56);
	right_bit_shift_n(112, g_sum+2345, 50);
	

	delta = divstepsx_256(255, delta, f_sum+2398, g_sum+2398, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2394+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2394+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2394+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2394+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2386+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2386+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2386+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2386+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2374+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+2374+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+2374);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+2374);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+2374+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+2374+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+2374);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+2374);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(p_00+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, p_00+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+8, 8, p_00+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+4, 8, p_00+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+0, 8, p_00+839+0, 8, temp);
	memset(p_01+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, p_01+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+8, 8, p_01+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+4, 8, p_01+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+0, 8, p_01+839+0, 8, temp);
	memset(p_10+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, p_10+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+8, 8, p_10+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+4, 8, p_10+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+0, 8, p_10+839+0, 8, temp);
	memset(p_11+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, p_11+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+8, 8, p_11+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+4, 8, p_11+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+0, 8, p_11+839+0, 8, temp);
	

	// Calculating left operands: n: 3570, depth: 4
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+2346+28, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+28, 28, p_01+839);
	gf2x_add(56, f_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+2346+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+0, 28, p_01+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2514, 28, f_sum+2514, 28, temp+28);
	right_bit_shift_n(56, f_sum+2514, 57);
	GF2X_MUL(56, temp, 28, f_sum+2346+28, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+28, 28, p_11+839);
	gf2x_add(56, g_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+2346+0, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+0, 28, p_11+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2514, 28, g_sum+2514, 28, temp+28);
	right_bit_shift_n(56, g_sum+2514, 57);
	

	delta = divstepsx_256(255, delta, f_sum+2539, g_sum+2539, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, q_00+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+8, 8, q_00+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+4, 8, q_00+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+0, 8, q_00+834+0, 8, temp);
	memset(q_01+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, q_01+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+8, 8, q_01+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+4, 8, q_01+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+0, 8, q_01+834+0, 8, temp);
	memset(q_10+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, q_10+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+8, 8, q_10+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+4, 8, q_10+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+0, 8, q_10+834+0, 8, temp);
	memset(q_11+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, q_11+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+8, 8, q_11+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+4, 8, q_11+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+0, 8, q_11+834+0, 8, temp);
	

	// Recombining results: n: 3570, depth: 4
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_10+839);
	gf2x_add(56, q_00+778+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_11+839);
	gf2x_add(56, q_01+778+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_10+839);
	gf2x_add(56, q_10+778+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_11+839);
	gf2x_add(56, q_11+778+0, 56, temp, 56, temp2);
	

	// Recombining results: n: 7140, depth: 3
	GF2X_MUL(112, temp, 56, q_00+778+0, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, q_01+778+0, 56, p_10+783);
	gf2x_add(112, q_00+666+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, q_00+778+0, 56, p_01+783);
	GF2X_MUL(112, temp2, 56, q_01+778+0, 56, p_11+783);
	gf2x_add(112, q_01+666+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, q_10+778+0, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, q_11+778+0, 56, p_10+783);
	gf2x_add(112, q_10+666+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, q_10+778+0, 56, p_01+783);
	GF2X_MUL(112, temp2, 56, q_11+778+0, 56, p_11+783);
	gf2x_add(112, q_11+666+0, 112, temp, 112, temp2);
	

	// Recombining results: n: 14280, depth: 2
	GF2X_MUL(224, temp, 112, q_00+666+0, 112, p_00+671);
	GF2X_MUL(224, temp2, 112, q_01+666+0, 112, p_10+671);
	gf2x_add(224, p_00+447+0, 224, temp, 224, temp2);
	GF2X_MUL(224, temp, 112, q_00+666+0, 112, p_01+671);
	GF2X_MUL(224, temp2, 112, q_01+666+0, 112, p_11+671);
	gf2x_add(224, p_01+447+0, 224, temp, 224, temp2);
	GF2X_MUL(224, temp, 112, q_10+666+0, 112, p_00+671);
	GF2X_MUL(224, temp2, 112, q_11+666+0, 112, p_10+671);
	gf2x_add(224, p_10+447+0, 224, temp, 224, temp2);
	GF2X_MUL(224, temp, 112, q_10+666+0, 112, p_01+671);
	GF2X_MUL(224, temp2, 112, q_11+666+0, 112, p_11+671);
	gf2x_add(224, p_11+447+0, 224, temp, 224, temp2);
	

	// Calculating left operands: n: 28261, depth: 1
	// Digits to shift: 223
	// Displacement: 223
	GF2X_MUL(448, temp, 224, f_sum+1+218, 224, p_00+447);
	GF2X_MUL(448, temp2, 224, g_sum+1+218, 224, p_01+447);
	gf2x_add(443, f_sum+1336, 443, temp+5, 443, temp2+5);
	GF2X_MUL(436, temp, 218, p_00+447+6, 218, f_sum+1);
	GF2X_MUL(436, temp2, 218, p_01+447+6, 218, g_sum+1);
	gf2x_add(436, temp, 436, temp, 436, temp2);
	gf2x_add(219, f_sum+1336, 219, f_sum+1336, 219, temp+217);
	GF2X_MUL(12, temp, 6, f_sum+1+212, 6, p_00+447);
	GF2X_MUL(12, temp2, 6, g_sum+1+212, 6, p_01+447);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(1, f_sum+1336, 1, f_sum+1336, 1, temp+11);
	right_bit_shift_n(442, f_sum+1336, 8);
	GF2X_MUL(448, temp, 224, f_sum+1+218, 224, p_10+447);
	GF2X_MUL(448, temp2, 224, g_sum+1+218, 224, p_11+447);
	gf2x_add(443, g_sum+1336, 443, temp+5, 443, temp2+5);
	GF2X_MUL(436, temp, 218, p_10+447+6, 218, f_sum+1);
	GF2X_MUL(436, temp2, 218, p_11+447+6, 218, g_sum+1);
	gf2x_add(436, temp, 436, temp, 436, temp2);
	gf2x_add(219, g_sum+1336, 219, g_sum+1336, 219, temp+217);
	GF2X_MUL(12, temp, 6, f_sum+1+212, 6, p_10+447);
	GF2X_MUL(12, temp2, 6, g_sum+1+212, 6, p_11+447);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(1, g_sum+1336, 1, g_sum+1336, 1, temp+11);
	right_bit_shift_n(442, g_sum+1336, 8);
	

	delta = divstepsx_256(255, delta, f_sum+1552, g_sum+1552, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1548+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+1548+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1548+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+1548+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+1548+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+1548+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1548+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+1548+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1540+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+1540+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1540+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+1540+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+1540+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+1540+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1540+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+1540+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1528+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+1528+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+1528);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+1528);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+1528+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+1528+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+1528);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+1528);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(p_00+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, p_00+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+8, 8, p_00+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+4, 8, p_00+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+0, 8, p_00+839+0, 8, temp);
	memset(p_01+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, p_01+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+8, 8, p_01+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+4, 8, p_01+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+0, 8, p_01+839+0, 8, temp);
	memset(p_10+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, p_10+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+8, 8, p_10+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+4, 8, p_10+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+0, 8, p_10+839+0, 8, temp);
	memset(p_11+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, p_11+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+8, 8, p_11+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+4, 8, p_11+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+0, 8, p_11+839+0, 8, temp);
	

	// Calculating left operands: n: 3570, depth: 4
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+1500+28, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+1500+28, 28, p_01+839);
	gf2x_add(56, f_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+1500+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+1500+0, 28, p_01+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2514, 28, f_sum+2514, 28, temp+28);
	right_bit_shift_n(56, f_sum+2514, 57);
	GF2X_MUL(56, temp, 28, f_sum+1500+28, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+1500+28, 28, p_11+839);
	gf2x_add(56, g_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+1500+0, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+1500+0, 28, p_11+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2514, 28, g_sum+2514, 28, temp+28);
	right_bit_shift_n(56, g_sum+2514, 57);
	

	delta = divstepsx_256(255, delta, f_sum+2539, g_sum+2539, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, q_00+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+8, 8, q_00+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+4, 8, q_00+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+0, 8, q_00+834+0, 8, temp);
	memset(q_01+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, q_01+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+8, 8, q_01+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+4, 8, q_01+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+0, 8, q_01+834+0, 8, temp);
	memset(q_10+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, q_10+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+8, 8, q_10+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+4, 8, q_10+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+0, 8, q_10+834+0, 8, temp);
	memset(q_11+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, q_11+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+8, 8, q_11+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+4, 8, q_11+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+0, 8, q_11+834+0, 8, temp);
	

	// Recombining results: n: 3570, depth: 4
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_10+839);
	gf2x_add(56, p_00+783+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_11+839);
	gf2x_add(56, p_01+783+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_10+839);
	gf2x_add(56, p_10+783+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_11+839);
	gf2x_add(56, p_11+783+0, 56, temp, 56, temp2);
	

	// Calculating left operands: n: 7140, depth: 3
	// Digits to shift: 55
	// Displacement: 56
	GF2X_MUL(112, temp, 56, f_sum+1444+56, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, g_sum+1444+56, 56, p_01+783);
	gf2x_add(112, f_sum+2345+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, f_sum+1444+0, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, g_sum+1444+0, 56, p_01+783);
	gf2x_add(112, temp, 112, temp, 112, temp2);
	gf2x_add(56, f_sum+2345, 56, f_sum+2345, 56, temp+56);
	right_bit_shift_n(112, f_sum+2345, 50);
	GF2X_MUL(112, temp, 56, f_sum+1444+56, 56, p_10+783);
	GF2X_MUL(112, temp2, 56, g_sum+1444+56, 56, p_11+783);
	gf2x_add(112, g_sum+2345+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, f_sum+1444+0, 56, p_10+783);
	GF2X_MUL(112, temp2, 56, g_sum+1444+0, 56, p_11+783);
	gf2x_add(112, temp, 112, temp, 112, temp2);
	gf2x_add(56, g_sum+2345, 56, g_sum+2345, 56, temp+56);
	right_bit_shift_n(112, g_sum+2345, 50);
	

	delta = divstepsx_256(255, delta, f_sum+2398, g_sum+2398, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2394+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2394+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2394+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2394+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2394+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2386+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2386+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2386+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2386+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2386+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2374+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+2374+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+2374);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+2374);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+2374+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+2374+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+2374);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+2374);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(p_00+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, p_00+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+8, 8, p_00+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+4, 8, p_00+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+0, 8, p_00+839+0, 8, temp);
	memset(p_01+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, p_01+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+8, 8, p_01+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+4, 8, p_01+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+0, 8, p_01+839+0, 8, temp);
	memset(p_10+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, p_10+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+8, 8, p_10+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+4, 8, p_10+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+0, 8, p_10+839+0, 8, temp);
	memset(p_11+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, p_11+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+8, 8, p_11+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+4, 8, p_11+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+0, 8, p_11+839+0, 8, temp);
	

	// Calculating left operands: n: 3570, depth: 4
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+2346+28, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+28, 28, p_01+839);
	gf2x_add(56, f_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+2346+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+0, 28, p_01+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2514, 28, f_sum+2514, 28, temp+28);
	right_bit_shift_n(56, f_sum+2514, 57);
	GF2X_MUL(56, temp, 28, f_sum+2346+28, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+28, 28, p_11+839);
	gf2x_add(56, g_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+2346+0, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+0, 28, p_11+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2514, 28, g_sum+2514, 28, temp+28);
	right_bit_shift_n(56, g_sum+2514, 57);
	

	delta = divstepsx_256(255, delta, f_sum+2539, g_sum+2539, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, q_00+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+8, 8, q_00+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+4, 8, q_00+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+0, 8, q_00+834+0, 8, temp);
	memset(q_01+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, q_01+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+8, 8, q_01+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+4, 8, q_01+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+0, 8, q_01+834+0, 8, temp);
	memset(q_10+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, q_10+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+8, 8, q_10+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+4, 8, q_10+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+0, 8, q_10+834+0, 8, temp);
	memset(q_11+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, q_11+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+8, 8, q_11+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+4, 8, q_11+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+0, 8, q_11+834+0, 8, temp);
	

	// Recombining results: n: 3570, depth: 4
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_10+839);
	gf2x_add(56, q_00+778+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_11+839);
	gf2x_add(56, q_01+778+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_10+839);
	gf2x_add(56, q_10+778+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_11+839);
	gf2x_add(56, q_11+778+0, 56, temp, 56, temp2);
	

	// Recombining results: n: 7140, depth: 3
	GF2X_MUL(112, temp, 56, q_00+778+0, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, q_01+778+0, 56, p_10+783);
	gf2x_add(112, p_00+671+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, q_00+778+0, 56, p_01+783);
	GF2X_MUL(112, temp2, 56, q_01+778+0, 56, p_11+783);
	gf2x_add(112, p_01+671+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, q_10+778+0, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, q_11+778+0, 56, p_10+783);
	gf2x_add(112, p_10+671+0, 112, temp, 112, temp2);
	GF2X_MUL(112, temp, 56, q_10+778+0, 56, p_01+783);
	GF2X_MUL(112, temp2, 56, q_11+778+0, 56, p_11+783);
	gf2x_add(112, p_11+671+0, 112, temp, 112, temp2);
	

	// Calculating left operands: n: 13981, depth: 2
	// Digits to shift: 111
	// Displacement: 112
	GF2X_MUL(224, temp, 112, f_sum+1337+107, 112, p_00+671);
	GF2X_MUL(224, temp2, 112, g_sum+1337+107, 112, p_01+671);
	gf2x_add(219, f_sum+2008, 219, temp+5, 219, temp2+5);
	GF2X_MUL(214, temp, 107, p_00+671+5, 107, f_sum+1337);
	GF2X_MUL(214, temp2, 107, p_01+671+5, 107, g_sum+1337);
	gf2x_add(214, temp, 214, temp, 214, temp2);
	gf2x_add(107, f_sum+2008, 107, f_sum+2008, 107, temp+107);
	right_bit_shift_n(219, f_sum+2008, 36);
	GF2X_MUL(224, temp, 112, f_sum+1337+107, 112, p_10+671);
	GF2X_MUL(224, temp2, 112, g_sum+1337+107, 112, p_11+671);
	gf2x_add(219, g_sum+2008, 219, temp+5, 219, temp2+5);
	GF2X_MUL(214, temp, 107, p_10+671+5, 107, f_sum+1337);
	GF2X_MUL(214, temp2, 107, p_11+671+5, 107, g_sum+1337);
	gf2x_add(214, temp, 214, temp, 214, temp2);
	gf2x_add(107, g_sum+2008, 107, g_sum+2008, 107, temp+107);
	right_bit_shift_n(219, g_sum+2008, 36);
	

	delta = divstepsx_256(255, delta, f_sum+2112, g_sum+2112, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2108+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2108+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2108+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2108+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2108+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2108+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2108+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2108+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2100+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2100+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2100+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2100+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2100+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2100+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2100+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2100+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2088+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+2088+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+2088);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+2088);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+2088+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+2088+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+2088);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+2088);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(p_00+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, p_00+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+8, 8, p_00+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+4, 8, p_00+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+0, 8, p_00+839+0, 8, temp);
	memset(p_01+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, p_01+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+8, 8, p_01+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+4, 8, p_01+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+0, 8, p_01+839+0, 8, temp);
	memset(p_10+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, p_10+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+8, 8, p_10+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+4, 8, p_10+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+0, 8, p_10+839+0, 8, temp);
	memset(p_11+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, p_11+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+8, 8, p_11+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+4, 8, p_11+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+0, 8, p_11+839+0, 8, temp);
	

	// Calculating left operands: n: 3570, depth: 4
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+2060+28, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+2060+28, 28, p_01+839);
	gf2x_add(56, f_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+2060+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+2060+0, 28, p_01+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2514, 28, f_sum+2514, 28, temp+28);
	right_bit_shift_n(56, f_sum+2514, 57);
	GF2X_MUL(56, temp, 28, f_sum+2060+28, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+2060+28, 28, p_11+839);
	gf2x_add(56, g_sum+2514+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+2060+0, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+2060+0, 28, p_11+839);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2514, 28, g_sum+2514, 28, temp+28);
	right_bit_shift_n(56, g_sum+2514, 57);
	

	delta = divstepsx_256(255, delta, f_sum+2539, g_sum+2539, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2535+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2535+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2535+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2527+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2527+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+2515+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+2515+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+2515);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+2515);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, q_00+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+8, 8, q_00+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+4, 8, q_00+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+834+0, 8, q_00+834+0, 8, temp);
	memset(q_01+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, q_01+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+8, 8, q_01+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+4, 8, q_01+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+834+0, 8, q_01+834+0, 8, temp);
	memset(q_10+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, q_10+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+8, 8, q_10+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+4, 8, q_10+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+834+0, 8, q_10+834+0, 8, temp);
	memset(q_11+834, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, q_11+834+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+8, 8, q_11+834+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+4, 8, q_11+834+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+834+0, 8, q_11+834+0, 8, temp);
	

	// Recombining results: n: 3570, depth: 4
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_10+839);
	gf2x_add(56, p_00+783+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_00+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_01+834+0, 28, p_11+839);
	gf2x_add(56, p_01+783+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_10+839);
	gf2x_add(56, p_10+783+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+834+0, 28, p_01+839);
	GF2X_MUL(56, temp2, 28, q_11+834+0, 28, p_11+839);
	gf2x_add(56, p_11+783+0, 56, temp, 56, temp2);
	

	// Calculating left operands: n: 6841, depth: 3
	// Digits to shift: 55
	// Displacement: 55
	GF2X_MUL(112, temp, 56, f_sum+2009+51, 56, p_00+783);
	GF2X_MUL(112, temp2, 56, g_sum+2009+51, 56, p_01+783);
	gf2x_add(108, f_sum+2345, 108, temp+4, 108, temp2+4);
	GF2X_MUL(102, temp, 51, p_00+783+5, 51, f_sum+2009);
	GF2X_MUL(102, temp2, 51, p_01+783+5, 51, g_sum+2009);
	gf2x_add(102, temp, 102, temp, 102, temp2);
	gf2x_add(52, f_sum+2345, 52, f_sum+2345, 52, temp+50);
	GF2X_MUL(10, temp, 5, f_sum+2009+46, 5, p_00+783);
	GF2X_MUL(10, temp2, 5, g_sum+2009+46, 5, p_01+783);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(1, f_sum+2345, 1, f_sum+2345, 1, temp+9);
	right_bit_shift_n(107, f_sum+2345, 50);
	GF2X_MUL(112, temp, 56, f_sum+2009+51, 56, p_10+783);
	GF2X_MUL(112, temp2, 56, g_sum+2009+51, 56, p_11+783);
	gf2x_add(108, g_sum+2345, 108, temp+4, 108, temp2+4);
	GF2X_MUL(102, temp, 51, p_10+783+5, 51, f_sum+2009);
	GF2X_MUL(102, temp2, 51, p_11+783+5, 51, g_sum+2009);
	gf2x_add(102, temp, 102, temp, 102, temp2);
	gf2x_add(52, g_sum+2345, 52, g_sum+2345, 52, temp+50);
	GF2X_MUL(10, temp, 5, f_sum+2009+46, 5, p_10+783);
	GF2X_MUL(10, temp2, 5, g_sum+2009+46, 5, p_11+783);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(1, g_sum+2345, 1, g_sum+2345, 1, temp+9);
	right_bit_shift_n(107, g_sum+2345, 50);
	

	delta = divstepsx_256(255, delta, f_sum+2394, g_sum+2394, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2390+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2390+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2390+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2390+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2390+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2390+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2390+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2390+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2382+8, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2382+8, 8, p_01+883);
	gf2x_add(16, f_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2382+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2382+0, 8, p_01+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2644, 8, f_sum+2644, 8, temp+8);
	right_bit_shift_n(16, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2382+8, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2382+8, 8, p_11+883);
	gf2x_add(16, g_sum+2644+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2382+0, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2382+0, 8, p_11+883);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2644, 8, g_sum+2644, 8, temp+8);
	right_bit_shift_n(16, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2649, g_sum+2649, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2645+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2645+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2645+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, q_00+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, q_01+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, q_10+874+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, q_11+874+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_10+883);
	gf2x_add(16, p_00+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_01+874+0, 8, p_11+883);
	gf2x_add(16, p_01+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_10+883);
	gf2x_add(16, p_10+867+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+874+0, 8, p_01+883);
	GF2X_MUL(16, temp2, 8, q_11+874+0, 8, p_11+883);
	gf2x_add(16, p_11+867+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2370+12, 16, p_00+867);
	GF2X_MUL(32, temp2, 16, g_sum+2370+12, 16, p_01+867);
	gf2x_add(28, f_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, f_sum+2370);
	GF2X_MUL(24, temp2, 12, p_01+867+4, 12, g_sum+2370);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(28, f_sum+2599, 60);
	GF2X_MUL(32, temp, 16, f_sum+2370+12, 16, p_10+867);
	GF2X_MUL(32, temp2, 16, g_sum+2370+12, 16, p_11+867);
	gf2x_add(28, g_sum+2599, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+867+4, 12, f_sum+2370);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, g_sum+2370);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(28, g_sum+2599, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(p_00+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_01+862);
	gf2x_add(24, p_00+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+8, 8, p_00+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+4, 8, p_00+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+839+0, 8, p_00+839+0, 8, temp);
	memset(p_01+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_00+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_01+862);
	gf2x_add(24, p_01+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+8, 8, p_01+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+4, 8, p_01+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_01+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+839+0, 8, p_01+839+0, 8, temp);
	memset(p_10+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_10+867+4, 12, q_11+862);
	gf2x_add(24, p_10+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+8, 8, p_10+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+4, 8, p_10+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_00+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_10+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+839+0, 8, p_10+839+0, 8, temp);
	memset(p_11+839, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+867+4, 12, q_10+862);
	GF2X_MUL(24, temp2, 12, p_11+867+4, 12, q_11+862);
	gf2x_add(24, p_11+839+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+862+8, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+8, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+8, 8, p_11+839+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+4, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+4, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+4, 8, p_11+839+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+862+0, 4, p_01+867);
	GF2X_MUL(8, temp2, 4, q_11+862+0, 4, p_11+867);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+839+0, 8, p_11+839+0, 8, temp);
	

	// Calculating left operands: n: 3271, depth: 4
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+2346+24, 28, p_00+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+24, 28, p_01+839);
	gf2x_add(52, f_sum+2514, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_00+839+4, 24, f_sum+2346);
	GF2X_MUL(48, temp2, 24, p_01+839+4, 24, g_sum+2346);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+2514, 24, f_sum+2514, 24, temp+24);
	right_bit_shift_n(52, f_sum+2514, 57);
	GF2X_MUL(56, temp, 28, f_sum+2346+24, 28, p_10+839);
	GF2X_MUL(56, temp2, 28, g_sum+2346+24, 28, p_11+839);
	gf2x_add(52, g_sum+2514, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_10+839+4, 24, f_sum+2346);
	GF2X_MUL(48, temp2, 24, p_11+839+4, 24, g_sum+2346);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+2514, 24, g_sum+2514, 24, temp+24);
	right_bit_shift_n(52, g_sum+2514, 57);
	

	delta = divstepsx_256(255, delta, f_sum+2535, g_sum+2535, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2531+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2531+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2531+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2531+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2531+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2531+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2531+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2531+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2527+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2527);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2527);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2527+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2527+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2527);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2527);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 765, depth: 6
	memset(p_00+867, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, p_00+867+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+867+0, 8, p_00+867+0, 8, temp);
	memset(p_01+867, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, p_01+867+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+867+0, 8, p_01+867+0, 8, temp);
	memset(p_10+867, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, p_10+867+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+867+0, 8, p_10+867+0, 8, temp);
	memset(p_11+867, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, p_11+867+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+867+0, 8, p_11+867+0, 8, temp);
	

	// Calculating left operands: n: 1486, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2515+12, 12, p_00+867);
	GF2X_MUL(24, temp2, 12, g_sum+2515+12, 12, p_01+867);
	gf2x_add(24, f_sum+2599+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2515+0, 12, p_00+867);
	GF2X_MUL(24, temp2, 12, g_sum+2515+0, 12, p_01+867);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2599, 12, f_sum+2599, 12, temp+12);
	right_bit_shift_n(24, f_sum+2599, 61);
	GF2X_MUL(24, temp, 12, f_sum+2515+12, 12, p_10+867);
	GF2X_MUL(24, temp2, 12, g_sum+2515+12, 12, p_11+867);
	gf2x_add(24, g_sum+2599+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2515+0, 12, p_10+867);
	GF2X_MUL(24, temp2, 12, g_sum+2515+0, 12, p_11+867);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2599, 12, g_sum+2599, 12, temp+12);
	right_bit_shift_n(24, g_sum+2599, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2608, g_sum+2608, p_00+891, p_01+891, p_10+891, p_11+891);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_01+891);
	gf2x_add(8, f_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_01+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2669, 4, f_sum+2669, 4, temp+4);
	right_bit_shift_n(8, f_sum+2669, 63);
	GF2X_MUL(8, temp, 4, f_sum+2604+4, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+4, 4, p_11+891);
	gf2x_add(8, g_sum+2669+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2604+0, 4, p_10+891);
	GF2X_MUL(8, temp2, 4, g_sum+2604+0, 4, p_11+891);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2669, 4, g_sum+2669, 4, temp+4);
	right_bit_shift_n(8, g_sum+2669, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2670, g_sum+2670, q_00+882, q_01+882, q_10+882, q_11+882);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_10+891);
	gf2x_add(8, p_00+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_01+882+0, 4, p_11+891);
	gf2x_add(8, p_01+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_00+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_10+891);
	gf2x_add(8, p_10+883+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+882+0, 4, p_01+891);
	GF2X_MUL(8, temp2, 4, q_11+882+0, 4, p_11+891);
	gf2x_add(8, p_11+883+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 721, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_00+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_01+883);
	gf2x_add(12, f_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_01+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2644, 4, f_sum+2644, 4, temp+4);
	right_bit_shift_n(12, f_sum+2644, 62);
	GF2X_MUL(16, temp, 8, f_sum+2600+4, 8, p_10+883);
	GF2X_MUL(16, temp2, 8, g_sum+2600+4, 8, p_11+883);
	gf2x_add(12, g_sum+2644, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+883+4, 4, f_sum+2600);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, g_sum+2600);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2644, 4, g_sum+2644, 4, temp+4);
	right_bit_shift_n(12, g_sum+2644, 62);
	

	delta = divstepsx_256(211, delta, f_sum+2645, g_sum+2645, q_00+874, q_01+874, q_10+874, q_11+874);

	// Recombining results: n: 721, depth: 6
	memset(q_00+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_01+874);
	gf2x_add(8, q_00+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+862+0, 8, q_00+862+0, 8, temp);
	memset(q_01+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_00+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_01+874);
	gf2x_add(8, q_01+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_01+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+862+0, 8, q_01+862+0, 8, temp);
	memset(q_10+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_10+883+4, 4, q_11+874);
	gf2x_add(8, q_10+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_00+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_10+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+862+0, 8, q_10+862+0, 8, temp);
	memset(q_11+862, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+883+4, 4, q_10+874);
	GF2X_MUL(8, temp2, 4, p_11+883+4, 4, q_11+874);
	gf2x_add(8, q_11+862+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+874+0, 4, p_01+883);
	GF2X_MUL(8, temp2, 4, q_11+874+0, 4, p_11+883);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+862+0, 8, q_11+862+0, 8, temp);
	

	// Recombining results: n: 1486, depth: 5
	GF2X_MUL(24, temp, 12, q_00+862+0, 12, p_00+867);
	GF2X_MUL(24, temp2, 12, q_01+862+0, 12, p_10+867);
	gf2x_add(24, q_00+834+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+862+0, 12, p_01+867);
	GF2X_MUL(24, temp2, 12, q_01+862+0, 12, p_11+867);
	gf2x_add(24, q_01+834+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+862+0, 12, p_00+867);
	GF2X_MUL(24, temp2, 12, q_11+862+0, 12, p_10+867);
	gf2x_add(24, q_10+834+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+862+0, 12, p_01+867);
	GF2X_MUL(24, temp2, 12, q_11+862+0, 12, p_11+867);
	gf2x_add(24, q_11+834+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3271, depth: 4
	memset(q_00+778, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+839+4, 24, q_00+834);
	GF2X_MUL(48, temp2, 24, p_10+839+4, 24, q_01+834);
	gf2x_add(48, q_00+778+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+834+20, 4, p_00+839);
	GF2X_MUL(8, temp2, 4, q_01+834+20, 4, p_10+839);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+778+20, 8, q_00+778+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+834+16, 4, p_00+839);
	GF2X_MUL(8, temp2, 4, q_01+834+16, 4, p_10+839);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+778+16, 8, q_00+778+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+834+12, 4, p_00+839);
	GF2X_MUL(8, temp2, 4, q_01+834+12, 4, p_10+839);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+778+12, 8, q_00+778+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+834+8, 4, p_00+839);
	GF2X_MUL(8, temp2, 4, q_01+834+8, 4, p_10+839);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+778+8, 8, q_00+778+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+834+4, 4, p_00+839);
	GF2X_MUL(8, temp2, 4, q_01+834+4, 4, p_10+839);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+778+4, 8, q_00+778+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+834+0, 4, p_00+839);
	GF2X_MUL(8, temp2, 4, q_01+834+0, 4, p_10+839);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+778+0, 8, q_00+778+0, 8, temp);
	memset(q_01+778, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+839+4, 24, q_00+834);
	GF2X_MUL(48, temp2, 24, p_11+839+4, 24, q_01+834);
	gf2x_add(48, q_01+778+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+834+20, 4, p_01+839);
	GF2X_MUL(8, temp2, 4, q_01+834+20, 4, p_11+839);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+778+20, 8, q_01+778+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+834+16, 4, p_01+839);
	GF2X_MUL(8, temp2, 4, q_01+834+16, 4, p_11+839);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+778+16, 8, q_01+778+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+834+12, 4, p_01+839);
	GF2X_MUL(8, temp2, 4, q_01+834+12, 4, p_11+839);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+778+12, 8, q_01+778+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+834+8, 4, p_01+839);
	GF2X_MUL(8, temp2, 4, q_01+834+8, 4, p_11+839);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+778+8, 8, q_01+778+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+834+4, 4, p_01+839);
	GF2X_MUL(8, temp2, 4, q_01+834+4, 4, p_11+839);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+778+4, 8, q_01+778+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+834+0, 4, p_01+839);
	GF2X_MUL(8, temp2, 4, q_01+834+0, 4, p_11+839);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+778+0, 8, q_01+778+0, 8, temp);
	memset(q_10+778, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+839+4, 24, q_10+834);
	GF2X_MUL(48, temp2, 24, p_10+839+4, 24, q_11+834);
	gf2x_add(48, q_10+778+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+834+20, 4, p_00+839);
	GF2X_MUL(8, temp2, 4, q_11+834+20, 4, p_10+839);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+778+20, 8, q_10+778+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+834+16, 4, p_00+839);
	GF2X_MUL(8, temp2, 4, q_11+834+16, 4, p_10+839);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+778+16, 8, q_10+778+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+834+12, 4, p_00+839);
	GF2X_MUL(8, temp2, 4, q_11+834+12, 4, p_10+839);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+778+12, 8, q_10+778+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+834+8, 4, p_00+839);
	GF2X_MUL(8, temp2, 4, q_11+834+8, 4, p_10+839);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+778+8, 8, q_10+778+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+834+4, 4, p_00+839);
	GF2X_MUL(8, temp2, 4, q_11+834+4, 4, p_10+839);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+778+4, 8, q_10+778+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+834+0, 4, p_00+839);
	GF2X_MUL(8, temp2, 4, q_11+834+0, 4, p_10+839);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+778+0, 8, q_10+778+0, 8, temp);
	memset(q_11+778, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+839+4, 24, q_10+834);
	GF2X_MUL(48, temp2, 24, p_11+839+4, 24, q_11+834);
	gf2x_add(48, q_11+778+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+834+20, 4, p_01+839);
	GF2X_MUL(8, temp2, 4, q_11+834+20, 4, p_11+839);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+778+20, 8, q_11+778+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+834+16, 4, p_01+839);
	GF2X_MUL(8, temp2, 4, q_11+834+16, 4, p_11+839);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+778+16, 8, q_11+778+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+834+12, 4, p_01+839);
	GF2X_MUL(8, temp2, 4, q_11+834+12, 4, p_11+839);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+778+12, 8, q_11+778+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+834+8, 4, p_01+839);
	GF2X_MUL(8, temp2, 4, q_11+834+8, 4, p_11+839);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+778+8, 8, q_11+778+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+834+4, 4, p_01+839);
	GF2X_MUL(8, temp2, 4, q_11+834+4, 4, p_11+839);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+778+4, 8, q_11+778+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+834+0, 4, p_01+839);
	GF2X_MUL(8, temp2, 4, q_11+834+0, 4, p_11+839);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+778+0, 8, q_11+778+0, 8, temp);
	

	// Recombining results: n: 6841, depth: 3
	memset(q_00+666, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(104, temp, 52, p_00+783+4, 52, q_00+778);
	GF2X_MUL(104, temp2, 52, p_10+783+4, 52, q_01+778);
	gf2x_add(104, q_00+666+3, 104, temp, 104, temp2);
	GF2X_MUL(8, temp, 4, q_00+778+48, 4, p_00+783);
	GF2X_MUL(8, temp2, 4, q_01+778+48, 4, p_10+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+666+47, 8, q_00+666+47, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+778+44, 4, p_00+783);
	GF2X_MUL(8, temp2, 4, q_01+778+44, 4, p_10+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+666+43, 8, q_00+666+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+778+40, 4, p_00+783);
	GF2X_MUL(8, temp2, 4, q_01+778+40, 4, p_10+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+666+39, 8, q_00+666+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+778+36, 4, p_00+783);
	GF2X_MUL(8, temp2, 4, q_01+778+36, 4, p_10+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+666+35, 8, q_00+666+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+778+32, 4, p_00+783);
	GF2X_MUL(8, temp2, 4, q_01+778+32, 4, p_10+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+666+31, 8, q_00+666+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+778+28, 4, p_00+783);
	GF2X_MUL(8, temp2, 4, q_01+778+28, 4, p_10+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+666+27, 8, q_00+666+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+778+24, 4, p_00+783);
	GF2X_MUL(8, temp2, 4, q_01+778+24, 4, p_10+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+666+23, 8, q_00+666+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+778+20, 4, p_00+783);
	GF2X_MUL(8, temp2, 4, q_01+778+20, 4, p_10+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+666+19, 8, q_00+666+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+778+16, 4, p_00+783);
	GF2X_MUL(8, temp2, 4, q_01+778+16, 4, p_10+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+666+15, 8, q_00+666+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+778+12, 4, p_00+783);
	GF2X_MUL(8, temp2, 4, q_01+778+12, 4, p_10+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+666+11, 8, q_00+666+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+778+8, 4, p_00+783);
	GF2X_MUL(8, temp2, 4, q_01+778+8, 4, p_10+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+666+7, 8, q_00+666+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+778+4, 4, p_00+783);
	GF2X_MUL(8, temp2, 4, q_01+778+4, 4, p_10+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+666+3, 8, q_00+666+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+778+0, 4, p_00+783);
	GF2X_MUL(8, temp2, 4, q_01+778+0, 4, p_10+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, q_00+666, 7, q_00+666, 7, temp+1);
	memset(q_01+666, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(104, temp, 52, p_01+783+4, 52, q_00+778);
	GF2X_MUL(104, temp2, 52, p_11+783+4, 52, q_01+778);
	gf2x_add(104, q_01+666+3, 104, temp, 104, temp2);
	GF2X_MUL(8, temp, 4, q_00+778+48, 4, p_01+783);
	GF2X_MUL(8, temp2, 4, q_01+778+48, 4, p_11+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+666+47, 8, q_01+666+47, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+778+44, 4, p_01+783);
	GF2X_MUL(8, temp2, 4, q_01+778+44, 4, p_11+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+666+43, 8, q_01+666+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+778+40, 4, p_01+783);
	GF2X_MUL(8, temp2, 4, q_01+778+40, 4, p_11+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+666+39, 8, q_01+666+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+778+36, 4, p_01+783);
	GF2X_MUL(8, temp2, 4, q_01+778+36, 4, p_11+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+666+35, 8, q_01+666+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+778+32, 4, p_01+783);
	GF2X_MUL(8, temp2, 4, q_01+778+32, 4, p_11+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+666+31, 8, q_01+666+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+778+28, 4, p_01+783);
	GF2X_MUL(8, temp2, 4, q_01+778+28, 4, p_11+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+666+27, 8, q_01+666+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+778+24, 4, p_01+783);
	GF2X_MUL(8, temp2, 4, q_01+778+24, 4, p_11+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+666+23, 8, q_01+666+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+778+20, 4, p_01+783);
	GF2X_MUL(8, temp2, 4, q_01+778+20, 4, p_11+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+666+19, 8, q_01+666+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+778+16, 4, p_01+783);
	GF2X_MUL(8, temp2, 4, q_01+778+16, 4, p_11+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+666+15, 8, q_01+666+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+778+12, 4, p_01+783);
	GF2X_MUL(8, temp2, 4, q_01+778+12, 4, p_11+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+666+11, 8, q_01+666+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+778+8, 4, p_01+783);
	GF2X_MUL(8, temp2, 4, q_01+778+8, 4, p_11+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+666+7, 8, q_01+666+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+778+4, 4, p_01+783);
	GF2X_MUL(8, temp2, 4, q_01+778+4, 4, p_11+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+666+3, 8, q_01+666+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+778+0, 4, p_01+783);
	GF2X_MUL(8, temp2, 4, q_01+778+0, 4, p_11+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, q_01+666, 7, q_01+666, 7, temp+1);
	memset(q_10+666, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(104, temp, 52, p_00+783+4, 52, q_10+778);
	GF2X_MUL(104, temp2, 52, p_10+783+4, 52, q_11+778);
	gf2x_add(104, q_10+666+3, 104, temp, 104, temp2);
	GF2X_MUL(8, temp, 4, q_10+778+48, 4, p_00+783);
	GF2X_MUL(8, temp2, 4, q_11+778+48, 4, p_10+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+666+47, 8, q_10+666+47, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+778+44, 4, p_00+783);
	GF2X_MUL(8, temp2, 4, q_11+778+44, 4, p_10+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+666+43, 8, q_10+666+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+778+40, 4, p_00+783);
	GF2X_MUL(8, temp2, 4, q_11+778+40, 4, p_10+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+666+39, 8, q_10+666+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+778+36, 4, p_00+783);
	GF2X_MUL(8, temp2, 4, q_11+778+36, 4, p_10+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+666+35, 8, q_10+666+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+778+32, 4, p_00+783);
	GF2X_MUL(8, temp2, 4, q_11+778+32, 4, p_10+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+666+31, 8, q_10+666+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+778+28, 4, p_00+783);
	GF2X_MUL(8, temp2, 4, q_11+778+28, 4, p_10+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+666+27, 8, q_10+666+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+778+24, 4, p_00+783);
	GF2X_MUL(8, temp2, 4, q_11+778+24, 4, p_10+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+666+23, 8, q_10+666+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+778+20, 4, p_00+783);
	GF2X_MUL(8, temp2, 4, q_11+778+20, 4, p_10+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+666+19, 8, q_10+666+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+778+16, 4, p_00+783);
	GF2X_MUL(8, temp2, 4, q_11+778+16, 4, p_10+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+666+15, 8, q_10+666+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+778+12, 4, p_00+783);
	GF2X_MUL(8, temp2, 4, q_11+778+12, 4, p_10+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+666+11, 8, q_10+666+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+778+8, 4, p_00+783);
	GF2X_MUL(8, temp2, 4, q_11+778+8, 4, p_10+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+666+7, 8, q_10+666+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+778+4, 4, p_00+783);
	GF2X_MUL(8, temp2, 4, q_11+778+4, 4, p_10+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+666+3, 8, q_10+666+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+778+0, 4, p_00+783);
	GF2X_MUL(8, temp2, 4, q_11+778+0, 4, p_10+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, q_10+666, 7, q_10+666, 7, temp+1);
	memset(q_11+666, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(104, temp, 52, p_01+783+4, 52, q_10+778);
	GF2X_MUL(104, temp2, 52, p_11+783+4, 52, q_11+778);
	gf2x_add(104, q_11+666+3, 104, temp, 104, temp2);
	GF2X_MUL(8, temp, 4, q_10+778+48, 4, p_01+783);
	GF2X_MUL(8, temp2, 4, q_11+778+48, 4, p_11+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+666+47, 8, q_11+666+47, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+778+44, 4, p_01+783);
	GF2X_MUL(8, temp2, 4, q_11+778+44, 4, p_11+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+666+43, 8, q_11+666+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+778+40, 4, p_01+783);
	GF2X_MUL(8, temp2, 4, q_11+778+40, 4, p_11+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+666+39, 8, q_11+666+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+778+36, 4, p_01+783);
	GF2X_MUL(8, temp2, 4, q_11+778+36, 4, p_11+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+666+35, 8, q_11+666+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+778+32, 4, p_01+783);
	GF2X_MUL(8, temp2, 4, q_11+778+32, 4, p_11+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+666+31, 8, q_11+666+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+778+28, 4, p_01+783);
	GF2X_MUL(8, temp2, 4, q_11+778+28, 4, p_11+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+666+27, 8, q_11+666+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+778+24, 4, p_01+783);
	GF2X_MUL(8, temp2, 4, q_11+778+24, 4, p_11+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+666+23, 8, q_11+666+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+778+20, 4, p_01+783);
	GF2X_MUL(8, temp2, 4, q_11+778+20, 4, p_11+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+666+19, 8, q_11+666+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+778+16, 4, p_01+783);
	GF2X_MUL(8, temp2, 4, q_11+778+16, 4, p_11+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+666+15, 8, q_11+666+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+778+12, 4, p_01+783);
	GF2X_MUL(8, temp2, 4, q_11+778+12, 4, p_11+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+666+11, 8, q_11+666+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+778+8, 4, p_01+783);
	GF2X_MUL(8, temp2, 4, q_11+778+8, 4, p_11+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+666+7, 8, q_11+666+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+778+4, 4, p_01+783);
	GF2X_MUL(8, temp2, 4, q_11+778+4, 4, p_11+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+666+3, 8, q_11+666+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+778+0, 4, p_01+783);
	GF2X_MUL(8, temp2, 4, q_11+778+0, 4, p_11+783);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, q_11+666, 7, q_11+666, 7, temp+1);
	

	// Recombining results: n: 13981, depth: 2
	memset(q_00+442, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(214, temp, 107, p_00+671+5, 107, q_00+666);
	GF2X_MUL(214, temp2, 107, p_10+671+5, 107, q_01+666);
	gf2x_add(214, q_00+442+5, 214, temp, 214, temp2);
	GF2X_MUL(10, temp, 5, q_00+666+102, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_01+666+102, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+442+102, 10, q_00+442+102, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+97, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_01+666+97, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+442+97, 10, q_00+442+97, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+92, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_01+666+92, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+442+92, 10, q_00+442+92, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+87, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_01+666+87, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+442+87, 10, q_00+442+87, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+82, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_01+666+82, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+442+82, 10, q_00+442+82, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+77, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_01+666+77, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+442+77, 10, q_00+442+77, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+72, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_01+666+72, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+442+72, 10, q_00+442+72, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+67, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_01+666+67, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+442+67, 10, q_00+442+67, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+62, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_01+666+62, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+442+62, 10, q_00+442+62, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+57, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_01+666+57, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+442+57, 10, q_00+442+57, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+52, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_01+666+52, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+442+52, 10, q_00+442+52, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+47, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_01+666+47, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+442+47, 10, q_00+442+47, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+42, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_01+666+42, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+442+42, 10, q_00+442+42, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+37, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_01+666+37, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+442+37, 10, q_00+442+37, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+32, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_01+666+32, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+442+32, 10, q_00+442+32, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+27, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_01+666+27, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+442+27, 10, q_00+442+27, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+22, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_01+666+22, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+442+22, 10, q_00+442+22, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+17, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_01+666+17, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+442+17, 10, q_00+442+17, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+12, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_01+666+12, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+442+12, 10, q_00+442+12, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+7, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_01+666+7, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+442+7, 10, q_00+442+7, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+2, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_01+666+2, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+442+2, 10, q_00+442+2, 10, temp);
	GF2X_MUL(4, temp, 2, p_00+671+3, 2, q_00+666);
	GF2X_MUL(4, temp2, 2, p_10+671+3, 2, q_01+666);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+442+3, 4, q_00+442+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+671+1, 2, q_00+666);
	GF2X_MUL(4, temp2, 2, p_10+671+1, 2, q_01+666);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+442+1, 4, q_00+442+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_00+666+1, 1, p_00+671);
	GF2X_MUL(2, temp2, 1, q_01+666+1, 1, p_10+671);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+442+1, 2, q_00+442+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+666+0, 1, p_00+671);
	GF2X_MUL(2, temp2, 1, q_01+666+0, 1, p_10+671);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+442+0, 2, q_00+442+0, 2, temp);
	memset(q_01+442, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(214, temp, 107, p_01+671+5, 107, q_00+666);
	GF2X_MUL(214, temp2, 107, p_11+671+5, 107, q_01+666);
	gf2x_add(214, q_01+442+5, 214, temp, 214, temp2);
	GF2X_MUL(10, temp, 5, q_00+666+102, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_01+666+102, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+442+102, 10, q_01+442+102, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+97, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_01+666+97, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+442+97, 10, q_01+442+97, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+92, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_01+666+92, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+442+92, 10, q_01+442+92, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+87, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_01+666+87, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+442+87, 10, q_01+442+87, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+82, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_01+666+82, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+442+82, 10, q_01+442+82, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+77, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_01+666+77, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+442+77, 10, q_01+442+77, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+72, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_01+666+72, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+442+72, 10, q_01+442+72, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+67, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_01+666+67, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+442+67, 10, q_01+442+67, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+62, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_01+666+62, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+442+62, 10, q_01+442+62, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+57, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_01+666+57, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+442+57, 10, q_01+442+57, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+52, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_01+666+52, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+442+52, 10, q_01+442+52, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+47, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_01+666+47, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+442+47, 10, q_01+442+47, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+42, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_01+666+42, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+442+42, 10, q_01+442+42, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+37, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_01+666+37, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+442+37, 10, q_01+442+37, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+32, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_01+666+32, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+442+32, 10, q_01+442+32, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+27, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_01+666+27, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+442+27, 10, q_01+442+27, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+22, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_01+666+22, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+442+22, 10, q_01+442+22, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+17, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_01+666+17, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+442+17, 10, q_01+442+17, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+12, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_01+666+12, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+442+12, 10, q_01+442+12, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+7, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_01+666+7, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+442+7, 10, q_01+442+7, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+666+2, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_01+666+2, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+442+2, 10, q_01+442+2, 10, temp);
	GF2X_MUL(4, temp, 2, p_01+671+3, 2, q_00+666);
	GF2X_MUL(4, temp2, 2, p_11+671+3, 2, q_01+666);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+442+3, 4, q_01+442+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+671+1, 2, q_00+666);
	GF2X_MUL(4, temp2, 2, p_11+671+1, 2, q_01+666);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+442+1, 4, q_01+442+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_00+666+1, 1, p_01+671);
	GF2X_MUL(2, temp2, 1, q_01+666+1, 1, p_11+671);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+442+1, 2, q_01+442+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+666+0, 1, p_01+671);
	GF2X_MUL(2, temp2, 1, q_01+666+0, 1, p_11+671);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+442+0, 2, q_01+442+0, 2, temp);
	memset(q_10+442, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(214, temp, 107, p_00+671+5, 107, q_10+666);
	GF2X_MUL(214, temp2, 107, p_10+671+5, 107, q_11+666);
	gf2x_add(214, q_10+442+5, 214, temp, 214, temp2);
	GF2X_MUL(10, temp, 5, q_10+666+102, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_11+666+102, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+442+102, 10, q_10+442+102, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+97, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_11+666+97, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+442+97, 10, q_10+442+97, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+92, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_11+666+92, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+442+92, 10, q_10+442+92, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+87, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_11+666+87, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+442+87, 10, q_10+442+87, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+82, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_11+666+82, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+442+82, 10, q_10+442+82, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+77, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_11+666+77, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+442+77, 10, q_10+442+77, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+72, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_11+666+72, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+442+72, 10, q_10+442+72, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+67, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_11+666+67, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+442+67, 10, q_10+442+67, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+62, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_11+666+62, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+442+62, 10, q_10+442+62, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+57, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_11+666+57, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+442+57, 10, q_10+442+57, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+52, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_11+666+52, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+442+52, 10, q_10+442+52, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+47, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_11+666+47, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+442+47, 10, q_10+442+47, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+42, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_11+666+42, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+442+42, 10, q_10+442+42, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+37, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_11+666+37, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+442+37, 10, q_10+442+37, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+32, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_11+666+32, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+442+32, 10, q_10+442+32, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+27, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_11+666+27, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+442+27, 10, q_10+442+27, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+22, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_11+666+22, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+442+22, 10, q_10+442+22, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+17, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_11+666+17, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+442+17, 10, q_10+442+17, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+12, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_11+666+12, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+442+12, 10, q_10+442+12, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+7, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_11+666+7, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+442+7, 10, q_10+442+7, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+2, 5, p_00+671);
	GF2X_MUL(10, temp2, 5, q_11+666+2, 5, p_10+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+442+2, 10, q_10+442+2, 10, temp);
	GF2X_MUL(4, temp, 2, p_00+671+3, 2, q_10+666);
	GF2X_MUL(4, temp2, 2, p_10+671+3, 2, q_11+666);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+442+3, 4, q_10+442+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+671+1, 2, q_10+666);
	GF2X_MUL(4, temp2, 2, p_10+671+1, 2, q_11+666);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+442+1, 4, q_10+442+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_10+666+1, 1, p_00+671);
	GF2X_MUL(2, temp2, 1, q_11+666+1, 1, p_10+671);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+442+1, 2, q_10+442+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+666+0, 1, p_00+671);
	GF2X_MUL(2, temp2, 1, q_11+666+0, 1, p_10+671);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+442+0, 2, q_10+442+0, 2, temp);
	memset(q_11+442, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(214, temp, 107, p_01+671+5, 107, q_10+666);
	GF2X_MUL(214, temp2, 107, p_11+671+5, 107, q_11+666);
	gf2x_add(214, q_11+442+5, 214, temp, 214, temp2);
	GF2X_MUL(10, temp, 5, q_10+666+102, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_11+666+102, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+442+102, 10, q_11+442+102, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+97, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_11+666+97, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+442+97, 10, q_11+442+97, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+92, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_11+666+92, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+442+92, 10, q_11+442+92, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+87, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_11+666+87, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+442+87, 10, q_11+442+87, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+82, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_11+666+82, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+442+82, 10, q_11+442+82, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+77, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_11+666+77, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+442+77, 10, q_11+442+77, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+72, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_11+666+72, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+442+72, 10, q_11+442+72, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+67, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_11+666+67, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+442+67, 10, q_11+442+67, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+62, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_11+666+62, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+442+62, 10, q_11+442+62, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+57, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_11+666+57, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+442+57, 10, q_11+442+57, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+52, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_11+666+52, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+442+52, 10, q_11+442+52, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+47, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_11+666+47, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+442+47, 10, q_11+442+47, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+42, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_11+666+42, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+442+42, 10, q_11+442+42, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+37, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_11+666+37, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+442+37, 10, q_11+442+37, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+32, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_11+666+32, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+442+32, 10, q_11+442+32, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+27, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_11+666+27, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+442+27, 10, q_11+442+27, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+22, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_11+666+22, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+442+22, 10, q_11+442+22, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+17, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_11+666+17, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+442+17, 10, q_11+442+17, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+12, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_11+666+12, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+442+12, 10, q_11+442+12, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+7, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_11+666+7, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+442+7, 10, q_11+442+7, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+666+2, 5, p_01+671);
	GF2X_MUL(10, temp2, 5, q_11+666+2, 5, p_11+671);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+442+2, 10, q_11+442+2, 10, temp);
	GF2X_MUL(4, temp, 2, p_01+671+3, 2, q_10+666);
	GF2X_MUL(4, temp2, 2, p_11+671+3, 2, q_11+666);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+442+3, 4, q_11+442+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+671+1, 2, q_10+666);
	GF2X_MUL(4, temp2, 2, p_11+671+1, 2, q_11+666);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+442+1, 4, q_11+442+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_10+666+1, 1, p_01+671);
	GF2X_MUL(2, temp2, 1, q_11+666+1, 1, p_11+671);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+442+1, 2, q_11+442+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+666+0, 1, p_01+671);
	GF2X_MUL(2, temp2, 1, q_11+666+0, 1, p_11+671);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+442+0, 2, q_11+442+0, 2, temp);
	

	// Recombining results: n: 28261, depth: 1
	memset(q_00+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(438, temp, 219, p_00+447+5, 219, q_00+442);
	GF2X_MUL(438, temp2, 219, p_10+447+5, 219, q_01+442);
	gf2x_add(438, q_00+0+4, 438, temp, 438, temp2);
	GF2X_MUL(10, temp, 5, q_00+442+214, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+214, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+213, 10, q_00+0+213, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+209, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+209, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+208, 10, q_00+0+208, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+204, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+204, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+203, 10, q_00+0+203, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+199, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+199, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+198, 10, q_00+0+198, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+194, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+194, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+193, 10, q_00+0+193, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+189, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+189, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+188, 10, q_00+0+188, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+184, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+184, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+183, 10, q_00+0+183, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+179, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+179, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+178, 10, q_00+0+178, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+174, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+174, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+173, 10, q_00+0+173, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+169, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+169, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+168, 10, q_00+0+168, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+164, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+164, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+163, 10, q_00+0+163, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+159, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+159, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+158, 10, q_00+0+158, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+154, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+154, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+153, 10, q_00+0+153, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+149, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+149, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+148, 10, q_00+0+148, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+144, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+144, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+143, 10, q_00+0+143, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+139, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+139, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+138, 10, q_00+0+138, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+134, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+134, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+133, 10, q_00+0+133, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+129, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+129, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+128, 10, q_00+0+128, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+124, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+124, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+123, 10, q_00+0+123, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+119, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+119, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+118, 10, q_00+0+118, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+114, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+114, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+113, 10, q_00+0+113, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+109, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+109, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+108, 10, q_00+0+108, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+104, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+104, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+103, 10, q_00+0+103, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+99, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+99, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+98, 10, q_00+0+98, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+94, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+94, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+93, 10, q_00+0+93, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+89, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+89, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+88, 10, q_00+0+88, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+84, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+84, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+83, 10, q_00+0+83, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+79, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+79, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+78, 10, q_00+0+78, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+74, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+74, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+73, 10, q_00+0+73, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+69, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+69, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+68, 10, q_00+0+68, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+64, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+64, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+63, 10, q_00+0+63, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+59, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+59, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+58, 10, q_00+0+58, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+54, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+54, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+53, 10, q_00+0+53, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+49, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+49, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+48, 10, q_00+0+48, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+44, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+44, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+43, 10, q_00+0+43, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+39, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+39, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+38, 10, q_00+0+38, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+34, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+34, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+33, 10, q_00+0+33, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+29, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+29, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+28, 10, q_00+0+28, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+24, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+24, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+23, 10, q_00+0+23, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+19, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+19, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+18, 10, q_00+0+18, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+14, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+14, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+13, 10, q_00+0+13, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+9, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+9, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+8, 10, q_00+0+8, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+4, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_01+442+4, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+3, 10, q_00+0+3, 10, temp);
	GF2X_MUL(8, temp, 4, p_00+447+1, 4, q_00+442);
	GF2X_MUL(8, temp2, 4, p_10+447+1, 4, q_01+442);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+0+0, 8, q_00+0+0, 8, temp);
	GF2X_MUL(2, temp, 1, q_00+442+3, 1, p_00+447);
	GF2X_MUL(2, temp2, 1, q_01+442+3, 1, p_10+447);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+2, 2, q_00+0+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+442+2, 1, p_00+447);
	GF2X_MUL(2, temp2, 1, q_01+442+2, 1, p_10+447);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+1, 2, q_00+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+442+1, 1, p_00+447);
	GF2X_MUL(2, temp2, 1, q_01+442+1, 1, p_10+447);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+0, 2, q_00+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+442+0, 1, p_00+447);
	GF2X_MUL(2, temp2, 1, q_01+442+0, 1, p_10+447);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_00+0, 1, q_00+0, 1, temp+1);
	memset(q_01+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(438, temp, 219, p_01+447+5, 219, q_00+442);
	GF2X_MUL(438, temp2, 219, p_11+447+5, 219, q_01+442);
	gf2x_add(438, q_01+0+4, 438, temp, 438, temp2);
	GF2X_MUL(10, temp, 5, q_00+442+214, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+214, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+213, 10, q_01+0+213, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+209, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+209, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+208, 10, q_01+0+208, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+204, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+204, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+203, 10, q_01+0+203, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+199, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+199, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+198, 10, q_01+0+198, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+194, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+194, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+193, 10, q_01+0+193, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+189, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+189, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+188, 10, q_01+0+188, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+184, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+184, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+183, 10, q_01+0+183, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+179, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+179, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+178, 10, q_01+0+178, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+174, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+174, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+173, 10, q_01+0+173, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+169, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+169, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+168, 10, q_01+0+168, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+164, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+164, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+163, 10, q_01+0+163, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+159, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+159, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+158, 10, q_01+0+158, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+154, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+154, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+153, 10, q_01+0+153, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+149, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+149, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+148, 10, q_01+0+148, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+144, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+144, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+143, 10, q_01+0+143, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+139, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+139, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+138, 10, q_01+0+138, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+134, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+134, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+133, 10, q_01+0+133, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+129, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+129, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+128, 10, q_01+0+128, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+124, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+124, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+123, 10, q_01+0+123, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+119, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+119, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+118, 10, q_01+0+118, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+114, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+114, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+113, 10, q_01+0+113, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+109, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+109, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+108, 10, q_01+0+108, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+104, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+104, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+103, 10, q_01+0+103, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+99, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+99, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+98, 10, q_01+0+98, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+94, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+94, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+93, 10, q_01+0+93, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+89, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+89, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+88, 10, q_01+0+88, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+84, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+84, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+83, 10, q_01+0+83, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+79, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+79, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+78, 10, q_01+0+78, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+74, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+74, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+73, 10, q_01+0+73, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+69, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+69, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+68, 10, q_01+0+68, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+64, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+64, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+63, 10, q_01+0+63, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+59, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+59, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+58, 10, q_01+0+58, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+54, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+54, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+53, 10, q_01+0+53, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+49, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+49, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+48, 10, q_01+0+48, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+44, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+44, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+43, 10, q_01+0+43, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+39, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+39, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+38, 10, q_01+0+38, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+34, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+34, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+33, 10, q_01+0+33, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+29, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+29, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+28, 10, q_01+0+28, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+24, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+24, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+23, 10, q_01+0+23, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+19, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+19, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+18, 10, q_01+0+18, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+14, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+14, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+13, 10, q_01+0+13, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+9, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+9, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+8, 10, q_01+0+8, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+442+4, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_01+442+4, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+3, 10, q_01+0+3, 10, temp);
	GF2X_MUL(8, temp, 4, p_01+447+1, 4, q_00+442);
	GF2X_MUL(8, temp2, 4, p_11+447+1, 4, q_01+442);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+0+0, 8, q_01+0+0, 8, temp);
	GF2X_MUL(2, temp, 1, q_00+442+3, 1, p_01+447);
	GF2X_MUL(2, temp2, 1, q_01+442+3, 1, p_11+447);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+2, 2, q_01+0+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+442+2, 1, p_01+447);
	GF2X_MUL(2, temp2, 1, q_01+442+2, 1, p_11+447);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+1, 2, q_01+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+442+1, 1, p_01+447);
	GF2X_MUL(2, temp2, 1, q_01+442+1, 1, p_11+447);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+0, 2, q_01+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+442+0, 1, p_01+447);
	GF2X_MUL(2, temp2, 1, q_01+442+0, 1, p_11+447);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_01+0, 1, q_01+0, 1, temp+1);
	memset(q_10+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(438, temp, 219, p_00+447+5, 219, q_10+442);
	GF2X_MUL(438, temp2, 219, p_10+447+5, 219, q_11+442);
	gf2x_add(438, q_10+0+4, 438, temp, 438, temp2);
	GF2X_MUL(10, temp, 5, q_10+442+214, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+214, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+213, 10, q_10+0+213, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+209, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+209, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+208, 10, q_10+0+208, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+204, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+204, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+203, 10, q_10+0+203, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+199, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+199, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+198, 10, q_10+0+198, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+194, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+194, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+193, 10, q_10+0+193, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+189, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+189, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+188, 10, q_10+0+188, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+184, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+184, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+183, 10, q_10+0+183, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+179, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+179, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+178, 10, q_10+0+178, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+174, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+174, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+173, 10, q_10+0+173, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+169, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+169, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+168, 10, q_10+0+168, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+164, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+164, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+163, 10, q_10+0+163, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+159, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+159, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+158, 10, q_10+0+158, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+154, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+154, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+153, 10, q_10+0+153, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+149, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+149, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+148, 10, q_10+0+148, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+144, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+144, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+143, 10, q_10+0+143, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+139, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+139, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+138, 10, q_10+0+138, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+134, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+134, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+133, 10, q_10+0+133, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+129, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+129, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+128, 10, q_10+0+128, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+124, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+124, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+123, 10, q_10+0+123, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+119, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+119, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+118, 10, q_10+0+118, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+114, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+114, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+113, 10, q_10+0+113, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+109, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+109, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+108, 10, q_10+0+108, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+104, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+104, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+103, 10, q_10+0+103, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+99, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+99, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+98, 10, q_10+0+98, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+94, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+94, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+93, 10, q_10+0+93, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+89, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+89, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+88, 10, q_10+0+88, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+84, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+84, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+83, 10, q_10+0+83, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+79, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+79, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+78, 10, q_10+0+78, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+74, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+74, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+73, 10, q_10+0+73, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+69, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+69, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+68, 10, q_10+0+68, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+64, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+64, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+63, 10, q_10+0+63, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+59, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+59, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+58, 10, q_10+0+58, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+54, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+54, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+53, 10, q_10+0+53, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+49, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+49, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+48, 10, q_10+0+48, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+44, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+44, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+43, 10, q_10+0+43, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+39, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+39, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+38, 10, q_10+0+38, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+34, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+34, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+33, 10, q_10+0+33, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+29, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+29, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+28, 10, q_10+0+28, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+24, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+24, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+23, 10, q_10+0+23, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+19, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+19, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+18, 10, q_10+0+18, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+14, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+14, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+13, 10, q_10+0+13, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+9, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+9, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+8, 10, q_10+0+8, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+4, 5, p_00+447);
	GF2X_MUL(10, temp2, 5, q_11+442+4, 5, p_10+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+3, 10, q_10+0+3, 10, temp);
	GF2X_MUL(8, temp, 4, p_00+447+1, 4, q_10+442);
	GF2X_MUL(8, temp2, 4, p_10+447+1, 4, q_11+442);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+0+0, 8, q_10+0+0, 8, temp);
	GF2X_MUL(2, temp, 1, q_10+442+3, 1, p_00+447);
	GF2X_MUL(2, temp2, 1, q_11+442+3, 1, p_10+447);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+2, 2, q_10+0+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+442+2, 1, p_00+447);
	GF2X_MUL(2, temp2, 1, q_11+442+2, 1, p_10+447);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+1, 2, q_10+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+442+1, 1, p_00+447);
	GF2X_MUL(2, temp2, 1, q_11+442+1, 1, p_10+447);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+0, 2, q_10+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+442+0, 1, p_00+447);
	GF2X_MUL(2, temp2, 1, q_11+442+0, 1, p_10+447);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_10+0, 1, q_10+0, 1, temp+1);
	memset(q_11+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(438, temp, 219, p_01+447+5, 219, q_10+442);
	GF2X_MUL(438, temp2, 219, p_11+447+5, 219, q_11+442);
	gf2x_add(438, q_11+0+4, 438, temp, 438, temp2);
	GF2X_MUL(10, temp, 5, q_10+442+214, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+214, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+213, 10, q_11+0+213, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+209, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+209, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+208, 10, q_11+0+208, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+204, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+204, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+203, 10, q_11+0+203, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+199, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+199, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+198, 10, q_11+0+198, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+194, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+194, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+193, 10, q_11+0+193, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+189, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+189, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+188, 10, q_11+0+188, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+184, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+184, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+183, 10, q_11+0+183, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+179, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+179, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+178, 10, q_11+0+178, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+174, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+174, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+173, 10, q_11+0+173, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+169, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+169, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+168, 10, q_11+0+168, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+164, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+164, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+163, 10, q_11+0+163, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+159, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+159, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+158, 10, q_11+0+158, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+154, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+154, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+153, 10, q_11+0+153, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+149, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+149, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+148, 10, q_11+0+148, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+144, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+144, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+143, 10, q_11+0+143, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+139, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+139, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+138, 10, q_11+0+138, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+134, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+134, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+133, 10, q_11+0+133, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+129, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+129, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+128, 10, q_11+0+128, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+124, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+124, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+123, 10, q_11+0+123, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+119, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+119, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+118, 10, q_11+0+118, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+114, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+114, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+113, 10, q_11+0+113, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+109, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+109, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+108, 10, q_11+0+108, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+104, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+104, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+103, 10, q_11+0+103, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+99, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+99, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+98, 10, q_11+0+98, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+94, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+94, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+93, 10, q_11+0+93, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+89, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+89, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+88, 10, q_11+0+88, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+84, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+84, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+83, 10, q_11+0+83, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+79, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+79, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+78, 10, q_11+0+78, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+74, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+74, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+73, 10, q_11+0+73, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+69, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+69, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+68, 10, q_11+0+68, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+64, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+64, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+63, 10, q_11+0+63, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+59, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+59, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+58, 10, q_11+0+58, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+54, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+54, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+53, 10, q_11+0+53, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+49, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+49, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+48, 10, q_11+0+48, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+44, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+44, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+43, 10, q_11+0+43, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+39, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+39, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+38, 10, q_11+0+38, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+34, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+34, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+33, 10, q_11+0+33, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+29, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+29, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+28, 10, q_11+0+28, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+24, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+24, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+23, 10, q_11+0+23, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+19, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+19, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+18, 10, q_11+0+18, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+14, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+14, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+13, 10, q_11+0+13, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+9, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+9, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+8, 10, q_11+0+8, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+442+4, 5, p_01+447);
	GF2X_MUL(10, temp2, 5, q_11+442+4, 5, p_11+447);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+3, 10, q_11+0+3, 10, temp);
	GF2X_MUL(8, temp, 4, p_01+447+1, 4, q_10+442);
	GF2X_MUL(8, temp2, 4, p_11+447+1, 4, q_11+442);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+0+0, 8, q_11+0+0, 8, temp);
	GF2X_MUL(2, temp, 1, q_10+442+3, 1, p_01+447);
	GF2X_MUL(2, temp2, 1, q_11+442+3, 1, p_11+447);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+2, 2, q_11+0+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+442+2, 1, p_01+447);
	GF2X_MUL(2, temp2, 1, q_11+442+2, 1, p_11+447);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+1, 2, q_11+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+442+1, 1, p_01+447);
	GF2X_MUL(2, temp2, 1, q_11+442+1, 1, p_11+447);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+0, 2, q_11+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+442+0, 1, p_01+447);
	GF2X_MUL(2, temp2, 1, q_11+442+0, 1, p_11+447);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_11+0, 1, q_11+0, 1, temp+1);
	

	// Recombining results: n: 56821, depth: 0
	memset(t_00+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(884, temp, 442, p_00+0+5, 442, q_00+0);
	GF2X_MUL(884, temp2, 442, p_10+0+5, 442, q_01+0);
	gf2x_add(884, t_00+0+4, 884, temp, 884, temp2);
	GF2X_MUL(10, temp, 5, q_00+0+437, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+437, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+436, 10, t_00+0+436, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+432, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+432, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+431, 10, t_00+0+431, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+427, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+427, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+426, 10, t_00+0+426, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+422, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+422, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+421, 10, t_00+0+421, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+417, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+417, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+416, 10, t_00+0+416, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+412, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+412, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+411, 10, t_00+0+411, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+407, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+407, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+406, 10, t_00+0+406, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+402, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+402, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+401, 10, t_00+0+401, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+397, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+397, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+396, 10, t_00+0+396, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+392, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+392, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+391, 10, t_00+0+391, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+387, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+387, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+386, 10, t_00+0+386, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+382, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+382, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+381, 10, t_00+0+381, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+377, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+377, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+376, 10, t_00+0+376, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+372, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+372, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+371, 10, t_00+0+371, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+367, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+367, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+366, 10, t_00+0+366, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+362, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+362, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+361, 10, t_00+0+361, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+357, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+357, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+356, 10, t_00+0+356, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+352, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+352, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+351, 10, t_00+0+351, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+347, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+347, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+346, 10, t_00+0+346, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+342, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+342, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+341, 10, t_00+0+341, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+337, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+337, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+336, 10, t_00+0+336, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+332, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+332, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+331, 10, t_00+0+331, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+327, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+327, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+326, 10, t_00+0+326, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+322, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+322, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+321, 10, t_00+0+321, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+317, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+317, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+316, 10, t_00+0+316, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+312, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+312, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+311, 10, t_00+0+311, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+307, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+307, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+306, 10, t_00+0+306, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+302, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+302, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+301, 10, t_00+0+301, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+297, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+297, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+296, 10, t_00+0+296, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+292, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+292, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+291, 10, t_00+0+291, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+287, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+287, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+286, 10, t_00+0+286, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+282, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+282, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+281, 10, t_00+0+281, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+277, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+277, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+276, 10, t_00+0+276, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+272, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+272, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+271, 10, t_00+0+271, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+267, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+267, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+266, 10, t_00+0+266, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+262, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+262, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+261, 10, t_00+0+261, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+257, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+257, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+256, 10, t_00+0+256, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+252, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+252, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+251, 10, t_00+0+251, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+247, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+247, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+246, 10, t_00+0+246, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+242, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+242, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+241, 10, t_00+0+241, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+237, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+237, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+236, 10, t_00+0+236, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+232, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+232, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+231, 10, t_00+0+231, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+227, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+227, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+226, 10, t_00+0+226, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+222, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+222, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+221, 10, t_00+0+221, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+217, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+217, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+216, 10, t_00+0+216, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+212, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+212, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+211, 10, t_00+0+211, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+207, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+207, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+206, 10, t_00+0+206, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+202, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+202, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+201, 10, t_00+0+201, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+197, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+197, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+196, 10, t_00+0+196, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+192, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+192, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+191, 10, t_00+0+191, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+187, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+187, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+186, 10, t_00+0+186, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+182, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+182, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+181, 10, t_00+0+181, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+177, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+177, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+176, 10, t_00+0+176, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+172, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+172, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+171, 10, t_00+0+171, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+167, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+167, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+166, 10, t_00+0+166, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+162, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+162, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+161, 10, t_00+0+161, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+157, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+157, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+156, 10, t_00+0+156, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+152, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+152, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+151, 10, t_00+0+151, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+147, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+147, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+146, 10, t_00+0+146, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+142, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+142, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+141, 10, t_00+0+141, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+137, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+137, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+136, 10, t_00+0+136, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+132, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+132, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+131, 10, t_00+0+131, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+127, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+127, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+126, 10, t_00+0+126, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+122, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+122, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+121, 10, t_00+0+121, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+117, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+117, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+116, 10, t_00+0+116, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+112, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+112, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+111, 10, t_00+0+111, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+107, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+107, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+106, 10, t_00+0+106, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+102, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+102, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+101, 10, t_00+0+101, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+97, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+97, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+96, 10, t_00+0+96, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+92, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+92, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+91, 10, t_00+0+91, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+87, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+87, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+86, 10, t_00+0+86, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+82, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+82, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+81, 10, t_00+0+81, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+77, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+77, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+76, 10, t_00+0+76, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+72, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+72, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+71, 10, t_00+0+71, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+67, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+67, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+66, 10, t_00+0+66, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+62, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+62, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+61, 10, t_00+0+61, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+57, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+57, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+56, 10, t_00+0+56, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+52, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+52, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+51, 10, t_00+0+51, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+47, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+47, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+46, 10, t_00+0+46, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+42, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+42, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+41, 10, t_00+0+41, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+37, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+37, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+36, 10, t_00+0+36, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+32, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+32, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+31, 10, t_00+0+31, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+27, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+27, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+26, 10, t_00+0+26, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+22, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+22, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+21, 10, t_00+0+21, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+17, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+17, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+16, 10, t_00+0+16, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+12, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+12, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+11, 10, t_00+0+11, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+7, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+7, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+6, 10, t_00+0+6, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+2, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+2, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+1, 10, t_00+0+1, 10, temp);
	GF2X_MUL(4, temp, 2, p_00+0+3, 2, q_00+0);
	GF2X_MUL(4, temp2, 2, p_10+0+3, 2, q_01+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+2, 4, t_00+0+2, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+0+1, 2, q_00+0);
	GF2X_MUL(4, temp2, 2, p_10+0+1, 2, q_01+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+0, 4, t_00+0+0, 4, temp);
	GF2X_MUL(2, temp, 1, q_00+0+1, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, q_01+0+1, 1, p_10+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_00+0+0, 2, t_00+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+0+0, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, q_01+0+0, 1, p_10+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, t_00+0, 1, t_00+0, 1, temp+1);
	memset(t_01+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(884, temp, 442, p_01+0+5, 442, q_00+0);
	GF2X_MUL(884, temp2, 442, p_11+0+5, 442, q_01+0);
	gf2x_add(884, t_01+0+4, 884, temp, 884, temp2);
	GF2X_MUL(10, temp, 5, q_00+0+437, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+437, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+436, 10, t_01+0+436, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+432, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+432, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+431, 10, t_01+0+431, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+427, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+427, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+426, 10, t_01+0+426, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+422, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+422, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+421, 10, t_01+0+421, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+417, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+417, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+416, 10, t_01+0+416, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+412, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+412, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+411, 10, t_01+0+411, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+407, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+407, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+406, 10, t_01+0+406, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+402, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+402, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+401, 10, t_01+0+401, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+397, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+397, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+396, 10, t_01+0+396, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+392, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+392, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+391, 10, t_01+0+391, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+387, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+387, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+386, 10, t_01+0+386, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+382, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+382, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+381, 10, t_01+0+381, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+377, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+377, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+376, 10, t_01+0+376, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+372, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+372, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+371, 10, t_01+0+371, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+367, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+367, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+366, 10, t_01+0+366, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+362, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+362, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+361, 10, t_01+0+361, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+357, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+357, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+356, 10, t_01+0+356, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+352, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+352, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+351, 10, t_01+0+351, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+347, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+347, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+346, 10, t_01+0+346, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+342, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+342, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+341, 10, t_01+0+341, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+337, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+337, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+336, 10, t_01+0+336, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+332, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+332, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+331, 10, t_01+0+331, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+327, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+327, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+326, 10, t_01+0+326, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+322, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+322, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+321, 10, t_01+0+321, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+317, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+317, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+316, 10, t_01+0+316, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+312, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+312, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+311, 10, t_01+0+311, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+307, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+307, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+306, 10, t_01+0+306, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+302, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+302, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+301, 10, t_01+0+301, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+297, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+297, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+296, 10, t_01+0+296, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+292, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+292, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+291, 10, t_01+0+291, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+287, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+287, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+286, 10, t_01+0+286, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+282, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+282, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+281, 10, t_01+0+281, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+277, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+277, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+276, 10, t_01+0+276, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+272, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+272, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+271, 10, t_01+0+271, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+267, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+267, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+266, 10, t_01+0+266, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+262, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+262, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+261, 10, t_01+0+261, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+257, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+257, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+256, 10, t_01+0+256, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+252, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+252, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+251, 10, t_01+0+251, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+247, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+247, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+246, 10, t_01+0+246, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+242, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+242, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+241, 10, t_01+0+241, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+237, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+237, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+236, 10, t_01+0+236, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+232, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+232, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+231, 10, t_01+0+231, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+227, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+227, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+226, 10, t_01+0+226, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+222, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+222, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+221, 10, t_01+0+221, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+217, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+217, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+216, 10, t_01+0+216, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+212, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+212, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+211, 10, t_01+0+211, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+207, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+207, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+206, 10, t_01+0+206, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+202, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+202, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+201, 10, t_01+0+201, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+197, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+197, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+196, 10, t_01+0+196, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+192, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+192, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+191, 10, t_01+0+191, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+187, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+187, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+186, 10, t_01+0+186, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+182, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+182, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+181, 10, t_01+0+181, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+177, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+177, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+176, 10, t_01+0+176, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+172, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+172, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+171, 10, t_01+0+171, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+167, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+167, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+166, 10, t_01+0+166, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+162, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+162, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+161, 10, t_01+0+161, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+157, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+157, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+156, 10, t_01+0+156, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+152, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+152, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+151, 10, t_01+0+151, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+147, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+147, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+146, 10, t_01+0+146, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+142, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+142, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+141, 10, t_01+0+141, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+137, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+137, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+136, 10, t_01+0+136, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+132, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+132, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+131, 10, t_01+0+131, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+127, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+127, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+126, 10, t_01+0+126, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+122, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+122, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+121, 10, t_01+0+121, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+117, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+117, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+116, 10, t_01+0+116, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+112, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+112, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+111, 10, t_01+0+111, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+107, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+107, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+106, 10, t_01+0+106, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+102, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+102, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+101, 10, t_01+0+101, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+97, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+97, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+96, 10, t_01+0+96, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+92, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+92, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+91, 10, t_01+0+91, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+87, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+87, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+86, 10, t_01+0+86, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+82, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+82, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+81, 10, t_01+0+81, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+77, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+77, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+76, 10, t_01+0+76, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+72, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+72, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+71, 10, t_01+0+71, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+67, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+67, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+66, 10, t_01+0+66, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+62, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+62, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+61, 10, t_01+0+61, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+57, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+57, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+56, 10, t_01+0+56, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+52, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+52, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+51, 10, t_01+0+51, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+47, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+47, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+46, 10, t_01+0+46, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+42, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+42, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+41, 10, t_01+0+41, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+37, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+37, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+36, 10, t_01+0+36, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+32, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+32, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+31, 10, t_01+0+31, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+27, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+27, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+26, 10, t_01+0+26, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+22, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+22, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+21, 10, t_01+0+21, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+17, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+17, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+16, 10, t_01+0+16, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+12, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+12, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+11, 10, t_01+0+11, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+7, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+7, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+6, 10, t_01+0+6, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+2, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+2, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+1, 10, t_01+0+1, 10, temp);
	GF2X_MUL(4, temp, 2, p_01+0+3, 2, q_00+0);
	GF2X_MUL(4, temp2, 2, p_11+0+3, 2, q_01+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+2, 4, t_01+0+2, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+0+1, 2, q_00+0);
	GF2X_MUL(4, temp2, 2, p_11+0+1, 2, q_01+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+0, 4, t_01+0+0, 4, temp);
	GF2X_MUL(2, temp, 1, q_00+0+1, 1, p_01+0);
	GF2X_MUL(2, temp2, 1, q_01+0+1, 1, p_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_01+0+0, 2, t_01+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+0+0, 1, p_01+0);
	GF2X_MUL(2, temp2, 1, q_01+0+0, 1, p_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, t_01+0, 1, t_01+0, 1, temp+1);
	memset(t_10+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(884, temp, 442, p_00+0+5, 442, q_10+0);
	GF2X_MUL(884, temp2, 442, p_10+0+5, 442, q_11+0);
	gf2x_add(884, t_10+0+4, 884, temp, 884, temp2);
	GF2X_MUL(10, temp, 5, q_10+0+437, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+437, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+436, 10, t_10+0+436, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+432, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+432, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+431, 10, t_10+0+431, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+427, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+427, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+426, 10, t_10+0+426, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+422, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+422, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+421, 10, t_10+0+421, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+417, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+417, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+416, 10, t_10+0+416, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+412, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+412, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+411, 10, t_10+0+411, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+407, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+407, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+406, 10, t_10+0+406, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+402, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+402, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+401, 10, t_10+0+401, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+397, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+397, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+396, 10, t_10+0+396, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+392, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+392, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+391, 10, t_10+0+391, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+387, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+387, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+386, 10, t_10+0+386, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+382, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+382, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+381, 10, t_10+0+381, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+377, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+377, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+376, 10, t_10+0+376, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+372, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+372, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+371, 10, t_10+0+371, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+367, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+367, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+366, 10, t_10+0+366, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+362, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+362, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+361, 10, t_10+0+361, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+357, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+357, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+356, 10, t_10+0+356, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+352, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+352, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+351, 10, t_10+0+351, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+347, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+347, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+346, 10, t_10+0+346, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+342, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+342, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+341, 10, t_10+0+341, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+337, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+337, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+336, 10, t_10+0+336, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+332, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+332, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+331, 10, t_10+0+331, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+327, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+327, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+326, 10, t_10+0+326, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+322, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+322, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+321, 10, t_10+0+321, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+317, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+317, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+316, 10, t_10+0+316, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+312, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+312, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+311, 10, t_10+0+311, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+307, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+307, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+306, 10, t_10+0+306, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+302, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+302, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+301, 10, t_10+0+301, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+297, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+297, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+296, 10, t_10+0+296, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+292, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+292, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+291, 10, t_10+0+291, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+287, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+287, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+286, 10, t_10+0+286, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+282, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+282, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+281, 10, t_10+0+281, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+277, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+277, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+276, 10, t_10+0+276, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+272, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+272, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+271, 10, t_10+0+271, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+267, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+267, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+266, 10, t_10+0+266, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+262, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+262, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+261, 10, t_10+0+261, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+257, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+257, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+256, 10, t_10+0+256, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+252, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+252, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+251, 10, t_10+0+251, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+247, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+247, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+246, 10, t_10+0+246, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+242, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+242, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+241, 10, t_10+0+241, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+237, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+237, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+236, 10, t_10+0+236, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+232, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+232, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+231, 10, t_10+0+231, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+227, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+227, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+226, 10, t_10+0+226, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+222, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+222, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+221, 10, t_10+0+221, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+217, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+217, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+216, 10, t_10+0+216, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+212, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+212, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+211, 10, t_10+0+211, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+207, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+207, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+206, 10, t_10+0+206, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+202, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+202, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+201, 10, t_10+0+201, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+197, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+197, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+196, 10, t_10+0+196, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+192, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+192, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+191, 10, t_10+0+191, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+187, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+187, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+186, 10, t_10+0+186, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+182, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+182, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+181, 10, t_10+0+181, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+177, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+177, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+176, 10, t_10+0+176, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+172, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+172, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+171, 10, t_10+0+171, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+167, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+167, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+166, 10, t_10+0+166, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+162, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+162, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+161, 10, t_10+0+161, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+157, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+157, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+156, 10, t_10+0+156, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+152, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+152, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+151, 10, t_10+0+151, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+147, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+147, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+146, 10, t_10+0+146, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+142, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+142, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+141, 10, t_10+0+141, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+137, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+137, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+136, 10, t_10+0+136, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+132, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+132, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+131, 10, t_10+0+131, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+127, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+127, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+126, 10, t_10+0+126, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+122, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+122, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+121, 10, t_10+0+121, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+117, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+117, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+116, 10, t_10+0+116, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+112, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+112, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+111, 10, t_10+0+111, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+107, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+107, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+106, 10, t_10+0+106, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+102, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+102, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+101, 10, t_10+0+101, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+97, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+97, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+96, 10, t_10+0+96, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+92, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+92, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+91, 10, t_10+0+91, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+87, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+87, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+86, 10, t_10+0+86, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+82, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+82, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+81, 10, t_10+0+81, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+77, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+77, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+76, 10, t_10+0+76, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+72, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+72, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+71, 10, t_10+0+71, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+67, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+67, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+66, 10, t_10+0+66, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+62, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+62, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+61, 10, t_10+0+61, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+57, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+57, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+56, 10, t_10+0+56, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+52, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+52, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+51, 10, t_10+0+51, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+47, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+47, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+46, 10, t_10+0+46, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+42, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+42, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+41, 10, t_10+0+41, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+37, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+37, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+36, 10, t_10+0+36, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+32, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+32, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+31, 10, t_10+0+31, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+27, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+27, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+26, 10, t_10+0+26, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+22, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+22, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+21, 10, t_10+0+21, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+17, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+17, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+16, 10, t_10+0+16, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+12, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+12, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+11, 10, t_10+0+11, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+7, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+7, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+6, 10, t_10+0+6, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+2, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+2, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+1, 10, t_10+0+1, 10, temp);
	GF2X_MUL(4, temp, 2, p_00+0+3, 2, q_10+0);
	GF2X_MUL(4, temp2, 2, p_10+0+3, 2, q_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+2, 4, t_10+0+2, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+0+1, 2, q_10+0);
	GF2X_MUL(4, temp2, 2, p_10+0+1, 2, q_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+0, 4, t_10+0+0, 4, temp);
	GF2X_MUL(2, temp, 1, q_10+0+1, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, q_11+0+1, 1, p_10+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_10+0+0, 2, t_10+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+0+0, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, q_11+0+0, 1, p_10+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, t_10+0, 1, t_10+0, 1, temp+1);
	memset(t_11+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(884, temp, 442, p_01+0+5, 442, q_10+0);
	GF2X_MUL(884, temp2, 442, p_11+0+5, 442, q_11+0);
	gf2x_add(884, t_11+0+4, 884, temp, 884, temp2);
	GF2X_MUL(10, temp, 5, q_10+0+437, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+437, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+436, 10, t_11+0+436, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+432, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+432, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+431, 10, t_11+0+431, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+427, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+427, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+426, 10, t_11+0+426, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+422, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+422, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+421, 10, t_11+0+421, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+417, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+417, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+416, 10, t_11+0+416, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+412, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+412, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+411, 10, t_11+0+411, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+407, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+407, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+406, 10, t_11+0+406, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+402, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+402, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+401, 10, t_11+0+401, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+397, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+397, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+396, 10, t_11+0+396, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+392, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+392, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+391, 10, t_11+0+391, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+387, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+387, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+386, 10, t_11+0+386, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+382, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+382, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+381, 10, t_11+0+381, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+377, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+377, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+376, 10, t_11+0+376, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+372, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+372, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+371, 10, t_11+0+371, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+367, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+367, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+366, 10, t_11+0+366, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+362, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+362, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+361, 10, t_11+0+361, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+357, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+357, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+356, 10, t_11+0+356, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+352, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+352, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+351, 10, t_11+0+351, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+347, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+347, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+346, 10, t_11+0+346, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+342, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+342, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+341, 10, t_11+0+341, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+337, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+337, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+336, 10, t_11+0+336, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+332, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+332, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+331, 10, t_11+0+331, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+327, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+327, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+326, 10, t_11+0+326, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+322, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+322, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+321, 10, t_11+0+321, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+317, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+317, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+316, 10, t_11+0+316, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+312, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+312, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+311, 10, t_11+0+311, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+307, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+307, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+306, 10, t_11+0+306, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+302, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+302, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+301, 10, t_11+0+301, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+297, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+297, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+296, 10, t_11+0+296, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+292, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+292, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+291, 10, t_11+0+291, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+287, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+287, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+286, 10, t_11+0+286, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+282, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+282, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+281, 10, t_11+0+281, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+277, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+277, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+276, 10, t_11+0+276, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+272, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+272, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+271, 10, t_11+0+271, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+267, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+267, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+266, 10, t_11+0+266, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+262, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+262, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+261, 10, t_11+0+261, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+257, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+257, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+256, 10, t_11+0+256, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+252, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+252, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+251, 10, t_11+0+251, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+247, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+247, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+246, 10, t_11+0+246, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+242, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+242, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+241, 10, t_11+0+241, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+237, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+237, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+236, 10, t_11+0+236, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+232, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+232, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+231, 10, t_11+0+231, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+227, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+227, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+226, 10, t_11+0+226, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+222, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+222, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+221, 10, t_11+0+221, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+217, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+217, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+216, 10, t_11+0+216, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+212, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+212, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+211, 10, t_11+0+211, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+207, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+207, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+206, 10, t_11+0+206, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+202, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+202, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+201, 10, t_11+0+201, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+197, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+197, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+196, 10, t_11+0+196, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+192, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+192, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+191, 10, t_11+0+191, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+187, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+187, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+186, 10, t_11+0+186, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+182, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+182, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+181, 10, t_11+0+181, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+177, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+177, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+176, 10, t_11+0+176, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+172, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+172, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+171, 10, t_11+0+171, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+167, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+167, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+166, 10, t_11+0+166, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+162, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+162, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+161, 10, t_11+0+161, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+157, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+157, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+156, 10, t_11+0+156, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+152, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+152, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+151, 10, t_11+0+151, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+147, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+147, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+146, 10, t_11+0+146, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+142, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+142, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+141, 10, t_11+0+141, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+137, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+137, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+136, 10, t_11+0+136, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+132, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+132, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+131, 10, t_11+0+131, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+127, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+127, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+126, 10, t_11+0+126, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+122, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+122, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+121, 10, t_11+0+121, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+117, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+117, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+116, 10, t_11+0+116, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+112, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+112, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+111, 10, t_11+0+111, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+107, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+107, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+106, 10, t_11+0+106, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+102, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+102, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+101, 10, t_11+0+101, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+97, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+97, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+96, 10, t_11+0+96, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+92, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+92, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+91, 10, t_11+0+91, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+87, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+87, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+86, 10, t_11+0+86, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+82, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+82, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+81, 10, t_11+0+81, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+77, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+77, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+76, 10, t_11+0+76, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+72, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+72, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+71, 10, t_11+0+71, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+67, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+67, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+66, 10, t_11+0+66, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+62, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+62, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+61, 10, t_11+0+61, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+57, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+57, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+56, 10, t_11+0+56, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+52, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+52, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+51, 10, t_11+0+51, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+47, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+47, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+46, 10, t_11+0+46, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+42, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+42, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+41, 10, t_11+0+41, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+37, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+37, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+36, 10, t_11+0+36, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+32, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+32, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+31, 10, t_11+0+31, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+27, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+27, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+26, 10, t_11+0+26, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+22, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+22, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+21, 10, t_11+0+21, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+17, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+17, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+16, 10, t_11+0+16, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+12, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+12, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+11, 10, t_11+0+11, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+7, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+7, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+6, 10, t_11+0+6, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+2, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+2, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+1, 10, t_11+0+1, 10, temp);
	GF2X_MUL(4, temp, 2, p_01+0+3, 2, q_10+0);
	GF2X_MUL(4, temp2, 2, p_11+0+3, 2, q_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+2, 4, t_11+0+2, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+0+1, 2, q_10+0);
	GF2X_MUL(4, temp2, 2, p_11+0+1, 2, q_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+0, 4, t_11+0+0, 4, temp);
	GF2X_MUL(2, temp, 1, q_10+0+1, 1, p_01+0);
	GF2X_MUL(2, temp2, 1, q_11+0+1, 1, p_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_11+0+0, 2, t_11+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+0+0, 1, p_01+0);
	GF2X_MUL(2, temp2, 1, q_11+0+0, 1, p_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, t_11+0, 1, t_11+0, 1, temp+1);
	

	return delta;
}