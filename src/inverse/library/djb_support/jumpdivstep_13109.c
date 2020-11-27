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

int jumpdivstep_13109(int n, int delta, int nf, DIGIT *f, DIGIT *g, DIGIT *t_00, DIGIT *t_01, DIGIT *t_10, DIGIT *t_11, float x) {
	DIGIT p_00[420];
	DIGIT p_01[420];
	DIGIT p_10[420];
	DIGIT p_11[420];
	
	DIGIT q_00[407];
	DIGIT q_01[407];
	DIGIT q_10[407];
	DIGIT q_11[407];
	
	DIGIT f_sum[1254];
	DIGIT g_sum[1254];
	
	DIGIT temp[825];
	DIGIT temp2[825];
	

	delta = divstepsx_256(255, delta, f+406, g+406, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f+402+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g+402+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+402+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g+402+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f+402+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g+402+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+402+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g+402+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f+394+8, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g+394+8, 8, p_01+408);
	gf2x_add(16, f_sum+1215+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f+394+0, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g+394+0, 8, p_01+408);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1215, 8, f_sum+1215, 8, temp+8);
	right_bit_shift_n(16, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f+394+8, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g+394+8, 8, p_11+408);
	gf2x_add(16, g_sum+1215+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f+394+0, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g+394+0, 8, p_11+408);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1215, 8, g_sum+1215, 8, temp+8);
	right_bit_shift_n(16, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1220, g_sum+1220, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1216+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1216+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1216+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1216+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, q_00+395+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, q_01+395+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, q_10+395+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, q_11+395+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+395+0, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, q_01+395+0, 8, p_10+408);
	gf2x_add(16, p_00+392+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+395+0, 8, p_01+408);
	GF2X_MUL(16, temp2, 8, q_01+395+0, 8, p_11+408);
	gf2x_add(16, p_01+392+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+395+0, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, q_11+395+0, 8, p_10+408);
	gf2x_add(16, p_10+392+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+395+0, 8, p_01+408);
	GF2X_MUL(16, temp2, 8, q_11+395+0, 8, p_11+408);
	gf2x_add(16, p_11+392+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f+382+12, 16, p_00+392);
	GF2X_MUL(32, temp2, 16, g+382+12, 16, p_01+392);
	gf2x_add(28, f_sum+1170, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+392+4, 12, f+382);
	GF2X_MUL(24, temp2, 12, p_01+392+4, 12, g+382);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1170, 12, f_sum+1170, 12, temp+12);
	right_bit_shift_n(28, f_sum+1170, 60);
	GF2X_MUL(32, temp, 16, f+382+12, 16, p_10+392);
	GF2X_MUL(32, temp2, 16, g+382+12, 16, p_11+392);
	gf2x_add(28, g_sum+1170, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+392+4, 12, f+382);
	GF2X_MUL(24, temp2, 12, p_11+392+4, 12, g+382);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1170, 12, g_sum+1170, 12, temp+12);
	right_bit_shift_n(28, g_sum+1170, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1179, g_sum+1179, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_01+408);
	gf2x_add(12, f_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_01+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1215, 4, f_sum+1215, 4, temp+4);
	right_bit_shift_n(12, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_11+408);
	gf2x_add(12, g_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1215, 4, g_sum+1215, 4, temp+4);
	right_bit_shift_n(12, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1216, g_sum+1216, q_00+395, q_01+395, q_10+395, q_11+395);

	// Recombining results: n: 765, depth: 5
	memset(q_00+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_01+395);
	gf2x_add(8, q_00+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+383+0, 8, q_00+383+0, 8, temp);
	memset(q_01+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_01+395);
	gf2x_add(8, q_01+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+383+0, 8, q_01+383+0, 8, temp);
	memset(q_10+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_11+395);
	gf2x_add(8, q_10+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+383+0, 8, q_10+383+0, 8, temp);
	memset(q_11+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_11+395);
	gf2x_add(8, q_11+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+383+0, 8, q_11+383+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 4
	memset(p_00+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+392+4, 12, q_00+383);
	GF2X_MUL(24, temp2, 12, p_10+392+4, 12, q_01+383);
	gf2x_add(24, p_00+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+383+8, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_01+383+8, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+364+8, 8, p_00+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+4, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_01+383+4, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+364+4, 8, p_00+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+0, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_01+383+0, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+364+0, 8, p_00+364+0, 8, temp);
	memset(p_01+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+392+4, 12, q_00+383);
	GF2X_MUL(24, temp2, 12, p_11+392+4, 12, q_01+383);
	gf2x_add(24, p_01+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+383+8, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_01+383+8, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+364+8, 8, p_01+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+4, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_01+383+4, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+364+4, 8, p_01+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+0, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_01+383+0, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+364+0, 8, p_01+364+0, 8, temp);
	memset(p_10+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+392+4, 12, q_10+383);
	GF2X_MUL(24, temp2, 12, p_10+392+4, 12, q_11+383);
	gf2x_add(24, p_10+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+383+8, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_11+383+8, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+364+8, 8, p_10+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+4, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_11+383+4, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+364+4, 8, p_10+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+0, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_11+383+0, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+364+0, 8, p_10+364+0, 8, temp);
	memset(p_11+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+392+4, 12, q_10+383);
	GF2X_MUL(24, temp2, 12, p_11+392+4, 12, q_11+383);
	gf2x_add(24, p_11+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+383+8, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_11+383+8, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+364+8, 8, p_11+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+4, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_11+383+4, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+364+4, 8, p_11+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+0, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_11+383+0, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+364+0, 8, p_11+364+0, 8, temp);
	

	// Calculating left operands: n: 3315, depth: 3
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f+358+24, 28, p_00+364);
	GF2X_MUL(56, temp2, 28, g+358+24, 28, p_01+364);
	gf2x_add(52, f_sum+1089, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_00+364+4, 24, f+358);
	GF2X_MUL(48, temp2, 24, p_01+364+4, 24, g+358);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+1089, 24, f_sum+1089, 24, temp+24);
	right_bit_shift_n(52, f_sum+1089, 57);
	GF2X_MUL(56, temp, 28, f+358+24, 28, p_10+364);
	GF2X_MUL(56, temp2, 28, g+358+24, 28, p_11+364);
	gf2x_add(52, g_sum+1089, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_10+364+4, 24, f+358);
	GF2X_MUL(48, temp2, 24, p_11+364+4, 24, g+358);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+1089, 24, g_sum+1089, 24, temp+24);
	right_bit_shift_n(52, g_sum+1089, 57);
	

	delta = divstepsx_256(255, delta, f_sum+1110, g_sum+1110, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1106+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1106+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1106+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1106+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1102+4, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+1102+4, 8, p_01+408);
	gf2x_add(12, f_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, f_sum+1102);
	GF2X_MUL(8, temp2, 4, p_01+408+4, 4, g_sum+1102);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1215, 4, f_sum+1215, 4, temp+4);
	right_bit_shift_n(12, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+1102+4, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+1102+4, 8, p_11+408);
	gf2x_add(12, g_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+408+4, 4, f_sum+1102);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, g_sum+1102);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1215, 4, g_sum+1215, 4, temp+4);
	right_bit_shift_n(12, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1216, g_sum+1216, q_00+395, q_01+395, q_10+395, q_11+395);

	// Recombining results: n: 765, depth: 5
	memset(p_00+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_01+395);
	gf2x_add(8, p_00+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+392+0, 8, p_00+392+0, 8, temp);
	memset(p_01+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_01+395);
	gf2x_add(8, p_01+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+392+0, 8, p_01+392+0, 8, temp);
	memset(p_10+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_11+395);
	gf2x_add(8, p_10+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+392+0, 8, p_10+392+0, 8, temp);
	memset(p_11+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_11+395);
	gf2x_add(8, p_11+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+392+0, 8, p_11+392+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1090+12, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+12, 12, p_01+392);
	gf2x_add(24, f_sum+1170+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1090+0, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+0, 12, p_01+392);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1170, 12, f_sum+1170, 12, temp+12);
	right_bit_shift_n(24, f_sum+1170, 61);
	GF2X_MUL(24, temp, 12, f_sum+1090+12, 12, p_10+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+12, 12, p_11+392);
	gf2x_add(24, g_sum+1170+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1090+0, 12, p_10+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+0, 12, p_11+392);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1170, 12, g_sum+1170, 12, temp+12);
	right_bit_shift_n(24, g_sum+1170, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1179, g_sum+1179, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_01+408);
	gf2x_add(12, f_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_01+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1215, 4, f_sum+1215, 4, temp+4);
	right_bit_shift_n(12, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_11+408);
	gf2x_add(12, g_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1215, 4, g_sum+1215, 4, temp+4);
	right_bit_shift_n(12, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1216, g_sum+1216, q_00+395, q_01+395, q_10+395, q_11+395);

	// Recombining results: n: 765, depth: 5
	memset(q_00+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_01+395);
	gf2x_add(8, q_00+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+383+0, 8, q_00+383+0, 8, temp);
	memset(q_01+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_01+395);
	gf2x_add(8, q_01+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+383+0, 8, q_01+383+0, 8, temp);
	memset(q_10+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_11+395);
	gf2x_add(8, q_10+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+383+0, 8, q_10+383+0, 8, temp);
	memset(q_11+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_11+395);
	gf2x_add(8, q_11+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+383+0, 8, q_11+383+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 4
	GF2X_MUL(24, temp, 12, q_00+383+0, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, q_01+383+0, 12, p_10+392);
	gf2x_add(24, q_00+359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+383+0, 12, p_01+392);
	GF2X_MUL(24, temp2, 12, q_01+383+0, 12, p_11+392);
	gf2x_add(24, q_01+359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+383+0, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, q_11+383+0, 12, p_10+392);
	gf2x_add(24, q_10+359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+383+0, 12, p_01+392);
	GF2X_MUL(24, temp2, 12, q_11+383+0, 12, p_11+392);
	gf2x_add(24, q_11+359+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3315, depth: 3
	memset(p_00+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+364+4, 24, q_00+359);
	GF2X_MUL(48, temp2, 24, p_10+364+4, 24, q_01+359);
	gf2x_add(48, p_00+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+359+20, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+20, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+312+20, 8, p_00+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+16, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+16, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+312+16, 8, p_00+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+12, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+12, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+312+12, 8, p_00+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+8, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+8, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+312+8, 8, p_00+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+4, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+4, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+312+4, 8, p_00+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+0, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+0, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+312+0, 8, p_00+312+0, 8, temp);
	memset(p_01+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+364+4, 24, q_00+359);
	GF2X_MUL(48, temp2, 24, p_11+364+4, 24, q_01+359);
	gf2x_add(48, p_01+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+359+20, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+20, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+312+20, 8, p_01+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+16, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+16, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+312+16, 8, p_01+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+12, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+12, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+312+12, 8, p_01+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+8, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+8, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+312+8, 8, p_01+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+4, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+4, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+312+4, 8, p_01+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+0, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+0, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+312+0, 8, p_01+312+0, 8, temp);
	memset(p_10+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+364+4, 24, q_10+359);
	GF2X_MUL(48, temp2, 24, p_10+364+4, 24, q_11+359);
	gf2x_add(48, p_10+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+359+20, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+20, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+312+20, 8, p_10+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+16, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+16, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+312+16, 8, p_10+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+12, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+12, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+312+12, 8, p_10+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+8, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+8, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+312+8, 8, p_10+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+4, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+4, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+312+4, 8, p_10+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+0, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+0, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+312+0, 8, p_10+312+0, 8, temp);
	memset(p_11+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+364+4, 24, q_10+359);
	GF2X_MUL(48, temp2, 24, p_11+364+4, 24, q_11+359);
	gf2x_add(48, p_11+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+359+20, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+20, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+312+20, 8, p_11+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+16, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+16, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+312+16, 8, p_11+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+12, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+12, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+312+12, 8, p_11+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+8, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+8, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+312+8, 8, p_11+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+4, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+4, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+312+4, 8, p_11+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+0, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+0, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+312+0, 8, p_11+312+0, 8, temp);
	

	// Calculating left operands: n: 6630, depth: 2
	// Digits to shift: 51
	// Displacement: 52
	GF2X_MUL(104, temp, 52, f+306+52, 52, p_00+312);
	GF2X_MUL(104, temp2, 52, g+306+52, 52, p_01+312);
	gf2x_add(104, f_sum+932+0, 104, temp, 104, temp2);
	GF2X_MUL(104, temp, 52, f+306+0, 52, p_00+312);
	GF2X_MUL(104, temp2, 52, g+306+0, 52, p_01+312);
	gf2x_add(104, temp, 104, temp, 104, temp2);
	gf2x_add(52, f_sum+932, 52, f_sum+932, 52, temp+52);
	right_bit_shift_n(104, f_sum+932, 51);
	GF2X_MUL(104, temp, 52, f+306+52, 52, p_10+312);
	GF2X_MUL(104, temp2, 52, g+306+52, 52, p_11+312);
	gf2x_add(104, g_sum+932+0, 104, temp, 104, temp2);
	GF2X_MUL(104, temp, 52, f+306+0, 52, p_10+312);
	GF2X_MUL(104, temp2, 52, g+306+0, 52, p_11+312);
	gf2x_add(104, temp, 104, temp, 104, temp2);
	gf2x_add(52, g_sum+932, 52, g_sum+932, 52, temp+52);
	right_bit_shift_n(104, g_sum+932, 51);
	

	delta = divstepsx_256(255, delta, f_sum+981, g_sum+981, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+977+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+977+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+977+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+977+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+977+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+977+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+977+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+977+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+969+8, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+969+8, 8, p_01+408);
	gf2x_add(16, f_sum+1215+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+969+0, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+969+0, 8, p_01+408);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1215, 8, f_sum+1215, 8, temp+8);
	right_bit_shift_n(16, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+969+8, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+969+8, 8, p_11+408);
	gf2x_add(16, g_sum+1215+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+969+0, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+969+0, 8, p_11+408);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1215, 8, g_sum+1215, 8, temp+8);
	right_bit_shift_n(16, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1220, g_sum+1220, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1216+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1216+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1216+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1216+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, q_00+395+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, q_01+395+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, q_10+395+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, q_11+395+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+395+0, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, q_01+395+0, 8, p_10+408);
	gf2x_add(16, p_00+392+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+395+0, 8, p_01+408);
	GF2X_MUL(16, temp2, 8, q_01+395+0, 8, p_11+408);
	gf2x_add(16, p_01+392+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+395+0, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, q_11+395+0, 8, p_10+408);
	gf2x_add(16, p_10+392+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+395+0, 8, p_01+408);
	GF2X_MUL(16, temp2, 8, q_11+395+0, 8, p_11+408);
	gf2x_add(16, p_11+392+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+957+12, 16, p_00+392);
	GF2X_MUL(32, temp2, 16, g_sum+957+12, 16, p_01+392);
	gf2x_add(28, f_sum+1170, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+392+4, 12, f_sum+957);
	GF2X_MUL(24, temp2, 12, p_01+392+4, 12, g_sum+957);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1170, 12, f_sum+1170, 12, temp+12);
	right_bit_shift_n(28, f_sum+1170, 60);
	GF2X_MUL(32, temp, 16, f_sum+957+12, 16, p_10+392);
	GF2X_MUL(32, temp2, 16, g_sum+957+12, 16, p_11+392);
	gf2x_add(28, g_sum+1170, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+392+4, 12, f_sum+957);
	GF2X_MUL(24, temp2, 12, p_11+392+4, 12, g_sum+957);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1170, 12, g_sum+1170, 12, temp+12);
	right_bit_shift_n(28, g_sum+1170, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1179, g_sum+1179, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_01+408);
	gf2x_add(12, f_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_01+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1215, 4, f_sum+1215, 4, temp+4);
	right_bit_shift_n(12, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_11+408);
	gf2x_add(12, g_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1215, 4, g_sum+1215, 4, temp+4);
	right_bit_shift_n(12, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1216, g_sum+1216, q_00+395, q_01+395, q_10+395, q_11+395);

	// Recombining results: n: 765, depth: 5
	memset(q_00+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_01+395);
	gf2x_add(8, q_00+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+383+0, 8, q_00+383+0, 8, temp);
	memset(q_01+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_01+395);
	gf2x_add(8, q_01+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+383+0, 8, q_01+383+0, 8, temp);
	memset(q_10+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_11+395);
	gf2x_add(8, q_10+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+383+0, 8, q_10+383+0, 8, temp);
	memset(q_11+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_11+395);
	gf2x_add(8, q_11+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+383+0, 8, q_11+383+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 4
	memset(p_00+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+392+4, 12, q_00+383);
	GF2X_MUL(24, temp2, 12, p_10+392+4, 12, q_01+383);
	gf2x_add(24, p_00+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+383+8, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_01+383+8, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+364+8, 8, p_00+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+4, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_01+383+4, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+364+4, 8, p_00+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+0, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_01+383+0, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+364+0, 8, p_00+364+0, 8, temp);
	memset(p_01+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+392+4, 12, q_00+383);
	GF2X_MUL(24, temp2, 12, p_11+392+4, 12, q_01+383);
	gf2x_add(24, p_01+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+383+8, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_01+383+8, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+364+8, 8, p_01+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+4, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_01+383+4, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+364+4, 8, p_01+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+0, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_01+383+0, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+364+0, 8, p_01+364+0, 8, temp);
	memset(p_10+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+392+4, 12, q_10+383);
	GF2X_MUL(24, temp2, 12, p_10+392+4, 12, q_11+383);
	gf2x_add(24, p_10+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+383+8, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_11+383+8, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+364+8, 8, p_10+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+4, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_11+383+4, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+364+4, 8, p_10+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+0, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_11+383+0, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+364+0, 8, p_10+364+0, 8, temp);
	memset(p_11+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+392+4, 12, q_10+383);
	GF2X_MUL(24, temp2, 12, p_11+392+4, 12, q_11+383);
	gf2x_add(24, p_11+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+383+8, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_11+383+8, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+364+8, 8, p_11+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+4, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_11+383+4, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+364+4, 8, p_11+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+0, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_11+383+0, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+364+0, 8, p_11+364+0, 8, temp);
	

	// Calculating left operands: n: 3315, depth: 3
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+933+24, 28, p_00+364);
	GF2X_MUL(56, temp2, 28, g_sum+933+24, 28, p_01+364);
	gf2x_add(52, f_sum+1089, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_00+364+4, 24, f_sum+933);
	GF2X_MUL(48, temp2, 24, p_01+364+4, 24, g_sum+933);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+1089, 24, f_sum+1089, 24, temp+24);
	right_bit_shift_n(52, f_sum+1089, 57);
	GF2X_MUL(56, temp, 28, f_sum+933+24, 28, p_10+364);
	GF2X_MUL(56, temp2, 28, g_sum+933+24, 28, p_11+364);
	gf2x_add(52, g_sum+1089, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_10+364+4, 24, f_sum+933);
	GF2X_MUL(48, temp2, 24, p_11+364+4, 24, g_sum+933);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+1089, 24, g_sum+1089, 24, temp+24);
	right_bit_shift_n(52, g_sum+1089, 57);
	

	delta = divstepsx_256(255, delta, f_sum+1110, g_sum+1110, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1106+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1106+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1106+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1106+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1102+4, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+1102+4, 8, p_01+408);
	gf2x_add(12, f_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, f_sum+1102);
	GF2X_MUL(8, temp2, 4, p_01+408+4, 4, g_sum+1102);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1215, 4, f_sum+1215, 4, temp+4);
	right_bit_shift_n(12, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+1102+4, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+1102+4, 8, p_11+408);
	gf2x_add(12, g_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+408+4, 4, f_sum+1102);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, g_sum+1102);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1215, 4, g_sum+1215, 4, temp+4);
	right_bit_shift_n(12, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1216, g_sum+1216, q_00+395, q_01+395, q_10+395, q_11+395);

	// Recombining results: n: 765, depth: 5
	memset(p_00+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_01+395);
	gf2x_add(8, p_00+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+392+0, 8, p_00+392+0, 8, temp);
	memset(p_01+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_01+395);
	gf2x_add(8, p_01+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+392+0, 8, p_01+392+0, 8, temp);
	memset(p_10+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_11+395);
	gf2x_add(8, p_10+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+392+0, 8, p_10+392+0, 8, temp);
	memset(p_11+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_11+395);
	gf2x_add(8, p_11+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+392+0, 8, p_11+392+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1090+12, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+12, 12, p_01+392);
	gf2x_add(24, f_sum+1170+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1090+0, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+0, 12, p_01+392);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1170, 12, f_sum+1170, 12, temp+12);
	right_bit_shift_n(24, f_sum+1170, 61);
	GF2X_MUL(24, temp, 12, f_sum+1090+12, 12, p_10+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+12, 12, p_11+392);
	gf2x_add(24, g_sum+1170+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1090+0, 12, p_10+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+0, 12, p_11+392);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1170, 12, g_sum+1170, 12, temp+12);
	right_bit_shift_n(24, g_sum+1170, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1179, g_sum+1179, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_01+408);
	gf2x_add(12, f_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_01+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1215, 4, f_sum+1215, 4, temp+4);
	right_bit_shift_n(12, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_11+408);
	gf2x_add(12, g_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1215, 4, g_sum+1215, 4, temp+4);
	right_bit_shift_n(12, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1216, g_sum+1216, q_00+395, q_01+395, q_10+395, q_11+395);

	// Recombining results: n: 765, depth: 5
	memset(q_00+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_01+395);
	gf2x_add(8, q_00+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+383+0, 8, q_00+383+0, 8, temp);
	memset(q_01+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_01+395);
	gf2x_add(8, q_01+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+383+0, 8, q_01+383+0, 8, temp);
	memset(q_10+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_11+395);
	gf2x_add(8, q_10+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+383+0, 8, q_10+383+0, 8, temp);
	memset(q_11+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_11+395);
	gf2x_add(8, q_11+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+383+0, 8, q_11+383+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 4
	GF2X_MUL(24, temp, 12, q_00+383+0, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, q_01+383+0, 12, p_10+392);
	gf2x_add(24, q_00+359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+383+0, 12, p_01+392);
	GF2X_MUL(24, temp2, 12, q_01+383+0, 12, p_11+392);
	gf2x_add(24, q_01+359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+383+0, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, q_11+383+0, 12, p_10+392);
	gf2x_add(24, q_10+359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+383+0, 12, p_01+392);
	GF2X_MUL(24, temp2, 12, q_11+383+0, 12, p_11+392);
	gf2x_add(24, q_11+359+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3315, depth: 3
	memset(q_00+307, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+364+4, 24, q_00+359);
	GF2X_MUL(48, temp2, 24, p_10+364+4, 24, q_01+359);
	gf2x_add(48, q_00+307+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+359+20, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+20, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+307+20, 8, q_00+307+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+16, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+16, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+307+16, 8, q_00+307+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+12, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+12, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+307+12, 8, q_00+307+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+8, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+8, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+307+8, 8, q_00+307+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+4, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+4, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+307+4, 8, q_00+307+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+0, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+0, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+307+0, 8, q_00+307+0, 8, temp);
	memset(q_01+307, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+364+4, 24, q_00+359);
	GF2X_MUL(48, temp2, 24, p_11+364+4, 24, q_01+359);
	gf2x_add(48, q_01+307+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+359+20, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+20, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+307+20, 8, q_01+307+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+16, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+16, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+307+16, 8, q_01+307+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+12, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+12, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+307+12, 8, q_01+307+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+8, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+8, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+307+8, 8, q_01+307+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+4, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+4, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+307+4, 8, q_01+307+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+0, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+0, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+307+0, 8, q_01+307+0, 8, temp);
	memset(q_10+307, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+364+4, 24, q_10+359);
	GF2X_MUL(48, temp2, 24, p_10+364+4, 24, q_11+359);
	gf2x_add(48, q_10+307+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+359+20, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+20, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+307+20, 8, q_10+307+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+16, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+16, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+307+16, 8, q_10+307+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+12, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+12, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+307+12, 8, q_10+307+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+8, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+8, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+307+8, 8, q_10+307+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+4, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+4, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+307+4, 8, q_10+307+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+0, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+0, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+307+0, 8, q_10+307+0, 8, temp);
	memset(q_11+307, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+364+4, 24, q_10+359);
	GF2X_MUL(48, temp2, 24, p_11+364+4, 24, q_11+359);
	gf2x_add(48, q_11+307+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+359+20, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+20, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+307+20, 8, q_11+307+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+16, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+16, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+307+16, 8, q_11+307+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+12, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+12, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+307+12, 8, q_11+307+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+8, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+8, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+307+8, 8, q_11+307+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+4, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+4, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+307+4, 8, q_11+307+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+0, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+0, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+307+0, 8, q_11+307+0, 8, temp);
	

	// Recombining results: n: 6630, depth: 2
	GF2X_MUL(104, temp, 52, q_00+307+0, 52, p_00+312);
	GF2X_MUL(104, temp2, 52, q_01+307+0, 52, p_10+312);
	gf2x_add(104, p_00+208+0, 104, temp, 104, temp2);
	GF2X_MUL(104, temp, 52, q_00+307+0, 52, p_01+312);
	GF2X_MUL(104, temp2, 52, q_01+307+0, 52, p_11+312);
	gf2x_add(104, p_01+208+0, 104, temp, 104, temp2);
	GF2X_MUL(104, temp, 52, q_10+307+0, 52, p_00+312);
	GF2X_MUL(104, temp2, 52, q_11+307+0, 52, p_10+312);
	gf2x_add(104, p_10+208+0, 104, temp, 104, temp2);
	GF2X_MUL(104, temp, 52, q_10+307+0, 52, p_01+312);
	GF2X_MUL(104, temp2, 52, q_11+307+0, 52, p_11+312);
	gf2x_add(104, p_11+208+0, 104, temp, 104, temp2);
	

	// Calculating left operands: n: 13260, depth: 1
	// Digits to shift: 103
	// Displacement: 104
	GF2X_MUL(208, temp, 104, f+202+104, 104, p_00+208);
	GF2X_MUL(208, temp2, 104, g+202+104, 104, p_01+208);
	gf2x_add(208, f_sum+619+0, 208, temp, 208, temp2);
	GF2X_MUL(208, temp, 104, f+202+0, 104, p_00+208);
	GF2X_MUL(208, temp2, 104, g+202+0, 104, p_01+208);
	gf2x_add(208, temp, 208, temp, 208, temp2);
	gf2x_add(104, f_sum+619, 104, f_sum+619, 104, temp+104);
	right_bit_shift_n(208, f_sum+619, 38);
	GF2X_MUL(208, temp, 104, f+202+104, 104, p_10+208);
	GF2X_MUL(208, temp2, 104, g+202+104, 104, p_11+208);
	gf2x_add(208, g_sum+619+0, 208, temp, 208, temp2);
	GF2X_MUL(208, temp, 104, f+202+0, 104, p_10+208);
	GF2X_MUL(208, temp2, 104, g+202+0, 104, p_11+208);
	gf2x_add(208, temp, 208, temp, 208, temp2);
	gf2x_add(104, g_sum+619, 104, g_sum+619, 104, temp+104);
	right_bit_shift_n(208, g_sum+619, 38);
	

	delta = divstepsx_256(255, delta, f_sum+720, g_sum+720, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+716+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+716+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+716+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+716+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+716+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+716+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+716+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+716+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+708+8, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+708+8, 8, p_01+408);
	gf2x_add(16, f_sum+1215+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+708+0, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+708+0, 8, p_01+408);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1215, 8, f_sum+1215, 8, temp+8);
	right_bit_shift_n(16, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+708+8, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+708+8, 8, p_11+408);
	gf2x_add(16, g_sum+1215+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+708+0, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+708+0, 8, p_11+408);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1215, 8, g_sum+1215, 8, temp+8);
	right_bit_shift_n(16, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1220, g_sum+1220, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1216+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1216+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1216+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1216+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, q_00+395+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, q_01+395+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, q_10+395+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, q_11+395+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+395+0, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, q_01+395+0, 8, p_10+408);
	gf2x_add(16, p_00+392+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+395+0, 8, p_01+408);
	GF2X_MUL(16, temp2, 8, q_01+395+0, 8, p_11+408);
	gf2x_add(16, p_01+392+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+395+0, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, q_11+395+0, 8, p_10+408);
	gf2x_add(16, p_10+392+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+395+0, 8, p_01+408);
	GF2X_MUL(16, temp2, 8, q_11+395+0, 8, p_11+408);
	gf2x_add(16, p_11+392+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+696+12, 16, p_00+392);
	GF2X_MUL(32, temp2, 16, g_sum+696+12, 16, p_01+392);
	gf2x_add(28, f_sum+1170, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+392+4, 12, f_sum+696);
	GF2X_MUL(24, temp2, 12, p_01+392+4, 12, g_sum+696);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1170, 12, f_sum+1170, 12, temp+12);
	right_bit_shift_n(28, f_sum+1170, 60);
	GF2X_MUL(32, temp, 16, f_sum+696+12, 16, p_10+392);
	GF2X_MUL(32, temp2, 16, g_sum+696+12, 16, p_11+392);
	gf2x_add(28, g_sum+1170, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+392+4, 12, f_sum+696);
	GF2X_MUL(24, temp2, 12, p_11+392+4, 12, g_sum+696);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1170, 12, g_sum+1170, 12, temp+12);
	right_bit_shift_n(28, g_sum+1170, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1179, g_sum+1179, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_01+408);
	gf2x_add(12, f_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_01+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1215, 4, f_sum+1215, 4, temp+4);
	right_bit_shift_n(12, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_11+408);
	gf2x_add(12, g_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1215, 4, g_sum+1215, 4, temp+4);
	right_bit_shift_n(12, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1216, g_sum+1216, q_00+395, q_01+395, q_10+395, q_11+395);

	// Recombining results: n: 765, depth: 5
	memset(q_00+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_01+395);
	gf2x_add(8, q_00+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+383+0, 8, q_00+383+0, 8, temp);
	memset(q_01+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_01+395);
	gf2x_add(8, q_01+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+383+0, 8, q_01+383+0, 8, temp);
	memset(q_10+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_11+395);
	gf2x_add(8, q_10+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+383+0, 8, q_10+383+0, 8, temp);
	memset(q_11+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_11+395);
	gf2x_add(8, q_11+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+383+0, 8, q_11+383+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 4
	memset(p_00+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+392+4, 12, q_00+383);
	GF2X_MUL(24, temp2, 12, p_10+392+4, 12, q_01+383);
	gf2x_add(24, p_00+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+383+8, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_01+383+8, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+364+8, 8, p_00+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+4, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_01+383+4, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+364+4, 8, p_00+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+0, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_01+383+0, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+364+0, 8, p_00+364+0, 8, temp);
	memset(p_01+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+392+4, 12, q_00+383);
	GF2X_MUL(24, temp2, 12, p_11+392+4, 12, q_01+383);
	gf2x_add(24, p_01+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+383+8, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_01+383+8, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+364+8, 8, p_01+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+4, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_01+383+4, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+364+4, 8, p_01+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+0, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_01+383+0, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+364+0, 8, p_01+364+0, 8, temp);
	memset(p_10+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+392+4, 12, q_10+383);
	GF2X_MUL(24, temp2, 12, p_10+392+4, 12, q_11+383);
	gf2x_add(24, p_10+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+383+8, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_11+383+8, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+364+8, 8, p_10+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+4, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_11+383+4, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+364+4, 8, p_10+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+0, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_11+383+0, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+364+0, 8, p_10+364+0, 8, temp);
	memset(p_11+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+392+4, 12, q_10+383);
	GF2X_MUL(24, temp2, 12, p_11+392+4, 12, q_11+383);
	gf2x_add(24, p_11+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+383+8, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_11+383+8, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+364+8, 8, p_11+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+4, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_11+383+4, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+364+4, 8, p_11+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+0, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_11+383+0, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+364+0, 8, p_11+364+0, 8, temp);
	

	// Calculating left operands: n: 3315, depth: 3
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+672+24, 28, p_00+364);
	GF2X_MUL(56, temp2, 28, g_sum+672+24, 28, p_01+364);
	gf2x_add(52, f_sum+1089, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_00+364+4, 24, f_sum+672);
	GF2X_MUL(48, temp2, 24, p_01+364+4, 24, g_sum+672);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+1089, 24, f_sum+1089, 24, temp+24);
	right_bit_shift_n(52, f_sum+1089, 57);
	GF2X_MUL(56, temp, 28, f_sum+672+24, 28, p_10+364);
	GF2X_MUL(56, temp2, 28, g_sum+672+24, 28, p_11+364);
	gf2x_add(52, g_sum+1089, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_10+364+4, 24, f_sum+672);
	GF2X_MUL(48, temp2, 24, p_11+364+4, 24, g_sum+672);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+1089, 24, g_sum+1089, 24, temp+24);
	right_bit_shift_n(52, g_sum+1089, 57);
	

	delta = divstepsx_256(255, delta, f_sum+1110, g_sum+1110, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1106+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1106+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1106+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1106+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1102+4, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+1102+4, 8, p_01+408);
	gf2x_add(12, f_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, f_sum+1102);
	GF2X_MUL(8, temp2, 4, p_01+408+4, 4, g_sum+1102);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1215, 4, f_sum+1215, 4, temp+4);
	right_bit_shift_n(12, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+1102+4, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+1102+4, 8, p_11+408);
	gf2x_add(12, g_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+408+4, 4, f_sum+1102);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, g_sum+1102);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1215, 4, g_sum+1215, 4, temp+4);
	right_bit_shift_n(12, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1216, g_sum+1216, q_00+395, q_01+395, q_10+395, q_11+395);

	// Recombining results: n: 765, depth: 5
	memset(p_00+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_01+395);
	gf2x_add(8, p_00+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+392+0, 8, p_00+392+0, 8, temp);
	memset(p_01+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_01+395);
	gf2x_add(8, p_01+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+392+0, 8, p_01+392+0, 8, temp);
	memset(p_10+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_11+395);
	gf2x_add(8, p_10+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+392+0, 8, p_10+392+0, 8, temp);
	memset(p_11+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_11+395);
	gf2x_add(8, p_11+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+392+0, 8, p_11+392+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1090+12, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+12, 12, p_01+392);
	gf2x_add(24, f_sum+1170+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1090+0, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+0, 12, p_01+392);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1170, 12, f_sum+1170, 12, temp+12);
	right_bit_shift_n(24, f_sum+1170, 61);
	GF2X_MUL(24, temp, 12, f_sum+1090+12, 12, p_10+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+12, 12, p_11+392);
	gf2x_add(24, g_sum+1170+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1090+0, 12, p_10+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+0, 12, p_11+392);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1170, 12, g_sum+1170, 12, temp+12);
	right_bit_shift_n(24, g_sum+1170, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1179, g_sum+1179, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_01+408);
	gf2x_add(12, f_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_01+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1215, 4, f_sum+1215, 4, temp+4);
	right_bit_shift_n(12, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_11+408);
	gf2x_add(12, g_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1215, 4, g_sum+1215, 4, temp+4);
	right_bit_shift_n(12, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1216, g_sum+1216, q_00+395, q_01+395, q_10+395, q_11+395);

	// Recombining results: n: 765, depth: 5
	memset(q_00+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_01+395);
	gf2x_add(8, q_00+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+383+0, 8, q_00+383+0, 8, temp);
	memset(q_01+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_01+395);
	gf2x_add(8, q_01+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+383+0, 8, q_01+383+0, 8, temp);
	memset(q_10+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_11+395);
	gf2x_add(8, q_10+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+383+0, 8, q_10+383+0, 8, temp);
	memset(q_11+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_11+395);
	gf2x_add(8, q_11+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+383+0, 8, q_11+383+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 4
	GF2X_MUL(24, temp, 12, q_00+383+0, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, q_01+383+0, 12, p_10+392);
	gf2x_add(24, q_00+359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+383+0, 12, p_01+392);
	GF2X_MUL(24, temp2, 12, q_01+383+0, 12, p_11+392);
	gf2x_add(24, q_01+359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+383+0, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, q_11+383+0, 12, p_10+392);
	gf2x_add(24, q_10+359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+383+0, 12, p_01+392);
	GF2X_MUL(24, temp2, 12, q_11+383+0, 12, p_11+392);
	gf2x_add(24, q_11+359+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3315, depth: 3
	memset(p_00+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+364+4, 24, q_00+359);
	GF2X_MUL(48, temp2, 24, p_10+364+4, 24, q_01+359);
	gf2x_add(48, p_00+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+359+20, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+20, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+312+20, 8, p_00+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+16, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+16, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+312+16, 8, p_00+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+12, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+12, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+312+12, 8, p_00+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+8, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+8, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+312+8, 8, p_00+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+4, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+4, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+312+4, 8, p_00+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+0, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+0, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+312+0, 8, p_00+312+0, 8, temp);
	memset(p_01+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+364+4, 24, q_00+359);
	GF2X_MUL(48, temp2, 24, p_11+364+4, 24, q_01+359);
	gf2x_add(48, p_01+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+359+20, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+20, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+312+20, 8, p_01+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+16, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+16, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+312+16, 8, p_01+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+12, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+12, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+312+12, 8, p_01+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+8, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+8, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+312+8, 8, p_01+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+4, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+4, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+312+4, 8, p_01+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+0, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+0, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+312+0, 8, p_01+312+0, 8, temp);
	memset(p_10+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+364+4, 24, q_10+359);
	GF2X_MUL(48, temp2, 24, p_10+364+4, 24, q_11+359);
	gf2x_add(48, p_10+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+359+20, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+20, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+312+20, 8, p_10+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+16, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+16, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+312+16, 8, p_10+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+12, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+12, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+312+12, 8, p_10+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+8, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+8, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+312+8, 8, p_10+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+4, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+4, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+312+4, 8, p_10+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+0, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+0, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+312+0, 8, p_10+312+0, 8, temp);
	memset(p_11+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+364+4, 24, q_10+359);
	GF2X_MUL(48, temp2, 24, p_11+364+4, 24, q_11+359);
	gf2x_add(48, p_11+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+359+20, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+20, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+312+20, 8, p_11+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+16, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+16, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+312+16, 8, p_11+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+12, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+12, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+312+12, 8, p_11+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+8, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+8, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+312+8, 8, p_11+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+4, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+4, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+312+4, 8, p_11+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+0, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+0, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+312+0, 8, p_11+312+0, 8, temp);
	

	// Calculating left operands: n: 6630, depth: 2
	// Digits to shift: 51
	// Displacement: 52
	GF2X_MUL(104, temp, 52, f_sum+620+52, 52, p_00+312);
	GF2X_MUL(104, temp2, 52, g_sum+620+52, 52, p_01+312);
	gf2x_add(104, f_sum+932+0, 104, temp, 104, temp2);
	GF2X_MUL(104, temp, 52, f_sum+620+0, 52, p_00+312);
	GF2X_MUL(104, temp2, 52, g_sum+620+0, 52, p_01+312);
	gf2x_add(104, temp, 104, temp, 104, temp2);
	gf2x_add(52, f_sum+932, 52, f_sum+932, 52, temp+52);
	right_bit_shift_n(104, f_sum+932, 51);
	GF2X_MUL(104, temp, 52, f_sum+620+52, 52, p_10+312);
	GF2X_MUL(104, temp2, 52, g_sum+620+52, 52, p_11+312);
	gf2x_add(104, g_sum+932+0, 104, temp, 104, temp2);
	GF2X_MUL(104, temp, 52, f_sum+620+0, 52, p_10+312);
	GF2X_MUL(104, temp2, 52, g_sum+620+0, 52, p_11+312);
	gf2x_add(104, temp, 104, temp, 104, temp2);
	gf2x_add(52, g_sum+932, 52, g_sum+932, 52, temp+52);
	right_bit_shift_n(104, g_sum+932, 51);
	

	delta = divstepsx_256(255, delta, f_sum+981, g_sum+981, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+977+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+977+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+977+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+977+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+977+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+977+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+977+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+977+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+969+8, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+969+8, 8, p_01+408);
	gf2x_add(16, f_sum+1215+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+969+0, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+969+0, 8, p_01+408);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1215, 8, f_sum+1215, 8, temp+8);
	right_bit_shift_n(16, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+969+8, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+969+8, 8, p_11+408);
	gf2x_add(16, g_sum+1215+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+969+0, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+969+0, 8, p_11+408);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1215, 8, g_sum+1215, 8, temp+8);
	right_bit_shift_n(16, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1220, g_sum+1220, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1216+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1216+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1216+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1216+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, q_00+395+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, q_01+395+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, q_10+395+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, q_11+395+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+395+0, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, q_01+395+0, 8, p_10+408);
	gf2x_add(16, p_00+392+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+395+0, 8, p_01+408);
	GF2X_MUL(16, temp2, 8, q_01+395+0, 8, p_11+408);
	gf2x_add(16, p_01+392+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+395+0, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, q_11+395+0, 8, p_10+408);
	gf2x_add(16, p_10+392+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+395+0, 8, p_01+408);
	GF2X_MUL(16, temp2, 8, q_11+395+0, 8, p_11+408);
	gf2x_add(16, p_11+392+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+957+12, 16, p_00+392);
	GF2X_MUL(32, temp2, 16, g_sum+957+12, 16, p_01+392);
	gf2x_add(28, f_sum+1170, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+392+4, 12, f_sum+957);
	GF2X_MUL(24, temp2, 12, p_01+392+4, 12, g_sum+957);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1170, 12, f_sum+1170, 12, temp+12);
	right_bit_shift_n(28, f_sum+1170, 60);
	GF2X_MUL(32, temp, 16, f_sum+957+12, 16, p_10+392);
	GF2X_MUL(32, temp2, 16, g_sum+957+12, 16, p_11+392);
	gf2x_add(28, g_sum+1170, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+392+4, 12, f_sum+957);
	GF2X_MUL(24, temp2, 12, p_11+392+4, 12, g_sum+957);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1170, 12, g_sum+1170, 12, temp+12);
	right_bit_shift_n(28, g_sum+1170, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1179, g_sum+1179, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_01+408);
	gf2x_add(12, f_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_01+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1215, 4, f_sum+1215, 4, temp+4);
	right_bit_shift_n(12, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_11+408);
	gf2x_add(12, g_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1215, 4, g_sum+1215, 4, temp+4);
	right_bit_shift_n(12, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1216, g_sum+1216, q_00+395, q_01+395, q_10+395, q_11+395);

	// Recombining results: n: 765, depth: 5
	memset(q_00+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_01+395);
	gf2x_add(8, q_00+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+383+0, 8, q_00+383+0, 8, temp);
	memset(q_01+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_01+395);
	gf2x_add(8, q_01+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+383+0, 8, q_01+383+0, 8, temp);
	memset(q_10+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_11+395);
	gf2x_add(8, q_10+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+383+0, 8, q_10+383+0, 8, temp);
	memset(q_11+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_11+395);
	gf2x_add(8, q_11+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+383+0, 8, q_11+383+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 4
	memset(p_00+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+392+4, 12, q_00+383);
	GF2X_MUL(24, temp2, 12, p_10+392+4, 12, q_01+383);
	gf2x_add(24, p_00+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+383+8, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_01+383+8, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+364+8, 8, p_00+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+4, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_01+383+4, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+364+4, 8, p_00+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+0, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_01+383+0, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+364+0, 8, p_00+364+0, 8, temp);
	memset(p_01+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+392+4, 12, q_00+383);
	GF2X_MUL(24, temp2, 12, p_11+392+4, 12, q_01+383);
	gf2x_add(24, p_01+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+383+8, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_01+383+8, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+364+8, 8, p_01+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+4, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_01+383+4, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+364+4, 8, p_01+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+0, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_01+383+0, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+364+0, 8, p_01+364+0, 8, temp);
	memset(p_10+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+392+4, 12, q_10+383);
	GF2X_MUL(24, temp2, 12, p_10+392+4, 12, q_11+383);
	gf2x_add(24, p_10+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+383+8, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_11+383+8, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+364+8, 8, p_10+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+4, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_11+383+4, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+364+4, 8, p_10+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+0, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_11+383+0, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+364+0, 8, p_10+364+0, 8, temp);
	memset(p_11+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+392+4, 12, q_10+383);
	GF2X_MUL(24, temp2, 12, p_11+392+4, 12, q_11+383);
	gf2x_add(24, p_11+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+383+8, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_11+383+8, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+364+8, 8, p_11+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+4, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_11+383+4, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+364+4, 8, p_11+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+0, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_11+383+0, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+364+0, 8, p_11+364+0, 8, temp);
	

	// Calculating left operands: n: 3315, depth: 3
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+933+24, 28, p_00+364);
	GF2X_MUL(56, temp2, 28, g_sum+933+24, 28, p_01+364);
	gf2x_add(52, f_sum+1089, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_00+364+4, 24, f_sum+933);
	GF2X_MUL(48, temp2, 24, p_01+364+4, 24, g_sum+933);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+1089, 24, f_sum+1089, 24, temp+24);
	right_bit_shift_n(52, f_sum+1089, 57);
	GF2X_MUL(56, temp, 28, f_sum+933+24, 28, p_10+364);
	GF2X_MUL(56, temp2, 28, g_sum+933+24, 28, p_11+364);
	gf2x_add(52, g_sum+1089, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_10+364+4, 24, f_sum+933);
	GF2X_MUL(48, temp2, 24, p_11+364+4, 24, g_sum+933);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+1089, 24, g_sum+1089, 24, temp+24);
	right_bit_shift_n(52, g_sum+1089, 57);
	

	delta = divstepsx_256(255, delta, f_sum+1110, g_sum+1110, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1106+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1106+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1106+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1106+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1102+4, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+1102+4, 8, p_01+408);
	gf2x_add(12, f_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, f_sum+1102);
	GF2X_MUL(8, temp2, 4, p_01+408+4, 4, g_sum+1102);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1215, 4, f_sum+1215, 4, temp+4);
	right_bit_shift_n(12, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+1102+4, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+1102+4, 8, p_11+408);
	gf2x_add(12, g_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+408+4, 4, f_sum+1102);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, g_sum+1102);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1215, 4, g_sum+1215, 4, temp+4);
	right_bit_shift_n(12, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1216, g_sum+1216, q_00+395, q_01+395, q_10+395, q_11+395);

	// Recombining results: n: 765, depth: 5
	memset(p_00+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_01+395);
	gf2x_add(8, p_00+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+392+0, 8, p_00+392+0, 8, temp);
	memset(p_01+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_01+395);
	gf2x_add(8, p_01+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+392+0, 8, p_01+392+0, 8, temp);
	memset(p_10+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_11+395);
	gf2x_add(8, p_10+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+392+0, 8, p_10+392+0, 8, temp);
	memset(p_11+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_11+395);
	gf2x_add(8, p_11+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+392+0, 8, p_11+392+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1090+12, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+12, 12, p_01+392);
	gf2x_add(24, f_sum+1170+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1090+0, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+0, 12, p_01+392);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1170, 12, f_sum+1170, 12, temp+12);
	right_bit_shift_n(24, f_sum+1170, 61);
	GF2X_MUL(24, temp, 12, f_sum+1090+12, 12, p_10+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+12, 12, p_11+392);
	gf2x_add(24, g_sum+1170+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1090+0, 12, p_10+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+0, 12, p_11+392);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1170, 12, g_sum+1170, 12, temp+12);
	right_bit_shift_n(24, g_sum+1170, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1179, g_sum+1179, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_01+408);
	gf2x_add(12, f_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_01+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1215, 4, f_sum+1215, 4, temp+4);
	right_bit_shift_n(12, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_11+408);
	gf2x_add(12, g_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1215, 4, g_sum+1215, 4, temp+4);
	right_bit_shift_n(12, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1216, g_sum+1216, q_00+395, q_01+395, q_10+395, q_11+395);

	// Recombining results: n: 765, depth: 5
	memset(q_00+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_01+395);
	gf2x_add(8, q_00+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+383+0, 8, q_00+383+0, 8, temp);
	memset(q_01+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_01+395);
	gf2x_add(8, q_01+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+383+0, 8, q_01+383+0, 8, temp);
	memset(q_10+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_11+395);
	gf2x_add(8, q_10+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+383+0, 8, q_10+383+0, 8, temp);
	memset(q_11+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_11+395);
	gf2x_add(8, q_11+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+383+0, 8, q_11+383+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 4
	GF2X_MUL(24, temp, 12, q_00+383+0, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, q_01+383+0, 12, p_10+392);
	gf2x_add(24, q_00+359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+383+0, 12, p_01+392);
	GF2X_MUL(24, temp2, 12, q_01+383+0, 12, p_11+392);
	gf2x_add(24, q_01+359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+383+0, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, q_11+383+0, 12, p_10+392);
	gf2x_add(24, q_10+359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+383+0, 12, p_01+392);
	GF2X_MUL(24, temp2, 12, q_11+383+0, 12, p_11+392);
	gf2x_add(24, q_11+359+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3315, depth: 3
	memset(q_00+307, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+364+4, 24, q_00+359);
	GF2X_MUL(48, temp2, 24, p_10+364+4, 24, q_01+359);
	gf2x_add(48, q_00+307+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+359+20, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+20, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+307+20, 8, q_00+307+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+16, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+16, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+307+16, 8, q_00+307+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+12, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+12, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+307+12, 8, q_00+307+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+8, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+8, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+307+8, 8, q_00+307+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+4, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+4, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+307+4, 8, q_00+307+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+0, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+0, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+307+0, 8, q_00+307+0, 8, temp);
	memset(q_01+307, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+364+4, 24, q_00+359);
	GF2X_MUL(48, temp2, 24, p_11+364+4, 24, q_01+359);
	gf2x_add(48, q_01+307+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+359+20, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+20, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+307+20, 8, q_01+307+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+16, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+16, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+307+16, 8, q_01+307+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+12, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+12, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+307+12, 8, q_01+307+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+8, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+8, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+307+8, 8, q_01+307+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+4, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+4, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+307+4, 8, q_01+307+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+0, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+0, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+307+0, 8, q_01+307+0, 8, temp);
	memset(q_10+307, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+364+4, 24, q_10+359);
	GF2X_MUL(48, temp2, 24, p_10+364+4, 24, q_11+359);
	gf2x_add(48, q_10+307+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+359+20, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+20, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+307+20, 8, q_10+307+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+16, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+16, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+307+16, 8, q_10+307+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+12, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+12, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+307+12, 8, q_10+307+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+8, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+8, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+307+8, 8, q_10+307+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+4, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+4, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+307+4, 8, q_10+307+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+0, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+0, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+307+0, 8, q_10+307+0, 8, temp);
	memset(q_11+307, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+364+4, 24, q_10+359);
	GF2X_MUL(48, temp2, 24, p_11+364+4, 24, q_11+359);
	gf2x_add(48, q_11+307+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+359+20, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+20, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+307+20, 8, q_11+307+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+16, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+16, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+307+16, 8, q_11+307+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+12, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+12, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+307+12, 8, q_11+307+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+8, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+8, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+307+8, 8, q_11+307+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+4, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+4, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+307+4, 8, q_11+307+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+0, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+0, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+307+0, 8, q_11+307+0, 8, temp);
	

	// Recombining results: n: 6630, depth: 2
	GF2X_MUL(104, temp, 52, q_00+307+0, 52, p_00+312);
	GF2X_MUL(104, temp2, 52, q_01+307+0, 52, p_10+312);
	gf2x_add(104, q_00+203+0, 104, temp, 104, temp2);
	GF2X_MUL(104, temp, 52, q_00+307+0, 52, p_01+312);
	GF2X_MUL(104, temp2, 52, q_01+307+0, 52, p_11+312);
	gf2x_add(104, q_01+203+0, 104, temp, 104, temp2);
	GF2X_MUL(104, temp, 52, q_10+307+0, 52, p_00+312);
	GF2X_MUL(104, temp2, 52, q_11+307+0, 52, p_10+312);
	gf2x_add(104, q_10+203+0, 104, temp, 104, temp2);
	GF2X_MUL(104, temp, 52, q_10+307+0, 52, p_01+312);
	GF2X_MUL(104, temp2, 52, q_11+307+0, 52, p_11+312);
	gf2x_add(104, q_11+203+0, 104, temp, 104, temp2);
	

	// Recombining results: n: 13260, depth: 1
	GF2X_MUL(208, temp, 104, q_00+203+0, 104, p_00+208);
	GF2X_MUL(208, temp2, 104, q_01+203+0, 104, p_10+208);
	gf2x_add(208, p_00+0+0, 208, temp, 208, temp2);
	GF2X_MUL(208, temp, 104, q_00+203+0, 104, p_01+208);
	GF2X_MUL(208, temp2, 104, q_01+203+0, 104, p_11+208);
	gf2x_add(208, p_01+0+0, 208, temp, 208, temp2);
	GF2X_MUL(208, temp, 104, q_10+203+0, 104, p_00+208);
	GF2X_MUL(208, temp2, 104, q_11+203+0, 104, p_10+208);
	gf2x_add(208, p_10+0+0, 208, temp, 208, temp2);
	GF2X_MUL(208, temp, 104, q_10+203+0, 104, p_01+208);
	GF2X_MUL(208, temp2, 104, q_11+203+0, 104, p_11+208);
	gf2x_add(208, p_11+0+0, 208, temp, 208, temp2);
	

	// Calculating left operands: n: 26217, depth: 0
	// Digits to shift: 207
	// Displacement: 207
	GF2X_MUL(416, temp, 208, f+0+202, 208, p_00+0);
	GF2X_MUL(416, temp2, 208, g+0+202, 208, p_01+0);
	gf2x_add(411, f_sum+0, 411, temp+5, 411, temp2+5);
	GF2X_MUL(404, temp, 202, p_00+0+6, 202, f+0);
	GF2X_MUL(404, temp2, 202, p_01+0+6, 202, g+0);
	gf2x_add(404, temp, 404, temp, 404, temp2);
	gf2x_add(203, f_sum+0, 203, f_sum+0, 203, temp+201);
	GF2X_MUL(12, temp, 6, f+0+196, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, g+0+196, 6, p_01+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(1, f_sum+0, 1, f_sum+0, 1, temp+11);
	right_bit_shift_n(410, f_sum+0, 12);
	GF2X_MUL(416, temp, 208, f+0+202, 208, p_10+0);
	GF2X_MUL(416, temp2, 208, g+0+202, 208, p_11+0);
	gf2x_add(411, g_sum+0, 411, temp+5, 411, temp2+5);
	GF2X_MUL(404, temp, 202, p_10+0+6, 202, f+0);
	GF2X_MUL(404, temp2, 202, p_11+0+6, 202, g+0);
	gf2x_add(404, temp, 404, temp, 404, temp2);
	gf2x_add(203, g_sum+0, 203, g_sum+0, 203, temp+201);
	GF2X_MUL(12, temp, 6, f+0+196, 6, p_10+0);
	GF2X_MUL(12, temp2, 6, g+0+196, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(1, g_sum+0, 1, g_sum+0, 1, temp+11);
	right_bit_shift_n(410, g_sum+0, 12);
	

	delta = divstepsx_256(255, delta, f_sum+200, g_sum+200, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+196+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+196+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+196+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+196+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+196+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+196+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+196+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+196+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+188+8, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+188+8, 8, p_01+408);
	gf2x_add(16, f_sum+1215+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+188+0, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+188+0, 8, p_01+408);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1215, 8, f_sum+1215, 8, temp+8);
	right_bit_shift_n(16, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+188+8, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+188+8, 8, p_11+408);
	gf2x_add(16, g_sum+1215+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+188+0, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+188+0, 8, p_11+408);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1215, 8, g_sum+1215, 8, temp+8);
	right_bit_shift_n(16, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1220, g_sum+1220, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1216+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1216+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1216+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1216+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, q_00+395+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, q_01+395+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, q_10+395+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, q_11+395+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+395+0, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, q_01+395+0, 8, p_10+408);
	gf2x_add(16, p_00+392+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+395+0, 8, p_01+408);
	GF2X_MUL(16, temp2, 8, q_01+395+0, 8, p_11+408);
	gf2x_add(16, p_01+392+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+395+0, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, q_11+395+0, 8, p_10+408);
	gf2x_add(16, p_10+392+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+395+0, 8, p_01+408);
	GF2X_MUL(16, temp2, 8, q_11+395+0, 8, p_11+408);
	gf2x_add(16, p_11+392+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+176+12, 16, p_00+392);
	GF2X_MUL(32, temp2, 16, g_sum+176+12, 16, p_01+392);
	gf2x_add(28, f_sum+1170, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+392+4, 12, f_sum+176);
	GF2X_MUL(24, temp2, 12, p_01+392+4, 12, g_sum+176);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1170, 12, f_sum+1170, 12, temp+12);
	right_bit_shift_n(28, f_sum+1170, 60);
	GF2X_MUL(32, temp, 16, f_sum+176+12, 16, p_10+392);
	GF2X_MUL(32, temp2, 16, g_sum+176+12, 16, p_11+392);
	gf2x_add(28, g_sum+1170, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+392+4, 12, f_sum+176);
	GF2X_MUL(24, temp2, 12, p_11+392+4, 12, g_sum+176);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1170, 12, g_sum+1170, 12, temp+12);
	right_bit_shift_n(28, g_sum+1170, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1179, g_sum+1179, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_01+408);
	gf2x_add(12, f_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_01+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1215, 4, f_sum+1215, 4, temp+4);
	right_bit_shift_n(12, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_11+408);
	gf2x_add(12, g_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1215, 4, g_sum+1215, 4, temp+4);
	right_bit_shift_n(12, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1216, g_sum+1216, q_00+395, q_01+395, q_10+395, q_11+395);

	// Recombining results: n: 765, depth: 5
	memset(q_00+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_01+395);
	gf2x_add(8, q_00+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+383+0, 8, q_00+383+0, 8, temp);
	memset(q_01+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_01+395);
	gf2x_add(8, q_01+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+383+0, 8, q_01+383+0, 8, temp);
	memset(q_10+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_11+395);
	gf2x_add(8, q_10+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+383+0, 8, q_10+383+0, 8, temp);
	memset(q_11+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_11+395);
	gf2x_add(8, q_11+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+383+0, 8, q_11+383+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 4
	memset(p_00+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+392+4, 12, q_00+383);
	GF2X_MUL(24, temp2, 12, p_10+392+4, 12, q_01+383);
	gf2x_add(24, p_00+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+383+8, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_01+383+8, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+364+8, 8, p_00+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+4, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_01+383+4, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+364+4, 8, p_00+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+0, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_01+383+0, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+364+0, 8, p_00+364+0, 8, temp);
	memset(p_01+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+392+4, 12, q_00+383);
	GF2X_MUL(24, temp2, 12, p_11+392+4, 12, q_01+383);
	gf2x_add(24, p_01+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+383+8, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_01+383+8, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+364+8, 8, p_01+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+4, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_01+383+4, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+364+4, 8, p_01+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+0, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_01+383+0, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+364+0, 8, p_01+364+0, 8, temp);
	memset(p_10+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+392+4, 12, q_10+383);
	GF2X_MUL(24, temp2, 12, p_10+392+4, 12, q_11+383);
	gf2x_add(24, p_10+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+383+8, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_11+383+8, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+364+8, 8, p_10+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+4, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_11+383+4, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+364+4, 8, p_10+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+0, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_11+383+0, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+364+0, 8, p_10+364+0, 8, temp);
	memset(p_11+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+392+4, 12, q_10+383);
	GF2X_MUL(24, temp2, 12, p_11+392+4, 12, q_11+383);
	gf2x_add(24, p_11+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+383+8, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_11+383+8, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+364+8, 8, p_11+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+4, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_11+383+4, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+364+4, 8, p_11+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+0, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_11+383+0, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+364+0, 8, p_11+364+0, 8, temp);
	

	// Calculating left operands: n: 3315, depth: 3
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+152+24, 28, p_00+364);
	GF2X_MUL(56, temp2, 28, g_sum+152+24, 28, p_01+364);
	gf2x_add(52, f_sum+1089, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_00+364+4, 24, f_sum+152);
	GF2X_MUL(48, temp2, 24, p_01+364+4, 24, g_sum+152);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+1089, 24, f_sum+1089, 24, temp+24);
	right_bit_shift_n(52, f_sum+1089, 57);
	GF2X_MUL(56, temp, 28, f_sum+152+24, 28, p_10+364);
	GF2X_MUL(56, temp2, 28, g_sum+152+24, 28, p_11+364);
	gf2x_add(52, g_sum+1089, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_10+364+4, 24, f_sum+152);
	GF2X_MUL(48, temp2, 24, p_11+364+4, 24, g_sum+152);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+1089, 24, g_sum+1089, 24, temp+24);
	right_bit_shift_n(52, g_sum+1089, 57);
	

	delta = divstepsx_256(255, delta, f_sum+1110, g_sum+1110, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1106+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1106+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1106+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1106+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1102+4, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+1102+4, 8, p_01+408);
	gf2x_add(12, f_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, f_sum+1102);
	GF2X_MUL(8, temp2, 4, p_01+408+4, 4, g_sum+1102);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1215, 4, f_sum+1215, 4, temp+4);
	right_bit_shift_n(12, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+1102+4, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+1102+4, 8, p_11+408);
	gf2x_add(12, g_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+408+4, 4, f_sum+1102);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, g_sum+1102);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1215, 4, g_sum+1215, 4, temp+4);
	right_bit_shift_n(12, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1216, g_sum+1216, q_00+395, q_01+395, q_10+395, q_11+395);

	// Recombining results: n: 765, depth: 5
	memset(p_00+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_01+395);
	gf2x_add(8, p_00+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+392+0, 8, p_00+392+0, 8, temp);
	memset(p_01+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_01+395);
	gf2x_add(8, p_01+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+392+0, 8, p_01+392+0, 8, temp);
	memset(p_10+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_11+395);
	gf2x_add(8, p_10+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+392+0, 8, p_10+392+0, 8, temp);
	memset(p_11+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_11+395);
	gf2x_add(8, p_11+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+392+0, 8, p_11+392+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1090+12, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+12, 12, p_01+392);
	gf2x_add(24, f_sum+1170+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1090+0, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+0, 12, p_01+392);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1170, 12, f_sum+1170, 12, temp+12);
	right_bit_shift_n(24, f_sum+1170, 61);
	GF2X_MUL(24, temp, 12, f_sum+1090+12, 12, p_10+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+12, 12, p_11+392);
	gf2x_add(24, g_sum+1170+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1090+0, 12, p_10+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+0, 12, p_11+392);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1170, 12, g_sum+1170, 12, temp+12);
	right_bit_shift_n(24, g_sum+1170, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1179, g_sum+1179, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_01+408);
	gf2x_add(12, f_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_01+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1215, 4, f_sum+1215, 4, temp+4);
	right_bit_shift_n(12, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_11+408);
	gf2x_add(12, g_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1215, 4, g_sum+1215, 4, temp+4);
	right_bit_shift_n(12, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1216, g_sum+1216, q_00+395, q_01+395, q_10+395, q_11+395);

	// Recombining results: n: 765, depth: 5
	memset(q_00+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_01+395);
	gf2x_add(8, q_00+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+383+0, 8, q_00+383+0, 8, temp);
	memset(q_01+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_01+395);
	gf2x_add(8, q_01+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+383+0, 8, q_01+383+0, 8, temp);
	memset(q_10+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_11+395);
	gf2x_add(8, q_10+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+383+0, 8, q_10+383+0, 8, temp);
	memset(q_11+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_11+395);
	gf2x_add(8, q_11+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+383+0, 8, q_11+383+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 4
	GF2X_MUL(24, temp, 12, q_00+383+0, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, q_01+383+0, 12, p_10+392);
	gf2x_add(24, q_00+359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+383+0, 12, p_01+392);
	GF2X_MUL(24, temp2, 12, q_01+383+0, 12, p_11+392);
	gf2x_add(24, q_01+359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+383+0, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, q_11+383+0, 12, p_10+392);
	gf2x_add(24, q_10+359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+383+0, 12, p_01+392);
	GF2X_MUL(24, temp2, 12, q_11+383+0, 12, p_11+392);
	gf2x_add(24, q_11+359+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3315, depth: 3
	memset(p_00+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+364+4, 24, q_00+359);
	GF2X_MUL(48, temp2, 24, p_10+364+4, 24, q_01+359);
	gf2x_add(48, p_00+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+359+20, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+20, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+312+20, 8, p_00+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+16, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+16, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+312+16, 8, p_00+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+12, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+12, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+312+12, 8, p_00+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+8, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+8, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+312+8, 8, p_00+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+4, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+4, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+312+4, 8, p_00+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+0, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+0, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+312+0, 8, p_00+312+0, 8, temp);
	memset(p_01+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+364+4, 24, q_00+359);
	GF2X_MUL(48, temp2, 24, p_11+364+4, 24, q_01+359);
	gf2x_add(48, p_01+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+359+20, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+20, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+312+20, 8, p_01+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+16, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+16, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+312+16, 8, p_01+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+12, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+12, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+312+12, 8, p_01+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+8, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+8, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+312+8, 8, p_01+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+4, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+4, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+312+4, 8, p_01+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+0, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+0, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+312+0, 8, p_01+312+0, 8, temp);
	memset(p_10+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+364+4, 24, q_10+359);
	GF2X_MUL(48, temp2, 24, p_10+364+4, 24, q_11+359);
	gf2x_add(48, p_10+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+359+20, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+20, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+312+20, 8, p_10+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+16, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+16, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+312+16, 8, p_10+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+12, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+12, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+312+12, 8, p_10+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+8, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+8, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+312+8, 8, p_10+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+4, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+4, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+312+4, 8, p_10+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+0, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+0, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+312+0, 8, p_10+312+0, 8, temp);
	memset(p_11+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+364+4, 24, q_10+359);
	GF2X_MUL(48, temp2, 24, p_11+364+4, 24, q_11+359);
	gf2x_add(48, p_11+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+359+20, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+20, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+312+20, 8, p_11+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+16, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+16, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+312+16, 8, p_11+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+12, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+12, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+312+12, 8, p_11+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+8, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+8, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+312+8, 8, p_11+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+4, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+4, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+312+4, 8, p_11+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+0, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+0, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+312+0, 8, p_11+312+0, 8, temp);
	

	// Calculating left operands: n: 6630, depth: 2
	// Digits to shift: 51
	// Displacement: 52
	GF2X_MUL(104, temp, 52, f_sum+100+52, 52, p_00+312);
	GF2X_MUL(104, temp2, 52, g_sum+100+52, 52, p_01+312);
	gf2x_add(104, f_sum+932+0, 104, temp, 104, temp2);
	GF2X_MUL(104, temp, 52, f_sum+100+0, 52, p_00+312);
	GF2X_MUL(104, temp2, 52, g_sum+100+0, 52, p_01+312);
	gf2x_add(104, temp, 104, temp, 104, temp2);
	gf2x_add(52, f_sum+932, 52, f_sum+932, 52, temp+52);
	right_bit_shift_n(104, f_sum+932, 51);
	GF2X_MUL(104, temp, 52, f_sum+100+52, 52, p_10+312);
	GF2X_MUL(104, temp2, 52, g_sum+100+52, 52, p_11+312);
	gf2x_add(104, g_sum+932+0, 104, temp, 104, temp2);
	GF2X_MUL(104, temp, 52, f_sum+100+0, 52, p_10+312);
	GF2X_MUL(104, temp2, 52, g_sum+100+0, 52, p_11+312);
	gf2x_add(104, temp, 104, temp, 104, temp2);
	gf2x_add(52, g_sum+932, 52, g_sum+932, 52, temp+52);
	right_bit_shift_n(104, g_sum+932, 51);
	

	delta = divstepsx_256(255, delta, f_sum+981, g_sum+981, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+977+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+977+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+977+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+977+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+977+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+977+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+977+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+977+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+969+8, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+969+8, 8, p_01+408);
	gf2x_add(16, f_sum+1215+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+969+0, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+969+0, 8, p_01+408);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1215, 8, f_sum+1215, 8, temp+8);
	right_bit_shift_n(16, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+969+8, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+969+8, 8, p_11+408);
	gf2x_add(16, g_sum+1215+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+969+0, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+969+0, 8, p_11+408);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1215, 8, g_sum+1215, 8, temp+8);
	right_bit_shift_n(16, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1220, g_sum+1220, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1216+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1216+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1216+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1216+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, q_00+395+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, q_01+395+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, q_10+395+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, q_11+395+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+395+0, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, q_01+395+0, 8, p_10+408);
	gf2x_add(16, p_00+392+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+395+0, 8, p_01+408);
	GF2X_MUL(16, temp2, 8, q_01+395+0, 8, p_11+408);
	gf2x_add(16, p_01+392+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+395+0, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, q_11+395+0, 8, p_10+408);
	gf2x_add(16, p_10+392+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+395+0, 8, p_01+408);
	GF2X_MUL(16, temp2, 8, q_11+395+0, 8, p_11+408);
	gf2x_add(16, p_11+392+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+957+12, 16, p_00+392);
	GF2X_MUL(32, temp2, 16, g_sum+957+12, 16, p_01+392);
	gf2x_add(28, f_sum+1170, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+392+4, 12, f_sum+957);
	GF2X_MUL(24, temp2, 12, p_01+392+4, 12, g_sum+957);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1170, 12, f_sum+1170, 12, temp+12);
	right_bit_shift_n(28, f_sum+1170, 60);
	GF2X_MUL(32, temp, 16, f_sum+957+12, 16, p_10+392);
	GF2X_MUL(32, temp2, 16, g_sum+957+12, 16, p_11+392);
	gf2x_add(28, g_sum+1170, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+392+4, 12, f_sum+957);
	GF2X_MUL(24, temp2, 12, p_11+392+4, 12, g_sum+957);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1170, 12, g_sum+1170, 12, temp+12);
	right_bit_shift_n(28, g_sum+1170, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1179, g_sum+1179, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_01+408);
	gf2x_add(12, f_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_01+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1215, 4, f_sum+1215, 4, temp+4);
	right_bit_shift_n(12, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_11+408);
	gf2x_add(12, g_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1215, 4, g_sum+1215, 4, temp+4);
	right_bit_shift_n(12, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1216, g_sum+1216, q_00+395, q_01+395, q_10+395, q_11+395);

	// Recombining results: n: 765, depth: 5
	memset(q_00+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_01+395);
	gf2x_add(8, q_00+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+383+0, 8, q_00+383+0, 8, temp);
	memset(q_01+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_01+395);
	gf2x_add(8, q_01+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+383+0, 8, q_01+383+0, 8, temp);
	memset(q_10+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_11+395);
	gf2x_add(8, q_10+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+383+0, 8, q_10+383+0, 8, temp);
	memset(q_11+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_11+395);
	gf2x_add(8, q_11+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+383+0, 8, q_11+383+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 4
	memset(p_00+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+392+4, 12, q_00+383);
	GF2X_MUL(24, temp2, 12, p_10+392+4, 12, q_01+383);
	gf2x_add(24, p_00+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+383+8, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_01+383+8, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+364+8, 8, p_00+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+4, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_01+383+4, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+364+4, 8, p_00+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+0, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_01+383+0, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+364+0, 8, p_00+364+0, 8, temp);
	memset(p_01+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+392+4, 12, q_00+383);
	GF2X_MUL(24, temp2, 12, p_11+392+4, 12, q_01+383);
	gf2x_add(24, p_01+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+383+8, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_01+383+8, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+364+8, 8, p_01+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+4, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_01+383+4, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+364+4, 8, p_01+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+0, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_01+383+0, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+364+0, 8, p_01+364+0, 8, temp);
	memset(p_10+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+392+4, 12, q_10+383);
	GF2X_MUL(24, temp2, 12, p_10+392+4, 12, q_11+383);
	gf2x_add(24, p_10+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+383+8, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_11+383+8, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+364+8, 8, p_10+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+4, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_11+383+4, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+364+4, 8, p_10+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+0, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_11+383+0, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+364+0, 8, p_10+364+0, 8, temp);
	memset(p_11+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+392+4, 12, q_10+383);
	GF2X_MUL(24, temp2, 12, p_11+392+4, 12, q_11+383);
	gf2x_add(24, p_11+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+383+8, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_11+383+8, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+364+8, 8, p_11+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+4, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_11+383+4, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+364+4, 8, p_11+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+0, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_11+383+0, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+364+0, 8, p_11+364+0, 8, temp);
	

	// Calculating left operands: n: 3315, depth: 3
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+933+24, 28, p_00+364);
	GF2X_MUL(56, temp2, 28, g_sum+933+24, 28, p_01+364);
	gf2x_add(52, f_sum+1089, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_00+364+4, 24, f_sum+933);
	GF2X_MUL(48, temp2, 24, p_01+364+4, 24, g_sum+933);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+1089, 24, f_sum+1089, 24, temp+24);
	right_bit_shift_n(52, f_sum+1089, 57);
	GF2X_MUL(56, temp, 28, f_sum+933+24, 28, p_10+364);
	GF2X_MUL(56, temp2, 28, g_sum+933+24, 28, p_11+364);
	gf2x_add(52, g_sum+1089, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_10+364+4, 24, f_sum+933);
	GF2X_MUL(48, temp2, 24, p_11+364+4, 24, g_sum+933);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+1089, 24, g_sum+1089, 24, temp+24);
	right_bit_shift_n(52, g_sum+1089, 57);
	

	delta = divstepsx_256(255, delta, f_sum+1110, g_sum+1110, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1106+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1106+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1106+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1106+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1102+4, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+1102+4, 8, p_01+408);
	gf2x_add(12, f_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, f_sum+1102);
	GF2X_MUL(8, temp2, 4, p_01+408+4, 4, g_sum+1102);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1215, 4, f_sum+1215, 4, temp+4);
	right_bit_shift_n(12, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+1102+4, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+1102+4, 8, p_11+408);
	gf2x_add(12, g_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+408+4, 4, f_sum+1102);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, g_sum+1102);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1215, 4, g_sum+1215, 4, temp+4);
	right_bit_shift_n(12, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1216, g_sum+1216, q_00+395, q_01+395, q_10+395, q_11+395);

	// Recombining results: n: 765, depth: 5
	memset(p_00+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_01+395);
	gf2x_add(8, p_00+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+392+0, 8, p_00+392+0, 8, temp);
	memset(p_01+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_01+395);
	gf2x_add(8, p_01+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+392+0, 8, p_01+392+0, 8, temp);
	memset(p_10+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_11+395);
	gf2x_add(8, p_10+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+392+0, 8, p_10+392+0, 8, temp);
	memset(p_11+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_11+395);
	gf2x_add(8, p_11+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+392+0, 8, p_11+392+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1090+12, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+12, 12, p_01+392);
	gf2x_add(24, f_sum+1170+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1090+0, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+0, 12, p_01+392);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1170, 12, f_sum+1170, 12, temp+12);
	right_bit_shift_n(24, f_sum+1170, 61);
	GF2X_MUL(24, temp, 12, f_sum+1090+12, 12, p_10+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+12, 12, p_11+392);
	gf2x_add(24, g_sum+1170+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1090+0, 12, p_10+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+0, 12, p_11+392);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1170, 12, g_sum+1170, 12, temp+12);
	right_bit_shift_n(24, g_sum+1170, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1179, g_sum+1179, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_01+408);
	gf2x_add(12, f_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_01+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1215, 4, f_sum+1215, 4, temp+4);
	right_bit_shift_n(12, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_11+408);
	gf2x_add(12, g_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1215, 4, g_sum+1215, 4, temp+4);
	right_bit_shift_n(12, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1216, g_sum+1216, q_00+395, q_01+395, q_10+395, q_11+395);

	// Recombining results: n: 765, depth: 5
	memset(q_00+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_01+395);
	gf2x_add(8, q_00+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+383+0, 8, q_00+383+0, 8, temp);
	memset(q_01+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_01+395);
	gf2x_add(8, q_01+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+383+0, 8, q_01+383+0, 8, temp);
	memset(q_10+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_11+395);
	gf2x_add(8, q_10+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+383+0, 8, q_10+383+0, 8, temp);
	memset(q_11+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_11+395);
	gf2x_add(8, q_11+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+383+0, 8, q_11+383+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 4
	GF2X_MUL(24, temp, 12, q_00+383+0, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, q_01+383+0, 12, p_10+392);
	gf2x_add(24, q_00+359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+383+0, 12, p_01+392);
	GF2X_MUL(24, temp2, 12, q_01+383+0, 12, p_11+392);
	gf2x_add(24, q_01+359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+383+0, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, q_11+383+0, 12, p_10+392);
	gf2x_add(24, q_10+359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+383+0, 12, p_01+392);
	GF2X_MUL(24, temp2, 12, q_11+383+0, 12, p_11+392);
	gf2x_add(24, q_11+359+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3315, depth: 3
	memset(q_00+307, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+364+4, 24, q_00+359);
	GF2X_MUL(48, temp2, 24, p_10+364+4, 24, q_01+359);
	gf2x_add(48, q_00+307+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+359+20, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+20, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+307+20, 8, q_00+307+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+16, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+16, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+307+16, 8, q_00+307+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+12, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+12, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+307+12, 8, q_00+307+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+8, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+8, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+307+8, 8, q_00+307+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+4, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+4, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+307+4, 8, q_00+307+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+0, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+0, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+307+0, 8, q_00+307+0, 8, temp);
	memset(q_01+307, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+364+4, 24, q_00+359);
	GF2X_MUL(48, temp2, 24, p_11+364+4, 24, q_01+359);
	gf2x_add(48, q_01+307+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+359+20, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+20, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+307+20, 8, q_01+307+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+16, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+16, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+307+16, 8, q_01+307+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+12, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+12, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+307+12, 8, q_01+307+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+8, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+8, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+307+8, 8, q_01+307+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+4, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+4, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+307+4, 8, q_01+307+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+0, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+0, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+307+0, 8, q_01+307+0, 8, temp);
	memset(q_10+307, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+364+4, 24, q_10+359);
	GF2X_MUL(48, temp2, 24, p_10+364+4, 24, q_11+359);
	gf2x_add(48, q_10+307+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+359+20, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+20, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+307+20, 8, q_10+307+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+16, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+16, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+307+16, 8, q_10+307+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+12, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+12, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+307+12, 8, q_10+307+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+8, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+8, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+307+8, 8, q_10+307+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+4, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+4, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+307+4, 8, q_10+307+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+0, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+0, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+307+0, 8, q_10+307+0, 8, temp);
	memset(q_11+307, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+364+4, 24, q_10+359);
	GF2X_MUL(48, temp2, 24, p_11+364+4, 24, q_11+359);
	gf2x_add(48, q_11+307+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+359+20, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+20, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+307+20, 8, q_11+307+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+16, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+16, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+307+16, 8, q_11+307+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+12, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+12, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+307+12, 8, q_11+307+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+8, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+8, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+307+8, 8, q_11+307+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+4, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+4, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+307+4, 8, q_11+307+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+0, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+0, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+307+0, 8, q_11+307+0, 8, temp);
	

	// Recombining results: n: 6630, depth: 2
	GF2X_MUL(104, temp, 52, q_00+307+0, 52, p_00+312);
	GF2X_MUL(104, temp2, 52, q_01+307+0, 52, p_10+312);
	gf2x_add(104, p_00+208+0, 104, temp, 104, temp2);
	GF2X_MUL(104, temp, 52, q_00+307+0, 52, p_01+312);
	GF2X_MUL(104, temp2, 52, q_01+307+0, 52, p_11+312);
	gf2x_add(104, p_01+208+0, 104, temp, 104, temp2);
	GF2X_MUL(104, temp, 52, q_10+307+0, 52, p_00+312);
	GF2X_MUL(104, temp2, 52, q_11+307+0, 52, p_10+312);
	gf2x_add(104, p_10+208+0, 104, temp, 104, temp2);
	GF2X_MUL(104, temp, 52, q_10+307+0, 52, p_01+312);
	GF2X_MUL(104, temp2, 52, q_11+307+0, 52, p_11+312);
	gf2x_add(104, p_11+208+0, 104, temp, 104, temp2);
	

	// Calculating left operands: n: 12957, depth: 1
	// Digits to shift: 103
	// Displacement: 104
	GF2X_MUL(208, temp, 104, f_sum+1+99, 104, p_00+208);
	GF2X_MUL(208, temp2, 104, g_sum+1+99, 104, p_01+208);
	gf2x_add(203, f_sum+619, 203, temp+5, 203, temp2+5);
	GF2X_MUL(198, temp, 99, p_00+208+5, 99, f_sum+1);
	GF2X_MUL(198, temp2, 99, p_01+208+5, 99, g_sum+1);
	gf2x_add(198, temp, 198, temp, 198, temp2);
	gf2x_add(99, f_sum+619, 99, f_sum+619, 99, temp+99);
	right_bit_shift_n(203, f_sum+619, 38);
	GF2X_MUL(208, temp, 104, f_sum+1+99, 104, p_10+208);
	GF2X_MUL(208, temp2, 104, g_sum+1+99, 104, p_11+208);
	gf2x_add(203, g_sum+619, 203, temp+5, 203, temp2+5);
	GF2X_MUL(198, temp, 99, p_10+208+5, 99, f_sum+1);
	GF2X_MUL(198, temp2, 99, p_11+208+5, 99, g_sum+1);
	gf2x_add(198, temp, 198, temp, 198, temp2);
	gf2x_add(99, g_sum+619, 99, g_sum+619, 99, temp+99);
	right_bit_shift_n(203, g_sum+619, 38);
	

	delta = divstepsx_256(255, delta, f_sum+715, g_sum+715, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+711+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+711+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+711+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+711+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+711+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+711+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+711+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+711+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+703+8, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+703+8, 8, p_01+408);
	gf2x_add(16, f_sum+1215+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+703+0, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+703+0, 8, p_01+408);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1215, 8, f_sum+1215, 8, temp+8);
	right_bit_shift_n(16, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+703+8, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+703+8, 8, p_11+408);
	gf2x_add(16, g_sum+1215+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+703+0, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+703+0, 8, p_11+408);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1215, 8, g_sum+1215, 8, temp+8);
	right_bit_shift_n(16, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1220, g_sum+1220, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1216+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1216+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1216+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1216+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1216+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, q_00+395+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, q_01+395+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, q_10+395+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, q_11+395+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+395+0, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, q_01+395+0, 8, p_10+408);
	gf2x_add(16, p_00+392+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+395+0, 8, p_01+408);
	GF2X_MUL(16, temp2, 8, q_01+395+0, 8, p_11+408);
	gf2x_add(16, p_01+392+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+395+0, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, q_11+395+0, 8, p_10+408);
	gf2x_add(16, p_10+392+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+395+0, 8, p_01+408);
	GF2X_MUL(16, temp2, 8, q_11+395+0, 8, p_11+408);
	gf2x_add(16, p_11+392+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+691+12, 16, p_00+392);
	GF2X_MUL(32, temp2, 16, g_sum+691+12, 16, p_01+392);
	gf2x_add(28, f_sum+1170, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+392+4, 12, f_sum+691);
	GF2X_MUL(24, temp2, 12, p_01+392+4, 12, g_sum+691);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1170, 12, f_sum+1170, 12, temp+12);
	right_bit_shift_n(28, f_sum+1170, 60);
	GF2X_MUL(32, temp, 16, f_sum+691+12, 16, p_10+392);
	GF2X_MUL(32, temp2, 16, g_sum+691+12, 16, p_11+392);
	gf2x_add(28, g_sum+1170, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+392+4, 12, f_sum+691);
	GF2X_MUL(24, temp2, 12, p_11+392+4, 12, g_sum+691);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1170, 12, g_sum+1170, 12, temp+12);
	right_bit_shift_n(28, g_sum+1170, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1179, g_sum+1179, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_01+408);
	gf2x_add(12, f_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_01+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1215, 4, f_sum+1215, 4, temp+4);
	right_bit_shift_n(12, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_11+408);
	gf2x_add(12, g_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1215, 4, g_sum+1215, 4, temp+4);
	right_bit_shift_n(12, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1216, g_sum+1216, q_00+395, q_01+395, q_10+395, q_11+395);

	// Recombining results: n: 765, depth: 5
	memset(q_00+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_01+395);
	gf2x_add(8, q_00+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+383+0, 8, q_00+383+0, 8, temp);
	memset(q_01+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_01+395);
	gf2x_add(8, q_01+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+383+0, 8, q_01+383+0, 8, temp);
	memset(q_10+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_11+395);
	gf2x_add(8, q_10+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+383+0, 8, q_10+383+0, 8, temp);
	memset(q_11+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_11+395);
	gf2x_add(8, q_11+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+383+0, 8, q_11+383+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 4
	memset(p_00+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+392+4, 12, q_00+383);
	GF2X_MUL(24, temp2, 12, p_10+392+4, 12, q_01+383);
	gf2x_add(24, p_00+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+383+8, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_01+383+8, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+364+8, 8, p_00+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+4, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_01+383+4, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+364+4, 8, p_00+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+0, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_01+383+0, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+364+0, 8, p_00+364+0, 8, temp);
	memset(p_01+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+392+4, 12, q_00+383);
	GF2X_MUL(24, temp2, 12, p_11+392+4, 12, q_01+383);
	gf2x_add(24, p_01+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+383+8, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_01+383+8, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+364+8, 8, p_01+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+4, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_01+383+4, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+364+4, 8, p_01+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+383+0, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_01+383+0, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+364+0, 8, p_01+364+0, 8, temp);
	memset(p_10+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+392+4, 12, q_10+383);
	GF2X_MUL(24, temp2, 12, p_10+392+4, 12, q_11+383);
	gf2x_add(24, p_10+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+383+8, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_11+383+8, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+364+8, 8, p_10+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+4, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_11+383+4, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+364+4, 8, p_10+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+0, 4, p_00+392);
	GF2X_MUL(8, temp2, 4, q_11+383+0, 4, p_10+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+364+0, 8, p_10+364+0, 8, temp);
	memset(p_11+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+392+4, 12, q_10+383);
	GF2X_MUL(24, temp2, 12, p_11+392+4, 12, q_11+383);
	gf2x_add(24, p_11+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+383+8, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_11+383+8, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+364+8, 8, p_11+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+4, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_11+383+4, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+364+4, 8, p_11+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+383+0, 4, p_01+392);
	GF2X_MUL(8, temp2, 4, q_11+383+0, 4, p_11+392);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+364+0, 8, p_11+364+0, 8, temp);
	

	// Calculating left operands: n: 3315, depth: 3
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+667+24, 28, p_00+364);
	GF2X_MUL(56, temp2, 28, g_sum+667+24, 28, p_01+364);
	gf2x_add(52, f_sum+1089, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_00+364+4, 24, f_sum+667);
	GF2X_MUL(48, temp2, 24, p_01+364+4, 24, g_sum+667);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+1089, 24, f_sum+1089, 24, temp+24);
	right_bit_shift_n(52, f_sum+1089, 57);
	GF2X_MUL(56, temp, 28, f_sum+667+24, 28, p_10+364);
	GF2X_MUL(56, temp2, 28, g_sum+667+24, 28, p_11+364);
	gf2x_add(52, g_sum+1089, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_10+364+4, 24, f_sum+667);
	GF2X_MUL(48, temp2, 24, p_11+364+4, 24, g_sum+667);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+1089, 24, g_sum+1089, 24, temp+24);
	right_bit_shift_n(52, g_sum+1089, 57);
	

	delta = divstepsx_256(255, delta, f_sum+1110, g_sum+1110, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1106+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1106+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1106+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1106+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1102+4, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+1102+4, 8, p_01+408);
	gf2x_add(12, f_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, f_sum+1102);
	GF2X_MUL(8, temp2, 4, p_01+408+4, 4, g_sum+1102);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1215, 4, f_sum+1215, 4, temp+4);
	right_bit_shift_n(12, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+1102+4, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+1102+4, 8, p_11+408);
	gf2x_add(12, g_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+408+4, 4, f_sum+1102);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, g_sum+1102);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1215, 4, g_sum+1215, 4, temp+4);
	right_bit_shift_n(12, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1216, g_sum+1216, q_00+395, q_01+395, q_10+395, q_11+395);

	// Recombining results: n: 765, depth: 5
	memset(p_00+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_01+395);
	gf2x_add(8, p_00+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+392+0, 8, p_00+392+0, 8, temp);
	memset(p_01+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_01+395);
	gf2x_add(8, p_01+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+392+0, 8, p_01+392+0, 8, temp);
	memset(p_10+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_11+395);
	gf2x_add(8, p_10+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+392+0, 8, p_10+392+0, 8, temp);
	memset(p_11+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_11+395);
	gf2x_add(8, p_11+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+392+0, 8, p_11+392+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1090+12, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+12, 12, p_01+392);
	gf2x_add(24, f_sum+1170+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1090+0, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+0, 12, p_01+392);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1170, 12, f_sum+1170, 12, temp+12);
	right_bit_shift_n(24, f_sum+1170, 61);
	GF2X_MUL(24, temp, 12, f_sum+1090+12, 12, p_10+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+12, 12, p_11+392);
	gf2x_add(24, g_sum+1170+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1090+0, 12, p_10+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+0, 12, p_11+392);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1170, 12, g_sum+1170, 12, temp+12);
	right_bit_shift_n(24, g_sum+1170, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1179, g_sum+1179, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_01+408);
	gf2x_add(12, f_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_01+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1215, 4, f_sum+1215, 4, temp+4);
	right_bit_shift_n(12, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_11+408);
	gf2x_add(12, g_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1215, 4, g_sum+1215, 4, temp+4);
	right_bit_shift_n(12, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1216, g_sum+1216, q_00+395, q_01+395, q_10+395, q_11+395);

	// Recombining results: n: 765, depth: 5
	memset(q_00+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_01+395);
	gf2x_add(8, q_00+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+383+0, 8, q_00+383+0, 8, temp);
	memset(q_01+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_01+395);
	gf2x_add(8, q_01+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+383+0, 8, q_01+383+0, 8, temp);
	memset(q_10+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_11+395);
	gf2x_add(8, q_10+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+383+0, 8, q_10+383+0, 8, temp);
	memset(q_11+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_11+395);
	gf2x_add(8, q_11+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+383+0, 8, q_11+383+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 4
	GF2X_MUL(24, temp, 12, q_00+383+0, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, q_01+383+0, 12, p_10+392);
	gf2x_add(24, q_00+359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+383+0, 12, p_01+392);
	GF2X_MUL(24, temp2, 12, q_01+383+0, 12, p_11+392);
	gf2x_add(24, q_01+359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+383+0, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, q_11+383+0, 12, p_10+392);
	gf2x_add(24, q_10+359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+383+0, 12, p_01+392);
	GF2X_MUL(24, temp2, 12, q_11+383+0, 12, p_11+392);
	gf2x_add(24, q_11+359+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3315, depth: 3
	memset(p_00+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+364+4, 24, q_00+359);
	GF2X_MUL(48, temp2, 24, p_10+364+4, 24, q_01+359);
	gf2x_add(48, p_00+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+359+20, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+20, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+312+20, 8, p_00+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+16, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+16, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+312+16, 8, p_00+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+12, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+12, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+312+12, 8, p_00+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+8, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+8, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+312+8, 8, p_00+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+4, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+4, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+312+4, 8, p_00+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+0, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_01+359+0, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+312+0, 8, p_00+312+0, 8, temp);
	memset(p_01+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+364+4, 24, q_00+359);
	GF2X_MUL(48, temp2, 24, p_11+364+4, 24, q_01+359);
	gf2x_add(48, p_01+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+359+20, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+20, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+312+20, 8, p_01+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+16, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+16, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+312+16, 8, p_01+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+12, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+12, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+312+12, 8, p_01+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+8, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+8, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+312+8, 8, p_01+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+4, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+4, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+312+4, 8, p_01+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+359+0, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_01+359+0, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+312+0, 8, p_01+312+0, 8, temp);
	memset(p_10+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+364+4, 24, q_10+359);
	GF2X_MUL(48, temp2, 24, p_10+364+4, 24, q_11+359);
	gf2x_add(48, p_10+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+359+20, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+20, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+312+20, 8, p_10+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+16, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+16, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+312+16, 8, p_10+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+12, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+12, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+312+12, 8, p_10+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+8, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+8, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+312+8, 8, p_10+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+4, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+4, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+312+4, 8, p_10+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+0, 4, p_00+364);
	GF2X_MUL(8, temp2, 4, q_11+359+0, 4, p_10+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+312+0, 8, p_10+312+0, 8, temp);
	memset(p_11+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+364+4, 24, q_10+359);
	GF2X_MUL(48, temp2, 24, p_11+364+4, 24, q_11+359);
	gf2x_add(48, p_11+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+359+20, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+20, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+312+20, 8, p_11+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+16, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+16, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+312+16, 8, p_11+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+12, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+12, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+312+12, 8, p_11+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+8, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+8, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+312+8, 8, p_11+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+4, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+4, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+312+4, 8, p_11+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+359+0, 4, p_01+364);
	GF2X_MUL(8, temp2, 4, q_11+359+0, 4, p_11+364);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+312+0, 8, p_11+312+0, 8, temp);
	

	// Calculating left operands: n: 6327, depth: 2
	// Digits to shift: 51
	// Displacement: 51
	GF2X_MUL(104, temp, 52, f_sum+620+47, 52, p_00+312);
	GF2X_MUL(104, temp2, 52, g_sum+620+47, 52, p_01+312);
	gf2x_add(100, f_sum+932, 100, temp+4, 100, temp2+4);
	GF2X_MUL(94, temp, 47, p_00+312+5, 47, f_sum+620);
	GF2X_MUL(94, temp2, 47, p_01+312+5, 47, g_sum+620);
	gf2x_add(94, temp, 94, temp, 94, temp2);
	gf2x_add(48, f_sum+932, 48, f_sum+932, 48, temp+46);
	GF2X_MUL(10, temp, 5, f_sum+620+42, 5, p_00+312);
	GF2X_MUL(10, temp2, 5, g_sum+620+42, 5, p_01+312);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(1, f_sum+932, 1, f_sum+932, 1, temp+9);
	right_bit_shift_n(99, f_sum+932, 51);
	GF2X_MUL(104, temp, 52, f_sum+620+47, 52, p_10+312);
	GF2X_MUL(104, temp2, 52, g_sum+620+47, 52, p_11+312);
	gf2x_add(100, g_sum+932, 100, temp+4, 100, temp2+4);
	GF2X_MUL(94, temp, 47, p_10+312+5, 47, f_sum+620);
	GF2X_MUL(94, temp2, 47, p_11+312+5, 47, g_sum+620);
	gf2x_add(94, temp, 94, temp, 94, temp2);
	gf2x_add(48, g_sum+932, 48, g_sum+932, 48, temp+46);
	GF2X_MUL(10, temp, 5, f_sum+620+42, 5, p_10+312);
	GF2X_MUL(10, temp2, 5, g_sum+620+42, 5, p_11+312);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(1, g_sum+932, 1, g_sum+932, 1, temp+9);
	right_bit_shift_n(99, g_sum+932, 51);
	

	delta = divstepsx_256(255, delta, f_sum+977, g_sum+977, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+973+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+973+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+973+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+973+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+973+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+973+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+973+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+973+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+969+4, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+969+4, 8, p_01+408);
	gf2x_add(12, f_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, f_sum+969);
	GF2X_MUL(8, temp2, 4, p_01+408+4, 4, g_sum+969);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1215, 4, f_sum+1215, 4, temp+4);
	right_bit_shift_n(12, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+969+4, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+969+4, 8, p_11+408);
	gf2x_add(12, g_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+408+4, 4, f_sum+969);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, g_sum+969);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1215, 4, g_sum+1215, 4, temp+4);
	right_bit_shift_n(12, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1216, g_sum+1216, q_00+395, q_01+395, q_10+395, q_11+395);

	// Recombining results: n: 765, depth: 5
	memset(p_00+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_01+395);
	gf2x_add(8, p_00+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+392+0, 8, p_00+392+0, 8, temp);
	memset(p_01+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_01+395);
	gf2x_add(8, p_01+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+392+0, 8, p_01+392+0, 8, temp);
	memset(p_10+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_11+395);
	gf2x_add(8, p_10+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+392+0, 8, p_10+392+0, 8, temp);
	memset(p_11+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_11+395);
	gf2x_add(8, p_11+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+392+0, 8, p_11+392+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+957+12, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, g_sum+957+12, 12, p_01+392);
	gf2x_add(24, f_sum+1170+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+957+0, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, g_sum+957+0, 12, p_01+392);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1170, 12, f_sum+1170, 12, temp+12);
	right_bit_shift_n(24, f_sum+1170, 61);
	GF2X_MUL(24, temp, 12, f_sum+957+12, 12, p_10+392);
	GF2X_MUL(24, temp2, 12, g_sum+957+12, 12, p_11+392);
	gf2x_add(24, g_sum+1170+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+957+0, 12, p_10+392);
	GF2X_MUL(24, temp2, 12, g_sum+957+0, 12, p_11+392);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1170, 12, g_sum+1170, 12, temp+12);
	right_bit_shift_n(24, g_sum+1170, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1179, g_sum+1179, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_01+408);
	gf2x_add(12, f_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_01+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1215, 4, f_sum+1215, 4, temp+4);
	right_bit_shift_n(12, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_11+408);
	gf2x_add(12, g_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1215, 4, g_sum+1215, 4, temp+4);
	right_bit_shift_n(12, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1216, g_sum+1216, q_00+395, q_01+395, q_10+395, q_11+395);

	// Recombining results: n: 765, depth: 5
	memset(q_00+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_01+395);
	gf2x_add(8, q_00+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+383+0, 8, q_00+383+0, 8, temp);
	memset(q_01+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_01+395);
	gf2x_add(8, q_01+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+383+0, 8, q_01+383+0, 8, temp);
	memset(q_10+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_11+395);
	gf2x_add(8, q_10+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+383+0, 8, q_10+383+0, 8, temp);
	memset(q_11+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_11+395);
	gf2x_add(8, q_11+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+383+0, 8, q_11+383+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 4
	GF2X_MUL(24, temp, 12, q_00+383+0, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, q_01+383+0, 12, p_10+392);
	gf2x_add(24, p_00+364+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+383+0, 12, p_01+392);
	GF2X_MUL(24, temp2, 12, q_01+383+0, 12, p_11+392);
	gf2x_add(24, p_01+364+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+383+0, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, q_11+383+0, 12, p_10+392);
	gf2x_add(24, p_10+364+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+383+0, 12, p_01+392);
	GF2X_MUL(24, temp2, 12, q_11+383+0, 12, p_11+392);
	gf2x_add(24, p_11+364+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 3012, depth: 3
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+933+24, 24, p_00+364);
	GF2X_MUL(48, temp2, 24, g_sum+933+24, 24, p_01+364);
	gf2x_add(48, f_sum+1089+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+933+0, 24, p_00+364);
	GF2X_MUL(48, temp2, 24, g_sum+933+0, 24, p_01+364);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+1089, 24, f_sum+1089, 24, temp+24);
	right_bit_shift_n(48, f_sum+1089, 58);
	GF2X_MUL(48, temp, 24, f_sum+933+24, 24, p_10+364);
	GF2X_MUL(48, temp2, 24, g_sum+933+24, 24, p_11+364);
	gf2x_add(48, g_sum+1089+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+933+0, 24, p_10+364);
	GF2X_MUL(48, temp2, 24, g_sum+933+0, 24, p_11+364);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+1089, 24, g_sum+1089, 24, temp+24);
	right_bit_shift_n(48, g_sum+1089, 58);
	

	delta = divstepsx_256(255, delta, f_sum+1110, g_sum+1110, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1106+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1106+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1106+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1106+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1106+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1102+4, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+1102+4, 8, p_01+408);
	gf2x_add(12, f_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, f_sum+1102);
	GF2X_MUL(8, temp2, 4, p_01+408+4, 4, g_sum+1102);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1215, 4, f_sum+1215, 4, temp+4);
	right_bit_shift_n(12, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+1102+4, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+1102+4, 8, p_11+408);
	gf2x_add(12, g_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+408+4, 4, f_sum+1102);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, g_sum+1102);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1215, 4, g_sum+1215, 4, temp+4);
	right_bit_shift_n(12, g_sum+1215, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1216, g_sum+1216, q_00+395, q_01+395, q_10+395, q_11+395);

	// Recombining results: n: 765, depth: 5
	memset(p_00+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_01+395);
	gf2x_add(8, p_00+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+392+0, 8, p_00+392+0, 8, temp);
	memset(p_01+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_01+395);
	gf2x_add(8, p_01+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+392+0, 8, p_01+392+0, 8, temp);
	memset(p_10+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_11+395);
	gf2x_add(8, p_10+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+392+0, 8, p_10+392+0, 8, temp);
	memset(p_11+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_11+395);
	gf2x_add(8, p_11+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+392+0, 8, p_11+392+0, 8, temp);
	

	// Calculating left operands: n: 1482, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1090+12, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+12, 12, p_01+392);
	gf2x_add(24, f_sum+1170+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1090+0, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+0, 12, p_01+392);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1170, 12, f_sum+1170, 12, temp+12);
	right_bit_shift_n(24, f_sum+1170, 61);
	GF2X_MUL(24, temp, 12, f_sum+1090+12, 12, p_10+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+12, 12, p_11+392);
	gf2x_add(24, g_sum+1170+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1090+0, 12, p_10+392);
	GF2X_MUL(24, temp2, 12, g_sum+1090+0, 12, p_11+392);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1170, 12, g_sum+1170, 12, temp+12);
	right_bit_shift_n(24, g_sum+1170, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1179, g_sum+1179, p_00+416, p_01+416, p_10+416, p_11+416);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_01+416);
	gf2x_add(8, f_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_01+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1240, 4, f_sum+1240, 4, temp+4);
	right_bit_shift_n(8, f_sum+1240, 63);
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_11+416);
	gf2x_add(8, g_sum+1240+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_10+416);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_11+416);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1240, 4, g_sum+1240, 4, temp+4);
	right_bit_shift_n(8, g_sum+1240, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1241, g_sum+1241, q_00+403, q_01+403, q_10+403, q_11+403);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_10+416);
	gf2x_add(8, p_00+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_01+403+0, 4, p_11+416);
	gf2x_add(8, p_01+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_00+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_10+416);
	gf2x_add(8, p_10+408+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+403+0, 4, p_01+416);
	GF2X_MUL(8, temp2, 4, q_11+403+0, 4, p_11+416);
	gf2x_add(8, p_11+408+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 717, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_00+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_01+408);
	gf2x_add(12, f_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_01+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1215, 4, f_sum+1215, 4, temp+4);
	right_bit_shift_n(12, f_sum+1215, 62);
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_10+408);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_11+408);
	gf2x_add(12, g_sum+1215, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+408+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1215, 4, g_sum+1215, 4, temp+4);
	right_bit_shift_n(12, g_sum+1215, 62);
	

	delta = divstepsx_256(207, delta, f_sum+1216, g_sum+1216, q_00+395, q_01+395, q_10+395, q_11+395);

	// Recombining results: n: 717, depth: 5
	memset(q_00+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_01+395);
	gf2x_add(8, q_00+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+383+0, 8, q_00+383+0, 8, temp);
	memset(q_01+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_00+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_01+395);
	gf2x_add(8, q_01+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_01+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+383+0, 8, q_01+383+0, 8, temp);
	memset(q_10+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_10+408+4, 4, q_11+395);
	gf2x_add(8, q_10+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_00+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_10+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+383+0, 8, q_10+383+0, 8, temp);
	memset(q_11+383, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+408+4, 4, q_10+395);
	GF2X_MUL(8, temp2, 4, p_11+408+4, 4, q_11+395);
	gf2x_add(8, q_11+383+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+395+0, 4, p_01+408);
	GF2X_MUL(8, temp2, 4, q_11+395+0, 4, p_11+408);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+383+0, 8, q_11+383+0, 8, temp);
	

	// Recombining results: n: 1482, depth: 4
	GF2X_MUL(24, temp, 12, q_00+383+0, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, q_01+383+0, 12, p_10+392);
	gf2x_add(24, q_00+359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+383+0, 12, p_01+392);
	GF2X_MUL(24, temp2, 12, q_01+383+0, 12, p_11+392);
	gf2x_add(24, q_01+359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+383+0, 12, p_00+392);
	GF2X_MUL(24, temp2, 12, q_11+383+0, 12, p_10+392);
	gf2x_add(24, q_10+359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+383+0, 12, p_01+392);
	GF2X_MUL(24, temp2, 12, q_11+383+0, 12, p_11+392);
	gf2x_add(24, q_11+359+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3012, depth: 3
	GF2X_MUL(48, temp, 24, q_00+359+0, 24, p_00+364);
	GF2X_MUL(48, temp2, 24, q_01+359+0, 24, p_10+364);
	gf2x_add(48, q_00+307+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_00+359+0, 24, p_01+364);
	GF2X_MUL(48, temp2, 24, q_01+359+0, 24, p_11+364);
	gf2x_add(48, q_01+307+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+359+0, 24, p_00+364);
	GF2X_MUL(48, temp2, 24, q_11+359+0, 24, p_10+364);
	gf2x_add(48, q_10+307+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+359+0, 24, p_01+364);
	GF2X_MUL(48, temp2, 24, q_11+359+0, 24, p_11+364);
	gf2x_add(48, q_11+307+0, 48, temp, 48, temp2);
	

	// Recombining results: n: 6327, depth: 2
	memset(q_00+203, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_00+312+4, 48, q_00+307);
	GF2X_MUL(96, temp2, 48, p_10+312+4, 48, q_01+307);
	gf2x_add(96, q_00+203+3, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_00+307+44, 4, p_00+312);
	GF2X_MUL(8, temp2, 4, q_01+307+44, 4, p_10+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+203+43, 8, q_00+203+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+307+40, 4, p_00+312);
	GF2X_MUL(8, temp2, 4, q_01+307+40, 4, p_10+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+203+39, 8, q_00+203+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+307+36, 4, p_00+312);
	GF2X_MUL(8, temp2, 4, q_01+307+36, 4, p_10+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+203+35, 8, q_00+203+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+307+32, 4, p_00+312);
	GF2X_MUL(8, temp2, 4, q_01+307+32, 4, p_10+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+203+31, 8, q_00+203+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+307+28, 4, p_00+312);
	GF2X_MUL(8, temp2, 4, q_01+307+28, 4, p_10+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+203+27, 8, q_00+203+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+307+24, 4, p_00+312);
	GF2X_MUL(8, temp2, 4, q_01+307+24, 4, p_10+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+203+23, 8, q_00+203+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+307+20, 4, p_00+312);
	GF2X_MUL(8, temp2, 4, q_01+307+20, 4, p_10+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+203+19, 8, q_00+203+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+307+16, 4, p_00+312);
	GF2X_MUL(8, temp2, 4, q_01+307+16, 4, p_10+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+203+15, 8, q_00+203+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+307+12, 4, p_00+312);
	GF2X_MUL(8, temp2, 4, q_01+307+12, 4, p_10+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+203+11, 8, q_00+203+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+307+8, 4, p_00+312);
	GF2X_MUL(8, temp2, 4, q_01+307+8, 4, p_10+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+203+7, 8, q_00+203+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+307+4, 4, p_00+312);
	GF2X_MUL(8, temp2, 4, q_01+307+4, 4, p_10+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+203+3, 8, q_00+203+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+307+0, 4, p_00+312);
	GF2X_MUL(8, temp2, 4, q_01+307+0, 4, p_10+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, q_00+203, 7, q_00+203, 7, temp+1);
	memset(q_01+203, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_01+312+4, 48, q_00+307);
	GF2X_MUL(96, temp2, 48, p_11+312+4, 48, q_01+307);
	gf2x_add(96, q_01+203+3, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_00+307+44, 4, p_01+312);
	GF2X_MUL(8, temp2, 4, q_01+307+44, 4, p_11+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+203+43, 8, q_01+203+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+307+40, 4, p_01+312);
	GF2X_MUL(8, temp2, 4, q_01+307+40, 4, p_11+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+203+39, 8, q_01+203+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+307+36, 4, p_01+312);
	GF2X_MUL(8, temp2, 4, q_01+307+36, 4, p_11+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+203+35, 8, q_01+203+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+307+32, 4, p_01+312);
	GF2X_MUL(8, temp2, 4, q_01+307+32, 4, p_11+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+203+31, 8, q_01+203+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+307+28, 4, p_01+312);
	GF2X_MUL(8, temp2, 4, q_01+307+28, 4, p_11+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+203+27, 8, q_01+203+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+307+24, 4, p_01+312);
	GF2X_MUL(8, temp2, 4, q_01+307+24, 4, p_11+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+203+23, 8, q_01+203+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+307+20, 4, p_01+312);
	GF2X_MUL(8, temp2, 4, q_01+307+20, 4, p_11+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+203+19, 8, q_01+203+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+307+16, 4, p_01+312);
	GF2X_MUL(8, temp2, 4, q_01+307+16, 4, p_11+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+203+15, 8, q_01+203+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+307+12, 4, p_01+312);
	GF2X_MUL(8, temp2, 4, q_01+307+12, 4, p_11+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+203+11, 8, q_01+203+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+307+8, 4, p_01+312);
	GF2X_MUL(8, temp2, 4, q_01+307+8, 4, p_11+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+203+7, 8, q_01+203+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+307+4, 4, p_01+312);
	GF2X_MUL(8, temp2, 4, q_01+307+4, 4, p_11+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+203+3, 8, q_01+203+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+307+0, 4, p_01+312);
	GF2X_MUL(8, temp2, 4, q_01+307+0, 4, p_11+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, q_01+203, 7, q_01+203, 7, temp+1);
	memset(q_10+203, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_00+312+4, 48, q_10+307);
	GF2X_MUL(96, temp2, 48, p_10+312+4, 48, q_11+307);
	gf2x_add(96, q_10+203+3, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_10+307+44, 4, p_00+312);
	GF2X_MUL(8, temp2, 4, q_11+307+44, 4, p_10+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+203+43, 8, q_10+203+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+307+40, 4, p_00+312);
	GF2X_MUL(8, temp2, 4, q_11+307+40, 4, p_10+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+203+39, 8, q_10+203+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+307+36, 4, p_00+312);
	GF2X_MUL(8, temp2, 4, q_11+307+36, 4, p_10+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+203+35, 8, q_10+203+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+307+32, 4, p_00+312);
	GF2X_MUL(8, temp2, 4, q_11+307+32, 4, p_10+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+203+31, 8, q_10+203+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+307+28, 4, p_00+312);
	GF2X_MUL(8, temp2, 4, q_11+307+28, 4, p_10+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+203+27, 8, q_10+203+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+307+24, 4, p_00+312);
	GF2X_MUL(8, temp2, 4, q_11+307+24, 4, p_10+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+203+23, 8, q_10+203+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+307+20, 4, p_00+312);
	GF2X_MUL(8, temp2, 4, q_11+307+20, 4, p_10+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+203+19, 8, q_10+203+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+307+16, 4, p_00+312);
	GF2X_MUL(8, temp2, 4, q_11+307+16, 4, p_10+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+203+15, 8, q_10+203+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+307+12, 4, p_00+312);
	GF2X_MUL(8, temp2, 4, q_11+307+12, 4, p_10+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+203+11, 8, q_10+203+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+307+8, 4, p_00+312);
	GF2X_MUL(8, temp2, 4, q_11+307+8, 4, p_10+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+203+7, 8, q_10+203+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+307+4, 4, p_00+312);
	GF2X_MUL(8, temp2, 4, q_11+307+4, 4, p_10+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+203+3, 8, q_10+203+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+307+0, 4, p_00+312);
	GF2X_MUL(8, temp2, 4, q_11+307+0, 4, p_10+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, q_10+203, 7, q_10+203, 7, temp+1);
	memset(q_11+203, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_01+312+4, 48, q_10+307);
	GF2X_MUL(96, temp2, 48, p_11+312+4, 48, q_11+307);
	gf2x_add(96, q_11+203+3, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_10+307+44, 4, p_01+312);
	GF2X_MUL(8, temp2, 4, q_11+307+44, 4, p_11+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+203+43, 8, q_11+203+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+307+40, 4, p_01+312);
	GF2X_MUL(8, temp2, 4, q_11+307+40, 4, p_11+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+203+39, 8, q_11+203+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+307+36, 4, p_01+312);
	GF2X_MUL(8, temp2, 4, q_11+307+36, 4, p_11+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+203+35, 8, q_11+203+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+307+32, 4, p_01+312);
	GF2X_MUL(8, temp2, 4, q_11+307+32, 4, p_11+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+203+31, 8, q_11+203+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+307+28, 4, p_01+312);
	GF2X_MUL(8, temp2, 4, q_11+307+28, 4, p_11+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+203+27, 8, q_11+203+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+307+24, 4, p_01+312);
	GF2X_MUL(8, temp2, 4, q_11+307+24, 4, p_11+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+203+23, 8, q_11+203+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+307+20, 4, p_01+312);
	GF2X_MUL(8, temp2, 4, q_11+307+20, 4, p_11+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+203+19, 8, q_11+203+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+307+16, 4, p_01+312);
	GF2X_MUL(8, temp2, 4, q_11+307+16, 4, p_11+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+203+15, 8, q_11+203+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+307+12, 4, p_01+312);
	GF2X_MUL(8, temp2, 4, q_11+307+12, 4, p_11+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+203+11, 8, q_11+203+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+307+8, 4, p_01+312);
	GF2X_MUL(8, temp2, 4, q_11+307+8, 4, p_11+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+203+7, 8, q_11+203+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+307+4, 4, p_01+312);
	GF2X_MUL(8, temp2, 4, q_11+307+4, 4, p_11+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+203+3, 8, q_11+203+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+307+0, 4, p_01+312);
	GF2X_MUL(8, temp2, 4, q_11+307+0, 4, p_11+312);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, q_11+203, 7, q_11+203, 7, temp+1);
	

	// Recombining results: n: 12957, depth: 1
	memset(q_00+0, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(198, temp, 99, p_00+208+5, 99, q_00+203);
	GF2X_MUL(198, temp2, 99, p_10+208+5, 99, q_01+203);
	gf2x_add(198, q_00+0+5, 198, temp, 198, temp2);
	GF2X_MUL(10, temp, 5, q_00+203+94, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_01+203+94, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+94, 10, q_00+0+94, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+89, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_01+203+89, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+89, 10, q_00+0+89, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+84, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_01+203+84, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+84, 10, q_00+0+84, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+79, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_01+203+79, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+79, 10, q_00+0+79, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+74, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_01+203+74, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+74, 10, q_00+0+74, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+69, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_01+203+69, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+69, 10, q_00+0+69, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+64, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_01+203+64, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+64, 10, q_00+0+64, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+59, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_01+203+59, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+59, 10, q_00+0+59, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+54, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_01+203+54, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+54, 10, q_00+0+54, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+49, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_01+203+49, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+49, 10, q_00+0+49, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+44, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_01+203+44, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+44, 10, q_00+0+44, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+39, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_01+203+39, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+39, 10, q_00+0+39, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+34, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_01+203+34, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+34, 10, q_00+0+34, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+29, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_01+203+29, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+29, 10, q_00+0+29, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+24, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_01+203+24, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+24, 10, q_00+0+24, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+19, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_01+203+19, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+19, 10, q_00+0+19, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+14, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_01+203+14, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+14, 10, q_00+0+14, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+9, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_01+203+9, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+9, 10, q_00+0+9, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+4, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_01+203+4, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+0+4, 10, q_00+0+4, 10, temp);
	GF2X_MUL(8, temp, 4, p_00+208+1, 4, q_00+203);
	GF2X_MUL(8, temp2, 4, p_10+208+1, 4, q_01+203);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+0+1, 8, q_00+0+1, 8, temp);
	GF2X_MUL(2, temp, 1, q_00+203+3, 1, p_00+208);
	GF2X_MUL(2, temp2, 1, q_01+203+3, 1, p_10+208);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+3, 2, q_00+0+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+203+2, 1, p_00+208);
	GF2X_MUL(2, temp2, 1, q_01+203+2, 1, p_10+208);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+2, 2, q_00+0+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+203+1, 1, p_00+208);
	GF2X_MUL(2, temp2, 1, q_01+203+1, 1, p_10+208);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+1, 2, q_00+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+203+0, 1, p_00+208);
	GF2X_MUL(2, temp2, 1, q_01+203+0, 1, p_10+208);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+0, 2, q_00+0+0, 2, temp);
	memset(q_01+0, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(198, temp, 99, p_01+208+5, 99, q_00+203);
	GF2X_MUL(198, temp2, 99, p_11+208+5, 99, q_01+203);
	gf2x_add(198, q_01+0+5, 198, temp, 198, temp2);
	GF2X_MUL(10, temp, 5, q_00+203+94, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_01+203+94, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+94, 10, q_01+0+94, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+89, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_01+203+89, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+89, 10, q_01+0+89, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+84, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_01+203+84, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+84, 10, q_01+0+84, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+79, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_01+203+79, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+79, 10, q_01+0+79, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+74, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_01+203+74, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+74, 10, q_01+0+74, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+69, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_01+203+69, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+69, 10, q_01+0+69, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+64, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_01+203+64, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+64, 10, q_01+0+64, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+59, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_01+203+59, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+59, 10, q_01+0+59, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+54, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_01+203+54, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+54, 10, q_01+0+54, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+49, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_01+203+49, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+49, 10, q_01+0+49, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+44, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_01+203+44, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+44, 10, q_01+0+44, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+39, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_01+203+39, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+39, 10, q_01+0+39, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+34, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_01+203+34, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+34, 10, q_01+0+34, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+29, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_01+203+29, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+29, 10, q_01+0+29, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+24, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_01+203+24, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+24, 10, q_01+0+24, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+19, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_01+203+19, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+19, 10, q_01+0+19, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+14, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_01+203+14, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+14, 10, q_01+0+14, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+9, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_01+203+9, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+9, 10, q_01+0+9, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+203+4, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_01+203+4, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+0+4, 10, q_01+0+4, 10, temp);
	GF2X_MUL(8, temp, 4, p_01+208+1, 4, q_00+203);
	GF2X_MUL(8, temp2, 4, p_11+208+1, 4, q_01+203);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+0+1, 8, q_01+0+1, 8, temp);
	GF2X_MUL(2, temp, 1, q_00+203+3, 1, p_01+208);
	GF2X_MUL(2, temp2, 1, q_01+203+3, 1, p_11+208);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+3, 2, q_01+0+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+203+2, 1, p_01+208);
	GF2X_MUL(2, temp2, 1, q_01+203+2, 1, p_11+208);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+2, 2, q_01+0+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+203+1, 1, p_01+208);
	GF2X_MUL(2, temp2, 1, q_01+203+1, 1, p_11+208);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+1, 2, q_01+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+203+0, 1, p_01+208);
	GF2X_MUL(2, temp2, 1, q_01+203+0, 1, p_11+208);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+0, 2, q_01+0+0, 2, temp);
	memset(q_10+0, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(198, temp, 99, p_00+208+5, 99, q_10+203);
	GF2X_MUL(198, temp2, 99, p_10+208+5, 99, q_11+203);
	gf2x_add(198, q_10+0+5, 198, temp, 198, temp2);
	GF2X_MUL(10, temp, 5, q_10+203+94, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_11+203+94, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+94, 10, q_10+0+94, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+89, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_11+203+89, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+89, 10, q_10+0+89, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+84, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_11+203+84, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+84, 10, q_10+0+84, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+79, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_11+203+79, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+79, 10, q_10+0+79, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+74, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_11+203+74, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+74, 10, q_10+0+74, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+69, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_11+203+69, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+69, 10, q_10+0+69, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+64, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_11+203+64, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+64, 10, q_10+0+64, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+59, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_11+203+59, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+59, 10, q_10+0+59, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+54, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_11+203+54, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+54, 10, q_10+0+54, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+49, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_11+203+49, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+49, 10, q_10+0+49, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+44, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_11+203+44, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+44, 10, q_10+0+44, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+39, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_11+203+39, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+39, 10, q_10+0+39, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+34, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_11+203+34, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+34, 10, q_10+0+34, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+29, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_11+203+29, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+29, 10, q_10+0+29, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+24, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_11+203+24, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+24, 10, q_10+0+24, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+19, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_11+203+19, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+19, 10, q_10+0+19, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+14, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_11+203+14, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+14, 10, q_10+0+14, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+9, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_11+203+9, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+9, 10, q_10+0+9, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+4, 5, p_00+208);
	GF2X_MUL(10, temp2, 5, q_11+203+4, 5, p_10+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+0+4, 10, q_10+0+4, 10, temp);
	GF2X_MUL(8, temp, 4, p_00+208+1, 4, q_10+203);
	GF2X_MUL(8, temp2, 4, p_10+208+1, 4, q_11+203);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+0+1, 8, q_10+0+1, 8, temp);
	GF2X_MUL(2, temp, 1, q_10+203+3, 1, p_00+208);
	GF2X_MUL(2, temp2, 1, q_11+203+3, 1, p_10+208);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+3, 2, q_10+0+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+203+2, 1, p_00+208);
	GF2X_MUL(2, temp2, 1, q_11+203+2, 1, p_10+208);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+2, 2, q_10+0+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+203+1, 1, p_00+208);
	GF2X_MUL(2, temp2, 1, q_11+203+1, 1, p_10+208);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+1, 2, q_10+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+203+0, 1, p_00+208);
	GF2X_MUL(2, temp2, 1, q_11+203+0, 1, p_10+208);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+0, 2, q_10+0+0, 2, temp);
	memset(q_11+0, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(198, temp, 99, p_01+208+5, 99, q_10+203);
	GF2X_MUL(198, temp2, 99, p_11+208+5, 99, q_11+203);
	gf2x_add(198, q_11+0+5, 198, temp, 198, temp2);
	GF2X_MUL(10, temp, 5, q_10+203+94, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_11+203+94, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+94, 10, q_11+0+94, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+89, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_11+203+89, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+89, 10, q_11+0+89, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+84, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_11+203+84, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+84, 10, q_11+0+84, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+79, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_11+203+79, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+79, 10, q_11+0+79, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+74, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_11+203+74, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+74, 10, q_11+0+74, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+69, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_11+203+69, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+69, 10, q_11+0+69, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+64, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_11+203+64, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+64, 10, q_11+0+64, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+59, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_11+203+59, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+59, 10, q_11+0+59, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+54, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_11+203+54, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+54, 10, q_11+0+54, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+49, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_11+203+49, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+49, 10, q_11+0+49, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+44, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_11+203+44, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+44, 10, q_11+0+44, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+39, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_11+203+39, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+39, 10, q_11+0+39, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+34, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_11+203+34, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+34, 10, q_11+0+34, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+29, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_11+203+29, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+29, 10, q_11+0+29, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+24, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_11+203+24, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+24, 10, q_11+0+24, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+19, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_11+203+19, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+19, 10, q_11+0+19, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+14, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_11+203+14, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+14, 10, q_11+0+14, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+9, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_11+203+9, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+9, 10, q_11+0+9, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+203+4, 5, p_01+208);
	GF2X_MUL(10, temp2, 5, q_11+203+4, 5, p_11+208);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+0+4, 10, q_11+0+4, 10, temp);
	GF2X_MUL(8, temp, 4, p_01+208+1, 4, q_10+203);
	GF2X_MUL(8, temp2, 4, p_11+208+1, 4, q_11+203);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+0+1, 8, q_11+0+1, 8, temp);
	GF2X_MUL(2, temp, 1, q_10+203+3, 1, p_01+208);
	GF2X_MUL(2, temp2, 1, q_11+203+3, 1, p_11+208);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+3, 2, q_11+0+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+203+2, 1, p_01+208);
	GF2X_MUL(2, temp2, 1, q_11+203+2, 1, p_11+208);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+2, 2, q_11+0+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+203+1, 1, p_01+208);
	GF2X_MUL(2, temp2, 1, q_11+203+1, 1, p_11+208);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+1, 2, q_11+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+203+0, 1, p_01+208);
	GF2X_MUL(2, temp2, 1, q_11+203+0, 1, p_11+208);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+0, 2, q_11+0+0, 2, temp);
	

	// Recombining results: n: 26217, depth: 0
	memset(t_00+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(406, temp, 203, p_00+0+5, 203, q_00+0);
	GF2X_MUL(406, temp2, 203, p_10+0+5, 203, q_01+0);
	gf2x_add(406, t_00+0+4, 406, temp, 406, temp2);
	GF2X_MUL(10, temp, 5, q_00+0+198, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+198, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+197, 10, t_00+0+197, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+193, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+193, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+192, 10, t_00+0+192, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+188, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+188, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+187, 10, t_00+0+187, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+183, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+183, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+182, 10, t_00+0+182, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+178, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+178, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+177, 10, t_00+0+177, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+173, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+173, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+172, 10, t_00+0+172, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+168, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+168, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+167, 10, t_00+0+167, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+163, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+163, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+162, 10, t_00+0+162, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+158, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+158, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+157, 10, t_00+0+157, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+153, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+153, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+152, 10, t_00+0+152, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+148, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+148, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+147, 10, t_00+0+147, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+143, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+143, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+142, 10, t_00+0+142, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+138, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+138, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+137, 10, t_00+0+137, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+133, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+133, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+132, 10, t_00+0+132, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+128, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+128, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+127, 10, t_00+0+127, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+123, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+123, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+122, 10, t_00+0+122, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+118, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+118, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+117, 10, t_00+0+117, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+113, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+113, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+112, 10, t_00+0+112, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+108, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+108, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+107, 10, t_00+0+107, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+103, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+103, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+102, 10, t_00+0+102, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+98, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+98, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+97, 10, t_00+0+97, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+93, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+93, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+92, 10, t_00+0+92, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+88, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+88, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+87, 10, t_00+0+87, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+83, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+83, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+82, 10, t_00+0+82, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+78, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+78, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+77, 10, t_00+0+77, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+73, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+73, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+72, 10, t_00+0+72, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+68, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+68, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+67, 10, t_00+0+67, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+63, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+63, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+62, 10, t_00+0+62, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+58, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+58, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+57, 10, t_00+0+57, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+53, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+53, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+52, 10, t_00+0+52, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+48, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+48, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+47, 10, t_00+0+47, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+43, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+43, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+42, 10, t_00+0+42, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+38, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+38, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+37, 10, t_00+0+37, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+33, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+33, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+32, 10, t_00+0+32, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+28, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+28, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+27, 10, t_00+0+27, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+23, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+23, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+22, 10, t_00+0+22, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+18, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+18, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+17, 10, t_00+0+17, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+13, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+13, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+12, 10, t_00+0+12, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+8, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+8, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+7, 10, t_00+0+7, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+3, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+3, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+2, 10, t_00+0+2, 10, temp);
	GF2X_MUL(6, temp, 3, p_00+0+2, 3, q_00+0);
	GF2X_MUL(6, temp2, 3, p_10+0+2, 3, q_01+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+1, 6, t_00+0+1, 6, temp);
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
	memset(t_01+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(406, temp, 203, p_01+0+5, 203, q_00+0);
	GF2X_MUL(406, temp2, 203, p_11+0+5, 203, q_01+0);
	gf2x_add(406, t_01+0+4, 406, temp, 406, temp2);
	GF2X_MUL(10, temp, 5, q_00+0+198, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+198, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+197, 10, t_01+0+197, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+193, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+193, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+192, 10, t_01+0+192, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+188, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+188, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+187, 10, t_01+0+187, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+183, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+183, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+182, 10, t_01+0+182, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+178, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+178, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+177, 10, t_01+0+177, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+173, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+173, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+172, 10, t_01+0+172, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+168, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+168, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+167, 10, t_01+0+167, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+163, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+163, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+162, 10, t_01+0+162, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+158, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+158, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+157, 10, t_01+0+157, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+153, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+153, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+152, 10, t_01+0+152, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+148, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+148, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+147, 10, t_01+0+147, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+143, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+143, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+142, 10, t_01+0+142, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+138, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+138, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+137, 10, t_01+0+137, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+133, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+133, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+132, 10, t_01+0+132, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+128, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+128, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+127, 10, t_01+0+127, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+123, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+123, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+122, 10, t_01+0+122, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+118, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+118, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+117, 10, t_01+0+117, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+113, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+113, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+112, 10, t_01+0+112, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+108, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+108, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+107, 10, t_01+0+107, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+103, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+103, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+102, 10, t_01+0+102, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+98, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+98, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+97, 10, t_01+0+97, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+93, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+93, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+92, 10, t_01+0+92, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+88, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+88, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+87, 10, t_01+0+87, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+83, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+83, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+82, 10, t_01+0+82, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+78, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+78, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+77, 10, t_01+0+77, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+73, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+73, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+72, 10, t_01+0+72, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+68, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+68, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+67, 10, t_01+0+67, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+63, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+63, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+62, 10, t_01+0+62, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+58, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+58, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+57, 10, t_01+0+57, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+53, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+53, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+52, 10, t_01+0+52, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+48, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+48, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+47, 10, t_01+0+47, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+43, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+43, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+42, 10, t_01+0+42, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+38, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+38, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+37, 10, t_01+0+37, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+33, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+33, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+32, 10, t_01+0+32, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+28, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+28, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+27, 10, t_01+0+27, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+23, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+23, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+22, 10, t_01+0+22, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+18, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+18, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+17, 10, t_01+0+17, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+13, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+13, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+12, 10, t_01+0+12, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+8, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+8, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+7, 10, t_01+0+7, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+3, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+3, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+2, 10, t_01+0+2, 10, temp);
	GF2X_MUL(6, temp, 3, p_01+0+2, 3, q_00+0);
	GF2X_MUL(6, temp2, 3, p_11+0+2, 3, q_01+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+1, 6, t_01+0+1, 6, temp);
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
	memset(t_10+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(406, temp, 203, p_00+0+5, 203, q_10+0);
	GF2X_MUL(406, temp2, 203, p_10+0+5, 203, q_11+0);
	gf2x_add(406, t_10+0+4, 406, temp, 406, temp2);
	GF2X_MUL(10, temp, 5, q_10+0+198, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+198, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+197, 10, t_10+0+197, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+193, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+193, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+192, 10, t_10+0+192, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+188, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+188, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+187, 10, t_10+0+187, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+183, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+183, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+182, 10, t_10+0+182, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+178, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+178, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+177, 10, t_10+0+177, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+173, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+173, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+172, 10, t_10+0+172, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+168, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+168, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+167, 10, t_10+0+167, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+163, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+163, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+162, 10, t_10+0+162, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+158, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+158, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+157, 10, t_10+0+157, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+153, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+153, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+152, 10, t_10+0+152, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+148, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+148, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+147, 10, t_10+0+147, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+143, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+143, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+142, 10, t_10+0+142, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+138, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+138, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+137, 10, t_10+0+137, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+133, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+133, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+132, 10, t_10+0+132, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+128, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+128, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+127, 10, t_10+0+127, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+123, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+123, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+122, 10, t_10+0+122, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+118, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+118, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+117, 10, t_10+0+117, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+113, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+113, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+112, 10, t_10+0+112, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+108, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+108, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+107, 10, t_10+0+107, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+103, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+103, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+102, 10, t_10+0+102, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+98, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+98, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+97, 10, t_10+0+97, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+93, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+93, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+92, 10, t_10+0+92, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+88, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+88, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+87, 10, t_10+0+87, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+83, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+83, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+82, 10, t_10+0+82, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+78, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+78, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+77, 10, t_10+0+77, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+73, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+73, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+72, 10, t_10+0+72, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+68, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+68, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+67, 10, t_10+0+67, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+63, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+63, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+62, 10, t_10+0+62, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+58, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+58, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+57, 10, t_10+0+57, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+53, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+53, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+52, 10, t_10+0+52, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+48, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+48, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+47, 10, t_10+0+47, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+43, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+43, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+42, 10, t_10+0+42, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+38, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+38, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+37, 10, t_10+0+37, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+33, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+33, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+32, 10, t_10+0+32, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+28, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+28, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+27, 10, t_10+0+27, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+23, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+23, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+22, 10, t_10+0+22, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+18, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+18, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+17, 10, t_10+0+17, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+13, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+13, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+12, 10, t_10+0+12, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+8, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+8, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+7, 10, t_10+0+7, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+3, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+3, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+2, 10, t_10+0+2, 10, temp);
	GF2X_MUL(6, temp, 3, p_00+0+2, 3, q_10+0);
	GF2X_MUL(6, temp2, 3, p_10+0+2, 3, q_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+1, 6, t_10+0+1, 6, temp);
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
	memset(t_11+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(406, temp, 203, p_01+0+5, 203, q_10+0);
	GF2X_MUL(406, temp2, 203, p_11+0+5, 203, q_11+0);
	gf2x_add(406, t_11+0+4, 406, temp, 406, temp2);
	GF2X_MUL(10, temp, 5, q_10+0+198, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+198, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+197, 10, t_11+0+197, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+193, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+193, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+192, 10, t_11+0+192, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+188, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+188, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+187, 10, t_11+0+187, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+183, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+183, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+182, 10, t_11+0+182, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+178, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+178, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+177, 10, t_11+0+177, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+173, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+173, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+172, 10, t_11+0+172, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+168, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+168, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+167, 10, t_11+0+167, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+163, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+163, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+162, 10, t_11+0+162, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+158, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+158, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+157, 10, t_11+0+157, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+153, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+153, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+152, 10, t_11+0+152, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+148, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+148, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+147, 10, t_11+0+147, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+143, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+143, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+142, 10, t_11+0+142, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+138, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+138, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+137, 10, t_11+0+137, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+133, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+133, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+132, 10, t_11+0+132, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+128, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+128, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+127, 10, t_11+0+127, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+123, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+123, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+122, 10, t_11+0+122, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+118, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+118, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+117, 10, t_11+0+117, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+113, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+113, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+112, 10, t_11+0+112, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+108, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+108, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+107, 10, t_11+0+107, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+103, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+103, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+102, 10, t_11+0+102, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+98, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+98, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+97, 10, t_11+0+97, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+93, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+93, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+92, 10, t_11+0+92, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+88, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+88, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+87, 10, t_11+0+87, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+83, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+83, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+82, 10, t_11+0+82, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+78, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+78, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+77, 10, t_11+0+77, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+73, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+73, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+72, 10, t_11+0+72, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+68, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+68, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+67, 10, t_11+0+67, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+63, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+63, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+62, 10, t_11+0+62, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+58, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+58, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+57, 10, t_11+0+57, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+53, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+53, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+52, 10, t_11+0+52, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+48, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+48, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+47, 10, t_11+0+47, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+43, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+43, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+42, 10, t_11+0+42, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+38, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+38, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+37, 10, t_11+0+37, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+33, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+33, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+32, 10, t_11+0+32, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+28, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+28, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+27, 10, t_11+0+27, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+23, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+23, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+22, 10, t_11+0+22, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+18, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+18, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+17, 10, t_11+0+17, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+13, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+13, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+12, 10, t_11+0+12, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+8, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+8, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+7, 10, t_11+0+7, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+3, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+3, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+2, 10, t_11+0+2, 10, temp);
	GF2X_MUL(6, temp, 3, p_01+0+2, 3, q_10+0);
	GF2X_MUL(6, temp2, 3, p_11+0+2, 3, q_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+1, 6, t_11+0+1, 6, temp);
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