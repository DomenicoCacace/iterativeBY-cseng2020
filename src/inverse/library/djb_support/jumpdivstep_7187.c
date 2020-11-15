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

int jumpdivstep_7187(int n, int delta, int nf, DIGIT *f, DIGIT *g, DIGIT *t_00, DIGIT *t_01, DIGIT *t_10, DIGIT *t_11, float x) {
	DIGIT p_00[236];
	DIGIT p_01[236];
	DIGIT p_10[236];
	DIGIT p_11[236];
	
	DIGIT q_00[222];
	DIGIT q_01[222];
	DIGIT q_10[222];
	DIGIT q_11[222];
	
	DIGIT f_sum[693];
	DIGIT g_sum[693];
	
	DIGIT temp[456];
	DIGIT recombine[456];
	DIGIT temp2[456];
	DIGIT buffer[456];
	

	delta = divstepsx_256(255, delta, f+221, g+221, p_00+232, p_01+232, p_10+232, p_11+232);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f+217);
	memcpy(buffer+4, p_01+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g+217);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f+217);
	memcpy(buffer+4, p_11+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g+217);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+681, g_sum+681, q_00+218, q_01+218, q_10+218, q_11+218);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+224, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 4
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f+209);
	memcpy(buffer+8, p_01+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g+209);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+657, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f+209);
	memcpy(buffer+8, p_11+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g+209);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+657, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+661, g_sum+661, p_00+232, p_01+232, p_10+232, p_11+232);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+657);
	memcpy(buffer+4, p_01+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+657);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+657);
	memcpy(buffer+4, p_11+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+657);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+681, g_sum+681, q_00+218, q_01+218, q_10+218, q_11+218);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+210, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+210, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+210, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+210, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 4
	GF2X_MUL(16, recombine, 8, p_00+224, 8, q_00+210);
	GF2X_MUL(16, temp, 8, p_10+224, 8, q_01+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+208, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, q_00+210);
	GF2X_MUL(16, temp, 8, p_11+224, 8, q_01+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+208, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+224, 8, q_10+210);
	GF2X_MUL(16, temp, 8, p_10+224, 8, q_11+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+208, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, q_10+210);
	GF2X_MUL(16, temp, 8, p_11+224, 8, q_11+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+208, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 3
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f+193);
	memcpy(buffer+16, p_01+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g+193);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+609, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f+193);
	memcpy(buffer+16, p_11+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g+193);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+609, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+621, g_sum+621, p_00+232, p_01+232, p_10+232, p_11+232);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+617);
	memcpy(buffer+4, p_01+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+617);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+617);
	memcpy(buffer+4, p_11+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+617);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+681, g_sum+681, q_00+218, q_01+218, q_10+218, q_11+218);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+224, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 4
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+609);
	memcpy(buffer+8, p_01+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+609);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+657, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+609);
	memcpy(buffer+8, p_11+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+609);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+657, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+661, g_sum+661, p_00+232, p_01+232, p_10+232, p_11+232);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+657);
	memcpy(buffer+4, p_01+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+657);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+657);
	memcpy(buffer+4, p_11+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+657);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+681, g_sum+681, q_00+218, q_01+218, q_10+218, q_11+218);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+210, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+210, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+210, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+210, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 4
	GF2X_MUL(16, recombine, 8, p_00+224, 8, q_00+210);
	GF2X_MUL(16, temp, 8, p_10+224, 8, q_01+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+194, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, q_00+210);
	GF2X_MUL(16, temp, 8, p_11+224, 8, q_01+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+194, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+224, 8, q_10+210);
	GF2X_MUL(16, temp, 8, p_10+224, 8, q_11+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+194, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, q_10+210);
	GF2X_MUL(16, temp, 8, p_11+224, 8, q_11+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+194, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 3
	GF2X_MUL(32, recombine, 16, p_00+208, 16, q_00+194);
	GF2X_MUL(32, temp, 16, p_10+208, 16, q_01+194);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_00+176, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+208, 16, q_00+194);
	GF2X_MUL(32, temp, 16, p_11+208, 16, q_01+194);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_01+176, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+208, 16, q_10+194);
	GF2X_MUL(32, temp, 16, p_10+208, 16, q_11+194);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_10+176, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+208, 16, q_10+194);
	GF2X_MUL(32, temp, 16, p_11+208, 16, q_11+194);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_11+176, recombine+0, 32*DIGIT_SIZE_B);
	
// Calculating left operands: n:3825, depth: 2
	memset(buffer, 0x00, 28*DIGIT_SIZE_B);
	memcpy(buffer+28, p_00+176, 32*DIGIT_SIZE_B);
	GF2X_MUL(120, temp2, 60, buffer, 60, f+165);
	memcpy(buffer+28, p_01+176, 32*DIGIT_SIZE_B);
	GF2X_MUL(120, temp, 60, buffer, 60, g+165);
	gf2x_add(120, temp, 120, temp2, 120, temp);
	memcpy(temp2, temp+28, 92*DIGIT_SIZE_B);
	right_bit_shift_wide_n(92, temp2, 2040);
	memcpy(f_sum+517, temp2+64, 60*DIGIT_SIZE_B);
	memset(buffer, 0x00, 28*DIGIT_SIZE_B);
	memcpy(buffer+28, p_10+176, 32*DIGIT_SIZE_B);
	GF2X_MUL(120, temp2, 60, buffer, 60, f+165);
	memcpy(buffer+28, p_11+176, 32*DIGIT_SIZE_B);
	GF2X_MUL(120, temp, 60, buffer, 60, g+165);
	gf2x_add(120, temp, 120, temp2, 120, temp);
	memcpy(temp2, temp+28, 92*DIGIT_SIZE_B);
	right_bit_shift_wide_n(92, temp2, 2040);
	memcpy(g_sum+517, temp2+64, 60*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+541, g_sum+541, p_00+232, p_01+232, p_10+232, p_11+232);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+537);
	memcpy(buffer+4, p_01+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+537);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+537);
	memcpy(buffer+4, p_11+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+537);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+681, g_sum+681, q_00+218, q_01+218, q_10+218, q_11+218);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+224, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 4
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+529);
	memcpy(buffer+8, p_01+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+529);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+657, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+529);
	memcpy(buffer+8, p_11+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+529);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+657, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+661, g_sum+661, p_00+232, p_01+232, p_10+232, p_11+232);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+657);
	memcpy(buffer+4, p_01+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+657);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+657);
	memcpy(buffer+4, p_11+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+657);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+681, g_sum+681, q_00+218, q_01+218, q_10+218, q_11+218);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+210, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+210, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+210, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+210, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 4
	GF2X_MUL(16, recombine, 8, p_00+224, 8, q_00+210);
	GF2X_MUL(16, temp, 8, p_10+224, 8, q_01+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+208, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, q_00+210);
	GF2X_MUL(16, temp, 8, p_11+224, 8, q_01+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+208, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+224, 8, q_10+210);
	GF2X_MUL(16, temp, 8, p_10+224, 8, q_11+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+208, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, q_10+210);
	GF2X_MUL(16, temp, 8, p_11+224, 8, q_11+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+208, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:1785, depth: 3
	memset(buffer, 0x00, 12*DIGIT_SIZE_B);
	memcpy(buffer+12, p_00+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(56, temp2, 28, buffer, 28, f_sum+517);
	memcpy(buffer+12, p_01+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, buffer, 28, g_sum+517);
	gf2x_add(56, temp, 56, temp2, 56, temp);
	memcpy(temp2, temp+12, 44*DIGIT_SIZE_B);
	right_bit_shift_wide_n(44, temp2, 1020);
	memcpy(f_sum+609, temp2+32, 28*DIGIT_SIZE_B);
	memset(buffer, 0x00, 12*DIGIT_SIZE_B);
	memcpy(buffer+12, p_10+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(56, temp2, 28, buffer, 28, f_sum+517);
	memcpy(buffer+12, p_11+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, buffer, 28, g_sum+517);
	gf2x_add(56, temp, 56, temp2, 56, temp);
	memcpy(temp2, temp+12, 44*DIGIT_SIZE_B);
	right_bit_shift_wide_n(44, temp2, 1020);
	memcpy(g_sum+609, temp2+32, 28*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+617, g_sum+617, p_00+232, p_01+232, p_10+232, p_11+232);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+613);
	memcpy(buffer+4, p_01+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+613);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+613);
	memcpy(buffer+4, p_11+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+613);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+681, g_sum+681, q_00+218, q_01+218, q_10+218, q_11+218);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+224, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:765, depth: 4
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp2, 12, buffer, 12, f_sum+609);
	memcpy(buffer+4, p_01+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, buffer, 12, g_sum+609);
	gf2x_add(24, temp, 24, temp2, 24, temp);
	memcpy(temp2, temp+4, 20*DIGIT_SIZE_B);
	right_bit_shift_wide_n(20, temp2, 510);
	memcpy(f_sum+657, temp2+16, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp2, 12, buffer, 12, f_sum+609);
	memcpy(buffer+4, p_11+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, buffer, 12, g_sum+609);
	gf2x_add(24, temp, 24, temp2, 24, temp);
	memcpy(temp2, temp+4, 20*DIGIT_SIZE_B);
	right_bit_shift_wide_n(20, temp2, 510);
	memcpy(g_sum+657, temp2+16, 12*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+657, g_sum+657, q_00+210, q_01+210, q_10+210, q_11+210);
	
