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
	
	DIGIT f_sum[1520];
	DIGIT g_sum[1520];
	
	DIGIT temp[1019];
	DIGIT recombine[1019];
	DIGIT temp2[1019];
	DIGIT buffer[1019];
	

	delta = divstepsx_256(255, delta, f+504, g+504, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f+500);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g+500);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f+500);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g+500);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f+492);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g+492);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f+492);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g+492);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f+476);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g+476);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f+476);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g+476);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+477, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_00+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_01+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_10+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_11+448, recombine+0, 32*DIGIT_SIZE_B);
	
// Calculating left operands: n:4080, depth: 3
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_00+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f+444);
	memcpy(buffer+32, p_01+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g+444);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(f_sum+1340, temp2+64, 64*DIGIT_SIZE_B);
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_10+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f+444);
	memcpy(buffer+32, p_11+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g+444);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(g_sum+1340, temp2+64, 64*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1368, g_sum+1368, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1364);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1364);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1364);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1364);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1356);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1356);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1356);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1356);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1340);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1340);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1340);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1340);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+477, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_00+445, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_01+445, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_10+445, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_11+445, recombine+0, 32*DIGIT_SIZE_B);
	
// Recombining results: n:4080, depth: 3
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_00+445);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_01+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_00+384, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_00+445);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_01+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_01+384, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_10+445);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_11+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_10+384, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_10+445);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_11+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_11+384, recombine+0, 64*DIGIT_SIZE_B);
	
// Calculating left operands: n:8160, depth: 2
	memset(buffer, 0x00, 64*DIGIT_SIZE_B);
	memcpy(buffer+64, p_00+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(256, temp2, 128, buffer, 128, f+380);
	memcpy(buffer+64, p_01+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(256, temp, 128, buffer, 128, g+380);
	gf2x_add(256, temp, 256, temp2, 256, temp);
	memcpy(temp2, temp+64, 192*DIGIT_SIZE_B);
	right_bit_shift_wide_n(192, temp2, 4080);
	memcpy(f_sum+1148, temp2+128, 128*DIGIT_SIZE_B);
	memset(buffer, 0x00, 64*DIGIT_SIZE_B);
	memcpy(buffer+64, p_10+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(256, temp2, 128, buffer, 128, f+380);
	memcpy(buffer+64, p_11+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(256, temp, 128, buffer, 128, g+380);
	gf2x_add(256, temp, 256, temp2, 256, temp);
	memcpy(temp2, temp+64, 192*DIGIT_SIZE_B);
	right_bit_shift_wide_n(192, temp2, 4080);
	memcpy(g_sum+1148, temp2+128, 128*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1208, g_sum+1208, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1204);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1204);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1204);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1204);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1196);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1196);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1196);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1196);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1180);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1180);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1180);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1180);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+477, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_00+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_01+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_10+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_11+448, recombine+0, 32*DIGIT_SIZE_B);
	
// Calculating left operands: n:4080, depth: 3
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_00+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+1148);
	memcpy(buffer+32, p_01+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+1148);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(f_sum+1340, temp2+64, 64*DIGIT_SIZE_B);
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_10+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+1148);
	memcpy(buffer+32, p_11+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+1148);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(g_sum+1340, temp2+64, 64*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1368, g_sum+1368, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1364);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1364);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1364);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1364);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1356);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1356);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1356);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1356);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1340);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1340);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1340);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1340);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+477, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_00+445, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_01+445, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_10+445, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_11+445, recombine+0, 32*DIGIT_SIZE_B);
	
// Recombining results: n:4080, depth: 3
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_00+445);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_01+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_00+381, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_00+445);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_01+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_01+381, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_10+445);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_11+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_10+381, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_10+445);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_11+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_11+381, recombine+0, 64*DIGIT_SIZE_B);
	
// Recombining results: n:8160, depth: 2
	GF2X_MUL(128, recombine, 64, p_00+384, 64, q_00+381);
	GF2X_MUL(128, temp, 64, p_10+384, 64, q_01+381);
	gf2x_add(128, recombine, 128, temp, 128, recombine);
	memcpy(p_00+256, recombine+0, 128*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_01+384, 64, q_00+381);
	GF2X_MUL(128, temp, 64, p_11+384, 64, q_01+381);
	gf2x_add(128, recombine, 128, temp, 128, recombine);
	memcpy(p_01+256, recombine+0, 128*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_00+384, 64, q_10+381);
	GF2X_MUL(128, temp, 64, p_10+384, 64, q_11+381);
	gf2x_add(128, recombine, 128, temp, 128, recombine);
	memcpy(p_10+256, recombine+0, 128*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_01+384, 64, q_10+381);
	GF2X_MUL(128, temp, 64, p_11+384, 64, q_11+381);
	gf2x_add(128, recombine, 128, temp, 128, recombine);
	memcpy(p_11+256, recombine+0, 128*DIGIT_SIZE_B);
	
