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

int jumpdivstep_13397(int n, int delta, int nf, DIGIT *f, DIGIT *g, DIGIT *t_00, DIGIT *t_01, DIGIT *t_10, DIGIT *t_11, float x) {
	DIGIT p_00[432];
	DIGIT p_01[432];
	DIGIT p_10[432];
	DIGIT p_11[432];
	
	DIGIT q_00[416];
	DIGIT q_01[416];
	DIGIT q_10[416];
	DIGIT q_11[416];
	
	DIGIT f_sum[1287];
	DIGIT g_sum[1287];
	
	DIGIT temp[842];
	DIGIT temp2[842];
	

	delta = divstepsx_256(255, delta, f+415, g+415, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f+411+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g+411+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+411+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g+411+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f+411+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g+411+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+411+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g+411+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f+403+8, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g+403+8, 8, p_01+420);
	gf2x_add(16, f_sum+1248+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f+403+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g+403+0, 8, p_01+420);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1248, 8, f_sum+1248, 8, temp+8);
	right_bit_shift_n(16, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f+403+8, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g+403+8, 8, p_11+420);
	gf2x_add(16, g_sum+1248+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f+403+0, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g+403+0, 8, p_11+420);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1248, 8, g_sum+1248, 8, temp+8);
	right_bit_shift_n(16, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1253, g_sum+1253, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1249+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1249+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1249+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1249+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, q_00+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, q_01+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, q_10+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, q_11+404+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+404+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, q_01+404+0, 8, p_10+420);
	gf2x_add(16, p_00+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+404+0, 8, p_01+420);
	GF2X_MUL(16, temp2, 8, q_01+404+0, 8, p_11+420);
	gf2x_add(16, p_01+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+404+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, q_11+404+0, 8, p_10+420);
	gf2x_add(16, p_10+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+404+0, 8, p_01+420);
	GF2X_MUL(16, temp2, 8, q_11+404+0, 8, p_11+420);
	gf2x_add(16, p_11+404+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f+391+12, 16, p_00+404);
	GF2X_MUL(32, temp2, 16, g+391+12, 16, p_01+404);
	gf2x_add(28, f_sum+1203, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, f+391);
	GF2X_MUL(24, temp2, 12, p_01+404+4, 12, g+391);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1203, 12, f_sum+1203, 12, temp+12);
	right_bit_shift_n(28, f_sum+1203, 60);
	GF2X_MUL(32, temp, 16, f+391+12, 16, p_10+404);
	GF2X_MUL(32, temp2, 16, g+391+12, 16, p_11+404);
	gf2x_add(28, g_sum+1203, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+404+4, 12, f+391);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, g+391);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1203, 12, g_sum+1203, 12, temp+12);
	right_bit_shift_n(28, g_sum+1203, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1212, g_sum+1212, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_01+420);
	gf2x_add(12, f_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_01+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1248, 4, f_sum+1248, 4, temp+4);
	right_bit_shift_n(12, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_11+420);
	gf2x_add(12, g_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1248, 4, g_sum+1248, 4, temp+4);
	right_bit_shift_n(12, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1249, g_sum+1249, q_00+404, q_01+404, q_10+404, q_11+404);

	// Recombining results: n: 765, depth: 5
	memset(q_00+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_01+404);
	gf2x_add(8, q_00+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+392+0, 8, q_00+392+0, 8, temp);
	memset(q_01+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_01+404);
	gf2x_add(8, q_01+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+392+0, 8, q_01+392+0, 8, temp);
	memset(q_10+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_11+404);
	gf2x_add(8, q_10+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+392+0, 8, q_10+392+0, 8, temp);
	memset(q_11+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_11+404);
	gf2x_add(8, q_11+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+392+0, 8, q_11+392+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 4
	memset(p_00+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, q_00+392);
	GF2X_MUL(24, temp2, 12, p_10+404+4, 12, q_01+392);
	gf2x_add(24, p_00+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+392+8, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+8, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+376+8, 8, p_00+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+4, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+4, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+376+4, 8, p_00+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+0, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+0, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+376+0, 8, p_00+376+0, 8, temp);
	memset(p_01+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+404+4, 12, q_00+392);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, q_01+392);
	gf2x_add(24, p_01+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+392+8, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+8, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+376+8, 8, p_01+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+4, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+4, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+376+4, 8, p_01+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+0, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+0, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+376+0, 8, p_01+376+0, 8, temp);
	memset(p_10+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, q_10+392);
	GF2X_MUL(24, temp2, 12, p_10+404+4, 12, q_11+392);
	gf2x_add(24, p_10+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+392+8, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+8, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+376+8, 8, p_10+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+4, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+4, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+376+4, 8, p_10+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+0, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+0, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+376+0, 8, p_10+376+0, 8, temp);
	memset(p_11+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+404+4, 12, q_10+392);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, q_11+392);
	gf2x_add(24, p_11+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+392+8, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+8, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+376+8, 8, p_11+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+4, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+4, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+376+4, 8, p_11+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+0, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+0, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+376+0, 8, p_11+376+0, 8, temp);
	

	// Calculating left operands: n: 3570, depth: 3
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f+363+28, 28, p_00+376);
	GF2X_MUL(56, temp2, 28, g+363+28, 28, p_01+376);
	gf2x_add(56, f_sum+1118+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f+363+0, 28, p_00+376);
	GF2X_MUL(56, temp2, 28, g+363+0, 28, p_01+376);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+1118, 28, f_sum+1118, 28, temp+28);
	right_bit_shift_n(56, f_sum+1118, 57);
	GF2X_MUL(56, temp, 28, f+363+28, 28, p_10+376);
	GF2X_MUL(56, temp2, 28, g+363+28, 28, p_11+376);
	gf2x_add(56, g_sum+1118+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f+363+0, 28, p_10+376);
	GF2X_MUL(56, temp2, 28, g+363+0, 28, p_11+376);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+1118, 28, g_sum+1118, 28, temp+28);
	right_bit_shift_n(56, g_sum+1118, 57);
	

	delta = divstepsx_256(255, delta, f_sum+1143, g_sum+1143, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1139+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1139+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1139+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1139+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1139+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1139+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1139+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1139+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1131+8, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+1131+8, 8, p_01+420);
	gf2x_add(16, f_sum+1248+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1131+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+1131+0, 8, p_01+420);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1248, 8, f_sum+1248, 8, temp+8);
	right_bit_shift_n(16, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+1131+8, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+1131+8, 8, p_11+420);
	gf2x_add(16, g_sum+1248+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1131+0, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+1131+0, 8, p_11+420);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1248, 8, g_sum+1248, 8, temp+8);
	right_bit_shift_n(16, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1253, g_sum+1253, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1249+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1249+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1249+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1249+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, q_00+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, q_01+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, q_10+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, q_11+404+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+404+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, q_01+404+0, 8, p_10+420);
	gf2x_add(16, p_00+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+404+0, 8, p_01+420);
	GF2X_MUL(16, temp2, 8, q_01+404+0, 8, p_11+420);
	gf2x_add(16, p_01+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+404+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, q_11+404+0, 8, p_10+420);
	gf2x_add(16, p_10+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+404+0, 8, p_01+420);
	GF2X_MUL(16, temp2, 8, q_11+404+0, 8, p_11+420);
	gf2x_add(16, p_11+404+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1119+12, 16, p_00+404);
	GF2X_MUL(32, temp2, 16, g_sum+1119+12, 16, p_01+404);
	gf2x_add(28, f_sum+1203, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, f_sum+1119);
	GF2X_MUL(24, temp2, 12, p_01+404+4, 12, g_sum+1119);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1203, 12, f_sum+1203, 12, temp+12);
	right_bit_shift_n(28, f_sum+1203, 60);
	GF2X_MUL(32, temp, 16, f_sum+1119+12, 16, p_10+404);
	GF2X_MUL(32, temp2, 16, g_sum+1119+12, 16, p_11+404);
	gf2x_add(28, g_sum+1203, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+404+4, 12, f_sum+1119);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, g_sum+1119);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1203, 12, g_sum+1203, 12, temp+12);
	right_bit_shift_n(28, g_sum+1203, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1212, g_sum+1212, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_01+420);
	gf2x_add(12, f_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_01+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1248, 4, f_sum+1248, 4, temp+4);
	right_bit_shift_n(12, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_11+420);
	gf2x_add(12, g_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1248, 4, g_sum+1248, 4, temp+4);
	right_bit_shift_n(12, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1249, g_sum+1249, q_00+404, q_01+404, q_10+404, q_11+404);

	// Recombining results: n: 765, depth: 5
	memset(q_00+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_01+404);
	gf2x_add(8, q_00+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+392+0, 8, q_00+392+0, 8, temp);
	memset(q_01+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_01+404);
	gf2x_add(8, q_01+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+392+0, 8, q_01+392+0, 8, temp);
	memset(q_10+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_11+404);
	gf2x_add(8, q_10+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+392+0, 8, q_10+392+0, 8, temp);
	memset(q_11+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_11+404);
	gf2x_add(8, q_11+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+392+0, 8, q_11+392+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 4
	memset(q_00+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, q_00+392);
	GF2X_MUL(24, temp2, 12, p_10+404+4, 12, q_01+392);
	gf2x_add(24, q_00+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+392+8, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+8, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+364+8, 8, q_00+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+4, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+4, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+364+4, 8, q_00+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+0, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+0, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+364+0, 8, q_00+364+0, 8, temp);
	memset(q_01+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+404+4, 12, q_00+392);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, q_01+392);
	gf2x_add(24, q_01+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+392+8, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+8, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+364+8, 8, q_01+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+4, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+4, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+364+4, 8, q_01+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+0, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+0, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+364+0, 8, q_01+364+0, 8, temp);
	memset(q_10+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, q_10+392);
	GF2X_MUL(24, temp2, 12, p_10+404+4, 12, q_11+392);
	gf2x_add(24, q_10+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+392+8, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+8, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+364+8, 8, q_10+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+4, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+4, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+364+4, 8, q_10+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+0, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+0, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+364+0, 8, q_10+364+0, 8, temp);
	memset(q_11+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+404+4, 12, q_10+392);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, q_11+392);
	gf2x_add(24, q_11+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+392+8, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+8, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+364+8, 8, q_11+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+4, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+4, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+364+4, 8, q_11+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+0, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+0, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+364+0, 8, q_11+364+0, 8, temp);
	

	// Recombining results: n: 3570, depth: 3
	GF2X_MUL(56, temp, 28, q_00+364+0, 28, p_00+376);
	GF2X_MUL(56, temp2, 28, q_01+364+0, 28, p_10+376);
	gf2x_add(56, p_00+320+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_00+364+0, 28, p_01+376);
	GF2X_MUL(56, temp2, 28, q_01+364+0, 28, p_11+376);
	gf2x_add(56, p_01+320+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+364+0, 28, p_00+376);
	GF2X_MUL(56, temp2, 28, q_11+364+0, 28, p_10+376);
	gf2x_add(56, p_10+320+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+364+0, 28, p_01+376);
	GF2X_MUL(56, temp2, 28, q_11+364+0, 28, p_11+376);
	gf2x_add(56, p_11+320+0, 56, temp, 56, temp2);
	

	// Calculating left operands: n: 6885, depth: 2
	// Digits to shift: 55
	// Displacement: 56
	GF2X_MUL(112, temp, 56, f+311+52, 56, p_00+320);
	GF2X_MUL(112, temp2, 56, g+311+52, 56, p_01+320);
	gf2x_add(108, f_sum+953, 108, temp+4, 108, temp2+4);
	GF2X_MUL(104, temp, 52, p_00+320+4, 52, f+311);
	GF2X_MUL(104, temp2, 52, p_01+320+4, 52, g+311);
	gf2x_add(104, temp, 104, temp, 104, temp2);
	gf2x_add(52, f_sum+953, 52, f_sum+953, 52, temp+52);
	right_bit_shift_n(108, f_sum+953, 50);
	GF2X_MUL(112, temp, 56, f+311+52, 56, p_10+320);
	GF2X_MUL(112, temp2, 56, g+311+52, 56, p_11+320);
	gf2x_add(108, g_sum+953, 108, temp+4, 108, temp2+4);
	GF2X_MUL(104, temp, 52, p_10+320+4, 52, f+311);
	GF2X_MUL(104, temp2, 52, p_11+320+4, 52, g+311);
	gf2x_add(104, temp, 104, temp, 104, temp2);
	gf2x_add(52, g_sum+953, 52, g_sum+953, 52, temp+52);
	right_bit_shift_n(108, g_sum+953, 50);
	

	delta = divstepsx_256(255, delta, f_sum+1002, g_sum+1002, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+998+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+998+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+998+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+998+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+998+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+998+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+998+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+998+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+990+8, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+990+8, 8, p_01+420);
	gf2x_add(16, f_sum+1248+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+990+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+990+0, 8, p_01+420);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1248, 8, f_sum+1248, 8, temp+8);
	right_bit_shift_n(16, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+990+8, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+990+8, 8, p_11+420);
	gf2x_add(16, g_sum+1248+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+990+0, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+990+0, 8, p_11+420);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1248, 8, g_sum+1248, 8, temp+8);
	right_bit_shift_n(16, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1253, g_sum+1253, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1249+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1249+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1249+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1249+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, q_00+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, q_01+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, q_10+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, q_11+404+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+404+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, q_01+404+0, 8, p_10+420);
	gf2x_add(16, p_00+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+404+0, 8, p_01+420);
	GF2X_MUL(16, temp2, 8, q_01+404+0, 8, p_11+420);
	gf2x_add(16, p_01+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+404+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, q_11+404+0, 8, p_10+420);
	gf2x_add(16, p_10+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+404+0, 8, p_01+420);
	GF2X_MUL(16, temp2, 8, q_11+404+0, 8, p_11+420);
	gf2x_add(16, p_11+404+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+978+12, 16, p_00+404);
	GF2X_MUL(32, temp2, 16, g_sum+978+12, 16, p_01+404);
	gf2x_add(28, f_sum+1203, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, f_sum+978);
	GF2X_MUL(24, temp2, 12, p_01+404+4, 12, g_sum+978);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1203, 12, f_sum+1203, 12, temp+12);
	right_bit_shift_n(28, f_sum+1203, 60);
	GF2X_MUL(32, temp, 16, f_sum+978+12, 16, p_10+404);
	GF2X_MUL(32, temp2, 16, g_sum+978+12, 16, p_11+404);
	gf2x_add(28, g_sum+1203, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+404+4, 12, f_sum+978);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, g_sum+978);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1203, 12, g_sum+1203, 12, temp+12);
	right_bit_shift_n(28, g_sum+1203, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1212, g_sum+1212, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_01+420);
	gf2x_add(12, f_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_01+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1248, 4, f_sum+1248, 4, temp+4);
	right_bit_shift_n(12, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_11+420);
	gf2x_add(12, g_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1248, 4, g_sum+1248, 4, temp+4);
	right_bit_shift_n(12, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1249, g_sum+1249, q_00+404, q_01+404, q_10+404, q_11+404);

	// Recombining results: n: 765, depth: 5
	memset(q_00+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_01+404);
	gf2x_add(8, q_00+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+392+0, 8, q_00+392+0, 8, temp);
	memset(q_01+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_01+404);
	gf2x_add(8, q_01+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+392+0, 8, q_01+392+0, 8, temp);
	memset(q_10+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_11+404);
	gf2x_add(8, q_10+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+392+0, 8, q_10+392+0, 8, temp);
	memset(q_11+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_11+404);
	gf2x_add(8, q_11+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+392+0, 8, q_11+392+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 4
	memset(p_00+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, q_00+392);
	GF2X_MUL(24, temp2, 12, p_10+404+4, 12, q_01+392);
	gf2x_add(24, p_00+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+392+8, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+8, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+376+8, 8, p_00+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+4, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+4, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+376+4, 8, p_00+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+0, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+0, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+376+0, 8, p_00+376+0, 8, temp);
	memset(p_01+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+404+4, 12, q_00+392);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, q_01+392);
	gf2x_add(24, p_01+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+392+8, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+8, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+376+8, 8, p_01+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+4, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+4, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+376+4, 8, p_01+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+0, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+0, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+376+0, 8, p_01+376+0, 8, temp);
	memset(p_10+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, q_10+392);
	GF2X_MUL(24, temp2, 12, p_10+404+4, 12, q_11+392);
	gf2x_add(24, p_10+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+392+8, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+8, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+376+8, 8, p_10+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+4, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+4, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+376+4, 8, p_10+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+0, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+0, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+376+0, 8, p_10+376+0, 8, temp);
	memset(p_11+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+404+4, 12, q_10+392);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, q_11+392);
	gf2x_add(24, p_11+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+392+8, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+8, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+376+8, 8, p_11+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+4, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+4, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+376+4, 8, p_11+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+0, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+0, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+376+0, 8, p_11+376+0, 8, temp);
	

	// Calculating left operands: n: 3315, depth: 3
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+954+24, 28, p_00+376);
	GF2X_MUL(56, temp2, 28, g_sum+954+24, 28, p_01+376);
	gf2x_add(52, f_sum+1118, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_00+376+4, 24, f_sum+954);
	GF2X_MUL(48, temp2, 24, p_01+376+4, 24, g_sum+954);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+1118, 24, f_sum+1118, 24, temp+24);
	right_bit_shift_n(52, f_sum+1118, 57);
	GF2X_MUL(56, temp, 28, f_sum+954+24, 28, p_10+376);
	GF2X_MUL(56, temp2, 28, g_sum+954+24, 28, p_11+376);
	gf2x_add(52, g_sum+1118, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_10+376+4, 24, f_sum+954);
	GF2X_MUL(48, temp2, 24, p_11+376+4, 24, g_sum+954);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+1118, 24, g_sum+1118, 24, temp+24);
	right_bit_shift_n(52, g_sum+1118, 57);
	

	delta = divstepsx_256(255, delta, f_sum+1139, g_sum+1139, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1135+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1135+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1135+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1135+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1135+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1135+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1135+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1135+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1131+4, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+1131+4, 8, p_01+420);
	gf2x_add(12, f_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, f_sum+1131);
	GF2X_MUL(8, temp2, 4, p_01+420+4, 4, g_sum+1131);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1248, 4, f_sum+1248, 4, temp+4);
	right_bit_shift_n(12, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+1131+4, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+1131+4, 8, p_11+420);
	gf2x_add(12, g_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+420+4, 4, f_sum+1131);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, g_sum+1131);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1248, 4, g_sum+1248, 4, temp+4);
	right_bit_shift_n(12, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1249, g_sum+1249, q_00+404, q_01+404, q_10+404, q_11+404);

	// Recombining results: n: 765, depth: 5
	memset(p_00+404, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_01+404);
	gf2x_add(8, p_00+404+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+404+0, 8, p_00+404+0, 8, temp);
	memset(p_01+404, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_01+404);
	gf2x_add(8, p_01+404+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+404+0, 8, p_01+404+0, 8, temp);
	memset(p_10+404, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_11+404);
	gf2x_add(8, p_10+404+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+404+0, 8, p_10+404+0, 8, temp);
	memset(p_11+404, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_11+404);
	gf2x_add(8, p_11+404+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+404+0, 8, p_11+404+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1119+12, 12, p_00+404);
	GF2X_MUL(24, temp2, 12, g_sum+1119+12, 12, p_01+404);
	gf2x_add(24, f_sum+1203+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1119+0, 12, p_00+404);
	GF2X_MUL(24, temp2, 12, g_sum+1119+0, 12, p_01+404);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1203, 12, f_sum+1203, 12, temp+12);
	right_bit_shift_n(24, f_sum+1203, 61);
	GF2X_MUL(24, temp, 12, f_sum+1119+12, 12, p_10+404);
	GF2X_MUL(24, temp2, 12, g_sum+1119+12, 12, p_11+404);
	gf2x_add(24, g_sum+1203+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1119+0, 12, p_10+404);
	GF2X_MUL(24, temp2, 12, g_sum+1119+0, 12, p_11+404);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1203, 12, g_sum+1203, 12, temp+12);
	right_bit_shift_n(24, g_sum+1203, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1212, g_sum+1212, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_01+420);
	gf2x_add(12, f_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_01+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1248, 4, f_sum+1248, 4, temp+4);
	right_bit_shift_n(12, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_11+420);
	gf2x_add(12, g_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1248, 4, g_sum+1248, 4, temp+4);
	right_bit_shift_n(12, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1249, g_sum+1249, q_00+404, q_01+404, q_10+404, q_11+404);

	// Recombining results: n: 765, depth: 5
	memset(q_00+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_01+404);
	gf2x_add(8, q_00+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+392+0, 8, q_00+392+0, 8, temp);
	memset(q_01+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_01+404);
	gf2x_add(8, q_01+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+392+0, 8, q_01+392+0, 8, temp);
	memset(q_10+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_11+404);
	gf2x_add(8, q_10+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+392+0, 8, q_10+392+0, 8, temp);
	memset(q_11+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_11+404);
	gf2x_add(8, q_11+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+392+0, 8, q_11+392+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 4
	GF2X_MUL(24, temp, 12, q_00+392+0, 12, p_00+404);
	GF2X_MUL(24, temp2, 12, q_01+392+0, 12, p_10+404);
	gf2x_add(24, q_00+364+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+392+0, 12, p_01+404);
	GF2X_MUL(24, temp2, 12, q_01+392+0, 12, p_11+404);
	gf2x_add(24, q_01+364+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+392+0, 12, p_00+404);
	GF2X_MUL(24, temp2, 12, q_11+392+0, 12, p_10+404);
	gf2x_add(24, q_10+364+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+392+0, 12, p_01+404);
	GF2X_MUL(24, temp2, 12, q_11+392+0, 12, p_11+404);
	gf2x_add(24, q_11+364+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3315, depth: 3
	memset(q_00+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+376+4, 24, q_00+364);
	GF2X_MUL(48, temp2, 24, p_10+376+4, 24, q_01+364);
	gf2x_add(48, q_00+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+364+20, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+20, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+312+20, 8, q_00+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+16, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+16, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+312+16, 8, q_00+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+12, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+12, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+312+12, 8, q_00+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+8, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+8, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+312+8, 8, q_00+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+4, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+4, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+312+4, 8, q_00+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+0, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+0, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+312+0, 8, q_00+312+0, 8, temp);
	memset(q_01+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+376+4, 24, q_00+364);
	GF2X_MUL(48, temp2, 24, p_11+376+4, 24, q_01+364);
	gf2x_add(48, q_01+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+364+20, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+20, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+312+20, 8, q_01+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+16, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+16, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+312+16, 8, q_01+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+12, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+12, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+312+12, 8, q_01+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+8, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+8, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+312+8, 8, q_01+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+4, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+4, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+312+4, 8, q_01+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+0, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+0, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+312+0, 8, q_01+312+0, 8, temp);
	memset(q_10+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+376+4, 24, q_10+364);
	GF2X_MUL(48, temp2, 24, p_10+376+4, 24, q_11+364);
	gf2x_add(48, q_10+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+364+20, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+20, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+312+20, 8, q_10+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+16, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+16, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+312+16, 8, q_10+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+12, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+12, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+312+12, 8, q_10+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+8, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+8, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+312+8, 8, q_10+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+4, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+4, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+312+4, 8, q_10+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+0, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+0, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+312+0, 8, q_10+312+0, 8, temp);
	memset(q_11+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+376+4, 24, q_10+364);
	GF2X_MUL(48, temp2, 24, p_11+376+4, 24, q_11+364);
	gf2x_add(48, q_11+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+364+20, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+20, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+312+20, 8, q_11+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+16, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+16, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+312+16, 8, q_11+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+12, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+12, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+312+12, 8, q_11+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+8, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+8, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+312+8, 8, q_11+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+4, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+4, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+312+4, 8, q_11+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+0, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+0, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+312+0, 8, q_11+312+0, 8, temp);
	

	// Recombining results: n: 6885, depth: 2
	memset(p_00+212, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(104, temp, 52, p_00+320+4, 52, q_00+312);
	GF2X_MUL(104, temp2, 52, p_10+320+4, 52, q_01+312);
	gf2x_add(104, p_00+212+4, 104, temp, 104, temp2);
	GF2X_MUL(8, temp, 4, q_00+312+48, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_01+312+48, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+212+48, 8, p_00+212+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+44, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_01+312+44, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+212+44, 8, p_00+212+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+40, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_01+312+40, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+212+40, 8, p_00+212+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+36, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_01+312+36, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+212+36, 8, p_00+212+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+32, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_01+312+32, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+212+32, 8, p_00+212+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+28, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_01+312+28, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+212+28, 8, p_00+212+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+24, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_01+312+24, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+212+24, 8, p_00+212+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+20, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_01+312+20, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+212+20, 8, p_00+212+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+16, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_01+312+16, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+212+16, 8, p_00+212+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+12, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_01+312+12, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+212+12, 8, p_00+212+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+8, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_01+312+8, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+212+8, 8, p_00+212+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+4, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_01+312+4, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+212+4, 8, p_00+212+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+0, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_01+312+0, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+212+0, 8, p_00+212+0, 8, temp);
	memset(p_01+212, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(104, temp, 52, p_01+320+4, 52, q_00+312);
	GF2X_MUL(104, temp2, 52, p_11+320+4, 52, q_01+312);
	gf2x_add(104, p_01+212+4, 104, temp, 104, temp2);
	GF2X_MUL(8, temp, 4, q_00+312+48, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_01+312+48, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+212+48, 8, p_01+212+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+44, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_01+312+44, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+212+44, 8, p_01+212+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+40, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_01+312+40, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+212+40, 8, p_01+212+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+36, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_01+312+36, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+212+36, 8, p_01+212+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+32, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_01+312+32, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+212+32, 8, p_01+212+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+28, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_01+312+28, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+212+28, 8, p_01+212+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+24, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_01+312+24, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+212+24, 8, p_01+212+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+20, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_01+312+20, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+212+20, 8, p_01+212+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+16, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_01+312+16, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+212+16, 8, p_01+212+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+12, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_01+312+12, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+212+12, 8, p_01+212+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+8, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_01+312+8, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+212+8, 8, p_01+212+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+4, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_01+312+4, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+212+4, 8, p_01+212+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+0, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_01+312+0, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+212+0, 8, p_01+212+0, 8, temp);
	memset(p_10+212, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(104, temp, 52, p_00+320+4, 52, q_10+312);
	GF2X_MUL(104, temp2, 52, p_10+320+4, 52, q_11+312);
	gf2x_add(104, p_10+212+4, 104, temp, 104, temp2);
	GF2X_MUL(8, temp, 4, q_10+312+48, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_11+312+48, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+212+48, 8, p_10+212+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+44, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_11+312+44, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+212+44, 8, p_10+212+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+40, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_11+312+40, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+212+40, 8, p_10+212+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+36, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_11+312+36, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+212+36, 8, p_10+212+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+32, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_11+312+32, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+212+32, 8, p_10+212+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+28, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_11+312+28, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+212+28, 8, p_10+212+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+24, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_11+312+24, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+212+24, 8, p_10+212+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+20, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_11+312+20, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+212+20, 8, p_10+212+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+16, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_11+312+16, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+212+16, 8, p_10+212+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+12, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_11+312+12, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+212+12, 8, p_10+212+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+8, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_11+312+8, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+212+8, 8, p_10+212+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+4, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_11+312+4, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+212+4, 8, p_10+212+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+0, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_11+312+0, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+212+0, 8, p_10+212+0, 8, temp);
	memset(p_11+212, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(104, temp, 52, p_01+320+4, 52, q_10+312);
	GF2X_MUL(104, temp2, 52, p_11+320+4, 52, q_11+312);
	gf2x_add(104, p_11+212+4, 104, temp, 104, temp2);
	GF2X_MUL(8, temp, 4, q_10+312+48, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_11+312+48, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+212+48, 8, p_11+212+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+44, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_11+312+44, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+212+44, 8, p_11+212+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+40, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_11+312+40, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+212+40, 8, p_11+212+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+36, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_11+312+36, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+212+36, 8, p_11+212+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+32, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_11+312+32, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+212+32, 8, p_11+212+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+28, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_11+312+28, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+212+28, 8, p_11+212+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+24, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_11+312+24, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+212+24, 8, p_11+212+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+20, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_11+312+20, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+212+20, 8, p_11+212+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+16, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_11+312+16, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+212+16, 8, p_11+212+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+12, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_11+312+12, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+212+12, 8, p_11+212+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+8, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_11+312+8, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+212+8, 8, p_11+212+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+4, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_11+312+4, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+212+4, 8, p_11+212+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+0, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_11+312+0, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+212+0, 8, p_11+212+0, 8, temp);
	

	// Calculating left operands: n: 13515, depth: 1
	// Digits to shift: 107
	// Displacement: 108
	GF2X_MUL(216, temp, 108, f+207+104, 108, p_00+212);
	GF2X_MUL(216, temp2, 108, g+207+104, 108, p_01+212);
	gf2x_add(212, f_sum+632, 212, temp+4, 212, temp2+4);
	GF2X_MUL(208, temp, 104, p_00+212+4, 104, f+207);
	GF2X_MUL(208, temp2, 104, p_01+212+4, 104, g+207);
	gf2x_add(208, temp, 208, temp, 208, temp2);
	gf2x_add(104, f_sum+632, 104, f_sum+632, 104, temp+104);
	right_bit_shift_n(212, f_sum+632, 37);
	GF2X_MUL(216, temp, 108, f+207+104, 108, p_10+212);
	GF2X_MUL(216, temp2, 108, g+207+104, 108, p_11+212);
	gf2x_add(212, g_sum+632, 212, temp+4, 212, temp2+4);
	GF2X_MUL(208, temp, 104, p_10+212+4, 104, f+207);
	GF2X_MUL(208, temp2, 104, p_11+212+4, 104, g+207);
	gf2x_add(208, temp, 208, temp, 208, temp2);
	gf2x_add(104, g_sum+632, 104, g_sum+632, 104, temp+104);
	right_bit_shift_n(212, g_sum+632, 37);
	

	delta = divstepsx_256(255, delta, f_sum+733, g_sum+733, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+729+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+729+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+729+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+729+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+729+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+729+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+729+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+729+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+721+8, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+721+8, 8, p_01+420);
	gf2x_add(16, f_sum+1248+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+721+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+721+0, 8, p_01+420);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1248, 8, f_sum+1248, 8, temp+8);
	right_bit_shift_n(16, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+721+8, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+721+8, 8, p_11+420);
	gf2x_add(16, g_sum+1248+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+721+0, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+721+0, 8, p_11+420);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1248, 8, g_sum+1248, 8, temp+8);
	right_bit_shift_n(16, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1253, g_sum+1253, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1249+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1249+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1249+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1249+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, q_00+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, q_01+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, q_10+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, q_11+404+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+404+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, q_01+404+0, 8, p_10+420);
	gf2x_add(16, p_00+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+404+0, 8, p_01+420);
	GF2X_MUL(16, temp2, 8, q_01+404+0, 8, p_11+420);
	gf2x_add(16, p_01+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+404+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, q_11+404+0, 8, p_10+420);
	gf2x_add(16, p_10+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+404+0, 8, p_01+420);
	GF2X_MUL(16, temp2, 8, q_11+404+0, 8, p_11+420);
	gf2x_add(16, p_11+404+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+709+12, 16, p_00+404);
	GF2X_MUL(32, temp2, 16, g_sum+709+12, 16, p_01+404);
	gf2x_add(28, f_sum+1203, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, f_sum+709);
	GF2X_MUL(24, temp2, 12, p_01+404+4, 12, g_sum+709);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1203, 12, f_sum+1203, 12, temp+12);
	right_bit_shift_n(28, f_sum+1203, 60);
	GF2X_MUL(32, temp, 16, f_sum+709+12, 16, p_10+404);
	GF2X_MUL(32, temp2, 16, g_sum+709+12, 16, p_11+404);
	gf2x_add(28, g_sum+1203, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+404+4, 12, f_sum+709);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, g_sum+709);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1203, 12, g_sum+1203, 12, temp+12);
	right_bit_shift_n(28, g_sum+1203, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1212, g_sum+1212, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_01+420);
	gf2x_add(12, f_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_01+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1248, 4, f_sum+1248, 4, temp+4);
	right_bit_shift_n(12, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_11+420);
	gf2x_add(12, g_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1248, 4, g_sum+1248, 4, temp+4);
	right_bit_shift_n(12, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1249, g_sum+1249, q_00+404, q_01+404, q_10+404, q_11+404);

	// Recombining results: n: 765, depth: 5
	memset(q_00+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_01+404);
	gf2x_add(8, q_00+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+392+0, 8, q_00+392+0, 8, temp);
	memset(q_01+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_01+404);
	gf2x_add(8, q_01+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+392+0, 8, q_01+392+0, 8, temp);
	memset(q_10+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_11+404);
	gf2x_add(8, q_10+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+392+0, 8, q_10+392+0, 8, temp);
	memset(q_11+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_11+404);
	gf2x_add(8, q_11+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+392+0, 8, q_11+392+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 4
	memset(p_00+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, q_00+392);
	GF2X_MUL(24, temp2, 12, p_10+404+4, 12, q_01+392);
	gf2x_add(24, p_00+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+392+8, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+8, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+376+8, 8, p_00+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+4, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+4, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+376+4, 8, p_00+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+0, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+0, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+376+0, 8, p_00+376+0, 8, temp);
	memset(p_01+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+404+4, 12, q_00+392);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, q_01+392);
	gf2x_add(24, p_01+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+392+8, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+8, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+376+8, 8, p_01+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+4, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+4, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+376+4, 8, p_01+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+0, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+0, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+376+0, 8, p_01+376+0, 8, temp);
	memset(p_10+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, q_10+392);
	GF2X_MUL(24, temp2, 12, p_10+404+4, 12, q_11+392);
	gf2x_add(24, p_10+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+392+8, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+8, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+376+8, 8, p_10+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+4, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+4, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+376+4, 8, p_10+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+0, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+0, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+376+0, 8, p_10+376+0, 8, temp);
	memset(p_11+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+404+4, 12, q_10+392);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, q_11+392);
	gf2x_add(24, p_11+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+392+8, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+8, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+376+8, 8, p_11+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+4, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+4, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+376+4, 8, p_11+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+0, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+0, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+376+0, 8, p_11+376+0, 8, temp);
	

	// Calculating left operands: n: 3315, depth: 3
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+685+24, 28, p_00+376);
	GF2X_MUL(56, temp2, 28, g_sum+685+24, 28, p_01+376);
	gf2x_add(52, f_sum+1118, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_00+376+4, 24, f_sum+685);
	GF2X_MUL(48, temp2, 24, p_01+376+4, 24, g_sum+685);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+1118, 24, f_sum+1118, 24, temp+24);
	right_bit_shift_n(52, f_sum+1118, 57);
	GF2X_MUL(56, temp, 28, f_sum+685+24, 28, p_10+376);
	GF2X_MUL(56, temp2, 28, g_sum+685+24, 28, p_11+376);
	gf2x_add(52, g_sum+1118, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_10+376+4, 24, f_sum+685);
	GF2X_MUL(48, temp2, 24, p_11+376+4, 24, g_sum+685);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+1118, 24, g_sum+1118, 24, temp+24);
	right_bit_shift_n(52, g_sum+1118, 57);
	

	delta = divstepsx_256(255, delta, f_sum+1139, g_sum+1139, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1135+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1135+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1135+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1135+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1135+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1135+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1135+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1135+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1131+4, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+1131+4, 8, p_01+420);
	gf2x_add(12, f_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, f_sum+1131);
	GF2X_MUL(8, temp2, 4, p_01+420+4, 4, g_sum+1131);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1248, 4, f_sum+1248, 4, temp+4);
	right_bit_shift_n(12, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+1131+4, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+1131+4, 8, p_11+420);
	gf2x_add(12, g_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+420+4, 4, f_sum+1131);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, g_sum+1131);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1248, 4, g_sum+1248, 4, temp+4);
	right_bit_shift_n(12, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1249, g_sum+1249, q_00+404, q_01+404, q_10+404, q_11+404);

	// Recombining results: n: 765, depth: 5
	memset(p_00+404, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_01+404);
	gf2x_add(8, p_00+404+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+404+0, 8, p_00+404+0, 8, temp);
	memset(p_01+404, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_01+404);
	gf2x_add(8, p_01+404+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+404+0, 8, p_01+404+0, 8, temp);
	memset(p_10+404, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_11+404);
	gf2x_add(8, p_10+404+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+404+0, 8, p_10+404+0, 8, temp);
	memset(p_11+404, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_11+404);
	gf2x_add(8, p_11+404+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+404+0, 8, p_11+404+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1119+12, 12, p_00+404);
	GF2X_MUL(24, temp2, 12, g_sum+1119+12, 12, p_01+404);
	gf2x_add(24, f_sum+1203+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1119+0, 12, p_00+404);
	GF2X_MUL(24, temp2, 12, g_sum+1119+0, 12, p_01+404);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1203, 12, f_sum+1203, 12, temp+12);
	right_bit_shift_n(24, f_sum+1203, 61);
	GF2X_MUL(24, temp, 12, f_sum+1119+12, 12, p_10+404);
	GF2X_MUL(24, temp2, 12, g_sum+1119+12, 12, p_11+404);
	gf2x_add(24, g_sum+1203+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1119+0, 12, p_10+404);
	GF2X_MUL(24, temp2, 12, g_sum+1119+0, 12, p_11+404);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1203, 12, g_sum+1203, 12, temp+12);
	right_bit_shift_n(24, g_sum+1203, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1212, g_sum+1212, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_01+420);
	gf2x_add(12, f_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_01+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1248, 4, f_sum+1248, 4, temp+4);
	right_bit_shift_n(12, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_11+420);
	gf2x_add(12, g_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1248, 4, g_sum+1248, 4, temp+4);
	right_bit_shift_n(12, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1249, g_sum+1249, q_00+404, q_01+404, q_10+404, q_11+404);

	// Recombining results: n: 765, depth: 5
	memset(q_00+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_01+404);
	gf2x_add(8, q_00+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+392+0, 8, q_00+392+0, 8, temp);
	memset(q_01+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_01+404);
	gf2x_add(8, q_01+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+392+0, 8, q_01+392+0, 8, temp);
	memset(q_10+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_11+404);
	gf2x_add(8, q_10+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+392+0, 8, q_10+392+0, 8, temp);
	memset(q_11+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_11+404);
	gf2x_add(8, q_11+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+392+0, 8, q_11+392+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 4
	GF2X_MUL(24, temp, 12, q_00+392+0, 12, p_00+404);
	GF2X_MUL(24, temp2, 12, q_01+392+0, 12, p_10+404);
	gf2x_add(24, q_00+364+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+392+0, 12, p_01+404);
	GF2X_MUL(24, temp2, 12, q_01+392+0, 12, p_11+404);
	gf2x_add(24, q_01+364+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+392+0, 12, p_00+404);
	GF2X_MUL(24, temp2, 12, q_11+392+0, 12, p_10+404);
	gf2x_add(24, q_10+364+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+392+0, 12, p_01+404);
	GF2X_MUL(24, temp2, 12, q_11+392+0, 12, p_11+404);
	gf2x_add(24, q_11+364+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3315, depth: 3
	memset(p_00+320, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+376+4, 24, q_00+364);
	GF2X_MUL(48, temp2, 24, p_10+376+4, 24, q_01+364);
	gf2x_add(48, p_00+320+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+364+20, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+20, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+320+20, 8, p_00+320+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+16, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+16, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+320+16, 8, p_00+320+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+12, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+12, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+320+12, 8, p_00+320+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+8, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+8, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+320+8, 8, p_00+320+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+4, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+4, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+320+4, 8, p_00+320+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+0, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+0, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+320+0, 8, p_00+320+0, 8, temp);
	memset(p_01+320, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+376+4, 24, q_00+364);
	GF2X_MUL(48, temp2, 24, p_11+376+4, 24, q_01+364);
	gf2x_add(48, p_01+320+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+364+20, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+20, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+320+20, 8, p_01+320+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+16, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+16, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+320+16, 8, p_01+320+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+12, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+12, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+320+12, 8, p_01+320+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+8, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+8, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+320+8, 8, p_01+320+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+4, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+4, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+320+4, 8, p_01+320+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+0, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+0, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+320+0, 8, p_01+320+0, 8, temp);
	memset(p_10+320, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+376+4, 24, q_10+364);
	GF2X_MUL(48, temp2, 24, p_10+376+4, 24, q_11+364);
	gf2x_add(48, p_10+320+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+364+20, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+20, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+320+20, 8, p_10+320+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+16, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+16, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+320+16, 8, p_10+320+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+12, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+12, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+320+12, 8, p_10+320+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+8, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+8, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+320+8, 8, p_10+320+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+4, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+4, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+320+4, 8, p_10+320+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+0, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+0, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+320+0, 8, p_10+320+0, 8, temp);
	memset(p_11+320, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+376+4, 24, q_10+364);
	GF2X_MUL(48, temp2, 24, p_11+376+4, 24, q_11+364);
	gf2x_add(48, p_11+320+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+364+20, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+20, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+320+20, 8, p_11+320+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+16, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+16, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+320+16, 8, p_11+320+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+12, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+12, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+320+12, 8, p_11+320+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+8, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+8, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+320+8, 8, p_11+320+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+4, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+4, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+320+4, 8, p_11+320+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+0, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+0, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+320+0, 8, p_11+320+0, 8, temp);
	

	// Calculating left operands: n: 6630, depth: 2
	// Digits to shift: 51
	// Displacement: 52
	GF2X_MUL(104, temp, 52, f_sum+633+52, 52, p_00+320);
	GF2X_MUL(104, temp2, 52, g_sum+633+52, 52, p_01+320);
	gf2x_add(104, f_sum+953+0, 104, temp, 104, temp2);
	GF2X_MUL(104, temp, 52, f_sum+633+0, 52, p_00+320);
	GF2X_MUL(104, temp2, 52, g_sum+633+0, 52, p_01+320);
	gf2x_add(104, temp, 104, temp, 104, temp2);
	gf2x_add(52, f_sum+953, 52, f_sum+953, 52, temp+52);
	right_bit_shift_n(104, f_sum+953, 51);
	GF2X_MUL(104, temp, 52, f_sum+633+52, 52, p_10+320);
	GF2X_MUL(104, temp2, 52, g_sum+633+52, 52, p_11+320);
	gf2x_add(104, g_sum+953+0, 104, temp, 104, temp2);
	GF2X_MUL(104, temp, 52, f_sum+633+0, 52, p_10+320);
	GF2X_MUL(104, temp2, 52, g_sum+633+0, 52, p_11+320);
	gf2x_add(104, temp, 104, temp, 104, temp2);
	gf2x_add(52, g_sum+953, 52, g_sum+953, 52, temp+52);
	right_bit_shift_n(104, g_sum+953, 51);
	

	delta = divstepsx_256(255, delta, f_sum+1002, g_sum+1002, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+998+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+998+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+998+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+998+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+998+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+998+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+998+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+998+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+990+8, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+990+8, 8, p_01+420);
	gf2x_add(16, f_sum+1248+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+990+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+990+0, 8, p_01+420);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1248, 8, f_sum+1248, 8, temp+8);
	right_bit_shift_n(16, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+990+8, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+990+8, 8, p_11+420);
	gf2x_add(16, g_sum+1248+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+990+0, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+990+0, 8, p_11+420);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1248, 8, g_sum+1248, 8, temp+8);
	right_bit_shift_n(16, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1253, g_sum+1253, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1249+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1249+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1249+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1249+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, q_00+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, q_01+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, q_10+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, q_11+404+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+404+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, q_01+404+0, 8, p_10+420);
	gf2x_add(16, p_00+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+404+0, 8, p_01+420);
	GF2X_MUL(16, temp2, 8, q_01+404+0, 8, p_11+420);
	gf2x_add(16, p_01+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+404+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, q_11+404+0, 8, p_10+420);
	gf2x_add(16, p_10+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+404+0, 8, p_01+420);
	GF2X_MUL(16, temp2, 8, q_11+404+0, 8, p_11+420);
	gf2x_add(16, p_11+404+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+978+12, 16, p_00+404);
	GF2X_MUL(32, temp2, 16, g_sum+978+12, 16, p_01+404);
	gf2x_add(28, f_sum+1203, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, f_sum+978);
	GF2X_MUL(24, temp2, 12, p_01+404+4, 12, g_sum+978);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1203, 12, f_sum+1203, 12, temp+12);
	right_bit_shift_n(28, f_sum+1203, 60);
	GF2X_MUL(32, temp, 16, f_sum+978+12, 16, p_10+404);
	GF2X_MUL(32, temp2, 16, g_sum+978+12, 16, p_11+404);
	gf2x_add(28, g_sum+1203, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+404+4, 12, f_sum+978);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, g_sum+978);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1203, 12, g_sum+1203, 12, temp+12);
	right_bit_shift_n(28, g_sum+1203, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1212, g_sum+1212, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_01+420);
	gf2x_add(12, f_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_01+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1248, 4, f_sum+1248, 4, temp+4);
	right_bit_shift_n(12, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_11+420);
	gf2x_add(12, g_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1248, 4, g_sum+1248, 4, temp+4);
	right_bit_shift_n(12, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1249, g_sum+1249, q_00+404, q_01+404, q_10+404, q_11+404);

	// Recombining results: n: 765, depth: 5
	memset(q_00+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_01+404);
	gf2x_add(8, q_00+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+392+0, 8, q_00+392+0, 8, temp);
	memset(q_01+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_01+404);
	gf2x_add(8, q_01+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+392+0, 8, q_01+392+0, 8, temp);
	memset(q_10+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_11+404);
	gf2x_add(8, q_10+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+392+0, 8, q_10+392+0, 8, temp);
	memset(q_11+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_11+404);
	gf2x_add(8, q_11+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+392+0, 8, q_11+392+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 4
	memset(p_00+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, q_00+392);
	GF2X_MUL(24, temp2, 12, p_10+404+4, 12, q_01+392);
	gf2x_add(24, p_00+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+392+8, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+8, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+376+8, 8, p_00+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+4, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+4, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+376+4, 8, p_00+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+0, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+0, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+376+0, 8, p_00+376+0, 8, temp);
	memset(p_01+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+404+4, 12, q_00+392);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, q_01+392);
	gf2x_add(24, p_01+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+392+8, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+8, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+376+8, 8, p_01+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+4, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+4, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+376+4, 8, p_01+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+0, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+0, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+376+0, 8, p_01+376+0, 8, temp);
	memset(p_10+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, q_10+392);
	GF2X_MUL(24, temp2, 12, p_10+404+4, 12, q_11+392);
	gf2x_add(24, p_10+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+392+8, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+8, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+376+8, 8, p_10+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+4, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+4, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+376+4, 8, p_10+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+0, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+0, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+376+0, 8, p_10+376+0, 8, temp);
	memset(p_11+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+404+4, 12, q_10+392);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, q_11+392);
	gf2x_add(24, p_11+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+392+8, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+8, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+376+8, 8, p_11+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+4, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+4, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+376+4, 8, p_11+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+0, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+0, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+376+0, 8, p_11+376+0, 8, temp);
	

	// Calculating left operands: n: 3315, depth: 3
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+954+24, 28, p_00+376);
	GF2X_MUL(56, temp2, 28, g_sum+954+24, 28, p_01+376);
	gf2x_add(52, f_sum+1118, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_00+376+4, 24, f_sum+954);
	GF2X_MUL(48, temp2, 24, p_01+376+4, 24, g_sum+954);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+1118, 24, f_sum+1118, 24, temp+24);
	right_bit_shift_n(52, f_sum+1118, 57);
	GF2X_MUL(56, temp, 28, f_sum+954+24, 28, p_10+376);
	GF2X_MUL(56, temp2, 28, g_sum+954+24, 28, p_11+376);
	gf2x_add(52, g_sum+1118, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_10+376+4, 24, f_sum+954);
	GF2X_MUL(48, temp2, 24, p_11+376+4, 24, g_sum+954);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+1118, 24, g_sum+1118, 24, temp+24);
	right_bit_shift_n(52, g_sum+1118, 57);
	

	delta = divstepsx_256(255, delta, f_sum+1139, g_sum+1139, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1135+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1135+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1135+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1135+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1135+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1135+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1135+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1135+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1131+4, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+1131+4, 8, p_01+420);
	gf2x_add(12, f_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, f_sum+1131);
	GF2X_MUL(8, temp2, 4, p_01+420+4, 4, g_sum+1131);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1248, 4, f_sum+1248, 4, temp+4);
	right_bit_shift_n(12, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+1131+4, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+1131+4, 8, p_11+420);
	gf2x_add(12, g_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+420+4, 4, f_sum+1131);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, g_sum+1131);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1248, 4, g_sum+1248, 4, temp+4);
	right_bit_shift_n(12, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1249, g_sum+1249, q_00+404, q_01+404, q_10+404, q_11+404);

	// Recombining results: n: 765, depth: 5
	memset(p_00+404, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_01+404);
	gf2x_add(8, p_00+404+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+404+0, 8, p_00+404+0, 8, temp);
	memset(p_01+404, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_01+404);
	gf2x_add(8, p_01+404+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+404+0, 8, p_01+404+0, 8, temp);
	memset(p_10+404, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_11+404);
	gf2x_add(8, p_10+404+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+404+0, 8, p_10+404+0, 8, temp);
	memset(p_11+404, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_11+404);
	gf2x_add(8, p_11+404+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+404+0, 8, p_11+404+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1119+12, 12, p_00+404);
	GF2X_MUL(24, temp2, 12, g_sum+1119+12, 12, p_01+404);
	gf2x_add(24, f_sum+1203+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1119+0, 12, p_00+404);
	GF2X_MUL(24, temp2, 12, g_sum+1119+0, 12, p_01+404);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1203, 12, f_sum+1203, 12, temp+12);
	right_bit_shift_n(24, f_sum+1203, 61);
	GF2X_MUL(24, temp, 12, f_sum+1119+12, 12, p_10+404);
	GF2X_MUL(24, temp2, 12, g_sum+1119+12, 12, p_11+404);
	gf2x_add(24, g_sum+1203+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1119+0, 12, p_10+404);
	GF2X_MUL(24, temp2, 12, g_sum+1119+0, 12, p_11+404);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1203, 12, g_sum+1203, 12, temp+12);
	right_bit_shift_n(24, g_sum+1203, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1212, g_sum+1212, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_01+420);
	gf2x_add(12, f_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_01+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1248, 4, f_sum+1248, 4, temp+4);
	right_bit_shift_n(12, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_11+420);
	gf2x_add(12, g_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1248, 4, g_sum+1248, 4, temp+4);
	right_bit_shift_n(12, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1249, g_sum+1249, q_00+404, q_01+404, q_10+404, q_11+404);

	// Recombining results: n: 765, depth: 5
	memset(q_00+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_01+404);
	gf2x_add(8, q_00+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+392+0, 8, q_00+392+0, 8, temp);
	memset(q_01+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_01+404);
	gf2x_add(8, q_01+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+392+0, 8, q_01+392+0, 8, temp);
	memset(q_10+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_11+404);
	gf2x_add(8, q_10+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+392+0, 8, q_10+392+0, 8, temp);
	memset(q_11+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_11+404);
	gf2x_add(8, q_11+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+392+0, 8, q_11+392+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 4
	GF2X_MUL(24, temp, 12, q_00+392+0, 12, p_00+404);
	GF2X_MUL(24, temp2, 12, q_01+392+0, 12, p_10+404);
	gf2x_add(24, q_00+364+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+392+0, 12, p_01+404);
	GF2X_MUL(24, temp2, 12, q_01+392+0, 12, p_11+404);
	gf2x_add(24, q_01+364+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+392+0, 12, p_00+404);
	GF2X_MUL(24, temp2, 12, q_11+392+0, 12, p_10+404);
	gf2x_add(24, q_10+364+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+392+0, 12, p_01+404);
	GF2X_MUL(24, temp2, 12, q_11+392+0, 12, p_11+404);
	gf2x_add(24, q_11+364+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3315, depth: 3
	memset(q_00+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+376+4, 24, q_00+364);
	GF2X_MUL(48, temp2, 24, p_10+376+4, 24, q_01+364);
	gf2x_add(48, q_00+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+364+20, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+20, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+312+20, 8, q_00+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+16, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+16, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+312+16, 8, q_00+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+12, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+12, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+312+12, 8, q_00+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+8, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+8, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+312+8, 8, q_00+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+4, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+4, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+312+4, 8, q_00+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+0, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+0, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+312+0, 8, q_00+312+0, 8, temp);
	memset(q_01+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+376+4, 24, q_00+364);
	GF2X_MUL(48, temp2, 24, p_11+376+4, 24, q_01+364);
	gf2x_add(48, q_01+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+364+20, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+20, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+312+20, 8, q_01+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+16, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+16, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+312+16, 8, q_01+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+12, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+12, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+312+12, 8, q_01+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+8, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+8, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+312+8, 8, q_01+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+4, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+4, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+312+4, 8, q_01+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+0, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+0, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+312+0, 8, q_01+312+0, 8, temp);
	memset(q_10+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+376+4, 24, q_10+364);
	GF2X_MUL(48, temp2, 24, p_10+376+4, 24, q_11+364);
	gf2x_add(48, q_10+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+364+20, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+20, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+312+20, 8, q_10+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+16, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+16, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+312+16, 8, q_10+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+12, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+12, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+312+12, 8, q_10+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+8, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+8, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+312+8, 8, q_10+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+4, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+4, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+312+4, 8, q_10+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+0, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+0, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+312+0, 8, q_10+312+0, 8, temp);
	memset(q_11+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+376+4, 24, q_10+364);
	GF2X_MUL(48, temp2, 24, p_11+376+4, 24, q_11+364);
	gf2x_add(48, q_11+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+364+20, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+20, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+312+20, 8, q_11+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+16, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+16, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+312+16, 8, q_11+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+12, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+12, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+312+12, 8, q_11+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+8, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+8, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+312+8, 8, q_11+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+4, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+4, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+312+4, 8, q_11+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+0, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+0, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+312+0, 8, q_11+312+0, 8, temp);
	

	// Recombining results: n: 6630, depth: 2
	GF2X_MUL(104, temp, 52, q_00+312+0, 52, p_00+320);
	GF2X_MUL(104, temp2, 52, q_01+312+0, 52, p_10+320);
	gf2x_add(104, q_00+208+0, 104, temp, 104, temp2);
	GF2X_MUL(104, temp, 52, q_00+312+0, 52, p_01+320);
	GF2X_MUL(104, temp2, 52, q_01+312+0, 52, p_11+320);
	gf2x_add(104, q_01+208+0, 104, temp, 104, temp2);
	GF2X_MUL(104, temp, 52, q_10+312+0, 52, p_00+320);
	GF2X_MUL(104, temp2, 52, q_11+312+0, 52, p_10+320);
	gf2x_add(104, q_10+208+0, 104, temp, 104, temp2);
	GF2X_MUL(104, temp, 52, q_10+312+0, 52, p_01+320);
	GF2X_MUL(104, temp2, 52, q_11+312+0, 52, p_11+320);
	gf2x_add(104, q_11+208+0, 104, temp, 104, temp2);
	

	// Recombining results: n: 13515, depth: 1
	memset(p_00+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(208, temp, 104, p_00+212+4, 104, q_00+208);
	GF2X_MUL(208, temp2, 104, p_10+212+4, 104, q_01+208);
	gf2x_add(208, p_00+0+4, 208, temp, 208, temp2);
	GF2X_MUL(8, temp, 4, q_00+208+100, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_01+208+100, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+100, 8, p_00+0+100, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+96, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_01+208+96, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+96, 8, p_00+0+96, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+92, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_01+208+92, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+92, 8, p_00+0+92, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+88, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_01+208+88, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+88, 8, p_00+0+88, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+84, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_01+208+84, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+84, 8, p_00+0+84, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+80, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_01+208+80, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+80, 8, p_00+0+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+76, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_01+208+76, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+76, 8, p_00+0+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+72, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_01+208+72, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+72, 8, p_00+0+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+68, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_01+208+68, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+68, 8, p_00+0+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+64, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_01+208+64, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+64, 8, p_00+0+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+60, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_01+208+60, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+60, 8, p_00+0+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+56, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_01+208+56, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+56, 8, p_00+0+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+52, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_01+208+52, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+52, 8, p_00+0+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+48, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_01+208+48, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+48, 8, p_00+0+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+44, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_01+208+44, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+44, 8, p_00+0+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+40, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_01+208+40, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+40, 8, p_00+0+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+36, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_01+208+36, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+36, 8, p_00+0+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+32, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_01+208+32, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+32, 8, p_00+0+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+28, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_01+208+28, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+28, 8, p_00+0+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+24, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_01+208+24, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+24, 8, p_00+0+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+20, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_01+208+20, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+20, 8, p_00+0+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+16, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_01+208+16, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+16, 8, p_00+0+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+12, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_01+208+12, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+12, 8, p_00+0+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+8, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_01+208+8, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+8, 8, p_00+0+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+4, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_01+208+4, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+4, 8, p_00+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+0, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_01+208+0, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+0, 8, p_00+0+0, 8, temp);
	memset(p_01+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(208, temp, 104, p_01+212+4, 104, q_00+208);
	GF2X_MUL(208, temp2, 104, p_11+212+4, 104, q_01+208);
	gf2x_add(208, p_01+0+4, 208, temp, 208, temp2);
	GF2X_MUL(8, temp, 4, q_00+208+100, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_01+208+100, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+100, 8, p_01+0+100, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+96, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_01+208+96, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+96, 8, p_01+0+96, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+92, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_01+208+92, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+92, 8, p_01+0+92, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+88, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_01+208+88, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+88, 8, p_01+0+88, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+84, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_01+208+84, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+84, 8, p_01+0+84, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+80, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_01+208+80, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+80, 8, p_01+0+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+76, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_01+208+76, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+76, 8, p_01+0+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+72, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_01+208+72, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+72, 8, p_01+0+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+68, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_01+208+68, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+68, 8, p_01+0+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+64, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_01+208+64, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+64, 8, p_01+0+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+60, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_01+208+60, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+60, 8, p_01+0+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+56, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_01+208+56, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+56, 8, p_01+0+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+52, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_01+208+52, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+52, 8, p_01+0+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+48, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_01+208+48, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+48, 8, p_01+0+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+44, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_01+208+44, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+44, 8, p_01+0+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+40, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_01+208+40, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+40, 8, p_01+0+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+36, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_01+208+36, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+36, 8, p_01+0+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+32, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_01+208+32, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+32, 8, p_01+0+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+28, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_01+208+28, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+28, 8, p_01+0+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+24, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_01+208+24, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+24, 8, p_01+0+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+20, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_01+208+20, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+20, 8, p_01+0+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+16, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_01+208+16, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+16, 8, p_01+0+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+12, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_01+208+12, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+12, 8, p_01+0+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+8, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_01+208+8, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+8, 8, p_01+0+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+4, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_01+208+4, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+4, 8, p_01+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+0, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_01+208+0, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+0, 8, p_01+0+0, 8, temp);
	memset(p_10+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(208, temp, 104, p_00+212+4, 104, q_10+208);
	GF2X_MUL(208, temp2, 104, p_10+212+4, 104, q_11+208);
	gf2x_add(208, p_10+0+4, 208, temp, 208, temp2);
	GF2X_MUL(8, temp, 4, q_10+208+100, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_11+208+100, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+100, 8, p_10+0+100, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+96, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_11+208+96, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+96, 8, p_10+0+96, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+92, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_11+208+92, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+92, 8, p_10+0+92, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+88, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_11+208+88, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+88, 8, p_10+0+88, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+84, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_11+208+84, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+84, 8, p_10+0+84, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+80, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_11+208+80, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+80, 8, p_10+0+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+76, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_11+208+76, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+76, 8, p_10+0+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+72, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_11+208+72, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+72, 8, p_10+0+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+68, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_11+208+68, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+68, 8, p_10+0+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+64, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_11+208+64, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+64, 8, p_10+0+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+60, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_11+208+60, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+60, 8, p_10+0+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+56, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_11+208+56, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+56, 8, p_10+0+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+52, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_11+208+52, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+52, 8, p_10+0+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+48, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_11+208+48, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+48, 8, p_10+0+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+44, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_11+208+44, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+44, 8, p_10+0+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+40, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_11+208+40, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+40, 8, p_10+0+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+36, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_11+208+36, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+36, 8, p_10+0+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+32, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_11+208+32, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+32, 8, p_10+0+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+28, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_11+208+28, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+28, 8, p_10+0+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+24, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_11+208+24, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+24, 8, p_10+0+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+20, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_11+208+20, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+20, 8, p_10+0+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+16, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_11+208+16, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+16, 8, p_10+0+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+12, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_11+208+12, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+12, 8, p_10+0+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+8, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_11+208+8, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+8, 8, p_10+0+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+4, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_11+208+4, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+4, 8, p_10+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+0, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_11+208+0, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+0, 8, p_10+0+0, 8, temp);
	memset(p_11+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(208, temp, 104, p_01+212+4, 104, q_10+208);
	GF2X_MUL(208, temp2, 104, p_11+212+4, 104, q_11+208);
	gf2x_add(208, p_11+0+4, 208, temp, 208, temp2);
	GF2X_MUL(8, temp, 4, q_10+208+100, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_11+208+100, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+100, 8, p_11+0+100, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+96, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_11+208+96, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+96, 8, p_11+0+96, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+92, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_11+208+92, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+92, 8, p_11+0+92, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+88, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_11+208+88, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+88, 8, p_11+0+88, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+84, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_11+208+84, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+84, 8, p_11+0+84, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+80, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_11+208+80, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+80, 8, p_11+0+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+76, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_11+208+76, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+76, 8, p_11+0+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+72, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_11+208+72, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+72, 8, p_11+0+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+68, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_11+208+68, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+68, 8, p_11+0+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+64, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_11+208+64, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+64, 8, p_11+0+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+60, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_11+208+60, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+60, 8, p_11+0+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+56, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_11+208+56, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+56, 8, p_11+0+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+52, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_11+208+52, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+52, 8, p_11+0+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+48, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_11+208+48, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+48, 8, p_11+0+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+44, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_11+208+44, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+44, 8, p_11+0+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+40, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_11+208+40, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+40, 8, p_11+0+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+36, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_11+208+36, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+36, 8, p_11+0+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+32, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_11+208+32, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+32, 8, p_11+0+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+28, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_11+208+28, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+28, 8, p_11+0+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+24, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_11+208+24, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+24, 8, p_11+0+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+20, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_11+208+20, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+20, 8, p_11+0+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+16, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_11+208+16, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+16, 8, p_11+0+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+12, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_11+208+12, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+12, 8, p_11+0+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+8, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_11+208+8, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+8, 8, p_11+0+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+4, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_11+208+4, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+4, 8, p_11+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+0, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_11+208+0, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+0, 8, p_11+0+0, 8, temp);
	

	// Calculating left operands: n: 26793, depth: 0
	// Digits to shift: 211
	// Displacement: 211
	GF2X_MUL(424, temp, 212, f+0+207, 212, p_00+0);
	GF2X_MUL(424, temp2, 212, g+0+207, 212, p_01+0);
	gf2x_add(420, f_sum+0, 420, temp+4, 420, temp2+4);
	GF2X_MUL(414, temp, 207, p_00+0+5, 207, f+0);
	GF2X_MUL(414, temp2, 207, p_01+0+5, 207, g+0);
	gf2x_add(414, temp, 414, temp, 414, temp2);
	gf2x_add(208, f_sum+0, 208, f_sum+0, 208, temp+206);
	GF2X_MUL(10, temp, 5, f+0+202, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, g+0+202, 5, p_01+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(1, f_sum+0, 1, f_sum+0, 1, temp+9);
	right_bit_shift_n(419, f_sum+0, 11);
	GF2X_MUL(424, temp, 212, f+0+207, 212, p_10+0);
	GF2X_MUL(424, temp2, 212, g+0+207, 212, p_11+0);
	gf2x_add(420, g_sum+0, 420, temp+4, 420, temp2+4);
	GF2X_MUL(414, temp, 207, p_10+0+5, 207, f+0);
	GF2X_MUL(414, temp2, 207, p_11+0+5, 207, g+0);
	gf2x_add(414, temp, 414, temp, 414, temp2);
	gf2x_add(208, g_sum+0, 208, g_sum+0, 208, temp+206);
	GF2X_MUL(10, temp, 5, f+0+202, 5, p_10+0);
	GF2X_MUL(10, temp2, 5, g+0+202, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(1, g_sum+0, 1, g_sum+0, 1, temp+9);
	right_bit_shift_n(419, g_sum+0, 11);
	

	delta = divstepsx_256(255, delta, f_sum+205, g_sum+205, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+201+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+201+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+201+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+201+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+201+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+201+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+201+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+201+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+193+8, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+193+8, 8, p_01+420);
	gf2x_add(16, f_sum+1248+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+193+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+193+0, 8, p_01+420);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1248, 8, f_sum+1248, 8, temp+8);
	right_bit_shift_n(16, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+193+8, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+193+8, 8, p_11+420);
	gf2x_add(16, g_sum+1248+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+193+0, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+193+0, 8, p_11+420);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1248, 8, g_sum+1248, 8, temp+8);
	right_bit_shift_n(16, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1253, g_sum+1253, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1249+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1249+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1249+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1249+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, q_00+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, q_01+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, q_10+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, q_11+404+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+404+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, q_01+404+0, 8, p_10+420);
	gf2x_add(16, p_00+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+404+0, 8, p_01+420);
	GF2X_MUL(16, temp2, 8, q_01+404+0, 8, p_11+420);
	gf2x_add(16, p_01+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+404+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, q_11+404+0, 8, p_10+420);
	gf2x_add(16, p_10+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+404+0, 8, p_01+420);
	GF2X_MUL(16, temp2, 8, q_11+404+0, 8, p_11+420);
	gf2x_add(16, p_11+404+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+181+12, 16, p_00+404);
	GF2X_MUL(32, temp2, 16, g_sum+181+12, 16, p_01+404);
	gf2x_add(28, f_sum+1203, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, f_sum+181);
	GF2X_MUL(24, temp2, 12, p_01+404+4, 12, g_sum+181);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1203, 12, f_sum+1203, 12, temp+12);
	right_bit_shift_n(28, f_sum+1203, 60);
	GF2X_MUL(32, temp, 16, f_sum+181+12, 16, p_10+404);
	GF2X_MUL(32, temp2, 16, g_sum+181+12, 16, p_11+404);
	gf2x_add(28, g_sum+1203, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+404+4, 12, f_sum+181);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, g_sum+181);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1203, 12, g_sum+1203, 12, temp+12);
	right_bit_shift_n(28, g_sum+1203, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1212, g_sum+1212, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_01+420);
	gf2x_add(12, f_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_01+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1248, 4, f_sum+1248, 4, temp+4);
	right_bit_shift_n(12, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_11+420);
	gf2x_add(12, g_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1248, 4, g_sum+1248, 4, temp+4);
	right_bit_shift_n(12, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1249, g_sum+1249, q_00+404, q_01+404, q_10+404, q_11+404);

	// Recombining results: n: 765, depth: 5
	memset(q_00+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_01+404);
	gf2x_add(8, q_00+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+392+0, 8, q_00+392+0, 8, temp);
	memset(q_01+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_01+404);
	gf2x_add(8, q_01+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+392+0, 8, q_01+392+0, 8, temp);
	memset(q_10+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_11+404);
	gf2x_add(8, q_10+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+392+0, 8, q_10+392+0, 8, temp);
	memset(q_11+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_11+404);
	gf2x_add(8, q_11+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+392+0, 8, q_11+392+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 4
	memset(p_00+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, q_00+392);
	GF2X_MUL(24, temp2, 12, p_10+404+4, 12, q_01+392);
	gf2x_add(24, p_00+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+392+8, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+8, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+376+8, 8, p_00+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+4, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+4, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+376+4, 8, p_00+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+0, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+0, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+376+0, 8, p_00+376+0, 8, temp);
	memset(p_01+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+404+4, 12, q_00+392);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, q_01+392);
	gf2x_add(24, p_01+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+392+8, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+8, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+376+8, 8, p_01+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+4, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+4, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+376+4, 8, p_01+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+0, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+0, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+376+0, 8, p_01+376+0, 8, temp);
	memset(p_10+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, q_10+392);
	GF2X_MUL(24, temp2, 12, p_10+404+4, 12, q_11+392);
	gf2x_add(24, p_10+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+392+8, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+8, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+376+8, 8, p_10+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+4, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+4, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+376+4, 8, p_10+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+0, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+0, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+376+0, 8, p_10+376+0, 8, temp);
	memset(p_11+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+404+4, 12, q_10+392);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, q_11+392);
	gf2x_add(24, p_11+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+392+8, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+8, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+376+8, 8, p_11+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+4, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+4, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+376+4, 8, p_11+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+0, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+0, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+376+0, 8, p_11+376+0, 8, temp);
	

	// Calculating left operands: n: 3570, depth: 3
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+153+28, 28, p_00+376);
	GF2X_MUL(56, temp2, 28, g_sum+153+28, 28, p_01+376);
	gf2x_add(56, f_sum+1118+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+153+0, 28, p_00+376);
	GF2X_MUL(56, temp2, 28, g_sum+153+0, 28, p_01+376);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+1118, 28, f_sum+1118, 28, temp+28);
	right_bit_shift_n(56, f_sum+1118, 57);
	GF2X_MUL(56, temp, 28, f_sum+153+28, 28, p_10+376);
	GF2X_MUL(56, temp2, 28, g_sum+153+28, 28, p_11+376);
	gf2x_add(56, g_sum+1118+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+153+0, 28, p_10+376);
	GF2X_MUL(56, temp2, 28, g_sum+153+0, 28, p_11+376);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+1118, 28, g_sum+1118, 28, temp+28);
	right_bit_shift_n(56, g_sum+1118, 57);
	

	delta = divstepsx_256(255, delta, f_sum+1143, g_sum+1143, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1139+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1139+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1139+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1139+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1139+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1139+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1139+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1139+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1131+8, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+1131+8, 8, p_01+420);
	gf2x_add(16, f_sum+1248+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1131+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+1131+0, 8, p_01+420);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1248, 8, f_sum+1248, 8, temp+8);
	right_bit_shift_n(16, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+1131+8, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+1131+8, 8, p_11+420);
	gf2x_add(16, g_sum+1248+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1131+0, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+1131+0, 8, p_11+420);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1248, 8, g_sum+1248, 8, temp+8);
	right_bit_shift_n(16, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1253, g_sum+1253, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1249+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1249+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1249+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1249+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, q_00+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, q_01+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, q_10+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, q_11+404+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+404+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, q_01+404+0, 8, p_10+420);
	gf2x_add(16, p_00+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+404+0, 8, p_01+420);
	GF2X_MUL(16, temp2, 8, q_01+404+0, 8, p_11+420);
	gf2x_add(16, p_01+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+404+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, q_11+404+0, 8, p_10+420);
	gf2x_add(16, p_10+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+404+0, 8, p_01+420);
	GF2X_MUL(16, temp2, 8, q_11+404+0, 8, p_11+420);
	gf2x_add(16, p_11+404+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1119+12, 16, p_00+404);
	GF2X_MUL(32, temp2, 16, g_sum+1119+12, 16, p_01+404);
	gf2x_add(28, f_sum+1203, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, f_sum+1119);
	GF2X_MUL(24, temp2, 12, p_01+404+4, 12, g_sum+1119);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1203, 12, f_sum+1203, 12, temp+12);
	right_bit_shift_n(28, f_sum+1203, 60);
	GF2X_MUL(32, temp, 16, f_sum+1119+12, 16, p_10+404);
	GF2X_MUL(32, temp2, 16, g_sum+1119+12, 16, p_11+404);
	gf2x_add(28, g_sum+1203, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+404+4, 12, f_sum+1119);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, g_sum+1119);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1203, 12, g_sum+1203, 12, temp+12);
	right_bit_shift_n(28, g_sum+1203, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1212, g_sum+1212, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_01+420);
	gf2x_add(12, f_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_01+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1248, 4, f_sum+1248, 4, temp+4);
	right_bit_shift_n(12, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_11+420);
	gf2x_add(12, g_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1248, 4, g_sum+1248, 4, temp+4);
	right_bit_shift_n(12, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1249, g_sum+1249, q_00+404, q_01+404, q_10+404, q_11+404);

	// Recombining results: n: 765, depth: 5
	memset(q_00+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_01+404);
	gf2x_add(8, q_00+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+392+0, 8, q_00+392+0, 8, temp);
	memset(q_01+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_01+404);
	gf2x_add(8, q_01+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+392+0, 8, q_01+392+0, 8, temp);
	memset(q_10+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_11+404);
	gf2x_add(8, q_10+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+392+0, 8, q_10+392+0, 8, temp);
	memset(q_11+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_11+404);
	gf2x_add(8, q_11+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+392+0, 8, q_11+392+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 4
	memset(q_00+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, q_00+392);
	GF2X_MUL(24, temp2, 12, p_10+404+4, 12, q_01+392);
	gf2x_add(24, q_00+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+392+8, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+8, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+364+8, 8, q_00+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+4, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+4, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+364+4, 8, q_00+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+0, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+0, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+364+0, 8, q_00+364+0, 8, temp);
	memset(q_01+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+404+4, 12, q_00+392);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, q_01+392);
	gf2x_add(24, q_01+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+392+8, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+8, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+364+8, 8, q_01+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+4, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+4, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+364+4, 8, q_01+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+0, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+0, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+364+0, 8, q_01+364+0, 8, temp);
	memset(q_10+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, q_10+392);
	GF2X_MUL(24, temp2, 12, p_10+404+4, 12, q_11+392);
	gf2x_add(24, q_10+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+392+8, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+8, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+364+8, 8, q_10+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+4, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+4, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+364+4, 8, q_10+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+0, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+0, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+364+0, 8, q_10+364+0, 8, temp);
	memset(q_11+364, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+404+4, 12, q_10+392);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, q_11+392);
	gf2x_add(24, q_11+364+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+392+8, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+8, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+364+8, 8, q_11+364+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+4, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+4, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+364+4, 8, q_11+364+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+0, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+0, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+364+0, 8, q_11+364+0, 8, temp);
	

	// Recombining results: n: 3570, depth: 3
	GF2X_MUL(56, temp, 28, q_00+364+0, 28, p_00+376);
	GF2X_MUL(56, temp2, 28, q_01+364+0, 28, p_10+376);
	gf2x_add(56, p_00+320+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_00+364+0, 28, p_01+376);
	GF2X_MUL(56, temp2, 28, q_01+364+0, 28, p_11+376);
	gf2x_add(56, p_01+320+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+364+0, 28, p_00+376);
	GF2X_MUL(56, temp2, 28, q_11+364+0, 28, p_10+376);
	gf2x_add(56, p_10+320+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+364+0, 28, p_01+376);
	GF2X_MUL(56, temp2, 28, q_11+364+0, 28, p_11+376);
	gf2x_add(56, p_11+320+0, 56, temp, 56, temp2);
	

	// Calculating left operands: n: 6885, depth: 2
	// Digits to shift: 55
	// Displacement: 56
	GF2X_MUL(112, temp, 56, f_sum+101+52, 56, p_00+320);
	GF2X_MUL(112, temp2, 56, g_sum+101+52, 56, p_01+320);
	gf2x_add(108, f_sum+953, 108, temp+4, 108, temp2+4);
	GF2X_MUL(104, temp, 52, p_00+320+4, 52, f_sum+101);
	GF2X_MUL(104, temp2, 52, p_01+320+4, 52, g_sum+101);
	gf2x_add(104, temp, 104, temp, 104, temp2);
	gf2x_add(52, f_sum+953, 52, f_sum+953, 52, temp+52);
	right_bit_shift_n(108, f_sum+953, 50);
	GF2X_MUL(112, temp, 56, f_sum+101+52, 56, p_10+320);
	GF2X_MUL(112, temp2, 56, g_sum+101+52, 56, p_11+320);
	gf2x_add(108, g_sum+953, 108, temp+4, 108, temp2+4);
	GF2X_MUL(104, temp, 52, p_10+320+4, 52, f_sum+101);
	GF2X_MUL(104, temp2, 52, p_11+320+4, 52, g_sum+101);
	gf2x_add(104, temp, 104, temp, 104, temp2);
	gf2x_add(52, g_sum+953, 52, g_sum+953, 52, temp+52);
	right_bit_shift_n(108, g_sum+953, 50);
	

	delta = divstepsx_256(255, delta, f_sum+1002, g_sum+1002, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+998+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+998+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+998+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+998+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+998+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+998+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+998+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+998+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+990+8, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+990+8, 8, p_01+420);
	gf2x_add(16, f_sum+1248+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+990+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+990+0, 8, p_01+420);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1248, 8, f_sum+1248, 8, temp+8);
	right_bit_shift_n(16, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+990+8, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+990+8, 8, p_11+420);
	gf2x_add(16, g_sum+1248+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+990+0, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+990+0, 8, p_11+420);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1248, 8, g_sum+1248, 8, temp+8);
	right_bit_shift_n(16, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1253, g_sum+1253, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1249+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1249+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1249+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1249+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, q_00+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, q_01+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, q_10+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, q_11+404+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+404+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, q_01+404+0, 8, p_10+420);
	gf2x_add(16, p_00+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+404+0, 8, p_01+420);
	GF2X_MUL(16, temp2, 8, q_01+404+0, 8, p_11+420);
	gf2x_add(16, p_01+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+404+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, q_11+404+0, 8, p_10+420);
	gf2x_add(16, p_10+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+404+0, 8, p_01+420);
	GF2X_MUL(16, temp2, 8, q_11+404+0, 8, p_11+420);
	gf2x_add(16, p_11+404+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+978+12, 16, p_00+404);
	GF2X_MUL(32, temp2, 16, g_sum+978+12, 16, p_01+404);
	gf2x_add(28, f_sum+1203, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, f_sum+978);
	GF2X_MUL(24, temp2, 12, p_01+404+4, 12, g_sum+978);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1203, 12, f_sum+1203, 12, temp+12);
	right_bit_shift_n(28, f_sum+1203, 60);
	GF2X_MUL(32, temp, 16, f_sum+978+12, 16, p_10+404);
	GF2X_MUL(32, temp2, 16, g_sum+978+12, 16, p_11+404);
	gf2x_add(28, g_sum+1203, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+404+4, 12, f_sum+978);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, g_sum+978);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1203, 12, g_sum+1203, 12, temp+12);
	right_bit_shift_n(28, g_sum+1203, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1212, g_sum+1212, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_01+420);
	gf2x_add(12, f_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_01+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1248, 4, f_sum+1248, 4, temp+4);
	right_bit_shift_n(12, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_11+420);
	gf2x_add(12, g_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1248, 4, g_sum+1248, 4, temp+4);
	right_bit_shift_n(12, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1249, g_sum+1249, q_00+404, q_01+404, q_10+404, q_11+404);

	// Recombining results: n: 765, depth: 5
	memset(q_00+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_01+404);
	gf2x_add(8, q_00+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+392+0, 8, q_00+392+0, 8, temp);
	memset(q_01+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_01+404);
	gf2x_add(8, q_01+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+392+0, 8, q_01+392+0, 8, temp);
	memset(q_10+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_11+404);
	gf2x_add(8, q_10+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+392+0, 8, q_10+392+0, 8, temp);
	memset(q_11+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_11+404);
	gf2x_add(8, q_11+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+392+0, 8, q_11+392+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 4
	memset(p_00+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, q_00+392);
	GF2X_MUL(24, temp2, 12, p_10+404+4, 12, q_01+392);
	gf2x_add(24, p_00+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+392+8, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+8, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+376+8, 8, p_00+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+4, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+4, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+376+4, 8, p_00+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+0, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+0, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+376+0, 8, p_00+376+0, 8, temp);
	memset(p_01+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+404+4, 12, q_00+392);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, q_01+392);
	gf2x_add(24, p_01+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+392+8, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+8, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+376+8, 8, p_01+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+4, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+4, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+376+4, 8, p_01+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+0, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+0, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+376+0, 8, p_01+376+0, 8, temp);
	memset(p_10+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, q_10+392);
	GF2X_MUL(24, temp2, 12, p_10+404+4, 12, q_11+392);
	gf2x_add(24, p_10+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+392+8, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+8, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+376+8, 8, p_10+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+4, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+4, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+376+4, 8, p_10+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+0, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+0, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+376+0, 8, p_10+376+0, 8, temp);
	memset(p_11+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+404+4, 12, q_10+392);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, q_11+392);
	gf2x_add(24, p_11+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+392+8, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+8, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+376+8, 8, p_11+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+4, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+4, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+376+4, 8, p_11+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+0, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+0, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+376+0, 8, p_11+376+0, 8, temp);
	

	// Calculating left operands: n: 3315, depth: 3
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+954+24, 28, p_00+376);
	GF2X_MUL(56, temp2, 28, g_sum+954+24, 28, p_01+376);
	gf2x_add(52, f_sum+1118, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_00+376+4, 24, f_sum+954);
	GF2X_MUL(48, temp2, 24, p_01+376+4, 24, g_sum+954);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+1118, 24, f_sum+1118, 24, temp+24);
	right_bit_shift_n(52, f_sum+1118, 57);
	GF2X_MUL(56, temp, 28, f_sum+954+24, 28, p_10+376);
	GF2X_MUL(56, temp2, 28, g_sum+954+24, 28, p_11+376);
	gf2x_add(52, g_sum+1118, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_10+376+4, 24, f_sum+954);
	GF2X_MUL(48, temp2, 24, p_11+376+4, 24, g_sum+954);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+1118, 24, g_sum+1118, 24, temp+24);
	right_bit_shift_n(52, g_sum+1118, 57);
	

	delta = divstepsx_256(255, delta, f_sum+1139, g_sum+1139, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1135+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1135+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1135+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1135+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1135+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1135+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1135+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1135+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1131+4, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+1131+4, 8, p_01+420);
	gf2x_add(12, f_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, f_sum+1131);
	GF2X_MUL(8, temp2, 4, p_01+420+4, 4, g_sum+1131);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1248, 4, f_sum+1248, 4, temp+4);
	right_bit_shift_n(12, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+1131+4, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+1131+4, 8, p_11+420);
	gf2x_add(12, g_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+420+4, 4, f_sum+1131);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, g_sum+1131);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1248, 4, g_sum+1248, 4, temp+4);
	right_bit_shift_n(12, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1249, g_sum+1249, q_00+404, q_01+404, q_10+404, q_11+404);

	// Recombining results: n: 765, depth: 5
	memset(p_00+404, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_01+404);
	gf2x_add(8, p_00+404+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+404+0, 8, p_00+404+0, 8, temp);
	memset(p_01+404, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_01+404);
	gf2x_add(8, p_01+404+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+404+0, 8, p_01+404+0, 8, temp);
	memset(p_10+404, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_11+404);
	gf2x_add(8, p_10+404+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+404+0, 8, p_10+404+0, 8, temp);
	memset(p_11+404, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_11+404);
	gf2x_add(8, p_11+404+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+404+0, 8, p_11+404+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1119+12, 12, p_00+404);
	GF2X_MUL(24, temp2, 12, g_sum+1119+12, 12, p_01+404);
	gf2x_add(24, f_sum+1203+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1119+0, 12, p_00+404);
	GF2X_MUL(24, temp2, 12, g_sum+1119+0, 12, p_01+404);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1203, 12, f_sum+1203, 12, temp+12);
	right_bit_shift_n(24, f_sum+1203, 61);
	GF2X_MUL(24, temp, 12, f_sum+1119+12, 12, p_10+404);
	GF2X_MUL(24, temp2, 12, g_sum+1119+12, 12, p_11+404);
	gf2x_add(24, g_sum+1203+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1119+0, 12, p_10+404);
	GF2X_MUL(24, temp2, 12, g_sum+1119+0, 12, p_11+404);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1203, 12, g_sum+1203, 12, temp+12);
	right_bit_shift_n(24, g_sum+1203, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1212, g_sum+1212, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_01+420);
	gf2x_add(12, f_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_01+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1248, 4, f_sum+1248, 4, temp+4);
	right_bit_shift_n(12, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_11+420);
	gf2x_add(12, g_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1248, 4, g_sum+1248, 4, temp+4);
	right_bit_shift_n(12, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1249, g_sum+1249, q_00+404, q_01+404, q_10+404, q_11+404);

	// Recombining results: n: 765, depth: 5
	memset(q_00+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_01+404);
	gf2x_add(8, q_00+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+392+0, 8, q_00+392+0, 8, temp);
	memset(q_01+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_01+404);
	gf2x_add(8, q_01+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+392+0, 8, q_01+392+0, 8, temp);
	memset(q_10+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_11+404);
	gf2x_add(8, q_10+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+392+0, 8, q_10+392+0, 8, temp);
	memset(q_11+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_11+404);
	gf2x_add(8, q_11+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+392+0, 8, q_11+392+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 4
	GF2X_MUL(24, temp, 12, q_00+392+0, 12, p_00+404);
	GF2X_MUL(24, temp2, 12, q_01+392+0, 12, p_10+404);
	gf2x_add(24, q_00+364+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+392+0, 12, p_01+404);
	GF2X_MUL(24, temp2, 12, q_01+392+0, 12, p_11+404);
	gf2x_add(24, q_01+364+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+392+0, 12, p_00+404);
	GF2X_MUL(24, temp2, 12, q_11+392+0, 12, p_10+404);
	gf2x_add(24, q_10+364+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+392+0, 12, p_01+404);
	GF2X_MUL(24, temp2, 12, q_11+392+0, 12, p_11+404);
	gf2x_add(24, q_11+364+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3315, depth: 3
	memset(q_00+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+376+4, 24, q_00+364);
	GF2X_MUL(48, temp2, 24, p_10+376+4, 24, q_01+364);
	gf2x_add(48, q_00+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+364+20, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+20, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+312+20, 8, q_00+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+16, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+16, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+312+16, 8, q_00+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+12, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+12, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+312+12, 8, q_00+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+8, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+8, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+312+8, 8, q_00+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+4, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+4, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+312+4, 8, q_00+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+0, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+0, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+312+0, 8, q_00+312+0, 8, temp);
	memset(q_01+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+376+4, 24, q_00+364);
	GF2X_MUL(48, temp2, 24, p_11+376+4, 24, q_01+364);
	gf2x_add(48, q_01+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+364+20, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+20, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+312+20, 8, q_01+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+16, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+16, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+312+16, 8, q_01+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+12, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+12, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+312+12, 8, q_01+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+8, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+8, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+312+8, 8, q_01+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+4, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+4, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+312+4, 8, q_01+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+0, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+0, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+312+0, 8, q_01+312+0, 8, temp);
	memset(q_10+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+376+4, 24, q_10+364);
	GF2X_MUL(48, temp2, 24, p_10+376+4, 24, q_11+364);
	gf2x_add(48, q_10+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+364+20, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+20, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+312+20, 8, q_10+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+16, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+16, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+312+16, 8, q_10+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+12, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+12, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+312+12, 8, q_10+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+8, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+8, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+312+8, 8, q_10+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+4, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+4, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+312+4, 8, q_10+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+0, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+0, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+312+0, 8, q_10+312+0, 8, temp);
	memset(q_11+312, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+376+4, 24, q_10+364);
	GF2X_MUL(48, temp2, 24, p_11+376+4, 24, q_11+364);
	gf2x_add(48, q_11+312+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+364+20, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+20, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+312+20, 8, q_11+312+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+16, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+16, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+312+16, 8, q_11+312+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+12, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+12, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+312+12, 8, q_11+312+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+8, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+8, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+312+8, 8, q_11+312+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+4, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+4, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+312+4, 8, q_11+312+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+0, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+0, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+312+0, 8, q_11+312+0, 8, temp);
	

	// Recombining results: n: 6885, depth: 2
	memset(p_00+212, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(104, temp, 52, p_00+320+4, 52, q_00+312);
	GF2X_MUL(104, temp2, 52, p_10+320+4, 52, q_01+312);
	gf2x_add(104, p_00+212+4, 104, temp, 104, temp2);
	GF2X_MUL(8, temp, 4, q_00+312+48, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_01+312+48, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+212+48, 8, p_00+212+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+44, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_01+312+44, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+212+44, 8, p_00+212+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+40, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_01+312+40, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+212+40, 8, p_00+212+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+36, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_01+312+36, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+212+36, 8, p_00+212+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+32, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_01+312+32, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+212+32, 8, p_00+212+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+28, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_01+312+28, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+212+28, 8, p_00+212+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+24, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_01+312+24, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+212+24, 8, p_00+212+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+20, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_01+312+20, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+212+20, 8, p_00+212+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+16, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_01+312+16, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+212+16, 8, p_00+212+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+12, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_01+312+12, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+212+12, 8, p_00+212+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+8, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_01+312+8, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+212+8, 8, p_00+212+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+4, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_01+312+4, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+212+4, 8, p_00+212+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+0, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_01+312+0, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+212+0, 8, p_00+212+0, 8, temp);
	memset(p_01+212, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(104, temp, 52, p_01+320+4, 52, q_00+312);
	GF2X_MUL(104, temp2, 52, p_11+320+4, 52, q_01+312);
	gf2x_add(104, p_01+212+4, 104, temp, 104, temp2);
	GF2X_MUL(8, temp, 4, q_00+312+48, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_01+312+48, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+212+48, 8, p_01+212+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+44, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_01+312+44, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+212+44, 8, p_01+212+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+40, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_01+312+40, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+212+40, 8, p_01+212+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+36, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_01+312+36, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+212+36, 8, p_01+212+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+32, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_01+312+32, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+212+32, 8, p_01+212+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+28, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_01+312+28, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+212+28, 8, p_01+212+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+24, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_01+312+24, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+212+24, 8, p_01+212+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+20, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_01+312+20, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+212+20, 8, p_01+212+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+16, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_01+312+16, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+212+16, 8, p_01+212+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+12, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_01+312+12, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+212+12, 8, p_01+212+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+8, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_01+312+8, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+212+8, 8, p_01+212+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+4, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_01+312+4, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+212+4, 8, p_01+212+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+312+0, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_01+312+0, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+212+0, 8, p_01+212+0, 8, temp);
	memset(p_10+212, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(104, temp, 52, p_00+320+4, 52, q_10+312);
	GF2X_MUL(104, temp2, 52, p_10+320+4, 52, q_11+312);
	gf2x_add(104, p_10+212+4, 104, temp, 104, temp2);
	GF2X_MUL(8, temp, 4, q_10+312+48, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_11+312+48, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+212+48, 8, p_10+212+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+44, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_11+312+44, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+212+44, 8, p_10+212+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+40, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_11+312+40, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+212+40, 8, p_10+212+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+36, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_11+312+36, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+212+36, 8, p_10+212+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+32, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_11+312+32, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+212+32, 8, p_10+212+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+28, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_11+312+28, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+212+28, 8, p_10+212+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+24, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_11+312+24, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+212+24, 8, p_10+212+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+20, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_11+312+20, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+212+20, 8, p_10+212+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+16, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_11+312+16, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+212+16, 8, p_10+212+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+12, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_11+312+12, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+212+12, 8, p_10+212+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+8, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_11+312+8, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+212+8, 8, p_10+212+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+4, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_11+312+4, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+212+4, 8, p_10+212+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+0, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, q_11+312+0, 4, p_10+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+212+0, 8, p_10+212+0, 8, temp);
	memset(p_11+212, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(104, temp, 52, p_01+320+4, 52, q_10+312);
	GF2X_MUL(104, temp2, 52, p_11+320+4, 52, q_11+312);
	gf2x_add(104, p_11+212+4, 104, temp, 104, temp2);
	GF2X_MUL(8, temp, 4, q_10+312+48, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_11+312+48, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+212+48, 8, p_11+212+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+44, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_11+312+44, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+212+44, 8, p_11+212+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+40, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_11+312+40, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+212+40, 8, p_11+212+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+36, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_11+312+36, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+212+36, 8, p_11+212+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+32, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_11+312+32, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+212+32, 8, p_11+212+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+28, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_11+312+28, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+212+28, 8, p_11+212+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+24, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_11+312+24, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+212+24, 8, p_11+212+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+20, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_11+312+20, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+212+20, 8, p_11+212+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+16, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_11+312+16, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+212+16, 8, p_11+212+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+12, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_11+312+12, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+212+12, 8, p_11+212+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+8, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_11+312+8, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+212+8, 8, p_11+212+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+4, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_11+312+4, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+212+4, 8, p_11+212+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+312+0, 4, p_01+320);
	GF2X_MUL(8, temp2, 4, q_11+312+0, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+212+0, 8, p_11+212+0, 8, temp);
	

	// Calculating left operands: n: 13278, depth: 1
	// Digits to shift: 107
	// Displacement: 108
	GF2X_MUL(216, temp, 108, f_sum+1+100, 108, p_00+212);
	GF2X_MUL(216, temp2, 108, g_sum+1+100, 108, p_01+212);
	gf2x_add(208, f_sum+632, 208, temp+8, 208, temp2+8);
	GF2X_MUL(200, temp, 100, p_00+212+8, 100, f_sum+1);
	GF2X_MUL(200, temp2, 100, p_01+212+8, 100, g_sum+1);
	gf2x_add(200, temp, 200, temp, 200, temp2);
	gf2x_add(100, f_sum+632, 100, f_sum+632, 100, temp+100);
	right_bit_shift_n(208, f_sum+632, 37);
	GF2X_MUL(216, temp, 108, f_sum+1+100, 108, p_10+212);
	GF2X_MUL(216, temp2, 108, g_sum+1+100, 108, p_11+212);
	gf2x_add(208, g_sum+632, 208, temp+8, 208, temp2+8);
	GF2X_MUL(200, temp, 100, p_10+212+8, 100, f_sum+1);
	GF2X_MUL(200, temp2, 100, p_11+212+8, 100, g_sum+1);
	gf2x_add(200, temp, 200, temp, 200, temp2);
	gf2x_add(100, g_sum+632, 100, g_sum+632, 100, temp+100);
	right_bit_shift_n(208, g_sum+632, 37);
	

	delta = divstepsx_256(255, delta, f_sum+729, g_sum+729, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+725+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+725+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+725+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+725+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+725+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+725+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+725+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+725+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+717+8, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+717+8, 8, p_01+420);
	gf2x_add(16, f_sum+1248+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+717+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+717+0, 8, p_01+420);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1248, 8, f_sum+1248, 8, temp+8);
	right_bit_shift_n(16, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+717+8, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+717+8, 8, p_11+420);
	gf2x_add(16, g_sum+1248+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+717+0, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+717+0, 8, p_11+420);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1248, 8, g_sum+1248, 8, temp+8);
	right_bit_shift_n(16, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1253, g_sum+1253, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1249+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1249+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1249+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1249+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, q_00+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, q_01+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, q_10+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, q_11+404+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+404+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, q_01+404+0, 8, p_10+420);
	gf2x_add(16, p_00+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+404+0, 8, p_01+420);
	GF2X_MUL(16, temp2, 8, q_01+404+0, 8, p_11+420);
	gf2x_add(16, p_01+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+404+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, q_11+404+0, 8, p_10+420);
	gf2x_add(16, p_10+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+404+0, 8, p_01+420);
	GF2X_MUL(16, temp2, 8, q_11+404+0, 8, p_11+420);
	gf2x_add(16, p_11+404+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+705+12, 16, p_00+404);
	GF2X_MUL(32, temp2, 16, g_sum+705+12, 16, p_01+404);
	gf2x_add(28, f_sum+1203, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, f_sum+705);
	GF2X_MUL(24, temp2, 12, p_01+404+4, 12, g_sum+705);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1203, 12, f_sum+1203, 12, temp+12);
	right_bit_shift_n(28, f_sum+1203, 60);
	GF2X_MUL(32, temp, 16, f_sum+705+12, 16, p_10+404);
	GF2X_MUL(32, temp2, 16, g_sum+705+12, 16, p_11+404);
	gf2x_add(28, g_sum+1203, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+404+4, 12, f_sum+705);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, g_sum+705);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1203, 12, g_sum+1203, 12, temp+12);
	right_bit_shift_n(28, g_sum+1203, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1212, g_sum+1212, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_01+420);
	gf2x_add(12, f_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_01+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1248, 4, f_sum+1248, 4, temp+4);
	right_bit_shift_n(12, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_11+420);
	gf2x_add(12, g_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1248, 4, g_sum+1248, 4, temp+4);
	right_bit_shift_n(12, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1249, g_sum+1249, q_00+404, q_01+404, q_10+404, q_11+404);

	// Recombining results: n: 765, depth: 5
	memset(q_00+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_01+404);
	gf2x_add(8, q_00+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+392+0, 8, q_00+392+0, 8, temp);
	memset(q_01+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_01+404);
	gf2x_add(8, q_01+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+392+0, 8, q_01+392+0, 8, temp);
	memset(q_10+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_11+404);
	gf2x_add(8, q_10+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+392+0, 8, q_10+392+0, 8, temp);
	memset(q_11+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_11+404);
	gf2x_add(8, q_11+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+392+0, 8, q_11+392+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 4
	memset(p_00+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, q_00+392);
	GF2X_MUL(24, temp2, 12, p_10+404+4, 12, q_01+392);
	gf2x_add(24, p_00+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+392+8, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+8, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+376+8, 8, p_00+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+4, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+4, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+376+4, 8, p_00+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+0, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+0, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+376+0, 8, p_00+376+0, 8, temp);
	memset(p_01+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+404+4, 12, q_00+392);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, q_01+392);
	gf2x_add(24, p_01+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+392+8, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+8, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+376+8, 8, p_01+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+4, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+4, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+376+4, 8, p_01+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+0, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+0, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+376+0, 8, p_01+376+0, 8, temp);
	memset(p_10+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, q_10+392);
	GF2X_MUL(24, temp2, 12, p_10+404+4, 12, q_11+392);
	gf2x_add(24, p_10+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+392+8, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+8, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+376+8, 8, p_10+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+4, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+4, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+376+4, 8, p_10+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+0, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+0, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+376+0, 8, p_10+376+0, 8, temp);
	memset(p_11+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+404+4, 12, q_10+392);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, q_11+392);
	gf2x_add(24, p_11+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+392+8, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+8, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+376+8, 8, p_11+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+4, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+4, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+376+4, 8, p_11+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+0, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+0, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+376+0, 8, p_11+376+0, 8, temp);
	

	// Calculating left operands: n: 3315, depth: 3
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+681+24, 28, p_00+376);
	GF2X_MUL(56, temp2, 28, g_sum+681+24, 28, p_01+376);
	gf2x_add(52, f_sum+1118, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_00+376+4, 24, f_sum+681);
	GF2X_MUL(48, temp2, 24, p_01+376+4, 24, g_sum+681);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+1118, 24, f_sum+1118, 24, temp+24);
	right_bit_shift_n(52, f_sum+1118, 57);
	GF2X_MUL(56, temp, 28, f_sum+681+24, 28, p_10+376);
	GF2X_MUL(56, temp2, 28, g_sum+681+24, 28, p_11+376);
	gf2x_add(52, g_sum+1118, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_10+376+4, 24, f_sum+681);
	GF2X_MUL(48, temp2, 24, p_11+376+4, 24, g_sum+681);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+1118, 24, g_sum+1118, 24, temp+24);
	right_bit_shift_n(52, g_sum+1118, 57);
	

	delta = divstepsx_256(255, delta, f_sum+1139, g_sum+1139, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1135+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1135+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1135+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1135+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1135+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1135+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1135+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1135+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1131+4, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+1131+4, 8, p_01+420);
	gf2x_add(12, f_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, f_sum+1131);
	GF2X_MUL(8, temp2, 4, p_01+420+4, 4, g_sum+1131);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1248, 4, f_sum+1248, 4, temp+4);
	right_bit_shift_n(12, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+1131+4, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+1131+4, 8, p_11+420);
	gf2x_add(12, g_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+420+4, 4, f_sum+1131);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, g_sum+1131);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1248, 4, g_sum+1248, 4, temp+4);
	right_bit_shift_n(12, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1249, g_sum+1249, q_00+404, q_01+404, q_10+404, q_11+404);

	// Recombining results: n: 765, depth: 5
	memset(p_00+404, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_01+404);
	gf2x_add(8, p_00+404+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+404+0, 8, p_00+404+0, 8, temp);
	memset(p_01+404, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_01+404);
	gf2x_add(8, p_01+404+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+404+0, 8, p_01+404+0, 8, temp);
	memset(p_10+404, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_11+404);
	gf2x_add(8, p_10+404+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+404+0, 8, p_10+404+0, 8, temp);
	memset(p_11+404, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_11+404);
	gf2x_add(8, p_11+404+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+404+0, 8, p_11+404+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1119+12, 12, p_00+404);
	GF2X_MUL(24, temp2, 12, g_sum+1119+12, 12, p_01+404);
	gf2x_add(24, f_sum+1203+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1119+0, 12, p_00+404);
	GF2X_MUL(24, temp2, 12, g_sum+1119+0, 12, p_01+404);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1203, 12, f_sum+1203, 12, temp+12);
	right_bit_shift_n(24, f_sum+1203, 61);
	GF2X_MUL(24, temp, 12, f_sum+1119+12, 12, p_10+404);
	GF2X_MUL(24, temp2, 12, g_sum+1119+12, 12, p_11+404);
	gf2x_add(24, g_sum+1203+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1119+0, 12, p_10+404);
	GF2X_MUL(24, temp2, 12, g_sum+1119+0, 12, p_11+404);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1203, 12, g_sum+1203, 12, temp+12);
	right_bit_shift_n(24, g_sum+1203, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1212, g_sum+1212, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_01+420);
	gf2x_add(12, f_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_01+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1248, 4, f_sum+1248, 4, temp+4);
	right_bit_shift_n(12, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_11+420);
	gf2x_add(12, g_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1248, 4, g_sum+1248, 4, temp+4);
	right_bit_shift_n(12, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1249, g_sum+1249, q_00+404, q_01+404, q_10+404, q_11+404);

	// Recombining results: n: 765, depth: 5
	memset(q_00+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_01+404);
	gf2x_add(8, q_00+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+392+0, 8, q_00+392+0, 8, temp);
	memset(q_01+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_01+404);
	gf2x_add(8, q_01+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+392+0, 8, q_01+392+0, 8, temp);
	memset(q_10+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_11+404);
	gf2x_add(8, q_10+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+392+0, 8, q_10+392+0, 8, temp);
	memset(q_11+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_11+404);
	gf2x_add(8, q_11+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+392+0, 8, q_11+392+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 4
	GF2X_MUL(24, temp, 12, q_00+392+0, 12, p_00+404);
	GF2X_MUL(24, temp2, 12, q_01+392+0, 12, p_10+404);
	gf2x_add(24, q_00+364+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+392+0, 12, p_01+404);
	GF2X_MUL(24, temp2, 12, q_01+392+0, 12, p_11+404);
	gf2x_add(24, q_01+364+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+392+0, 12, p_00+404);
	GF2X_MUL(24, temp2, 12, q_11+392+0, 12, p_10+404);
	gf2x_add(24, q_10+364+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+392+0, 12, p_01+404);
	GF2X_MUL(24, temp2, 12, q_11+392+0, 12, p_11+404);
	gf2x_add(24, q_11+364+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3315, depth: 3
	memset(p_00+320, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+376+4, 24, q_00+364);
	GF2X_MUL(48, temp2, 24, p_10+376+4, 24, q_01+364);
	gf2x_add(48, p_00+320+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+364+20, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+20, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+320+20, 8, p_00+320+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+16, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+16, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+320+16, 8, p_00+320+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+12, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+12, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+320+12, 8, p_00+320+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+8, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+8, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+320+8, 8, p_00+320+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+4, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+4, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+320+4, 8, p_00+320+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+0, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_01+364+0, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+320+0, 8, p_00+320+0, 8, temp);
	memset(p_01+320, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+376+4, 24, q_00+364);
	GF2X_MUL(48, temp2, 24, p_11+376+4, 24, q_01+364);
	gf2x_add(48, p_01+320+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+364+20, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+20, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+320+20, 8, p_01+320+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+16, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+16, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+320+16, 8, p_01+320+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+12, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+12, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+320+12, 8, p_01+320+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+8, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+8, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+320+8, 8, p_01+320+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+4, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+4, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+320+4, 8, p_01+320+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+364+0, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_01+364+0, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+320+0, 8, p_01+320+0, 8, temp);
	memset(p_10+320, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+376+4, 24, q_10+364);
	GF2X_MUL(48, temp2, 24, p_10+376+4, 24, q_11+364);
	gf2x_add(48, p_10+320+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+364+20, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+20, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+320+20, 8, p_10+320+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+16, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+16, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+320+16, 8, p_10+320+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+12, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+12, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+320+12, 8, p_10+320+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+8, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+8, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+320+8, 8, p_10+320+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+4, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+4, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+320+4, 8, p_10+320+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+0, 4, p_00+376);
	GF2X_MUL(8, temp2, 4, q_11+364+0, 4, p_10+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+320+0, 8, p_10+320+0, 8, temp);
	memset(p_11+320, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+376+4, 24, q_10+364);
	GF2X_MUL(48, temp2, 24, p_11+376+4, 24, q_11+364);
	gf2x_add(48, p_11+320+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+364+20, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+20, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+320+20, 8, p_11+320+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+16, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+16, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+320+16, 8, p_11+320+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+12, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+12, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+320+12, 8, p_11+320+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+8, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+8, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+320+8, 8, p_11+320+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+4, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+4, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+320+4, 8, p_11+320+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+364+0, 4, p_01+376);
	GF2X_MUL(8, temp2, 4, q_11+364+0, 4, p_11+376);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+320+0, 8, p_11+320+0, 8, temp);
	

	// Calculating left operands: n: 6393, depth: 2
	// Digits to shift: 51
	// Displacement: 51
	GF2X_MUL(104, temp, 52, f_sum+633+48, 52, p_00+320);
	GF2X_MUL(104, temp2, 52, g_sum+633+48, 52, p_01+320);
	gf2x_add(101, f_sum+953, 101, temp+3, 101, temp2+3);
	GF2X_MUL(96, temp, 48, p_00+320+4, 48, f_sum+633);
	GF2X_MUL(96, temp2, 48, p_01+320+4, 48, g_sum+633);
	gf2x_add(96, temp, 96, temp, 96, temp2);
	gf2x_add(49, f_sum+953, 49, f_sum+953, 49, temp+47);
	GF2X_MUL(8, temp, 4, f_sum+633+44, 4, p_00+320);
	GF2X_MUL(8, temp2, 4, g_sum+633+44, 4, p_01+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(1, f_sum+953, 1, f_sum+953, 1, temp+7);
	right_bit_shift_n(100, f_sum+953, 51);
	GF2X_MUL(104, temp, 52, f_sum+633+48, 52, p_10+320);
	GF2X_MUL(104, temp2, 52, g_sum+633+48, 52, p_11+320);
	gf2x_add(101, g_sum+953, 101, temp+3, 101, temp2+3);
	GF2X_MUL(96, temp, 48, p_10+320+4, 48, f_sum+633);
	GF2X_MUL(96, temp2, 48, p_11+320+4, 48, g_sum+633);
	gf2x_add(96, temp, 96, temp, 96, temp2);
	gf2x_add(49, g_sum+953, 49, g_sum+953, 49, temp+47);
	GF2X_MUL(8, temp, 4, f_sum+633+44, 4, p_10+320);
	GF2X_MUL(8, temp2, 4, g_sum+633+44, 4, p_11+320);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(1, g_sum+953, 1, g_sum+953, 1, temp+7);
	right_bit_shift_n(100, g_sum+953, 51);
	

	delta = divstepsx_256(255, delta, f_sum+999, g_sum+999, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+995+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+995+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+995+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+995+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+995+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+995+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+995+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+995+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+987+8, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+987+8, 8, p_01+420);
	gf2x_add(16, f_sum+1248+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+987+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+987+0, 8, p_01+420);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1248, 8, f_sum+1248, 8, temp+8);
	right_bit_shift_n(16, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+987+8, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+987+8, 8, p_11+420);
	gf2x_add(16, g_sum+1248+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+987+0, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+987+0, 8, p_11+420);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1248, 8, g_sum+1248, 8, temp+8);
	right_bit_shift_n(16, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1253, g_sum+1253, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1249+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1249+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1249+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1249+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1249+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, q_00+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, q_01+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, q_10+404+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, q_11+404+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+404+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, q_01+404+0, 8, p_10+420);
	gf2x_add(16, p_00+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+404+0, 8, p_01+420);
	GF2X_MUL(16, temp2, 8, q_01+404+0, 8, p_11+420);
	gf2x_add(16, p_01+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+404+0, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, q_11+404+0, 8, p_10+420);
	gf2x_add(16, p_10+404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+404+0, 8, p_01+420);
	GF2X_MUL(16, temp2, 8, q_11+404+0, 8, p_11+420);
	gf2x_add(16, p_11+404+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+975+12, 16, p_00+404);
	GF2X_MUL(32, temp2, 16, g_sum+975+12, 16, p_01+404);
	gf2x_add(28, f_sum+1203, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, f_sum+975);
	GF2X_MUL(24, temp2, 12, p_01+404+4, 12, g_sum+975);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1203, 12, f_sum+1203, 12, temp+12);
	right_bit_shift_n(28, f_sum+1203, 60);
	GF2X_MUL(32, temp, 16, f_sum+975+12, 16, p_10+404);
	GF2X_MUL(32, temp2, 16, g_sum+975+12, 16, p_11+404);
	gf2x_add(28, g_sum+1203, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+404+4, 12, f_sum+975);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, g_sum+975);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1203, 12, g_sum+1203, 12, temp+12);
	right_bit_shift_n(28, g_sum+1203, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1212, g_sum+1212, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1208+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1208+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1208+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_01+420);
	gf2x_add(12, f_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_01+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1248, 4, f_sum+1248, 4, temp+4);
	right_bit_shift_n(12, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+1204+4, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+4, 8, p_11+420);
	gf2x_add(12, g_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+420+4, 4, f_sum+1204);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, g_sum+1204);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1248, 4, g_sum+1248, 4, temp+4);
	right_bit_shift_n(12, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1249, g_sum+1249, q_00+404, q_01+404, q_10+404, q_11+404);

	// Recombining results: n: 765, depth: 5
	memset(q_00+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_01+404);
	gf2x_add(8, q_00+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+392+0, 8, q_00+392+0, 8, temp);
	memset(q_01+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_01+404);
	gf2x_add(8, q_01+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+392+0, 8, q_01+392+0, 8, temp);
	memset(q_10+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_11+404);
	gf2x_add(8, q_10+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+392+0, 8, q_10+392+0, 8, temp);
	memset(q_11+392, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_11+404);
	gf2x_add(8, q_11+392+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+392+0, 8, q_11+392+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 4
	memset(p_00+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, q_00+392);
	GF2X_MUL(24, temp2, 12, p_10+404+4, 12, q_01+392);
	gf2x_add(24, p_00+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+392+8, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+8, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+376+8, 8, p_00+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+4, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+4, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+376+4, 8, p_00+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+0, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_01+392+0, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+376+0, 8, p_00+376+0, 8, temp);
	memset(p_01+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+404+4, 12, q_00+392);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, q_01+392);
	gf2x_add(24, p_01+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+392+8, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+8, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+376+8, 8, p_01+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+4, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+4, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+376+4, 8, p_01+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+392+0, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_01+392+0, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+376+0, 8, p_01+376+0, 8, temp);
	memset(p_10+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+404+4, 12, q_10+392);
	GF2X_MUL(24, temp2, 12, p_10+404+4, 12, q_11+392);
	gf2x_add(24, p_10+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+392+8, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+8, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+376+8, 8, p_10+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+4, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+4, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+376+4, 8, p_10+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+0, 4, p_00+404);
	GF2X_MUL(8, temp2, 4, q_11+392+0, 4, p_10+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+376+0, 8, p_10+376+0, 8, temp);
	memset(p_11+376, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+404+4, 12, q_10+392);
	GF2X_MUL(24, temp2, 12, p_11+404+4, 12, q_11+392);
	gf2x_add(24, p_11+376+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+392+8, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+8, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+376+8, 8, p_11+376+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+4, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+4, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+376+4, 8, p_11+376+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+392+0, 4, p_01+404);
	GF2X_MUL(8, temp2, 4, q_11+392+0, 4, p_11+404);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+376+0, 8, p_11+376+0, 8, temp);
	

	// Calculating left operands: n: 3078, depth: 3
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+954+21, 28, p_00+376);
	GF2X_MUL(56, temp2, 28, g_sum+954+21, 28, p_01+376);
	gf2x_add(49, f_sum+1118, 49, temp+7, 49, temp2+7);
	GF2X_MUL(42, temp, 21, p_00+376+7, 21, f_sum+954);
	GF2X_MUL(42, temp2, 21, p_01+376+7, 21, g_sum+954);
	gf2x_add(42, temp, 42, temp, 42, temp2);
	gf2x_add(21, f_sum+1118, 21, f_sum+1118, 21, temp+21);
	right_bit_shift_n(49, f_sum+1118, 57);
	GF2X_MUL(56, temp, 28, f_sum+954+21, 28, p_10+376);
	GF2X_MUL(56, temp2, 28, g_sum+954+21, 28, p_11+376);
	gf2x_add(49, g_sum+1118, 49, temp+7, 49, temp2+7);
	GF2X_MUL(42, temp, 21, p_10+376+7, 21, f_sum+954);
	GF2X_MUL(42, temp2, 21, p_11+376+7, 21, g_sum+954);
	gf2x_add(42, temp, 42, temp, 42, temp2);
	gf2x_add(21, g_sum+1118, 21, g_sum+1118, 21, temp+21);
	right_bit_shift_n(49, g_sum+1118, 57);
	

	delta = divstepsx_256(255, delta, f_sum+1136, g_sum+1136, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1132+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1132+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1132+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1132+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1132+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1132+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1132+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1132+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1128+4, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+1128+4, 8, p_01+420);
	gf2x_add(12, f_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, f_sum+1128);
	GF2X_MUL(8, temp2, 4, p_01+420+4, 4, g_sum+1128);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1248, 4, f_sum+1248, 4, temp+4);
	right_bit_shift_n(12, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+1128+4, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+1128+4, 8, p_11+420);
	gf2x_add(12, g_sum+1248, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+420+4, 4, f_sum+1128);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, g_sum+1128);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1248, 4, g_sum+1248, 4, temp+4);
	right_bit_shift_n(12, g_sum+1248, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1249, g_sum+1249, q_00+404, q_01+404, q_10+404, q_11+404);

	// Recombining results: n: 765, depth: 5
	memset(p_00+404, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_01+404);
	gf2x_add(8, p_00+404+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+404+0, 8, p_00+404+0, 8, temp);
	memset(p_01+404, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_00+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_01+404);
	gf2x_add(8, p_01+404+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_01+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+404+0, 8, p_01+404+0, 8, temp);
	memset(p_10+404, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_10+420+4, 4, q_11+404);
	gf2x_add(8, p_10+404+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_00+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_10+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+404+0, 8, p_10+404+0, 8, temp);
	memset(p_11+404, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+420+4, 4, q_10+404);
	GF2X_MUL(8, temp2, 4, p_11+420+4, 4, q_11+404);
	gf2x_add(8, p_11+404+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+404+0, 4, p_01+420);
	GF2X_MUL(8, temp2, 4, q_11+404+0, 4, p_11+420);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+404+0, 8, p_11+404+0, 8, temp);
	

	// Calculating left operands: n: 1293, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1119+9, 12, p_00+404);
	GF2X_MUL(24, temp2, 12, g_sum+1119+9, 12, p_01+404);
	gf2x_add(21, f_sum+1203, 21, temp+3, 21, temp2+3);
	GF2X_MUL(18, temp, 9, p_00+404+3, 9, f_sum+1119);
	GF2X_MUL(18, temp2, 9, p_01+404+3, 9, g_sum+1119);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(9, f_sum+1203, 9, f_sum+1203, 9, temp+9);
	right_bit_shift_n(21, f_sum+1203, 61);
	GF2X_MUL(24, temp, 12, f_sum+1119+9, 12, p_10+404);
	GF2X_MUL(24, temp2, 12, g_sum+1119+9, 12, p_11+404);
	gf2x_add(21, g_sum+1203, 21, temp+3, 21, temp2+3);
	GF2X_MUL(18, temp, 9, p_10+404+3, 9, f_sum+1119);
	GF2X_MUL(18, temp2, 9, p_11+404+3, 9, g_sum+1119);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(9, g_sum+1203, 9, g_sum+1203, 9, temp+9);
	right_bit_shift_n(21, g_sum+1203, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1209, g_sum+1209, p_00+428, p_01+428, p_10+428, p_11+428);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1205+4, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1205+4, 4, p_01+428);
	gf2x_add(8, f_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1205+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, g_sum+1205+0, 4, p_01+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1273, 4, f_sum+1273, 4, temp+4);
	right_bit_shift_n(8, f_sum+1273, 63);
	GF2X_MUL(8, temp, 4, f_sum+1205+4, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1205+4, 4, p_11+428);
	gf2x_add(8, g_sum+1273+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1205+0, 4, p_10+428);
	GF2X_MUL(8, temp2, 4, g_sum+1205+0, 4, p_11+428);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1273, 4, g_sum+1273, 4, temp+4);
	right_bit_shift_n(8, g_sum+1273, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1274, g_sum+1274, q_00+412, q_01+412, q_10+412, q_11+412);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_10+428);
	gf2x_add(8, p_00+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_01+412+0, 4, p_11+428);
	gf2x_add(8, p_01+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_00+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_10+428);
	gf2x_add(8, p_10+420+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+412+0, 4, p_01+428);
	GF2X_MUL(8, temp2, 4, q_11+412+0, 4, p_11+428);
	gf2x_add(8, p_11+420+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 528, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1204+1, 8, p_00+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+1, 8, p_01+420);
	gf2x_add(9, f_sum+1248, 9, temp+7, 9, temp2+7);
	GF2X_MUL(2, temp, 1, p_00+420+7, 1, f_sum+1204);
	GF2X_MUL(2, temp2, 1, p_01+420+7, 1, g_sum+1204);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, f_sum+1248, 1, f_sum+1248, 1, temp+1);
	right_bit_shift_n(9, f_sum+1248, 62);
	GF2X_MUL(16, temp, 8, f_sum+1204+1, 8, p_10+420);
	GF2X_MUL(16, temp2, 8, g_sum+1204+1, 8, p_11+420);
	gf2x_add(9, g_sum+1248, 9, temp+7, 9, temp2+7);
	GF2X_MUL(2, temp, 1, p_10+420+7, 1, f_sum+1204);
	GF2X_MUL(2, temp2, 1, p_11+420+7, 1, g_sum+1204);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, g_sum+1248, 1, g_sum+1248, 1, temp+1);
	right_bit_shift_n(9, g_sum+1248, 62);
	

	delta = divstepsx(18, delta, *(f_sum+1249), *(g_sum+1249), q_00+404, q_01+404, q_10+404, q_11+404);

	// Recombining results: n: 528, depth: 5
	memset(q_00+392, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(2, temp, 1, p_00+420+7, 1, q_00+404);
	GF2X_MUL(2, temp2, 1, p_10+420+7, 1, q_01+404);
	gf2x_add(2, q_00+392+7, 2, temp, 2, temp2);
	GF2X_MUL(2, temp, 1, p_00+420+6, 1, q_00+404);
	GF2X_MUL(2, temp2, 1, p_10+420+6, 1, q_01+404);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+392+6, 2, q_00+392+6, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+420+5, 1, q_00+404);
	GF2X_MUL(2, temp2, 1, p_10+420+5, 1, q_01+404);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+392+5, 2, q_00+392+5, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+420+4, 1, q_00+404);
	GF2X_MUL(2, temp2, 1, p_10+420+4, 1, q_01+404);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+392+4, 2, q_00+392+4, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+420+3, 1, q_00+404);
	GF2X_MUL(2, temp2, 1, p_10+420+3, 1, q_01+404);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+392+3, 2, q_00+392+3, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+420+2, 1, q_00+404);
	GF2X_MUL(2, temp2, 1, p_10+420+2, 1, q_01+404);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+392+2, 2, q_00+392+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+420+1, 1, q_00+404);
	GF2X_MUL(2, temp2, 1, p_10+420+1, 1, q_01+404);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+392+1, 2, q_00+392+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+404+0, 1, p_00+420);
	GF2X_MUL(2, temp2, 1, q_01+404+0, 1, p_10+420);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+392+0, 2, q_00+392+0, 2, temp);
	memset(q_01+392, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(2, temp, 1, p_01+420+7, 1, q_00+404);
	GF2X_MUL(2, temp2, 1, p_11+420+7, 1, q_01+404);
	gf2x_add(2, q_01+392+7, 2, temp, 2, temp2);
	GF2X_MUL(2, temp, 1, p_01+420+6, 1, q_00+404);
	GF2X_MUL(2, temp2, 1, p_11+420+6, 1, q_01+404);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+392+6, 2, q_01+392+6, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+420+5, 1, q_00+404);
	GF2X_MUL(2, temp2, 1, p_11+420+5, 1, q_01+404);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+392+5, 2, q_01+392+5, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+420+4, 1, q_00+404);
	GF2X_MUL(2, temp2, 1, p_11+420+4, 1, q_01+404);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+392+4, 2, q_01+392+4, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+420+3, 1, q_00+404);
	GF2X_MUL(2, temp2, 1, p_11+420+3, 1, q_01+404);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+392+3, 2, q_01+392+3, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+420+2, 1, q_00+404);
	GF2X_MUL(2, temp2, 1, p_11+420+2, 1, q_01+404);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+392+2, 2, q_01+392+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+420+1, 1, q_00+404);
	GF2X_MUL(2, temp2, 1, p_11+420+1, 1, q_01+404);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+392+1, 2, q_01+392+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+404+0, 1, p_01+420);
	GF2X_MUL(2, temp2, 1, q_01+404+0, 1, p_11+420);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+392+0, 2, q_01+392+0, 2, temp);
	memset(q_10+392, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(2, temp, 1, p_00+420+7, 1, q_10+404);
	GF2X_MUL(2, temp2, 1, p_10+420+7, 1, q_11+404);
	gf2x_add(2, q_10+392+7, 2, temp, 2, temp2);
	GF2X_MUL(2, temp, 1, p_00+420+6, 1, q_10+404);
	GF2X_MUL(2, temp2, 1, p_10+420+6, 1, q_11+404);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+392+6, 2, q_10+392+6, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+420+5, 1, q_10+404);
	GF2X_MUL(2, temp2, 1, p_10+420+5, 1, q_11+404);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+392+5, 2, q_10+392+5, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+420+4, 1, q_10+404);
	GF2X_MUL(2, temp2, 1, p_10+420+4, 1, q_11+404);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+392+4, 2, q_10+392+4, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+420+3, 1, q_10+404);
	GF2X_MUL(2, temp2, 1, p_10+420+3, 1, q_11+404);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+392+3, 2, q_10+392+3, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+420+2, 1, q_10+404);
	GF2X_MUL(2, temp2, 1, p_10+420+2, 1, q_11+404);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+392+2, 2, q_10+392+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+420+1, 1, q_10+404);
	GF2X_MUL(2, temp2, 1, p_10+420+1, 1, q_11+404);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+392+1, 2, q_10+392+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+404+0, 1, p_00+420);
	GF2X_MUL(2, temp2, 1, q_11+404+0, 1, p_10+420);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+392+0, 2, q_10+392+0, 2, temp);
	memset(q_11+392, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(2, temp, 1, p_01+420+7, 1, q_10+404);
	GF2X_MUL(2, temp2, 1, p_11+420+7, 1, q_11+404);
	gf2x_add(2, q_11+392+7, 2, temp, 2, temp2);
	GF2X_MUL(2, temp, 1, p_01+420+6, 1, q_10+404);
	GF2X_MUL(2, temp2, 1, p_11+420+6, 1, q_11+404);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+392+6, 2, q_11+392+6, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+420+5, 1, q_10+404);
	GF2X_MUL(2, temp2, 1, p_11+420+5, 1, q_11+404);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+392+5, 2, q_11+392+5, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+420+4, 1, q_10+404);
	GF2X_MUL(2, temp2, 1, p_11+420+4, 1, q_11+404);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+392+4, 2, q_11+392+4, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+420+3, 1, q_10+404);
	GF2X_MUL(2, temp2, 1, p_11+420+3, 1, q_11+404);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+392+3, 2, q_11+392+3, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+420+2, 1, q_10+404);
	GF2X_MUL(2, temp2, 1, p_11+420+2, 1, q_11+404);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+392+2, 2, q_11+392+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+420+1, 1, q_10+404);
	GF2X_MUL(2, temp2, 1, p_11+420+1, 1, q_11+404);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+392+1, 2, q_11+392+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+404+0, 1, p_01+420);
	GF2X_MUL(2, temp2, 1, q_11+404+0, 1, p_11+420);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+392+0, 2, q_11+392+0, 2, temp);
	

	// Recombining results: n: 1293, depth: 4
	memset(q_00+364, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(18, temp, 9, p_00+404+3, 9, q_00+392);
	GF2X_MUL(18, temp2, 9, p_10+404+3, 9, q_01+392);
	gf2x_add(18, q_00+364+3, 18, temp, 18, temp2);
	GF2X_MUL(6, temp, 3, q_00+392+6, 3, p_00+404);
	GF2X_MUL(6, temp2, 3, q_01+392+6, 3, p_10+404);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+6, 6, q_00+364+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+392+3, 3, p_00+404);
	GF2X_MUL(6, temp2, 3, q_01+392+3, 3, p_10+404);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+3, 6, q_00+364+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+392+0, 3, p_00+404);
	GF2X_MUL(6, temp2, 3, q_01+392+0, 3, p_10+404);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+0, 6, q_00+364+0, 6, temp);
	memset(q_01+364, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(18, temp, 9, p_01+404+3, 9, q_00+392);
	GF2X_MUL(18, temp2, 9, p_11+404+3, 9, q_01+392);
	gf2x_add(18, q_01+364+3, 18, temp, 18, temp2);
	GF2X_MUL(6, temp, 3, q_00+392+6, 3, p_01+404);
	GF2X_MUL(6, temp2, 3, q_01+392+6, 3, p_11+404);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+6, 6, q_01+364+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+392+3, 3, p_01+404);
	GF2X_MUL(6, temp2, 3, q_01+392+3, 3, p_11+404);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+3, 6, q_01+364+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+392+0, 3, p_01+404);
	GF2X_MUL(6, temp2, 3, q_01+392+0, 3, p_11+404);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+0, 6, q_01+364+0, 6, temp);
	memset(q_10+364, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(18, temp, 9, p_00+404+3, 9, q_10+392);
	GF2X_MUL(18, temp2, 9, p_10+404+3, 9, q_11+392);
	gf2x_add(18, q_10+364+3, 18, temp, 18, temp2);
	GF2X_MUL(6, temp, 3, q_10+392+6, 3, p_00+404);
	GF2X_MUL(6, temp2, 3, q_11+392+6, 3, p_10+404);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+6, 6, q_10+364+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+392+3, 3, p_00+404);
	GF2X_MUL(6, temp2, 3, q_11+392+3, 3, p_10+404);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+3, 6, q_10+364+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+392+0, 3, p_00+404);
	GF2X_MUL(6, temp2, 3, q_11+392+0, 3, p_10+404);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+0, 6, q_10+364+0, 6, temp);
	memset(q_11+364, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(18, temp, 9, p_01+404+3, 9, q_10+392);
	GF2X_MUL(18, temp2, 9, p_11+404+3, 9, q_11+392);
	gf2x_add(18, q_11+364+3, 18, temp, 18, temp2);
	GF2X_MUL(6, temp, 3, q_10+392+6, 3, p_01+404);
	GF2X_MUL(6, temp2, 3, q_11+392+6, 3, p_11+404);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+6, 6, q_11+364+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+392+3, 3, p_01+404);
	GF2X_MUL(6, temp2, 3, q_11+392+3, 3, p_11+404);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+3, 6, q_11+364+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+392+0, 3, p_01+404);
	GF2X_MUL(6, temp2, 3, q_11+392+0, 3, p_11+404);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+0, 6, q_11+364+0, 6, temp);
	

	// Recombining results: n: 3078, depth: 3
	memset(q_00+312, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(42, temp, 21, p_00+376+7, 21, q_00+364);
	GF2X_MUL(42, temp2, 21, p_10+376+7, 21, q_01+364);
	gf2x_add(42, q_00+312+7, 42, temp, 42, temp2);
	GF2X_MUL(14, temp, 7, q_00+364+14, 7, p_00+376);
	GF2X_MUL(14, temp2, 7, q_01+364+14, 7, p_10+376);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_00+312+14, 14, q_00+312+14, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+364+7, 7, p_00+376);
	GF2X_MUL(14, temp2, 7, q_01+364+7, 7, p_10+376);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_00+312+7, 14, q_00+312+7, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+364+0, 7, p_00+376);
	GF2X_MUL(14, temp2, 7, q_01+364+0, 7, p_10+376);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_00+312+0, 14, q_00+312+0, 14, temp);
	memset(q_01+312, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(42, temp, 21, p_01+376+7, 21, q_00+364);
	GF2X_MUL(42, temp2, 21, p_11+376+7, 21, q_01+364);
	gf2x_add(42, q_01+312+7, 42, temp, 42, temp2);
	GF2X_MUL(14, temp, 7, q_00+364+14, 7, p_01+376);
	GF2X_MUL(14, temp2, 7, q_01+364+14, 7, p_11+376);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_01+312+14, 14, q_01+312+14, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+364+7, 7, p_01+376);
	GF2X_MUL(14, temp2, 7, q_01+364+7, 7, p_11+376);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_01+312+7, 14, q_01+312+7, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+364+0, 7, p_01+376);
	GF2X_MUL(14, temp2, 7, q_01+364+0, 7, p_11+376);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_01+312+0, 14, q_01+312+0, 14, temp);
	memset(q_10+312, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(42, temp, 21, p_00+376+7, 21, q_10+364);
	GF2X_MUL(42, temp2, 21, p_10+376+7, 21, q_11+364);
	gf2x_add(42, q_10+312+7, 42, temp, 42, temp2);
	GF2X_MUL(14, temp, 7, q_10+364+14, 7, p_00+376);
	GF2X_MUL(14, temp2, 7, q_11+364+14, 7, p_10+376);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_10+312+14, 14, q_10+312+14, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+364+7, 7, p_00+376);
	GF2X_MUL(14, temp2, 7, q_11+364+7, 7, p_10+376);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_10+312+7, 14, q_10+312+7, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+364+0, 7, p_00+376);
	GF2X_MUL(14, temp2, 7, q_11+364+0, 7, p_10+376);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_10+312+0, 14, q_10+312+0, 14, temp);
	memset(q_11+312, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(42, temp, 21, p_01+376+7, 21, q_10+364);
	GF2X_MUL(42, temp2, 21, p_11+376+7, 21, q_11+364);
	gf2x_add(42, q_11+312+7, 42, temp, 42, temp2);
	GF2X_MUL(14, temp, 7, q_10+364+14, 7, p_01+376);
	GF2X_MUL(14, temp2, 7, q_11+364+14, 7, p_11+376);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_11+312+14, 14, q_11+312+14, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+364+7, 7, p_01+376);
	GF2X_MUL(14, temp2, 7, q_11+364+7, 7, p_11+376);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_11+312+7, 14, q_11+312+7, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+364+0, 7, p_01+376);
	GF2X_MUL(14, temp2, 7, q_11+364+0, 7, p_11+376);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_11+312+0, 14, q_11+312+0, 14, temp);
	

	// Recombining results: n: 6393, depth: 2
	memset(q_00+208, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(98, temp, 49, p_00+320+3, 49, q_00+312);
	GF2X_MUL(98, temp2, 49, p_10+320+3, 49, q_01+312);
	gf2x_add(98, q_00+208+2, 98, temp, 98, temp2);
	GF2X_MUL(6, temp, 3, q_00+312+46, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_01+312+46, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+208+45, 6, q_00+208+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+43, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_01+312+43, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+208+42, 6, q_00+208+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+40, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_01+312+40, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+208+39, 6, q_00+208+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+37, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_01+312+37, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+208+36, 6, q_00+208+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+34, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_01+312+34, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+208+33, 6, q_00+208+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+31, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_01+312+31, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+208+30, 6, q_00+208+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+28, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_01+312+28, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+208+27, 6, q_00+208+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+25, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_01+312+25, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+208+24, 6, q_00+208+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+22, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_01+312+22, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+208+21, 6, q_00+208+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+19, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_01+312+19, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+208+18, 6, q_00+208+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+16, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_01+312+16, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+208+15, 6, q_00+208+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+13, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_01+312+13, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+208+12, 6, q_00+208+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+10, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_01+312+10, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+208+9, 6, q_00+208+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+7, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_01+312+7, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+208+6, 6, q_00+208+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+4, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_01+312+4, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+208+3, 6, q_00+208+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+1, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_01+312+1, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+208+0, 6, q_00+208+0, 6, temp);
	GF2X_MUL(2, temp, 1, p_00+320+2, 1, q_00+312);
	GF2X_MUL(2, temp2, 1, p_10+320+2, 1, q_01+312);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+208+1, 2, q_00+208+1, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+320+1, 1, q_00+312);
	GF2X_MUL(2, temp2, 1, p_10+320+1, 1, q_01+312);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+208+0, 2, q_00+208+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+312+0, 1, p_00+320);
	GF2X_MUL(2, temp2, 1, q_01+312+0, 1, p_10+320);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_00+208, 1, q_00+208, 1, temp+1);
	memset(q_01+208, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(98, temp, 49, p_01+320+3, 49, q_00+312);
	GF2X_MUL(98, temp2, 49, p_11+320+3, 49, q_01+312);
	gf2x_add(98, q_01+208+2, 98, temp, 98, temp2);
	GF2X_MUL(6, temp, 3, q_00+312+46, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_01+312+46, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+208+45, 6, q_01+208+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+43, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_01+312+43, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+208+42, 6, q_01+208+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+40, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_01+312+40, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+208+39, 6, q_01+208+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+37, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_01+312+37, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+208+36, 6, q_01+208+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+34, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_01+312+34, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+208+33, 6, q_01+208+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+31, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_01+312+31, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+208+30, 6, q_01+208+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+28, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_01+312+28, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+208+27, 6, q_01+208+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+25, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_01+312+25, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+208+24, 6, q_01+208+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+22, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_01+312+22, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+208+21, 6, q_01+208+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+19, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_01+312+19, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+208+18, 6, q_01+208+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+16, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_01+312+16, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+208+15, 6, q_01+208+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+13, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_01+312+13, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+208+12, 6, q_01+208+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+10, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_01+312+10, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+208+9, 6, q_01+208+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+7, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_01+312+7, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+208+6, 6, q_01+208+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+4, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_01+312+4, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+208+3, 6, q_01+208+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+312+1, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_01+312+1, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+208+0, 6, q_01+208+0, 6, temp);
	GF2X_MUL(2, temp, 1, p_01+320+2, 1, q_00+312);
	GF2X_MUL(2, temp2, 1, p_11+320+2, 1, q_01+312);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+208+1, 2, q_01+208+1, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+320+1, 1, q_00+312);
	GF2X_MUL(2, temp2, 1, p_11+320+1, 1, q_01+312);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+208+0, 2, q_01+208+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+312+0, 1, p_01+320);
	GF2X_MUL(2, temp2, 1, q_01+312+0, 1, p_11+320);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_01+208, 1, q_01+208, 1, temp+1);
	memset(q_10+208, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(98, temp, 49, p_00+320+3, 49, q_10+312);
	GF2X_MUL(98, temp2, 49, p_10+320+3, 49, q_11+312);
	gf2x_add(98, q_10+208+2, 98, temp, 98, temp2);
	GF2X_MUL(6, temp, 3, q_10+312+46, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_11+312+46, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+208+45, 6, q_10+208+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+43, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_11+312+43, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+208+42, 6, q_10+208+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+40, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_11+312+40, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+208+39, 6, q_10+208+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+37, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_11+312+37, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+208+36, 6, q_10+208+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+34, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_11+312+34, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+208+33, 6, q_10+208+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+31, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_11+312+31, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+208+30, 6, q_10+208+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+28, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_11+312+28, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+208+27, 6, q_10+208+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+25, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_11+312+25, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+208+24, 6, q_10+208+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+22, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_11+312+22, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+208+21, 6, q_10+208+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+19, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_11+312+19, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+208+18, 6, q_10+208+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+16, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_11+312+16, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+208+15, 6, q_10+208+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+13, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_11+312+13, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+208+12, 6, q_10+208+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+10, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_11+312+10, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+208+9, 6, q_10+208+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+7, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_11+312+7, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+208+6, 6, q_10+208+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+4, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_11+312+4, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+208+3, 6, q_10+208+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+1, 3, p_00+320);
	GF2X_MUL(6, temp2, 3, q_11+312+1, 3, p_10+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+208+0, 6, q_10+208+0, 6, temp);
	GF2X_MUL(2, temp, 1, p_00+320+2, 1, q_10+312);
	GF2X_MUL(2, temp2, 1, p_10+320+2, 1, q_11+312);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+208+1, 2, q_10+208+1, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+320+1, 1, q_10+312);
	GF2X_MUL(2, temp2, 1, p_10+320+1, 1, q_11+312);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+208+0, 2, q_10+208+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+312+0, 1, p_00+320);
	GF2X_MUL(2, temp2, 1, q_11+312+0, 1, p_10+320);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_10+208, 1, q_10+208, 1, temp+1);
	memset(q_11+208, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(98, temp, 49, p_01+320+3, 49, q_10+312);
	GF2X_MUL(98, temp2, 49, p_11+320+3, 49, q_11+312);
	gf2x_add(98, q_11+208+2, 98, temp, 98, temp2);
	GF2X_MUL(6, temp, 3, q_10+312+46, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_11+312+46, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+208+45, 6, q_11+208+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+43, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_11+312+43, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+208+42, 6, q_11+208+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+40, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_11+312+40, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+208+39, 6, q_11+208+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+37, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_11+312+37, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+208+36, 6, q_11+208+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+34, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_11+312+34, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+208+33, 6, q_11+208+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+31, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_11+312+31, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+208+30, 6, q_11+208+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+28, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_11+312+28, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+208+27, 6, q_11+208+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+25, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_11+312+25, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+208+24, 6, q_11+208+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+22, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_11+312+22, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+208+21, 6, q_11+208+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+19, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_11+312+19, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+208+18, 6, q_11+208+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+16, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_11+312+16, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+208+15, 6, q_11+208+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+13, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_11+312+13, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+208+12, 6, q_11+208+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+10, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_11+312+10, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+208+9, 6, q_11+208+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+7, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_11+312+7, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+208+6, 6, q_11+208+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+4, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_11+312+4, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+208+3, 6, q_11+208+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+312+1, 3, p_01+320);
	GF2X_MUL(6, temp2, 3, q_11+312+1, 3, p_11+320);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+208+0, 6, q_11+208+0, 6, temp);
	GF2X_MUL(2, temp, 1, p_01+320+2, 1, q_10+312);
	GF2X_MUL(2, temp2, 1, p_11+320+2, 1, q_11+312);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+208+1, 2, q_11+208+1, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+320+1, 1, q_10+312);
	GF2X_MUL(2, temp2, 1, p_11+320+1, 1, q_11+312);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+208+0, 2, q_11+208+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+312+0, 1, p_01+320);
	GF2X_MUL(2, temp2, 1, q_11+312+0, 1, p_11+320);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_11+208, 1, q_11+208, 1, temp+1);
	

	// Recombining results: n: 13278, depth: 1
	memset(q_00+0, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(200, temp, 100, p_00+212+8, 100, q_00+208);
	GF2X_MUL(200, temp2, 100, p_10+212+8, 100, q_01+208);
	gf2x_add(200, q_00+0+8, 200, temp, 200, temp2);
	GF2X_MUL(16, temp, 8, q_00+208+92, 8, p_00+212);
	GF2X_MUL(16, temp2, 8, q_01+208+92, 8, p_10+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0+92, 16, q_00+0+92, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+208+84, 8, p_00+212);
	GF2X_MUL(16, temp2, 8, q_01+208+84, 8, p_10+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0+84, 16, q_00+0+84, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+208+76, 8, p_00+212);
	GF2X_MUL(16, temp2, 8, q_01+208+76, 8, p_10+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0+76, 16, q_00+0+76, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+208+68, 8, p_00+212);
	GF2X_MUL(16, temp2, 8, q_01+208+68, 8, p_10+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0+68, 16, q_00+0+68, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+208+60, 8, p_00+212);
	GF2X_MUL(16, temp2, 8, q_01+208+60, 8, p_10+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0+60, 16, q_00+0+60, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+208+52, 8, p_00+212);
	GF2X_MUL(16, temp2, 8, q_01+208+52, 8, p_10+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0+52, 16, q_00+0+52, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+208+44, 8, p_00+212);
	GF2X_MUL(16, temp2, 8, q_01+208+44, 8, p_10+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0+44, 16, q_00+0+44, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+208+36, 8, p_00+212);
	GF2X_MUL(16, temp2, 8, q_01+208+36, 8, p_10+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0+36, 16, q_00+0+36, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+208+28, 8, p_00+212);
	GF2X_MUL(16, temp2, 8, q_01+208+28, 8, p_10+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0+28, 16, q_00+0+28, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+208+20, 8, p_00+212);
	GF2X_MUL(16, temp2, 8, q_01+208+20, 8, p_10+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0+20, 16, q_00+0+20, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+208+12, 8, p_00+212);
	GF2X_MUL(16, temp2, 8, q_01+208+12, 8, p_10+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0+12, 16, q_00+0+12, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+208+4, 8, p_00+212);
	GF2X_MUL(16, temp2, 8, q_01+208+4, 8, p_10+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0+4, 16, q_00+0+4, 16, temp);
	GF2X_MUL(8, temp, 4, p_00+212+4, 4, q_00+208);
	GF2X_MUL(8, temp2, 4, p_10+212+4, 4, q_01+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+0+4, 8, q_00+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+0, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_01+208+0, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+0+0, 8, q_00+0+0, 8, temp);
	memset(q_01+0, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(200, temp, 100, p_01+212+8, 100, q_00+208);
	GF2X_MUL(200, temp2, 100, p_11+212+8, 100, q_01+208);
	gf2x_add(200, q_01+0+8, 200, temp, 200, temp2);
	GF2X_MUL(16, temp, 8, q_00+208+92, 8, p_01+212);
	GF2X_MUL(16, temp2, 8, q_01+208+92, 8, p_11+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0+92, 16, q_01+0+92, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+208+84, 8, p_01+212);
	GF2X_MUL(16, temp2, 8, q_01+208+84, 8, p_11+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0+84, 16, q_01+0+84, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+208+76, 8, p_01+212);
	GF2X_MUL(16, temp2, 8, q_01+208+76, 8, p_11+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0+76, 16, q_01+0+76, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+208+68, 8, p_01+212);
	GF2X_MUL(16, temp2, 8, q_01+208+68, 8, p_11+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0+68, 16, q_01+0+68, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+208+60, 8, p_01+212);
	GF2X_MUL(16, temp2, 8, q_01+208+60, 8, p_11+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0+60, 16, q_01+0+60, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+208+52, 8, p_01+212);
	GF2X_MUL(16, temp2, 8, q_01+208+52, 8, p_11+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0+52, 16, q_01+0+52, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+208+44, 8, p_01+212);
	GF2X_MUL(16, temp2, 8, q_01+208+44, 8, p_11+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0+44, 16, q_01+0+44, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+208+36, 8, p_01+212);
	GF2X_MUL(16, temp2, 8, q_01+208+36, 8, p_11+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0+36, 16, q_01+0+36, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+208+28, 8, p_01+212);
	GF2X_MUL(16, temp2, 8, q_01+208+28, 8, p_11+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0+28, 16, q_01+0+28, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+208+20, 8, p_01+212);
	GF2X_MUL(16, temp2, 8, q_01+208+20, 8, p_11+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0+20, 16, q_01+0+20, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+208+12, 8, p_01+212);
	GF2X_MUL(16, temp2, 8, q_01+208+12, 8, p_11+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0+12, 16, q_01+0+12, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+208+4, 8, p_01+212);
	GF2X_MUL(16, temp2, 8, q_01+208+4, 8, p_11+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0+4, 16, q_01+0+4, 16, temp);
	GF2X_MUL(8, temp, 4, p_01+212+4, 4, q_00+208);
	GF2X_MUL(8, temp2, 4, p_11+212+4, 4, q_01+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+0+4, 8, q_01+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+208+0, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_01+208+0, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+0+0, 8, q_01+0+0, 8, temp);
	memset(q_10+0, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(200, temp, 100, p_00+212+8, 100, q_10+208);
	GF2X_MUL(200, temp2, 100, p_10+212+8, 100, q_11+208);
	gf2x_add(200, q_10+0+8, 200, temp, 200, temp2);
	GF2X_MUL(16, temp, 8, q_10+208+92, 8, p_00+212);
	GF2X_MUL(16, temp2, 8, q_11+208+92, 8, p_10+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0+92, 16, q_10+0+92, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+208+84, 8, p_00+212);
	GF2X_MUL(16, temp2, 8, q_11+208+84, 8, p_10+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0+84, 16, q_10+0+84, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+208+76, 8, p_00+212);
	GF2X_MUL(16, temp2, 8, q_11+208+76, 8, p_10+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0+76, 16, q_10+0+76, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+208+68, 8, p_00+212);
	GF2X_MUL(16, temp2, 8, q_11+208+68, 8, p_10+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0+68, 16, q_10+0+68, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+208+60, 8, p_00+212);
	GF2X_MUL(16, temp2, 8, q_11+208+60, 8, p_10+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0+60, 16, q_10+0+60, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+208+52, 8, p_00+212);
	GF2X_MUL(16, temp2, 8, q_11+208+52, 8, p_10+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0+52, 16, q_10+0+52, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+208+44, 8, p_00+212);
	GF2X_MUL(16, temp2, 8, q_11+208+44, 8, p_10+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0+44, 16, q_10+0+44, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+208+36, 8, p_00+212);
	GF2X_MUL(16, temp2, 8, q_11+208+36, 8, p_10+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0+36, 16, q_10+0+36, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+208+28, 8, p_00+212);
	GF2X_MUL(16, temp2, 8, q_11+208+28, 8, p_10+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0+28, 16, q_10+0+28, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+208+20, 8, p_00+212);
	GF2X_MUL(16, temp2, 8, q_11+208+20, 8, p_10+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0+20, 16, q_10+0+20, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+208+12, 8, p_00+212);
	GF2X_MUL(16, temp2, 8, q_11+208+12, 8, p_10+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0+12, 16, q_10+0+12, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+208+4, 8, p_00+212);
	GF2X_MUL(16, temp2, 8, q_11+208+4, 8, p_10+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0+4, 16, q_10+0+4, 16, temp);
	GF2X_MUL(8, temp, 4, p_00+212+4, 4, q_10+208);
	GF2X_MUL(8, temp2, 4, p_10+212+4, 4, q_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+0+4, 8, q_10+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+0, 4, p_00+212);
	GF2X_MUL(8, temp2, 4, q_11+208+0, 4, p_10+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+0+0, 8, q_10+0+0, 8, temp);
	memset(q_11+0, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(200, temp, 100, p_01+212+8, 100, q_10+208);
	GF2X_MUL(200, temp2, 100, p_11+212+8, 100, q_11+208);
	gf2x_add(200, q_11+0+8, 200, temp, 200, temp2);
	GF2X_MUL(16, temp, 8, q_10+208+92, 8, p_01+212);
	GF2X_MUL(16, temp2, 8, q_11+208+92, 8, p_11+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0+92, 16, q_11+0+92, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+208+84, 8, p_01+212);
	GF2X_MUL(16, temp2, 8, q_11+208+84, 8, p_11+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0+84, 16, q_11+0+84, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+208+76, 8, p_01+212);
	GF2X_MUL(16, temp2, 8, q_11+208+76, 8, p_11+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0+76, 16, q_11+0+76, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+208+68, 8, p_01+212);
	GF2X_MUL(16, temp2, 8, q_11+208+68, 8, p_11+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0+68, 16, q_11+0+68, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+208+60, 8, p_01+212);
	GF2X_MUL(16, temp2, 8, q_11+208+60, 8, p_11+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0+60, 16, q_11+0+60, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+208+52, 8, p_01+212);
	GF2X_MUL(16, temp2, 8, q_11+208+52, 8, p_11+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0+52, 16, q_11+0+52, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+208+44, 8, p_01+212);
	GF2X_MUL(16, temp2, 8, q_11+208+44, 8, p_11+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0+44, 16, q_11+0+44, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+208+36, 8, p_01+212);
	GF2X_MUL(16, temp2, 8, q_11+208+36, 8, p_11+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0+36, 16, q_11+0+36, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+208+28, 8, p_01+212);
	GF2X_MUL(16, temp2, 8, q_11+208+28, 8, p_11+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0+28, 16, q_11+0+28, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+208+20, 8, p_01+212);
	GF2X_MUL(16, temp2, 8, q_11+208+20, 8, p_11+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0+20, 16, q_11+0+20, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+208+12, 8, p_01+212);
	GF2X_MUL(16, temp2, 8, q_11+208+12, 8, p_11+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0+12, 16, q_11+0+12, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+208+4, 8, p_01+212);
	GF2X_MUL(16, temp2, 8, q_11+208+4, 8, p_11+212);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0+4, 16, q_11+0+4, 16, temp);
	GF2X_MUL(8, temp, 4, p_01+212+4, 4, q_10+208);
	GF2X_MUL(8, temp2, 4, p_11+212+4, 4, q_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+0+4, 8, q_11+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+208+0, 4, p_01+212);
	GF2X_MUL(8, temp2, 4, q_11+208+0, 4, p_11+212);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+0+0, 8, q_11+0+0, 8, temp);
	

	// Recombining results: n: 26793, depth: 0
	memset(t_00+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(416, temp, 208, p_00+0+4, 208, q_00+0);
	GF2X_MUL(416, temp2, 208, p_10+0+4, 208, q_01+0);
	gf2x_add(416, t_00+0+3, 416, temp, 416, temp2);
	GF2X_MUL(8, temp, 4, q_00+0+204, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+204, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+203, 8, t_00+0+203, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+200, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+200, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+199, 8, t_00+0+199, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+196, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+196, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+195, 8, t_00+0+195, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+192, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+192, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+191, 8, t_00+0+191, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+188, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+188, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+187, 8, t_00+0+187, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+184, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+184, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+183, 8, t_00+0+183, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+180, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+180, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+179, 8, t_00+0+179, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+176, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+176, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+175, 8, t_00+0+175, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+172, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+172, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+171, 8, t_00+0+171, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+168, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+168, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+167, 8, t_00+0+167, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+164, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+164, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+163, 8, t_00+0+163, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+160, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+160, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+159, 8, t_00+0+159, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+156, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+156, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+155, 8, t_00+0+155, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+152, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+152, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+151, 8, t_00+0+151, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+148, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+148, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+147, 8, t_00+0+147, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+144, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+144, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+143, 8, t_00+0+143, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+140, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+140, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+139, 8, t_00+0+139, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+136, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+136, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+135, 8, t_00+0+135, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+132, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+132, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+131, 8, t_00+0+131, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+128, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+128, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+127, 8, t_00+0+127, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+124, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+124, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+123, 8, t_00+0+123, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+120, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+120, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+119, 8, t_00+0+119, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+116, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+116, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+115, 8, t_00+0+115, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+112, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+112, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+111, 8, t_00+0+111, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+108, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+108, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+107, 8, t_00+0+107, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+104, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+104, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+103, 8, t_00+0+103, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+100, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+100, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+99, 8, t_00+0+99, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+96, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+96, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+95, 8, t_00+0+95, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+92, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+92, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+91, 8, t_00+0+91, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+88, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+88, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+87, 8, t_00+0+87, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+84, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+84, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+83, 8, t_00+0+83, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+80, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+80, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+79, 8, t_00+0+79, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+76, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+76, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+75, 8, t_00+0+75, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+72, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+72, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+71, 8, t_00+0+71, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+68, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+68, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+67, 8, t_00+0+67, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+64, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+64, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+63, 8, t_00+0+63, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+60, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+60, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+59, 8, t_00+0+59, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+56, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+56, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+55, 8, t_00+0+55, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+52, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+52, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+51, 8, t_00+0+51, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+48, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+48, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+47, 8, t_00+0+47, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+44, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+44, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+43, 8, t_00+0+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+40, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+40, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+39, 8, t_00+0+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+36, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+36, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+35, 8, t_00+0+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+32, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+32, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+31, 8, t_00+0+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+28, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+28, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+27, 8, t_00+0+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+24, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+24, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+23, 8, t_00+0+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+20, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+20, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+19, 8, t_00+0+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+16, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+16, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+15, 8, t_00+0+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+12, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+12, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+11, 8, t_00+0+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+8, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+8, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+7, 8, t_00+0+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+4, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+4, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+3, 8, t_00+0+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+0, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+0, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, t_00+0, 7, t_00+0, 7, temp+1);
	memset(t_01+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(416, temp, 208, p_01+0+4, 208, q_00+0);
	GF2X_MUL(416, temp2, 208, p_11+0+4, 208, q_01+0);
	gf2x_add(416, t_01+0+3, 416, temp, 416, temp2);
	GF2X_MUL(8, temp, 4, q_00+0+204, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+204, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+203, 8, t_01+0+203, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+200, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+200, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+199, 8, t_01+0+199, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+196, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+196, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+195, 8, t_01+0+195, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+192, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+192, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+191, 8, t_01+0+191, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+188, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+188, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+187, 8, t_01+0+187, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+184, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+184, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+183, 8, t_01+0+183, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+180, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+180, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+179, 8, t_01+0+179, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+176, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+176, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+175, 8, t_01+0+175, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+172, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+172, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+171, 8, t_01+0+171, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+168, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+168, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+167, 8, t_01+0+167, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+164, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+164, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+163, 8, t_01+0+163, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+160, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+160, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+159, 8, t_01+0+159, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+156, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+156, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+155, 8, t_01+0+155, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+152, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+152, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+151, 8, t_01+0+151, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+148, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+148, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+147, 8, t_01+0+147, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+144, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+144, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+143, 8, t_01+0+143, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+140, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+140, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+139, 8, t_01+0+139, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+136, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+136, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+135, 8, t_01+0+135, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+132, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+132, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+131, 8, t_01+0+131, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+128, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+128, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+127, 8, t_01+0+127, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+124, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+124, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+123, 8, t_01+0+123, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+120, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+120, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+119, 8, t_01+0+119, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+116, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+116, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+115, 8, t_01+0+115, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+112, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+112, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+111, 8, t_01+0+111, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+108, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+108, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+107, 8, t_01+0+107, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+104, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+104, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+103, 8, t_01+0+103, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+100, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+100, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+99, 8, t_01+0+99, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+96, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+96, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+95, 8, t_01+0+95, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+92, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+92, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+91, 8, t_01+0+91, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+88, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+88, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+87, 8, t_01+0+87, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+84, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+84, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+83, 8, t_01+0+83, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+80, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+80, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+79, 8, t_01+0+79, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+76, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+76, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+75, 8, t_01+0+75, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+72, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+72, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+71, 8, t_01+0+71, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+68, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+68, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+67, 8, t_01+0+67, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+64, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+64, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+63, 8, t_01+0+63, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+60, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+60, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+59, 8, t_01+0+59, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+56, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+56, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+55, 8, t_01+0+55, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+52, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+52, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+51, 8, t_01+0+51, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+48, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+48, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+47, 8, t_01+0+47, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+44, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+44, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+43, 8, t_01+0+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+40, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+40, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+39, 8, t_01+0+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+36, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+36, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+35, 8, t_01+0+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+32, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+32, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+31, 8, t_01+0+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+28, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+28, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+27, 8, t_01+0+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+24, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+24, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+23, 8, t_01+0+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+20, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+20, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+19, 8, t_01+0+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+16, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+16, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+15, 8, t_01+0+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+12, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+12, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+11, 8, t_01+0+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+8, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+8, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+7, 8, t_01+0+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+4, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+4, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+3, 8, t_01+0+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+0, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+0, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, t_01+0, 7, t_01+0, 7, temp+1);
	memset(t_10+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(416, temp, 208, p_00+0+4, 208, q_10+0);
	GF2X_MUL(416, temp2, 208, p_10+0+4, 208, q_11+0);
	gf2x_add(416, t_10+0+3, 416, temp, 416, temp2);
	GF2X_MUL(8, temp, 4, q_10+0+204, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+204, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+203, 8, t_10+0+203, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+200, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+200, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+199, 8, t_10+0+199, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+196, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+196, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+195, 8, t_10+0+195, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+192, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+192, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+191, 8, t_10+0+191, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+188, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+188, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+187, 8, t_10+0+187, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+184, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+184, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+183, 8, t_10+0+183, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+180, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+180, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+179, 8, t_10+0+179, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+176, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+176, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+175, 8, t_10+0+175, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+172, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+172, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+171, 8, t_10+0+171, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+168, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+168, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+167, 8, t_10+0+167, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+164, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+164, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+163, 8, t_10+0+163, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+160, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+160, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+159, 8, t_10+0+159, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+156, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+156, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+155, 8, t_10+0+155, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+152, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+152, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+151, 8, t_10+0+151, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+148, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+148, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+147, 8, t_10+0+147, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+144, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+144, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+143, 8, t_10+0+143, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+140, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+140, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+139, 8, t_10+0+139, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+136, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+136, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+135, 8, t_10+0+135, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+132, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+132, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+131, 8, t_10+0+131, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+128, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+128, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+127, 8, t_10+0+127, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+124, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+124, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+123, 8, t_10+0+123, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+120, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+120, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+119, 8, t_10+0+119, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+116, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+116, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+115, 8, t_10+0+115, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+112, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+112, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+111, 8, t_10+0+111, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+108, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+108, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+107, 8, t_10+0+107, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+104, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+104, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+103, 8, t_10+0+103, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+100, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+100, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+99, 8, t_10+0+99, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+96, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+96, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+95, 8, t_10+0+95, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+92, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+92, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+91, 8, t_10+0+91, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+88, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+88, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+87, 8, t_10+0+87, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+84, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+84, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+83, 8, t_10+0+83, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+80, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+80, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+79, 8, t_10+0+79, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+76, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+76, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+75, 8, t_10+0+75, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+72, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+72, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+71, 8, t_10+0+71, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+68, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+68, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+67, 8, t_10+0+67, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+64, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+64, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+63, 8, t_10+0+63, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+60, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+60, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+59, 8, t_10+0+59, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+56, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+56, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+55, 8, t_10+0+55, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+52, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+52, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+51, 8, t_10+0+51, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+48, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+48, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+47, 8, t_10+0+47, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+44, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+44, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+43, 8, t_10+0+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+40, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+40, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+39, 8, t_10+0+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+36, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+36, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+35, 8, t_10+0+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+32, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+32, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+31, 8, t_10+0+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+28, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+28, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+27, 8, t_10+0+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+24, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+24, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+23, 8, t_10+0+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+20, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+20, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+19, 8, t_10+0+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+16, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+16, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+15, 8, t_10+0+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+12, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+12, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+11, 8, t_10+0+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+8, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+8, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+7, 8, t_10+0+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+4, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+4, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+3, 8, t_10+0+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+0, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+0, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, t_10+0, 7, t_10+0, 7, temp+1);
	memset(t_11+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(416, temp, 208, p_01+0+4, 208, q_10+0);
	GF2X_MUL(416, temp2, 208, p_11+0+4, 208, q_11+0);
	gf2x_add(416, t_11+0+3, 416, temp, 416, temp2);
	GF2X_MUL(8, temp, 4, q_10+0+204, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+204, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+203, 8, t_11+0+203, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+200, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+200, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+199, 8, t_11+0+199, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+196, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+196, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+195, 8, t_11+0+195, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+192, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+192, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+191, 8, t_11+0+191, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+188, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+188, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+187, 8, t_11+0+187, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+184, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+184, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+183, 8, t_11+0+183, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+180, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+180, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+179, 8, t_11+0+179, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+176, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+176, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+175, 8, t_11+0+175, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+172, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+172, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+171, 8, t_11+0+171, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+168, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+168, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+167, 8, t_11+0+167, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+164, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+164, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+163, 8, t_11+0+163, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+160, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+160, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+159, 8, t_11+0+159, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+156, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+156, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+155, 8, t_11+0+155, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+152, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+152, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+151, 8, t_11+0+151, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+148, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+148, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+147, 8, t_11+0+147, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+144, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+144, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+143, 8, t_11+0+143, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+140, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+140, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+139, 8, t_11+0+139, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+136, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+136, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+135, 8, t_11+0+135, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+132, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+132, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+131, 8, t_11+0+131, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+128, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+128, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+127, 8, t_11+0+127, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+124, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+124, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+123, 8, t_11+0+123, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+120, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+120, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+119, 8, t_11+0+119, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+116, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+116, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+115, 8, t_11+0+115, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+112, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+112, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+111, 8, t_11+0+111, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+108, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+108, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+107, 8, t_11+0+107, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+104, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+104, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+103, 8, t_11+0+103, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+100, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+100, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+99, 8, t_11+0+99, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+96, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+96, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+95, 8, t_11+0+95, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+92, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+92, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+91, 8, t_11+0+91, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+88, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+88, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+87, 8, t_11+0+87, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+84, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+84, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+83, 8, t_11+0+83, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+80, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+80, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+79, 8, t_11+0+79, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+76, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+76, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+75, 8, t_11+0+75, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+72, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+72, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+71, 8, t_11+0+71, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+68, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+68, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+67, 8, t_11+0+67, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+64, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+64, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+63, 8, t_11+0+63, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+60, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+60, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+59, 8, t_11+0+59, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+56, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+56, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+55, 8, t_11+0+55, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+52, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+52, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+51, 8, t_11+0+51, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+48, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+48, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+47, 8, t_11+0+47, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+44, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+44, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+43, 8, t_11+0+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+40, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+40, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+39, 8, t_11+0+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+36, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+36, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+35, 8, t_11+0+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+32, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+32, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+31, 8, t_11+0+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+28, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+28, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+27, 8, t_11+0+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+24, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+24, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+23, 8, t_11+0+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+20, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+20, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+19, 8, t_11+0+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+16, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+16, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+15, 8, t_11+0+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+12, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+12, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+11, 8, t_11+0+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+8, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+8, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+7, 8, t_11+0+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+4, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+4, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+3, 8, t_11+0+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+0, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+0, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, t_11+0, 7, t_11+0, 7, temp+1);
	

	return delta;
}