// Recombining results: n:765, depth: 4
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+224, 8, buffer);
	memcpy(buffer+4, q_01+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_10+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(q_00+194, recombine+0, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, buffer);
	memcpy(buffer+4, q_01+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_11+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(q_01+194, recombine+0, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+224, 8, buffer);
	memcpy(buffer+4, q_11+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_10+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(q_10+194, recombine+0, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, buffer);
	memcpy(buffer+4, q_11+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_11+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(q_11+194, recombine+0, 12*DIGIT_SIZE_B);
	
// Recombining results: n:1785, depth: 3
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+208, 16, buffer);
	memcpy(buffer+4, q_01+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_10+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+4, 28*DIGIT_SIZE_B);
	memcpy(q_00+166, recombine+0, 28*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+208, 16, buffer);
	memcpy(buffer+4, q_01+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_11+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+4, 28*DIGIT_SIZE_B);
	memcpy(q_01+166, recombine+0, 28*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+208, 16, buffer);
	memcpy(buffer+4, q_11+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_10+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+4, 28*DIGIT_SIZE_B);
	memcpy(q_10+166, recombine+0, 28*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+208, 16, buffer);
	memcpy(buffer+4, q_11+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_11+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+4, 28*DIGIT_SIZE_B);
	memcpy(q_11+166, recombine+0, 28*DIGIT_SIZE_B);
	
// Recombining results: n:3825, depth: 2
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+166, 28*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_00+176, 32, buffer);
	memcpy(buffer+4, q_01+166, 28*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_10+176, 32, buffer);
	gf2x_add(64, temp, 64, recombine, 64, temp);
	memcpy(recombine, temp+4, 60*DIGIT_SIZE_B);
	memcpy(p_00+116, recombine+0, 60*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+166, 28*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+176, 32, buffer);
	memcpy(buffer+4, q_01+166, 28*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_11+176, 32, buffer);
	gf2x_add(64, temp, 64, recombine, 64, temp);
	memcpy(recombine, temp+4, 60*DIGIT_SIZE_B);
	memcpy(p_01+116, recombine+0, 60*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+166, 28*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_00+176, 32, buffer);
	memcpy(buffer+4, q_11+166, 28*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_10+176, 32, buffer);
	gf2x_add(64, temp, 64, recombine, 64, temp);
	memcpy(recombine, temp+4, 60*DIGIT_SIZE_B);
	memcpy(p_10+116, recombine+0, 60*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+166, 28*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+176, 32, buffer);
	memcpy(buffer+4, q_11+166, 28*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_11+176, 32, buffer);
	gf2x_add(64, temp, 64, recombine, 64, temp);
	memcpy(recombine, temp+4, 60*DIGIT_SIZE_B);
	memcpy(p_11+116, recombine+0, 60*DIGIT_SIZE_B);
	
// Calculating left operands: n:7395, depth: 1
	memset(buffer, 0x00, 56*DIGIT_SIZE_B);
	memcpy(buffer+56, p_00+116, 60*DIGIT_SIZE_B);
	GF2X_MUL(232, temp2, 116, buffer, 116, f+109);
	memcpy(buffer+56, p_01+116, 60*DIGIT_SIZE_B);
	GF2X_MUL(232, temp, 116, buffer, 116, g+109);
	gf2x_add(232, temp, 232, temp2, 232, temp);
	memcpy(temp2, temp+56, 176*DIGIT_SIZE_B);
	right_bit_shift_wide_n(176, temp2, 3825);
	memcpy(f_sum+341, temp2+120, 116*DIGIT_SIZE_B);
	memset(buffer, 0x00, 56*DIGIT_SIZE_B);
	memcpy(buffer+56, p_10+116, 60*DIGIT_SIZE_B);
	GF2X_MUL(232, temp2, 116, buffer, 116, f+109);
	memcpy(buffer+56, p_11+116, 60*DIGIT_SIZE_B);
	GF2X_MUL(232, temp, 116, buffer, 116, g+109);
	gf2x_add(232, temp, 232, temp2, 232, temp);
	memcpy(temp2, temp+56, 176*DIGIT_SIZE_B);
	right_bit_shift_wide_n(176, temp2, 3825);
	memcpy(g_sum+341, temp2+120, 116*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+393, g_sum+393, p_00+232, p_01+232, p_10+232, p_11+232);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+389);
	memcpy(buffer+4, p_01+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+389);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+389);
	memcpy(buffer+4, p_11+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+389);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+681, g_sum+681, q_00+218, q_01+218, q_10+218, q_11+218);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+224, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 4
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+381);
	memcpy(buffer+8, p_01+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+381);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+657, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+381);
	memcpy(buffer+8, p_11+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+381);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+657, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+661, g_sum+661, p_00+232, p_01+232, p_10+232, p_11+232);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+657);
	memcpy(buffer+4, p_01+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+657);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+657);
	memcpy(buffer+4, p_11+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+657);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+681, g_sum+681, q_00+218, q_01+218, q_10+218, q_11+218);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+210, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+210, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+210, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+210, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 4
	GF2X_MUL(16, recombine, 8, p_00+224, 8, q_00+210);
	GF2X_MUL(16, temp, 8, p_10+224, 8, q_01+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+208, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, q_00+210);
	GF2X_MUL(16, temp, 8, p_11+224, 8, q_01+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+208, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+224, 8, q_10+210);
	GF2X_MUL(16, temp, 8, p_10+224, 8, q_11+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+208, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, q_10+210);
	GF2X_MUL(16, temp, 8, p_11+224, 8, q_11+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+208, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:1785, depth: 3
	memset(buffer, 0x00, 12*DIGIT_SIZE_B);
	memcpy(buffer+12, p_00+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(56, temp2, 28, buffer, 28, f_sum+369);
	memcpy(buffer+12, p_01+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, buffer, 28, g_sum+369);
	gf2x_add(56, temp, 56, temp2, 56, temp);
	memcpy(temp2, temp+12, 44*DIGIT_SIZE_B);
	right_bit_shift_wide_n(44, temp2, 1020);
	memcpy(f_sum+609, temp2+32, 28*DIGIT_SIZE_B);
	memset(buffer, 0x00, 12*DIGIT_SIZE_B);
	memcpy(buffer+12, p_10+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(56, temp2, 28, buffer, 28, f_sum+369);
	memcpy(buffer+12, p_11+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, buffer, 28, g_sum+369);
	gf2x_add(56, temp, 56, temp2, 56, temp);
	memcpy(temp2, temp+12, 44*DIGIT_SIZE_B);
	right_bit_shift_wide_n(44, temp2, 1020);
	memcpy(g_sum+609, temp2+32, 28*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+617, g_sum+617, p_00+232, p_01+232, p_10+232, p_11+232);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+613);
	memcpy(buffer+4, p_01+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+613);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+613);
	memcpy(buffer+4, p_11+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+613);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+681, g_sum+681, q_00+218, q_01+218, q_10+218, q_11+218);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+224, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:765, depth: 4
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp2, 12, buffer, 12, f_sum+609);
	memcpy(buffer+4, p_01+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, buffer, 12, g_sum+609);
	gf2x_add(24, temp, 24, temp2, 24, temp);
	memcpy(temp2, temp+4, 20*DIGIT_SIZE_B);
	right_bit_shift_wide_n(20, temp2, 510);
	memcpy(f_sum+657, temp2+16, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp2, 12, buffer, 12, f_sum+609);
	memcpy(buffer+4, p_11+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, buffer, 12, g_sum+609);
	gf2x_add(24, temp, 24, temp2, 24, temp);
	memcpy(temp2, temp+4, 20*DIGIT_SIZE_B);
	right_bit_shift_wide_n(20, temp2, 510);
	memcpy(g_sum+657, temp2+16, 12*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+657, g_sum+657, q_00+210, q_01+210, q_10+210, q_11+210);
	