// Calculating left operands: n:16320, depth: 1
	memset(buffer, 0x00, 128*DIGIT_SIZE_B);
	memcpy(buffer+128, p_00+256, 128*DIGIT_SIZE_B);
	GF2X_MUL(512, temp2, 256, buffer, 256, f+252);
	memcpy(buffer+128, p_01+256, 128*DIGIT_SIZE_B);
	GF2X_MUL(512, temp, 256, buffer, 256, g+252);
	gf2x_add(512, temp, 512, temp2, 512, temp);
	memcpy(temp2, temp+128, 384*DIGIT_SIZE_B);
	right_bit_shift_wide_n(384, temp2, 8160);
	memcpy(f_sum+764, temp2+256, 256*DIGIT_SIZE_B);
	memset(buffer, 0x00, 128*DIGIT_SIZE_B);
	memcpy(buffer+128, p_10+256, 128*DIGIT_SIZE_B);
	GF2X_MUL(512, temp2, 256, buffer, 256, f+252);
	memcpy(buffer+128, p_11+256, 128*DIGIT_SIZE_B);
	GF2X_MUL(512, temp, 256, buffer, 256, g+252);
	gf2x_add(512, temp, 512, temp2, 512, temp);
	memcpy(temp2, temp+128, 384*DIGIT_SIZE_B);
	right_bit_shift_wide_n(384, temp2, 8160);
	memcpy(g_sum+764, temp2+256, 256*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+888, g_sum+888, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+884);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+884);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+884);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+884);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+876);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+876);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+876);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+876);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+860);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+860);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+860);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+860);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+477, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_00+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_01+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_10+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_11+448, recombine+0, 32*DIGIT_SIZE_B);
	
// Calculating left operands: n:4080, depth: 3
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_00+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+828);
	memcpy(buffer+32, p_01+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+828);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(f_sum+1340, temp2+64, 64*DIGIT_SIZE_B);
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_10+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+828);
	memcpy(buffer+32, p_11+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+828);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(g_sum+1340, temp2+64, 64*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1368, g_sum+1368, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1364);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1364);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1364);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1364);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1356);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1356);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1356);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1356);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1340);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1340);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1340);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1340);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+477, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_00+445, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_01+445, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_10+445, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_11+445, recombine+0, 32*DIGIT_SIZE_B);
	
// Recombining results: n:4080, depth: 3
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_00+445);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_01+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_00+384, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_00+445);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_01+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_01+384, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_10+445);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_11+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_10+384, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_10+445);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_11+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_11+384, recombine+0, 64*DIGIT_SIZE_B);
	
// Calculating left operands: n:8160, depth: 2
	memset(buffer, 0x00, 64*DIGIT_SIZE_B);
	memcpy(buffer+64, p_00+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(256, temp2, 128, buffer, 128, f_sum+764);
	memcpy(buffer+64, p_01+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(256, temp, 128, buffer, 128, g_sum+764);
	gf2x_add(256, temp, 256, temp2, 256, temp);
	memcpy(temp2, temp+64, 192*DIGIT_SIZE_B);
	right_bit_shift_wide_n(192, temp2, 4080);
	memcpy(f_sum+1148, temp2+128, 128*DIGIT_SIZE_B);
	memset(buffer, 0x00, 64*DIGIT_SIZE_B);
	memcpy(buffer+64, p_10+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(256, temp2, 128, buffer, 128, f_sum+764);
	memcpy(buffer+64, p_11+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(256, temp, 128, buffer, 128, g_sum+764);
	gf2x_add(256, temp, 256, temp2, 256, temp);
	memcpy(temp2, temp+64, 192*DIGIT_SIZE_B);
	right_bit_shift_wide_n(192, temp2, 4080);
	memcpy(g_sum+1148, temp2+128, 128*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1208, g_sum+1208, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1204);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1204);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1204);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1204);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1196);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1196);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1196);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1196);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1180);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1180);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1180);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1180);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+477, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_00+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_01+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_10+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_11+448, recombine+0, 32*DIGIT_SIZE_B);
	
// Calculating left operands: n:4080, depth: 3
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_00+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+1148);
	memcpy(buffer+32, p_01+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+1148);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(f_sum+1340, temp2+64, 64*DIGIT_SIZE_B);
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_10+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+1148);
	memcpy(buffer+32, p_11+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+1148);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(g_sum+1340, temp2+64, 64*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1368, g_sum+1368, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1364);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1364);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1364);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1364);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1356);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1356);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1356);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1356);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1340);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1340);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1340);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1340);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+477, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_00+445, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_01+445, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_10+445, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_11+445, recombine+0, 32*DIGIT_SIZE_B);
	
// Recombining results: n:4080, depth: 3
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_00+445);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_01+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_00+381, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_00+445);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_01+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_01+381, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_10+445);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_11+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_10+381, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_10+445);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_11+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_11+381, recombine+0, 64*DIGIT_SIZE_B);
	
