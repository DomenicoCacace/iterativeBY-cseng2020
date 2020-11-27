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

int jumpdivstep_30803(int n, int delta, int nf, DIGIT *f, DIGIT *g, DIGIT *t_00, DIGIT *t_01, DIGIT *t_10, DIGIT *t_11, float x) {
	DIGIT p_00[975];
	DIGIT p_01[975];
	DIGIT p_10[975];
	DIGIT p_11[975];
	
	DIGIT q_00[961];
	DIGIT q_01[961];
	DIGIT q_10[961];
	DIGIT q_11[961];
	
	DIGIT f_sum[2918];
	DIGIT g_sum[2918];
	
	DIGIT temp[1928];
	DIGIT temp2[1928];
	

	delta = divstepsx_256(255, delta, f+959, g+959, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f+955+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g+955+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+955+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g+955+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f+955+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g+955+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+955+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g+955+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f+947+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g+947+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f+947+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g+947+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f+947+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g+947+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f+947+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g+947+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f+931+16, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g+931+16, 16, p_01+947);
	gf2x_add(32, f_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f+931+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g+931+0, 16, p_01+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+2830, 16, f_sum+2830, 16, temp+16);
	right_bit_shift_n(32, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f+931+16, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g+931+16, 16, p_11+947);
	gf2x_add(32, g_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f+931+0, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g+931+0, 16, p_11+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+2830, 16, g_sum+2830, 16, temp+16);
	right_bit_shift_n(32, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2843, g_sum+2843, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, q_00+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, q_01+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, q_10+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, q_11+933+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 5
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_10+947);
	gf2x_add(32, p_00+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_11+947);
	gf2x_add(32, p_01+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_10+947);
	gf2x_add(32, p_10+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_11+947);
	gf2x_add(32, p_11+915+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 4080, depth: 4
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f+899+32, 32, p_00+915);
	GF2X_MUL(64, temp2, 32, g+899+32, 32, p_01+915);
	gf2x_add(64, f_sum+2733+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f+899+0, 32, p_00+915);
	GF2X_MUL(64, temp2, 32, g+899+0, 32, p_01+915);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+2733, 32, f_sum+2733, 32, temp+32);
	right_bit_shift_n(64, f_sum+2733, 56);
	GF2X_MUL(64, temp, 32, f+899+32, 32, p_10+915);
	GF2X_MUL(64, temp2, 32, g+899+32, 32, p_11+915);
	gf2x_add(64, g_sum+2733+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f+899+0, 32, p_10+915);
	GF2X_MUL(64, temp2, 32, g+899+0, 32, p_11+915);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+2733, 32, g_sum+2733, 32, temp+32);
	right_bit_shift_n(64, g_sum+2733, 56);
	

	delta = divstepsx_256(255, delta, f_sum+2762, g_sum+2762, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2758+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2758+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2758+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2758+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2758+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2758+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2758+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2758+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2750+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2750+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2750+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2750+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2750+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2750+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2750+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2750+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2734+16, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+16, 16, p_01+947);
	gf2x_add(32, f_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2734+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+0, 16, p_01+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+2830, 16, f_sum+2830, 16, temp+16);
	right_bit_shift_n(32, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2734+16, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+16, 16, p_11+947);
	gf2x_add(32, g_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2734+0, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+0, 16, p_11+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+2830, 16, g_sum+2830, 16, temp+16);
	right_bit_shift_n(32, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2843, g_sum+2843, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, q_00+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, q_01+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, q_10+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, q_11+933+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 5
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_10+947);
	gf2x_add(32, q_00+901+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_11+947);
	gf2x_add(32, q_01+901+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_10+947);
	gf2x_add(32, q_10+901+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_11+947);
	gf2x_add(32, q_11+901+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4080, depth: 4
	GF2X_MUL(64, temp, 32, q_00+901+0, 32, p_00+915);
	GF2X_MUL(64, temp2, 32, q_01+901+0, 32, p_10+915);
	gf2x_add(64, p_00+851+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_00+901+0, 32, p_01+915);
	GF2X_MUL(64, temp2, 32, q_01+901+0, 32, p_11+915);
	gf2x_add(64, p_01+851+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+901+0, 32, p_00+915);
	GF2X_MUL(64, temp2, 32, q_11+901+0, 32, p_10+915);
	gf2x_add(64, p_10+851+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+901+0, 32, p_01+915);
	GF2X_MUL(64, temp2, 32, q_11+901+0, 32, p_11+915);
	gf2x_add(64, p_11+851+0, 64, temp, 64, temp2);
	

	// Calculating left operands: n: 7905, depth: 3
	// Digits to shift: 63
	// Displacement: 64
	GF2X_MUL(128, temp, 64, f+839+60, 64, p_00+851);
	GF2X_MUL(128, temp2, 64, g+839+60, 64, p_01+851);
	gf2x_add(124, f_sum+2544, 124, temp+4, 124, temp2+4);
	GF2X_MUL(120, temp, 60, p_00+851+4, 60, f+839);
	GF2X_MUL(120, temp2, 60, p_01+851+4, 60, g+839);
	gf2x_add(120, temp, 120, temp, 120, temp2);
	gf2x_add(60, f_sum+2544, 60, f_sum+2544, 60, temp+60);
	right_bit_shift_n(124, f_sum+2544, 48);
	GF2X_MUL(128, temp, 64, f+839+60, 64, p_10+851);
	GF2X_MUL(128, temp2, 64, g+839+60, 64, p_11+851);
	gf2x_add(124, g_sum+2544, 124, temp+4, 124, temp2+4);
	GF2X_MUL(120, temp, 60, p_10+851+4, 60, f+839);
	GF2X_MUL(120, temp2, 60, p_11+851+4, 60, g+839);
	gf2x_add(120, temp, 120, temp, 120, temp2);
	gf2x_add(60, g_sum+2544, 60, g_sum+2544, 60, temp+60);
	right_bit_shift_n(124, g_sum+2544, 48);
	

	delta = divstepsx_256(255, delta, f_sum+2601, g_sum+2601, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2597+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2597+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2597+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2597+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2589+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2589+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2589+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2589+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2573+16, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+16, 16, p_01+947);
	gf2x_add(32, f_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2573+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+0, 16, p_01+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+2830, 16, f_sum+2830, 16, temp+16);
	right_bit_shift_n(32, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2573+16, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+16, 16, p_11+947);
	gf2x_add(32, g_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2573+0, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+0, 16, p_11+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+2830, 16, g_sum+2830, 16, temp+16);
	right_bit_shift_n(32, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2843, g_sum+2843, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, q_00+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, q_01+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, q_10+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, q_11+933+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 5
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_10+947);
	gf2x_add(32, p_00+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_11+947);
	gf2x_add(32, p_01+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_10+947);
	gf2x_add(32, p_10+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_11+947);
	gf2x_add(32, p_11+915+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 3825, depth: 4
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+2545+28, 32, p_00+915);
	GF2X_MUL(64, temp2, 32, g_sum+2545+28, 32, p_01+915);
	gf2x_add(60, f_sum+2733, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, f_sum+2545);
	GF2X_MUL(56, temp2, 28, p_01+915+4, 28, g_sum+2545);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2733, 28, f_sum+2733, 28, temp+28);
	right_bit_shift_n(60, f_sum+2733, 56);
	GF2X_MUL(64, temp, 32, f_sum+2545+28, 32, p_10+915);
	GF2X_MUL(64, temp2, 32, g_sum+2545+28, 32, p_11+915);
	gf2x_add(60, g_sum+2733, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_10+915+4, 28, f_sum+2545);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, g_sum+2545);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2733, 28, g_sum+2733, 28, temp+28);
	right_bit_shift_n(60, g_sum+2733, 56);
	

	delta = divstepsx_256(255, delta, f_sum+2758, g_sum+2758, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2754+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2754+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2754+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2754+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2746+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2746+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2746+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2746+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2734+12, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+12, 16, p_01+947);
	gf2x_add(28, f_sum+2830, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, f_sum+2734);
	GF2X_MUL(24, temp2, 12, p_01+947+4, 12, g_sum+2734);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2830, 12, f_sum+2830, 12, temp+12);
	right_bit_shift_n(28, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2734+12, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+12, 16, p_11+947);
	gf2x_add(28, g_sum+2830, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+947+4, 12, f_sum+2734);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, g_sum+2734);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2830, 12, g_sum+2830, 12, temp+12);
	right_bit_shift_n(28, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2839, g_sum+2839, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2835+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2835+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2835+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2835+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+4, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+4, 8, p_01+963);
	gf2x_add(12, f_sum+2879, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, f_sum+2831);
	GF2X_MUL(8, temp2, 4, p_01+963+4, 4, g_sum+2831);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2879, 4, f_sum+2879, 4, temp+4);
	right_bit_shift_n(12, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+4, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+4, 8, p_11+963);
	gf2x_add(12, g_sum+2879, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+963+4, 4, f_sum+2831);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, g_sum+2831);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2879, 4, g_sum+2879, 4, temp+4);
	right_bit_shift_n(12, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2880, g_sum+2880, q_00+949, q_01+949, q_10+949, q_11+949);

	// Recombining results: n: 765, depth: 6
	memset(q_00+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, q_00+949);
	GF2X_MUL(8, temp2, 4, p_10+963+4, 4, q_01+949);
	gf2x_add(8, q_00+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+949+0, 4, p_00+963);
	GF2X_MUL(8, temp2, 4, q_01+949+0, 4, p_10+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+933+0, 8, q_00+933+0, 8, temp);
	memset(q_01+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+963+4, 4, q_00+949);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, q_01+949);
	gf2x_add(8, q_01+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+949+0, 4, p_01+963);
	GF2X_MUL(8, temp2, 4, q_01+949+0, 4, p_11+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+933+0, 8, q_01+933+0, 8, temp);
	memset(q_10+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, q_10+949);
	GF2X_MUL(8, temp2, 4, p_10+963+4, 4, q_11+949);
	gf2x_add(8, q_10+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+949+0, 4, p_00+963);
	GF2X_MUL(8, temp2, 4, q_11+949+0, 4, p_10+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+933+0, 8, q_10+933+0, 8, temp);
	memset(q_11+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+963+4, 4, q_10+949);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, q_11+949);
	gf2x_add(8, q_11+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+949+0, 4, p_01+963);
	GF2X_MUL(8, temp2, 4, q_11+949+0, 4, p_11+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+933+0, 8, q_11+933+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, q_00+933);
	GF2X_MUL(24, temp2, 12, p_10+947+4, 12, q_01+933);
	gf2x_add(24, q_00+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+933+8, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+8, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+8, 8, q_00+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+4, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+4, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+4, 8, q_00+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+0, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+0, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+0, 8, q_00+901+0, 8, temp);
	memset(q_01+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+947+4, 12, q_00+933);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, q_01+933);
	gf2x_add(24, q_01+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+933+8, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+8, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+8, 8, q_01+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+4, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+4, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+4, 8, q_01+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+0, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+0, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+0, 8, q_01+901+0, 8, temp);
	memset(q_10+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, q_10+933);
	GF2X_MUL(24, temp2, 12, p_10+947+4, 12, q_11+933);
	gf2x_add(24, q_10+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+933+8, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+8, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+8, 8, q_10+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+4, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+4, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+4, 8, q_10+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+0, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+0, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+0, 8, q_10+901+0, 8, temp);
	memset(q_11+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+947+4, 12, q_10+933);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, q_11+933);
	gf2x_add(24, q_11+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+933+8, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+8, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+8, 8, q_11+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+4, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+4, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+4, 8, q_11+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+0, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+0, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+0, 8, q_11+901+0, 8, temp);
	

	// Recombining results: n: 3825, depth: 4
	memset(q_00+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, q_00+901);
	GF2X_MUL(56, temp2, 28, p_10+915+4, 28, q_01+901);
	gf2x_add(56, q_00+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+901+24, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+24, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+24, 8, q_00+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+20, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+20, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+20, 8, q_00+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+16, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+16, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+16, 8, q_00+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+12, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+12, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+12, 8, q_00+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+8, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+8, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+8, 8, q_00+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+4, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+4, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+4, 8, q_00+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+0, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+0, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+0, 8, q_00+841+0, 8, temp);
	memset(q_01+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+915+4, 28, q_00+901);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, q_01+901);
	gf2x_add(56, q_01+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+901+24, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+24, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+24, 8, q_01+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+20, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+20, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+20, 8, q_01+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+16, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+16, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+16, 8, q_01+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+12, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+12, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+12, 8, q_01+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+8, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+8, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+8, 8, q_01+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+4, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+4, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+4, 8, q_01+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+0, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+0, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+0, 8, q_01+841+0, 8, temp);
	memset(q_10+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, q_10+901);
	GF2X_MUL(56, temp2, 28, p_10+915+4, 28, q_11+901);
	gf2x_add(56, q_10+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+901+24, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+24, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+24, 8, q_10+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+20, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+20, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+20, 8, q_10+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+16, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+16, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+16, 8, q_10+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+12, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+12, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+12, 8, q_10+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+8, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+8, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+8, 8, q_10+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+4, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+4, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+4, 8, q_10+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+0, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+0, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+0, 8, q_10+841+0, 8, temp);
	memset(q_11+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+915+4, 28, q_10+901);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, q_11+901);
	gf2x_add(56, q_11+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+901+24, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+24, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+24, 8, q_11+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+20, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+20, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+20, 8, q_11+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+16, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+16, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+16, 8, q_11+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+12, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+12, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+12, 8, q_11+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+8, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+8, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+8, 8, q_11+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+4, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+4, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+4, 8, q_11+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+0, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+0, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+0, 8, q_11+841+0, 8, temp);
	

	// Recombining results: n: 7905, depth: 3
	memset(p_00+727, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(120, temp, 60, p_00+851+4, 60, q_00+841);
	GF2X_MUL(120, temp2, 60, p_10+851+4, 60, q_01+841);
	gf2x_add(120, p_00+727+4, 120, temp, 120, temp2);
	GF2X_MUL(8, temp, 4, q_00+841+56, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+56, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+56, 8, p_00+727+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+52, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+52, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+52, 8, p_00+727+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+48, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+48, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+48, 8, p_00+727+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+44, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+44, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+44, 8, p_00+727+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+40, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+40, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+40, 8, p_00+727+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+36, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+36, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+36, 8, p_00+727+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+32, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+32, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+32, 8, p_00+727+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+28, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+28, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+28, 8, p_00+727+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+24, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+24, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+24, 8, p_00+727+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+20, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+20, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+20, 8, p_00+727+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+16, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+16, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+16, 8, p_00+727+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+12, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+12, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+12, 8, p_00+727+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+8, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+8, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+8, 8, p_00+727+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+4, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+4, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+4, 8, p_00+727+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+0, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+0, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+0, 8, p_00+727+0, 8, temp);
	memset(p_01+727, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(120, temp, 60, p_01+851+4, 60, q_00+841);
	GF2X_MUL(120, temp2, 60, p_11+851+4, 60, q_01+841);
	gf2x_add(120, p_01+727+4, 120, temp, 120, temp2);
	GF2X_MUL(8, temp, 4, q_00+841+56, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+56, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+56, 8, p_01+727+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+52, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+52, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+52, 8, p_01+727+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+48, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+48, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+48, 8, p_01+727+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+44, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+44, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+44, 8, p_01+727+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+40, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+40, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+40, 8, p_01+727+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+36, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+36, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+36, 8, p_01+727+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+32, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+32, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+32, 8, p_01+727+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+28, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+28, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+28, 8, p_01+727+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+24, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+24, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+24, 8, p_01+727+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+20, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+20, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+20, 8, p_01+727+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+16, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+16, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+16, 8, p_01+727+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+12, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+12, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+12, 8, p_01+727+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+8, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+8, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+8, 8, p_01+727+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+4, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+4, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+4, 8, p_01+727+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+0, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+0, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+0, 8, p_01+727+0, 8, temp);
	memset(p_10+727, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(120, temp, 60, p_00+851+4, 60, q_10+841);
	GF2X_MUL(120, temp2, 60, p_10+851+4, 60, q_11+841);
	gf2x_add(120, p_10+727+4, 120, temp, 120, temp2);
	GF2X_MUL(8, temp, 4, q_10+841+56, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+56, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+56, 8, p_10+727+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+52, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+52, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+52, 8, p_10+727+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+48, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+48, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+48, 8, p_10+727+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+44, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+44, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+44, 8, p_10+727+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+40, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+40, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+40, 8, p_10+727+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+36, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+36, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+36, 8, p_10+727+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+32, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+32, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+32, 8, p_10+727+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+28, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+28, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+28, 8, p_10+727+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+24, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+24, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+24, 8, p_10+727+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+20, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+20, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+20, 8, p_10+727+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+16, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+16, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+16, 8, p_10+727+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+12, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+12, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+12, 8, p_10+727+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+8, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+8, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+8, 8, p_10+727+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+4, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+4, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+4, 8, p_10+727+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+0, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+0, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+0, 8, p_10+727+0, 8, temp);
	memset(p_11+727, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(120, temp, 60, p_01+851+4, 60, q_10+841);
	GF2X_MUL(120, temp2, 60, p_11+851+4, 60, q_11+841);
	gf2x_add(120, p_11+727+4, 120, temp, 120, temp2);
	GF2X_MUL(8, temp, 4, q_10+841+56, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+56, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+56, 8, p_11+727+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+52, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+52, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+52, 8, p_11+727+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+48, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+48, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+48, 8, p_11+727+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+44, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+44, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+44, 8, p_11+727+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+40, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+40, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+40, 8, p_11+727+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+36, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+36, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+36, 8, p_11+727+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+32, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+32, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+32, 8, p_11+727+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+28, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+28, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+28, 8, p_11+727+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+24, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+24, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+24, 8, p_11+727+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+20, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+20, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+20, 8, p_11+727+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+16, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+16, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+16, 8, p_11+727+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+12, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+12, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+12, 8, p_11+727+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+8, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+8, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+8, 8, p_11+727+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+4, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+4, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+4, 8, p_11+727+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+0, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+0, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+0, 8, p_11+727+0, 8, temp);
	

	// Calculating left operands: n: 15555, depth: 2
	// Digits to shift: 123
	// Displacement: 124
	GF2X_MUL(248, temp, 124, f+719+120, 124, p_00+727);
	GF2X_MUL(248, temp2, 124, g+719+120, 124, p_01+727);
	gf2x_add(244, f_sum+2175, 244, temp+4, 244, temp2+4);
	GF2X_MUL(240, temp, 120, p_00+727+4, 120, f+719);
	GF2X_MUL(240, temp2, 120, p_01+727+4, 120, g+719);
	gf2x_add(240, temp, 240, temp, 240, temp2);
	gf2x_add(120, f_sum+2175, 120, f_sum+2175, 120, temp+120);
	right_bit_shift_n(244, f_sum+2175, 33);
	GF2X_MUL(248, temp, 124, f+719+120, 124, p_10+727);
	GF2X_MUL(248, temp2, 124, g+719+120, 124, p_11+727);
	gf2x_add(244, g_sum+2175, 244, temp+4, 244, temp2+4);
	GF2X_MUL(240, temp, 120, p_10+727+4, 120, f+719);
	GF2X_MUL(240, temp2, 120, p_11+727+4, 120, g+719);
	gf2x_add(240, temp, 240, temp, 240, temp2);
	gf2x_add(120, g_sum+2175, 120, g_sum+2175, 120, temp+120);
	right_bit_shift_n(244, g_sum+2175, 33);
	

	delta = divstepsx_256(255, delta, f_sum+2292, g_sum+2292, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2288+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2288+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2288+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2288+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2288+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2288+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2288+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2288+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2280+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2280+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2280+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2280+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2280+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2280+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2280+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2280+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2264+16, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2264+16, 16, p_01+947);
	gf2x_add(32, f_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2264+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2264+0, 16, p_01+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+2830, 16, f_sum+2830, 16, temp+16);
	right_bit_shift_n(32, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2264+16, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2264+16, 16, p_11+947);
	gf2x_add(32, g_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2264+0, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2264+0, 16, p_11+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+2830, 16, g_sum+2830, 16, temp+16);
	right_bit_shift_n(32, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2843, g_sum+2843, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, q_00+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, q_01+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, q_10+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, q_11+933+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 5
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_10+947);
	gf2x_add(32, p_00+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_11+947);
	gf2x_add(32, p_01+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_10+947);
	gf2x_add(32, p_10+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_11+947);
	gf2x_add(32, p_11+915+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 3825, depth: 4
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+2236+28, 32, p_00+915);
	GF2X_MUL(64, temp2, 32, g_sum+2236+28, 32, p_01+915);
	gf2x_add(60, f_sum+2733, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, f_sum+2236);
	GF2X_MUL(56, temp2, 28, p_01+915+4, 28, g_sum+2236);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2733, 28, f_sum+2733, 28, temp+28);
	right_bit_shift_n(60, f_sum+2733, 56);
	GF2X_MUL(64, temp, 32, f_sum+2236+28, 32, p_10+915);
	GF2X_MUL(64, temp2, 32, g_sum+2236+28, 32, p_11+915);
	gf2x_add(60, g_sum+2733, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_10+915+4, 28, f_sum+2236);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, g_sum+2236);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2733, 28, g_sum+2733, 28, temp+28);
	right_bit_shift_n(60, g_sum+2733, 56);
	

	delta = divstepsx_256(255, delta, f_sum+2758, g_sum+2758, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2754+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2754+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2754+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2754+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2746+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2746+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2746+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2746+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2734+12, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+12, 16, p_01+947);
	gf2x_add(28, f_sum+2830, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, f_sum+2734);
	GF2X_MUL(24, temp2, 12, p_01+947+4, 12, g_sum+2734);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2830, 12, f_sum+2830, 12, temp+12);
	right_bit_shift_n(28, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2734+12, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+12, 16, p_11+947);
	gf2x_add(28, g_sum+2830, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+947+4, 12, f_sum+2734);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, g_sum+2734);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2830, 12, g_sum+2830, 12, temp+12);
	right_bit_shift_n(28, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2839, g_sum+2839, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2835+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2835+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2835+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2835+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+4, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+4, 8, p_01+963);
	gf2x_add(12, f_sum+2879, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, f_sum+2831);
	GF2X_MUL(8, temp2, 4, p_01+963+4, 4, g_sum+2831);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2879, 4, f_sum+2879, 4, temp+4);
	right_bit_shift_n(12, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+4, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+4, 8, p_11+963);
	gf2x_add(12, g_sum+2879, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+963+4, 4, f_sum+2831);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, g_sum+2831);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2879, 4, g_sum+2879, 4, temp+4);
	right_bit_shift_n(12, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2880, g_sum+2880, q_00+949, q_01+949, q_10+949, q_11+949);

	// Recombining results: n: 765, depth: 6
	memset(q_00+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, q_00+949);
	GF2X_MUL(8, temp2, 4, p_10+963+4, 4, q_01+949);
	gf2x_add(8, q_00+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+949+0, 4, p_00+963);
	GF2X_MUL(8, temp2, 4, q_01+949+0, 4, p_10+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+933+0, 8, q_00+933+0, 8, temp);
	memset(q_01+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+963+4, 4, q_00+949);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, q_01+949);
	gf2x_add(8, q_01+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+949+0, 4, p_01+963);
	GF2X_MUL(8, temp2, 4, q_01+949+0, 4, p_11+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+933+0, 8, q_01+933+0, 8, temp);
	memset(q_10+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, q_10+949);
	GF2X_MUL(8, temp2, 4, p_10+963+4, 4, q_11+949);
	gf2x_add(8, q_10+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+949+0, 4, p_00+963);
	GF2X_MUL(8, temp2, 4, q_11+949+0, 4, p_10+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+933+0, 8, q_10+933+0, 8, temp);
	memset(q_11+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+963+4, 4, q_10+949);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, q_11+949);
	gf2x_add(8, q_11+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+949+0, 4, p_01+963);
	GF2X_MUL(8, temp2, 4, q_11+949+0, 4, p_11+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+933+0, 8, q_11+933+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, q_00+933);
	GF2X_MUL(24, temp2, 12, p_10+947+4, 12, q_01+933);
	gf2x_add(24, q_00+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+933+8, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+8, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+8, 8, q_00+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+4, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+4, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+4, 8, q_00+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+0, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+0, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+0, 8, q_00+901+0, 8, temp);
	memset(q_01+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+947+4, 12, q_00+933);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, q_01+933);
	gf2x_add(24, q_01+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+933+8, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+8, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+8, 8, q_01+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+4, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+4, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+4, 8, q_01+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+0, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+0, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+0, 8, q_01+901+0, 8, temp);
	memset(q_10+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, q_10+933);
	GF2X_MUL(24, temp2, 12, p_10+947+4, 12, q_11+933);
	gf2x_add(24, q_10+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+933+8, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+8, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+8, 8, q_10+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+4, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+4, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+4, 8, q_10+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+0, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+0, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+0, 8, q_10+901+0, 8, temp);
	memset(q_11+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+947+4, 12, q_10+933);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, q_11+933);
	gf2x_add(24, q_11+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+933+8, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+8, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+8, 8, q_11+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+4, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+4, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+4, 8, q_11+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+0, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+0, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+0, 8, q_11+901+0, 8, temp);
	

	// Recombining results: n: 3825, depth: 4
	memset(p_00+851, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, q_00+901);
	GF2X_MUL(56, temp2, 28, p_10+915+4, 28, q_01+901);
	gf2x_add(56, p_00+851+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+901+24, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+24, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+24, 8, p_00+851+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+20, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+20, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+20, 8, p_00+851+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+16, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+16, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+16, 8, p_00+851+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+12, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+12, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+12, 8, p_00+851+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+8, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+8, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+8, 8, p_00+851+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+4, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+4, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+4, 8, p_00+851+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+0, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+0, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+0, 8, p_00+851+0, 8, temp);
	memset(p_01+851, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+915+4, 28, q_00+901);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, q_01+901);
	gf2x_add(56, p_01+851+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+901+24, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+24, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+24, 8, p_01+851+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+20, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+20, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+20, 8, p_01+851+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+16, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+16, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+16, 8, p_01+851+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+12, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+12, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+12, 8, p_01+851+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+8, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+8, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+8, 8, p_01+851+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+4, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+4, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+4, 8, p_01+851+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+0, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+0, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+0, 8, p_01+851+0, 8, temp);
	memset(p_10+851, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, q_10+901);
	GF2X_MUL(56, temp2, 28, p_10+915+4, 28, q_11+901);
	gf2x_add(56, p_10+851+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+901+24, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+24, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+24, 8, p_10+851+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+20, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+20, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+20, 8, p_10+851+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+16, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+16, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+16, 8, p_10+851+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+12, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+12, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+12, 8, p_10+851+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+8, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+8, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+8, 8, p_10+851+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+4, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+4, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+4, 8, p_10+851+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+0, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+0, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+0, 8, p_10+851+0, 8, temp);
	memset(p_11+851, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+915+4, 28, q_10+901);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, q_11+901);
	gf2x_add(56, p_11+851+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+901+24, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+24, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+24, 8, p_11+851+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+20, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+20, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+20, 8, p_11+851+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+16, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+16, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+16, 8, p_11+851+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+12, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+12, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+12, 8, p_11+851+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+8, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+8, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+8, 8, p_11+851+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+4, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+4, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+4, 8, p_11+851+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+0, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+0, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+0, 8, p_11+851+0, 8, temp);
	

	// Calculating left operands: n: 7650, depth: 3
	// Digits to shift: 59
	// Displacement: 60
	GF2X_MUL(120, temp, 60, f_sum+2176+60, 60, p_00+851);
	GF2X_MUL(120, temp2, 60, g_sum+2176+60, 60, p_01+851);
	gf2x_add(120, f_sum+2544+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, f_sum+2176+0, 60, p_00+851);
	GF2X_MUL(120, temp2, 60, g_sum+2176+0, 60, p_01+851);
	gf2x_add(120, temp, 120, temp, 120, temp2);
	gf2x_add(60, f_sum+2544, 60, f_sum+2544, 60, temp+60);
	right_bit_shift_n(120, f_sum+2544, 49);
	GF2X_MUL(120, temp, 60, f_sum+2176+60, 60, p_10+851);
	GF2X_MUL(120, temp2, 60, g_sum+2176+60, 60, p_11+851);
	gf2x_add(120, g_sum+2544+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, f_sum+2176+0, 60, p_10+851);
	GF2X_MUL(120, temp2, 60, g_sum+2176+0, 60, p_11+851);
	gf2x_add(120, temp, 120, temp, 120, temp2);
	gf2x_add(60, g_sum+2544, 60, g_sum+2544, 60, temp+60);
	right_bit_shift_n(120, g_sum+2544, 49);
	

	delta = divstepsx_256(255, delta, f_sum+2601, g_sum+2601, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2597+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2597+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2597+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2597+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2589+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2589+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2589+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2589+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2573+16, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+16, 16, p_01+947);
	gf2x_add(32, f_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2573+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+0, 16, p_01+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+2830, 16, f_sum+2830, 16, temp+16);
	right_bit_shift_n(32, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2573+16, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+16, 16, p_11+947);
	gf2x_add(32, g_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2573+0, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+0, 16, p_11+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+2830, 16, g_sum+2830, 16, temp+16);
	right_bit_shift_n(32, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2843, g_sum+2843, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, q_00+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, q_01+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, q_10+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, q_11+933+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 5
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_10+947);
	gf2x_add(32, p_00+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_11+947);
	gf2x_add(32, p_01+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_10+947);
	gf2x_add(32, p_10+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_11+947);
	gf2x_add(32, p_11+915+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 3825, depth: 4
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+2545+28, 32, p_00+915);
	GF2X_MUL(64, temp2, 32, g_sum+2545+28, 32, p_01+915);
	gf2x_add(60, f_sum+2733, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, f_sum+2545);
	GF2X_MUL(56, temp2, 28, p_01+915+4, 28, g_sum+2545);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2733, 28, f_sum+2733, 28, temp+28);
	right_bit_shift_n(60, f_sum+2733, 56);
	GF2X_MUL(64, temp, 32, f_sum+2545+28, 32, p_10+915);
	GF2X_MUL(64, temp2, 32, g_sum+2545+28, 32, p_11+915);
	gf2x_add(60, g_sum+2733, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_10+915+4, 28, f_sum+2545);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, g_sum+2545);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2733, 28, g_sum+2733, 28, temp+28);
	right_bit_shift_n(60, g_sum+2733, 56);
	

	delta = divstepsx_256(255, delta, f_sum+2758, g_sum+2758, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2754+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2754+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2754+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2754+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2746+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2746+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2746+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2746+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2734+12, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+12, 16, p_01+947);
	gf2x_add(28, f_sum+2830, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, f_sum+2734);
	GF2X_MUL(24, temp2, 12, p_01+947+4, 12, g_sum+2734);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2830, 12, f_sum+2830, 12, temp+12);
	right_bit_shift_n(28, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2734+12, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+12, 16, p_11+947);
	gf2x_add(28, g_sum+2830, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+947+4, 12, f_sum+2734);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, g_sum+2734);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2830, 12, g_sum+2830, 12, temp+12);
	right_bit_shift_n(28, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2839, g_sum+2839, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2835+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2835+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2835+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2835+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+4, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+4, 8, p_01+963);
	gf2x_add(12, f_sum+2879, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, f_sum+2831);
	GF2X_MUL(8, temp2, 4, p_01+963+4, 4, g_sum+2831);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2879, 4, f_sum+2879, 4, temp+4);
	right_bit_shift_n(12, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+4, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+4, 8, p_11+963);
	gf2x_add(12, g_sum+2879, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+963+4, 4, f_sum+2831);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, g_sum+2831);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2879, 4, g_sum+2879, 4, temp+4);
	right_bit_shift_n(12, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2880, g_sum+2880, q_00+949, q_01+949, q_10+949, q_11+949);

	// Recombining results: n: 765, depth: 6
	memset(q_00+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, q_00+949);
	GF2X_MUL(8, temp2, 4, p_10+963+4, 4, q_01+949);
	gf2x_add(8, q_00+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+949+0, 4, p_00+963);
	GF2X_MUL(8, temp2, 4, q_01+949+0, 4, p_10+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+933+0, 8, q_00+933+0, 8, temp);
	memset(q_01+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+963+4, 4, q_00+949);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, q_01+949);
	gf2x_add(8, q_01+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+949+0, 4, p_01+963);
	GF2X_MUL(8, temp2, 4, q_01+949+0, 4, p_11+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+933+0, 8, q_01+933+0, 8, temp);
	memset(q_10+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, q_10+949);
	GF2X_MUL(8, temp2, 4, p_10+963+4, 4, q_11+949);
	gf2x_add(8, q_10+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+949+0, 4, p_00+963);
	GF2X_MUL(8, temp2, 4, q_11+949+0, 4, p_10+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+933+0, 8, q_10+933+0, 8, temp);
	memset(q_11+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+963+4, 4, q_10+949);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, q_11+949);
	gf2x_add(8, q_11+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+949+0, 4, p_01+963);
	GF2X_MUL(8, temp2, 4, q_11+949+0, 4, p_11+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+933+0, 8, q_11+933+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, q_00+933);
	GF2X_MUL(24, temp2, 12, p_10+947+4, 12, q_01+933);
	gf2x_add(24, q_00+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+933+8, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+8, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+8, 8, q_00+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+4, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+4, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+4, 8, q_00+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+0, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+0, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+0, 8, q_00+901+0, 8, temp);
	memset(q_01+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+947+4, 12, q_00+933);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, q_01+933);
	gf2x_add(24, q_01+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+933+8, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+8, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+8, 8, q_01+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+4, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+4, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+4, 8, q_01+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+0, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+0, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+0, 8, q_01+901+0, 8, temp);
	memset(q_10+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, q_10+933);
	GF2X_MUL(24, temp2, 12, p_10+947+4, 12, q_11+933);
	gf2x_add(24, q_10+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+933+8, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+8, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+8, 8, q_10+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+4, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+4, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+4, 8, q_10+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+0, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+0, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+0, 8, q_10+901+0, 8, temp);
	memset(q_11+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+947+4, 12, q_10+933);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, q_11+933);
	gf2x_add(24, q_11+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+933+8, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+8, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+8, 8, q_11+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+4, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+4, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+4, 8, q_11+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+0, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+0, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+0, 8, q_11+901+0, 8, temp);
	

	// Recombining results: n: 3825, depth: 4
	memset(q_00+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, q_00+901);
	GF2X_MUL(56, temp2, 28, p_10+915+4, 28, q_01+901);
	gf2x_add(56, q_00+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+901+24, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+24, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+24, 8, q_00+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+20, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+20, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+20, 8, q_00+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+16, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+16, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+16, 8, q_00+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+12, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+12, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+12, 8, q_00+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+8, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+8, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+8, 8, q_00+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+4, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+4, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+4, 8, q_00+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+0, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+0, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+0, 8, q_00+841+0, 8, temp);
	memset(q_01+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+915+4, 28, q_00+901);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, q_01+901);
	gf2x_add(56, q_01+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+901+24, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+24, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+24, 8, q_01+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+20, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+20, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+20, 8, q_01+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+16, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+16, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+16, 8, q_01+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+12, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+12, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+12, 8, q_01+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+8, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+8, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+8, 8, q_01+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+4, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+4, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+4, 8, q_01+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+0, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+0, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+0, 8, q_01+841+0, 8, temp);
	memset(q_10+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, q_10+901);
	GF2X_MUL(56, temp2, 28, p_10+915+4, 28, q_11+901);
	gf2x_add(56, q_10+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+901+24, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+24, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+24, 8, q_10+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+20, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+20, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+20, 8, q_10+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+16, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+16, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+16, 8, q_10+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+12, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+12, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+12, 8, q_10+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+8, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+8, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+8, 8, q_10+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+4, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+4, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+4, 8, q_10+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+0, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+0, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+0, 8, q_10+841+0, 8, temp);
	memset(q_11+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+915+4, 28, q_10+901);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, q_11+901);
	gf2x_add(56, q_11+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+901+24, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+24, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+24, 8, q_11+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+20, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+20, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+20, 8, q_11+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+16, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+16, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+16, 8, q_11+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+12, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+12, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+12, 8, q_11+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+8, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+8, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+8, 8, q_11+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+4, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+4, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+4, 8, q_11+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+0, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+0, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+0, 8, q_11+841+0, 8, temp);
	

	// Recombining results: n: 7650, depth: 3
	GF2X_MUL(120, temp, 60, q_00+841+0, 60, p_00+851);
	GF2X_MUL(120, temp2, 60, q_01+841+0, 60, p_10+851);
	gf2x_add(120, q_00+721+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, q_00+841+0, 60, p_01+851);
	GF2X_MUL(120, temp2, 60, q_01+841+0, 60, p_11+851);
	gf2x_add(120, q_01+721+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, q_10+841+0, 60, p_00+851);
	GF2X_MUL(120, temp2, 60, q_11+841+0, 60, p_10+851);
	gf2x_add(120, q_10+721+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, q_10+841+0, 60, p_01+851);
	GF2X_MUL(120, temp2, 60, q_11+841+0, 60, p_11+851);
	gf2x_add(120, q_11+721+0, 120, temp, 120, temp2);
	

	// Recombining results: n: 15555, depth: 2
	memset(p_00+483, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(240, temp, 120, p_00+727+4, 120, q_00+721);
	GF2X_MUL(240, temp2, 120, p_10+727+4, 120, q_01+721);
	gf2x_add(240, p_00+483+4, 240, temp, 240, temp2);
	GF2X_MUL(8, temp, 4, q_00+721+116, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+116, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+116, 8, p_00+483+116, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+112, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+112, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+112, 8, p_00+483+112, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+108, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+108, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+108, 8, p_00+483+108, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+104, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+104, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+104, 8, p_00+483+104, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+100, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+100, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+100, 8, p_00+483+100, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+96, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+96, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+96, 8, p_00+483+96, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+92, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+92, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+92, 8, p_00+483+92, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+88, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+88, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+88, 8, p_00+483+88, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+84, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+84, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+84, 8, p_00+483+84, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+80, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+80, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+80, 8, p_00+483+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+76, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+76, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+76, 8, p_00+483+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+72, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+72, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+72, 8, p_00+483+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+68, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+68, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+68, 8, p_00+483+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+64, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+64, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+64, 8, p_00+483+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+60, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+60, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+60, 8, p_00+483+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+56, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+56, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+56, 8, p_00+483+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+52, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+52, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+52, 8, p_00+483+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+48, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+48, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+48, 8, p_00+483+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+44, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+44, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+44, 8, p_00+483+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+40, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+40, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+40, 8, p_00+483+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+36, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+36, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+36, 8, p_00+483+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+32, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+32, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+32, 8, p_00+483+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+28, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+28, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+28, 8, p_00+483+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+24, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+24, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+24, 8, p_00+483+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+20, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+20, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+20, 8, p_00+483+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+16, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+16, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+16, 8, p_00+483+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+12, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+12, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+12, 8, p_00+483+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+8, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+8, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+8, 8, p_00+483+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+4, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+4, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+4, 8, p_00+483+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+0, 8, p_00+483+0, 8, temp);
	memset(p_01+483, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(240, temp, 120, p_01+727+4, 120, q_00+721);
	GF2X_MUL(240, temp2, 120, p_11+727+4, 120, q_01+721);
	gf2x_add(240, p_01+483+4, 240, temp, 240, temp2);
	GF2X_MUL(8, temp, 4, q_00+721+116, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+116, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+116, 8, p_01+483+116, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+112, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+112, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+112, 8, p_01+483+112, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+108, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+108, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+108, 8, p_01+483+108, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+104, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+104, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+104, 8, p_01+483+104, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+100, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+100, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+100, 8, p_01+483+100, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+96, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+96, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+96, 8, p_01+483+96, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+92, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+92, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+92, 8, p_01+483+92, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+88, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+88, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+88, 8, p_01+483+88, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+84, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+84, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+84, 8, p_01+483+84, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+80, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+80, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+80, 8, p_01+483+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+76, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+76, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+76, 8, p_01+483+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+72, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+72, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+72, 8, p_01+483+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+68, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+68, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+68, 8, p_01+483+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+64, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+64, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+64, 8, p_01+483+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+60, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+60, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+60, 8, p_01+483+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+56, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+56, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+56, 8, p_01+483+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+52, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+52, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+52, 8, p_01+483+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+48, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+48, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+48, 8, p_01+483+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+44, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+44, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+44, 8, p_01+483+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+40, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+40, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+40, 8, p_01+483+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+36, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+36, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+36, 8, p_01+483+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+32, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+32, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+32, 8, p_01+483+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+28, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+28, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+28, 8, p_01+483+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+24, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+24, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+24, 8, p_01+483+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+20, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+20, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+20, 8, p_01+483+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+16, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+16, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+16, 8, p_01+483+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+12, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+12, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+12, 8, p_01+483+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+8, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+8, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+8, 8, p_01+483+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+4, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+4, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+4, 8, p_01+483+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+0, 8, p_01+483+0, 8, temp);
	memset(p_10+483, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(240, temp, 120, p_00+727+4, 120, q_10+721);
	GF2X_MUL(240, temp2, 120, p_10+727+4, 120, q_11+721);
	gf2x_add(240, p_10+483+4, 240, temp, 240, temp2);
	GF2X_MUL(8, temp, 4, q_10+721+116, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+116, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+116, 8, p_10+483+116, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+112, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+112, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+112, 8, p_10+483+112, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+108, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+108, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+108, 8, p_10+483+108, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+104, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+104, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+104, 8, p_10+483+104, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+100, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+100, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+100, 8, p_10+483+100, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+96, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+96, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+96, 8, p_10+483+96, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+92, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+92, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+92, 8, p_10+483+92, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+88, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+88, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+88, 8, p_10+483+88, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+84, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+84, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+84, 8, p_10+483+84, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+80, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+80, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+80, 8, p_10+483+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+76, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+76, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+76, 8, p_10+483+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+72, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+72, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+72, 8, p_10+483+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+68, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+68, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+68, 8, p_10+483+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+64, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+64, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+64, 8, p_10+483+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+60, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+60, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+60, 8, p_10+483+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+56, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+56, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+56, 8, p_10+483+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+52, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+52, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+52, 8, p_10+483+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+48, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+48, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+48, 8, p_10+483+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+44, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+44, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+44, 8, p_10+483+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+40, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+40, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+40, 8, p_10+483+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+36, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+36, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+36, 8, p_10+483+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+32, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+32, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+32, 8, p_10+483+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+28, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+28, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+28, 8, p_10+483+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+24, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+24, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+24, 8, p_10+483+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+20, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+20, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+20, 8, p_10+483+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+16, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+16, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+16, 8, p_10+483+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+12, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+12, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+12, 8, p_10+483+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+8, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+8, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+8, 8, p_10+483+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+4, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+4, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+4, 8, p_10+483+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+0, 8, p_10+483+0, 8, temp);
	memset(p_11+483, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(240, temp, 120, p_01+727+4, 120, q_10+721);
	GF2X_MUL(240, temp2, 120, p_11+727+4, 120, q_11+721);
	gf2x_add(240, p_11+483+4, 240, temp, 240, temp2);
	GF2X_MUL(8, temp, 4, q_10+721+116, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+116, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+116, 8, p_11+483+116, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+112, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+112, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+112, 8, p_11+483+112, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+108, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+108, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+108, 8, p_11+483+108, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+104, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+104, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+104, 8, p_11+483+104, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+100, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+100, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+100, 8, p_11+483+100, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+96, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+96, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+96, 8, p_11+483+96, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+92, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+92, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+92, 8, p_11+483+92, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+88, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+88, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+88, 8, p_11+483+88, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+84, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+84, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+84, 8, p_11+483+84, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+80, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+80, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+80, 8, p_11+483+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+76, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+76, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+76, 8, p_11+483+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+72, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+72, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+72, 8, p_11+483+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+68, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+68, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+68, 8, p_11+483+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+64, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+64, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+64, 8, p_11+483+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+60, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+60, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+60, 8, p_11+483+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+56, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+56, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+56, 8, p_11+483+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+52, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+52, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+52, 8, p_11+483+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+48, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+48, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+48, 8, p_11+483+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+44, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+44, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+44, 8, p_11+483+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+40, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+40, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+40, 8, p_11+483+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+36, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+36, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+36, 8, p_11+483+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+32, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+32, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+32, 8, p_11+483+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+28, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+28, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+28, 8, p_11+483+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+24, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+24, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+24, 8, p_11+483+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+20, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+20, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+20, 8, p_11+483+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+16, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+16, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+16, 8, p_11+483+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+12, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+12, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+12, 8, p_11+483+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+8, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+8, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+8, 8, p_11+483+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+4, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+4, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+4, 8, p_11+483+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+0, 8, p_11+483+0, 8, temp);
	

	// Calculating left operands: n: 30855, depth: 1
	// Digits to shift: 243
	// Displacement: 243
	GF2X_MUL(488, temp, 244, f+480+239, 244, p_00+483);
	GF2X_MUL(488, temp2, 244, g+480+239, 244, p_01+483);
	gf2x_add(484, f_sum+1447, 484, temp+4, 484, temp2+4);
	GF2X_MUL(478, temp, 239, p_00+483+5, 239, f+480);
	GF2X_MUL(478, temp2, 239, p_01+483+5, 239, g+480);
	gf2x_add(478, temp, 478, temp, 478, temp2);
	gf2x_add(240, f_sum+1447, 240, f_sum+1447, 240, temp+238);
	GF2X_MUL(10, temp, 5, f+480+234, 5, p_00+483);
	GF2X_MUL(10, temp2, 5, g+480+234, 5, p_01+483);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(1, f_sum+1447, 1, f_sum+1447, 1, temp+9);
	right_bit_shift_n(483, f_sum+1447, 3);
	GF2X_MUL(488, temp, 244, f+480+239, 244, p_10+483);
	GF2X_MUL(488, temp2, 244, g+480+239, 244, p_11+483);
	gf2x_add(484, g_sum+1447, 484, temp+4, 484, temp2+4);
	GF2X_MUL(478, temp, 239, p_10+483+5, 239, f+480);
	GF2X_MUL(478, temp2, 239, p_11+483+5, 239, g+480);
	gf2x_add(478, temp, 478, temp, 478, temp2);
	gf2x_add(240, g_sum+1447, 240, g_sum+1447, 240, temp+238);
	GF2X_MUL(10, temp, 5, f+480+234, 5, p_10+483);
	GF2X_MUL(10, temp2, 5, g+480+234, 5, p_11+483);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(1, g_sum+1447, 1, g_sum+1447, 1, temp+9);
	right_bit_shift_n(483, g_sum+1447, 3);
	

	delta = divstepsx_256(255, delta, f_sum+1684, g_sum+1684, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1680+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+1680+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1680+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+1680+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+1680+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+1680+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1680+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+1680+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1672+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+1672+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1672+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+1672+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+1672+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+1672+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1672+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+1672+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1656+16, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+1656+16, 16, p_01+947);
	gf2x_add(32, f_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1656+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+1656+0, 16, p_01+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+2830, 16, f_sum+2830, 16, temp+16);
	right_bit_shift_n(32, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+1656+16, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+1656+16, 16, p_11+947);
	gf2x_add(32, g_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1656+0, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+1656+0, 16, p_11+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+2830, 16, g_sum+2830, 16, temp+16);
	right_bit_shift_n(32, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2843, g_sum+2843, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, q_00+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, q_01+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, q_10+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, q_11+933+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 5
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_10+947);
	gf2x_add(32, p_00+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_11+947);
	gf2x_add(32, p_01+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_10+947);
	gf2x_add(32, p_10+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_11+947);
	gf2x_add(32, p_11+915+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 3825, depth: 4
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+1628+28, 32, p_00+915);
	GF2X_MUL(64, temp2, 32, g_sum+1628+28, 32, p_01+915);
	gf2x_add(60, f_sum+2733, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, f_sum+1628);
	GF2X_MUL(56, temp2, 28, p_01+915+4, 28, g_sum+1628);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2733, 28, f_sum+2733, 28, temp+28);
	right_bit_shift_n(60, f_sum+2733, 56);
	GF2X_MUL(64, temp, 32, f_sum+1628+28, 32, p_10+915);
	GF2X_MUL(64, temp2, 32, g_sum+1628+28, 32, p_11+915);
	gf2x_add(60, g_sum+2733, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_10+915+4, 28, f_sum+1628);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, g_sum+1628);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2733, 28, g_sum+2733, 28, temp+28);
	right_bit_shift_n(60, g_sum+2733, 56);
	

	delta = divstepsx_256(255, delta, f_sum+2758, g_sum+2758, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2754+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2754+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2754+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2754+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2746+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2746+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2746+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2746+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2734+12, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+12, 16, p_01+947);
	gf2x_add(28, f_sum+2830, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, f_sum+2734);
	GF2X_MUL(24, temp2, 12, p_01+947+4, 12, g_sum+2734);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2830, 12, f_sum+2830, 12, temp+12);
	right_bit_shift_n(28, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2734+12, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+12, 16, p_11+947);
	gf2x_add(28, g_sum+2830, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+947+4, 12, f_sum+2734);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, g_sum+2734);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2830, 12, g_sum+2830, 12, temp+12);
	right_bit_shift_n(28, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2839, g_sum+2839, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2835+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2835+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2835+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2835+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+4, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+4, 8, p_01+963);
	gf2x_add(12, f_sum+2879, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, f_sum+2831);
	GF2X_MUL(8, temp2, 4, p_01+963+4, 4, g_sum+2831);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2879, 4, f_sum+2879, 4, temp+4);
	right_bit_shift_n(12, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+4, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+4, 8, p_11+963);
	gf2x_add(12, g_sum+2879, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+963+4, 4, f_sum+2831);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, g_sum+2831);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2879, 4, g_sum+2879, 4, temp+4);
	right_bit_shift_n(12, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2880, g_sum+2880, q_00+949, q_01+949, q_10+949, q_11+949);

	// Recombining results: n: 765, depth: 6
	memset(q_00+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, q_00+949);
	GF2X_MUL(8, temp2, 4, p_10+963+4, 4, q_01+949);
	gf2x_add(8, q_00+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+949+0, 4, p_00+963);
	GF2X_MUL(8, temp2, 4, q_01+949+0, 4, p_10+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+933+0, 8, q_00+933+0, 8, temp);
	memset(q_01+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+963+4, 4, q_00+949);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, q_01+949);
	gf2x_add(8, q_01+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+949+0, 4, p_01+963);
	GF2X_MUL(8, temp2, 4, q_01+949+0, 4, p_11+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+933+0, 8, q_01+933+0, 8, temp);
	memset(q_10+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, q_10+949);
	GF2X_MUL(8, temp2, 4, p_10+963+4, 4, q_11+949);
	gf2x_add(8, q_10+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+949+0, 4, p_00+963);
	GF2X_MUL(8, temp2, 4, q_11+949+0, 4, p_10+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+933+0, 8, q_10+933+0, 8, temp);
	memset(q_11+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+963+4, 4, q_10+949);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, q_11+949);
	gf2x_add(8, q_11+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+949+0, 4, p_01+963);
	GF2X_MUL(8, temp2, 4, q_11+949+0, 4, p_11+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+933+0, 8, q_11+933+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, q_00+933);
	GF2X_MUL(24, temp2, 12, p_10+947+4, 12, q_01+933);
	gf2x_add(24, q_00+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+933+8, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+8, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+8, 8, q_00+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+4, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+4, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+4, 8, q_00+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+0, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+0, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+0, 8, q_00+901+0, 8, temp);
	memset(q_01+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+947+4, 12, q_00+933);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, q_01+933);
	gf2x_add(24, q_01+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+933+8, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+8, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+8, 8, q_01+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+4, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+4, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+4, 8, q_01+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+0, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+0, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+0, 8, q_01+901+0, 8, temp);
	memset(q_10+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, q_10+933);
	GF2X_MUL(24, temp2, 12, p_10+947+4, 12, q_11+933);
	gf2x_add(24, q_10+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+933+8, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+8, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+8, 8, q_10+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+4, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+4, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+4, 8, q_10+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+0, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+0, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+0, 8, q_10+901+0, 8, temp);
	memset(q_11+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+947+4, 12, q_10+933);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, q_11+933);
	gf2x_add(24, q_11+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+933+8, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+8, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+8, 8, q_11+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+4, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+4, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+4, 8, q_11+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+0, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+0, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+0, 8, q_11+901+0, 8, temp);
	

	// Recombining results: n: 3825, depth: 4
	memset(p_00+851, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, q_00+901);
	GF2X_MUL(56, temp2, 28, p_10+915+4, 28, q_01+901);
	gf2x_add(56, p_00+851+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+901+24, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+24, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+24, 8, p_00+851+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+20, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+20, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+20, 8, p_00+851+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+16, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+16, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+16, 8, p_00+851+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+12, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+12, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+12, 8, p_00+851+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+8, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+8, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+8, 8, p_00+851+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+4, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+4, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+4, 8, p_00+851+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+0, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+0, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+0, 8, p_00+851+0, 8, temp);
	memset(p_01+851, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+915+4, 28, q_00+901);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, q_01+901);
	gf2x_add(56, p_01+851+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+901+24, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+24, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+24, 8, p_01+851+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+20, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+20, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+20, 8, p_01+851+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+16, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+16, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+16, 8, p_01+851+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+12, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+12, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+12, 8, p_01+851+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+8, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+8, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+8, 8, p_01+851+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+4, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+4, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+4, 8, p_01+851+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+0, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+0, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+0, 8, p_01+851+0, 8, temp);
	memset(p_10+851, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, q_10+901);
	GF2X_MUL(56, temp2, 28, p_10+915+4, 28, q_11+901);
	gf2x_add(56, p_10+851+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+901+24, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+24, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+24, 8, p_10+851+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+20, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+20, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+20, 8, p_10+851+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+16, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+16, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+16, 8, p_10+851+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+12, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+12, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+12, 8, p_10+851+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+8, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+8, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+8, 8, p_10+851+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+4, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+4, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+4, 8, p_10+851+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+0, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+0, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+0, 8, p_10+851+0, 8, temp);
	memset(p_11+851, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+915+4, 28, q_10+901);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, q_11+901);
	gf2x_add(56, p_11+851+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+901+24, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+24, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+24, 8, p_11+851+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+20, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+20, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+20, 8, p_11+851+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+16, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+16, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+16, 8, p_11+851+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+12, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+12, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+12, 8, p_11+851+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+8, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+8, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+8, 8, p_11+851+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+4, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+4, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+4, 8, p_11+851+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+0, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+0, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+0, 8, p_11+851+0, 8, temp);
	

	// Calculating left operands: n: 7650, depth: 3
	// Digits to shift: 59
	// Displacement: 60
	GF2X_MUL(120, temp, 60, f_sum+1568+60, 60, p_00+851);
	GF2X_MUL(120, temp2, 60, g_sum+1568+60, 60, p_01+851);
	gf2x_add(120, f_sum+2544+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, f_sum+1568+0, 60, p_00+851);
	GF2X_MUL(120, temp2, 60, g_sum+1568+0, 60, p_01+851);
	gf2x_add(120, temp, 120, temp, 120, temp2);
	gf2x_add(60, f_sum+2544, 60, f_sum+2544, 60, temp+60);
	right_bit_shift_n(120, f_sum+2544, 49);
	GF2X_MUL(120, temp, 60, f_sum+1568+60, 60, p_10+851);
	GF2X_MUL(120, temp2, 60, g_sum+1568+60, 60, p_11+851);
	gf2x_add(120, g_sum+2544+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, f_sum+1568+0, 60, p_10+851);
	GF2X_MUL(120, temp2, 60, g_sum+1568+0, 60, p_11+851);
	gf2x_add(120, temp, 120, temp, 120, temp2);
	gf2x_add(60, g_sum+2544, 60, g_sum+2544, 60, temp+60);
	right_bit_shift_n(120, g_sum+2544, 49);
	

	delta = divstepsx_256(255, delta, f_sum+2601, g_sum+2601, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2597+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2597+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2597+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2597+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2589+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2589+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2589+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2589+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2573+16, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+16, 16, p_01+947);
	gf2x_add(32, f_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2573+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+0, 16, p_01+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+2830, 16, f_sum+2830, 16, temp+16);
	right_bit_shift_n(32, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2573+16, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+16, 16, p_11+947);
	gf2x_add(32, g_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2573+0, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+0, 16, p_11+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+2830, 16, g_sum+2830, 16, temp+16);
	right_bit_shift_n(32, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2843, g_sum+2843, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, q_00+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, q_01+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, q_10+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, q_11+933+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 5
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_10+947);
	gf2x_add(32, p_00+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_11+947);
	gf2x_add(32, p_01+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_10+947);
	gf2x_add(32, p_10+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_11+947);
	gf2x_add(32, p_11+915+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 3825, depth: 4
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+2545+28, 32, p_00+915);
	GF2X_MUL(64, temp2, 32, g_sum+2545+28, 32, p_01+915);
	gf2x_add(60, f_sum+2733, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, f_sum+2545);
	GF2X_MUL(56, temp2, 28, p_01+915+4, 28, g_sum+2545);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2733, 28, f_sum+2733, 28, temp+28);
	right_bit_shift_n(60, f_sum+2733, 56);
	GF2X_MUL(64, temp, 32, f_sum+2545+28, 32, p_10+915);
	GF2X_MUL(64, temp2, 32, g_sum+2545+28, 32, p_11+915);
	gf2x_add(60, g_sum+2733, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_10+915+4, 28, f_sum+2545);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, g_sum+2545);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2733, 28, g_sum+2733, 28, temp+28);
	right_bit_shift_n(60, g_sum+2733, 56);
	

	delta = divstepsx_256(255, delta, f_sum+2758, g_sum+2758, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2754+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2754+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2754+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2754+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2746+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2746+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2746+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2746+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2734+12, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+12, 16, p_01+947);
	gf2x_add(28, f_sum+2830, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, f_sum+2734);
	GF2X_MUL(24, temp2, 12, p_01+947+4, 12, g_sum+2734);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2830, 12, f_sum+2830, 12, temp+12);
	right_bit_shift_n(28, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2734+12, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+12, 16, p_11+947);
	gf2x_add(28, g_sum+2830, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+947+4, 12, f_sum+2734);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, g_sum+2734);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2830, 12, g_sum+2830, 12, temp+12);
	right_bit_shift_n(28, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2839, g_sum+2839, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2835+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2835+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2835+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2835+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+4, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+4, 8, p_01+963);
	gf2x_add(12, f_sum+2879, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, f_sum+2831);
	GF2X_MUL(8, temp2, 4, p_01+963+4, 4, g_sum+2831);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2879, 4, f_sum+2879, 4, temp+4);
	right_bit_shift_n(12, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+4, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+4, 8, p_11+963);
	gf2x_add(12, g_sum+2879, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+963+4, 4, f_sum+2831);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, g_sum+2831);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2879, 4, g_sum+2879, 4, temp+4);
	right_bit_shift_n(12, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2880, g_sum+2880, q_00+949, q_01+949, q_10+949, q_11+949);

	// Recombining results: n: 765, depth: 6
	memset(q_00+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, q_00+949);
	GF2X_MUL(8, temp2, 4, p_10+963+4, 4, q_01+949);
	gf2x_add(8, q_00+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+949+0, 4, p_00+963);
	GF2X_MUL(8, temp2, 4, q_01+949+0, 4, p_10+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+933+0, 8, q_00+933+0, 8, temp);
	memset(q_01+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+963+4, 4, q_00+949);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, q_01+949);
	gf2x_add(8, q_01+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+949+0, 4, p_01+963);
	GF2X_MUL(8, temp2, 4, q_01+949+0, 4, p_11+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+933+0, 8, q_01+933+0, 8, temp);
	memset(q_10+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, q_10+949);
	GF2X_MUL(8, temp2, 4, p_10+963+4, 4, q_11+949);
	gf2x_add(8, q_10+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+949+0, 4, p_00+963);
	GF2X_MUL(8, temp2, 4, q_11+949+0, 4, p_10+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+933+0, 8, q_10+933+0, 8, temp);
	memset(q_11+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+963+4, 4, q_10+949);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, q_11+949);
	gf2x_add(8, q_11+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+949+0, 4, p_01+963);
	GF2X_MUL(8, temp2, 4, q_11+949+0, 4, p_11+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+933+0, 8, q_11+933+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, q_00+933);
	GF2X_MUL(24, temp2, 12, p_10+947+4, 12, q_01+933);
	gf2x_add(24, q_00+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+933+8, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+8, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+8, 8, q_00+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+4, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+4, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+4, 8, q_00+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+0, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+0, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+0, 8, q_00+901+0, 8, temp);
	memset(q_01+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+947+4, 12, q_00+933);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, q_01+933);
	gf2x_add(24, q_01+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+933+8, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+8, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+8, 8, q_01+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+4, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+4, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+4, 8, q_01+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+0, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+0, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+0, 8, q_01+901+0, 8, temp);
	memset(q_10+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, q_10+933);
	GF2X_MUL(24, temp2, 12, p_10+947+4, 12, q_11+933);
	gf2x_add(24, q_10+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+933+8, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+8, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+8, 8, q_10+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+4, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+4, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+4, 8, q_10+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+0, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+0, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+0, 8, q_10+901+0, 8, temp);
	memset(q_11+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+947+4, 12, q_10+933);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, q_11+933);
	gf2x_add(24, q_11+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+933+8, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+8, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+8, 8, q_11+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+4, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+4, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+4, 8, q_11+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+0, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+0, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+0, 8, q_11+901+0, 8, temp);
	

	// Recombining results: n: 3825, depth: 4
	memset(q_00+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, q_00+901);
	GF2X_MUL(56, temp2, 28, p_10+915+4, 28, q_01+901);
	gf2x_add(56, q_00+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+901+24, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+24, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+24, 8, q_00+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+20, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+20, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+20, 8, q_00+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+16, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+16, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+16, 8, q_00+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+12, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+12, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+12, 8, q_00+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+8, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+8, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+8, 8, q_00+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+4, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+4, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+4, 8, q_00+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+0, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+0, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+0, 8, q_00+841+0, 8, temp);
	memset(q_01+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+915+4, 28, q_00+901);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, q_01+901);
	gf2x_add(56, q_01+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+901+24, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+24, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+24, 8, q_01+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+20, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+20, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+20, 8, q_01+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+16, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+16, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+16, 8, q_01+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+12, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+12, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+12, 8, q_01+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+8, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+8, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+8, 8, q_01+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+4, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+4, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+4, 8, q_01+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+0, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+0, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+0, 8, q_01+841+0, 8, temp);
	memset(q_10+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, q_10+901);
	GF2X_MUL(56, temp2, 28, p_10+915+4, 28, q_11+901);
	gf2x_add(56, q_10+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+901+24, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+24, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+24, 8, q_10+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+20, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+20, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+20, 8, q_10+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+16, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+16, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+16, 8, q_10+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+12, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+12, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+12, 8, q_10+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+8, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+8, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+8, 8, q_10+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+4, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+4, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+4, 8, q_10+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+0, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+0, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+0, 8, q_10+841+0, 8, temp);
	memset(q_11+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+915+4, 28, q_10+901);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, q_11+901);
	gf2x_add(56, q_11+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+901+24, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+24, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+24, 8, q_11+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+20, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+20, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+20, 8, q_11+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+16, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+16, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+16, 8, q_11+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+12, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+12, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+12, 8, q_11+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+8, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+8, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+8, 8, q_11+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+4, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+4, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+4, 8, q_11+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+0, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+0, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+0, 8, q_11+841+0, 8, temp);
	

	// Recombining results: n: 7650, depth: 3
	GF2X_MUL(120, temp, 60, q_00+841+0, 60, p_00+851);
	GF2X_MUL(120, temp2, 60, q_01+841+0, 60, p_10+851);
	gf2x_add(120, p_00+727+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, q_00+841+0, 60, p_01+851);
	GF2X_MUL(120, temp2, 60, q_01+841+0, 60, p_11+851);
	gf2x_add(120, p_01+727+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, q_10+841+0, 60, p_00+851);
	GF2X_MUL(120, temp2, 60, q_11+841+0, 60, p_10+851);
	gf2x_add(120, p_10+727+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, q_10+841+0, 60, p_01+851);
	GF2X_MUL(120, temp2, 60, q_11+841+0, 60, p_11+851);
	gf2x_add(120, p_11+727+0, 120, temp, 120, temp2);
	

	// Calculating left operands: n: 15300, depth: 2
	// Digits to shift: 119
	// Displacement: 120
	GF2X_MUL(240, temp, 120, f_sum+1448+120, 120, p_00+727);
	GF2X_MUL(240, temp2, 120, g_sum+1448+120, 120, p_01+727);
	gf2x_add(240, f_sum+2175+0, 240, temp, 240, temp2);
	GF2X_MUL(240, temp, 120, f_sum+1448+0, 120, p_00+727);
	GF2X_MUL(240, temp2, 120, g_sum+1448+0, 120, p_01+727);
	gf2x_add(240, temp, 240, temp, 240, temp2);
	gf2x_add(120, f_sum+2175, 120, f_sum+2175, 120, temp+120);
	right_bit_shift_n(240, f_sum+2175, 34);
	GF2X_MUL(240, temp, 120, f_sum+1448+120, 120, p_10+727);
	GF2X_MUL(240, temp2, 120, g_sum+1448+120, 120, p_11+727);
	gf2x_add(240, g_sum+2175+0, 240, temp, 240, temp2);
	GF2X_MUL(240, temp, 120, f_sum+1448+0, 120, p_10+727);
	GF2X_MUL(240, temp2, 120, g_sum+1448+0, 120, p_11+727);
	gf2x_add(240, temp, 240, temp, 240, temp2);
	gf2x_add(120, g_sum+2175, 120, g_sum+2175, 120, temp+120);
	right_bit_shift_n(240, g_sum+2175, 34);
	

	delta = divstepsx_256(255, delta, f_sum+2292, g_sum+2292, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2288+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2288+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2288+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2288+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2288+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2288+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2288+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2288+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2280+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2280+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2280+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2280+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2280+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2280+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2280+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2280+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2264+16, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2264+16, 16, p_01+947);
	gf2x_add(32, f_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2264+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2264+0, 16, p_01+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+2830, 16, f_sum+2830, 16, temp+16);
	right_bit_shift_n(32, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2264+16, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2264+16, 16, p_11+947);
	gf2x_add(32, g_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2264+0, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2264+0, 16, p_11+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+2830, 16, g_sum+2830, 16, temp+16);
	right_bit_shift_n(32, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2843, g_sum+2843, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, q_00+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, q_01+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, q_10+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, q_11+933+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 5
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_10+947);
	gf2x_add(32, p_00+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_11+947);
	gf2x_add(32, p_01+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_10+947);
	gf2x_add(32, p_10+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_11+947);
	gf2x_add(32, p_11+915+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 3825, depth: 4
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+2236+28, 32, p_00+915);
	GF2X_MUL(64, temp2, 32, g_sum+2236+28, 32, p_01+915);
	gf2x_add(60, f_sum+2733, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, f_sum+2236);
	GF2X_MUL(56, temp2, 28, p_01+915+4, 28, g_sum+2236);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2733, 28, f_sum+2733, 28, temp+28);
	right_bit_shift_n(60, f_sum+2733, 56);
	GF2X_MUL(64, temp, 32, f_sum+2236+28, 32, p_10+915);
	GF2X_MUL(64, temp2, 32, g_sum+2236+28, 32, p_11+915);
	gf2x_add(60, g_sum+2733, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_10+915+4, 28, f_sum+2236);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, g_sum+2236);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2733, 28, g_sum+2733, 28, temp+28);
	right_bit_shift_n(60, g_sum+2733, 56);
	

	delta = divstepsx_256(255, delta, f_sum+2758, g_sum+2758, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2754+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2754+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2754+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2754+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2746+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2746+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2746+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2746+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2734+12, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+12, 16, p_01+947);
	gf2x_add(28, f_sum+2830, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, f_sum+2734);
	GF2X_MUL(24, temp2, 12, p_01+947+4, 12, g_sum+2734);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2830, 12, f_sum+2830, 12, temp+12);
	right_bit_shift_n(28, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2734+12, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+12, 16, p_11+947);
	gf2x_add(28, g_sum+2830, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+947+4, 12, f_sum+2734);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, g_sum+2734);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2830, 12, g_sum+2830, 12, temp+12);
	right_bit_shift_n(28, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2839, g_sum+2839, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2835+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2835+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2835+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2835+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+4, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+4, 8, p_01+963);
	gf2x_add(12, f_sum+2879, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, f_sum+2831);
	GF2X_MUL(8, temp2, 4, p_01+963+4, 4, g_sum+2831);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2879, 4, f_sum+2879, 4, temp+4);
	right_bit_shift_n(12, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+4, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+4, 8, p_11+963);
	gf2x_add(12, g_sum+2879, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+963+4, 4, f_sum+2831);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, g_sum+2831);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2879, 4, g_sum+2879, 4, temp+4);
	right_bit_shift_n(12, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2880, g_sum+2880, q_00+949, q_01+949, q_10+949, q_11+949);

	// Recombining results: n: 765, depth: 6
	memset(q_00+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, q_00+949);
	GF2X_MUL(8, temp2, 4, p_10+963+4, 4, q_01+949);
	gf2x_add(8, q_00+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+949+0, 4, p_00+963);
	GF2X_MUL(8, temp2, 4, q_01+949+0, 4, p_10+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+933+0, 8, q_00+933+0, 8, temp);
	memset(q_01+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+963+4, 4, q_00+949);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, q_01+949);
	gf2x_add(8, q_01+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+949+0, 4, p_01+963);
	GF2X_MUL(8, temp2, 4, q_01+949+0, 4, p_11+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+933+0, 8, q_01+933+0, 8, temp);
	memset(q_10+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, q_10+949);
	GF2X_MUL(8, temp2, 4, p_10+963+4, 4, q_11+949);
	gf2x_add(8, q_10+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+949+0, 4, p_00+963);
	GF2X_MUL(8, temp2, 4, q_11+949+0, 4, p_10+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+933+0, 8, q_10+933+0, 8, temp);
	memset(q_11+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+963+4, 4, q_10+949);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, q_11+949);
	gf2x_add(8, q_11+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+949+0, 4, p_01+963);
	GF2X_MUL(8, temp2, 4, q_11+949+0, 4, p_11+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+933+0, 8, q_11+933+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, q_00+933);
	GF2X_MUL(24, temp2, 12, p_10+947+4, 12, q_01+933);
	gf2x_add(24, q_00+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+933+8, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+8, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+8, 8, q_00+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+4, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+4, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+4, 8, q_00+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+0, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+0, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+0, 8, q_00+901+0, 8, temp);
	memset(q_01+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+947+4, 12, q_00+933);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, q_01+933);
	gf2x_add(24, q_01+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+933+8, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+8, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+8, 8, q_01+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+4, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+4, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+4, 8, q_01+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+0, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+0, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+0, 8, q_01+901+0, 8, temp);
	memset(q_10+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, q_10+933);
	GF2X_MUL(24, temp2, 12, p_10+947+4, 12, q_11+933);
	gf2x_add(24, q_10+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+933+8, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+8, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+8, 8, q_10+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+4, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+4, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+4, 8, q_10+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+0, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+0, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+0, 8, q_10+901+0, 8, temp);
	memset(q_11+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+947+4, 12, q_10+933);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, q_11+933);
	gf2x_add(24, q_11+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+933+8, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+8, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+8, 8, q_11+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+4, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+4, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+4, 8, q_11+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+0, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+0, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+0, 8, q_11+901+0, 8, temp);
	

	// Recombining results: n: 3825, depth: 4
	memset(p_00+851, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, q_00+901);
	GF2X_MUL(56, temp2, 28, p_10+915+4, 28, q_01+901);
	gf2x_add(56, p_00+851+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+901+24, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+24, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+24, 8, p_00+851+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+20, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+20, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+20, 8, p_00+851+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+16, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+16, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+16, 8, p_00+851+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+12, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+12, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+12, 8, p_00+851+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+8, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+8, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+8, 8, p_00+851+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+4, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+4, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+4, 8, p_00+851+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+0, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+0, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+0, 8, p_00+851+0, 8, temp);
	memset(p_01+851, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+915+4, 28, q_00+901);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, q_01+901);
	gf2x_add(56, p_01+851+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+901+24, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+24, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+24, 8, p_01+851+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+20, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+20, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+20, 8, p_01+851+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+16, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+16, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+16, 8, p_01+851+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+12, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+12, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+12, 8, p_01+851+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+8, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+8, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+8, 8, p_01+851+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+4, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+4, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+4, 8, p_01+851+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+0, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+0, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+0, 8, p_01+851+0, 8, temp);
	memset(p_10+851, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, q_10+901);
	GF2X_MUL(56, temp2, 28, p_10+915+4, 28, q_11+901);
	gf2x_add(56, p_10+851+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+901+24, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+24, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+24, 8, p_10+851+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+20, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+20, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+20, 8, p_10+851+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+16, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+16, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+16, 8, p_10+851+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+12, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+12, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+12, 8, p_10+851+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+8, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+8, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+8, 8, p_10+851+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+4, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+4, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+4, 8, p_10+851+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+0, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+0, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+0, 8, p_10+851+0, 8, temp);
	memset(p_11+851, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+915+4, 28, q_10+901);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, q_11+901);
	gf2x_add(56, p_11+851+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+901+24, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+24, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+24, 8, p_11+851+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+20, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+20, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+20, 8, p_11+851+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+16, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+16, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+16, 8, p_11+851+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+12, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+12, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+12, 8, p_11+851+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+8, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+8, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+8, 8, p_11+851+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+4, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+4, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+4, 8, p_11+851+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+0, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+0, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+0, 8, p_11+851+0, 8, temp);
	

	// Calculating left operands: n: 7650, depth: 3
	// Digits to shift: 59
	// Displacement: 60
	GF2X_MUL(120, temp, 60, f_sum+2176+60, 60, p_00+851);
	GF2X_MUL(120, temp2, 60, g_sum+2176+60, 60, p_01+851);
	gf2x_add(120, f_sum+2544+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, f_sum+2176+0, 60, p_00+851);
	GF2X_MUL(120, temp2, 60, g_sum+2176+0, 60, p_01+851);
	gf2x_add(120, temp, 120, temp, 120, temp2);
	gf2x_add(60, f_sum+2544, 60, f_sum+2544, 60, temp+60);
	right_bit_shift_n(120, f_sum+2544, 49);
	GF2X_MUL(120, temp, 60, f_sum+2176+60, 60, p_10+851);
	GF2X_MUL(120, temp2, 60, g_sum+2176+60, 60, p_11+851);
	gf2x_add(120, g_sum+2544+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, f_sum+2176+0, 60, p_10+851);
	GF2X_MUL(120, temp2, 60, g_sum+2176+0, 60, p_11+851);
	gf2x_add(120, temp, 120, temp, 120, temp2);
	gf2x_add(60, g_sum+2544, 60, g_sum+2544, 60, temp+60);
	right_bit_shift_n(120, g_sum+2544, 49);
	

	delta = divstepsx_256(255, delta, f_sum+2601, g_sum+2601, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2597+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2597+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2597+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2597+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2589+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2589+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2589+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2589+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2573+16, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+16, 16, p_01+947);
	gf2x_add(32, f_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2573+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+0, 16, p_01+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+2830, 16, f_sum+2830, 16, temp+16);
	right_bit_shift_n(32, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2573+16, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+16, 16, p_11+947);
	gf2x_add(32, g_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2573+0, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+0, 16, p_11+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+2830, 16, g_sum+2830, 16, temp+16);
	right_bit_shift_n(32, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2843, g_sum+2843, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, q_00+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, q_01+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, q_10+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, q_11+933+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 5
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_10+947);
	gf2x_add(32, p_00+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_11+947);
	gf2x_add(32, p_01+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_10+947);
	gf2x_add(32, p_10+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_11+947);
	gf2x_add(32, p_11+915+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 3825, depth: 4
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+2545+28, 32, p_00+915);
	GF2X_MUL(64, temp2, 32, g_sum+2545+28, 32, p_01+915);
	gf2x_add(60, f_sum+2733, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, f_sum+2545);
	GF2X_MUL(56, temp2, 28, p_01+915+4, 28, g_sum+2545);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2733, 28, f_sum+2733, 28, temp+28);
	right_bit_shift_n(60, f_sum+2733, 56);
	GF2X_MUL(64, temp, 32, f_sum+2545+28, 32, p_10+915);
	GF2X_MUL(64, temp2, 32, g_sum+2545+28, 32, p_11+915);
	gf2x_add(60, g_sum+2733, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_10+915+4, 28, f_sum+2545);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, g_sum+2545);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2733, 28, g_sum+2733, 28, temp+28);
	right_bit_shift_n(60, g_sum+2733, 56);
	

	delta = divstepsx_256(255, delta, f_sum+2758, g_sum+2758, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2754+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2754+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2754+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2754+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2746+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2746+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2746+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2746+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2734+12, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+12, 16, p_01+947);
	gf2x_add(28, f_sum+2830, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, f_sum+2734);
	GF2X_MUL(24, temp2, 12, p_01+947+4, 12, g_sum+2734);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2830, 12, f_sum+2830, 12, temp+12);
	right_bit_shift_n(28, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2734+12, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+12, 16, p_11+947);
	gf2x_add(28, g_sum+2830, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+947+4, 12, f_sum+2734);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, g_sum+2734);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2830, 12, g_sum+2830, 12, temp+12);
	right_bit_shift_n(28, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2839, g_sum+2839, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2835+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2835+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2835+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2835+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+4, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+4, 8, p_01+963);
	gf2x_add(12, f_sum+2879, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, f_sum+2831);
	GF2X_MUL(8, temp2, 4, p_01+963+4, 4, g_sum+2831);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2879, 4, f_sum+2879, 4, temp+4);
	right_bit_shift_n(12, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+4, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+4, 8, p_11+963);
	gf2x_add(12, g_sum+2879, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+963+4, 4, f_sum+2831);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, g_sum+2831);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2879, 4, g_sum+2879, 4, temp+4);
	right_bit_shift_n(12, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2880, g_sum+2880, q_00+949, q_01+949, q_10+949, q_11+949);

	// Recombining results: n: 765, depth: 6
	memset(q_00+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, q_00+949);
	GF2X_MUL(8, temp2, 4, p_10+963+4, 4, q_01+949);
	gf2x_add(8, q_00+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+949+0, 4, p_00+963);
	GF2X_MUL(8, temp2, 4, q_01+949+0, 4, p_10+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+933+0, 8, q_00+933+0, 8, temp);
	memset(q_01+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+963+4, 4, q_00+949);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, q_01+949);
	gf2x_add(8, q_01+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+949+0, 4, p_01+963);
	GF2X_MUL(8, temp2, 4, q_01+949+0, 4, p_11+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+933+0, 8, q_01+933+0, 8, temp);
	memset(q_10+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, q_10+949);
	GF2X_MUL(8, temp2, 4, p_10+963+4, 4, q_11+949);
	gf2x_add(8, q_10+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+949+0, 4, p_00+963);
	GF2X_MUL(8, temp2, 4, q_11+949+0, 4, p_10+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+933+0, 8, q_10+933+0, 8, temp);
	memset(q_11+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+963+4, 4, q_10+949);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, q_11+949);
	gf2x_add(8, q_11+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+949+0, 4, p_01+963);
	GF2X_MUL(8, temp2, 4, q_11+949+0, 4, p_11+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+933+0, 8, q_11+933+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, q_00+933);
	GF2X_MUL(24, temp2, 12, p_10+947+4, 12, q_01+933);
	gf2x_add(24, q_00+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+933+8, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+8, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+8, 8, q_00+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+4, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+4, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+4, 8, q_00+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+0, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+0, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+0, 8, q_00+901+0, 8, temp);
	memset(q_01+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+947+4, 12, q_00+933);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, q_01+933);
	gf2x_add(24, q_01+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+933+8, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+8, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+8, 8, q_01+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+4, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+4, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+4, 8, q_01+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+0, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+0, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+0, 8, q_01+901+0, 8, temp);
	memset(q_10+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, q_10+933);
	GF2X_MUL(24, temp2, 12, p_10+947+4, 12, q_11+933);
	gf2x_add(24, q_10+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+933+8, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+8, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+8, 8, q_10+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+4, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+4, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+4, 8, q_10+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+0, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+0, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+0, 8, q_10+901+0, 8, temp);
	memset(q_11+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+947+4, 12, q_10+933);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, q_11+933);
	gf2x_add(24, q_11+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+933+8, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+8, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+8, 8, q_11+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+4, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+4, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+4, 8, q_11+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+0, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+0, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+0, 8, q_11+901+0, 8, temp);
	

	// Recombining results: n: 3825, depth: 4
	memset(q_00+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, q_00+901);
	GF2X_MUL(56, temp2, 28, p_10+915+4, 28, q_01+901);
	gf2x_add(56, q_00+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+901+24, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+24, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+24, 8, q_00+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+20, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+20, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+20, 8, q_00+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+16, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+16, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+16, 8, q_00+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+12, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+12, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+12, 8, q_00+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+8, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+8, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+8, 8, q_00+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+4, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+4, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+4, 8, q_00+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+0, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+0, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+0, 8, q_00+841+0, 8, temp);
	memset(q_01+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+915+4, 28, q_00+901);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, q_01+901);
	gf2x_add(56, q_01+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+901+24, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+24, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+24, 8, q_01+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+20, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+20, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+20, 8, q_01+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+16, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+16, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+16, 8, q_01+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+12, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+12, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+12, 8, q_01+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+8, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+8, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+8, 8, q_01+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+4, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+4, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+4, 8, q_01+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+0, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+0, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+0, 8, q_01+841+0, 8, temp);
	memset(q_10+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, q_10+901);
	GF2X_MUL(56, temp2, 28, p_10+915+4, 28, q_11+901);
	gf2x_add(56, q_10+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+901+24, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+24, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+24, 8, q_10+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+20, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+20, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+20, 8, q_10+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+16, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+16, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+16, 8, q_10+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+12, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+12, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+12, 8, q_10+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+8, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+8, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+8, 8, q_10+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+4, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+4, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+4, 8, q_10+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+0, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+0, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+0, 8, q_10+841+0, 8, temp);
	memset(q_11+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+915+4, 28, q_10+901);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, q_11+901);
	gf2x_add(56, q_11+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+901+24, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+24, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+24, 8, q_11+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+20, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+20, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+20, 8, q_11+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+16, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+16, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+16, 8, q_11+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+12, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+12, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+12, 8, q_11+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+8, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+8, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+8, 8, q_11+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+4, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+4, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+4, 8, q_11+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+0, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+0, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+0, 8, q_11+841+0, 8, temp);
	

	// Recombining results: n: 7650, depth: 3
	GF2X_MUL(120, temp, 60, q_00+841+0, 60, p_00+851);
	GF2X_MUL(120, temp2, 60, q_01+841+0, 60, p_10+851);
	gf2x_add(120, q_00+721+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, q_00+841+0, 60, p_01+851);
	GF2X_MUL(120, temp2, 60, q_01+841+0, 60, p_11+851);
	gf2x_add(120, q_01+721+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, q_10+841+0, 60, p_00+851);
	GF2X_MUL(120, temp2, 60, q_11+841+0, 60, p_10+851);
	gf2x_add(120, q_10+721+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, q_10+841+0, 60, p_01+851);
	GF2X_MUL(120, temp2, 60, q_11+841+0, 60, p_11+851);
	gf2x_add(120, q_11+721+0, 120, temp, 120, temp2);
	

	// Recombining results: n: 15300, depth: 2
	GF2X_MUL(240, temp, 120, q_00+721+0, 120, p_00+727);
	GF2X_MUL(240, temp2, 120, q_01+721+0, 120, p_10+727);
	gf2x_add(240, q_00+481+0, 240, temp, 240, temp2);
	GF2X_MUL(240, temp, 120, q_00+721+0, 120, p_01+727);
	GF2X_MUL(240, temp2, 120, q_01+721+0, 120, p_11+727);
	gf2x_add(240, q_01+481+0, 240, temp, 240, temp2);
	GF2X_MUL(240, temp, 120, q_10+721+0, 120, p_00+727);
	GF2X_MUL(240, temp2, 120, q_11+721+0, 120, p_10+727);
	gf2x_add(240, q_10+481+0, 240, temp, 240, temp2);
	GF2X_MUL(240, temp, 120, q_10+721+0, 120, p_01+727);
	GF2X_MUL(240, temp2, 120, q_11+721+0, 120, p_11+727);
	gf2x_add(240, q_11+481+0, 240, temp, 240, temp2);
	

	// Recombining results: n: 30855, depth: 1
	memset(p_00+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(480, temp, 240, p_00+483+4, 240, q_00+481);
	GF2X_MUL(480, temp2, 240, p_10+483+4, 240, q_01+481);
	gf2x_add(480, p_00+0+3, 480, temp, 480, temp2);
	GF2X_MUL(8, temp, 4, q_00+481+236, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+236, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+235, 8, p_00+0+235, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+232, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+232, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+231, 8, p_00+0+231, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+228, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+228, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+227, 8, p_00+0+227, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+224, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+224, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+223, 8, p_00+0+223, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+220, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+220, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+219, 8, p_00+0+219, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+216, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+216, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+215, 8, p_00+0+215, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+212, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+212, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+211, 8, p_00+0+211, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+208, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+208, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+207, 8, p_00+0+207, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+204, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+204, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+203, 8, p_00+0+203, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+200, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+200, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+199, 8, p_00+0+199, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+196, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+196, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+195, 8, p_00+0+195, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+192, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+192, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+191, 8, p_00+0+191, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+188, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+188, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+187, 8, p_00+0+187, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+184, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+184, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+183, 8, p_00+0+183, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+180, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+180, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+179, 8, p_00+0+179, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+176, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+176, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+175, 8, p_00+0+175, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+172, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+172, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+171, 8, p_00+0+171, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+168, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+168, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+167, 8, p_00+0+167, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+164, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+164, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+163, 8, p_00+0+163, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+160, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+160, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+159, 8, p_00+0+159, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+156, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+156, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+155, 8, p_00+0+155, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+152, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+152, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+151, 8, p_00+0+151, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+148, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+148, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+147, 8, p_00+0+147, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+144, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+144, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+143, 8, p_00+0+143, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+140, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+140, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+139, 8, p_00+0+139, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+136, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+136, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+135, 8, p_00+0+135, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+132, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+132, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+131, 8, p_00+0+131, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+128, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+128, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+127, 8, p_00+0+127, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+124, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+124, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+123, 8, p_00+0+123, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+120, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+120, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+119, 8, p_00+0+119, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+116, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+116, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+115, 8, p_00+0+115, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+112, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+112, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+111, 8, p_00+0+111, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+108, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+108, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+107, 8, p_00+0+107, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+104, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+104, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+103, 8, p_00+0+103, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+100, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+100, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+99, 8, p_00+0+99, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+96, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+96, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+95, 8, p_00+0+95, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+92, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+92, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+91, 8, p_00+0+91, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+88, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+88, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+87, 8, p_00+0+87, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+84, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+84, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+83, 8, p_00+0+83, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+80, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+80, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+79, 8, p_00+0+79, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+76, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+76, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+75, 8, p_00+0+75, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+72, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+72, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+71, 8, p_00+0+71, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+68, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+68, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+67, 8, p_00+0+67, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+64, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+64, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+63, 8, p_00+0+63, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+60, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+60, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+59, 8, p_00+0+59, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+56, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+56, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+55, 8, p_00+0+55, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+52, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+52, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+51, 8, p_00+0+51, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+48, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+48, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+47, 8, p_00+0+47, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+44, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+44, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+43, 8, p_00+0+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+40, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+40, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+39, 8, p_00+0+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+36, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+36, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+35, 8, p_00+0+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+32, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+32, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+31, 8, p_00+0+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+28, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+28, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+27, 8, p_00+0+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+24, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+24, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+23, 8, p_00+0+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+20, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+20, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+19, 8, p_00+0+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+16, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+16, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+15, 8, p_00+0+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+12, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+12, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+11, 8, p_00+0+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+8, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+8, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+7, 8, p_00+0+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+4, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+4, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+3, 8, p_00+0+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+0, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_01+481+0, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, p_00+0, 7, p_00+0, 7, temp+1);
	memset(p_01+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(480, temp, 240, p_01+483+4, 240, q_00+481);
	GF2X_MUL(480, temp2, 240, p_11+483+4, 240, q_01+481);
	gf2x_add(480, p_01+0+3, 480, temp, 480, temp2);
	GF2X_MUL(8, temp, 4, q_00+481+236, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+236, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+235, 8, p_01+0+235, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+232, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+232, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+231, 8, p_01+0+231, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+228, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+228, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+227, 8, p_01+0+227, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+224, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+224, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+223, 8, p_01+0+223, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+220, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+220, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+219, 8, p_01+0+219, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+216, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+216, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+215, 8, p_01+0+215, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+212, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+212, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+211, 8, p_01+0+211, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+208, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+208, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+207, 8, p_01+0+207, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+204, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+204, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+203, 8, p_01+0+203, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+200, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+200, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+199, 8, p_01+0+199, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+196, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+196, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+195, 8, p_01+0+195, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+192, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+192, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+191, 8, p_01+0+191, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+188, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+188, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+187, 8, p_01+0+187, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+184, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+184, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+183, 8, p_01+0+183, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+180, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+180, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+179, 8, p_01+0+179, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+176, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+176, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+175, 8, p_01+0+175, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+172, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+172, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+171, 8, p_01+0+171, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+168, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+168, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+167, 8, p_01+0+167, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+164, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+164, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+163, 8, p_01+0+163, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+160, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+160, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+159, 8, p_01+0+159, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+156, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+156, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+155, 8, p_01+0+155, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+152, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+152, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+151, 8, p_01+0+151, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+148, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+148, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+147, 8, p_01+0+147, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+144, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+144, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+143, 8, p_01+0+143, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+140, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+140, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+139, 8, p_01+0+139, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+136, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+136, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+135, 8, p_01+0+135, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+132, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+132, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+131, 8, p_01+0+131, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+128, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+128, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+127, 8, p_01+0+127, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+124, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+124, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+123, 8, p_01+0+123, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+120, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+120, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+119, 8, p_01+0+119, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+116, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+116, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+115, 8, p_01+0+115, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+112, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+112, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+111, 8, p_01+0+111, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+108, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+108, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+107, 8, p_01+0+107, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+104, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+104, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+103, 8, p_01+0+103, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+100, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+100, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+99, 8, p_01+0+99, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+96, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+96, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+95, 8, p_01+0+95, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+92, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+92, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+91, 8, p_01+0+91, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+88, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+88, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+87, 8, p_01+0+87, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+84, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+84, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+83, 8, p_01+0+83, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+80, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+80, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+79, 8, p_01+0+79, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+76, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+76, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+75, 8, p_01+0+75, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+72, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+72, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+71, 8, p_01+0+71, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+68, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+68, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+67, 8, p_01+0+67, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+64, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+64, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+63, 8, p_01+0+63, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+60, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+60, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+59, 8, p_01+0+59, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+56, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+56, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+55, 8, p_01+0+55, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+52, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+52, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+51, 8, p_01+0+51, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+48, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+48, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+47, 8, p_01+0+47, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+44, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+44, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+43, 8, p_01+0+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+40, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+40, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+39, 8, p_01+0+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+36, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+36, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+35, 8, p_01+0+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+32, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+32, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+31, 8, p_01+0+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+28, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+28, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+27, 8, p_01+0+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+24, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+24, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+23, 8, p_01+0+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+20, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+20, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+19, 8, p_01+0+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+16, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+16, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+15, 8, p_01+0+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+12, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+12, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+11, 8, p_01+0+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+8, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+8, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+7, 8, p_01+0+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+4, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+4, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+3, 8, p_01+0+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+481+0, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_01+481+0, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, p_01+0, 7, p_01+0, 7, temp+1);
	memset(p_10+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(480, temp, 240, p_00+483+4, 240, q_10+481);
	GF2X_MUL(480, temp2, 240, p_10+483+4, 240, q_11+481);
	gf2x_add(480, p_10+0+3, 480, temp, 480, temp2);
	GF2X_MUL(8, temp, 4, q_10+481+236, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+236, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+235, 8, p_10+0+235, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+232, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+232, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+231, 8, p_10+0+231, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+228, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+228, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+227, 8, p_10+0+227, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+224, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+224, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+223, 8, p_10+0+223, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+220, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+220, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+219, 8, p_10+0+219, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+216, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+216, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+215, 8, p_10+0+215, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+212, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+212, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+211, 8, p_10+0+211, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+208, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+208, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+207, 8, p_10+0+207, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+204, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+204, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+203, 8, p_10+0+203, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+200, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+200, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+199, 8, p_10+0+199, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+196, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+196, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+195, 8, p_10+0+195, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+192, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+192, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+191, 8, p_10+0+191, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+188, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+188, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+187, 8, p_10+0+187, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+184, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+184, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+183, 8, p_10+0+183, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+180, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+180, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+179, 8, p_10+0+179, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+176, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+176, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+175, 8, p_10+0+175, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+172, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+172, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+171, 8, p_10+0+171, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+168, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+168, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+167, 8, p_10+0+167, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+164, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+164, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+163, 8, p_10+0+163, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+160, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+160, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+159, 8, p_10+0+159, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+156, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+156, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+155, 8, p_10+0+155, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+152, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+152, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+151, 8, p_10+0+151, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+148, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+148, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+147, 8, p_10+0+147, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+144, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+144, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+143, 8, p_10+0+143, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+140, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+140, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+139, 8, p_10+0+139, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+136, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+136, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+135, 8, p_10+0+135, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+132, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+132, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+131, 8, p_10+0+131, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+128, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+128, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+127, 8, p_10+0+127, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+124, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+124, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+123, 8, p_10+0+123, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+120, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+120, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+119, 8, p_10+0+119, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+116, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+116, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+115, 8, p_10+0+115, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+112, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+112, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+111, 8, p_10+0+111, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+108, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+108, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+107, 8, p_10+0+107, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+104, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+104, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+103, 8, p_10+0+103, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+100, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+100, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+99, 8, p_10+0+99, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+96, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+96, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+95, 8, p_10+0+95, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+92, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+92, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+91, 8, p_10+0+91, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+88, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+88, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+87, 8, p_10+0+87, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+84, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+84, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+83, 8, p_10+0+83, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+80, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+80, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+79, 8, p_10+0+79, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+76, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+76, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+75, 8, p_10+0+75, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+72, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+72, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+71, 8, p_10+0+71, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+68, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+68, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+67, 8, p_10+0+67, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+64, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+64, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+63, 8, p_10+0+63, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+60, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+60, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+59, 8, p_10+0+59, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+56, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+56, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+55, 8, p_10+0+55, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+52, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+52, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+51, 8, p_10+0+51, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+48, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+48, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+47, 8, p_10+0+47, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+44, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+44, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+43, 8, p_10+0+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+40, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+40, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+39, 8, p_10+0+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+36, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+36, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+35, 8, p_10+0+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+32, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+32, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+31, 8, p_10+0+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+28, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+28, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+27, 8, p_10+0+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+24, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+24, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+23, 8, p_10+0+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+20, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+20, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+19, 8, p_10+0+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+16, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+16, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+15, 8, p_10+0+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+12, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+12, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+11, 8, p_10+0+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+8, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+8, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+7, 8, p_10+0+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+4, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+4, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+3, 8, p_10+0+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+0, 4, p_00+483);
	GF2X_MUL(8, temp2, 4, q_11+481+0, 4, p_10+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, p_10+0, 7, p_10+0, 7, temp+1);
	memset(p_11+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(480, temp, 240, p_01+483+4, 240, q_10+481);
	GF2X_MUL(480, temp2, 240, p_11+483+4, 240, q_11+481);
	gf2x_add(480, p_11+0+3, 480, temp, 480, temp2);
	GF2X_MUL(8, temp, 4, q_10+481+236, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+236, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+235, 8, p_11+0+235, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+232, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+232, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+231, 8, p_11+0+231, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+228, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+228, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+227, 8, p_11+0+227, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+224, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+224, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+223, 8, p_11+0+223, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+220, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+220, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+219, 8, p_11+0+219, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+216, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+216, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+215, 8, p_11+0+215, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+212, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+212, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+211, 8, p_11+0+211, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+208, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+208, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+207, 8, p_11+0+207, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+204, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+204, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+203, 8, p_11+0+203, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+200, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+200, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+199, 8, p_11+0+199, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+196, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+196, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+195, 8, p_11+0+195, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+192, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+192, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+191, 8, p_11+0+191, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+188, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+188, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+187, 8, p_11+0+187, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+184, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+184, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+183, 8, p_11+0+183, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+180, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+180, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+179, 8, p_11+0+179, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+176, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+176, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+175, 8, p_11+0+175, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+172, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+172, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+171, 8, p_11+0+171, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+168, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+168, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+167, 8, p_11+0+167, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+164, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+164, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+163, 8, p_11+0+163, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+160, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+160, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+159, 8, p_11+0+159, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+156, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+156, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+155, 8, p_11+0+155, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+152, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+152, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+151, 8, p_11+0+151, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+148, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+148, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+147, 8, p_11+0+147, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+144, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+144, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+143, 8, p_11+0+143, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+140, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+140, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+139, 8, p_11+0+139, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+136, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+136, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+135, 8, p_11+0+135, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+132, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+132, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+131, 8, p_11+0+131, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+128, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+128, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+127, 8, p_11+0+127, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+124, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+124, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+123, 8, p_11+0+123, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+120, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+120, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+119, 8, p_11+0+119, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+116, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+116, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+115, 8, p_11+0+115, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+112, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+112, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+111, 8, p_11+0+111, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+108, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+108, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+107, 8, p_11+0+107, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+104, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+104, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+103, 8, p_11+0+103, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+100, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+100, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+99, 8, p_11+0+99, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+96, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+96, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+95, 8, p_11+0+95, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+92, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+92, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+91, 8, p_11+0+91, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+88, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+88, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+87, 8, p_11+0+87, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+84, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+84, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+83, 8, p_11+0+83, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+80, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+80, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+79, 8, p_11+0+79, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+76, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+76, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+75, 8, p_11+0+75, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+72, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+72, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+71, 8, p_11+0+71, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+68, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+68, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+67, 8, p_11+0+67, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+64, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+64, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+63, 8, p_11+0+63, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+60, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+60, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+59, 8, p_11+0+59, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+56, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+56, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+55, 8, p_11+0+55, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+52, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+52, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+51, 8, p_11+0+51, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+48, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+48, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+47, 8, p_11+0+47, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+44, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+44, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+43, 8, p_11+0+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+40, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+40, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+39, 8, p_11+0+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+36, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+36, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+35, 8, p_11+0+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+32, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+32, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+31, 8, p_11+0+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+28, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+28, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+27, 8, p_11+0+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+24, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+24, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+23, 8, p_11+0+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+20, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+20, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+19, 8, p_11+0+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+16, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+16, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+15, 8, p_11+0+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+12, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+12, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+11, 8, p_11+0+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+8, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+8, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+7, 8, p_11+0+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+4, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+4, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+3, 8, p_11+0+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+481+0, 4, p_01+483);
	GF2X_MUL(8, temp2, 4, q_11+481+0, 4, p_11+483);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, p_11+0, 7, p_11+0, 7, temp+1);
	

	// Calculating left operands: n: 61605, depth: 0
	// Digits to shift: 482
	// Displacement: 482
	GF2X_MUL(966, temp, 483, f+0+480, 483, p_00+0);
	GF2X_MUL(966, temp2, 483, g+0+480, 483, p_01+0);
	gf2x_add(964, f_sum+0, 964, temp+2, 964, temp2+2);
	GF2X_MUL(960, temp, 480, p_00+0+3, 480, f+0);
	GF2X_MUL(960, temp2, 480, p_01+0+3, 480, g+0);
	gf2x_add(960, temp, 960, temp, 960, temp2);
	gf2x_add(481, f_sum+0, 481, f_sum+0, 481, temp+479);
	GF2X_MUL(6, temp, 3, f+0+477, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, g+0+477, 3, p_01+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(1, f_sum+0, 1, f_sum+0, 1, temp+5);
	right_bit_shift_n(963, f_sum+0, 7);
	GF2X_MUL(966, temp, 483, f+0+480, 483, p_10+0);
	GF2X_MUL(966, temp2, 483, g+0+480, 483, p_11+0);
	gf2x_add(964, g_sum+0, 964, temp+2, 964, temp2+2);
	GF2X_MUL(960, temp, 480, p_10+0+3, 480, f+0);
	GF2X_MUL(960, temp2, 480, p_11+0+3, 480, g+0);
	gf2x_add(960, temp, 960, temp, 960, temp2);
	gf2x_add(481, g_sum+0, 481, g_sum+0, 481, temp+479);
	GF2X_MUL(6, temp, 3, f+0+477, 3, p_10+0);
	GF2X_MUL(6, temp2, 3, g+0+477, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(1, g_sum+0, 1, g_sum+0, 1, temp+5);
	right_bit_shift_n(963, g_sum+0, 7);
	

	delta = divstepsx_256(255, delta, f_sum+478, g_sum+478, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+474+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+474+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+474+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+474+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+474+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+474+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+474+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+474+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+466+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+466+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+466+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+466+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+466+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+466+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+466+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+466+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+450+16, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+450+16, 16, p_01+947);
	gf2x_add(32, f_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+450+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+450+0, 16, p_01+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+2830, 16, f_sum+2830, 16, temp+16);
	right_bit_shift_n(32, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+450+16, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+450+16, 16, p_11+947);
	gf2x_add(32, g_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+450+0, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+450+0, 16, p_11+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+2830, 16, g_sum+2830, 16, temp+16);
	right_bit_shift_n(32, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2843, g_sum+2843, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, q_00+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, q_01+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, q_10+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, q_11+933+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 5
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_10+947);
	gf2x_add(32, p_00+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_11+947);
	gf2x_add(32, p_01+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_10+947);
	gf2x_add(32, p_10+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_11+947);
	gf2x_add(32, p_11+915+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 4080, depth: 4
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+418+32, 32, p_00+915);
	GF2X_MUL(64, temp2, 32, g_sum+418+32, 32, p_01+915);
	gf2x_add(64, f_sum+2733+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+418+0, 32, p_00+915);
	GF2X_MUL(64, temp2, 32, g_sum+418+0, 32, p_01+915);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+2733, 32, f_sum+2733, 32, temp+32);
	right_bit_shift_n(64, f_sum+2733, 56);
	GF2X_MUL(64, temp, 32, f_sum+418+32, 32, p_10+915);
	GF2X_MUL(64, temp2, 32, g_sum+418+32, 32, p_11+915);
	gf2x_add(64, g_sum+2733+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+418+0, 32, p_10+915);
	GF2X_MUL(64, temp2, 32, g_sum+418+0, 32, p_11+915);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+2733, 32, g_sum+2733, 32, temp+32);
	right_bit_shift_n(64, g_sum+2733, 56);
	

	delta = divstepsx_256(255, delta, f_sum+2762, g_sum+2762, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2758+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2758+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2758+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2758+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2758+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2758+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2758+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2758+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2750+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2750+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2750+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2750+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2750+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2750+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2750+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2750+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2734+16, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+16, 16, p_01+947);
	gf2x_add(32, f_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2734+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+0, 16, p_01+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+2830, 16, f_sum+2830, 16, temp+16);
	right_bit_shift_n(32, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2734+16, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+16, 16, p_11+947);
	gf2x_add(32, g_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2734+0, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+0, 16, p_11+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+2830, 16, g_sum+2830, 16, temp+16);
	right_bit_shift_n(32, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2843, g_sum+2843, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, q_00+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, q_01+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, q_10+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, q_11+933+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 5
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_10+947);
	gf2x_add(32, q_00+901+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_11+947);
	gf2x_add(32, q_01+901+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_10+947);
	gf2x_add(32, q_10+901+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_11+947);
	gf2x_add(32, q_11+901+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4080, depth: 4
	GF2X_MUL(64, temp, 32, q_00+901+0, 32, p_00+915);
	GF2X_MUL(64, temp2, 32, q_01+901+0, 32, p_10+915);
	gf2x_add(64, p_00+851+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_00+901+0, 32, p_01+915);
	GF2X_MUL(64, temp2, 32, q_01+901+0, 32, p_11+915);
	gf2x_add(64, p_01+851+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+901+0, 32, p_00+915);
	GF2X_MUL(64, temp2, 32, q_11+901+0, 32, p_10+915);
	gf2x_add(64, p_10+851+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+901+0, 32, p_01+915);
	GF2X_MUL(64, temp2, 32, q_11+901+0, 32, p_11+915);
	gf2x_add(64, p_11+851+0, 64, temp, 64, temp2);
	

	// Calculating left operands: n: 7905, depth: 3
	// Digits to shift: 63
	// Displacement: 64
	GF2X_MUL(128, temp, 64, f_sum+358+60, 64, p_00+851);
	GF2X_MUL(128, temp2, 64, g_sum+358+60, 64, p_01+851);
	gf2x_add(124, f_sum+2544, 124, temp+4, 124, temp2+4);
	GF2X_MUL(120, temp, 60, p_00+851+4, 60, f_sum+358);
	GF2X_MUL(120, temp2, 60, p_01+851+4, 60, g_sum+358);
	gf2x_add(120, temp, 120, temp, 120, temp2);
	gf2x_add(60, f_sum+2544, 60, f_sum+2544, 60, temp+60);
	right_bit_shift_n(124, f_sum+2544, 48);
	GF2X_MUL(128, temp, 64, f_sum+358+60, 64, p_10+851);
	GF2X_MUL(128, temp2, 64, g_sum+358+60, 64, p_11+851);
	gf2x_add(124, g_sum+2544, 124, temp+4, 124, temp2+4);
	GF2X_MUL(120, temp, 60, p_10+851+4, 60, f_sum+358);
	GF2X_MUL(120, temp2, 60, p_11+851+4, 60, g_sum+358);
	gf2x_add(120, temp, 120, temp, 120, temp2);
	gf2x_add(60, g_sum+2544, 60, g_sum+2544, 60, temp+60);
	right_bit_shift_n(124, g_sum+2544, 48);
	

	delta = divstepsx_256(255, delta, f_sum+2601, g_sum+2601, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2597+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2597+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2597+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2597+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2589+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2589+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2589+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2589+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2573+16, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+16, 16, p_01+947);
	gf2x_add(32, f_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2573+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+0, 16, p_01+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+2830, 16, f_sum+2830, 16, temp+16);
	right_bit_shift_n(32, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2573+16, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+16, 16, p_11+947);
	gf2x_add(32, g_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2573+0, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+0, 16, p_11+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+2830, 16, g_sum+2830, 16, temp+16);
	right_bit_shift_n(32, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2843, g_sum+2843, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, q_00+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, q_01+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, q_10+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, q_11+933+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 5
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_10+947);
	gf2x_add(32, p_00+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_11+947);
	gf2x_add(32, p_01+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_10+947);
	gf2x_add(32, p_10+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_11+947);
	gf2x_add(32, p_11+915+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 3825, depth: 4
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+2545+28, 32, p_00+915);
	GF2X_MUL(64, temp2, 32, g_sum+2545+28, 32, p_01+915);
	gf2x_add(60, f_sum+2733, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, f_sum+2545);
	GF2X_MUL(56, temp2, 28, p_01+915+4, 28, g_sum+2545);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2733, 28, f_sum+2733, 28, temp+28);
	right_bit_shift_n(60, f_sum+2733, 56);
	GF2X_MUL(64, temp, 32, f_sum+2545+28, 32, p_10+915);
	GF2X_MUL(64, temp2, 32, g_sum+2545+28, 32, p_11+915);
	gf2x_add(60, g_sum+2733, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_10+915+4, 28, f_sum+2545);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, g_sum+2545);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2733, 28, g_sum+2733, 28, temp+28);
	right_bit_shift_n(60, g_sum+2733, 56);
	

	delta = divstepsx_256(255, delta, f_sum+2758, g_sum+2758, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2754+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2754+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2754+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2754+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2746+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2746+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2746+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2746+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2734+12, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+12, 16, p_01+947);
	gf2x_add(28, f_sum+2830, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, f_sum+2734);
	GF2X_MUL(24, temp2, 12, p_01+947+4, 12, g_sum+2734);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2830, 12, f_sum+2830, 12, temp+12);
	right_bit_shift_n(28, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2734+12, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+12, 16, p_11+947);
	gf2x_add(28, g_sum+2830, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+947+4, 12, f_sum+2734);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, g_sum+2734);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2830, 12, g_sum+2830, 12, temp+12);
	right_bit_shift_n(28, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2839, g_sum+2839, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2835+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2835+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2835+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2835+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+4, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+4, 8, p_01+963);
	gf2x_add(12, f_sum+2879, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, f_sum+2831);
	GF2X_MUL(8, temp2, 4, p_01+963+4, 4, g_sum+2831);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2879, 4, f_sum+2879, 4, temp+4);
	right_bit_shift_n(12, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+4, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+4, 8, p_11+963);
	gf2x_add(12, g_sum+2879, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+963+4, 4, f_sum+2831);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, g_sum+2831);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2879, 4, g_sum+2879, 4, temp+4);
	right_bit_shift_n(12, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2880, g_sum+2880, q_00+949, q_01+949, q_10+949, q_11+949);

	// Recombining results: n: 765, depth: 6
	memset(q_00+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, q_00+949);
	GF2X_MUL(8, temp2, 4, p_10+963+4, 4, q_01+949);
	gf2x_add(8, q_00+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+949+0, 4, p_00+963);
	GF2X_MUL(8, temp2, 4, q_01+949+0, 4, p_10+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+933+0, 8, q_00+933+0, 8, temp);
	memset(q_01+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+963+4, 4, q_00+949);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, q_01+949);
	gf2x_add(8, q_01+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+949+0, 4, p_01+963);
	GF2X_MUL(8, temp2, 4, q_01+949+0, 4, p_11+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+933+0, 8, q_01+933+0, 8, temp);
	memset(q_10+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, q_10+949);
	GF2X_MUL(8, temp2, 4, p_10+963+4, 4, q_11+949);
	gf2x_add(8, q_10+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+949+0, 4, p_00+963);
	GF2X_MUL(8, temp2, 4, q_11+949+0, 4, p_10+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+933+0, 8, q_10+933+0, 8, temp);
	memset(q_11+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+963+4, 4, q_10+949);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, q_11+949);
	gf2x_add(8, q_11+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+949+0, 4, p_01+963);
	GF2X_MUL(8, temp2, 4, q_11+949+0, 4, p_11+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+933+0, 8, q_11+933+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, q_00+933);
	GF2X_MUL(24, temp2, 12, p_10+947+4, 12, q_01+933);
	gf2x_add(24, q_00+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+933+8, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+8, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+8, 8, q_00+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+4, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+4, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+4, 8, q_00+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+0, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+0, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+0, 8, q_00+901+0, 8, temp);
	memset(q_01+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+947+4, 12, q_00+933);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, q_01+933);
	gf2x_add(24, q_01+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+933+8, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+8, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+8, 8, q_01+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+4, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+4, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+4, 8, q_01+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+0, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+0, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+0, 8, q_01+901+0, 8, temp);
	memset(q_10+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, q_10+933);
	GF2X_MUL(24, temp2, 12, p_10+947+4, 12, q_11+933);
	gf2x_add(24, q_10+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+933+8, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+8, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+8, 8, q_10+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+4, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+4, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+4, 8, q_10+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+0, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+0, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+0, 8, q_10+901+0, 8, temp);
	memset(q_11+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+947+4, 12, q_10+933);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, q_11+933);
	gf2x_add(24, q_11+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+933+8, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+8, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+8, 8, q_11+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+4, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+4, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+4, 8, q_11+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+0, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+0, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+0, 8, q_11+901+0, 8, temp);
	

	// Recombining results: n: 3825, depth: 4
	memset(q_00+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, q_00+901);
	GF2X_MUL(56, temp2, 28, p_10+915+4, 28, q_01+901);
	gf2x_add(56, q_00+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+901+24, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+24, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+24, 8, q_00+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+20, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+20, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+20, 8, q_00+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+16, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+16, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+16, 8, q_00+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+12, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+12, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+12, 8, q_00+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+8, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+8, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+8, 8, q_00+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+4, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+4, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+4, 8, q_00+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+0, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+0, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+0, 8, q_00+841+0, 8, temp);
	memset(q_01+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+915+4, 28, q_00+901);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, q_01+901);
	gf2x_add(56, q_01+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+901+24, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+24, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+24, 8, q_01+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+20, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+20, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+20, 8, q_01+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+16, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+16, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+16, 8, q_01+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+12, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+12, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+12, 8, q_01+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+8, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+8, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+8, 8, q_01+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+4, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+4, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+4, 8, q_01+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+0, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+0, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+0, 8, q_01+841+0, 8, temp);
	memset(q_10+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, q_10+901);
	GF2X_MUL(56, temp2, 28, p_10+915+4, 28, q_11+901);
	gf2x_add(56, q_10+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+901+24, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+24, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+24, 8, q_10+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+20, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+20, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+20, 8, q_10+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+16, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+16, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+16, 8, q_10+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+12, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+12, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+12, 8, q_10+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+8, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+8, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+8, 8, q_10+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+4, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+4, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+4, 8, q_10+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+0, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+0, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+0, 8, q_10+841+0, 8, temp);
	memset(q_11+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+915+4, 28, q_10+901);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, q_11+901);
	gf2x_add(56, q_11+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+901+24, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+24, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+24, 8, q_11+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+20, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+20, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+20, 8, q_11+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+16, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+16, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+16, 8, q_11+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+12, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+12, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+12, 8, q_11+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+8, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+8, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+8, 8, q_11+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+4, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+4, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+4, 8, q_11+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+0, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+0, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+0, 8, q_11+841+0, 8, temp);
	

	// Recombining results: n: 7905, depth: 3
	memset(p_00+727, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(120, temp, 60, p_00+851+4, 60, q_00+841);
	GF2X_MUL(120, temp2, 60, p_10+851+4, 60, q_01+841);
	gf2x_add(120, p_00+727+4, 120, temp, 120, temp2);
	GF2X_MUL(8, temp, 4, q_00+841+56, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+56, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+56, 8, p_00+727+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+52, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+52, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+52, 8, p_00+727+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+48, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+48, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+48, 8, p_00+727+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+44, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+44, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+44, 8, p_00+727+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+40, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+40, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+40, 8, p_00+727+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+36, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+36, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+36, 8, p_00+727+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+32, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+32, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+32, 8, p_00+727+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+28, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+28, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+28, 8, p_00+727+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+24, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+24, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+24, 8, p_00+727+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+20, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+20, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+20, 8, p_00+727+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+16, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+16, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+16, 8, p_00+727+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+12, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+12, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+12, 8, p_00+727+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+8, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+8, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+8, 8, p_00+727+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+4, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+4, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+4, 8, p_00+727+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+0, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_01+841+0, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+727+0, 8, p_00+727+0, 8, temp);
	memset(p_01+727, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(120, temp, 60, p_01+851+4, 60, q_00+841);
	GF2X_MUL(120, temp2, 60, p_11+851+4, 60, q_01+841);
	gf2x_add(120, p_01+727+4, 120, temp, 120, temp2);
	GF2X_MUL(8, temp, 4, q_00+841+56, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+56, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+56, 8, p_01+727+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+52, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+52, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+52, 8, p_01+727+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+48, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+48, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+48, 8, p_01+727+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+44, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+44, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+44, 8, p_01+727+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+40, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+40, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+40, 8, p_01+727+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+36, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+36, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+36, 8, p_01+727+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+32, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+32, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+32, 8, p_01+727+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+28, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+28, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+28, 8, p_01+727+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+24, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+24, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+24, 8, p_01+727+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+20, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+20, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+20, 8, p_01+727+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+16, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+16, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+16, 8, p_01+727+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+12, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+12, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+12, 8, p_01+727+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+8, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+8, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+8, 8, p_01+727+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+4, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+4, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+4, 8, p_01+727+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+841+0, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_01+841+0, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+727+0, 8, p_01+727+0, 8, temp);
	memset(p_10+727, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(120, temp, 60, p_00+851+4, 60, q_10+841);
	GF2X_MUL(120, temp2, 60, p_10+851+4, 60, q_11+841);
	gf2x_add(120, p_10+727+4, 120, temp, 120, temp2);
	GF2X_MUL(8, temp, 4, q_10+841+56, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+56, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+56, 8, p_10+727+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+52, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+52, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+52, 8, p_10+727+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+48, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+48, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+48, 8, p_10+727+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+44, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+44, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+44, 8, p_10+727+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+40, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+40, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+40, 8, p_10+727+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+36, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+36, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+36, 8, p_10+727+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+32, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+32, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+32, 8, p_10+727+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+28, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+28, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+28, 8, p_10+727+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+24, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+24, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+24, 8, p_10+727+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+20, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+20, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+20, 8, p_10+727+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+16, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+16, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+16, 8, p_10+727+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+12, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+12, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+12, 8, p_10+727+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+8, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+8, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+8, 8, p_10+727+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+4, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+4, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+4, 8, p_10+727+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+0, 4, p_00+851);
	GF2X_MUL(8, temp2, 4, q_11+841+0, 4, p_10+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+727+0, 8, p_10+727+0, 8, temp);
	memset(p_11+727, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(120, temp, 60, p_01+851+4, 60, q_10+841);
	GF2X_MUL(120, temp2, 60, p_11+851+4, 60, q_11+841);
	gf2x_add(120, p_11+727+4, 120, temp, 120, temp2);
	GF2X_MUL(8, temp, 4, q_10+841+56, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+56, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+56, 8, p_11+727+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+52, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+52, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+52, 8, p_11+727+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+48, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+48, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+48, 8, p_11+727+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+44, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+44, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+44, 8, p_11+727+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+40, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+40, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+40, 8, p_11+727+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+36, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+36, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+36, 8, p_11+727+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+32, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+32, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+32, 8, p_11+727+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+28, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+28, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+28, 8, p_11+727+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+24, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+24, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+24, 8, p_11+727+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+20, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+20, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+20, 8, p_11+727+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+16, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+16, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+16, 8, p_11+727+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+12, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+12, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+12, 8, p_11+727+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+8, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+8, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+8, 8, p_11+727+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+4, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+4, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+4, 8, p_11+727+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+841+0, 4, p_01+851);
	GF2X_MUL(8, temp2, 4, q_11+841+0, 4, p_11+851);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+727+0, 8, p_11+727+0, 8, temp);
	

	// Calculating left operands: n: 15555, depth: 2
	// Digits to shift: 123
	// Displacement: 124
	GF2X_MUL(248, temp, 124, f_sum+238+120, 124, p_00+727);
	GF2X_MUL(248, temp2, 124, g_sum+238+120, 124, p_01+727);
	gf2x_add(244, f_sum+2175, 244, temp+4, 244, temp2+4);
	GF2X_MUL(240, temp, 120, p_00+727+4, 120, f_sum+238);
	GF2X_MUL(240, temp2, 120, p_01+727+4, 120, g_sum+238);
	gf2x_add(240, temp, 240, temp, 240, temp2);
	gf2x_add(120, f_sum+2175, 120, f_sum+2175, 120, temp+120);
	right_bit_shift_n(244, f_sum+2175, 33);
	GF2X_MUL(248, temp, 124, f_sum+238+120, 124, p_10+727);
	GF2X_MUL(248, temp2, 124, g_sum+238+120, 124, p_11+727);
	gf2x_add(244, g_sum+2175, 244, temp+4, 244, temp2+4);
	GF2X_MUL(240, temp, 120, p_10+727+4, 120, f_sum+238);
	GF2X_MUL(240, temp2, 120, p_11+727+4, 120, g_sum+238);
	gf2x_add(240, temp, 240, temp, 240, temp2);
	gf2x_add(120, g_sum+2175, 120, g_sum+2175, 120, temp+120);
	right_bit_shift_n(244, g_sum+2175, 33);
	

	delta = divstepsx_256(255, delta, f_sum+2292, g_sum+2292, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2288+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2288+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2288+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2288+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2288+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2288+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2288+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2288+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2280+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2280+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2280+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2280+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2280+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2280+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2280+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2280+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2264+16, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2264+16, 16, p_01+947);
	gf2x_add(32, f_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2264+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2264+0, 16, p_01+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+2830, 16, f_sum+2830, 16, temp+16);
	right_bit_shift_n(32, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2264+16, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2264+16, 16, p_11+947);
	gf2x_add(32, g_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2264+0, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2264+0, 16, p_11+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+2830, 16, g_sum+2830, 16, temp+16);
	right_bit_shift_n(32, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2843, g_sum+2843, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, q_00+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, q_01+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, q_10+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, q_11+933+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 5
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_10+947);
	gf2x_add(32, p_00+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_11+947);
	gf2x_add(32, p_01+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_10+947);
	gf2x_add(32, p_10+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_11+947);
	gf2x_add(32, p_11+915+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 3825, depth: 4
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+2236+28, 32, p_00+915);
	GF2X_MUL(64, temp2, 32, g_sum+2236+28, 32, p_01+915);
	gf2x_add(60, f_sum+2733, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, f_sum+2236);
	GF2X_MUL(56, temp2, 28, p_01+915+4, 28, g_sum+2236);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2733, 28, f_sum+2733, 28, temp+28);
	right_bit_shift_n(60, f_sum+2733, 56);
	GF2X_MUL(64, temp, 32, f_sum+2236+28, 32, p_10+915);
	GF2X_MUL(64, temp2, 32, g_sum+2236+28, 32, p_11+915);
	gf2x_add(60, g_sum+2733, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_10+915+4, 28, f_sum+2236);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, g_sum+2236);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2733, 28, g_sum+2733, 28, temp+28);
	right_bit_shift_n(60, g_sum+2733, 56);
	

	delta = divstepsx_256(255, delta, f_sum+2758, g_sum+2758, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2754+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2754+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2754+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2754+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2746+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2746+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2746+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2746+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2734+12, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+12, 16, p_01+947);
	gf2x_add(28, f_sum+2830, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, f_sum+2734);
	GF2X_MUL(24, temp2, 12, p_01+947+4, 12, g_sum+2734);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2830, 12, f_sum+2830, 12, temp+12);
	right_bit_shift_n(28, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2734+12, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+12, 16, p_11+947);
	gf2x_add(28, g_sum+2830, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+947+4, 12, f_sum+2734);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, g_sum+2734);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2830, 12, g_sum+2830, 12, temp+12);
	right_bit_shift_n(28, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2839, g_sum+2839, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2835+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2835+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2835+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2835+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+4, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+4, 8, p_01+963);
	gf2x_add(12, f_sum+2879, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, f_sum+2831);
	GF2X_MUL(8, temp2, 4, p_01+963+4, 4, g_sum+2831);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2879, 4, f_sum+2879, 4, temp+4);
	right_bit_shift_n(12, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+4, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+4, 8, p_11+963);
	gf2x_add(12, g_sum+2879, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+963+4, 4, f_sum+2831);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, g_sum+2831);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2879, 4, g_sum+2879, 4, temp+4);
	right_bit_shift_n(12, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2880, g_sum+2880, q_00+949, q_01+949, q_10+949, q_11+949);

	// Recombining results: n: 765, depth: 6
	memset(q_00+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, q_00+949);
	GF2X_MUL(8, temp2, 4, p_10+963+4, 4, q_01+949);
	gf2x_add(8, q_00+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+949+0, 4, p_00+963);
	GF2X_MUL(8, temp2, 4, q_01+949+0, 4, p_10+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+933+0, 8, q_00+933+0, 8, temp);
	memset(q_01+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+963+4, 4, q_00+949);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, q_01+949);
	gf2x_add(8, q_01+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+949+0, 4, p_01+963);
	GF2X_MUL(8, temp2, 4, q_01+949+0, 4, p_11+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+933+0, 8, q_01+933+0, 8, temp);
	memset(q_10+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, q_10+949);
	GF2X_MUL(8, temp2, 4, p_10+963+4, 4, q_11+949);
	gf2x_add(8, q_10+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+949+0, 4, p_00+963);
	GF2X_MUL(8, temp2, 4, q_11+949+0, 4, p_10+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+933+0, 8, q_10+933+0, 8, temp);
	memset(q_11+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+963+4, 4, q_10+949);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, q_11+949);
	gf2x_add(8, q_11+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+949+0, 4, p_01+963);
	GF2X_MUL(8, temp2, 4, q_11+949+0, 4, p_11+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+933+0, 8, q_11+933+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, q_00+933);
	GF2X_MUL(24, temp2, 12, p_10+947+4, 12, q_01+933);
	gf2x_add(24, q_00+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+933+8, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+8, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+8, 8, q_00+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+4, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+4, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+4, 8, q_00+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+0, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+0, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+0, 8, q_00+901+0, 8, temp);
	memset(q_01+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+947+4, 12, q_00+933);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, q_01+933);
	gf2x_add(24, q_01+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+933+8, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+8, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+8, 8, q_01+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+4, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+4, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+4, 8, q_01+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+0, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+0, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+0, 8, q_01+901+0, 8, temp);
	memset(q_10+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, q_10+933);
	GF2X_MUL(24, temp2, 12, p_10+947+4, 12, q_11+933);
	gf2x_add(24, q_10+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+933+8, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+8, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+8, 8, q_10+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+4, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+4, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+4, 8, q_10+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+0, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+0, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+0, 8, q_10+901+0, 8, temp);
	memset(q_11+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+947+4, 12, q_10+933);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, q_11+933);
	gf2x_add(24, q_11+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+933+8, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+8, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+8, 8, q_11+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+4, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+4, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+4, 8, q_11+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+0, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+0, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+0, 8, q_11+901+0, 8, temp);
	

	// Recombining results: n: 3825, depth: 4
	memset(p_00+851, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, q_00+901);
	GF2X_MUL(56, temp2, 28, p_10+915+4, 28, q_01+901);
	gf2x_add(56, p_00+851+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+901+24, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+24, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+24, 8, p_00+851+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+20, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+20, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+20, 8, p_00+851+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+16, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+16, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+16, 8, p_00+851+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+12, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+12, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+12, 8, p_00+851+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+8, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+8, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+8, 8, p_00+851+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+4, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+4, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+4, 8, p_00+851+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+0, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+0, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+0, 8, p_00+851+0, 8, temp);
	memset(p_01+851, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+915+4, 28, q_00+901);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, q_01+901);
	gf2x_add(56, p_01+851+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+901+24, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+24, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+24, 8, p_01+851+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+20, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+20, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+20, 8, p_01+851+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+16, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+16, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+16, 8, p_01+851+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+12, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+12, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+12, 8, p_01+851+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+8, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+8, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+8, 8, p_01+851+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+4, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+4, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+4, 8, p_01+851+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+0, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+0, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+0, 8, p_01+851+0, 8, temp);
	memset(p_10+851, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, q_10+901);
	GF2X_MUL(56, temp2, 28, p_10+915+4, 28, q_11+901);
	gf2x_add(56, p_10+851+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+901+24, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+24, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+24, 8, p_10+851+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+20, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+20, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+20, 8, p_10+851+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+16, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+16, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+16, 8, p_10+851+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+12, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+12, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+12, 8, p_10+851+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+8, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+8, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+8, 8, p_10+851+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+4, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+4, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+4, 8, p_10+851+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+0, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+0, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+0, 8, p_10+851+0, 8, temp);
	memset(p_11+851, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+915+4, 28, q_10+901);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, q_11+901);
	gf2x_add(56, p_11+851+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+901+24, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+24, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+24, 8, p_11+851+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+20, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+20, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+20, 8, p_11+851+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+16, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+16, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+16, 8, p_11+851+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+12, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+12, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+12, 8, p_11+851+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+8, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+8, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+8, 8, p_11+851+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+4, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+4, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+4, 8, p_11+851+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+0, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+0, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+0, 8, p_11+851+0, 8, temp);
	

	// Calculating left operands: n: 7650, depth: 3
	// Digits to shift: 59
	// Displacement: 60
	GF2X_MUL(120, temp, 60, f_sum+2176+60, 60, p_00+851);
	GF2X_MUL(120, temp2, 60, g_sum+2176+60, 60, p_01+851);
	gf2x_add(120, f_sum+2544+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, f_sum+2176+0, 60, p_00+851);
	GF2X_MUL(120, temp2, 60, g_sum+2176+0, 60, p_01+851);
	gf2x_add(120, temp, 120, temp, 120, temp2);
	gf2x_add(60, f_sum+2544, 60, f_sum+2544, 60, temp+60);
	right_bit_shift_n(120, f_sum+2544, 49);
	GF2X_MUL(120, temp, 60, f_sum+2176+60, 60, p_10+851);
	GF2X_MUL(120, temp2, 60, g_sum+2176+60, 60, p_11+851);
	gf2x_add(120, g_sum+2544+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, f_sum+2176+0, 60, p_10+851);
	GF2X_MUL(120, temp2, 60, g_sum+2176+0, 60, p_11+851);
	gf2x_add(120, temp, 120, temp, 120, temp2);
	gf2x_add(60, g_sum+2544, 60, g_sum+2544, 60, temp+60);
	right_bit_shift_n(120, g_sum+2544, 49);
	

	delta = divstepsx_256(255, delta, f_sum+2601, g_sum+2601, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2597+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2597+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2597+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2597+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2589+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2589+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2589+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2589+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2573+16, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+16, 16, p_01+947);
	gf2x_add(32, f_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2573+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+0, 16, p_01+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+2830, 16, f_sum+2830, 16, temp+16);
	right_bit_shift_n(32, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2573+16, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+16, 16, p_11+947);
	gf2x_add(32, g_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2573+0, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+0, 16, p_11+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+2830, 16, g_sum+2830, 16, temp+16);
	right_bit_shift_n(32, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2843, g_sum+2843, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, q_00+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, q_01+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, q_10+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, q_11+933+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 5
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_10+947);
	gf2x_add(32, p_00+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_11+947);
	gf2x_add(32, p_01+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_10+947);
	gf2x_add(32, p_10+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_11+947);
	gf2x_add(32, p_11+915+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 3825, depth: 4
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+2545+28, 32, p_00+915);
	GF2X_MUL(64, temp2, 32, g_sum+2545+28, 32, p_01+915);
	gf2x_add(60, f_sum+2733, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, f_sum+2545);
	GF2X_MUL(56, temp2, 28, p_01+915+4, 28, g_sum+2545);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2733, 28, f_sum+2733, 28, temp+28);
	right_bit_shift_n(60, f_sum+2733, 56);
	GF2X_MUL(64, temp, 32, f_sum+2545+28, 32, p_10+915);
	GF2X_MUL(64, temp2, 32, g_sum+2545+28, 32, p_11+915);
	gf2x_add(60, g_sum+2733, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_10+915+4, 28, f_sum+2545);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, g_sum+2545);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2733, 28, g_sum+2733, 28, temp+28);
	right_bit_shift_n(60, g_sum+2733, 56);
	

	delta = divstepsx_256(255, delta, f_sum+2758, g_sum+2758, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2754+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2754+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2754+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2754+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2746+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2746+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2746+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2746+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2734+12, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+12, 16, p_01+947);
	gf2x_add(28, f_sum+2830, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, f_sum+2734);
	GF2X_MUL(24, temp2, 12, p_01+947+4, 12, g_sum+2734);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2830, 12, f_sum+2830, 12, temp+12);
	right_bit_shift_n(28, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2734+12, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+12, 16, p_11+947);
	gf2x_add(28, g_sum+2830, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+947+4, 12, f_sum+2734);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, g_sum+2734);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2830, 12, g_sum+2830, 12, temp+12);
	right_bit_shift_n(28, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2839, g_sum+2839, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2835+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2835+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2835+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2835+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+4, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+4, 8, p_01+963);
	gf2x_add(12, f_sum+2879, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, f_sum+2831);
	GF2X_MUL(8, temp2, 4, p_01+963+4, 4, g_sum+2831);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2879, 4, f_sum+2879, 4, temp+4);
	right_bit_shift_n(12, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+4, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+4, 8, p_11+963);
	gf2x_add(12, g_sum+2879, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+963+4, 4, f_sum+2831);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, g_sum+2831);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2879, 4, g_sum+2879, 4, temp+4);
	right_bit_shift_n(12, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2880, g_sum+2880, q_00+949, q_01+949, q_10+949, q_11+949);

	// Recombining results: n: 765, depth: 6
	memset(q_00+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, q_00+949);
	GF2X_MUL(8, temp2, 4, p_10+963+4, 4, q_01+949);
	gf2x_add(8, q_00+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+949+0, 4, p_00+963);
	GF2X_MUL(8, temp2, 4, q_01+949+0, 4, p_10+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+933+0, 8, q_00+933+0, 8, temp);
	memset(q_01+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+963+4, 4, q_00+949);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, q_01+949);
	gf2x_add(8, q_01+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+949+0, 4, p_01+963);
	GF2X_MUL(8, temp2, 4, q_01+949+0, 4, p_11+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+933+0, 8, q_01+933+0, 8, temp);
	memset(q_10+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, q_10+949);
	GF2X_MUL(8, temp2, 4, p_10+963+4, 4, q_11+949);
	gf2x_add(8, q_10+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+949+0, 4, p_00+963);
	GF2X_MUL(8, temp2, 4, q_11+949+0, 4, p_10+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+933+0, 8, q_10+933+0, 8, temp);
	memset(q_11+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+963+4, 4, q_10+949);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, q_11+949);
	gf2x_add(8, q_11+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+949+0, 4, p_01+963);
	GF2X_MUL(8, temp2, 4, q_11+949+0, 4, p_11+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+933+0, 8, q_11+933+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, q_00+933);
	GF2X_MUL(24, temp2, 12, p_10+947+4, 12, q_01+933);
	gf2x_add(24, q_00+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+933+8, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+8, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+8, 8, q_00+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+4, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+4, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+4, 8, q_00+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+0, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+0, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+0, 8, q_00+901+0, 8, temp);
	memset(q_01+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+947+4, 12, q_00+933);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, q_01+933);
	gf2x_add(24, q_01+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+933+8, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+8, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+8, 8, q_01+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+4, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+4, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+4, 8, q_01+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+0, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+0, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+0, 8, q_01+901+0, 8, temp);
	memset(q_10+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, q_10+933);
	GF2X_MUL(24, temp2, 12, p_10+947+4, 12, q_11+933);
	gf2x_add(24, q_10+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+933+8, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+8, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+8, 8, q_10+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+4, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+4, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+4, 8, q_10+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+0, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+0, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+0, 8, q_10+901+0, 8, temp);
	memset(q_11+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+947+4, 12, q_10+933);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, q_11+933);
	gf2x_add(24, q_11+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+933+8, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+8, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+8, 8, q_11+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+4, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+4, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+4, 8, q_11+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+0, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+0, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+0, 8, q_11+901+0, 8, temp);
	

	// Recombining results: n: 3825, depth: 4
	memset(q_00+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, q_00+901);
	GF2X_MUL(56, temp2, 28, p_10+915+4, 28, q_01+901);
	gf2x_add(56, q_00+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+901+24, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+24, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+24, 8, q_00+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+20, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+20, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+20, 8, q_00+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+16, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+16, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+16, 8, q_00+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+12, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+12, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+12, 8, q_00+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+8, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+8, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+8, 8, q_00+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+4, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+4, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+4, 8, q_00+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+0, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+0, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+0, 8, q_00+841+0, 8, temp);
	memset(q_01+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+915+4, 28, q_00+901);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, q_01+901);
	gf2x_add(56, q_01+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+901+24, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+24, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+24, 8, q_01+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+20, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+20, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+20, 8, q_01+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+16, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+16, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+16, 8, q_01+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+12, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+12, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+12, 8, q_01+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+8, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+8, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+8, 8, q_01+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+4, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+4, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+4, 8, q_01+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+0, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+0, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+0, 8, q_01+841+0, 8, temp);
	memset(q_10+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, q_10+901);
	GF2X_MUL(56, temp2, 28, p_10+915+4, 28, q_11+901);
	gf2x_add(56, q_10+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+901+24, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+24, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+24, 8, q_10+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+20, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+20, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+20, 8, q_10+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+16, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+16, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+16, 8, q_10+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+12, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+12, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+12, 8, q_10+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+8, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+8, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+8, 8, q_10+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+4, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+4, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+4, 8, q_10+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+0, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+0, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+0, 8, q_10+841+0, 8, temp);
	memset(q_11+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+915+4, 28, q_10+901);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, q_11+901);
	gf2x_add(56, q_11+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+901+24, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+24, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+24, 8, q_11+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+20, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+20, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+20, 8, q_11+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+16, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+16, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+16, 8, q_11+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+12, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+12, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+12, 8, q_11+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+8, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+8, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+8, 8, q_11+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+4, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+4, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+4, 8, q_11+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+0, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+0, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+0, 8, q_11+841+0, 8, temp);
	

	// Recombining results: n: 7650, depth: 3
	GF2X_MUL(120, temp, 60, q_00+841+0, 60, p_00+851);
	GF2X_MUL(120, temp2, 60, q_01+841+0, 60, p_10+851);
	gf2x_add(120, q_00+721+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, q_00+841+0, 60, p_01+851);
	GF2X_MUL(120, temp2, 60, q_01+841+0, 60, p_11+851);
	gf2x_add(120, q_01+721+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, q_10+841+0, 60, p_00+851);
	GF2X_MUL(120, temp2, 60, q_11+841+0, 60, p_10+851);
	gf2x_add(120, q_10+721+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, q_10+841+0, 60, p_01+851);
	GF2X_MUL(120, temp2, 60, q_11+841+0, 60, p_11+851);
	gf2x_add(120, q_11+721+0, 120, temp, 120, temp2);
	

	// Recombining results: n: 15555, depth: 2
	memset(p_00+483, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(240, temp, 120, p_00+727+4, 120, q_00+721);
	GF2X_MUL(240, temp2, 120, p_10+727+4, 120, q_01+721);
	gf2x_add(240, p_00+483+4, 240, temp, 240, temp2);
	GF2X_MUL(8, temp, 4, q_00+721+116, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+116, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+116, 8, p_00+483+116, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+112, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+112, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+112, 8, p_00+483+112, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+108, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+108, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+108, 8, p_00+483+108, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+104, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+104, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+104, 8, p_00+483+104, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+100, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+100, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+100, 8, p_00+483+100, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+96, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+96, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+96, 8, p_00+483+96, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+92, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+92, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+92, 8, p_00+483+92, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+88, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+88, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+88, 8, p_00+483+88, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+84, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+84, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+84, 8, p_00+483+84, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+80, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+80, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+80, 8, p_00+483+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+76, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+76, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+76, 8, p_00+483+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+72, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+72, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+72, 8, p_00+483+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+68, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+68, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+68, 8, p_00+483+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+64, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+64, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+64, 8, p_00+483+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+60, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+60, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+60, 8, p_00+483+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+56, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+56, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+56, 8, p_00+483+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+52, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+52, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+52, 8, p_00+483+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+48, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+48, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+48, 8, p_00+483+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+44, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+44, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+44, 8, p_00+483+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+40, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+40, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+40, 8, p_00+483+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+36, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+36, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+36, 8, p_00+483+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+32, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+32, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+32, 8, p_00+483+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+28, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+28, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+28, 8, p_00+483+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+24, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+24, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+24, 8, p_00+483+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+20, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+20, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+20, 8, p_00+483+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+16, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+16, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+16, 8, p_00+483+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+12, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+12, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+12, 8, p_00+483+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+8, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+8, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+8, 8, p_00+483+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+4, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+4, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+4, 8, p_00+483+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+721+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+483+0, 8, p_00+483+0, 8, temp);
	memset(p_01+483, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(240, temp, 120, p_01+727+4, 120, q_00+721);
	GF2X_MUL(240, temp2, 120, p_11+727+4, 120, q_01+721);
	gf2x_add(240, p_01+483+4, 240, temp, 240, temp2);
	GF2X_MUL(8, temp, 4, q_00+721+116, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+116, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+116, 8, p_01+483+116, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+112, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+112, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+112, 8, p_01+483+112, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+108, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+108, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+108, 8, p_01+483+108, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+104, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+104, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+104, 8, p_01+483+104, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+100, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+100, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+100, 8, p_01+483+100, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+96, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+96, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+96, 8, p_01+483+96, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+92, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+92, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+92, 8, p_01+483+92, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+88, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+88, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+88, 8, p_01+483+88, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+84, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+84, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+84, 8, p_01+483+84, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+80, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+80, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+80, 8, p_01+483+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+76, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+76, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+76, 8, p_01+483+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+72, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+72, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+72, 8, p_01+483+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+68, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+68, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+68, 8, p_01+483+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+64, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+64, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+64, 8, p_01+483+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+60, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+60, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+60, 8, p_01+483+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+56, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+56, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+56, 8, p_01+483+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+52, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+52, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+52, 8, p_01+483+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+48, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+48, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+48, 8, p_01+483+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+44, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+44, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+44, 8, p_01+483+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+40, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+40, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+40, 8, p_01+483+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+36, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+36, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+36, 8, p_01+483+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+32, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+32, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+32, 8, p_01+483+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+28, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+28, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+28, 8, p_01+483+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+24, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+24, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+24, 8, p_01+483+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+20, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+20, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+20, 8, p_01+483+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+16, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+16, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+16, 8, p_01+483+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+12, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+12, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+12, 8, p_01+483+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+8, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+8, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+8, 8, p_01+483+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+4, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+4, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+4, 8, p_01+483+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+721+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+721+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+483+0, 8, p_01+483+0, 8, temp);
	memset(p_10+483, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(240, temp, 120, p_00+727+4, 120, q_10+721);
	GF2X_MUL(240, temp2, 120, p_10+727+4, 120, q_11+721);
	gf2x_add(240, p_10+483+4, 240, temp, 240, temp2);
	GF2X_MUL(8, temp, 4, q_10+721+116, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+116, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+116, 8, p_10+483+116, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+112, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+112, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+112, 8, p_10+483+112, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+108, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+108, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+108, 8, p_10+483+108, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+104, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+104, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+104, 8, p_10+483+104, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+100, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+100, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+100, 8, p_10+483+100, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+96, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+96, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+96, 8, p_10+483+96, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+92, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+92, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+92, 8, p_10+483+92, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+88, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+88, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+88, 8, p_10+483+88, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+84, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+84, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+84, 8, p_10+483+84, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+80, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+80, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+80, 8, p_10+483+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+76, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+76, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+76, 8, p_10+483+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+72, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+72, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+72, 8, p_10+483+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+68, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+68, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+68, 8, p_10+483+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+64, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+64, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+64, 8, p_10+483+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+60, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+60, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+60, 8, p_10+483+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+56, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+56, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+56, 8, p_10+483+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+52, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+52, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+52, 8, p_10+483+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+48, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+48, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+48, 8, p_10+483+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+44, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+44, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+44, 8, p_10+483+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+40, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+40, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+40, 8, p_10+483+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+36, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+36, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+36, 8, p_10+483+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+32, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+32, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+32, 8, p_10+483+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+28, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+28, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+28, 8, p_10+483+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+24, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+24, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+24, 8, p_10+483+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+20, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+20, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+20, 8, p_10+483+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+16, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+16, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+16, 8, p_10+483+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+12, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+12, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+12, 8, p_10+483+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+8, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+8, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+8, 8, p_10+483+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+4, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+4, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+4, 8, p_10+483+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+721+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+483+0, 8, p_10+483+0, 8, temp);
	memset(p_11+483, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(240, temp, 120, p_01+727+4, 120, q_10+721);
	GF2X_MUL(240, temp2, 120, p_11+727+4, 120, q_11+721);
	gf2x_add(240, p_11+483+4, 240, temp, 240, temp2);
	GF2X_MUL(8, temp, 4, q_10+721+116, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+116, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+116, 8, p_11+483+116, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+112, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+112, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+112, 8, p_11+483+112, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+108, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+108, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+108, 8, p_11+483+108, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+104, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+104, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+104, 8, p_11+483+104, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+100, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+100, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+100, 8, p_11+483+100, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+96, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+96, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+96, 8, p_11+483+96, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+92, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+92, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+92, 8, p_11+483+92, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+88, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+88, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+88, 8, p_11+483+88, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+84, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+84, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+84, 8, p_11+483+84, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+80, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+80, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+80, 8, p_11+483+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+76, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+76, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+76, 8, p_11+483+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+72, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+72, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+72, 8, p_11+483+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+68, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+68, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+68, 8, p_11+483+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+64, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+64, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+64, 8, p_11+483+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+60, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+60, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+60, 8, p_11+483+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+56, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+56, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+56, 8, p_11+483+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+52, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+52, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+52, 8, p_11+483+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+48, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+48, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+48, 8, p_11+483+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+44, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+44, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+44, 8, p_11+483+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+40, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+40, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+40, 8, p_11+483+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+36, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+36, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+36, 8, p_11+483+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+32, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+32, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+32, 8, p_11+483+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+28, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+28, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+28, 8, p_11+483+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+24, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+24, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+24, 8, p_11+483+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+20, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+20, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+20, 8, p_11+483+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+16, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+16, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+16, 8, p_11+483+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+12, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+12, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+12, 8, p_11+483+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+8, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+8, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+8, 8, p_11+483+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+4, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+4, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+4, 8, p_11+483+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+721+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+721+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+483+0, 8, p_11+483+0, 8, temp);
	

	// Calculating left operands: n: 30750, depth: 1
	// Digits to shift: 243
	// Displacement: 243
	GF2X_MUL(488, temp, 244, f_sum+1+237, 244, p_00+483);
	GF2X_MUL(488, temp2, 244, g_sum+1+237, 244, p_01+483);
	gf2x_add(482, f_sum+1447, 482, temp+6, 482, temp2+6);
	GF2X_MUL(474, temp, 237, p_00+483+7, 237, f_sum+1);
	GF2X_MUL(474, temp2, 237, p_01+483+7, 237, g_sum+1);
	gf2x_add(474, temp, 474, temp, 474, temp2);
	gf2x_add(238, f_sum+1447, 238, f_sum+1447, 238, temp+236);
	GF2X_MUL(14, temp, 7, f_sum+1+230, 7, p_00+483);
	GF2X_MUL(14, temp2, 7, g_sum+1+230, 7, p_01+483);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(1, f_sum+1447, 1, f_sum+1447, 1, temp+13);
	right_bit_shift_n(481, f_sum+1447, 3);
	GF2X_MUL(488, temp, 244, f_sum+1+237, 244, p_10+483);
	GF2X_MUL(488, temp2, 244, g_sum+1+237, 244, p_11+483);
	gf2x_add(482, g_sum+1447, 482, temp+6, 482, temp2+6);
	GF2X_MUL(474, temp, 237, p_10+483+7, 237, f_sum+1);
	GF2X_MUL(474, temp2, 237, p_11+483+7, 237, g_sum+1);
	gf2x_add(474, temp, 474, temp, 474, temp2);
	gf2x_add(238, g_sum+1447, 238, g_sum+1447, 238, temp+236);
	GF2X_MUL(14, temp, 7, f_sum+1+230, 7, p_10+483);
	GF2X_MUL(14, temp2, 7, g_sum+1+230, 7, p_11+483);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(1, g_sum+1447, 1, g_sum+1447, 1, temp+13);
	right_bit_shift_n(481, g_sum+1447, 3);
	

	delta = divstepsx_256(255, delta, f_sum+1682, g_sum+1682, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1678+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+1678+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1678+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+1678+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+1678+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+1678+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1678+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+1678+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1670+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+1670+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1670+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+1670+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+1670+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+1670+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1670+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+1670+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1654+16, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+1654+16, 16, p_01+947);
	gf2x_add(32, f_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1654+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+1654+0, 16, p_01+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+2830, 16, f_sum+2830, 16, temp+16);
	right_bit_shift_n(32, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+1654+16, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+1654+16, 16, p_11+947);
	gf2x_add(32, g_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1654+0, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+1654+0, 16, p_11+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+2830, 16, g_sum+2830, 16, temp+16);
	right_bit_shift_n(32, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2843, g_sum+2843, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, q_00+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, q_01+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, q_10+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, q_11+933+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 5
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_10+947);
	gf2x_add(32, p_00+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_11+947);
	gf2x_add(32, p_01+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_10+947);
	gf2x_add(32, p_10+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_11+947);
	gf2x_add(32, p_11+915+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 3825, depth: 4
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+1626+28, 32, p_00+915);
	GF2X_MUL(64, temp2, 32, g_sum+1626+28, 32, p_01+915);
	gf2x_add(60, f_sum+2733, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, f_sum+1626);
	GF2X_MUL(56, temp2, 28, p_01+915+4, 28, g_sum+1626);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2733, 28, f_sum+2733, 28, temp+28);
	right_bit_shift_n(60, f_sum+2733, 56);
	GF2X_MUL(64, temp, 32, f_sum+1626+28, 32, p_10+915);
	GF2X_MUL(64, temp2, 32, g_sum+1626+28, 32, p_11+915);
	gf2x_add(60, g_sum+2733, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_10+915+4, 28, f_sum+1626);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, g_sum+1626);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2733, 28, g_sum+2733, 28, temp+28);
	right_bit_shift_n(60, g_sum+2733, 56);
	

	delta = divstepsx_256(255, delta, f_sum+2758, g_sum+2758, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2754+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2754+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2754+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2754+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2746+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2746+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2746+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2746+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2734+12, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+12, 16, p_01+947);
	gf2x_add(28, f_sum+2830, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, f_sum+2734);
	GF2X_MUL(24, temp2, 12, p_01+947+4, 12, g_sum+2734);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2830, 12, f_sum+2830, 12, temp+12);
	right_bit_shift_n(28, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2734+12, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+12, 16, p_11+947);
	gf2x_add(28, g_sum+2830, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+947+4, 12, f_sum+2734);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, g_sum+2734);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2830, 12, g_sum+2830, 12, temp+12);
	right_bit_shift_n(28, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2839, g_sum+2839, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2835+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2835+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2835+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2835+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+4, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+4, 8, p_01+963);
	gf2x_add(12, f_sum+2879, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, f_sum+2831);
	GF2X_MUL(8, temp2, 4, p_01+963+4, 4, g_sum+2831);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2879, 4, f_sum+2879, 4, temp+4);
	right_bit_shift_n(12, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+4, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+4, 8, p_11+963);
	gf2x_add(12, g_sum+2879, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+963+4, 4, f_sum+2831);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, g_sum+2831);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2879, 4, g_sum+2879, 4, temp+4);
	right_bit_shift_n(12, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2880, g_sum+2880, q_00+949, q_01+949, q_10+949, q_11+949);

	// Recombining results: n: 765, depth: 6
	memset(q_00+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, q_00+949);
	GF2X_MUL(8, temp2, 4, p_10+963+4, 4, q_01+949);
	gf2x_add(8, q_00+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+949+0, 4, p_00+963);
	GF2X_MUL(8, temp2, 4, q_01+949+0, 4, p_10+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+933+0, 8, q_00+933+0, 8, temp);
	memset(q_01+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+963+4, 4, q_00+949);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, q_01+949);
	gf2x_add(8, q_01+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+949+0, 4, p_01+963);
	GF2X_MUL(8, temp2, 4, q_01+949+0, 4, p_11+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+933+0, 8, q_01+933+0, 8, temp);
	memset(q_10+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, q_10+949);
	GF2X_MUL(8, temp2, 4, p_10+963+4, 4, q_11+949);
	gf2x_add(8, q_10+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+949+0, 4, p_00+963);
	GF2X_MUL(8, temp2, 4, q_11+949+0, 4, p_10+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+933+0, 8, q_10+933+0, 8, temp);
	memset(q_11+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+963+4, 4, q_10+949);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, q_11+949);
	gf2x_add(8, q_11+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+949+0, 4, p_01+963);
	GF2X_MUL(8, temp2, 4, q_11+949+0, 4, p_11+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+933+0, 8, q_11+933+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, q_00+933);
	GF2X_MUL(24, temp2, 12, p_10+947+4, 12, q_01+933);
	gf2x_add(24, q_00+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+933+8, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+8, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+8, 8, q_00+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+4, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+4, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+4, 8, q_00+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+0, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+0, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+0, 8, q_00+901+0, 8, temp);
	memset(q_01+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+947+4, 12, q_00+933);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, q_01+933);
	gf2x_add(24, q_01+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+933+8, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+8, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+8, 8, q_01+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+4, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+4, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+4, 8, q_01+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+0, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+0, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+0, 8, q_01+901+0, 8, temp);
	memset(q_10+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, q_10+933);
	GF2X_MUL(24, temp2, 12, p_10+947+4, 12, q_11+933);
	gf2x_add(24, q_10+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+933+8, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+8, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+8, 8, q_10+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+4, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+4, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+4, 8, q_10+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+0, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+0, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+0, 8, q_10+901+0, 8, temp);
	memset(q_11+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+947+4, 12, q_10+933);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, q_11+933);
	gf2x_add(24, q_11+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+933+8, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+8, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+8, 8, q_11+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+4, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+4, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+4, 8, q_11+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+0, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+0, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+0, 8, q_11+901+0, 8, temp);
	

	// Recombining results: n: 3825, depth: 4
	memset(p_00+851, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, q_00+901);
	GF2X_MUL(56, temp2, 28, p_10+915+4, 28, q_01+901);
	gf2x_add(56, p_00+851+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+901+24, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+24, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+24, 8, p_00+851+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+20, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+20, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+20, 8, p_00+851+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+16, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+16, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+16, 8, p_00+851+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+12, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+12, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+12, 8, p_00+851+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+8, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+8, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+8, 8, p_00+851+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+4, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+4, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+4, 8, p_00+851+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+0, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+0, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+0, 8, p_00+851+0, 8, temp);
	memset(p_01+851, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+915+4, 28, q_00+901);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, q_01+901);
	gf2x_add(56, p_01+851+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+901+24, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+24, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+24, 8, p_01+851+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+20, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+20, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+20, 8, p_01+851+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+16, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+16, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+16, 8, p_01+851+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+12, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+12, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+12, 8, p_01+851+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+8, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+8, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+8, 8, p_01+851+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+4, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+4, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+4, 8, p_01+851+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+0, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+0, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+0, 8, p_01+851+0, 8, temp);
	memset(p_10+851, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, q_10+901);
	GF2X_MUL(56, temp2, 28, p_10+915+4, 28, q_11+901);
	gf2x_add(56, p_10+851+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+901+24, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+24, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+24, 8, p_10+851+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+20, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+20, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+20, 8, p_10+851+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+16, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+16, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+16, 8, p_10+851+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+12, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+12, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+12, 8, p_10+851+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+8, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+8, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+8, 8, p_10+851+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+4, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+4, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+4, 8, p_10+851+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+0, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+0, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+0, 8, p_10+851+0, 8, temp);
	memset(p_11+851, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+915+4, 28, q_10+901);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, q_11+901);
	gf2x_add(56, p_11+851+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+901+24, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+24, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+24, 8, p_11+851+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+20, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+20, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+20, 8, p_11+851+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+16, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+16, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+16, 8, p_11+851+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+12, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+12, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+12, 8, p_11+851+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+8, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+8, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+8, 8, p_11+851+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+4, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+4, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+4, 8, p_11+851+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+0, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+0, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+0, 8, p_11+851+0, 8, temp);
	

	// Calculating left operands: n: 7650, depth: 3
	// Digits to shift: 59
	// Displacement: 60
	GF2X_MUL(120, temp, 60, f_sum+1566+60, 60, p_00+851);
	GF2X_MUL(120, temp2, 60, g_sum+1566+60, 60, p_01+851);
	gf2x_add(120, f_sum+2544+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, f_sum+1566+0, 60, p_00+851);
	GF2X_MUL(120, temp2, 60, g_sum+1566+0, 60, p_01+851);
	gf2x_add(120, temp, 120, temp, 120, temp2);
	gf2x_add(60, f_sum+2544, 60, f_sum+2544, 60, temp+60);
	right_bit_shift_n(120, f_sum+2544, 49);
	GF2X_MUL(120, temp, 60, f_sum+1566+60, 60, p_10+851);
	GF2X_MUL(120, temp2, 60, g_sum+1566+60, 60, p_11+851);
	gf2x_add(120, g_sum+2544+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, f_sum+1566+0, 60, p_10+851);
	GF2X_MUL(120, temp2, 60, g_sum+1566+0, 60, p_11+851);
	gf2x_add(120, temp, 120, temp, 120, temp2);
	gf2x_add(60, g_sum+2544, 60, g_sum+2544, 60, temp+60);
	right_bit_shift_n(120, g_sum+2544, 49);
	

	delta = divstepsx_256(255, delta, f_sum+2601, g_sum+2601, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2597+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2597+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2597+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2597+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2597+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2589+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2589+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2589+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2589+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2589+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2573+16, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+16, 16, p_01+947);
	gf2x_add(32, f_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2573+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+0, 16, p_01+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+2830, 16, f_sum+2830, 16, temp+16);
	right_bit_shift_n(32, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2573+16, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+16, 16, p_11+947);
	gf2x_add(32, g_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2573+0, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2573+0, 16, p_11+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+2830, 16, g_sum+2830, 16, temp+16);
	right_bit_shift_n(32, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2843, g_sum+2843, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, q_00+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, q_01+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, q_10+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, q_11+933+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 5
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_10+947);
	gf2x_add(32, p_00+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_11+947);
	gf2x_add(32, p_01+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_10+947);
	gf2x_add(32, p_10+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_11+947);
	gf2x_add(32, p_11+915+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 3825, depth: 4
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+2545+28, 32, p_00+915);
	GF2X_MUL(64, temp2, 32, g_sum+2545+28, 32, p_01+915);
	gf2x_add(60, f_sum+2733, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, f_sum+2545);
	GF2X_MUL(56, temp2, 28, p_01+915+4, 28, g_sum+2545);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2733, 28, f_sum+2733, 28, temp+28);
	right_bit_shift_n(60, f_sum+2733, 56);
	GF2X_MUL(64, temp, 32, f_sum+2545+28, 32, p_10+915);
	GF2X_MUL(64, temp2, 32, g_sum+2545+28, 32, p_11+915);
	gf2x_add(60, g_sum+2733, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_10+915+4, 28, f_sum+2545);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, g_sum+2545);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2733, 28, g_sum+2733, 28, temp+28);
	right_bit_shift_n(60, g_sum+2733, 56);
	

	delta = divstepsx_256(255, delta, f_sum+2758, g_sum+2758, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2754+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2754+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2754+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2754+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2746+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2746+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2746+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2746+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2734+12, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+12, 16, p_01+947);
	gf2x_add(28, f_sum+2830, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, f_sum+2734);
	GF2X_MUL(24, temp2, 12, p_01+947+4, 12, g_sum+2734);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2830, 12, f_sum+2830, 12, temp+12);
	right_bit_shift_n(28, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2734+12, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+12, 16, p_11+947);
	gf2x_add(28, g_sum+2830, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+947+4, 12, f_sum+2734);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, g_sum+2734);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2830, 12, g_sum+2830, 12, temp+12);
	right_bit_shift_n(28, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2839, g_sum+2839, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2835+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2835+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2835+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2835+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+4, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+4, 8, p_01+963);
	gf2x_add(12, f_sum+2879, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, f_sum+2831);
	GF2X_MUL(8, temp2, 4, p_01+963+4, 4, g_sum+2831);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2879, 4, f_sum+2879, 4, temp+4);
	right_bit_shift_n(12, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+4, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+4, 8, p_11+963);
	gf2x_add(12, g_sum+2879, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+963+4, 4, f_sum+2831);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, g_sum+2831);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2879, 4, g_sum+2879, 4, temp+4);
	right_bit_shift_n(12, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2880, g_sum+2880, q_00+949, q_01+949, q_10+949, q_11+949);

	// Recombining results: n: 765, depth: 6
	memset(q_00+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, q_00+949);
	GF2X_MUL(8, temp2, 4, p_10+963+4, 4, q_01+949);
	gf2x_add(8, q_00+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+949+0, 4, p_00+963);
	GF2X_MUL(8, temp2, 4, q_01+949+0, 4, p_10+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+933+0, 8, q_00+933+0, 8, temp);
	memset(q_01+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+963+4, 4, q_00+949);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, q_01+949);
	gf2x_add(8, q_01+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+949+0, 4, p_01+963);
	GF2X_MUL(8, temp2, 4, q_01+949+0, 4, p_11+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+933+0, 8, q_01+933+0, 8, temp);
	memset(q_10+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, q_10+949);
	GF2X_MUL(8, temp2, 4, p_10+963+4, 4, q_11+949);
	gf2x_add(8, q_10+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+949+0, 4, p_00+963);
	GF2X_MUL(8, temp2, 4, q_11+949+0, 4, p_10+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+933+0, 8, q_10+933+0, 8, temp);
	memset(q_11+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+963+4, 4, q_10+949);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, q_11+949);
	gf2x_add(8, q_11+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+949+0, 4, p_01+963);
	GF2X_MUL(8, temp2, 4, q_11+949+0, 4, p_11+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+933+0, 8, q_11+933+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, q_00+933);
	GF2X_MUL(24, temp2, 12, p_10+947+4, 12, q_01+933);
	gf2x_add(24, q_00+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+933+8, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+8, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+8, 8, q_00+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+4, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+4, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+4, 8, q_00+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+0, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+0, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+0, 8, q_00+901+0, 8, temp);
	memset(q_01+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+947+4, 12, q_00+933);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, q_01+933);
	gf2x_add(24, q_01+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+933+8, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+8, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+8, 8, q_01+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+4, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+4, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+4, 8, q_01+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+0, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+0, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+0, 8, q_01+901+0, 8, temp);
	memset(q_10+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, q_10+933);
	GF2X_MUL(24, temp2, 12, p_10+947+4, 12, q_11+933);
	gf2x_add(24, q_10+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+933+8, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+8, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+8, 8, q_10+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+4, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+4, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+4, 8, q_10+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+0, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+0, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+0, 8, q_10+901+0, 8, temp);
	memset(q_11+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+947+4, 12, q_10+933);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, q_11+933);
	gf2x_add(24, q_11+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+933+8, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+8, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+8, 8, q_11+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+4, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+4, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+4, 8, q_11+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+0, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+0, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+0, 8, q_11+901+0, 8, temp);
	

	// Recombining results: n: 3825, depth: 4
	memset(q_00+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, q_00+901);
	GF2X_MUL(56, temp2, 28, p_10+915+4, 28, q_01+901);
	gf2x_add(56, q_00+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+901+24, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+24, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+24, 8, q_00+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+20, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+20, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+20, 8, q_00+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+16, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+16, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+16, 8, q_00+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+12, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+12, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+12, 8, q_00+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+8, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+8, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+8, 8, q_00+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+4, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+4, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+4, 8, q_00+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+0, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+0, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+841+0, 8, q_00+841+0, 8, temp);
	memset(q_01+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+915+4, 28, q_00+901);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, q_01+901);
	gf2x_add(56, q_01+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+901+24, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+24, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+24, 8, q_01+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+20, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+20, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+20, 8, q_01+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+16, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+16, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+16, 8, q_01+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+12, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+12, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+12, 8, q_01+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+8, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+8, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+8, 8, q_01+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+4, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+4, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+4, 8, q_01+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+0, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+0, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+841+0, 8, q_01+841+0, 8, temp);
	memset(q_10+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, q_10+901);
	GF2X_MUL(56, temp2, 28, p_10+915+4, 28, q_11+901);
	gf2x_add(56, q_10+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+901+24, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+24, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+24, 8, q_10+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+20, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+20, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+20, 8, q_10+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+16, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+16, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+16, 8, q_10+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+12, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+12, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+12, 8, q_10+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+8, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+8, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+8, 8, q_10+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+4, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+4, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+4, 8, q_10+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+0, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+0, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+841+0, 8, q_10+841+0, 8, temp);
	memset(q_11+841, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+915+4, 28, q_10+901);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, q_11+901);
	gf2x_add(56, q_11+841+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+901+24, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+24, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+24, 8, q_11+841+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+20, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+20, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+20, 8, q_11+841+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+16, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+16, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+16, 8, q_11+841+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+12, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+12, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+12, 8, q_11+841+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+8, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+8, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+8, 8, q_11+841+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+4, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+4, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+4, 8, q_11+841+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+0, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+0, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+841+0, 8, q_11+841+0, 8, temp);
	

	// Recombining results: n: 7650, depth: 3
	GF2X_MUL(120, temp, 60, q_00+841+0, 60, p_00+851);
	GF2X_MUL(120, temp2, 60, q_01+841+0, 60, p_10+851);
	gf2x_add(120, p_00+727+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, q_00+841+0, 60, p_01+851);
	GF2X_MUL(120, temp2, 60, q_01+841+0, 60, p_11+851);
	gf2x_add(120, p_01+727+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, q_10+841+0, 60, p_00+851);
	GF2X_MUL(120, temp2, 60, q_11+841+0, 60, p_10+851);
	gf2x_add(120, p_10+727+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, q_10+841+0, 60, p_01+851);
	GF2X_MUL(120, temp2, 60, q_11+841+0, 60, p_11+851);
	gf2x_add(120, p_11+727+0, 120, temp, 120, temp2);
	

	// Calculating left operands: n: 15195, depth: 2
	// Digits to shift: 119
	// Displacement: 120
	GF2X_MUL(240, temp, 120, f_sum+1448+118, 120, p_00+727);
	GF2X_MUL(240, temp2, 120, g_sum+1448+118, 120, p_01+727);
	gf2x_add(238, f_sum+2175, 238, temp+2, 238, temp2+2);
	GF2X_MUL(236, temp, 118, p_00+727+2, 118, f_sum+1448);
	GF2X_MUL(236, temp2, 118, p_01+727+2, 118, g_sum+1448);
	gf2x_add(236, temp, 236, temp, 236, temp2);
	gf2x_add(118, f_sum+2175, 118, f_sum+2175, 118, temp+118);
	right_bit_shift_n(238, f_sum+2175, 34);
	GF2X_MUL(240, temp, 120, f_sum+1448+118, 120, p_10+727);
	GF2X_MUL(240, temp2, 120, g_sum+1448+118, 120, p_11+727);
	gf2x_add(238, g_sum+2175, 238, temp+2, 238, temp2+2);
	GF2X_MUL(236, temp, 118, p_10+727+2, 118, f_sum+1448);
	GF2X_MUL(236, temp2, 118, p_11+727+2, 118, g_sum+1448);
	gf2x_add(236, temp, 236, temp, 236, temp2);
	gf2x_add(118, g_sum+2175, 118, g_sum+2175, 118, temp+118);
	right_bit_shift_n(238, g_sum+2175, 34);
	

	delta = divstepsx_256(255, delta, f_sum+2290, g_sum+2290, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2286+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2286+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2286+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2286+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2286+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2286+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2286+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2286+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2278+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2278+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2278+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2278+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2278+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2278+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2278+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2278+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2262+16, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2262+16, 16, p_01+947);
	gf2x_add(32, f_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2262+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2262+0, 16, p_01+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+2830, 16, f_sum+2830, 16, temp+16);
	right_bit_shift_n(32, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2262+16, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2262+16, 16, p_11+947);
	gf2x_add(32, g_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2262+0, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2262+0, 16, p_11+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+2830, 16, g_sum+2830, 16, temp+16);
	right_bit_shift_n(32, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2843, g_sum+2843, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, q_00+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, q_01+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, q_10+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, q_11+933+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 5
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_10+947);
	gf2x_add(32, p_00+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_11+947);
	gf2x_add(32, p_01+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_10+947);
	gf2x_add(32, p_10+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_11+947);
	gf2x_add(32, p_11+915+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 3825, depth: 4
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+2234+28, 32, p_00+915);
	GF2X_MUL(64, temp2, 32, g_sum+2234+28, 32, p_01+915);
	gf2x_add(60, f_sum+2733, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, f_sum+2234);
	GF2X_MUL(56, temp2, 28, p_01+915+4, 28, g_sum+2234);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+2733, 28, f_sum+2733, 28, temp+28);
	right_bit_shift_n(60, f_sum+2733, 56);
	GF2X_MUL(64, temp, 32, f_sum+2234+28, 32, p_10+915);
	GF2X_MUL(64, temp2, 32, g_sum+2234+28, 32, p_11+915);
	gf2x_add(60, g_sum+2733, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_10+915+4, 28, f_sum+2234);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, g_sum+2234);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+2733, 28, g_sum+2733, 28, temp+28);
	right_bit_shift_n(60, g_sum+2733, 56);
	

	delta = divstepsx_256(255, delta, f_sum+2758, g_sum+2758, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2754+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2754+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2754+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2754+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2754+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2746+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2746+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2746+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2746+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2746+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2734+12, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+12, 16, p_01+947);
	gf2x_add(28, f_sum+2830, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, f_sum+2734);
	GF2X_MUL(24, temp2, 12, p_01+947+4, 12, g_sum+2734);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2830, 12, f_sum+2830, 12, temp+12);
	right_bit_shift_n(28, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2734+12, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+12, 16, p_11+947);
	gf2x_add(28, g_sum+2830, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+947+4, 12, f_sum+2734);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, g_sum+2734);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2830, 12, g_sum+2830, 12, temp+12);
	right_bit_shift_n(28, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2839, g_sum+2839, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2835+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2835+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2835+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2835+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2835+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+4, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+4, 8, p_01+963);
	gf2x_add(12, f_sum+2879, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, f_sum+2831);
	GF2X_MUL(8, temp2, 4, p_01+963+4, 4, g_sum+2831);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2879, 4, f_sum+2879, 4, temp+4);
	right_bit_shift_n(12, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+4, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+4, 8, p_11+963);
	gf2x_add(12, g_sum+2879, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+963+4, 4, f_sum+2831);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, g_sum+2831);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2879, 4, g_sum+2879, 4, temp+4);
	right_bit_shift_n(12, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2880, g_sum+2880, q_00+949, q_01+949, q_10+949, q_11+949);

	// Recombining results: n: 765, depth: 6
	memset(q_00+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, q_00+949);
	GF2X_MUL(8, temp2, 4, p_10+963+4, 4, q_01+949);
	gf2x_add(8, q_00+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+949+0, 4, p_00+963);
	GF2X_MUL(8, temp2, 4, q_01+949+0, 4, p_10+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+933+0, 8, q_00+933+0, 8, temp);
	memset(q_01+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+963+4, 4, q_00+949);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, q_01+949);
	gf2x_add(8, q_01+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+949+0, 4, p_01+963);
	GF2X_MUL(8, temp2, 4, q_01+949+0, 4, p_11+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+933+0, 8, q_01+933+0, 8, temp);
	memset(q_10+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+963+4, 4, q_10+949);
	GF2X_MUL(8, temp2, 4, p_10+963+4, 4, q_11+949);
	gf2x_add(8, q_10+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+949+0, 4, p_00+963);
	GF2X_MUL(8, temp2, 4, q_11+949+0, 4, p_10+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+933+0, 8, q_10+933+0, 8, temp);
	memset(q_11+933, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+963+4, 4, q_10+949);
	GF2X_MUL(8, temp2, 4, p_11+963+4, 4, q_11+949);
	gf2x_add(8, q_11+933+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+949+0, 4, p_01+963);
	GF2X_MUL(8, temp2, 4, q_11+949+0, 4, p_11+963);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+933+0, 8, q_11+933+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(q_00+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, q_00+933);
	GF2X_MUL(24, temp2, 12, p_10+947+4, 12, q_01+933);
	gf2x_add(24, q_00+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+933+8, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+8, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+8, 8, q_00+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+4, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+4, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+4, 8, q_00+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+0, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_01+933+0, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+901+0, 8, q_00+901+0, 8, temp);
	memset(q_01+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+947+4, 12, q_00+933);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, q_01+933);
	gf2x_add(24, q_01+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+933+8, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+8, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+8, 8, q_01+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+4, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+4, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+4, 8, q_01+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+933+0, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_01+933+0, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+901+0, 8, q_01+901+0, 8, temp);
	memset(q_10+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+947+4, 12, q_10+933);
	GF2X_MUL(24, temp2, 12, p_10+947+4, 12, q_11+933);
	gf2x_add(24, q_10+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+933+8, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+8, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+8, 8, q_10+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+4, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+4, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+4, 8, q_10+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+0, 4, p_00+947);
	GF2X_MUL(8, temp2, 4, q_11+933+0, 4, p_10+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+901+0, 8, q_10+901+0, 8, temp);
	memset(q_11+901, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+947+4, 12, q_10+933);
	GF2X_MUL(24, temp2, 12, p_11+947+4, 12, q_11+933);
	gf2x_add(24, q_11+901+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+933+8, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+8, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+8, 8, q_11+901+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+4, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+4, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+4, 8, q_11+901+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+933+0, 4, p_01+947);
	GF2X_MUL(8, temp2, 4, q_11+933+0, 4, p_11+947);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+901+0, 8, q_11+901+0, 8, temp);
	

	// Recombining results: n: 3825, depth: 4
	memset(p_00+851, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, q_00+901);
	GF2X_MUL(56, temp2, 28, p_10+915+4, 28, q_01+901);
	gf2x_add(56, p_00+851+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+901+24, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+24, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+24, 8, p_00+851+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+20, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+20, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+20, 8, p_00+851+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+16, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+16, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+16, 8, p_00+851+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+12, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+12, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+12, 8, p_00+851+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+8, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+8, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+8, 8, p_00+851+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+4, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+4, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+4, 8, p_00+851+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+0, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_01+901+0, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+851+0, 8, p_00+851+0, 8, temp);
	memset(p_01+851, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+915+4, 28, q_00+901);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, q_01+901);
	gf2x_add(56, p_01+851+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+901+24, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+24, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+24, 8, p_01+851+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+20, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+20, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+20, 8, p_01+851+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+16, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+16, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+16, 8, p_01+851+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+12, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+12, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+12, 8, p_01+851+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+8, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+8, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+8, 8, p_01+851+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+4, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+4, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+4, 8, p_01+851+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+901+0, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_01+901+0, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+851+0, 8, p_01+851+0, 8, temp);
	memset(p_10+851, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+915+4, 28, q_10+901);
	GF2X_MUL(56, temp2, 28, p_10+915+4, 28, q_11+901);
	gf2x_add(56, p_10+851+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+901+24, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+24, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+24, 8, p_10+851+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+20, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+20, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+20, 8, p_10+851+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+16, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+16, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+16, 8, p_10+851+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+12, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+12, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+12, 8, p_10+851+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+8, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+8, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+8, 8, p_10+851+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+4, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+4, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+4, 8, p_10+851+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+0, 4, p_00+915);
	GF2X_MUL(8, temp2, 4, q_11+901+0, 4, p_10+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+851+0, 8, p_10+851+0, 8, temp);
	memset(p_11+851, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+915+4, 28, q_10+901);
	GF2X_MUL(56, temp2, 28, p_11+915+4, 28, q_11+901);
	gf2x_add(56, p_11+851+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+901+24, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+24, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+24, 8, p_11+851+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+20, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+20, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+20, 8, p_11+851+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+16, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+16, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+16, 8, p_11+851+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+12, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+12, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+12, 8, p_11+851+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+8, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+8, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+8, 8, p_11+851+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+4, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+4, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+4, 8, p_11+851+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+901+0, 4, p_01+915);
	GF2X_MUL(8, temp2, 4, q_11+901+0, 4, p_11+915);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+851+0, 8, p_11+851+0, 8, temp);
	

	// Calculating left operands: n: 7545, depth: 3
	// Digits to shift: 59
	// Displacement: 59
	GF2X_MUL(120, temp, 60, f_sum+2176+58, 60, p_00+851);
	GF2X_MUL(120, temp2, 60, g_sum+2176+58, 60, p_01+851);
	gf2x_add(119, f_sum+2544, 119, temp+1, 119, temp2+1);
	GF2X_MUL(116, temp, 58, p_00+851+2, 58, f_sum+2176);
	GF2X_MUL(116, temp2, 58, p_01+851+2, 58, g_sum+2176);
	gf2x_add(116, temp, 116, temp, 116, temp2);
	gf2x_add(59, f_sum+2544, 59, f_sum+2544, 59, temp+57);
	GF2X_MUL(4, temp, 2, f_sum+2176+56, 2, p_00+851);
	GF2X_MUL(4, temp2, 2, g_sum+2176+56, 2, p_01+851);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(1, f_sum+2544, 1, f_sum+2544, 1, temp+3);
	right_bit_shift_n(118, f_sum+2544, 49);
	GF2X_MUL(120, temp, 60, f_sum+2176+58, 60, p_10+851);
	GF2X_MUL(120, temp2, 60, g_sum+2176+58, 60, p_11+851);
	gf2x_add(119, g_sum+2544, 119, temp+1, 119, temp2+1);
	GF2X_MUL(116, temp, 58, p_10+851+2, 58, f_sum+2176);
	GF2X_MUL(116, temp2, 58, p_11+851+2, 58, g_sum+2176);
	gf2x_add(116, temp, 116, temp, 116, temp2);
	gf2x_add(59, g_sum+2544, 59, g_sum+2544, 59, temp+57);
	GF2X_MUL(4, temp, 2, f_sum+2176+56, 2, p_10+851);
	GF2X_MUL(4, temp2, 2, g_sum+2176+56, 2, p_11+851);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(1, g_sum+2544, 1, g_sum+2544, 1, temp+3);
	right_bit_shift_n(118, g_sum+2544, 49);
	

	delta = divstepsx_256(255, delta, f_sum+2600, g_sum+2600, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2596+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2596+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2596+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2596+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2596+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2596+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2596+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2596+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2588+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2588+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2588+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2588+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2588+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2588+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2588+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2588+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2572+16, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2572+16, 16, p_01+947);
	gf2x_add(32, f_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2572+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2572+0, 16, p_01+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+2830, 16, f_sum+2830, 16, temp+16);
	right_bit_shift_n(32, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2572+16, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2572+16, 16, p_11+947);
	gf2x_add(32, g_sum+2830+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+2572+0, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2572+0, 16, p_11+947);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+2830, 16, g_sum+2830, 16, temp+16);
	right_bit_shift_n(32, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2843, g_sum+2843, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2839+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2839+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2839+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2831+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, q_00+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, q_01+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, q_10+933+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, q_11+933+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 5
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_10+947);
	gf2x_add(32, p_00+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_01+933+0, 16, p_11+947);
	gf2x_add(32, p_01+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_10+947);
	gf2x_add(32, p_10+915+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+933+0, 16, p_01+947);
	GF2X_MUL(32, temp2, 16, q_11+933+0, 16, p_11+947);
	gf2x_add(32, p_11+915+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 3720, depth: 4
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+2545+27, 32, p_00+915);
	GF2X_MUL(64, temp2, 32, g_sum+2545+27, 32, p_01+915);
	gf2x_add(59, f_sum+2733, 59, temp+5, 59, temp2+5);
	GF2X_MUL(54, temp, 27, p_00+915+5, 27, f_sum+2545);
	GF2X_MUL(54, temp2, 27, p_01+915+5, 27, g_sum+2545);
	gf2x_add(54, temp, 54, temp, 54, temp2);
	gf2x_add(27, f_sum+2733, 27, f_sum+2733, 27, temp+27);
	right_bit_shift_n(59, f_sum+2733, 56);
	GF2X_MUL(64, temp, 32, f_sum+2545+27, 32, p_10+915);
	GF2X_MUL(64, temp2, 32, g_sum+2545+27, 32, p_11+915);
	gf2x_add(59, g_sum+2733, 59, temp+5, 59, temp2+5);
	GF2X_MUL(54, temp, 27, p_10+915+5, 27, f_sum+2545);
	GF2X_MUL(54, temp2, 27, p_11+915+5, 27, g_sum+2545);
	gf2x_add(54, temp, 54, temp, 54, temp2);
	gf2x_add(27, g_sum+2733, 27, g_sum+2733, 27, temp+27);
	right_bit_shift_n(59, g_sum+2733, 56);
	

	delta = divstepsx_256(255, delta, f_sum+2757, g_sum+2757, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2753+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2753+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2753+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2753+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2753+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2753+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2753+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2753+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2745+8, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2745+8, 8, p_01+963);
	gf2x_add(16, f_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2745+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2745+0, 8, p_01+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2879, 8, f_sum+2879, 8, temp+8);
	right_bit_shift_n(16, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2745+8, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2745+8, 8, p_11+963);
	gf2x_add(16, g_sum+2879+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2745+0, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2745+0, 8, p_11+963);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2879, 8, g_sum+2879, 8, temp+8);
	right_bit_shift_n(16, g_sum+2879, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2884, g_sum+2884, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2880+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2880+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2880+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, q_00+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, q_01+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, q_10+949+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, q_11+949+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_10+963);
	gf2x_add(16, p_00+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_01+949+0, 8, p_11+963);
	gf2x_add(16, p_01+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_10+963);
	gf2x_add(16, p_10+947+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+949+0, 8, p_01+963);
	GF2X_MUL(16, temp2, 8, q_11+949+0, 8, p_11+963);
	gf2x_add(16, p_11+947+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1680, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2734+11, 16, p_00+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+11, 16, p_01+947);
	gf2x_add(27, f_sum+2830, 27, temp+5, 27, temp2+5);
	GF2X_MUL(22, temp, 11, p_00+947+5, 11, f_sum+2734);
	GF2X_MUL(22, temp2, 11, p_01+947+5, 11, g_sum+2734);
	gf2x_add(22, temp, 22, temp, 22, temp2);
	gf2x_add(11, f_sum+2830, 11, f_sum+2830, 11, temp+11);
	right_bit_shift_n(27, f_sum+2830, 60);
	GF2X_MUL(32, temp, 16, f_sum+2734+11, 16, p_10+947);
	GF2X_MUL(32, temp2, 16, g_sum+2734+11, 16, p_11+947);
	gf2x_add(27, g_sum+2830, 27, temp+5, 27, temp2+5);
	GF2X_MUL(22, temp, 11, p_10+947+5, 11, f_sum+2734);
	GF2X_MUL(22, temp2, 11, p_11+947+5, 11, g_sum+2734);
	gf2x_add(22, temp, 22, temp, 22, temp2);
	gf2x_add(11, g_sum+2830, 11, g_sum+2830, 11, temp+11);
	right_bit_shift_n(27, g_sum+2830, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2838, g_sum+2838, p_00+971, p_01+971, p_10+971, p_11+971);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2834+4, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2834+4, 4, p_01+971);
	gf2x_add(8, f_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2834+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, g_sum+2834+0, 4, p_01+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2904, 4, f_sum+2904, 4, temp+4);
	right_bit_shift_n(8, f_sum+2904, 63);
	GF2X_MUL(8, temp, 4, f_sum+2834+4, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2834+4, 4, p_11+971);
	gf2x_add(8, g_sum+2904+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2834+0, 4, p_10+971);
	GF2X_MUL(8, temp2, 4, g_sum+2834+0, 4, p_11+971);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2904, 4, g_sum+2904, 4, temp+4);
	right_bit_shift_n(8, g_sum+2904, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2905, g_sum+2905, q_00+957, q_01+957, q_10+957, q_11+957);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_10+971);
	gf2x_add(8, p_00+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_01+957+0, 4, p_11+971);
	gf2x_add(8, p_01+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_00+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_10+971);
	gf2x_add(8, p_10+963+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+957+0, 4, p_01+971);
	GF2X_MUL(8, temp2, 4, q_11+957+0, 4, p_11+971);
	gf2x_add(8, p_11+963+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 660, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2831+3, 8, p_00+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+3, 8, p_01+963);
	gf2x_add(11, f_sum+2879, 11, temp+5, 11, temp2+5);
	GF2X_MUL(6, temp, 3, p_00+963+5, 3, f_sum+2831);
	GF2X_MUL(6, temp2, 3, p_01+963+5, 3, g_sum+2831);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(3, f_sum+2879, 3, f_sum+2879, 3, temp+3);
	right_bit_shift_n(11, f_sum+2879, 62);
	GF2X_MUL(16, temp, 8, f_sum+2831+3, 8, p_10+963);
	GF2X_MUL(16, temp2, 8, g_sum+2831+3, 8, p_11+963);
	gf2x_add(11, g_sum+2879, 11, temp+5, 11, temp2+5);
	GF2X_MUL(6, temp, 3, p_10+963+5, 3, f_sum+2831);
	GF2X_MUL(6, temp2, 3, p_11+963+5, 3, g_sum+2831);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(3, g_sum+2879, 3, g_sum+2879, 3, temp+3);
	right_bit_shift_n(11, g_sum+2879, 62);
	

	delta = support_jumpdivstep(150, delta, 3, f_sum+2880, g_sum+2880, q_00+949, q_01+949, q_10+949, q_11+949, x);

	// Recombining results: n: 660, depth: 6
	memset(q_00+933, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(6, temp, 3, p_00+963+5, 3, q_00+949);
	GF2X_MUL(6, temp2, 3, p_10+963+5, 3, q_01+949);
	gf2x_add(6, q_00+933+5, 6, temp, 6, temp2);
	GF2X_MUL(6, temp, 3, p_00+963+2, 3, q_00+949);
	GF2X_MUL(6, temp2, 3, p_10+963+2, 3, q_01+949);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+933+2, 6, q_00+933+2, 6, temp);
	GF2X_MUL(4, temp, 2, q_00+949+1, 2, p_00+963);
	GF2X_MUL(4, temp2, 2, q_01+949+1, 2, p_10+963);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+933+1, 4, q_00+933+1, 4, temp);
	GF2X_MUL(2, temp, 1, p_00+963+1, 1, q_00+949);
	GF2X_MUL(2, temp2, 1, p_10+963+1, 1, q_01+949);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+933+1, 2, q_00+933+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+949+0, 1, p_00+963);
	GF2X_MUL(2, temp2, 1, q_01+949+0, 1, p_10+963);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+933+0, 2, q_00+933+0, 2, temp);
	memset(q_01+933, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(6, temp, 3, p_01+963+5, 3, q_00+949);
	GF2X_MUL(6, temp2, 3, p_11+963+5, 3, q_01+949);
	gf2x_add(6, q_01+933+5, 6, temp, 6, temp2);
	GF2X_MUL(6, temp, 3, p_01+963+2, 3, q_00+949);
	GF2X_MUL(6, temp2, 3, p_11+963+2, 3, q_01+949);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+933+2, 6, q_01+933+2, 6, temp);
	GF2X_MUL(4, temp, 2, q_00+949+1, 2, p_01+963);
	GF2X_MUL(4, temp2, 2, q_01+949+1, 2, p_11+963);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+933+1, 4, q_01+933+1, 4, temp);
	GF2X_MUL(2, temp, 1, p_01+963+1, 1, q_00+949);
	GF2X_MUL(2, temp2, 1, p_11+963+1, 1, q_01+949);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+933+1, 2, q_01+933+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+949+0, 1, p_01+963);
	GF2X_MUL(2, temp2, 1, q_01+949+0, 1, p_11+963);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+933+0, 2, q_01+933+0, 2, temp);
	memset(q_10+933, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(6, temp, 3, p_00+963+5, 3, q_10+949);
	GF2X_MUL(6, temp2, 3, p_10+963+5, 3, q_11+949);
	gf2x_add(6, q_10+933+5, 6, temp, 6, temp2);
	GF2X_MUL(6, temp, 3, p_00+963+2, 3, q_10+949);
	GF2X_MUL(6, temp2, 3, p_10+963+2, 3, q_11+949);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+933+2, 6, q_10+933+2, 6, temp);
	GF2X_MUL(4, temp, 2, q_10+949+1, 2, p_00+963);
	GF2X_MUL(4, temp2, 2, q_11+949+1, 2, p_10+963);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+933+1, 4, q_10+933+1, 4, temp);
	GF2X_MUL(2, temp, 1, p_00+963+1, 1, q_10+949);
	GF2X_MUL(2, temp2, 1, p_10+963+1, 1, q_11+949);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+933+1, 2, q_10+933+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+949+0, 1, p_00+963);
	GF2X_MUL(2, temp2, 1, q_11+949+0, 1, p_10+963);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+933+0, 2, q_10+933+0, 2, temp);
	memset(q_11+933, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(6, temp, 3, p_01+963+5, 3, q_10+949);
	GF2X_MUL(6, temp2, 3, p_11+963+5, 3, q_11+949);
	gf2x_add(6, q_11+933+5, 6, temp, 6, temp2);
	GF2X_MUL(6, temp, 3, p_01+963+2, 3, q_10+949);
	GF2X_MUL(6, temp2, 3, p_11+963+2, 3, q_11+949);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+933+2, 6, q_11+933+2, 6, temp);
	GF2X_MUL(4, temp, 2, q_10+949+1, 2, p_01+963);
	GF2X_MUL(4, temp2, 2, q_11+949+1, 2, p_11+963);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+933+1, 4, q_11+933+1, 4, temp);
	GF2X_MUL(2, temp, 1, p_01+963+1, 1, q_10+949);
	GF2X_MUL(2, temp2, 1, p_11+963+1, 1, q_11+949);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+933+1, 2, q_11+933+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+949+0, 1, p_01+963);
	GF2X_MUL(2, temp2, 1, q_11+949+0, 1, p_11+963);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+933+0, 2, q_11+933+0, 2, temp);
	

	// Recombining results: n: 1680, depth: 5
	memset(q_00+901, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(22, temp, 11, p_00+947+5, 11, q_00+933);
	GF2X_MUL(22, temp2, 11, p_10+947+5, 11, q_01+933);
	gf2x_add(22, q_00+901+5, 22, temp, 22, temp2);
	GF2X_MUL(10, temp, 5, q_00+933+6, 5, p_00+947);
	GF2X_MUL(10, temp2, 5, q_01+933+6, 5, p_10+947);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+901+6, 10, q_00+901+6, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+933+1, 5, p_00+947);
	GF2X_MUL(10, temp2, 5, q_01+933+1, 5, p_10+947);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+901+1, 10, q_00+901+1, 10, temp);
	GF2X_MUL(2, temp, 1, p_00+947+4, 1, q_00+933);
	GF2X_MUL(2, temp2, 1, p_10+947+4, 1, q_01+933);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+901+4, 2, q_00+901+4, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+947+3, 1, q_00+933);
	GF2X_MUL(2, temp2, 1, p_10+947+3, 1, q_01+933);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+901+3, 2, q_00+901+3, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+947+2, 1, q_00+933);
	GF2X_MUL(2, temp2, 1, p_10+947+2, 1, q_01+933);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+901+2, 2, q_00+901+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+947+1, 1, q_00+933);
	GF2X_MUL(2, temp2, 1, p_10+947+1, 1, q_01+933);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+901+1, 2, q_00+901+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+933+0, 1, p_00+947);
	GF2X_MUL(2, temp2, 1, q_01+933+0, 1, p_10+947);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+901+0, 2, q_00+901+0, 2, temp);
	memset(q_01+901, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(22, temp, 11, p_01+947+5, 11, q_00+933);
	GF2X_MUL(22, temp2, 11, p_11+947+5, 11, q_01+933);
	gf2x_add(22, q_01+901+5, 22, temp, 22, temp2);
	GF2X_MUL(10, temp, 5, q_00+933+6, 5, p_01+947);
	GF2X_MUL(10, temp2, 5, q_01+933+6, 5, p_11+947);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+901+6, 10, q_01+901+6, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+933+1, 5, p_01+947);
	GF2X_MUL(10, temp2, 5, q_01+933+1, 5, p_11+947);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+901+1, 10, q_01+901+1, 10, temp);
	GF2X_MUL(2, temp, 1, p_01+947+4, 1, q_00+933);
	GF2X_MUL(2, temp2, 1, p_11+947+4, 1, q_01+933);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+901+4, 2, q_01+901+4, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+947+3, 1, q_00+933);
	GF2X_MUL(2, temp2, 1, p_11+947+3, 1, q_01+933);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+901+3, 2, q_01+901+3, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+947+2, 1, q_00+933);
	GF2X_MUL(2, temp2, 1, p_11+947+2, 1, q_01+933);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+901+2, 2, q_01+901+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+947+1, 1, q_00+933);
	GF2X_MUL(2, temp2, 1, p_11+947+1, 1, q_01+933);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+901+1, 2, q_01+901+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+933+0, 1, p_01+947);
	GF2X_MUL(2, temp2, 1, q_01+933+0, 1, p_11+947);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+901+0, 2, q_01+901+0, 2, temp);
	memset(q_10+901, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(22, temp, 11, p_00+947+5, 11, q_10+933);
	GF2X_MUL(22, temp2, 11, p_10+947+5, 11, q_11+933);
	gf2x_add(22, q_10+901+5, 22, temp, 22, temp2);
	GF2X_MUL(10, temp, 5, q_10+933+6, 5, p_00+947);
	GF2X_MUL(10, temp2, 5, q_11+933+6, 5, p_10+947);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+901+6, 10, q_10+901+6, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+933+1, 5, p_00+947);
	GF2X_MUL(10, temp2, 5, q_11+933+1, 5, p_10+947);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+901+1, 10, q_10+901+1, 10, temp);
	GF2X_MUL(2, temp, 1, p_00+947+4, 1, q_10+933);
	GF2X_MUL(2, temp2, 1, p_10+947+4, 1, q_11+933);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+901+4, 2, q_10+901+4, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+947+3, 1, q_10+933);
	GF2X_MUL(2, temp2, 1, p_10+947+3, 1, q_11+933);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+901+3, 2, q_10+901+3, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+947+2, 1, q_10+933);
	GF2X_MUL(2, temp2, 1, p_10+947+2, 1, q_11+933);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+901+2, 2, q_10+901+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+947+1, 1, q_10+933);
	GF2X_MUL(2, temp2, 1, p_10+947+1, 1, q_11+933);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+901+1, 2, q_10+901+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+933+0, 1, p_00+947);
	GF2X_MUL(2, temp2, 1, q_11+933+0, 1, p_10+947);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+901+0, 2, q_10+901+0, 2, temp);
	memset(q_11+901, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(22, temp, 11, p_01+947+5, 11, q_10+933);
	GF2X_MUL(22, temp2, 11, p_11+947+5, 11, q_11+933);
	gf2x_add(22, q_11+901+5, 22, temp, 22, temp2);
	GF2X_MUL(10, temp, 5, q_10+933+6, 5, p_01+947);
	GF2X_MUL(10, temp2, 5, q_11+933+6, 5, p_11+947);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+901+6, 10, q_11+901+6, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+933+1, 5, p_01+947);
	GF2X_MUL(10, temp2, 5, q_11+933+1, 5, p_11+947);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+901+1, 10, q_11+901+1, 10, temp);
	GF2X_MUL(2, temp, 1, p_01+947+4, 1, q_10+933);
	GF2X_MUL(2, temp2, 1, p_11+947+4, 1, q_11+933);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+901+4, 2, q_11+901+4, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+947+3, 1, q_10+933);
	GF2X_MUL(2, temp2, 1, p_11+947+3, 1, q_11+933);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+901+3, 2, q_11+901+3, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+947+2, 1, q_10+933);
	GF2X_MUL(2, temp2, 1, p_11+947+2, 1, q_11+933);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+901+2, 2, q_11+901+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+947+1, 1, q_10+933);
	GF2X_MUL(2, temp2, 1, p_11+947+1, 1, q_11+933);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+901+1, 2, q_11+901+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+933+0, 1, p_01+947);
	GF2X_MUL(2, temp2, 1, q_11+933+0, 1, p_11+947);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+901+0, 2, q_11+901+0, 2, temp);
	

	// Recombining results: n: 3720, depth: 4
	memset(q_00+841, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(54, temp, 27, p_00+915+5, 27, q_00+901);
	GF2X_MUL(54, temp2, 27, p_10+915+5, 27, q_01+901);
	gf2x_add(54, q_00+841+5, 54, temp, 54, temp2);
	GF2X_MUL(10, temp, 5, q_00+901+22, 5, p_00+915);
	GF2X_MUL(10, temp2, 5, q_01+901+22, 5, p_10+915);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+841+22, 10, q_00+841+22, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+901+17, 5, p_00+915);
	GF2X_MUL(10, temp2, 5, q_01+901+17, 5, p_10+915);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+841+17, 10, q_00+841+17, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+901+12, 5, p_00+915);
	GF2X_MUL(10, temp2, 5, q_01+901+12, 5, p_10+915);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+841+12, 10, q_00+841+12, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+901+7, 5, p_00+915);
	GF2X_MUL(10, temp2, 5, q_01+901+7, 5, p_10+915);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+841+7, 10, q_00+841+7, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+901+2, 5, p_00+915);
	GF2X_MUL(10, temp2, 5, q_01+901+2, 5, p_10+915);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+841+2, 10, q_00+841+2, 10, temp);
	GF2X_MUL(4, temp, 2, p_00+915+3, 2, q_00+901);
	GF2X_MUL(4, temp2, 2, p_10+915+3, 2, q_01+901);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+841+3, 4, q_00+841+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+915+1, 2, q_00+901);
	GF2X_MUL(4, temp2, 2, p_10+915+1, 2, q_01+901);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+841+1, 4, q_00+841+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_00+901+1, 1, p_00+915);
	GF2X_MUL(2, temp2, 1, q_01+901+1, 1, p_10+915);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+841+1, 2, q_00+841+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+901+0, 1, p_00+915);
	GF2X_MUL(2, temp2, 1, q_01+901+0, 1, p_10+915);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+841+0, 2, q_00+841+0, 2, temp);
	memset(q_01+841, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(54, temp, 27, p_01+915+5, 27, q_00+901);
	GF2X_MUL(54, temp2, 27, p_11+915+5, 27, q_01+901);
	gf2x_add(54, q_01+841+5, 54, temp, 54, temp2);
	GF2X_MUL(10, temp, 5, q_00+901+22, 5, p_01+915);
	GF2X_MUL(10, temp2, 5, q_01+901+22, 5, p_11+915);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+841+22, 10, q_01+841+22, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+901+17, 5, p_01+915);
	GF2X_MUL(10, temp2, 5, q_01+901+17, 5, p_11+915);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+841+17, 10, q_01+841+17, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+901+12, 5, p_01+915);
	GF2X_MUL(10, temp2, 5, q_01+901+12, 5, p_11+915);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+841+12, 10, q_01+841+12, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+901+7, 5, p_01+915);
	GF2X_MUL(10, temp2, 5, q_01+901+7, 5, p_11+915);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+841+7, 10, q_01+841+7, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+901+2, 5, p_01+915);
	GF2X_MUL(10, temp2, 5, q_01+901+2, 5, p_11+915);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+841+2, 10, q_01+841+2, 10, temp);
	GF2X_MUL(4, temp, 2, p_01+915+3, 2, q_00+901);
	GF2X_MUL(4, temp2, 2, p_11+915+3, 2, q_01+901);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+841+3, 4, q_01+841+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+915+1, 2, q_00+901);
	GF2X_MUL(4, temp2, 2, p_11+915+1, 2, q_01+901);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+841+1, 4, q_01+841+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_00+901+1, 1, p_01+915);
	GF2X_MUL(2, temp2, 1, q_01+901+1, 1, p_11+915);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+841+1, 2, q_01+841+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+901+0, 1, p_01+915);
	GF2X_MUL(2, temp2, 1, q_01+901+0, 1, p_11+915);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+841+0, 2, q_01+841+0, 2, temp);
	memset(q_10+841, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(54, temp, 27, p_00+915+5, 27, q_10+901);
	GF2X_MUL(54, temp2, 27, p_10+915+5, 27, q_11+901);
	gf2x_add(54, q_10+841+5, 54, temp, 54, temp2);
	GF2X_MUL(10, temp, 5, q_10+901+22, 5, p_00+915);
	GF2X_MUL(10, temp2, 5, q_11+901+22, 5, p_10+915);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+841+22, 10, q_10+841+22, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+901+17, 5, p_00+915);
	GF2X_MUL(10, temp2, 5, q_11+901+17, 5, p_10+915);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+841+17, 10, q_10+841+17, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+901+12, 5, p_00+915);
	GF2X_MUL(10, temp2, 5, q_11+901+12, 5, p_10+915);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+841+12, 10, q_10+841+12, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+901+7, 5, p_00+915);
	GF2X_MUL(10, temp2, 5, q_11+901+7, 5, p_10+915);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+841+7, 10, q_10+841+7, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+901+2, 5, p_00+915);
	GF2X_MUL(10, temp2, 5, q_11+901+2, 5, p_10+915);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+841+2, 10, q_10+841+2, 10, temp);
	GF2X_MUL(4, temp, 2, p_00+915+3, 2, q_10+901);
	GF2X_MUL(4, temp2, 2, p_10+915+3, 2, q_11+901);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+841+3, 4, q_10+841+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+915+1, 2, q_10+901);
	GF2X_MUL(4, temp2, 2, p_10+915+1, 2, q_11+901);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+841+1, 4, q_10+841+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_10+901+1, 1, p_00+915);
	GF2X_MUL(2, temp2, 1, q_11+901+1, 1, p_10+915);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+841+1, 2, q_10+841+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+901+0, 1, p_00+915);
	GF2X_MUL(2, temp2, 1, q_11+901+0, 1, p_10+915);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+841+0, 2, q_10+841+0, 2, temp);
	memset(q_11+841, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(54, temp, 27, p_01+915+5, 27, q_10+901);
	GF2X_MUL(54, temp2, 27, p_11+915+5, 27, q_11+901);
	gf2x_add(54, q_11+841+5, 54, temp, 54, temp2);
	GF2X_MUL(10, temp, 5, q_10+901+22, 5, p_01+915);
	GF2X_MUL(10, temp2, 5, q_11+901+22, 5, p_11+915);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+841+22, 10, q_11+841+22, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+901+17, 5, p_01+915);
	GF2X_MUL(10, temp2, 5, q_11+901+17, 5, p_11+915);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+841+17, 10, q_11+841+17, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+901+12, 5, p_01+915);
	GF2X_MUL(10, temp2, 5, q_11+901+12, 5, p_11+915);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+841+12, 10, q_11+841+12, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+901+7, 5, p_01+915);
	GF2X_MUL(10, temp2, 5, q_11+901+7, 5, p_11+915);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+841+7, 10, q_11+841+7, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+901+2, 5, p_01+915);
	GF2X_MUL(10, temp2, 5, q_11+901+2, 5, p_11+915);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+841+2, 10, q_11+841+2, 10, temp);
	GF2X_MUL(4, temp, 2, p_01+915+3, 2, q_10+901);
	GF2X_MUL(4, temp2, 2, p_11+915+3, 2, q_11+901);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+841+3, 4, q_11+841+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+915+1, 2, q_10+901);
	GF2X_MUL(4, temp2, 2, p_11+915+1, 2, q_11+901);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+841+1, 4, q_11+841+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_10+901+1, 1, p_01+915);
	GF2X_MUL(2, temp2, 1, q_11+901+1, 1, p_11+915);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+841+1, 2, q_11+841+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+901+0, 1, p_01+915);
	GF2X_MUL(2, temp2, 1, q_11+901+0, 1, p_11+915);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+841+0, 2, q_11+841+0, 2, temp);
	

	// Recombining results: n: 7545, depth: 3
	GF2X_MUL(118, temp, 59, p_00+851+1, 59, q_00+841);
	GF2X_MUL(118, temp2, 59, p_10+851+1, 59, q_01+841);
	gf2x_add(118, q_00+721+0, 118, temp, 118, temp2);
	GF2X_MUL(2, temp, 1, q_00+841+58, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+58, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+57, 2, q_00+721+57, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+57, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+57, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+56, 2, q_00+721+56, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+56, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+56, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+55, 2, q_00+721+55, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+55, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+55, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+54, 2, q_00+721+54, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+54, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+54, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+53, 2, q_00+721+53, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+53, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+53, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+52, 2, q_00+721+52, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+52, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+52, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+51, 2, q_00+721+51, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+51, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+51, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+50, 2, q_00+721+50, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+50, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+50, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+49, 2, q_00+721+49, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+49, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+49, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+48, 2, q_00+721+48, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+48, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+48, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+47, 2, q_00+721+47, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+47, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+47, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+46, 2, q_00+721+46, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+46, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+46, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+45, 2, q_00+721+45, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+45, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+45, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+44, 2, q_00+721+44, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+44, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+44, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+43, 2, q_00+721+43, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+43, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+43, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+42, 2, q_00+721+42, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+42, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+42, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+41, 2, q_00+721+41, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+41, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+41, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+40, 2, q_00+721+40, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+40, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+40, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+39, 2, q_00+721+39, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+39, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+39, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+38, 2, q_00+721+38, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+38, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+38, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+37, 2, q_00+721+37, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+37, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+37, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+36, 2, q_00+721+36, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+36, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+36, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+35, 2, q_00+721+35, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+35, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+35, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+34, 2, q_00+721+34, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+34, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+34, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+33, 2, q_00+721+33, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+33, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+33, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+32, 2, q_00+721+32, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+32, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+32, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+31, 2, q_00+721+31, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+31, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+31, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+30, 2, q_00+721+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+30, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+30, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+29, 2, q_00+721+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+29, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+29, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+28, 2, q_00+721+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+28, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+28, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+27, 2, q_00+721+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+27, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+27, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+26, 2, q_00+721+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+26, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+26, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+25, 2, q_00+721+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+25, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+25, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+24, 2, q_00+721+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+24, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+24, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+23, 2, q_00+721+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+23, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+23, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+22, 2, q_00+721+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+22, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+22, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+21, 2, q_00+721+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+21, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+21, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+20, 2, q_00+721+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+20, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+20, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+19, 2, q_00+721+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+19, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+19, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+18, 2, q_00+721+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+18, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+18, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+17, 2, q_00+721+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+17, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+17, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+16, 2, q_00+721+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+16, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+16, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+15, 2, q_00+721+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+15, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+15, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+14, 2, q_00+721+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+14, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+14, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+13, 2, q_00+721+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+13, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+13, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+12, 2, q_00+721+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+12, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+12, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+11, 2, q_00+721+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+11, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+11, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+10, 2, q_00+721+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+10, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+10, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+9, 2, q_00+721+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+9, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+9, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+8, 2, q_00+721+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+8, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+8, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+7, 2, q_00+721+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+7, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+7, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+6, 2, q_00+721+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+6, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+6, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+5, 2, q_00+721+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+5, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+5, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+4, 2, q_00+721+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+4, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+4, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+3, 2, q_00+721+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+3, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+3, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+2, 2, q_00+721+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+2, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+2, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+1, 2, q_00+721+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+1, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+1, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+721+0, 2, q_00+721+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+0, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_01+841+0, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_00+721, 1, q_00+721, 1, temp+1);
	GF2X_MUL(118, temp, 59, p_01+851+1, 59, q_00+841);
	GF2X_MUL(118, temp2, 59, p_11+851+1, 59, q_01+841);
	gf2x_add(118, q_01+721+0, 118, temp, 118, temp2);
	GF2X_MUL(2, temp, 1, q_00+841+58, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+58, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+57, 2, q_01+721+57, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+57, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+57, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+56, 2, q_01+721+56, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+56, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+56, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+55, 2, q_01+721+55, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+55, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+55, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+54, 2, q_01+721+54, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+54, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+54, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+53, 2, q_01+721+53, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+53, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+53, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+52, 2, q_01+721+52, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+52, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+52, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+51, 2, q_01+721+51, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+51, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+51, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+50, 2, q_01+721+50, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+50, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+50, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+49, 2, q_01+721+49, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+49, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+49, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+48, 2, q_01+721+48, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+48, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+48, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+47, 2, q_01+721+47, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+47, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+47, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+46, 2, q_01+721+46, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+46, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+46, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+45, 2, q_01+721+45, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+45, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+45, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+44, 2, q_01+721+44, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+44, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+44, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+43, 2, q_01+721+43, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+43, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+43, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+42, 2, q_01+721+42, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+42, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+42, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+41, 2, q_01+721+41, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+41, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+41, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+40, 2, q_01+721+40, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+40, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+40, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+39, 2, q_01+721+39, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+39, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+39, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+38, 2, q_01+721+38, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+38, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+38, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+37, 2, q_01+721+37, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+37, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+37, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+36, 2, q_01+721+36, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+36, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+36, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+35, 2, q_01+721+35, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+35, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+35, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+34, 2, q_01+721+34, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+34, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+34, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+33, 2, q_01+721+33, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+33, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+33, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+32, 2, q_01+721+32, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+32, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+32, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+31, 2, q_01+721+31, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+31, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+31, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+30, 2, q_01+721+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+30, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+30, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+29, 2, q_01+721+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+29, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+29, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+28, 2, q_01+721+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+28, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+28, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+27, 2, q_01+721+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+27, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+27, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+26, 2, q_01+721+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+26, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+26, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+25, 2, q_01+721+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+25, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+25, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+24, 2, q_01+721+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+24, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+24, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+23, 2, q_01+721+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+23, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+23, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+22, 2, q_01+721+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+22, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+22, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+21, 2, q_01+721+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+21, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+21, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+20, 2, q_01+721+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+20, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+20, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+19, 2, q_01+721+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+19, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+19, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+18, 2, q_01+721+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+18, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+18, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+17, 2, q_01+721+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+17, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+17, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+16, 2, q_01+721+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+16, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+16, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+15, 2, q_01+721+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+15, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+15, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+14, 2, q_01+721+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+14, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+14, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+13, 2, q_01+721+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+13, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+13, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+12, 2, q_01+721+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+12, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+12, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+11, 2, q_01+721+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+11, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+11, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+10, 2, q_01+721+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+10, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+10, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+9, 2, q_01+721+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+9, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+9, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+8, 2, q_01+721+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+8, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+8, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+7, 2, q_01+721+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+7, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+7, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+6, 2, q_01+721+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+6, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+6, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+5, 2, q_01+721+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+5, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+5, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+4, 2, q_01+721+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+4, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+4, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+3, 2, q_01+721+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+3, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+3, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+2, 2, q_01+721+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+2, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+2, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+1, 2, q_01+721+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+1, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+1, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+721+0, 2, q_01+721+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+841+0, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_01+841+0, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_01+721, 1, q_01+721, 1, temp+1);
	GF2X_MUL(118, temp, 59, p_00+851+1, 59, q_10+841);
	GF2X_MUL(118, temp2, 59, p_10+851+1, 59, q_11+841);
	gf2x_add(118, q_10+721+0, 118, temp, 118, temp2);
	GF2X_MUL(2, temp, 1, q_10+841+58, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+58, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+57, 2, q_10+721+57, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+57, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+57, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+56, 2, q_10+721+56, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+56, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+56, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+55, 2, q_10+721+55, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+55, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+55, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+54, 2, q_10+721+54, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+54, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+54, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+53, 2, q_10+721+53, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+53, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+53, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+52, 2, q_10+721+52, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+52, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+52, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+51, 2, q_10+721+51, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+51, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+51, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+50, 2, q_10+721+50, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+50, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+50, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+49, 2, q_10+721+49, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+49, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+49, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+48, 2, q_10+721+48, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+48, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+48, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+47, 2, q_10+721+47, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+47, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+47, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+46, 2, q_10+721+46, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+46, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+46, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+45, 2, q_10+721+45, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+45, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+45, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+44, 2, q_10+721+44, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+44, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+44, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+43, 2, q_10+721+43, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+43, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+43, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+42, 2, q_10+721+42, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+42, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+42, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+41, 2, q_10+721+41, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+41, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+41, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+40, 2, q_10+721+40, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+40, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+40, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+39, 2, q_10+721+39, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+39, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+39, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+38, 2, q_10+721+38, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+38, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+38, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+37, 2, q_10+721+37, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+37, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+37, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+36, 2, q_10+721+36, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+36, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+36, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+35, 2, q_10+721+35, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+35, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+35, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+34, 2, q_10+721+34, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+34, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+34, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+33, 2, q_10+721+33, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+33, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+33, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+32, 2, q_10+721+32, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+32, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+32, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+31, 2, q_10+721+31, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+31, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+31, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+30, 2, q_10+721+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+30, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+30, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+29, 2, q_10+721+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+29, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+29, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+28, 2, q_10+721+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+28, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+28, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+27, 2, q_10+721+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+27, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+27, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+26, 2, q_10+721+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+26, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+26, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+25, 2, q_10+721+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+25, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+25, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+24, 2, q_10+721+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+24, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+24, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+23, 2, q_10+721+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+23, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+23, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+22, 2, q_10+721+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+22, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+22, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+21, 2, q_10+721+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+21, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+21, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+20, 2, q_10+721+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+20, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+20, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+19, 2, q_10+721+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+19, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+19, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+18, 2, q_10+721+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+18, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+18, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+17, 2, q_10+721+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+17, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+17, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+16, 2, q_10+721+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+16, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+16, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+15, 2, q_10+721+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+15, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+15, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+14, 2, q_10+721+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+14, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+14, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+13, 2, q_10+721+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+13, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+13, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+12, 2, q_10+721+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+12, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+12, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+11, 2, q_10+721+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+11, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+11, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+10, 2, q_10+721+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+10, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+10, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+9, 2, q_10+721+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+9, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+9, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+8, 2, q_10+721+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+8, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+8, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+7, 2, q_10+721+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+7, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+7, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+6, 2, q_10+721+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+6, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+6, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+5, 2, q_10+721+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+5, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+5, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+4, 2, q_10+721+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+4, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+4, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+3, 2, q_10+721+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+3, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+3, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+2, 2, q_10+721+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+2, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+2, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+1, 2, q_10+721+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+1, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+1, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+721+0, 2, q_10+721+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+0, 1, p_00+851);
	GF2X_MUL(2, temp2, 1, q_11+841+0, 1, p_10+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_10+721, 1, q_10+721, 1, temp+1);
	GF2X_MUL(118, temp, 59, p_01+851+1, 59, q_10+841);
	GF2X_MUL(118, temp2, 59, p_11+851+1, 59, q_11+841);
	gf2x_add(118, q_11+721+0, 118, temp, 118, temp2);
	GF2X_MUL(2, temp, 1, q_10+841+58, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+58, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+57, 2, q_11+721+57, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+57, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+57, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+56, 2, q_11+721+56, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+56, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+56, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+55, 2, q_11+721+55, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+55, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+55, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+54, 2, q_11+721+54, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+54, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+54, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+53, 2, q_11+721+53, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+53, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+53, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+52, 2, q_11+721+52, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+52, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+52, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+51, 2, q_11+721+51, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+51, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+51, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+50, 2, q_11+721+50, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+50, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+50, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+49, 2, q_11+721+49, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+49, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+49, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+48, 2, q_11+721+48, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+48, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+48, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+47, 2, q_11+721+47, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+47, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+47, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+46, 2, q_11+721+46, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+46, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+46, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+45, 2, q_11+721+45, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+45, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+45, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+44, 2, q_11+721+44, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+44, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+44, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+43, 2, q_11+721+43, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+43, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+43, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+42, 2, q_11+721+42, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+42, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+42, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+41, 2, q_11+721+41, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+41, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+41, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+40, 2, q_11+721+40, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+40, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+40, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+39, 2, q_11+721+39, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+39, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+39, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+38, 2, q_11+721+38, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+38, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+38, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+37, 2, q_11+721+37, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+37, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+37, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+36, 2, q_11+721+36, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+36, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+36, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+35, 2, q_11+721+35, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+35, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+35, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+34, 2, q_11+721+34, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+34, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+34, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+33, 2, q_11+721+33, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+33, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+33, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+32, 2, q_11+721+32, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+32, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+32, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+31, 2, q_11+721+31, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+31, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+31, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+30, 2, q_11+721+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+30, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+30, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+29, 2, q_11+721+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+29, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+29, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+28, 2, q_11+721+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+28, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+28, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+27, 2, q_11+721+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+27, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+27, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+26, 2, q_11+721+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+26, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+26, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+25, 2, q_11+721+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+25, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+25, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+24, 2, q_11+721+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+24, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+24, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+23, 2, q_11+721+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+23, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+23, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+22, 2, q_11+721+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+22, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+22, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+21, 2, q_11+721+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+21, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+21, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+20, 2, q_11+721+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+20, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+20, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+19, 2, q_11+721+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+19, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+19, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+18, 2, q_11+721+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+18, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+18, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+17, 2, q_11+721+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+17, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+17, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+16, 2, q_11+721+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+16, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+16, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+15, 2, q_11+721+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+15, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+15, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+14, 2, q_11+721+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+14, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+14, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+13, 2, q_11+721+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+13, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+13, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+12, 2, q_11+721+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+12, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+12, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+11, 2, q_11+721+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+11, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+11, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+10, 2, q_11+721+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+10, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+10, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+9, 2, q_11+721+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+9, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+9, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+8, 2, q_11+721+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+8, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+8, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+7, 2, q_11+721+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+7, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+7, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+6, 2, q_11+721+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+6, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+6, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+5, 2, q_11+721+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+5, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+5, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+4, 2, q_11+721+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+4, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+4, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+3, 2, q_11+721+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+3, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+3, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+2, 2, q_11+721+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+2, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+2, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+1, 2, q_11+721+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+1, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+1, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+721+0, 2, q_11+721+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+841+0, 1, p_01+851);
	GF2X_MUL(2, temp2, 1, q_11+841+0, 1, p_11+851);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_11+721, 1, q_11+721, 1, temp+1);
	

	// Recombining results: n: 15195, depth: 2
	memset(q_00+481, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(236, temp, 118, p_00+727+2, 118, q_00+721);
	GF2X_MUL(236, temp2, 118, p_10+727+2, 118, q_01+721);
	gf2x_add(236, q_00+481+2, 236, temp, 236, temp2);
	GF2X_MUL(4, temp, 2, q_00+721+116, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+116, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+116, 4, q_00+481+116, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+114, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+114, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+114, 4, q_00+481+114, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+112, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+112, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+112, 4, q_00+481+112, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+110, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+110, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+110, 4, q_00+481+110, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+108, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+108, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+108, 4, q_00+481+108, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+106, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+106, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+106, 4, q_00+481+106, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+104, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+104, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+104, 4, q_00+481+104, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+102, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+102, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+102, 4, q_00+481+102, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+100, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+100, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+100, 4, q_00+481+100, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+98, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+98, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+98, 4, q_00+481+98, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+96, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+96, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+96, 4, q_00+481+96, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+94, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+94, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+94, 4, q_00+481+94, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+92, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+92, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+92, 4, q_00+481+92, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+90, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+90, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+90, 4, q_00+481+90, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+88, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+88, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+88, 4, q_00+481+88, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+86, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+86, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+86, 4, q_00+481+86, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+84, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+84, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+84, 4, q_00+481+84, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+82, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+82, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+82, 4, q_00+481+82, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+80, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+80, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+80, 4, q_00+481+80, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+78, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+78, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+78, 4, q_00+481+78, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+76, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+76, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+76, 4, q_00+481+76, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+74, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+74, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+74, 4, q_00+481+74, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+72, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+72, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+72, 4, q_00+481+72, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+70, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+70, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+70, 4, q_00+481+70, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+68, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+68, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+68, 4, q_00+481+68, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+66, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+66, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+66, 4, q_00+481+66, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+64, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+64, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+64, 4, q_00+481+64, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+62, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+62, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+62, 4, q_00+481+62, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+60, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+60, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+60, 4, q_00+481+60, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+58, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+58, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+58, 4, q_00+481+58, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+56, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+56, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+56, 4, q_00+481+56, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+54, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+54, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+54, 4, q_00+481+54, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+52, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+52, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+52, 4, q_00+481+52, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+50, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+50, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+50, 4, q_00+481+50, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+48, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+48, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+48, 4, q_00+481+48, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+46, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+46, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+46, 4, q_00+481+46, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+44, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+44, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+44, 4, q_00+481+44, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+42, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+42, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+42, 4, q_00+481+42, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+40, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+40, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+40, 4, q_00+481+40, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+38, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+38, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+38, 4, q_00+481+38, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+36, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+36, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+36, 4, q_00+481+36, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+34, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+34, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+34, 4, q_00+481+34, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+32, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+32, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+32, 4, q_00+481+32, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+30, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+30, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+30, 4, q_00+481+30, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+28, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+28, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+28, 4, q_00+481+28, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+26, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+26, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+26, 4, q_00+481+26, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+24, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+24, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+24, 4, q_00+481+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+22, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+22, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+22, 4, q_00+481+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+20, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+20, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+20, 4, q_00+481+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+18, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+18, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+18, 4, q_00+481+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+16, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+16, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+16, 4, q_00+481+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+14, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+14, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+14, 4, q_00+481+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+12, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+12, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+12, 4, q_00+481+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+10, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+10, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+10, 4, q_00+481+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+8, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+8, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+8, 4, q_00+481+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+6, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+6, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+6, 4, q_00+481+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+4, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+4, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+4, 4, q_00+481+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+2, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+2, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+2, 4, q_00+481+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+0, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+721+0, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+481+0, 4, q_00+481+0, 4, temp);
	memset(q_01+481, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(236, temp, 118, p_01+727+2, 118, q_00+721);
	GF2X_MUL(236, temp2, 118, p_11+727+2, 118, q_01+721);
	gf2x_add(236, q_01+481+2, 236, temp, 236, temp2);
	GF2X_MUL(4, temp, 2, q_00+721+116, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+116, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+116, 4, q_01+481+116, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+114, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+114, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+114, 4, q_01+481+114, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+112, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+112, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+112, 4, q_01+481+112, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+110, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+110, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+110, 4, q_01+481+110, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+108, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+108, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+108, 4, q_01+481+108, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+106, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+106, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+106, 4, q_01+481+106, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+104, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+104, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+104, 4, q_01+481+104, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+102, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+102, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+102, 4, q_01+481+102, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+100, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+100, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+100, 4, q_01+481+100, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+98, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+98, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+98, 4, q_01+481+98, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+96, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+96, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+96, 4, q_01+481+96, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+94, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+94, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+94, 4, q_01+481+94, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+92, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+92, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+92, 4, q_01+481+92, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+90, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+90, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+90, 4, q_01+481+90, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+88, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+88, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+88, 4, q_01+481+88, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+86, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+86, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+86, 4, q_01+481+86, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+84, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+84, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+84, 4, q_01+481+84, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+82, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+82, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+82, 4, q_01+481+82, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+80, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+80, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+80, 4, q_01+481+80, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+78, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+78, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+78, 4, q_01+481+78, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+76, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+76, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+76, 4, q_01+481+76, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+74, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+74, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+74, 4, q_01+481+74, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+72, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+72, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+72, 4, q_01+481+72, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+70, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+70, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+70, 4, q_01+481+70, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+68, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+68, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+68, 4, q_01+481+68, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+66, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+66, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+66, 4, q_01+481+66, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+64, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+64, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+64, 4, q_01+481+64, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+62, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+62, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+62, 4, q_01+481+62, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+60, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+60, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+60, 4, q_01+481+60, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+58, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+58, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+58, 4, q_01+481+58, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+56, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+56, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+56, 4, q_01+481+56, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+54, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+54, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+54, 4, q_01+481+54, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+52, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+52, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+52, 4, q_01+481+52, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+50, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+50, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+50, 4, q_01+481+50, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+48, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+48, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+48, 4, q_01+481+48, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+46, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+46, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+46, 4, q_01+481+46, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+44, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+44, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+44, 4, q_01+481+44, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+42, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+42, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+42, 4, q_01+481+42, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+40, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+40, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+40, 4, q_01+481+40, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+38, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+38, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+38, 4, q_01+481+38, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+36, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+36, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+36, 4, q_01+481+36, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+34, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+34, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+34, 4, q_01+481+34, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+32, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+32, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+32, 4, q_01+481+32, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+30, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+30, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+30, 4, q_01+481+30, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+28, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+28, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+28, 4, q_01+481+28, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+26, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+26, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+26, 4, q_01+481+26, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+24, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+24, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+24, 4, q_01+481+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+22, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+22, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+22, 4, q_01+481+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+20, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+20, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+20, 4, q_01+481+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+18, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+18, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+18, 4, q_01+481+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+16, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+16, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+16, 4, q_01+481+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+14, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+14, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+14, 4, q_01+481+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+12, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+12, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+12, 4, q_01+481+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+10, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+10, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+10, 4, q_01+481+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+8, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+8, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+8, 4, q_01+481+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+6, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+6, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+6, 4, q_01+481+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+4, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+4, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+4, 4, q_01+481+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+2, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+2, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+2, 4, q_01+481+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+721+0, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+721+0, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+481+0, 4, q_01+481+0, 4, temp);
	memset(q_10+481, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(236, temp, 118, p_00+727+2, 118, q_10+721);
	GF2X_MUL(236, temp2, 118, p_10+727+2, 118, q_11+721);
	gf2x_add(236, q_10+481+2, 236, temp, 236, temp2);
	GF2X_MUL(4, temp, 2, q_10+721+116, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+116, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+116, 4, q_10+481+116, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+114, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+114, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+114, 4, q_10+481+114, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+112, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+112, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+112, 4, q_10+481+112, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+110, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+110, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+110, 4, q_10+481+110, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+108, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+108, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+108, 4, q_10+481+108, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+106, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+106, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+106, 4, q_10+481+106, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+104, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+104, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+104, 4, q_10+481+104, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+102, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+102, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+102, 4, q_10+481+102, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+100, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+100, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+100, 4, q_10+481+100, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+98, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+98, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+98, 4, q_10+481+98, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+96, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+96, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+96, 4, q_10+481+96, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+94, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+94, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+94, 4, q_10+481+94, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+92, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+92, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+92, 4, q_10+481+92, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+90, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+90, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+90, 4, q_10+481+90, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+88, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+88, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+88, 4, q_10+481+88, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+86, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+86, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+86, 4, q_10+481+86, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+84, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+84, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+84, 4, q_10+481+84, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+82, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+82, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+82, 4, q_10+481+82, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+80, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+80, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+80, 4, q_10+481+80, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+78, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+78, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+78, 4, q_10+481+78, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+76, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+76, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+76, 4, q_10+481+76, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+74, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+74, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+74, 4, q_10+481+74, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+72, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+72, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+72, 4, q_10+481+72, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+70, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+70, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+70, 4, q_10+481+70, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+68, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+68, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+68, 4, q_10+481+68, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+66, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+66, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+66, 4, q_10+481+66, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+64, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+64, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+64, 4, q_10+481+64, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+62, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+62, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+62, 4, q_10+481+62, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+60, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+60, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+60, 4, q_10+481+60, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+58, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+58, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+58, 4, q_10+481+58, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+56, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+56, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+56, 4, q_10+481+56, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+54, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+54, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+54, 4, q_10+481+54, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+52, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+52, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+52, 4, q_10+481+52, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+50, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+50, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+50, 4, q_10+481+50, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+48, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+48, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+48, 4, q_10+481+48, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+46, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+46, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+46, 4, q_10+481+46, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+44, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+44, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+44, 4, q_10+481+44, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+42, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+42, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+42, 4, q_10+481+42, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+40, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+40, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+40, 4, q_10+481+40, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+38, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+38, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+38, 4, q_10+481+38, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+36, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+36, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+36, 4, q_10+481+36, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+34, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+34, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+34, 4, q_10+481+34, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+32, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+32, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+32, 4, q_10+481+32, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+30, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+30, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+30, 4, q_10+481+30, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+28, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+28, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+28, 4, q_10+481+28, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+26, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+26, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+26, 4, q_10+481+26, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+24, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+24, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+24, 4, q_10+481+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+22, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+22, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+22, 4, q_10+481+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+20, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+20, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+20, 4, q_10+481+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+18, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+18, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+18, 4, q_10+481+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+16, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+16, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+16, 4, q_10+481+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+14, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+14, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+14, 4, q_10+481+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+12, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+12, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+12, 4, q_10+481+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+10, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+10, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+10, 4, q_10+481+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+8, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+8, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+8, 4, q_10+481+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+6, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+6, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+6, 4, q_10+481+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+4, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+4, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+4, 4, q_10+481+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+2, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+2, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+2, 4, q_10+481+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+0, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+721+0, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+481+0, 4, q_10+481+0, 4, temp);
	memset(q_11+481, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(236, temp, 118, p_01+727+2, 118, q_10+721);
	GF2X_MUL(236, temp2, 118, p_11+727+2, 118, q_11+721);
	gf2x_add(236, q_11+481+2, 236, temp, 236, temp2);
	GF2X_MUL(4, temp, 2, q_10+721+116, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+116, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+116, 4, q_11+481+116, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+114, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+114, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+114, 4, q_11+481+114, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+112, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+112, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+112, 4, q_11+481+112, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+110, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+110, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+110, 4, q_11+481+110, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+108, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+108, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+108, 4, q_11+481+108, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+106, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+106, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+106, 4, q_11+481+106, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+104, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+104, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+104, 4, q_11+481+104, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+102, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+102, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+102, 4, q_11+481+102, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+100, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+100, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+100, 4, q_11+481+100, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+98, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+98, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+98, 4, q_11+481+98, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+96, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+96, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+96, 4, q_11+481+96, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+94, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+94, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+94, 4, q_11+481+94, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+92, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+92, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+92, 4, q_11+481+92, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+90, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+90, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+90, 4, q_11+481+90, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+88, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+88, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+88, 4, q_11+481+88, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+86, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+86, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+86, 4, q_11+481+86, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+84, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+84, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+84, 4, q_11+481+84, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+82, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+82, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+82, 4, q_11+481+82, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+80, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+80, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+80, 4, q_11+481+80, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+78, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+78, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+78, 4, q_11+481+78, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+76, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+76, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+76, 4, q_11+481+76, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+74, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+74, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+74, 4, q_11+481+74, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+72, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+72, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+72, 4, q_11+481+72, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+70, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+70, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+70, 4, q_11+481+70, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+68, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+68, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+68, 4, q_11+481+68, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+66, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+66, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+66, 4, q_11+481+66, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+64, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+64, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+64, 4, q_11+481+64, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+62, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+62, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+62, 4, q_11+481+62, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+60, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+60, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+60, 4, q_11+481+60, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+58, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+58, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+58, 4, q_11+481+58, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+56, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+56, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+56, 4, q_11+481+56, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+54, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+54, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+54, 4, q_11+481+54, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+52, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+52, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+52, 4, q_11+481+52, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+50, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+50, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+50, 4, q_11+481+50, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+48, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+48, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+48, 4, q_11+481+48, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+46, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+46, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+46, 4, q_11+481+46, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+44, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+44, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+44, 4, q_11+481+44, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+42, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+42, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+42, 4, q_11+481+42, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+40, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+40, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+40, 4, q_11+481+40, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+38, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+38, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+38, 4, q_11+481+38, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+36, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+36, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+36, 4, q_11+481+36, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+34, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+34, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+34, 4, q_11+481+34, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+32, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+32, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+32, 4, q_11+481+32, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+30, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+30, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+30, 4, q_11+481+30, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+28, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+28, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+28, 4, q_11+481+28, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+26, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+26, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+26, 4, q_11+481+26, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+24, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+24, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+24, 4, q_11+481+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+22, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+22, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+22, 4, q_11+481+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+20, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+20, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+20, 4, q_11+481+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+18, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+18, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+18, 4, q_11+481+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+16, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+16, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+16, 4, q_11+481+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+14, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+14, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+14, 4, q_11+481+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+12, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+12, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+12, 4, q_11+481+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+10, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+10, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+10, 4, q_11+481+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+8, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+8, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+8, 4, q_11+481+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+6, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+6, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+6, 4, q_11+481+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+4, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+4, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+4, 4, q_11+481+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+2, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+2, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+2, 4, q_11+481+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+721+0, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+721+0, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+481+0, 4, q_11+481+0, 4, temp);
	

	// Recombining results: n: 30750, depth: 1
	memset(q_00+0, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(476, temp, 238, p_00+483+6, 238, q_00+481);
	GF2X_MUL(476, temp2, 238, p_10+483+6, 238, q_01+481);
	gf2x_add(476, q_00+0+5, 476, temp, 476, temp2);
	GF2X_MUL(12, temp, 6, q_00+481+232, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+232, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+231, 12, q_00+0+231, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+226, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+226, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+225, 12, q_00+0+225, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+220, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+220, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+219, 12, q_00+0+219, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+214, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+214, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+213, 12, q_00+0+213, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+208, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+208, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+207, 12, q_00+0+207, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+202, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+202, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+201, 12, q_00+0+201, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+196, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+196, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+195, 12, q_00+0+195, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+190, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+190, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+189, 12, q_00+0+189, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+184, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+184, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+183, 12, q_00+0+183, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+178, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+178, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+177, 12, q_00+0+177, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+172, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+172, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+171, 12, q_00+0+171, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+166, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+166, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+165, 12, q_00+0+165, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+160, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+160, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+159, 12, q_00+0+159, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+154, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+154, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+153, 12, q_00+0+153, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+148, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+148, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+147, 12, q_00+0+147, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+142, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+142, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+141, 12, q_00+0+141, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+136, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+136, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+135, 12, q_00+0+135, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+130, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+130, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+129, 12, q_00+0+129, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+124, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+124, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+123, 12, q_00+0+123, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+118, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+118, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+117, 12, q_00+0+117, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+112, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+112, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+111, 12, q_00+0+111, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+106, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+106, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+105, 12, q_00+0+105, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+100, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+100, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+99, 12, q_00+0+99, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+94, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+94, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+93, 12, q_00+0+93, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+88, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+88, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+87, 12, q_00+0+87, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+82, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+82, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+81, 12, q_00+0+81, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+76, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+76, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+75, 12, q_00+0+75, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+70, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+70, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+69, 12, q_00+0+69, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+64, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+64, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+63, 12, q_00+0+63, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+58, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+58, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+57, 12, q_00+0+57, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+52, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+52, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+51, 12, q_00+0+51, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+46, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+46, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+45, 12, q_00+0+45, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+40, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+40, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+39, 12, q_00+0+39, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+34, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+34, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+33, 12, q_00+0+33, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+28, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+28, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+27, 12, q_00+0+27, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+22, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+22, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+21, 12, q_00+0+21, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+16, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+16, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+15, 12, q_00+0+15, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+10, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+10, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+9, 12, q_00+0+9, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+4, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_01+481+4, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+3, 12, q_00+0+3, 12, temp);
	GF2X_MUL(8, temp, 4, p_00+483+2, 4, q_00+481);
	GF2X_MUL(8, temp2, 4, p_10+483+2, 4, q_01+481);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+0+1, 8, q_00+0+1, 8, temp);
	GF2X_MUL(4, temp, 2, q_00+481+2, 2, p_00+483);
	GF2X_MUL(4, temp2, 2, q_01+481+2, 2, p_10+483);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+1, 4, q_00+0+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+481+0, 2, p_00+483);
	GF2X_MUL(4, temp2, 2, q_01+481+0, 2, p_10+483);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_00+0, 3, q_00+0, 3, temp+1);
	memset(q_01+0, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(476, temp, 238, p_01+483+6, 238, q_00+481);
	GF2X_MUL(476, temp2, 238, p_11+483+6, 238, q_01+481);
	gf2x_add(476, q_01+0+5, 476, temp, 476, temp2);
	GF2X_MUL(12, temp, 6, q_00+481+232, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+232, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+231, 12, q_01+0+231, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+226, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+226, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+225, 12, q_01+0+225, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+220, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+220, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+219, 12, q_01+0+219, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+214, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+214, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+213, 12, q_01+0+213, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+208, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+208, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+207, 12, q_01+0+207, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+202, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+202, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+201, 12, q_01+0+201, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+196, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+196, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+195, 12, q_01+0+195, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+190, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+190, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+189, 12, q_01+0+189, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+184, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+184, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+183, 12, q_01+0+183, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+178, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+178, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+177, 12, q_01+0+177, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+172, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+172, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+171, 12, q_01+0+171, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+166, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+166, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+165, 12, q_01+0+165, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+160, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+160, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+159, 12, q_01+0+159, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+154, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+154, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+153, 12, q_01+0+153, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+148, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+148, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+147, 12, q_01+0+147, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+142, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+142, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+141, 12, q_01+0+141, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+136, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+136, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+135, 12, q_01+0+135, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+130, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+130, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+129, 12, q_01+0+129, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+124, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+124, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+123, 12, q_01+0+123, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+118, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+118, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+117, 12, q_01+0+117, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+112, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+112, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+111, 12, q_01+0+111, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+106, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+106, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+105, 12, q_01+0+105, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+100, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+100, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+99, 12, q_01+0+99, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+94, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+94, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+93, 12, q_01+0+93, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+88, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+88, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+87, 12, q_01+0+87, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+82, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+82, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+81, 12, q_01+0+81, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+76, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+76, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+75, 12, q_01+0+75, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+70, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+70, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+69, 12, q_01+0+69, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+64, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+64, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+63, 12, q_01+0+63, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+58, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+58, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+57, 12, q_01+0+57, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+52, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+52, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+51, 12, q_01+0+51, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+46, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+46, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+45, 12, q_01+0+45, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+40, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+40, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+39, 12, q_01+0+39, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+34, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+34, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+33, 12, q_01+0+33, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+28, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+28, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+27, 12, q_01+0+27, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+22, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+22, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+21, 12, q_01+0+21, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+16, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+16, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+15, 12, q_01+0+15, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+10, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+10, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+9, 12, q_01+0+9, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+481+4, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_01+481+4, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+3, 12, q_01+0+3, 12, temp);
	GF2X_MUL(8, temp, 4, p_01+483+2, 4, q_00+481);
	GF2X_MUL(8, temp2, 4, p_11+483+2, 4, q_01+481);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+0+1, 8, q_01+0+1, 8, temp);
	GF2X_MUL(4, temp, 2, q_00+481+2, 2, p_01+483);
	GF2X_MUL(4, temp2, 2, q_01+481+2, 2, p_11+483);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+1, 4, q_01+0+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+481+0, 2, p_01+483);
	GF2X_MUL(4, temp2, 2, q_01+481+0, 2, p_11+483);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_01+0, 3, q_01+0, 3, temp+1);
	memset(q_10+0, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(476, temp, 238, p_00+483+6, 238, q_10+481);
	GF2X_MUL(476, temp2, 238, p_10+483+6, 238, q_11+481);
	gf2x_add(476, q_10+0+5, 476, temp, 476, temp2);
	GF2X_MUL(12, temp, 6, q_10+481+232, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+232, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+231, 12, q_10+0+231, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+226, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+226, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+225, 12, q_10+0+225, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+220, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+220, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+219, 12, q_10+0+219, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+214, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+214, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+213, 12, q_10+0+213, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+208, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+208, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+207, 12, q_10+0+207, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+202, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+202, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+201, 12, q_10+0+201, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+196, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+196, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+195, 12, q_10+0+195, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+190, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+190, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+189, 12, q_10+0+189, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+184, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+184, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+183, 12, q_10+0+183, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+178, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+178, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+177, 12, q_10+0+177, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+172, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+172, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+171, 12, q_10+0+171, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+166, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+166, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+165, 12, q_10+0+165, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+160, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+160, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+159, 12, q_10+0+159, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+154, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+154, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+153, 12, q_10+0+153, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+148, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+148, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+147, 12, q_10+0+147, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+142, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+142, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+141, 12, q_10+0+141, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+136, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+136, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+135, 12, q_10+0+135, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+130, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+130, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+129, 12, q_10+0+129, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+124, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+124, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+123, 12, q_10+0+123, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+118, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+118, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+117, 12, q_10+0+117, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+112, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+112, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+111, 12, q_10+0+111, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+106, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+106, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+105, 12, q_10+0+105, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+100, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+100, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+99, 12, q_10+0+99, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+94, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+94, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+93, 12, q_10+0+93, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+88, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+88, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+87, 12, q_10+0+87, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+82, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+82, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+81, 12, q_10+0+81, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+76, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+76, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+75, 12, q_10+0+75, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+70, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+70, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+69, 12, q_10+0+69, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+64, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+64, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+63, 12, q_10+0+63, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+58, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+58, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+57, 12, q_10+0+57, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+52, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+52, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+51, 12, q_10+0+51, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+46, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+46, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+45, 12, q_10+0+45, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+40, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+40, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+39, 12, q_10+0+39, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+34, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+34, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+33, 12, q_10+0+33, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+28, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+28, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+27, 12, q_10+0+27, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+22, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+22, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+21, 12, q_10+0+21, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+16, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+16, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+15, 12, q_10+0+15, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+10, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+10, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+9, 12, q_10+0+9, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+4, 6, p_00+483);
	GF2X_MUL(12, temp2, 6, q_11+481+4, 6, p_10+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+3, 12, q_10+0+3, 12, temp);
	GF2X_MUL(8, temp, 4, p_00+483+2, 4, q_10+481);
	GF2X_MUL(8, temp2, 4, p_10+483+2, 4, q_11+481);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+0+1, 8, q_10+0+1, 8, temp);
	GF2X_MUL(4, temp, 2, q_10+481+2, 2, p_00+483);
	GF2X_MUL(4, temp2, 2, q_11+481+2, 2, p_10+483);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+1, 4, q_10+0+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+481+0, 2, p_00+483);
	GF2X_MUL(4, temp2, 2, q_11+481+0, 2, p_10+483);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_10+0, 3, q_10+0, 3, temp+1);
	memset(q_11+0, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(476, temp, 238, p_01+483+6, 238, q_10+481);
	GF2X_MUL(476, temp2, 238, p_11+483+6, 238, q_11+481);
	gf2x_add(476, q_11+0+5, 476, temp, 476, temp2);
	GF2X_MUL(12, temp, 6, q_10+481+232, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+232, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+231, 12, q_11+0+231, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+226, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+226, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+225, 12, q_11+0+225, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+220, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+220, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+219, 12, q_11+0+219, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+214, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+214, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+213, 12, q_11+0+213, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+208, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+208, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+207, 12, q_11+0+207, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+202, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+202, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+201, 12, q_11+0+201, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+196, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+196, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+195, 12, q_11+0+195, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+190, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+190, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+189, 12, q_11+0+189, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+184, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+184, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+183, 12, q_11+0+183, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+178, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+178, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+177, 12, q_11+0+177, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+172, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+172, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+171, 12, q_11+0+171, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+166, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+166, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+165, 12, q_11+0+165, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+160, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+160, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+159, 12, q_11+0+159, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+154, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+154, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+153, 12, q_11+0+153, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+148, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+148, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+147, 12, q_11+0+147, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+142, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+142, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+141, 12, q_11+0+141, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+136, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+136, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+135, 12, q_11+0+135, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+130, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+130, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+129, 12, q_11+0+129, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+124, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+124, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+123, 12, q_11+0+123, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+118, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+118, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+117, 12, q_11+0+117, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+112, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+112, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+111, 12, q_11+0+111, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+106, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+106, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+105, 12, q_11+0+105, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+100, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+100, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+99, 12, q_11+0+99, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+94, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+94, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+93, 12, q_11+0+93, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+88, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+88, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+87, 12, q_11+0+87, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+82, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+82, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+81, 12, q_11+0+81, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+76, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+76, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+75, 12, q_11+0+75, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+70, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+70, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+69, 12, q_11+0+69, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+64, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+64, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+63, 12, q_11+0+63, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+58, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+58, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+57, 12, q_11+0+57, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+52, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+52, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+51, 12, q_11+0+51, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+46, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+46, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+45, 12, q_11+0+45, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+40, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+40, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+39, 12, q_11+0+39, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+34, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+34, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+33, 12, q_11+0+33, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+28, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+28, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+27, 12, q_11+0+27, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+22, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+22, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+21, 12, q_11+0+21, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+16, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+16, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+15, 12, q_11+0+15, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+10, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+10, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+9, 12, q_11+0+9, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+481+4, 6, p_01+483);
	GF2X_MUL(12, temp2, 6, q_11+481+4, 6, p_11+483);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+3, 12, q_11+0+3, 12, temp);
	GF2X_MUL(8, temp, 4, p_01+483+2, 4, q_10+481);
	GF2X_MUL(8, temp2, 4, p_11+483+2, 4, q_11+481);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+0+1, 8, q_11+0+1, 8, temp);
	GF2X_MUL(4, temp, 2, q_10+481+2, 2, p_01+483);
	GF2X_MUL(4, temp2, 2, q_11+481+2, 2, p_11+483);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+1, 4, q_11+0+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+481+0, 2, p_01+483);
	GF2X_MUL(4, temp2, 2, q_11+481+0, 2, p_11+483);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_11+0, 3, q_11+0, 3, temp+1);
	

	// Recombining results: n: 61605, depth: 0
	memset(t_00+0, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(962, temp, 481, p_00+0+2, 481, q_00+0);
	GF2X_MUL(962, temp2, 481, p_10+0+2, 481, q_01+0);
	gf2x_add(962, t_00+0+1, 962, temp, 962, temp2);
	GF2X_MUL(4, temp, 2, q_00+0+479, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+479, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+478, 4, t_00+0+478, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+477, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+477, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+476, 4, t_00+0+476, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+475, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+475, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+474, 4, t_00+0+474, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+473, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+473, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+472, 4, t_00+0+472, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+471, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+471, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+470, 4, t_00+0+470, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+469, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+469, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+468, 4, t_00+0+468, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+467, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+467, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+466, 4, t_00+0+466, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+465, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+465, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+464, 4, t_00+0+464, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+463, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+463, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+462, 4, t_00+0+462, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+461, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+461, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+460, 4, t_00+0+460, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+459, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+459, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+458, 4, t_00+0+458, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+457, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+457, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+456, 4, t_00+0+456, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+455, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+455, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+454, 4, t_00+0+454, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+453, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+453, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+452, 4, t_00+0+452, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+451, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+451, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+450, 4, t_00+0+450, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+449, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+449, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+448, 4, t_00+0+448, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+447, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+447, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+446, 4, t_00+0+446, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+445, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+445, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+444, 4, t_00+0+444, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+443, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+443, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+442, 4, t_00+0+442, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+441, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+441, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+440, 4, t_00+0+440, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+439, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+439, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+438, 4, t_00+0+438, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+437, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+437, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+436, 4, t_00+0+436, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+435, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+435, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+434, 4, t_00+0+434, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+433, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+433, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+432, 4, t_00+0+432, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+431, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+431, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+430, 4, t_00+0+430, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+429, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+429, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+428, 4, t_00+0+428, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+427, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+427, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+426, 4, t_00+0+426, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+425, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+425, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+424, 4, t_00+0+424, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+423, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+423, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+422, 4, t_00+0+422, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+421, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+421, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+420, 4, t_00+0+420, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+419, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+419, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+418, 4, t_00+0+418, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+417, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+417, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+416, 4, t_00+0+416, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+415, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+415, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+414, 4, t_00+0+414, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+413, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+413, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+412, 4, t_00+0+412, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+411, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+411, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+410, 4, t_00+0+410, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+409, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+409, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+408, 4, t_00+0+408, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+407, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+407, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+406, 4, t_00+0+406, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+405, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+405, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+404, 4, t_00+0+404, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+403, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+403, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+402, 4, t_00+0+402, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+401, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+401, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+400, 4, t_00+0+400, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+399, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+399, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+398, 4, t_00+0+398, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+397, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+397, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+396, 4, t_00+0+396, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+395, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+395, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+394, 4, t_00+0+394, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+393, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+393, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+392, 4, t_00+0+392, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+391, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+391, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+390, 4, t_00+0+390, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+389, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+389, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+388, 4, t_00+0+388, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+387, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+387, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+386, 4, t_00+0+386, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+385, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+385, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+384, 4, t_00+0+384, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+383, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+383, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+382, 4, t_00+0+382, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+381, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+381, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+380, 4, t_00+0+380, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+379, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+379, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+378, 4, t_00+0+378, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+377, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+377, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+376, 4, t_00+0+376, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+375, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+375, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+374, 4, t_00+0+374, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+373, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+373, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+372, 4, t_00+0+372, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+371, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+371, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+370, 4, t_00+0+370, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+369, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+369, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+368, 4, t_00+0+368, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+367, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+367, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+366, 4, t_00+0+366, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+365, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+365, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+364, 4, t_00+0+364, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+363, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+363, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+362, 4, t_00+0+362, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+361, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+361, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+360, 4, t_00+0+360, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+359, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+359, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+358, 4, t_00+0+358, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+357, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+357, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+356, 4, t_00+0+356, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+355, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+355, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+354, 4, t_00+0+354, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+353, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+353, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+352, 4, t_00+0+352, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+351, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+351, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+350, 4, t_00+0+350, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+349, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+349, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+348, 4, t_00+0+348, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+347, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+347, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+346, 4, t_00+0+346, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+345, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+345, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+344, 4, t_00+0+344, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+343, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+343, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+342, 4, t_00+0+342, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+341, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+341, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+340, 4, t_00+0+340, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+339, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+339, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+338, 4, t_00+0+338, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+337, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+337, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+336, 4, t_00+0+336, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+335, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+335, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+334, 4, t_00+0+334, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+333, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+333, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+332, 4, t_00+0+332, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+331, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+331, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+330, 4, t_00+0+330, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+329, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+329, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+328, 4, t_00+0+328, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+327, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+327, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+326, 4, t_00+0+326, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+325, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+325, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+324, 4, t_00+0+324, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+323, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+323, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+322, 4, t_00+0+322, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+321, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+321, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+320, 4, t_00+0+320, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+319, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+319, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+318, 4, t_00+0+318, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+317, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+317, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+316, 4, t_00+0+316, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+315, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+315, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+314, 4, t_00+0+314, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+313, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+313, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+312, 4, t_00+0+312, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+311, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+311, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+310, 4, t_00+0+310, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+309, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+309, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+308, 4, t_00+0+308, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+307, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+307, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+306, 4, t_00+0+306, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+305, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+305, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+304, 4, t_00+0+304, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+303, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+303, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+302, 4, t_00+0+302, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+301, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+301, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+300, 4, t_00+0+300, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+299, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+299, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+298, 4, t_00+0+298, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+297, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+297, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+296, 4, t_00+0+296, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+295, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+295, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+294, 4, t_00+0+294, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+293, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+293, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+292, 4, t_00+0+292, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+291, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+291, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+290, 4, t_00+0+290, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+289, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+289, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+288, 4, t_00+0+288, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+287, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+287, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+286, 4, t_00+0+286, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+285, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+285, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+284, 4, t_00+0+284, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+283, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+283, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+282, 4, t_00+0+282, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+281, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+281, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+280, 4, t_00+0+280, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+279, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+279, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+278, 4, t_00+0+278, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+277, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+277, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+276, 4, t_00+0+276, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+275, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+275, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+274, 4, t_00+0+274, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+273, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+273, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+272, 4, t_00+0+272, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+271, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+271, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+270, 4, t_00+0+270, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+269, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+269, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+268, 4, t_00+0+268, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+267, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+267, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+266, 4, t_00+0+266, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+265, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+265, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+264, 4, t_00+0+264, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+263, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+263, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+262, 4, t_00+0+262, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+261, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+261, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+260, 4, t_00+0+260, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+259, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+259, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+258, 4, t_00+0+258, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+257, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+257, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+256, 4, t_00+0+256, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+255, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+255, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+254, 4, t_00+0+254, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+253, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+253, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+252, 4, t_00+0+252, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+251, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+251, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+250, 4, t_00+0+250, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+249, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+249, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+248, 4, t_00+0+248, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+247, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+247, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+246, 4, t_00+0+246, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+245, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+245, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+244, 4, t_00+0+244, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+243, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+243, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+242, 4, t_00+0+242, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+241, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+241, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+240, 4, t_00+0+240, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+239, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+239, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+238, 4, t_00+0+238, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+237, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+237, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+236, 4, t_00+0+236, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+235, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+235, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+234, 4, t_00+0+234, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+233, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+233, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+232, 4, t_00+0+232, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+231, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+231, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+230, 4, t_00+0+230, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+229, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+229, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+228, 4, t_00+0+228, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+227, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+227, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+226, 4, t_00+0+226, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+225, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+225, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+224, 4, t_00+0+224, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+223, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+223, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+222, 4, t_00+0+222, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+221, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+221, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+220, 4, t_00+0+220, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+219, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+219, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+218, 4, t_00+0+218, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+217, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+217, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+216, 4, t_00+0+216, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+215, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+215, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+214, 4, t_00+0+214, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+213, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+213, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+212, 4, t_00+0+212, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+211, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+211, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+210, 4, t_00+0+210, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+209, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+209, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+208, 4, t_00+0+208, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+207, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+207, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+206, 4, t_00+0+206, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+205, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+205, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+204, 4, t_00+0+204, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+203, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+203, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+202, 4, t_00+0+202, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+201, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+201, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+200, 4, t_00+0+200, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+199, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+199, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+198, 4, t_00+0+198, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+197, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+197, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+196, 4, t_00+0+196, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+195, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+195, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+194, 4, t_00+0+194, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+193, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+193, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+192, 4, t_00+0+192, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+191, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+191, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+190, 4, t_00+0+190, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+189, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+189, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+188, 4, t_00+0+188, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+187, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+187, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+186, 4, t_00+0+186, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+185, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+185, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+184, 4, t_00+0+184, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+183, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+183, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+182, 4, t_00+0+182, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+181, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+181, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+180, 4, t_00+0+180, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+179, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+179, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+178, 4, t_00+0+178, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+177, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+177, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+176, 4, t_00+0+176, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+175, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+175, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+174, 4, t_00+0+174, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+173, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+173, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+172, 4, t_00+0+172, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+171, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+171, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+170, 4, t_00+0+170, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+169, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+169, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+168, 4, t_00+0+168, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+167, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+167, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+166, 4, t_00+0+166, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+165, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+165, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+164, 4, t_00+0+164, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+163, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+163, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+162, 4, t_00+0+162, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+161, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+161, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+160, 4, t_00+0+160, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+159, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+159, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+158, 4, t_00+0+158, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+157, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+157, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+156, 4, t_00+0+156, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+155, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+155, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+154, 4, t_00+0+154, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+153, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+153, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+152, 4, t_00+0+152, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+151, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+151, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+150, 4, t_00+0+150, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+149, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+149, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+148, 4, t_00+0+148, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+147, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+147, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+146, 4, t_00+0+146, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+145, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+145, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+144, 4, t_00+0+144, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+143, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+143, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+142, 4, t_00+0+142, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+141, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+141, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+140, 4, t_00+0+140, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+139, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+139, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+138, 4, t_00+0+138, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+137, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+137, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+136, 4, t_00+0+136, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+135, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+135, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+134, 4, t_00+0+134, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+133, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+133, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+132, 4, t_00+0+132, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+131, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+131, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+130, 4, t_00+0+130, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+129, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+129, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+128, 4, t_00+0+128, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+127, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+127, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+126, 4, t_00+0+126, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+125, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+125, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+124, 4, t_00+0+124, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+123, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+123, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+122, 4, t_00+0+122, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+121, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+121, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+120, 4, t_00+0+120, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+119, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+119, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+118, 4, t_00+0+118, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+117, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+117, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+116, 4, t_00+0+116, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+115, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+115, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+114, 4, t_00+0+114, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+113, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+113, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+112, 4, t_00+0+112, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+111, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+111, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+110, 4, t_00+0+110, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+109, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+109, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+108, 4, t_00+0+108, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+107, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+107, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+106, 4, t_00+0+106, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+105, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+105, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+104, 4, t_00+0+104, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+103, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+103, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+102, 4, t_00+0+102, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+101, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+101, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+100, 4, t_00+0+100, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+99, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+99, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+98, 4, t_00+0+98, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+97, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+97, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+96, 4, t_00+0+96, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+95, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+95, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+94, 4, t_00+0+94, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+93, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+93, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+92, 4, t_00+0+92, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+91, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+91, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+90, 4, t_00+0+90, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+89, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+89, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+88, 4, t_00+0+88, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+87, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+87, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+86, 4, t_00+0+86, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+85, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+85, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+84, 4, t_00+0+84, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+83, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+83, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+82, 4, t_00+0+82, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+81, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+81, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+80, 4, t_00+0+80, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+79, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+79, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+78, 4, t_00+0+78, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+77, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+77, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+76, 4, t_00+0+76, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+75, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+75, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+74, 4, t_00+0+74, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+73, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+73, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+72, 4, t_00+0+72, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+71, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+71, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+70, 4, t_00+0+70, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+69, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+69, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+68, 4, t_00+0+68, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+67, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+67, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+66, 4, t_00+0+66, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+65, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+65, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+64, 4, t_00+0+64, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+63, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+63, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+62, 4, t_00+0+62, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+61, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+61, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+60, 4, t_00+0+60, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+59, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+59, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+58, 4, t_00+0+58, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+57, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+57, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+56, 4, t_00+0+56, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+55, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+55, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+54, 4, t_00+0+54, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+53, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+53, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+52, 4, t_00+0+52, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+51, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+51, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+50, 4, t_00+0+50, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+49, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+49, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+48, 4, t_00+0+48, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+47, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+47, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+46, 4, t_00+0+46, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+45, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+45, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+44, 4, t_00+0+44, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+43, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+43, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+42, 4, t_00+0+42, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+41, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+41, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+40, 4, t_00+0+40, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+39, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+39, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+38, 4, t_00+0+38, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+37, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+37, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+36, 4, t_00+0+36, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+35, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+35, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+34, 4, t_00+0+34, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+33, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+33, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+32, 4, t_00+0+32, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+31, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+31, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+30, 4, t_00+0+30, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+29, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+29, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+28, 4, t_00+0+28, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+27, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+27, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+26, 4, t_00+0+26, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+25, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+25, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+24, 4, t_00+0+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+23, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+23, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+22, 4, t_00+0+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+21, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+21, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+20, 4, t_00+0+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+19, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+19, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+18, 4, t_00+0+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+17, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+17, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+16, 4, t_00+0+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+15, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+15, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+14, 4, t_00+0+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+13, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+13, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+12, 4, t_00+0+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+11, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+11, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+10, 4, t_00+0+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+9, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+9, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+8, 4, t_00+0+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+7, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+7, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+6, 4, t_00+0+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+5, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+5, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+4, 4, t_00+0+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+3, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+3, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+2, 4, t_00+0+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+1, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+1, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+0, 4, t_00+0+0, 4, temp);
	GF2X_MUL(2, temp, 1, p_00+0+1, 1, q_00+0);
	GF2X_MUL(2, temp2, 1, p_10+0+1, 1, q_01+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_00+0+0, 2, t_00+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+0+0, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, q_01+0+0, 1, p_10+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, t_00+0, 1, t_00+0, 1, temp+1);
	memset(t_01+0, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(962, temp, 481, p_01+0+2, 481, q_00+0);
	GF2X_MUL(962, temp2, 481, p_11+0+2, 481, q_01+0);
	gf2x_add(962, t_01+0+1, 962, temp, 962, temp2);
	GF2X_MUL(4, temp, 2, q_00+0+479, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+479, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+478, 4, t_01+0+478, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+477, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+477, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+476, 4, t_01+0+476, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+475, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+475, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+474, 4, t_01+0+474, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+473, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+473, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+472, 4, t_01+0+472, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+471, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+471, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+470, 4, t_01+0+470, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+469, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+469, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+468, 4, t_01+0+468, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+467, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+467, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+466, 4, t_01+0+466, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+465, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+465, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+464, 4, t_01+0+464, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+463, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+463, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+462, 4, t_01+0+462, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+461, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+461, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+460, 4, t_01+0+460, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+459, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+459, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+458, 4, t_01+0+458, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+457, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+457, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+456, 4, t_01+0+456, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+455, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+455, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+454, 4, t_01+0+454, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+453, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+453, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+452, 4, t_01+0+452, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+451, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+451, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+450, 4, t_01+0+450, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+449, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+449, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+448, 4, t_01+0+448, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+447, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+447, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+446, 4, t_01+0+446, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+445, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+445, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+444, 4, t_01+0+444, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+443, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+443, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+442, 4, t_01+0+442, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+441, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+441, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+440, 4, t_01+0+440, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+439, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+439, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+438, 4, t_01+0+438, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+437, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+437, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+436, 4, t_01+0+436, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+435, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+435, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+434, 4, t_01+0+434, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+433, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+433, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+432, 4, t_01+0+432, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+431, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+431, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+430, 4, t_01+0+430, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+429, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+429, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+428, 4, t_01+0+428, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+427, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+427, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+426, 4, t_01+0+426, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+425, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+425, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+424, 4, t_01+0+424, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+423, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+423, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+422, 4, t_01+0+422, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+421, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+421, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+420, 4, t_01+0+420, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+419, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+419, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+418, 4, t_01+0+418, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+417, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+417, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+416, 4, t_01+0+416, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+415, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+415, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+414, 4, t_01+0+414, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+413, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+413, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+412, 4, t_01+0+412, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+411, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+411, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+410, 4, t_01+0+410, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+409, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+409, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+408, 4, t_01+0+408, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+407, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+407, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+406, 4, t_01+0+406, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+405, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+405, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+404, 4, t_01+0+404, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+403, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+403, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+402, 4, t_01+0+402, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+401, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+401, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+400, 4, t_01+0+400, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+399, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+399, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+398, 4, t_01+0+398, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+397, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+397, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+396, 4, t_01+0+396, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+395, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+395, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+394, 4, t_01+0+394, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+393, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+393, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+392, 4, t_01+0+392, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+391, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+391, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+390, 4, t_01+0+390, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+389, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+389, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+388, 4, t_01+0+388, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+387, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+387, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+386, 4, t_01+0+386, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+385, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+385, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+384, 4, t_01+0+384, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+383, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+383, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+382, 4, t_01+0+382, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+381, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+381, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+380, 4, t_01+0+380, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+379, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+379, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+378, 4, t_01+0+378, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+377, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+377, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+376, 4, t_01+0+376, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+375, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+375, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+374, 4, t_01+0+374, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+373, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+373, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+372, 4, t_01+0+372, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+371, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+371, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+370, 4, t_01+0+370, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+369, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+369, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+368, 4, t_01+0+368, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+367, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+367, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+366, 4, t_01+0+366, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+365, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+365, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+364, 4, t_01+0+364, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+363, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+363, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+362, 4, t_01+0+362, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+361, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+361, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+360, 4, t_01+0+360, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+359, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+359, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+358, 4, t_01+0+358, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+357, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+357, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+356, 4, t_01+0+356, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+355, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+355, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+354, 4, t_01+0+354, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+353, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+353, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+352, 4, t_01+0+352, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+351, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+351, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+350, 4, t_01+0+350, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+349, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+349, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+348, 4, t_01+0+348, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+347, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+347, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+346, 4, t_01+0+346, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+345, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+345, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+344, 4, t_01+0+344, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+343, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+343, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+342, 4, t_01+0+342, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+341, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+341, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+340, 4, t_01+0+340, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+339, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+339, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+338, 4, t_01+0+338, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+337, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+337, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+336, 4, t_01+0+336, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+335, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+335, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+334, 4, t_01+0+334, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+333, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+333, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+332, 4, t_01+0+332, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+331, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+331, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+330, 4, t_01+0+330, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+329, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+329, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+328, 4, t_01+0+328, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+327, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+327, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+326, 4, t_01+0+326, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+325, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+325, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+324, 4, t_01+0+324, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+323, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+323, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+322, 4, t_01+0+322, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+321, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+321, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+320, 4, t_01+0+320, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+319, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+319, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+318, 4, t_01+0+318, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+317, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+317, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+316, 4, t_01+0+316, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+315, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+315, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+314, 4, t_01+0+314, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+313, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+313, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+312, 4, t_01+0+312, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+311, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+311, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+310, 4, t_01+0+310, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+309, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+309, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+308, 4, t_01+0+308, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+307, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+307, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+306, 4, t_01+0+306, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+305, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+305, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+304, 4, t_01+0+304, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+303, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+303, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+302, 4, t_01+0+302, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+301, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+301, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+300, 4, t_01+0+300, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+299, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+299, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+298, 4, t_01+0+298, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+297, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+297, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+296, 4, t_01+0+296, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+295, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+295, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+294, 4, t_01+0+294, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+293, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+293, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+292, 4, t_01+0+292, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+291, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+291, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+290, 4, t_01+0+290, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+289, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+289, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+288, 4, t_01+0+288, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+287, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+287, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+286, 4, t_01+0+286, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+285, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+285, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+284, 4, t_01+0+284, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+283, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+283, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+282, 4, t_01+0+282, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+281, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+281, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+280, 4, t_01+0+280, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+279, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+279, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+278, 4, t_01+0+278, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+277, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+277, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+276, 4, t_01+0+276, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+275, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+275, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+274, 4, t_01+0+274, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+273, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+273, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+272, 4, t_01+0+272, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+271, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+271, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+270, 4, t_01+0+270, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+269, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+269, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+268, 4, t_01+0+268, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+267, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+267, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+266, 4, t_01+0+266, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+265, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+265, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+264, 4, t_01+0+264, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+263, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+263, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+262, 4, t_01+0+262, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+261, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+261, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+260, 4, t_01+0+260, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+259, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+259, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+258, 4, t_01+0+258, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+257, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+257, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+256, 4, t_01+0+256, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+255, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+255, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+254, 4, t_01+0+254, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+253, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+253, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+252, 4, t_01+0+252, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+251, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+251, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+250, 4, t_01+0+250, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+249, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+249, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+248, 4, t_01+0+248, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+247, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+247, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+246, 4, t_01+0+246, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+245, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+245, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+244, 4, t_01+0+244, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+243, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+243, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+242, 4, t_01+0+242, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+241, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+241, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+240, 4, t_01+0+240, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+239, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+239, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+238, 4, t_01+0+238, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+237, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+237, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+236, 4, t_01+0+236, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+235, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+235, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+234, 4, t_01+0+234, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+233, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+233, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+232, 4, t_01+0+232, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+231, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+231, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+230, 4, t_01+0+230, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+229, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+229, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+228, 4, t_01+0+228, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+227, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+227, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+226, 4, t_01+0+226, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+225, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+225, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+224, 4, t_01+0+224, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+223, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+223, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+222, 4, t_01+0+222, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+221, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+221, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+220, 4, t_01+0+220, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+219, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+219, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+218, 4, t_01+0+218, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+217, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+217, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+216, 4, t_01+0+216, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+215, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+215, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+214, 4, t_01+0+214, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+213, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+213, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+212, 4, t_01+0+212, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+211, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+211, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+210, 4, t_01+0+210, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+209, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+209, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+208, 4, t_01+0+208, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+207, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+207, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+206, 4, t_01+0+206, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+205, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+205, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+204, 4, t_01+0+204, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+203, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+203, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+202, 4, t_01+0+202, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+201, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+201, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+200, 4, t_01+0+200, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+199, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+199, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+198, 4, t_01+0+198, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+197, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+197, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+196, 4, t_01+0+196, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+195, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+195, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+194, 4, t_01+0+194, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+193, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+193, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+192, 4, t_01+0+192, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+191, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+191, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+190, 4, t_01+0+190, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+189, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+189, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+188, 4, t_01+0+188, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+187, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+187, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+186, 4, t_01+0+186, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+185, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+185, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+184, 4, t_01+0+184, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+183, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+183, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+182, 4, t_01+0+182, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+181, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+181, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+180, 4, t_01+0+180, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+179, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+179, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+178, 4, t_01+0+178, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+177, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+177, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+176, 4, t_01+0+176, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+175, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+175, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+174, 4, t_01+0+174, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+173, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+173, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+172, 4, t_01+0+172, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+171, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+171, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+170, 4, t_01+0+170, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+169, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+169, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+168, 4, t_01+0+168, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+167, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+167, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+166, 4, t_01+0+166, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+165, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+165, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+164, 4, t_01+0+164, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+163, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+163, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+162, 4, t_01+0+162, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+161, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+161, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+160, 4, t_01+0+160, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+159, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+159, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+158, 4, t_01+0+158, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+157, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+157, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+156, 4, t_01+0+156, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+155, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+155, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+154, 4, t_01+0+154, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+153, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+153, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+152, 4, t_01+0+152, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+151, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+151, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+150, 4, t_01+0+150, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+149, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+149, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+148, 4, t_01+0+148, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+147, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+147, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+146, 4, t_01+0+146, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+145, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+145, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+144, 4, t_01+0+144, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+143, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+143, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+142, 4, t_01+0+142, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+141, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+141, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+140, 4, t_01+0+140, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+139, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+139, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+138, 4, t_01+0+138, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+137, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+137, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+136, 4, t_01+0+136, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+135, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+135, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+134, 4, t_01+0+134, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+133, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+133, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+132, 4, t_01+0+132, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+131, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+131, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+130, 4, t_01+0+130, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+129, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+129, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+128, 4, t_01+0+128, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+127, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+127, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+126, 4, t_01+0+126, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+125, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+125, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+124, 4, t_01+0+124, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+123, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+123, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+122, 4, t_01+0+122, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+121, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+121, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+120, 4, t_01+0+120, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+119, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+119, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+118, 4, t_01+0+118, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+117, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+117, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+116, 4, t_01+0+116, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+115, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+115, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+114, 4, t_01+0+114, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+113, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+113, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+112, 4, t_01+0+112, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+111, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+111, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+110, 4, t_01+0+110, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+109, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+109, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+108, 4, t_01+0+108, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+107, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+107, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+106, 4, t_01+0+106, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+105, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+105, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+104, 4, t_01+0+104, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+103, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+103, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+102, 4, t_01+0+102, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+101, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+101, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+100, 4, t_01+0+100, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+99, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+99, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+98, 4, t_01+0+98, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+97, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+97, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+96, 4, t_01+0+96, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+95, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+95, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+94, 4, t_01+0+94, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+93, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+93, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+92, 4, t_01+0+92, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+91, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+91, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+90, 4, t_01+0+90, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+89, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+89, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+88, 4, t_01+0+88, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+87, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+87, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+86, 4, t_01+0+86, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+85, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+85, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+84, 4, t_01+0+84, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+83, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+83, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+82, 4, t_01+0+82, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+81, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+81, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+80, 4, t_01+0+80, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+79, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+79, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+78, 4, t_01+0+78, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+77, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+77, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+76, 4, t_01+0+76, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+75, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+75, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+74, 4, t_01+0+74, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+73, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+73, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+72, 4, t_01+0+72, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+71, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+71, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+70, 4, t_01+0+70, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+69, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+69, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+68, 4, t_01+0+68, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+67, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+67, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+66, 4, t_01+0+66, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+65, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+65, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+64, 4, t_01+0+64, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+63, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+63, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+62, 4, t_01+0+62, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+61, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+61, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+60, 4, t_01+0+60, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+59, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+59, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+58, 4, t_01+0+58, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+57, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+57, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+56, 4, t_01+0+56, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+55, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+55, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+54, 4, t_01+0+54, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+53, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+53, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+52, 4, t_01+0+52, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+51, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+51, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+50, 4, t_01+0+50, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+49, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+49, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+48, 4, t_01+0+48, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+47, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+47, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+46, 4, t_01+0+46, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+45, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+45, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+44, 4, t_01+0+44, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+43, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+43, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+42, 4, t_01+0+42, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+41, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+41, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+40, 4, t_01+0+40, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+39, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+39, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+38, 4, t_01+0+38, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+37, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+37, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+36, 4, t_01+0+36, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+35, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+35, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+34, 4, t_01+0+34, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+33, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+33, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+32, 4, t_01+0+32, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+31, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+31, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+30, 4, t_01+0+30, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+29, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+29, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+28, 4, t_01+0+28, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+27, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+27, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+26, 4, t_01+0+26, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+25, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+25, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+24, 4, t_01+0+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+23, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+23, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+22, 4, t_01+0+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+21, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+21, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+20, 4, t_01+0+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+19, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+19, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+18, 4, t_01+0+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+17, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+17, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+16, 4, t_01+0+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+15, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+15, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+14, 4, t_01+0+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+13, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+13, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+12, 4, t_01+0+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+11, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+11, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+10, 4, t_01+0+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+9, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+9, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+8, 4, t_01+0+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+7, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+7, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+6, 4, t_01+0+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+5, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+5, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+4, 4, t_01+0+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+3, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+3, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+2, 4, t_01+0+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+1, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+1, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+0, 4, t_01+0+0, 4, temp);
	GF2X_MUL(2, temp, 1, p_01+0+1, 1, q_00+0);
	GF2X_MUL(2, temp2, 1, p_11+0+1, 1, q_01+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_01+0+0, 2, t_01+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+0+0, 1, p_01+0);
	GF2X_MUL(2, temp2, 1, q_01+0+0, 1, p_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, t_01+0, 1, t_01+0, 1, temp+1);
	memset(t_10+0, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(962, temp, 481, p_00+0+2, 481, q_10+0);
	GF2X_MUL(962, temp2, 481, p_10+0+2, 481, q_11+0);
	gf2x_add(962, t_10+0+1, 962, temp, 962, temp2);
	GF2X_MUL(4, temp, 2, q_10+0+479, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+479, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+478, 4, t_10+0+478, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+477, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+477, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+476, 4, t_10+0+476, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+475, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+475, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+474, 4, t_10+0+474, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+473, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+473, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+472, 4, t_10+0+472, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+471, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+471, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+470, 4, t_10+0+470, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+469, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+469, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+468, 4, t_10+0+468, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+467, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+467, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+466, 4, t_10+0+466, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+465, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+465, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+464, 4, t_10+0+464, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+463, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+463, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+462, 4, t_10+0+462, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+461, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+461, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+460, 4, t_10+0+460, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+459, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+459, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+458, 4, t_10+0+458, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+457, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+457, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+456, 4, t_10+0+456, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+455, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+455, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+454, 4, t_10+0+454, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+453, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+453, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+452, 4, t_10+0+452, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+451, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+451, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+450, 4, t_10+0+450, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+449, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+449, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+448, 4, t_10+0+448, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+447, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+447, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+446, 4, t_10+0+446, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+445, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+445, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+444, 4, t_10+0+444, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+443, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+443, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+442, 4, t_10+0+442, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+441, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+441, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+440, 4, t_10+0+440, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+439, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+439, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+438, 4, t_10+0+438, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+437, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+437, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+436, 4, t_10+0+436, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+435, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+435, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+434, 4, t_10+0+434, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+433, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+433, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+432, 4, t_10+0+432, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+431, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+431, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+430, 4, t_10+0+430, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+429, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+429, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+428, 4, t_10+0+428, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+427, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+427, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+426, 4, t_10+0+426, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+425, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+425, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+424, 4, t_10+0+424, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+423, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+423, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+422, 4, t_10+0+422, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+421, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+421, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+420, 4, t_10+0+420, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+419, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+419, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+418, 4, t_10+0+418, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+417, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+417, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+416, 4, t_10+0+416, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+415, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+415, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+414, 4, t_10+0+414, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+413, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+413, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+412, 4, t_10+0+412, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+411, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+411, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+410, 4, t_10+0+410, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+409, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+409, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+408, 4, t_10+0+408, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+407, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+407, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+406, 4, t_10+0+406, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+405, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+405, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+404, 4, t_10+0+404, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+403, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+403, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+402, 4, t_10+0+402, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+401, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+401, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+400, 4, t_10+0+400, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+399, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+399, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+398, 4, t_10+0+398, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+397, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+397, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+396, 4, t_10+0+396, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+395, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+395, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+394, 4, t_10+0+394, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+393, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+393, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+392, 4, t_10+0+392, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+391, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+391, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+390, 4, t_10+0+390, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+389, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+389, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+388, 4, t_10+0+388, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+387, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+387, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+386, 4, t_10+0+386, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+385, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+385, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+384, 4, t_10+0+384, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+383, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+383, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+382, 4, t_10+0+382, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+381, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+381, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+380, 4, t_10+0+380, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+379, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+379, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+378, 4, t_10+0+378, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+377, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+377, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+376, 4, t_10+0+376, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+375, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+375, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+374, 4, t_10+0+374, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+373, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+373, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+372, 4, t_10+0+372, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+371, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+371, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+370, 4, t_10+0+370, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+369, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+369, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+368, 4, t_10+0+368, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+367, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+367, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+366, 4, t_10+0+366, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+365, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+365, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+364, 4, t_10+0+364, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+363, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+363, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+362, 4, t_10+0+362, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+361, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+361, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+360, 4, t_10+0+360, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+359, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+359, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+358, 4, t_10+0+358, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+357, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+357, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+356, 4, t_10+0+356, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+355, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+355, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+354, 4, t_10+0+354, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+353, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+353, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+352, 4, t_10+0+352, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+351, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+351, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+350, 4, t_10+0+350, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+349, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+349, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+348, 4, t_10+0+348, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+347, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+347, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+346, 4, t_10+0+346, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+345, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+345, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+344, 4, t_10+0+344, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+343, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+343, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+342, 4, t_10+0+342, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+341, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+341, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+340, 4, t_10+0+340, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+339, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+339, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+338, 4, t_10+0+338, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+337, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+337, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+336, 4, t_10+0+336, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+335, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+335, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+334, 4, t_10+0+334, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+333, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+333, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+332, 4, t_10+0+332, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+331, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+331, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+330, 4, t_10+0+330, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+329, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+329, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+328, 4, t_10+0+328, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+327, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+327, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+326, 4, t_10+0+326, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+325, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+325, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+324, 4, t_10+0+324, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+323, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+323, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+322, 4, t_10+0+322, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+321, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+321, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+320, 4, t_10+0+320, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+319, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+319, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+318, 4, t_10+0+318, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+317, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+317, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+316, 4, t_10+0+316, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+315, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+315, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+314, 4, t_10+0+314, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+313, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+313, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+312, 4, t_10+0+312, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+311, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+311, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+310, 4, t_10+0+310, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+309, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+309, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+308, 4, t_10+0+308, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+307, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+307, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+306, 4, t_10+0+306, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+305, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+305, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+304, 4, t_10+0+304, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+303, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+303, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+302, 4, t_10+0+302, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+301, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+301, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+300, 4, t_10+0+300, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+299, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+299, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+298, 4, t_10+0+298, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+297, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+297, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+296, 4, t_10+0+296, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+295, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+295, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+294, 4, t_10+0+294, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+293, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+293, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+292, 4, t_10+0+292, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+291, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+291, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+290, 4, t_10+0+290, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+289, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+289, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+288, 4, t_10+0+288, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+287, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+287, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+286, 4, t_10+0+286, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+285, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+285, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+284, 4, t_10+0+284, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+283, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+283, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+282, 4, t_10+0+282, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+281, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+281, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+280, 4, t_10+0+280, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+279, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+279, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+278, 4, t_10+0+278, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+277, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+277, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+276, 4, t_10+0+276, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+275, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+275, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+274, 4, t_10+0+274, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+273, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+273, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+272, 4, t_10+0+272, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+271, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+271, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+270, 4, t_10+0+270, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+269, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+269, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+268, 4, t_10+0+268, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+267, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+267, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+266, 4, t_10+0+266, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+265, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+265, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+264, 4, t_10+0+264, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+263, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+263, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+262, 4, t_10+0+262, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+261, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+261, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+260, 4, t_10+0+260, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+259, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+259, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+258, 4, t_10+0+258, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+257, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+257, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+256, 4, t_10+0+256, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+255, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+255, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+254, 4, t_10+0+254, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+253, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+253, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+252, 4, t_10+0+252, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+251, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+251, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+250, 4, t_10+0+250, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+249, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+249, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+248, 4, t_10+0+248, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+247, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+247, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+246, 4, t_10+0+246, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+245, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+245, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+244, 4, t_10+0+244, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+243, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+243, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+242, 4, t_10+0+242, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+241, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+241, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+240, 4, t_10+0+240, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+239, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+239, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+238, 4, t_10+0+238, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+237, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+237, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+236, 4, t_10+0+236, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+235, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+235, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+234, 4, t_10+0+234, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+233, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+233, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+232, 4, t_10+0+232, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+231, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+231, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+230, 4, t_10+0+230, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+229, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+229, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+228, 4, t_10+0+228, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+227, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+227, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+226, 4, t_10+0+226, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+225, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+225, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+224, 4, t_10+0+224, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+223, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+223, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+222, 4, t_10+0+222, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+221, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+221, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+220, 4, t_10+0+220, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+219, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+219, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+218, 4, t_10+0+218, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+217, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+217, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+216, 4, t_10+0+216, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+215, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+215, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+214, 4, t_10+0+214, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+213, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+213, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+212, 4, t_10+0+212, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+211, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+211, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+210, 4, t_10+0+210, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+209, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+209, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+208, 4, t_10+0+208, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+207, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+207, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+206, 4, t_10+0+206, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+205, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+205, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+204, 4, t_10+0+204, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+203, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+203, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+202, 4, t_10+0+202, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+201, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+201, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+200, 4, t_10+0+200, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+199, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+199, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+198, 4, t_10+0+198, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+197, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+197, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+196, 4, t_10+0+196, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+195, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+195, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+194, 4, t_10+0+194, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+193, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+193, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+192, 4, t_10+0+192, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+191, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+191, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+190, 4, t_10+0+190, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+189, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+189, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+188, 4, t_10+0+188, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+187, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+187, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+186, 4, t_10+0+186, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+185, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+185, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+184, 4, t_10+0+184, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+183, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+183, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+182, 4, t_10+0+182, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+181, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+181, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+180, 4, t_10+0+180, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+179, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+179, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+178, 4, t_10+0+178, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+177, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+177, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+176, 4, t_10+0+176, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+175, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+175, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+174, 4, t_10+0+174, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+173, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+173, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+172, 4, t_10+0+172, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+171, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+171, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+170, 4, t_10+0+170, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+169, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+169, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+168, 4, t_10+0+168, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+167, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+167, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+166, 4, t_10+0+166, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+165, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+165, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+164, 4, t_10+0+164, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+163, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+163, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+162, 4, t_10+0+162, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+161, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+161, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+160, 4, t_10+0+160, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+159, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+159, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+158, 4, t_10+0+158, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+157, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+157, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+156, 4, t_10+0+156, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+155, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+155, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+154, 4, t_10+0+154, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+153, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+153, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+152, 4, t_10+0+152, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+151, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+151, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+150, 4, t_10+0+150, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+149, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+149, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+148, 4, t_10+0+148, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+147, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+147, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+146, 4, t_10+0+146, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+145, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+145, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+144, 4, t_10+0+144, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+143, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+143, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+142, 4, t_10+0+142, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+141, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+141, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+140, 4, t_10+0+140, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+139, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+139, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+138, 4, t_10+0+138, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+137, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+137, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+136, 4, t_10+0+136, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+135, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+135, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+134, 4, t_10+0+134, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+133, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+133, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+132, 4, t_10+0+132, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+131, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+131, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+130, 4, t_10+0+130, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+129, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+129, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+128, 4, t_10+0+128, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+127, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+127, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+126, 4, t_10+0+126, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+125, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+125, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+124, 4, t_10+0+124, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+123, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+123, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+122, 4, t_10+0+122, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+121, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+121, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+120, 4, t_10+0+120, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+119, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+119, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+118, 4, t_10+0+118, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+117, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+117, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+116, 4, t_10+0+116, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+115, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+115, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+114, 4, t_10+0+114, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+113, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+113, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+112, 4, t_10+0+112, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+111, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+111, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+110, 4, t_10+0+110, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+109, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+109, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+108, 4, t_10+0+108, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+107, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+107, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+106, 4, t_10+0+106, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+105, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+105, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+104, 4, t_10+0+104, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+103, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+103, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+102, 4, t_10+0+102, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+101, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+101, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+100, 4, t_10+0+100, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+99, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+99, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+98, 4, t_10+0+98, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+97, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+97, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+96, 4, t_10+0+96, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+95, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+95, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+94, 4, t_10+0+94, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+93, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+93, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+92, 4, t_10+0+92, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+91, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+91, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+90, 4, t_10+0+90, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+89, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+89, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+88, 4, t_10+0+88, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+87, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+87, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+86, 4, t_10+0+86, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+85, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+85, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+84, 4, t_10+0+84, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+83, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+83, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+82, 4, t_10+0+82, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+81, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+81, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+80, 4, t_10+0+80, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+79, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+79, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+78, 4, t_10+0+78, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+77, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+77, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+76, 4, t_10+0+76, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+75, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+75, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+74, 4, t_10+0+74, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+73, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+73, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+72, 4, t_10+0+72, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+71, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+71, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+70, 4, t_10+0+70, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+69, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+69, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+68, 4, t_10+0+68, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+67, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+67, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+66, 4, t_10+0+66, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+65, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+65, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+64, 4, t_10+0+64, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+63, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+63, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+62, 4, t_10+0+62, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+61, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+61, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+60, 4, t_10+0+60, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+59, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+59, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+58, 4, t_10+0+58, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+57, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+57, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+56, 4, t_10+0+56, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+55, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+55, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+54, 4, t_10+0+54, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+53, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+53, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+52, 4, t_10+0+52, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+51, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+51, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+50, 4, t_10+0+50, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+49, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+49, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+48, 4, t_10+0+48, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+47, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+47, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+46, 4, t_10+0+46, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+45, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+45, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+44, 4, t_10+0+44, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+43, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+43, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+42, 4, t_10+0+42, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+41, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+41, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+40, 4, t_10+0+40, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+39, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+39, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+38, 4, t_10+0+38, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+37, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+37, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+36, 4, t_10+0+36, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+35, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+35, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+34, 4, t_10+0+34, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+33, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+33, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+32, 4, t_10+0+32, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+31, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+31, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+30, 4, t_10+0+30, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+29, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+29, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+28, 4, t_10+0+28, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+27, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+27, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+26, 4, t_10+0+26, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+25, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+25, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+24, 4, t_10+0+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+23, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+23, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+22, 4, t_10+0+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+21, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+21, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+20, 4, t_10+0+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+19, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+19, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+18, 4, t_10+0+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+17, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+17, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+16, 4, t_10+0+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+15, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+15, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+14, 4, t_10+0+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+13, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+13, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+12, 4, t_10+0+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+11, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+11, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+10, 4, t_10+0+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+9, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+9, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+8, 4, t_10+0+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+7, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+7, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+6, 4, t_10+0+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+5, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+5, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+4, 4, t_10+0+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+3, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+3, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+2, 4, t_10+0+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+1, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+1, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+0, 4, t_10+0+0, 4, temp);
	GF2X_MUL(2, temp, 1, p_00+0+1, 1, q_10+0);
	GF2X_MUL(2, temp2, 1, p_10+0+1, 1, q_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_10+0+0, 2, t_10+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+0+0, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, q_11+0+0, 1, p_10+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, t_10+0, 1, t_10+0, 1, temp+1);
	memset(t_11+0, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(962, temp, 481, p_01+0+2, 481, q_10+0);
	GF2X_MUL(962, temp2, 481, p_11+0+2, 481, q_11+0);
	gf2x_add(962, t_11+0+1, 962, temp, 962, temp2);
	GF2X_MUL(4, temp, 2, q_10+0+479, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+479, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+478, 4, t_11+0+478, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+477, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+477, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+476, 4, t_11+0+476, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+475, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+475, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+474, 4, t_11+0+474, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+473, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+473, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+472, 4, t_11+0+472, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+471, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+471, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+470, 4, t_11+0+470, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+469, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+469, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+468, 4, t_11+0+468, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+467, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+467, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+466, 4, t_11+0+466, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+465, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+465, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+464, 4, t_11+0+464, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+463, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+463, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+462, 4, t_11+0+462, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+461, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+461, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+460, 4, t_11+0+460, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+459, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+459, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+458, 4, t_11+0+458, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+457, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+457, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+456, 4, t_11+0+456, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+455, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+455, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+454, 4, t_11+0+454, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+453, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+453, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+452, 4, t_11+0+452, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+451, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+451, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+450, 4, t_11+0+450, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+449, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+449, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+448, 4, t_11+0+448, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+447, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+447, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+446, 4, t_11+0+446, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+445, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+445, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+444, 4, t_11+0+444, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+443, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+443, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+442, 4, t_11+0+442, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+441, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+441, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+440, 4, t_11+0+440, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+439, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+439, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+438, 4, t_11+0+438, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+437, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+437, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+436, 4, t_11+0+436, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+435, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+435, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+434, 4, t_11+0+434, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+433, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+433, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+432, 4, t_11+0+432, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+431, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+431, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+430, 4, t_11+0+430, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+429, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+429, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+428, 4, t_11+0+428, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+427, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+427, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+426, 4, t_11+0+426, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+425, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+425, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+424, 4, t_11+0+424, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+423, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+423, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+422, 4, t_11+0+422, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+421, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+421, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+420, 4, t_11+0+420, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+419, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+419, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+418, 4, t_11+0+418, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+417, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+417, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+416, 4, t_11+0+416, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+415, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+415, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+414, 4, t_11+0+414, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+413, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+413, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+412, 4, t_11+0+412, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+411, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+411, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+410, 4, t_11+0+410, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+409, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+409, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+408, 4, t_11+0+408, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+407, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+407, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+406, 4, t_11+0+406, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+405, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+405, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+404, 4, t_11+0+404, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+403, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+403, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+402, 4, t_11+0+402, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+401, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+401, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+400, 4, t_11+0+400, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+399, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+399, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+398, 4, t_11+0+398, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+397, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+397, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+396, 4, t_11+0+396, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+395, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+395, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+394, 4, t_11+0+394, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+393, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+393, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+392, 4, t_11+0+392, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+391, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+391, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+390, 4, t_11+0+390, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+389, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+389, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+388, 4, t_11+0+388, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+387, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+387, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+386, 4, t_11+0+386, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+385, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+385, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+384, 4, t_11+0+384, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+383, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+383, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+382, 4, t_11+0+382, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+381, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+381, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+380, 4, t_11+0+380, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+379, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+379, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+378, 4, t_11+0+378, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+377, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+377, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+376, 4, t_11+0+376, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+375, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+375, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+374, 4, t_11+0+374, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+373, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+373, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+372, 4, t_11+0+372, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+371, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+371, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+370, 4, t_11+0+370, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+369, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+369, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+368, 4, t_11+0+368, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+367, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+367, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+366, 4, t_11+0+366, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+365, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+365, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+364, 4, t_11+0+364, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+363, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+363, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+362, 4, t_11+0+362, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+361, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+361, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+360, 4, t_11+0+360, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+359, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+359, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+358, 4, t_11+0+358, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+357, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+357, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+356, 4, t_11+0+356, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+355, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+355, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+354, 4, t_11+0+354, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+353, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+353, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+352, 4, t_11+0+352, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+351, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+351, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+350, 4, t_11+0+350, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+349, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+349, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+348, 4, t_11+0+348, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+347, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+347, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+346, 4, t_11+0+346, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+345, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+345, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+344, 4, t_11+0+344, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+343, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+343, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+342, 4, t_11+0+342, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+341, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+341, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+340, 4, t_11+0+340, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+339, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+339, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+338, 4, t_11+0+338, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+337, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+337, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+336, 4, t_11+0+336, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+335, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+335, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+334, 4, t_11+0+334, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+333, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+333, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+332, 4, t_11+0+332, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+331, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+331, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+330, 4, t_11+0+330, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+329, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+329, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+328, 4, t_11+0+328, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+327, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+327, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+326, 4, t_11+0+326, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+325, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+325, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+324, 4, t_11+0+324, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+323, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+323, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+322, 4, t_11+0+322, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+321, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+321, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+320, 4, t_11+0+320, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+319, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+319, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+318, 4, t_11+0+318, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+317, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+317, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+316, 4, t_11+0+316, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+315, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+315, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+314, 4, t_11+0+314, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+313, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+313, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+312, 4, t_11+0+312, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+311, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+311, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+310, 4, t_11+0+310, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+309, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+309, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+308, 4, t_11+0+308, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+307, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+307, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+306, 4, t_11+0+306, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+305, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+305, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+304, 4, t_11+0+304, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+303, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+303, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+302, 4, t_11+0+302, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+301, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+301, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+300, 4, t_11+0+300, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+299, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+299, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+298, 4, t_11+0+298, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+297, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+297, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+296, 4, t_11+0+296, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+295, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+295, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+294, 4, t_11+0+294, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+293, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+293, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+292, 4, t_11+0+292, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+291, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+291, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+290, 4, t_11+0+290, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+289, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+289, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+288, 4, t_11+0+288, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+287, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+287, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+286, 4, t_11+0+286, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+285, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+285, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+284, 4, t_11+0+284, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+283, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+283, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+282, 4, t_11+0+282, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+281, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+281, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+280, 4, t_11+0+280, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+279, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+279, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+278, 4, t_11+0+278, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+277, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+277, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+276, 4, t_11+0+276, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+275, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+275, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+274, 4, t_11+0+274, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+273, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+273, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+272, 4, t_11+0+272, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+271, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+271, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+270, 4, t_11+0+270, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+269, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+269, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+268, 4, t_11+0+268, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+267, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+267, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+266, 4, t_11+0+266, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+265, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+265, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+264, 4, t_11+0+264, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+263, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+263, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+262, 4, t_11+0+262, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+261, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+261, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+260, 4, t_11+0+260, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+259, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+259, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+258, 4, t_11+0+258, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+257, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+257, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+256, 4, t_11+0+256, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+255, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+255, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+254, 4, t_11+0+254, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+253, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+253, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+252, 4, t_11+0+252, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+251, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+251, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+250, 4, t_11+0+250, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+249, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+249, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+248, 4, t_11+0+248, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+247, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+247, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+246, 4, t_11+0+246, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+245, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+245, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+244, 4, t_11+0+244, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+243, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+243, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+242, 4, t_11+0+242, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+241, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+241, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+240, 4, t_11+0+240, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+239, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+239, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+238, 4, t_11+0+238, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+237, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+237, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+236, 4, t_11+0+236, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+235, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+235, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+234, 4, t_11+0+234, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+233, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+233, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+232, 4, t_11+0+232, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+231, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+231, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+230, 4, t_11+0+230, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+229, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+229, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+228, 4, t_11+0+228, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+227, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+227, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+226, 4, t_11+0+226, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+225, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+225, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+224, 4, t_11+0+224, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+223, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+223, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+222, 4, t_11+0+222, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+221, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+221, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+220, 4, t_11+0+220, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+219, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+219, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+218, 4, t_11+0+218, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+217, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+217, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+216, 4, t_11+0+216, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+215, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+215, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+214, 4, t_11+0+214, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+213, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+213, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+212, 4, t_11+0+212, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+211, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+211, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+210, 4, t_11+0+210, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+209, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+209, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+208, 4, t_11+0+208, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+207, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+207, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+206, 4, t_11+0+206, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+205, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+205, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+204, 4, t_11+0+204, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+203, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+203, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+202, 4, t_11+0+202, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+201, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+201, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+200, 4, t_11+0+200, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+199, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+199, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+198, 4, t_11+0+198, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+197, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+197, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+196, 4, t_11+0+196, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+195, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+195, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+194, 4, t_11+0+194, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+193, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+193, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+192, 4, t_11+0+192, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+191, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+191, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+190, 4, t_11+0+190, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+189, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+189, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+188, 4, t_11+0+188, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+187, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+187, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+186, 4, t_11+0+186, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+185, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+185, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+184, 4, t_11+0+184, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+183, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+183, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+182, 4, t_11+0+182, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+181, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+181, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+180, 4, t_11+0+180, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+179, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+179, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+178, 4, t_11+0+178, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+177, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+177, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+176, 4, t_11+0+176, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+175, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+175, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+174, 4, t_11+0+174, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+173, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+173, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+172, 4, t_11+0+172, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+171, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+171, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+170, 4, t_11+0+170, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+169, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+169, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+168, 4, t_11+0+168, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+167, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+167, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+166, 4, t_11+0+166, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+165, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+165, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+164, 4, t_11+0+164, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+163, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+163, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+162, 4, t_11+0+162, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+161, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+161, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+160, 4, t_11+0+160, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+159, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+159, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+158, 4, t_11+0+158, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+157, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+157, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+156, 4, t_11+0+156, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+155, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+155, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+154, 4, t_11+0+154, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+153, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+153, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+152, 4, t_11+0+152, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+151, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+151, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+150, 4, t_11+0+150, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+149, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+149, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+148, 4, t_11+0+148, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+147, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+147, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+146, 4, t_11+0+146, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+145, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+145, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+144, 4, t_11+0+144, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+143, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+143, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+142, 4, t_11+0+142, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+141, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+141, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+140, 4, t_11+0+140, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+139, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+139, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+138, 4, t_11+0+138, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+137, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+137, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+136, 4, t_11+0+136, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+135, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+135, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+134, 4, t_11+0+134, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+133, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+133, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+132, 4, t_11+0+132, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+131, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+131, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+130, 4, t_11+0+130, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+129, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+129, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+128, 4, t_11+0+128, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+127, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+127, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+126, 4, t_11+0+126, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+125, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+125, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+124, 4, t_11+0+124, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+123, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+123, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+122, 4, t_11+0+122, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+121, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+121, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+120, 4, t_11+0+120, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+119, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+119, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+118, 4, t_11+0+118, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+117, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+117, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+116, 4, t_11+0+116, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+115, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+115, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+114, 4, t_11+0+114, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+113, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+113, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+112, 4, t_11+0+112, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+111, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+111, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+110, 4, t_11+0+110, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+109, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+109, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+108, 4, t_11+0+108, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+107, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+107, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+106, 4, t_11+0+106, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+105, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+105, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+104, 4, t_11+0+104, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+103, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+103, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+102, 4, t_11+0+102, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+101, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+101, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+100, 4, t_11+0+100, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+99, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+99, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+98, 4, t_11+0+98, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+97, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+97, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+96, 4, t_11+0+96, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+95, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+95, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+94, 4, t_11+0+94, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+93, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+93, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+92, 4, t_11+0+92, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+91, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+91, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+90, 4, t_11+0+90, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+89, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+89, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+88, 4, t_11+0+88, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+87, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+87, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+86, 4, t_11+0+86, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+85, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+85, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+84, 4, t_11+0+84, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+83, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+83, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+82, 4, t_11+0+82, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+81, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+81, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+80, 4, t_11+0+80, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+79, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+79, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+78, 4, t_11+0+78, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+77, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+77, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+76, 4, t_11+0+76, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+75, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+75, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+74, 4, t_11+0+74, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+73, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+73, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+72, 4, t_11+0+72, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+71, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+71, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+70, 4, t_11+0+70, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+69, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+69, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+68, 4, t_11+0+68, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+67, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+67, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+66, 4, t_11+0+66, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+65, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+65, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+64, 4, t_11+0+64, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+63, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+63, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+62, 4, t_11+0+62, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+61, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+61, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+60, 4, t_11+0+60, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+59, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+59, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+58, 4, t_11+0+58, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+57, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+57, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+56, 4, t_11+0+56, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+55, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+55, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+54, 4, t_11+0+54, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+53, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+53, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+52, 4, t_11+0+52, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+51, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+51, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+50, 4, t_11+0+50, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+49, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+49, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+48, 4, t_11+0+48, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+47, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+47, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+46, 4, t_11+0+46, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+45, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+45, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+44, 4, t_11+0+44, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+43, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+43, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+42, 4, t_11+0+42, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+41, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+41, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+40, 4, t_11+0+40, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+39, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+39, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+38, 4, t_11+0+38, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+37, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+37, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+36, 4, t_11+0+36, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+35, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+35, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+34, 4, t_11+0+34, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+33, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+33, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+32, 4, t_11+0+32, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+31, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+31, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+30, 4, t_11+0+30, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+29, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+29, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+28, 4, t_11+0+28, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+27, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+27, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+26, 4, t_11+0+26, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+25, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+25, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+24, 4, t_11+0+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+23, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+23, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+22, 4, t_11+0+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+21, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+21, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+20, 4, t_11+0+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+19, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+19, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+18, 4, t_11+0+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+17, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+17, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+16, 4, t_11+0+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+15, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+15, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+14, 4, t_11+0+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+13, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+13, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+12, 4, t_11+0+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+11, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+11, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+10, 4, t_11+0+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+9, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+9, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+8, 4, t_11+0+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+7, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+7, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+6, 4, t_11+0+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+5, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+5, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+4, 4, t_11+0+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+3, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+3, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+2, 4, t_11+0+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+1, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+1, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+0, 4, t_11+0+0, 4, temp);
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