// Recombining results: n:765, depth: 4
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+224, 8, buffer);
	memcpy(buffer+4, q_01+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_10+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(q_00+194, recombine+0, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, buffer);
	memcpy(buffer+4, q_01+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_11+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(q_01+194, recombine+0, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+224, 8, buffer);
	memcpy(buffer+4, q_11+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_10+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(q_10+194, recombine+0, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, buffer);
	memcpy(buffer+4, q_11+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_11+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(q_11+194, recombine+0, 12*DIGIT_SIZE_B);
	
// Recombining results: n:1785, depth: 3
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+208, 16, buffer);
	memcpy(buffer+4, q_01+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_10+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+4, 28*DIGIT_SIZE_B);
	memcpy(p_00+176, recombine+0, 28*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+208, 16, buffer);
	memcpy(buffer+4, q_01+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_11+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+4, 28*DIGIT_SIZE_B);
	memcpy(p_01+176, recombine+0, 28*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+208, 16, buffer);
	memcpy(buffer+4, q_11+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_10+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+4, 28*DIGIT_SIZE_B);
	memcpy(p_10+176, recombine+0, 28*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+208, 16, buffer);
	memcpy(buffer+4, q_11+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_11+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+4, 28*DIGIT_SIZE_B);
	memcpy(p_11+176, recombine+0, 28*DIGIT_SIZE_B);
	
// Calculating left operands: n:3570, depth: 2
	memset(buffer, 0x00, 28*DIGIT_SIZE_B);
	memcpy(buffer+28, p_00+176, 28*DIGIT_SIZE_B);
	GF2X_MUL(112, temp2, 56, buffer, 56, f_sum+341);
	memcpy(buffer+28, p_01+176, 28*DIGIT_SIZE_B);
	GF2X_MUL(112, temp, 56, buffer, 56, g_sum+341);
	gf2x_add(112, temp, 112, temp2, 112, temp);
	memcpy(temp2, temp+28, 84*DIGIT_SIZE_B);
	right_bit_shift_wide_n(84, temp2, 1785);
	memcpy(f_sum+517, temp2+56, 56*DIGIT_SIZE_B);
	memset(buffer, 0x00, 28*DIGIT_SIZE_B);
	memcpy(buffer+28, p_10+176, 28*DIGIT_SIZE_B);
	GF2X_MUL(112, temp2, 56, buffer, 56, f_sum+341);
	memcpy(buffer+28, p_11+176, 28*DIGIT_SIZE_B);
	GF2X_MUL(112, temp, 56, buffer, 56, g_sum+341);
	gf2x_add(112, temp, 112, temp2, 112, temp);
	memcpy(temp2, temp+28, 84*DIGIT_SIZE_B);
	right_bit_shift_wide_n(84, temp2, 1785);
	memcpy(g_sum+517, temp2+56, 56*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+541, g_sum+541, p_00+232, p_01+232, p_10+232, p_11+232);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+537);
	memcpy(buffer+4, p_01+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+537);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+537);
	memcpy(buffer+4, p_11+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+537);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+681, g_sum+681, q_00+218, q_01+218, q_10+218, q_11+218);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+224, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 4
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+529);
	memcpy(buffer+8, p_01+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+529);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+657, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+529);
	memcpy(buffer+8, p_11+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+529);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+657, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+661, g_sum+661, p_00+232, p_01+232, p_10+232, p_11+232);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+657);
	memcpy(buffer+4, p_01+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+657);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+657);
	memcpy(buffer+4, p_11+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+657);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+681, g_sum+681, q_00+218, q_01+218, q_10+218, q_11+218);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+210, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+210, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+210, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+210, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 4
	GF2X_MUL(16, recombine, 8, p_00+224, 8, q_00+210);
	GF2X_MUL(16, temp, 8, p_10+224, 8, q_01+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+208, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, q_00+210);
	GF2X_MUL(16, temp, 8, p_11+224, 8, q_01+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+208, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+224, 8, q_10+210);
	GF2X_MUL(16, temp, 8, p_10+224, 8, q_11+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+208, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, q_10+210);
	GF2X_MUL(16, temp, 8, p_11+224, 8, q_11+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+208, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:1785, depth: 3
	memset(buffer, 0x00, 12*DIGIT_SIZE_B);
	memcpy(buffer+12, p_00+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(56, temp2, 28, buffer, 28, f_sum+517);
	memcpy(buffer+12, p_01+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, buffer, 28, g_sum+517);
	gf2x_add(56, temp, 56, temp2, 56, temp);
	memcpy(temp2, temp+12, 44*DIGIT_SIZE_B);
	right_bit_shift_wide_n(44, temp2, 1020);
	memcpy(f_sum+609, temp2+32, 28*DIGIT_SIZE_B);
	memset(buffer, 0x00, 12*DIGIT_SIZE_B);
	memcpy(buffer+12, p_10+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(56, temp2, 28, buffer, 28, f_sum+517);
	memcpy(buffer+12, p_11+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, buffer, 28, g_sum+517);
	gf2x_add(56, temp, 56, temp2, 56, temp);
	memcpy(temp2, temp+12, 44*DIGIT_SIZE_B);
	right_bit_shift_wide_n(44, temp2, 1020);
	memcpy(g_sum+609, temp2+32, 28*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+617, g_sum+617, p_00+232, p_01+232, p_10+232, p_11+232);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+613);
	memcpy(buffer+4, p_01+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+613);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+613);
	memcpy(buffer+4, p_11+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+613);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+681, g_sum+681, q_00+218, q_01+218, q_10+218, q_11+218);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+224, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:765, depth: 4
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp2, 12, buffer, 12, f_sum+609);
	memcpy(buffer+4, p_01+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, buffer, 12, g_sum+609);
	gf2x_add(24, temp, 24, temp2, 24, temp);
	memcpy(temp2, temp+4, 20*DIGIT_SIZE_B);
	right_bit_shift_wide_n(20, temp2, 510);
	memcpy(f_sum+657, temp2+16, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp2, 12, buffer, 12, f_sum+609);
	memcpy(buffer+4, p_11+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, buffer, 12, g_sum+609);
	gf2x_add(24, temp, 24, temp2, 24, temp);
	memcpy(temp2, temp+4, 20*DIGIT_SIZE_B);
	right_bit_shift_wide_n(20, temp2, 510);
	memcpy(g_sum+657, temp2+16, 12*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+657, g_sum+657, q_00+210, q_01+210, q_10+210, q_11+210);
	