// Recombining results: n:8160, depth: 2
	GF2X_MUL(128, recombine, 64, p_00+384, 64, q_00+381);
	GF2X_MUL(128, temp, 64, p_10+384, 64, q_01+381);
	gf2x_add(128, recombine, 128, temp, 128, recombine);
	memcpy(q_00+253, recombine+0, 128*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_01+384, 64, q_00+381);
	GF2X_MUL(128, temp, 64, p_11+384, 64, q_01+381);
	gf2x_add(128, recombine, 128, temp, 128, recombine);
	memcpy(q_01+253, recombine+0, 128*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_00+384, 64, q_10+381);
	GF2X_MUL(128, temp, 64, p_10+384, 64, q_11+381);
	gf2x_add(128, recombine, 128, temp, 128, recombine);
	memcpy(q_10+253, recombine+0, 128*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_01+384, 64, q_10+381);
	GF2X_MUL(128, temp, 64, p_11+384, 64, q_11+381);
	gf2x_add(128, recombine, 128, temp, 128, recombine);
	memcpy(q_11+253, recombine+0, 128*DIGIT_SIZE_B);
	
// Recombining results: n:16320, depth: 1
	GF2X_MUL(256, recombine, 128, p_00+256, 128, q_00+253);
	GF2X_MUL(256, temp, 128, p_10+256, 128, q_01+253);
	gf2x_add(256, recombine, 256, temp, 256, recombine);
	memcpy(p_00+0, recombine+0, 256*DIGIT_SIZE_B);
	GF2X_MUL(256, recombine, 128, p_01+256, 128, q_00+253);
	GF2X_MUL(256, temp, 128, p_11+256, 128, q_01+253);
	gf2x_add(256, recombine, 256, temp, 256, recombine);
	memcpy(p_01+0, recombine+0, 256*DIGIT_SIZE_B);
	GF2X_MUL(256, recombine, 128, p_00+256, 128, q_10+253);
	GF2X_MUL(256, temp, 128, p_10+256, 128, q_11+253);
	gf2x_add(256, recombine, 256, temp, 256, recombine);
	memcpy(p_10+0, recombine+0, 256*DIGIT_SIZE_B);
	GF2X_MUL(256, recombine, 128, p_01+256, 128, q_10+253);
	GF2X_MUL(256, temp, 128, p_11+256, 128, q_11+253);
	gf2x_add(256, recombine, 256, temp, 256, recombine);
	memcpy(p_11+0, recombine+0, 256*DIGIT_SIZE_B);
	
// Calculating left operands: n:32457, depth: 0
	memset(buffer, 0x00, 252*DIGIT_SIZE_B);
	memcpy(buffer+252, p_00+0, 256*DIGIT_SIZE_B);
	GF2X_MUL(1016, temp2, 508, buffer, 508, f+0);
	memcpy(buffer+252, p_01+0, 256*DIGIT_SIZE_B);
	GF2X_MUL(1016, temp, 508, buffer, 508, g+0);
	gf2x_add(1016, temp, 1016, temp2, 1016, temp);
	memcpy(temp2, temp+252, 764*DIGIT_SIZE_B);
	right_bit_shift_wide_n(764, temp2, 16320);
	memcpy(f_sum+0, temp2+511, 508*DIGIT_SIZE_B);
	memset(buffer, 0x00, 252*DIGIT_SIZE_B);
	memcpy(buffer+252, p_10+0, 256*DIGIT_SIZE_B);
	GF2X_MUL(1016, temp2, 508, buffer, 508, f+0);
	memcpy(buffer+252, p_11+0, 256*DIGIT_SIZE_B);
	GF2X_MUL(1016, temp, 508, buffer, 508, g+0);
	gf2x_add(1016, temp, 1016, temp2, 1016, temp);
	memcpy(temp2, temp+252, 764*DIGIT_SIZE_B);
	right_bit_shift_wide_n(764, temp2, 16320);
	memcpy(g_sum+0, temp2+511, 508*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+249, g_sum+249, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+245);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+245);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+245);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+245);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+237);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+237);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+237);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+237);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+221);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+221);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+221);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+221);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+477, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_00+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_01+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_10+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_11+448, recombine+0, 32*DIGIT_SIZE_B);
	
// Calculating left operands: n:4080, depth: 3
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_00+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+189);
	memcpy(buffer+32, p_01+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+189);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(f_sum+1340, temp2+64, 64*DIGIT_SIZE_B);
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_10+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+189);
	memcpy(buffer+32, p_11+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+189);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(g_sum+1340, temp2+64, 64*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1368, g_sum+1368, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1364);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1364);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1364);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1364);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1356);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1356);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1356);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1356);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1340);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1340);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1340);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1340);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+477, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_00+445, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_01+445, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_10+445, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_11+445, recombine+0, 32*DIGIT_SIZE_B);
	
// Recombining results: n:4080, depth: 3
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_00+445);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_01+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_00+384, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_00+445);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_01+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_01+384, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_10+445);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_11+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_10+384, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_10+445);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_11+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_11+384, recombine+0, 64*DIGIT_SIZE_B);
	
// Calculating left operands: n:8160, depth: 2
	memset(buffer, 0x00, 64*DIGIT_SIZE_B);
	memcpy(buffer+64, p_00+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(256, temp2, 128, buffer, 128, f_sum+125);
	memcpy(buffer+64, p_01+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(256, temp, 128, buffer, 128, g_sum+125);
	gf2x_add(256, temp, 256, temp2, 256, temp);
	memcpy(temp2, temp+64, 192*DIGIT_SIZE_B);
	right_bit_shift_wide_n(192, temp2, 4080);
	memcpy(f_sum+1148, temp2+128, 128*DIGIT_SIZE_B);
	memset(buffer, 0x00, 64*DIGIT_SIZE_B);
	memcpy(buffer+64, p_10+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(256, temp2, 128, buffer, 128, f_sum+125);
	memcpy(buffer+64, p_11+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(256, temp, 128, buffer, 128, g_sum+125);
	gf2x_add(256, temp, 256, temp2, 256, temp);
	memcpy(temp2, temp+64, 192*DIGIT_SIZE_B);
	right_bit_shift_wide_n(192, temp2, 4080);
	memcpy(g_sum+1148, temp2+128, 128*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1208, g_sum+1208, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1204);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1204);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1204);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1204);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1196);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1196);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1196);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1196);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1180);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1180);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1180);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1180);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+477, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_00+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_01+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_10+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_11+448, recombine+0, 32*DIGIT_SIZE_B);
	
// Calculating left operands: n:4080, depth: 3
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_00+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+1148);
	memcpy(buffer+32, p_01+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+1148);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(f_sum+1340, temp2+64, 64*DIGIT_SIZE_B);
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_10+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+1148);
	memcpy(buffer+32, p_11+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+1148);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(g_sum+1340, temp2+64, 64*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1368, g_sum+1368, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1364);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1364);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1364);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1364);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1356);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1356);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1356);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1356);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1340);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1340);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1340);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1340);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+477, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_00+445, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_01+445, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_10+445, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_11+445, recombine+0, 32*DIGIT_SIZE_B);
	
// Recombining results: n:4080, depth: 3
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_00+445);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_01+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_00+381, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_00+445);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_01+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_01+381, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_10+445);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_11+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_10+381, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_10+445);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_11+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_11+381, recombine+0, 64*DIGIT_SIZE_B);
	
// Recombining results: n:8160, depth: 2
	GF2X_MUL(128, recombine, 64, p_00+384, 64, q_00+381);
	GF2X_MUL(128, temp, 64, p_10+384, 64, q_01+381);
	gf2x_add(128, recombine, 128, temp, 128, recombine);
	memcpy(p_00+256, recombine+0, 128*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_01+384, 64, q_00+381);
	GF2X_MUL(128, temp, 64, p_11+384, 64, q_01+381);
	gf2x_add(128, recombine, 128, temp, 128, recombine);
	memcpy(p_01+256, recombine+0, 128*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_00+384, 64, q_10+381);
	GF2X_MUL(128, temp, 64, p_10+384, 64, q_11+381);
	gf2x_add(128, recombine, 128, temp, 128, recombine);
	memcpy(p_10+256, recombine+0, 128*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_01+384, 64, q_10+381);
	GF2X_MUL(128, temp, 64, p_11+384, 64, q_11+381);
	gf2x_add(128, recombine, 128, temp, 128, recombine);
	memcpy(p_11+256, recombine+0, 128*DIGIT_SIZE_B);
	
// Calculating left operands: n:16137, depth: 1
	memset(buffer, 0x00, 125*DIGIT_SIZE_B);
	memcpy(buffer+125, p_00+256, 128*DIGIT_SIZE_B);
	GF2X_MUL(506, temp2, 253, buffer, 253, f_sum+0);
	memcpy(buffer+125, p_01+256, 128*DIGIT_SIZE_B);
	GF2X_MUL(506, temp, 253, buffer, 253, g_sum+0);
	gf2x_add(506, temp, 506, temp2, 506, temp);
	memcpy(temp2, temp+125, 381*DIGIT_SIZE_B);
	right_bit_shift_wide_n(381, temp2, 8160);
	memcpy(f_sum+764, temp2+256, 253*DIGIT_SIZE_B);
	memset(buffer, 0x00, 125*DIGIT_SIZE_B);
	memcpy(buffer+125, p_10+256, 128*DIGIT_SIZE_B);
	GF2X_MUL(506, temp2, 253, buffer, 253, f_sum+0);
	memcpy(buffer+125, p_11+256, 128*DIGIT_SIZE_B);
	GF2X_MUL(506, temp, 253, buffer, 253, g_sum+0);
	gf2x_add(506, temp, 506, temp2, 506, temp);
	memcpy(temp2, temp+125, 381*DIGIT_SIZE_B);
	right_bit_shift_wide_n(381, temp2, 8160);
	memcpy(g_sum+764, temp2+256, 253*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+885, g_sum+885, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+881);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+881);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+881);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+881);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+873);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+873);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+873);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+873);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+857);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+857);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+857);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+857);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+477, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_00+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_01+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_10+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_11+448, recombine+0, 32*DIGIT_SIZE_B);
	