// Recombining results: n:765, depth: 4
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+224, 8, buffer);
	memcpy(buffer+4, q_01+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_10+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(q_00+194, recombine+0, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, buffer);
	memcpy(buffer+4, q_01+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_11+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(q_01+194, recombine+0, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+224, 8, buffer);
	memcpy(buffer+4, q_11+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_10+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(q_10+194, recombine+0, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, buffer);
	memcpy(buffer+4, q_11+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_11+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(q_11+194, recombine+0, 12*DIGIT_SIZE_B);
	
// Recombining results: n:1785, depth: 3
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+208, 16, buffer);
	memcpy(buffer+4, q_01+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_10+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+4, 28*DIGIT_SIZE_B);
	memcpy(q_00+166, recombine+0, 28*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+208, 16, buffer);
	memcpy(buffer+4, q_01+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_11+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+4, 28*DIGIT_SIZE_B);
	memcpy(q_01+166, recombine+0, 28*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+208, 16, buffer);
	memcpy(buffer+4, q_11+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_10+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+4, 28*DIGIT_SIZE_B);
	memcpy(q_10+166, recombine+0, 28*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+208, 16, buffer);
	memcpy(buffer+4, q_11+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_11+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+4, 28*DIGIT_SIZE_B);
	memcpy(q_11+166, recombine+0, 28*DIGIT_SIZE_B);
	
// Recombining results: n:3570, depth: 2
	GF2X_MUL(56, recombine, 28, p_00+176, 28, q_00+166);
	GF2X_MUL(56, temp, 28, p_10+176, 28, q_01+166);
	gf2x_add(56, recombine, 56, temp, 56, recombine);
	memcpy(q_00+110, recombine+0, 56*DIGIT_SIZE_B);
	GF2X_MUL(56, recombine, 28, p_01+176, 28, q_00+166);
	GF2X_MUL(56, temp, 28, p_11+176, 28, q_01+166);
	gf2x_add(56, recombine, 56, temp, 56, recombine);
	memcpy(q_01+110, recombine+0, 56*DIGIT_SIZE_B);
	GF2X_MUL(56, recombine, 28, p_00+176, 28, q_10+166);
	GF2X_MUL(56, temp, 28, p_10+176, 28, q_11+166);
	gf2x_add(56, recombine, 56, temp, 56, recombine);
	memcpy(q_10+110, recombine+0, 56*DIGIT_SIZE_B);
	GF2X_MUL(56, recombine, 28, p_01+176, 28, q_10+166);
	GF2X_MUL(56, temp, 28, p_11+176, 28, q_11+166);
	gf2x_add(56, recombine, 56, temp, 56, recombine);
	memcpy(q_11+110, recombine+0, 56*DIGIT_SIZE_B);
	
// Recombining results: n:7395, depth: 1
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+110, 56*DIGIT_SIZE_B);
	GF2X_MUL(120, recombine, 60, p_00+116, 60, buffer);
	memcpy(buffer+4, q_01+110, 56*DIGIT_SIZE_B);
	GF2X_MUL(120, temp, 60, p_10+116, 60, buffer);
	gf2x_add(120, temp, 120, recombine, 120, temp);
	memcpy(recombine, temp+4, 116*DIGIT_SIZE_B);
	memcpy(p_00+0, recombine+0, 116*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+110, 56*DIGIT_SIZE_B);
	GF2X_MUL(120, recombine, 60, p_01+116, 60, buffer);
	memcpy(buffer+4, q_01+110, 56*DIGIT_SIZE_B);
	GF2X_MUL(120, temp, 60, p_11+116, 60, buffer);
	gf2x_add(120, temp, 120, recombine, 120, temp);
	memcpy(recombine, temp+4, 116*DIGIT_SIZE_B);
	memcpy(p_01+0, recombine+0, 116*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+110, 56*DIGIT_SIZE_B);
	GF2X_MUL(120, recombine, 60, p_00+116, 60, buffer);
	memcpy(buffer+4, q_11+110, 56*DIGIT_SIZE_B);
	GF2X_MUL(120, temp, 60, p_10+116, 60, buffer);
	gf2x_add(120, temp, 120, recombine, 120, temp);
	memcpy(recombine, temp+4, 116*DIGIT_SIZE_B);
	memcpy(p_10+0, recombine+0, 116*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+110, 56*DIGIT_SIZE_B);
	GF2X_MUL(120, recombine, 60, p_01+116, 60, buffer);
	memcpy(buffer+4, q_11+110, 56*DIGIT_SIZE_B);
	GF2X_MUL(120, temp, 60, p_11+116, 60, buffer);
	gf2x_add(120, temp, 120, recombine, 120, temp);
	memcpy(recombine, temp+4, 116*DIGIT_SIZE_B);
	memcpy(p_11+0, recombine+0, 116*DIGIT_SIZE_B);
	
// Calculating left operands: n:14373, depth: 0
	memset(buffer, 0x00, 109*DIGIT_SIZE_B);
	memcpy(buffer+109, p_00+0, 116*DIGIT_SIZE_B);
	GF2X_MUL(450, temp2, 225, buffer, 225, f+0);
	memcpy(buffer+109, p_01+0, 116*DIGIT_SIZE_B);
	GF2X_MUL(450, temp, 225, buffer, 225, g+0);
	gf2x_add(450, temp, 450, temp2, 450, temp);
	memcpy(temp2, temp+109, 341*DIGIT_SIZE_B);
	right_bit_shift_wide_n(341, temp2, 7395);
	memcpy(f_sum+0, temp2+231, 225*DIGIT_SIZE_B);
	memset(buffer, 0x00, 109*DIGIT_SIZE_B);
	memcpy(buffer+109, p_10+0, 116*DIGIT_SIZE_B);
	GF2X_MUL(450, temp2, 225, buffer, 225, f+0);
	memcpy(buffer+109, p_11+0, 116*DIGIT_SIZE_B);
	GF2X_MUL(450, temp, 225, buffer, 225, g+0);
	gf2x_add(450, temp, 450, temp2, 450, temp);
	memcpy(temp2, temp+109, 341*DIGIT_SIZE_B);
	right_bit_shift_wide_n(341, temp2, 7395);
	memcpy(g_sum+0, temp2+231, 225*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+106, g_sum+106, p_00+232, p_01+232, p_10+232, p_11+232);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+102);
	memcpy(buffer+4, p_01+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+102);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+102);
	memcpy(buffer+4, p_11+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+102);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+681, g_sum+681, q_00+218, q_01+218, q_10+218, q_11+218);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+224, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 4
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+94);
	memcpy(buffer+8, p_01+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+94);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+657, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+94);
	memcpy(buffer+8, p_11+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+94);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+657, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+661, g_sum+661, p_00+232, p_01+232, p_10+232, p_11+232);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+657);
	memcpy(buffer+4, p_01+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+657);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+657);
	memcpy(buffer+4, p_11+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+657);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+681, g_sum+681, q_00+218, q_01+218, q_10+218, q_11+218);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+210, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+210, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+210, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+210, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 4
	GF2X_MUL(16, recombine, 8, p_00+224, 8, q_00+210);
	GF2X_MUL(16, temp, 8, p_10+224, 8, q_01+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+208, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, q_00+210);
	GF2X_MUL(16, temp, 8, p_11+224, 8, q_01+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+208, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+224, 8, q_10+210);
	GF2X_MUL(16, temp, 8, p_10+224, 8, q_11+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+208, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, q_10+210);
	GF2X_MUL(16, temp, 8, p_11+224, 8, q_11+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+208, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:1785, depth: 3
	memset(buffer, 0x00, 12*DIGIT_SIZE_B);
	memcpy(buffer+12, p_00+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(56, temp2, 28, buffer, 28, f_sum+82);
	memcpy(buffer+12, p_01+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, buffer, 28, g_sum+82);
	gf2x_add(56, temp, 56, temp2, 56, temp);
	memcpy(temp2, temp+12, 44*DIGIT_SIZE_B);
	right_bit_shift_wide_n(44, temp2, 1020);
	memcpy(f_sum+609, temp2+32, 28*DIGIT_SIZE_B);
	memset(buffer, 0x00, 12*DIGIT_SIZE_B);
	memcpy(buffer+12, p_10+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(56, temp2, 28, buffer, 28, f_sum+82);
	memcpy(buffer+12, p_11+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, buffer, 28, g_sum+82);
	gf2x_add(56, temp, 56, temp2, 56, temp);
	memcpy(temp2, temp+12, 44*DIGIT_SIZE_B);
	right_bit_shift_wide_n(44, temp2, 1020);
	memcpy(g_sum+609, temp2+32, 28*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+617, g_sum+617, p_00+232, p_01+232, p_10+232, p_11+232);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+613);
	memcpy(buffer+4, p_01+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+613);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+613);
	memcpy(buffer+4, p_11+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+613);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+681, g_sum+681, q_00+218, q_01+218, q_10+218, q_11+218);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+224, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:765, depth: 4
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp2, 12, buffer, 12, f_sum+609);
	memcpy(buffer+4, p_01+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, buffer, 12, g_sum+609);
	gf2x_add(24, temp, 24, temp2, 24, temp);
	memcpy(temp2, temp+4, 20*DIGIT_SIZE_B);
	right_bit_shift_wide_n(20, temp2, 510);
	memcpy(f_sum+657, temp2+16, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp2, 12, buffer, 12, f_sum+609);
	memcpy(buffer+4, p_11+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, buffer, 12, g_sum+609);
	gf2x_add(24, temp, 24, temp2, 24, temp);
	memcpy(temp2, temp+4, 20*DIGIT_SIZE_B);
	right_bit_shift_wide_n(20, temp2, 510);
	memcpy(g_sum+657, temp2+16, 12*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+657, g_sum+657, q_00+210, q_01+210, q_10+210, q_11+210);
	