// Calculating left operands: n:4080, depth: 3
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_00+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+825);
	memcpy(buffer+32, p_01+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+825);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(f_sum+1340, temp2+64, 64*DIGIT_SIZE_B);
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_10+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+825);
	memcpy(buffer+32, p_11+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+825);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(g_sum+1340, temp2+64, 64*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1368, g_sum+1368, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1364);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1364);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1364);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1364);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1356);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1356);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1356);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1356);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1340);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1340);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1340);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1340);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+477, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_00+445, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_01+445, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_10+445, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_11+445, recombine+0, 32*DIGIT_SIZE_B);
	
// Recombining results: n:4080, depth: 3
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_00+445);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_01+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_00+384, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_00+445);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_01+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_01+384, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_10+445);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_11+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_10+384, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_10+445);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_11+445);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_11+384, recombine+0, 64*DIGIT_SIZE_B);
	
// Calculating left operands: n:7977, depth: 2
	memset(buffer, 0x00, 61*DIGIT_SIZE_B);
	memcpy(buffer+61, p_00+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(250, temp2, 125, buffer, 125, f_sum+764);
	memcpy(buffer+61, p_01+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(250, temp, 125, buffer, 125, g_sum+764);
	gf2x_add(250, temp, 250, temp2, 250, temp);
	memcpy(temp2, temp+61, 189*DIGIT_SIZE_B);
	right_bit_shift_wide_n(189, temp2, 4080);
	memcpy(f_sum+1148, temp2+128, 125*DIGIT_SIZE_B);
	memset(buffer, 0x00, 61*DIGIT_SIZE_B);
	memcpy(buffer+61, p_10+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(250, temp2, 125, buffer, 125, f_sum+764);
	memcpy(buffer+61, p_11+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(250, temp, 125, buffer, 125, g_sum+764);
	gf2x_add(250, temp, 250, temp2, 250, temp);
	memcpy(temp2, temp+61, 189*DIGIT_SIZE_B);
	right_bit_shift_wide_n(189, temp2, 4080);
	memcpy(g_sum+1148, temp2+128, 125*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1205, g_sum+1205, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1201);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1201);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1201);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1201);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1193);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1193);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1193);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1193);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1177);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1177);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1177);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1177);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1436, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1444);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1444);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1436);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1436);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+477, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+477, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_00+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_01+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_10+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+477);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+477);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_11+448, recombine+0, 32*DIGIT_SIZE_B);
	