// Recombining results: n:765, depth: 4
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+224, 8, buffer);
	memcpy(buffer+4, q_01+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_10+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(q_00+194, recombine+0, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, buffer);
	memcpy(buffer+4, q_01+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_11+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(q_01+194, recombine+0, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+224, 8, buffer);
	memcpy(buffer+4, q_11+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_10+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(q_10+194, recombine+0, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, buffer);
	memcpy(buffer+4, q_11+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_11+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(q_11+194, recombine+0, 12*DIGIT_SIZE_B);
	
// Recombining results: n:1785, depth: 3
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+208, 16, buffer);
	memcpy(buffer+4, q_01+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_10+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+4, 28*DIGIT_SIZE_B);
	memcpy(p_00+176, recombine+0, 28*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+208, 16, buffer);
	memcpy(buffer+4, q_01+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_11+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+4, 28*DIGIT_SIZE_B);
	memcpy(p_01+176, recombine+0, 28*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+208, 16, buffer);
	memcpy(buffer+4, q_11+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_10+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+4, 28*DIGIT_SIZE_B);
	memcpy(p_10+176, recombine+0, 28*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+208, 16, buffer);
	memcpy(buffer+4, q_11+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_11+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+4, 28*DIGIT_SIZE_B);
	memcpy(p_11+176, recombine+0, 28*DIGIT_SIZE_B);
	
// Calculating left operands: n:3570, depth: 2
	memset(buffer, 0x00, 28*DIGIT_SIZE_B);
	memcpy(buffer+28, p_00+176, 28*DIGIT_SIZE_B);
	GF2X_MUL(112, temp2, 56, buffer, 56, f_sum+54);
	memcpy(buffer+28, p_01+176, 28*DIGIT_SIZE_B);
	GF2X_MUL(112, temp, 56, buffer, 56, g_sum+54);
	gf2x_add(112, temp, 112, temp2, 112, temp);
	memcpy(temp2, temp+28, 84*DIGIT_SIZE_B);
	right_bit_shift_wide_n(84, temp2, 1785);
	memcpy(f_sum+517, temp2+56, 56*DIGIT_SIZE_B);
	memset(buffer, 0x00, 28*DIGIT_SIZE_B);
	memcpy(buffer+28, p_10+176, 28*DIGIT_SIZE_B);
	GF2X_MUL(112, temp2, 56, buffer, 56, f_sum+54);
	memcpy(buffer+28, p_11+176, 28*DIGIT_SIZE_B);
	GF2X_MUL(112, temp, 56, buffer, 56, g_sum+54);
	gf2x_add(112, temp, 112, temp2, 112, temp);
	memcpy(temp2, temp+28, 84*DIGIT_SIZE_B);
	right_bit_shift_wide_n(84, temp2, 1785);
	memcpy(g_sum+517, temp2+56, 56*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+541, g_sum+541, p_00+232, p_01+232, p_10+232, p_11+232);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+537);
	memcpy(buffer+4, p_01+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+537);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+537);
	memcpy(buffer+4, p_11+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+537);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+681, g_sum+681, q_00+218, q_01+218, q_10+218, q_11+218);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+224, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 4
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+529);
	memcpy(buffer+8, p_01+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+529);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+657, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+529);
	memcpy(buffer+8, p_11+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+529);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+657, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+661, g_sum+661, p_00+232, p_01+232, p_10+232, p_11+232);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+657);
	memcpy(buffer+4, p_01+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+657);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+657);
	memcpy(buffer+4, p_11+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+657);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+681, g_sum+681, q_00+218, q_01+218, q_10+218, q_11+218);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+210, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+210, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+210, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+210, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 4
	GF2X_MUL(16, recombine, 8, p_00+224, 8, q_00+210);
	GF2X_MUL(16, temp, 8, p_10+224, 8, q_01+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+208, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, q_00+210);
	GF2X_MUL(16, temp, 8, p_11+224, 8, q_01+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+208, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+224, 8, q_10+210);
	GF2X_MUL(16, temp, 8, p_10+224, 8, q_11+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+208, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, q_10+210);
	GF2X_MUL(16, temp, 8, p_11+224, 8, q_11+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+208, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:1785, depth: 3
	memset(buffer, 0x00, 12*DIGIT_SIZE_B);
	memcpy(buffer+12, p_00+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(56, temp2, 28, buffer, 28, f_sum+517);
	memcpy(buffer+12, p_01+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, buffer, 28, g_sum+517);
	gf2x_add(56, temp, 56, temp2, 56, temp);
	memcpy(temp2, temp+12, 44*DIGIT_SIZE_B);
	right_bit_shift_wide_n(44, temp2, 1020);
	memcpy(f_sum+609, temp2+32, 28*DIGIT_SIZE_B);
	memset(buffer, 0x00, 12*DIGIT_SIZE_B);
	memcpy(buffer+12, p_10+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(56, temp2, 28, buffer, 28, f_sum+517);
	memcpy(buffer+12, p_11+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, buffer, 28, g_sum+517);
	gf2x_add(56, temp, 56, temp2, 56, temp);
	memcpy(temp2, temp+12, 44*DIGIT_SIZE_B);
	right_bit_shift_wide_n(44, temp2, 1020);
	memcpy(g_sum+609, temp2+32, 28*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+617, g_sum+617, p_00+232, p_01+232, p_10+232, p_11+232);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+613);
	memcpy(buffer+4, p_01+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+613);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+613);
	memcpy(buffer+4, p_11+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+613);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+681, g_sum+681, q_00+218, q_01+218, q_10+218, q_11+218);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+224, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:765, depth: 4
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp2, 12, buffer, 12, f_sum+609);
	memcpy(buffer+4, p_01+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, buffer, 12, g_sum+609);
	gf2x_add(24, temp, 24, temp2, 24, temp);
	memcpy(temp2, temp+4, 20*DIGIT_SIZE_B);
	right_bit_shift_wide_n(20, temp2, 510);
	memcpy(f_sum+657, temp2+16, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp2, 12, buffer, 12, f_sum+609);
	memcpy(buffer+4, p_11+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, buffer, 12, g_sum+609);
	gf2x_add(24, temp, 24, temp2, 24, temp);
	memcpy(temp2, temp+4, 20*DIGIT_SIZE_B);
	right_bit_shift_wide_n(20, temp2, 510);
	memcpy(g_sum+657, temp2+16, 12*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+657, g_sum+657, q_00+210, q_01+210, q_10+210, q_11+210);
	