// Calculating left operands: n:3897, depth: 3
	memset(buffer, 0x00, 29*DIGIT_SIZE_B);
	memcpy(buffer+29, p_00+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(122, temp2, 61, buffer, 61, f_sum+1148);
	memcpy(buffer+29, p_01+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(122, temp, 61, buffer, 61, g_sum+1148);
	gf2x_add(122, temp, 122, temp2, 122, temp);
	memcpy(temp2, temp+29, 93*DIGIT_SIZE_B);
	right_bit_shift_wide_n(93, temp2, 2040);
	memcpy(f_sum+1340, temp2+63, 61*DIGIT_SIZE_B);
	memset(buffer, 0x00, 29*DIGIT_SIZE_B);
	memcpy(buffer+29, p_10+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(122, temp2, 61, buffer, 61, f_sum+1148);
	memcpy(buffer+29, p_11+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(122, temp, 61, buffer, 61, g_sum+1148);
	gf2x_add(122, temp, 122, temp2, 122, temp);
	memcpy(temp2, temp+29, 93*DIGIT_SIZE_B);
	right_bit_shift_wide_n(93, temp2, 2040);
	memcpy(g_sum+1340, temp2+63, 61*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1366, g_sum+1366, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1362);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1362);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1362);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1362);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1354);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1354);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1354);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1354);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1488, g_sum+1488, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1484);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1484);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+493, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+493, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+493);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+493);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:1857, depth: 4
	memset(buffer, 0x00, 14*DIGIT_SIZE_B);
	memcpy(buffer+14, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(60, temp2, 30, buffer, 30, f_sum+1340);
	memcpy(buffer+14, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(60, temp, 30, buffer, 30, g_sum+1340);
	gf2x_add(60, temp, 60, temp2, 60, temp);
	memcpy(temp2, temp+14, 46*DIGIT_SIZE_B);
	right_bit_shift_wide_n(46, temp2, 1020);
	memcpy(f_sum+1436, temp2+32, 30*DIGIT_SIZE_B);
	memset(buffer, 0x00, 14*DIGIT_SIZE_B);
	memcpy(buffer+14, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(60, temp2, 30, buffer, 30, f_sum+1340);
	memcpy(buffer+14, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(60, temp, 30, buffer, 30, g_sum+1340);
	gf2x_add(60, temp, 60, temp2, 60, temp);
	memcpy(temp2, temp+14, 46*DIGIT_SIZE_B);
	right_bit_shift_wide_n(46, temp2, 1020);
	memcpy(g_sum+1436, temp2+32, 30*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1446, g_sum+1446, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1442);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1442);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1442);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1442);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+501);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+501);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:837, depth: 5
	memset(buffer, 0x00, 6*DIGIT_SIZE_B);
	memcpy(buffer+6, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(28, temp2, 14, buffer, 14, f_sum+1436);
	memcpy(buffer+6, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(28, temp, 14, buffer, 14, g_sum+1436);
	gf2x_add(28, temp, 28, temp2, 28, temp);
	memcpy(temp2, temp+6, 22*DIGIT_SIZE_B);
	right_bit_shift_wide_n(22, temp2, 510);
	memcpy(f_sum+1484, temp2+16, 14*DIGIT_SIZE_B);
	memset(buffer, 0x00, 6*DIGIT_SIZE_B);
	memcpy(buffer+6, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(28, temp2, 14, buffer, 14, f_sum+1436);
	memcpy(buffer+6, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(28, temp, 14, buffer, 14, g_sum+1436);
	gf2x_add(28, temp, 28, temp2, 28, temp);
	memcpy(temp2, temp+6, 22*DIGIT_SIZE_B);
	right_bit_shift_wide_n(22, temp2, 510);
	memcpy(g_sum+1484, temp2+16, 14*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1486, g_sum+1486, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:327, depth: 6
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(12, temp2, 6, buffer, 6, f_sum+1484);
	memcpy(buffer+2, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(12, temp, 6, buffer, 6, g_sum+1484);
	gf2x_add(12, temp, 12, temp2, 12, temp);
	memcpy(temp2, temp+2, 10*DIGIT_SIZE_B);
	right_bit_shift_wide_n(10, temp2, 255);
	memcpy(f_sum+1508, temp2+8, 6*DIGIT_SIZE_B);
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(12, temp2, 6, buffer, 6, f_sum+1484);
	memcpy(buffer+2, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(12, temp, 6, buffer, 6, g_sum+1484);
	gf2x_add(12, temp, 12, temp2, 12, temp);
	memcpy(temp2, temp+2, 10*DIGIT_SIZE_B);
	right_bit_shift_wide_n(10, temp2, 255);
	memcpy(g_sum+1508, temp2+8, 6*DIGIT_SIZE_B);
	delta = divstepsx_128(72, delta, f_sum+1508, g_sum+1508, q_00+501, q_01+501, q_10+501, q_11+501);
	
// Recombining results: n:327, depth: 6
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, q_00+501, 2*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, buffer);
	memcpy(buffer+2, q_01+501, 2*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_10+504, 4, buffer);
	gf2x_add(8, temp, 8, recombine, 8, temp);
	memcpy(recombine, temp+2, 6*DIGIT_SIZE_B);
	memcpy(q_00+493, recombine+0, 6*DIGIT_SIZE_B);
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, q_00+501, 2*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, buffer);
	memcpy(buffer+2, q_01+501, 2*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_11+504, 4, buffer);
	gf2x_add(8, temp, 8, recombine, 8, temp);
	memcpy(recombine, temp+2, 6*DIGIT_SIZE_B);
	memcpy(q_01+493, recombine+0, 6*DIGIT_SIZE_B);
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, q_10+501, 2*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, buffer);
	memcpy(buffer+2, q_11+501, 2*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_10+504, 4, buffer);
	gf2x_add(8, temp, 8, recombine, 8, temp);
	memcpy(recombine, temp+2, 6*DIGIT_SIZE_B);
	memcpy(q_10+493, recombine+0, 6*DIGIT_SIZE_B);
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, q_10+501, 2*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, buffer);
	memcpy(buffer+2, q_11+501, 2*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_11+504, 4, buffer);
	gf2x_add(8, temp, 8, recombine, 8, temp);
	memcpy(recombine, temp+2, 6*DIGIT_SIZE_B);
	memcpy(q_11+493, recombine+0, 6*DIGIT_SIZE_B);
	
// Recombining results: n:837, depth: 5
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, q_00+493, 6*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, buffer);
	memcpy(buffer+2, q_01+493, 6*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_10+496, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+2, 14*DIGIT_SIZE_B);
	memcpy(q_00+477, recombine+0, 14*DIGIT_SIZE_B);
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, q_00+493, 6*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, buffer);
	memcpy(buffer+2, q_01+493, 6*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_11+496, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+2, 14*DIGIT_SIZE_B);
	memcpy(q_01+477, recombine+0, 14*DIGIT_SIZE_B);
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, q_10+493, 6*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, buffer);
	memcpy(buffer+2, q_11+493, 6*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_10+496, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+2, 14*DIGIT_SIZE_B);
	memcpy(q_10+477, recombine+0, 14*DIGIT_SIZE_B);
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, q_10+493, 6*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, buffer);
	memcpy(buffer+2, q_11+493, 6*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_11+496, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+2, 14*DIGIT_SIZE_B);
	memcpy(q_11+477, recombine+0, 14*DIGIT_SIZE_B);
	
// Recombining results: n:1857, depth: 4
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, q_00+477, 14*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, buffer);
	memcpy(buffer+2, q_01+477, 14*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_10+480, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+2, 30*DIGIT_SIZE_B);
	memcpy(q_00+445, recombine+0, 30*DIGIT_SIZE_B);
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, q_00+477, 14*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, buffer);
	memcpy(buffer+2, q_01+477, 14*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_11+480, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+2, 30*DIGIT_SIZE_B);
	memcpy(q_01+445, recombine+0, 30*DIGIT_SIZE_B);
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, q_10+477, 14*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, buffer);
	memcpy(buffer+2, q_11+477, 14*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_10+480, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+2, 30*DIGIT_SIZE_B);
	memcpy(q_10+445, recombine+0, 30*DIGIT_SIZE_B);
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, q_10+477, 14*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, buffer);
	memcpy(buffer+2, q_11+477, 14*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_11+480, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+2, 30*DIGIT_SIZE_B);
	memcpy(q_11+445, recombine+0, 30*DIGIT_SIZE_B);
	
// Recombining results: n:3897, depth: 3
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, q_00+445, 30*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_00+448, 32, buffer);
	memcpy(buffer+2, q_01+445, 30*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_10+448, 32, buffer);
	gf2x_add(64, temp, 64, recombine, 64, temp);
	memcpy(recombine, temp+2, 62*DIGIT_SIZE_B);
	memcpy(q_00+381, recombine+1, 61*DIGIT_SIZE_B);
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, q_00+445, 30*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, buffer);
	memcpy(buffer+2, q_01+445, 30*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_11+448, 32, buffer);
	gf2x_add(64, temp, 64, recombine, 64, temp);
	memcpy(recombine, temp+2, 62*DIGIT_SIZE_B);
	memcpy(q_01+381, recombine+1, 61*DIGIT_SIZE_B);
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, q_10+445, 30*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_00+448, 32, buffer);
	memcpy(buffer+2, q_11+445, 30*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_10+448, 32, buffer);
	gf2x_add(64, temp, 64, recombine, 64, temp);
	memcpy(recombine, temp+2, 62*DIGIT_SIZE_B);
	memcpy(q_10+381, recombine+1, 61*DIGIT_SIZE_B);
	memset(buffer, 0x00, 2*DIGIT_SIZE_B);
	memcpy(buffer+2, q_10+445, 30*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, buffer);
	memcpy(buffer+2, q_11+445, 30*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_11+448, 32, buffer);
	gf2x_add(64, temp, 64, recombine, 64, temp);
	memcpy(recombine, temp+2, 62*DIGIT_SIZE_B);
	memcpy(q_11+381, recombine+1, 61*DIGIT_SIZE_B);
	
// Recombining results: n:7977, depth: 2
	memset(buffer, 0x00, 3*DIGIT_SIZE_B);
	memcpy(buffer+3, q_00+381, 61*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_00+384, 64, buffer);
	memcpy(buffer+3, q_01+381, 61*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, p_10+384, 64, buffer);
	gf2x_add(128, temp, 128, recombine, 128, temp);
	memcpy(recombine, temp+3, 125*DIGIT_SIZE_B);
	memcpy(q_00+253, recombine+0, 125*DIGIT_SIZE_B);
	memset(buffer, 0x00, 3*DIGIT_SIZE_B);
	memcpy(buffer+3, q_00+381, 61*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_01+384, 64, buffer);
	memcpy(buffer+3, q_01+381, 61*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, p_11+384, 64, buffer);
	gf2x_add(128, temp, 128, recombine, 128, temp);
	memcpy(recombine, temp+3, 125*DIGIT_SIZE_B);
	memcpy(q_01+253, recombine+0, 125*DIGIT_SIZE_B);
	memset(buffer, 0x00, 3*DIGIT_SIZE_B);
	memcpy(buffer+3, q_10+381, 61*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_00+384, 64, buffer);
	memcpy(buffer+3, q_11+381, 61*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, p_10+384, 64, buffer);
	gf2x_add(128, temp, 128, recombine, 128, temp);
	memcpy(recombine, temp+3, 125*DIGIT_SIZE_B);
	memcpy(q_10+253, recombine+0, 125*DIGIT_SIZE_B);
	memset(buffer, 0x00, 3*DIGIT_SIZE_B);
	memcpy(buffer+3, q_10+381, 61*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_01+384, 64, buffer);
	memcpy(buffer+3, q_11+381, 61*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, p_11+384, 64, buffer);
	gf2x_add(128, temp, 128, recombine, 128, temp);
	memcpy(recombine, temp+3, 125*DIGIT_SIZE_B);
	memcpy(q_11+253, recombine+0, 125*DIGIT_SIZE_B);
	