// Recombining results: n:765, depth: 4
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+224, 8, buffer);
	memcpy(buffer+4, q_01+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_10+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(q_00+194, recombine+0, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, buffer);
	memcpy(buffer+4, q_01+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_11+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(q_01+194, recombine+0, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+224, 8, buffer);
	memcpy(buffer+4, q_11+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_10+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(q_10+194, recombine+0, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, buffer);
	memcpy(buffer+4, q_11+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_11+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(q_11+194, recombine+0, 12*DIGIT_SIZE_B);
	
// Recombining results: n:1785, depth: 3
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+208, 16, buffer);
	memcpy(buffer+4, q_01+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_10+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+4, 28*DIGIT_SIZE_B);
	memcpy(q_00+166, recombine+0, 28*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+208, 16, buffer);
	memcpy(buffer+4, q_01+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_11+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+4, 28*DIGIT_SIZE_B);
	memcpy(q_01+166, recombine+0, 28*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+208, 16, buffer);
	memcpy(buffer+4, q_11+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_10+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+4, 28*DIGIT_SIZE_B);
	memcpy(q_10+166, recombine+0, 28*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+208, 16, buffer);
	memcpy(buffer+4, q_11+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_11+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+4, 28*DIGIT_SIZE_B);
	memcpy(q_11+166, recombine+0, 28*DIGIT_SIZE_B);
	
// Recombining results: n:3570, depth: 2
	GF2X_MUL(56, recombine, 28, p_00+176, 28, q_00+166);
	GF2X_MUL(56, temp, 28, p_10+176, 28, q_01+166);
	gf2x_add(56, recombine, 56, temp, 56, recombine);
	memcpy(p_00+116, recombine+0, 56*DIGIT_SIZE_B);
	GF2X_MUL(56, recombine, 28, p_01+176, 28, q_00+166);
	GF2X_MUL(56, temp, 28, p_11+176, 28, q_01+166);
	gf2x_add(56, recombine, 56, temp, 56, recombine);
	memcpy(p_01+116, recombine+0, 56*DIGIT_SIZE_B);
	GF2X_MUL(56, recombine, 28, p_00+176, 28, q_10+166);
	GF2X_MUL(56, temp, 28, p_10+176, 28, q_11+166);
	gf2x_add(56, recombine, 56, temp, 56, recombine);
	memcpy(p_10+116, recombine+0, 56*DIGIT_SIZE_B);
	GF2X_MUL(56, recombine, 28, p_01+176, 28, q_10+166);
	GF2X_MUL(56, temp, 28, p_11+176, 28, q_11+166);
	gf2x_add(56, recombine, 56, temp, 56, recombine);
	memcpy(p_11+116, recombine+0, 56*DIGIT_SIZE_B);
	
// Calculating left operands: n:6978, depth: 1
	memset(buffer, 0x00, 54*DIGIT_SIZE_B);
	memcpy(buffer+54, p_00+116, 56*DIGIT_SIZE_B);
	GF2X_MUL(220, temp2, 110, buffer, 110, f_sum+0);
	memcpy(buffer+54, p_01+116, 56*DIGIT_SIZE_B);
	GF2X_MUL(220, temp, 110, buffer, 110, g_sum+0);
	gf2x_add(220, temp, 220, temp2, 220, temp);
	memcpy(temp2, temp+54, 166*DIGIT_SIZE_B);
	right_bit_shift_wide_n(166, temp2, 3570);
	memcpy(f_sum+341, temp2+112, 110*DIGIT_SIZE_B);
	memset(buffer, 0x00, 54*DIGIT_SIZE_B);
	memcpy(buffer+54, p_10+116, 56*DIGIT_SIZE_B);
	GF2X_MUL(220, temp2, 110, buffer, 110, f_sum+0);
	memcpy(buffer+54, p_11+116, 56*DIGIT_SIZE_B);
	GF2X_MUL(220, temp, 110, buffer, 110, g_sum+0);
	gf2x_add(220, temp, 220, temp2, 220, temp);
	memcpy(temp2, temp+54, 166*DIGIT_SIZE_B);
	right_bit_shift_wide_n(166, temp2, 3570);
	memcpy(g_sum+341, temp2+112, 110*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+391, g_sum+391, p_00+232, p_01+232, p_10+232, p_11+232);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+387);
	memcpy(buffer+4, p_01+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+387);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+387);
	memcpy(buffer+4, p_11+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+387);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+681, g_sum+681, q_00+218, q_01+218, q_10+218, q_11+218);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+224, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 4
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+379);
	memcpy(buffer+8, p_01+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+379);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+657, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+379);
	memcpy(buffer+8, p_11+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+379);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+657, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+661, g_sum+661, p_00+232, p_01+232, p_10+232, p_11+232);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+657);
	memcpy(buffer+4, p_01+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+657);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+657);
	memcpy(buffer+4, p_11+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+657);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+681, g_sum+681, q_00+218, q_01+218, q_10+218, q_11+218);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+210, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+210, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+210, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+210, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 4
	GF2X_MUL(16, recombine, 8, p_00+224, 8, q_00+210);
	GF2X_MUL(16, temp, 8, p_10+224, 8, q_01+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+208, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, q_00+210);
	GF2X_MUL(16, temp, 8, p_11+224, 8, q_01+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+208, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+224, 8, q_10+210);
	GF2X_MUL(16, temp, 8, p_10+224, 8, q_11+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+208, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, q_10+210);
	GF2X_MUL(16, temp, 8, p_11+224, 8, q_11+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+208, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:1785, depth: 3
	memset(buffer, 0x00, 12*DIGIT_SIZE_B);
	memcpy(buffer+12, p_00+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(56, temp2, 28, buffer, 28, f_sum+367);
	memcpy(buffer+12, p_01+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, buffer, 28, g_sum+367);
	gf2x_add(56, temp, 56, temp2, 56, temp);
	memcpy(temp2, temp+12, 44*DIGIT_SIZE_B);
	right_bit_shift_wide_n(44, temp2, 1020);
	memcpy(f_sum+609, temp2+32, 28*DIGIT_SIZE_B);
	memset(buffer, 0x00, 12*DIGIT_SIZE_B);
	memcpy(buffer+12, p_10+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(56, temp2, 28, buffer, 28, f_sum+367);
	memcpy(buffer+12, p_11+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, buffer, 28, g_sum+367);
	gf2x_add(56, temp, 56, temp2, 56, temp);
	memcpy(temp2, temp+12, 44*DIGIT_SIZE_B);
	right_bit_shift_wide_n(44, temp2, 1020);
	memcpy(g_sum+609, temp2+32, 28*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+617, g_sum+617, p_00+232, p_01+232, p_10+232, p_11+232);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+613);
	memcpy(buffer+4, p_01+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+613);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+613);
	memcpy(buffer+4, p_11+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+613);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+681, g_sum+681, q_00+218, q_01+218, q_10+218, q_11+218);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+224, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:765, depth: 4
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp2, 12, buffer, 12, f_sum+609);
	memcpy(buffer+4, p_01+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, buffer, 12, g_sum+609);
	gf2x_add(24, temp, 24, temp2, 24, temp);
	memcpy(temp2, temp+4, 20*DIGIT_SIZE_B);
	right_bit_shift_wide_n(20, temp2, 510);
	memcpy(f_sum+657, temp2+16, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp2, 12, buffer, 12, f_sum+609);
	memcpy(buffer+4, p_11+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, buffer, 12, g_sum+609);
	gf2x_add(24, temp, 24, temp2, 24, temp);
	memcpy(temp2, temp+4, 20*DIGIT_SIZE_B);
	right_bit_shift_wide_n(20, temp2, 510);
	memcpy(g_sum+657, temp2+16, 12*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+657, g_sum+657, q_00+210, q_01+210, q_10+210, q_11+210);
	
// Recombining results: n:765, depth: 4
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+224, 8, buffer);
	memcpy(buffer+4, q_01+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_10+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(q_00+194, recombine+0, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, buffer);
	memcpy(buffer+4, q_01+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_11+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(q_01+194, recombine+0, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+224, 8, buffer);
	memcpy(buffer+4, q_11+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_10+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(q_10+194, recombine+0, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, buffer);
	memcpy(buffer+4, q_11+210, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_11+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(q_11+194, recombine+0, 12*DIGIT_SIZE_B);
	
// Recombining results: n:1785, depth: 3
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+208, 16, buffer);
	memcpy(buffer+4, q_01+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_10+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+4, 28*DIGIT_SIZE_B);
	memcpy(p_00+176, recombine+0, 28*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+208, 16, buffer);
	memcpy(buffer+4, q_01+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_11+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+4, 28*DIGIT_SIZE_B);
	memcpy(p_01+176, recombine+0, 28*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+208, 16, buffer);
	memcpy(buffer+4, q_11+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_10+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+4, 28*DIGIT_SIZE_B);
	memcpy(p_10+176, recombine+0, 28*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+208, 16, buffer);
	memcpy(buffer+4, q_11+194, 12*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_11+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+4, 28*DIGIT_SIZE_B);
	memcpy(p_11+176, recombine+0, 28*DIGIT_SIZE_B);
	
// Calculating left operands: n:3408, depth: 2
	memset(buffer, 0x00, 26*DIGIT_SIZE_B);
	memcpy(buffer+26, p_00+176, 28*DIGIT_SIZE_B);
	GF2X_MUL(108, temp2, 54, buffer, 54, f_sum+341);
	memcpy(buffer+26, p_01+176, 28*DIGIT_SIZE_B);
	GF2X_MUL(108, temp, 54, buffer, 54, g_sum+341);
	gf2x_add(108, temp, 108, temp2, 108, temp);
	memcpy(temp2, temp+26, 82*DIGIT_SIZE_B);
	right_bit_shift_wide_n(82, temp2, 1785);
	memcpy(f_sum+517, temp2+56, 54*DIGIT_SIZE_B);
	memset(buffer, 0x00, 26*DIGIT_SIZE_B);
	memcpy(buffer+26, p_10+176, 28*DIGIT_SIZE_B);
	GF2X_MUL(108, temp2, 54, buffer, 54, f_sum+341);
	memcpy(buffer+26, p_11+176, 28*DIGIT_SIZE_B);
	GF2X_MUL(108, temp, 54, buffer, 54, g_sum+341);
	gf2x_add(108, temp, 108, temp2, 108, temp);
	memcpy(temp2, temp+26, 82*DIGIT_SIZE_B);
	right_bit_shift_wide_n(82, temp2, 1785);
	memcpy(g_sum+517, temp2+56, 54*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+539, g_sum+539, p_00+232, p_01+232, p_10+232, p_11+232);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+535);
	memcpy(buffer+4, p_01+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+535);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+535);
	memcpy(buffer+4, p_11+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+535);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+681, g_sum+681, q_00+218, q_01+218, q_10+218, q_11+218);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+224, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 4
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+527);
	memcpy(buffer+8, p_01+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+527);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+657, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+527);
	memcpy(buffer+8, p_11+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+527);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+657, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+661, g_sum+661, p_00+232, p_01+232, p_10+232, p_11+232);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+657);
	memcpy(buffer+4, p_01+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+657);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+657);
	memcpy(buffer+4, p_11+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+657);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+681, g_sum+681, q_00+218, q_01+218, q_10+218, q_11+218);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+210, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+210, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+210, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+210, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 4
	GF2X_MUL(16, recombine, 8, p_00+224, 8, q_00+210);
	GF2X_MUL(16, temp, 8, p_10+224, 8, q_01+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+208, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, q_00+210);
	GF2X_MUL(16, temp, 8, p_11+224, 8, q_01+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+208, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+224, 8, q_10+210);
	GF2X_MUL(16, temp, 8, p_10+224, 8, q_11+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+208, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, q_10+210);
	GF2X_MUL(16, temp, 8, p_11+224, 8, q_11+210);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+208, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:1623, depth: 3
	memset(buffer, 0x00, 10*DIGIT_SIZE_B);
	memcpy(buffer+10, p_00+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(52, temp2, 26, buffer, 26, f_sum+517);
	memcpy(buffer+10, p_01+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(52, temp, 26, buffer, 26, g_sum+517);
	gf2x_add(52, temp, 52, temp2, 52, temp);
	memcpy(temp2, temp+10, 42*DIGIT_SIZE_B);
	right_bit_shift_wide_n(42, temp2, 1020);
	memcpy(f_sum+609, temp2+32, 26*DIGIT_SIZE_B);
	memset(buffer, 0x00, 10*DIGIT_SIZE_B);
	memcpy(buffer+10, p_10+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(52, temp2, 26, buffer, 26, f_sum+517);
	memcpy(buffer+10, p_11+208, 16*DIGIT_SIZE_B);
	GF2X_MUL(52, temp, 26, buffer, 26, g_sum+517);
	gf2x_add(52, temp, 52, temp2, 52, temp);
	memcpy(temp2, temp+10, 42*DIGIT_SIZE_B);
	right_bit_shift_wide_n(42, temp2, 1020);
	memcpy(g_sum+609, temp2+32, 26*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+615, g_sum+615, p_00+232, p_01+232, p_10+232, p_11+232);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+611);
	memcpy(buffer+4, p_01+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+611);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+611);
	memcpy(buffer+4, p_11+232, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+611);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+681, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+681, g_sum+681, q_00+218, q_01+218, q_10+218, q_11+218);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_00+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_01+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_10+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+224, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+232, 4, q_10+218);
	GF2X_MUL(8, temp, 4, p_11+232, 4, q_11+218);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+224, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:603, depth: 4
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, p_00+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(20, temp2, 10, buffer, 10, f_sum+609);
	memcpy(buffer+2, p_01+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(20, temp, 10, buffer, 10, g_sum+609);
	gf2x_add(20, temp, 20, temp2, 20, temp);
	memcpy(temp2, temp+2, 18*DIGIT_SIZE_B);
	right_bit_shift_wide_n(18, temp2, 510);
	memcpy(f_sum+657, temp2+16, 10*DIGIT_SIZE_B);
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, p_10+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(20, temp2, 10, buffer, 10, f_sum+609);
	memcpy(buffer+2, p_11+224, 8*DIGIT_SIZE_B);
	GF2X_MUL(20, temp, 10, buffer, 10, g_sum+609);
	gf2x_add(20, temp, 20, temp2, 20, temp);
	memcpy(temp2, temp+2, 18*DIGIT_SIZE_B);
	right_bit_shift_wide_n(18, temp2, 510);
	memcpy(g_sum+657, temp2+16, 10*DIGIT_SIZE_B);
	delta = divstepsx_128(93, delta, f_sum+657, g_sum+657, q_00+210, q_01+210, q_10+210, q_11+210);
	
// Recombining results: n:603, depth: 4
	memset(buffer, 0x00, 6*DIGIT_SIZE_B);
	memcpy(buffer+6, q_00+210, 2*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+224, 8, buffer);
	memcpy(buffer+6, q_01+210, 2*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_10+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+6, 10*DIGIT_SIZE_B);
	memcpy(q_00+194, recombine+0, 10*DIGIT_SIZE_B);
	memset(buffer, 0x00, 6*DIGIT_SIZE_B);
	memcpy(buffer+6, q_00+210, 2*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, buffer);
	memcpy(buffer+6, q_01+210, 2*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_11+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+6, 10*DIGIT_SIZE_B);
	memcpy(q_01+194, recombine+0, 10*DIGIT_SIZE_B);
	memset(buffer, 0x00, 6*DIGIT_SIZE_B);
	memcpy(buffer+6, q_10+210, 2*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+224, 8, buffer);
	memcpy(buffer+6, q_11+210, 2*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_10+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+6, 10*DIGIT_SIZE_B);
	memcpy(q_10+194, recombine+0, 10*DIGIT_SIZE_B);
	memset(buffer, 0x00, 6*DIGIT_SIZE_B);
	memcpy(buffer+6, q_10+210, 2*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+224, 8, buffer);
	memcpy(buffer+6, q_11+210, 2*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_11+224, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+6, 10*DIGIT_SIZE_B);
	memcpy(q_11+194, recombine+0, 10*DIGIT_SIZE_B);
	
// Recombining results: n:1623, depth: 3
	memset(buffer, 0x00, 6*DIGIT_SIZE_B);
	memcpy(buffer+6, q_00+194, 10*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+208, 16, buffer);
	memcpy(buffer+6, q_01+194, 10*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_10+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+6, 26*DIGIT_SIZE_B);
	memcpy(q_00+166, recombine+0, 26*DIGIT_SIZE_B);
	memset(buffer, 0x00, 6*DIGIT_SIZE_B);
	memcpy(buffer+6, q_00+194, 10*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+208, 16, buffer);
	memcpy(buffer+6, q_01+194, 10*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_11+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+6, 26*DIGIT_SIZE_B);
	memcpy(q_01+166, recombine+0, 26*DIGIT_SIZE_B);
	memset(buffer, 0x00, 6*DIGIT_SIZE_B);
	memcpy(buffer+6, q_10+194, 10*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+208, 16, buffer);
	memcpy(buffer+6, q_11+194, 10*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_10+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+6, 26*DIGIT_SIZE_B);
	memcpy(q_10+166, recombine+0, 26*DIGIT_SIZE_B);
	memset(buffer, 0x00, 6*DIGIT_SIZE_B);
	memcpy(buffer+6, q_10+194, 10*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+208, 16, buffer);
	memcpy(buffer+6, q_11+194, 10*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_11+208, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+6, 26*DIGIT_SIZE_B);
	memcpy(q_11+166, recombine+0, 26*DIGIT_SIZE_B);
	
// Recombining results: n:3408, depth: 2
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, q_00+166, 26*DIGIT_SIZE_B);
	GF2X_MUL(56, recombine, 28, p_00+176, 28, buffer);
	memcpy(buffer+2, q_01+166, 26*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_10+176, 28, buffer);
	gf2x_add(56, temp, 56, recombine, 56, temp);
	memcpy(recombine, temp+2, 54*DIGIT_SIZE_B);
	memcpy(q_00+110, recombine+0, 54*DIGIT_SIZE_B);
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, q_00+166, 26*DIGIT_SIZE_B);
	GF2X_MUL(56, recombine, 28, p_01+176, 28, buffer);
	memcpy(buffer+2, q_01+166, 26*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_11+176, 28, buffer);
	gf2x_add(56, temp, 56, recombine, 56, temp);
	memcpy(recombine, temp+2, 54*DIGIT_SIZE_B);
	memcpy(q_01+110, recombine+0, 54*DIGIT_SIZE_B);
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, q_10+166, 26*DIGIT_SIZE_B);
	GF2X_MUL(56, recombine, 28, p_00+176, 28, buffer);
	memcpy(buffer+2, q_11+166, 26*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_10+176, 28, buffer);
	gf2x_add(56, temp, 56, recombine, 56, temp);
	memcpy(recombine, temp+2, 54*DIGIT_SIZE_B);
	memcpy(q_10+110, recombine+0, 54*DIGIT_SIZE_B);
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, q_10+166, 26*DIGIT_SIZE_B);
	GF2X_MUL(56, recombine, 28, p_01+176, 28, buffer);
	memcpy(buffer+2, q_11+166, 26*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_11+176, 28, buffer);
	gf2x_add(56, temp, 56, recombine, 56, temp);
	memcpy(recombine, temp+2, 54*DIGIT_SIZE_B);
	memcpy(q_11+110, recombine+0, 54*DIGIT_SIZE_B);
	