// Recombining results: n:16137, depth: 1
	memset(buffer, 0x00, 3*DIGIT_SIZE_B);
	memcpy(buffer+3, q_00+253, 125*DIGIT_SIZE_B);
	GF2X_MUL(256, recombine, 128, p_00+256, 128, buffer);
	memcpy(buffer+3, q_01+253, 125*DIGIT_SIZE_B);
	GF2X_MUL(256, temp, 128, p_10+256, 128, buffer);
	gf2x_add(256, temp, 256, recombine, 256, temp);
	memcpy(recombine, temp+3, 253*DIGIT_SIZE_B);
	memcpy(q_00+0, recombine+0, 253*DIGIT_SIZE_B);
	memset(buffer, 0x00, 3*DIGIT_SIZE_B);
	memcpy(buffer+3, q_00+253, 125*DIGIT_SIZE_B);
	GF2X_MUL(256, recombine, 128, p_01+256, 128, buffer);
	memcpy(buffer+3, q_01+253, 125*DIGIT_SIZE_B);
	GF2X_MUL(256, temp, 128, p_11+256, 128, buffer);
	gf2x_add(256, temp, 256, recombine, 256, temp);
	memcpy(recombine, temp+3, 253*DIGIT_SIZE_B);
	memcpy(q_01+0, recombine+0, 253*DIGIT_SIZE_B);
	memset(buffer, 0x00, 3*DIGIT_SIZE_B);
	memcpy(buffer+3, q_10+253, 125*DIGIT_SIZE_B);
	GF2X_MUL(256, recombine, 128, p_00+256, 128, buffer);
	memcpy(buffer+3, q_11+253, 125*DIGIT_SIZE_B);
	GF2X_MUL(256, temp, 128, p_10+256, 128, buffer);
	gf2x_add(256, temp, 256, recombine, 256, temp);
	memcpy(recombine, temp+3, 253*DIGIT_SIZE_B);
	memcpy(q_10+0, recombine+0, 253*DIGIT_SIZE_B);
	memset(buffer, 0x00, 3*DIGIT_SIZE_B);
	memcpy(buffer+3, q_10+253, 125*DIGIT_SIZE_B);
	GF2X_MUL(256, recombine, 128, p_01+256, 128, buffer);
	memcpy(buffer+3, q_11+253, 125*DIGIT_SIZE_B);
	GF2X_MUL(256, temp, 128, p_11+256, 128, buffer);
	gf2x_add(256, temp, 256, recombine, 256, temp);
	memcpy(recombine, temp+3, 253*DIGIT_SIZE_B);
	memcpy(q_11+0, recombine+0, 253*DIGIT_SIZE_B);
	
// Recombining results: n:32457, depth: 0
	memset(buffer, 0x00, 3*DIGIT_SIZE_B);
	memcpy(buffer+3, q_00+0, 253*DIGIT_SIZE_B);
	GF2X_MUL(512, recombine, 256, p_00+0, 256, buffer);
	memcpy(buffer+3, q_01+0, 253*DIGIT_SIZE_B);
	GF2X_MUL(512, temp, 256, p_10+0, 256, buffer);
	gf2x_add(512, temp, 512, recombine, 512, temp);
	memcpy(recombine, temp+3, 509*DIGIT_SIZE_B);
	memcpy(t_00+0, recombine+1, 508*DIGIT_SIZE_B);
	memset(buffer, 0x00, 3*DIGIT_SIZE_B);
	memcpy(buffer+3, q_00+0, 253*DIGIT_SIZE_B);
	GF2X_MUL(512, recombine, 256, p_01+0, 256, buffer);
	memcpy(buffer+3, q_01+0, 253*DIGIT_SIZE_B);
	GF2X_MUL(512, temp, 256, p_11+0, 256, buffer);
	gf2x_add(512, temp, 512, recombine, 512, temp);
	memcpy(recombine, temp+3, 509*DIGIT_SIZE_B);
	memcpy(t_01+0, recombine+1, 508*DIGIT_SIZE_B);
	memset(buffer, 0x00, 3*DIGIT_SIZE_B);
	memcpy(buffer+3, q_10+0, 253*DIGIT_SIZE_B);
	GF2X_MUL(512, recombine, 256, p_00+0, 256, buffer);
	memcpy(buffer+3, q_11+0, 253*DIGIT_SIZE_B);
	GF2X_MUL(512, temp, 256, p_10+0, 256, buffer);
	gf2x_add(512, temp, 512, recombine, 512, temp);
	memcpy(recombine, temp+3, 509*DIGIT_SIZE_B);
	memcpy(t_10+0, recombine+1, 508*DIGIT_SIZE_B);
	memset(buffer, 0x00, 3*DIGIT_SIZE_B);
	memcpy(buffer+3, q_10+0, 253*DIGIT_SIZE_B);
	GF2X_MUL(512, recombine, 256, p_01+0, 256, buffer);
	memcpy(buffer+3, q_11+0, 253*DIGIT_SIZE_B);
	GF2X_MUL(512, temp, 256, p_11+0, 256, buffer);
	gf2x_add(512, temp, 512, recombine, 512, temp);
	memcpy(recombine, temp+3, 509*DIGIT_SIZE_B);
	memcpy(t_11+0, recombine+1, 508*DIGIT_SIZE_B);
	return delta;
}