// Recombining results: n:6978, depth: 1
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, q_00+110, 54*DIGIT_SIZE_B);
	GF2X_MUL(112, recombine, 56, p_00+116, 56, buffer);
	memcpy(buffer+2, q_01+110, 54*DIGIT_SIZE_B);
	GF2X_MUL(112, temp, 56, p_10+116, 56, buffer);
	gf2x_add(112, temp, 112, recombine, 112, temp);
	memcpy(recombine, temp+2, 110*DIGIT_SIZE_B);
	memcpy(q_00+0, recombine+0, 110*DIGIT_SIZE_B);
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, q_00+110, 54*DIGIT_SIZE_B);
	GF2X_MUL(112, recombine, 56, p_01+116, 56, buffer);
	memcpy(buffer+2, q_01+110, 54*DIGIT_SIZE_B);
	GF2X_MUL(112, temp, 56, p_11+116, 56, buffer);
	gf2x_add(112, temp, 112, recombine, 112, temp);
	memcpy(recombine, temp+2, 110*DIGIT_SIZE_B);
	memcpy(q_01+0, recombine+0, 110*DIGIT_SIZE_B);
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, q_10+110, 54*DIGIT_SIZE_B);
	GF2X_MUL(112, recombine, 56, p_00+116, 56, buffer);
	memcpy(buffer+2, q_11+110, 54*DIGIT_SIZE_B);
	GF2X_MUL(112, temp, 56, p_10+116, 56, buffer);
	gf2x_add(112, temp, 112, recombine, 112, temp);
	memcpy(recombine, temp+2, 110*DIGIT_SIZE_B);
	memcpy(q_10+0, recombine+0, 110*DIGIT_SIZE_B);
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, q_10+110, 54*DIGIT_SIZE_B);
	GF2X_MUL(112, recombine, 56, p_01+116, 56, buffer);
	memcpy(buffer+2, q_11+110, 54*DIGIT_SIZE_B);
	GF2X_MUL(112, temp, 56, p_11+116, 56, buffer);
	gf2x_add(112, temp, 112, recombine, 112, temp);
	memcpy(recombine, temp+2, 110*DIGIT_SIZE_B);
	memcpy(q_11+0, recombine+0, 110*DIGIT_SIZE_B);
	
// Recombining results: n:14373, depth: 0
	memset(buffer, 0x00, 6*DIGIT_SIZE_B);
	memcpy(buffer+6, q_00+0, 110*DIGIT_SIZE_B);
	GF2X_MUL(232, recombine, 116, p_00+0, 116, buffer);
	memcpy(buffer+6, q_01+0, 110*DIGIT_SIZE_B);
	GF2X_MUL(232, temp, 116, p_10+0, 116, buffer);
	gf2x_add(232, temp, 232, recombine, 232, temp);
	memcpy(recombine, temp+6, 226*DIGIT_SIZE_B);
	memcpy(t_00+0, recombine+1, 225*DIGIT_SIZE_B);
	memset(buffer, 0x00, 6*DIGIT_SIZE_B);
	memcpy(buffer+6, q_00+0, 110*DIGIT_SIZE_B);
	GF2X_MUL(232, recombine, 116, p_01+0, 116, buffer);
	memcpy(buffer+6, q_01+0, 110*DIGIT_SIZE_B);
	GF2X_MUL(232, temp, 116, p_11+0, 116, buffer);
	gf2x_add(232, temp, 232, recombine, 232, temp);
	memcpy(recombine, temp+6, 226*DIGIT_SIZE_B);
	memcpy(t_01+0, recombine+1, 225*DIGIT_SIZE_B);
	memset(buffer, 0x00, 6*DIGIT_SIZE_B);
	memcpy(buffer+6, q_10+0, 110*DIGIT_SIZE_B);
	GF2X_MUL(232, recombine, 116, p_00+0, 116, buffer);
	memcpy(buffer+6, q_11+0, 110*DIGIT_SIZE_B);
	GF2X_MUL(232, temp, 116, p_10+0, 116, buffer);
	gf2x_add(232, temp, 232, recombine, 232, temp);
	memcpy(recombine, temp+6, 226*DIGIT_SIZE_B);
	memcpy(t_10+0, recombine+1, 225*DIGIT_SIZE_B);
	memset(buffer, 0x00, 6*DIGIT_SIZE_B);
	memcpy(buffer+6, q_10+0, 110*DIGIT_SIZE_B);
	GF2X_MUL(232, recombine, 116, p_01+0, 116, buffer);
	memcpy(buffer+6, q_11+0, 110*DIGIT_SIZE_B);
	GF2X_MUL(232, temp, 116, p_11+0, 116, buffer);
	gf2x_add(232, temp, 232, recombine, 232, temp);
	memcpy(recombine, temp+6, 226*DIGIT_SIZE_B);
	memcpy(t_11+0, recombine+1, 225*DIGIT_SIZE_B);
	return delta;
}