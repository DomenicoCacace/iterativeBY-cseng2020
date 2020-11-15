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

int jumpdivstep_8237(int n, int delta, int nf, DIGIT *f, DIGIT *g, DIGIT *t_00, DIGIT *t_01, DIGIT *t_10, DIGIT *t_11, float x) {
	DIGIT p_00[280];
	DIGIT p_01[280];
	DIGIT p_10[280];
	DIGIT p_11[280];
	
	DIGIT q_00[254];
	DIGIT q_01[254];
	DIGIT q_10[254];
	DIGIT q_11[254];
	
	DIGIT f_sum[814];
	DIGIT g_sum[814];
	
	DIGIT temp[522];
	DIGIT recombine[522];
	DIGIT temp2[522];
	DIGIT buffer[522];
	

	delta = divstepsx_256(255, delta, f+254, g+254, p_00+276, p_01+276, p_10+276, p_11+276);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+276, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f+250);
	memcpy(buffer+4, p_01+276, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g+250);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+802, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+276, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f+250);
	memcpy(buffer+4, p_11+276, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g+250);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+802, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+802, g_sum+802, q_00+250, q_01+250, q_10+250, q_11+250);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+276, 4, q_00+250);
	GF2X_MUL(8, temp, 4, p_10+276, 4, q_01+250);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+268, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+276, 4, q_00+250);
	GF2X_MUL(8, temp, 4, p_11+276, 4, q_01+250);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+268, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+276, 4, q_10+250);
	GF2X_MUL(8, temp, 4, p_10+276, 4, q_11+250);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+268, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+276, 4, q_10+250);
	GF2X_MUL(8, temp, 4, p_11+276, 4, q_11+250);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+268, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:765, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp2, 12, buffer, 12, f+246);
	memcpy(buffer+4, p_01+268, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, buffer, 12, g+246);
	gf2x_add(24, temp, 24, temp2, 24, temp);
	memcpy(temp2, temp+4, 20*DIGIT_SIZE_B);
	right_bit_shift_wide_n(20, temp2, 510);
	memcpy(f_sum+782, temp2+16, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp2, 12, buffer, 12, f+246);
	memcpy(buffer+4, p_11+268, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, buffer, 12, g+246);
	gf2x_add(24, temp, 24, temp2, 24, temp);
	memcpy(temp2, temp+4, 20*DIGIT_SIZE_B);
	right_bit_shift_wide_n(20, temp2, 510);
	memcpy(g_sum+782, temp2+16, 12*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:765, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+246, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+268, 8, buffer);
	memcpy(buffer+4, q_01+246, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_10+268, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(p_00+256, recombine+0, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+246, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+268, 8, buffer);
	memcpy(buffer+4, q_01+246, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_11+268, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(p_01+256, recombine+0, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+246, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+268, 8, buffer);
	memcpy(buffer+4, q_11+246, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_10+268, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(p_10+256, recombine+0, 12*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+246, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+268, 8, buffer);
	memcpy(buffer+4, q_11+246, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_11+268, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+4, 12*DIGIT_SIZE_B);
	memcpy(p_11+256, recombine+0, 12*DIGIT_SIZE_B);
	
// Calculating left operands: n:1275, depth: 4
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+256, 12*DIGIT_SIZE_B);
	GF2X_MUL(40, temp2, 20, buffer, 20, f+238);
	memcpy(buffer+8, p_01+256, 12*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, buffer, 20, g+238);
	gf2x_add(40, temp, 40, temp2, 40, temp);
	memcpy(temp2, temp+8, 32*DIGIT_SIZE_B);
	right_bit_shift_wide_n(32, temp2, 765);
	memcpy(f_sum+750, temp2+24, 20*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+256, 12*DIGIT_SIZE_B);
	GF2X_MUL(40, temp2, 20, buffer, 20, f+238);
	memcpy(buffer+8, p_11+256, 12*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, buffer, 20, g+238);
	gf2x_add(40, temp, 40, temp2, 40, temp);
	memcpy(temp2, temp+8, 32*DIGIT_SIZE_B);
	right_bit_shift_wide_n(32, temp2, 765);
	memcpy(g_sum+750, temp2+24, 20*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+754, g_sum+754, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+238, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1275, depth: 4
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+238, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, recombine, 12, p_00+256, 12, buffer);
	memcpy(buffer+4, q_01+238, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_10+256, 12, buffer);
	gf2x_add(24, temp, 24, recombine, 24, temp);
	memcpy(recombine, temp+4, 20*DIGIT_SIZE_B);
	memcpy(p_00+236, recombine+0, 20*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+238, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, recombine, 12, p_01+256, 12, buffer);
	memcpy(buffer+4, q_01+238, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_11+256, 12, buffer);
	gf2x_add(24, temp, 24, recombine, 24, temp);
	memcpy(recombine, temp+4, 20*DIGIT_SIZE_B);
	memcpy(p_01+236, recombine+0, 20*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+238, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, recombine, 12, p_00+256, 12, buffer);
	memcpy(buffer+4, q_11+238, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_10+256, 12, buffer);
	gf2x_add(24, temp, 24, recombine, 24, temp);
	memcpy(recombine, temp+4, 20*DIGIT_SIZE_B);
	memcpy(p_10+236, recombine+0, 20*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+238, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, recombine, 12, p_01+256, 12, buffer);
	memcpy(buffer+4, q_11+238, 8*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_11+256, 12, buffer);
	gf2x_add(24, temp, 24, recombine, 24, temp);
	memcpy(recombine, temp+4, 20*DIGIT_SIZE_B);
	memcpy(p_11+236, recombine+0, 20*DIGIT_SIZE_B);
	
// Calculating left operands: n:2295, depth: 3
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+236, 20*DIGIT_SIZE_B);
	GF2X_MUL(72, temp2, 36, buffer, 36, f+222);
	memcpy(buffer+16, p_01+236, 20*DIGIT_SIZE_B);
	GF2X_MUL(72, temp, 36, buffer, 36, g+222);
	gf2x_add(72, temp, 72, temp2, 72, temp);
	memcpy(temp2, temp+16, 56*DIGIT_SIZE_B);
	right_bit_shift_wide_n(56, temp2, 1275);
	memcpy(f_sum+694, temp2+40, 36*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+236, 20*DIGIT_SIZE_B);
	GF2X_MUL(72, temp2, 36, buffer, 36, f+222);
	memcpy(buffer+16, p_11+236, 20*DIGIT_SIZE_B);
	GF2X_MUL(72, temp, 36, buffer, 36, g+222);
	gf2x_add(72, temp, 72, temp2, 72, temp);
	memcpy(temp2, temp+16, 56*DIGIT_SIZE_B);
	right_bit_shift_wide_n(56, temp2, 1275);
	memcpy(g_sum+694, temp2+40, 36*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+706, g_sum+706, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+702);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+702);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+702);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+702);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+256, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 4
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+694);
	memcpy(buffer+8, p_01+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+694);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+694);
	memcpy(buffer+8, p_11+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+694);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+754, g_sum+754, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+238, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 4
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+222, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+222, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+222, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+222, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2295, depth: 3
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+222, 16*DIGIT_SIZE_B);
	GF2X_MUL(40, recombine, 20, p_00+236, 20, buffer);
	memcpy(buffer+4, q_01+222, 16*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_10+236, 20, buffer);
	gf2x_add(40, temp, 40, recombine, 40, temp);
	memcpy(recombine, temp+4, 36*DIGIT_SIZE_B);
	memcpy(p_00+200, recombine+0, 36*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+222, 16*DIGIT_SIZE_B);
	GF2X_MUL(40, recombine, 20, p_01+236, 20, buffer);
	memcpy(buffer+4, q_01+222, 16*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_11+236, 20, buffer);
	gf2x_add(40, temp, 40, recombine, 40, temp);
	memcpy(recombine, temp+4, 36*DIGIT_SIZE_B);
	memcpy(p_01+200, recombine+0, 36*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+222, 16*DIGIT_SIZE_B);
	GF2X_MUL(40, recombine, 20, p_00+236, 20, buffer);
	memcpy(buffer+4, q_11+222, 16*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_10+236, 20, buffer);
	gf2x_add(40, temp, 40, recombine, 40, temp);
	memcpy(recombine, temp+4, 36*DIGIT_SIZE_B);
	memcpy(p_10+200, recombine+0, 36*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+222, 16*DIGIT_SIZE_B);
	GF2X_MUL(40, recombine, 20, p_01+236, 20, buffer);
	memcpy(buffer+4, q_11+222, 16*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_11+236, 20, buffer);
	gf2x_add(40, temp, 40, recombine, 40, temp);
	memcpy(recombine, temp+4, 36*DIGIT_SIZE_B);
	memcpy(p_11+200, recombine+0, 36*DIGIT_SIZE_B);
	
// Calculating left operands: n:4335, depth: 2
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_00+200, 36*DIGIT_SIZE_B);
	GF2X_MUL(136, temp2, 68, buffer, 68, f+190);
	memcpy(buffer+32, p_01+200, 36*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, buffer, 68, g+190);
	gf2x_add(136, temp, 136, temp2, 136, temp);
	memcpy(temp2, temp+32, 104*DIGIT_SIZE_B);
	right_bit_shift_wide_n(104, temp2, 2295);
	memcpy(f_sum+590, temp2+72, 68*DIGIT_SIZE_B);
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_10+200, 36*DIGIT_SIZE_B);
	GF2X_MUL(136, temp2, 68, buffer, 68, f+190);
	memcpy(buffer+32, p_11+200, 36*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, buffer, 68, g+190);
	gf2x_add(136, temp, 136, temp2, 136, temp);
	memcpy(temp2, temp+32, 104*DIGIT_SIZE_B);
	right_bit_shift_wide_n(104, temp2, 2295);
	memcpy(g_sum+590, temp2+72, 68*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+618, g_sum+618, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+614);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+614);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+614);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+614);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+256, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 4
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+606);
	memcpy(buffer+8, p_01+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+606);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+606);
	memcpy(buffer+8, p_11+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+606);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+754, g_sum+754, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+238, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 4
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+236, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+236, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+236, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+236, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 3
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+590);
	memcpy(buffer+16, p_01+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+590);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+694, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+590);
	memcpy(buffer+16, p_11+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+590);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+694, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+706, g_sum+706, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+702);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+702);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+702);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+702);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+256, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 4
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+694);
	memcpy(buffer+8, p_01+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+694);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+694);
	memcpy(buffer+8, p_11+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+694);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+754, g_sum+754, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+238, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 4
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+222, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+222, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+222, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+222, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 3
	GF2X_MUL(32, recombine, 16, p_00+236, 16, q_00+222);
	GF2X_MUL(32, temp, 16, p_10+236, 16, q_01+222);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_00+190, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+236, 16, q_00+222);
	GF2X_MUL(32, temp, 16, p_11+236, 16, q_01+222);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_01+190, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+236, 16, q_10+222);
	GF2X_MUL(32, temp, 16, p_10+236, 16, q_11+222);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_10+190, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+236, 16, q_10+222);
	GF2X_MUL(32, temp, 16, p_11+236, 16, q_11+222);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_11+190, recombine+0, 32*DIGIT_SIZE_B);
	
// Recombining results: n:4335, depth: 2
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+190, 32*DIGIT_SIZE_B);
	GF2X_MUL(72, recombine, 36, p_00+200, 36, buffer);
	memcpy(buffer+4, q_01+190, 32*DIGIT_SIZE_B);
	GF2X_MUL(72, temp, 36, p_10+200, 36, buffer);
	gf2x_add(72, temp, 72, recombine, 72, temp);
	memcpy(recombine, temp+4, 68*DIGIT_SIZE_B);
	memcpy(p_00+132, recombine+0, 68*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+190, 32*DIGIT_SIZE_B);
	GF2X_MUL(72, recombine, 36, p_01+200, 36, buffer);
	memcpy(buffer+4, q_01+190, 32*DIGIT_SIZE_B);
	GF2X_MUL(72, temp, 36, p_11+200, 36, buffer);
	gf2x_add(72, temp, 72, recombine, 72, temp);
	memcpy(recombine, temp+4, 68*DIGIT_SIZE_B);
	memcpy(p_01+132, recombine+0, 68*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+190, 32*DIGIT_SIZE_B);
	GF2X_MUL(72, recombine, 36, p_00+200, 36, buffer);
	memcpy(buffer+4, q_11+190, 32*DIGIT_SIZE_B);
	GF2X_MUL(72, temp, 36, p_10+200, 36, buffer);
	gf2x_add(72, temp, 72, recombine, 72, temp);
	memcpy(recombine, temp+4, 68*DIGIT_SIZE_B);
	memcpy(p_10+132, recombine+0, 68*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+190, 32*DIGIT_SIZE_B);
	GF2X_MUL(72, recombine, 36, p_01+200, 36, buffer);
	memcpy(buffer+4, q_11+190, 32*DIGIT_SIZE_B);
	GF2X_MUL(72, temp, 36, p_11+200, 36, buffer);
	gf2x_add(72, temp, 72, recombine, 72, temp);
	memcpy(recombine, temp+4, 68*DIGIT_SIZE_B);
	memcpy(p_11+132, recombine+0, 68*DIGIT_SIZE_B);
	
// Calculating left operands: n:8415, depth: 1
	memset(buffer, 0x00, 64*DIGIT_SIZE_B);
	memcpy(buffer+64, p_00+132, 68*DIGIT_SIZE_B);
	GF2X_MUL(264, temp2, 132, buffer, 132, f+126);
	memcpy(buffer+64, p_01+132, 68*DIGIT_SIZE_B);
	GF2X_MUL(264, temp, 132, buffer, 132, g+126);
	gf2x_add(264, temp, 264, temp2, 264, temp);
	memcpy(temp2, temp+64, 200*DIGIT_SIZE_B);
	right_bit_shift_wide_n(200, temp2, 4335);
	memcpy(f_sum+390, temp2+136, 132*DIGIT_SIZE_B);
	memset(buffer, 0x00, 64*DIGIT_SIZE_B);
	memcpy(buffer+64, p_10+132, 68*DIGIT_SIZE_B);
	GF2X_MUL(264, temp2, 132, buffer, 132, f+126);
	memcpy(buffer+64, p_11+132, 68*DIGIT_SIZE_B);
	GF2X_MUL(264, temp, 132, buffer, 132, g+126);
	gf2x_add(264, temp, 264, temp2, 264, temp);
	memcpy(temp2, temp+64, 200*DIGIT_SIZE_B);
	right_bit_shift_wide_n(200, temp2, 4335);
	memcpy(g_sum+390, temp2+136, 132*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+450, g_sum+450, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+446);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+446);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+446);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+446);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+256, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 4
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+438);
	memcpy(buffer+8, p_01+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+438);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+438);
	memcpy(buffer+8, p_11+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+438);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+754, g_sum+754, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+238, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 4
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+236, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+236, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+236, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+236, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 3
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+422);
	memcpy(buffer+16, p_01+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+422);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+694, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+422);
	memcpy(buffer+16, p_11+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+422);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+694, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+706, g_sum+706, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+702);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+702);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+702);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+702);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+256, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 4
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+694);
	memcpy(buffer+8, p_01+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+694);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+694);
	memcpy(buffer+8, p_11+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+694);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+754, g_sum+754, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+238, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 4
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+222, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+222, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+222, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+222, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 3
	GF2X_MUL(32, recombine, 16, p_00+236, 16, q_00+222);
	GF2X_MUL(32, temp, 16, p_10+236, 16, q_01+222);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_00+200, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+236, 16, q_00+222);
	GF2X_MUL(32, temp, 16, p_11+236, 16, q_01+222);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_01+200, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+236, 16, q_10+222);
	GF2X_MUL(32, temp, 16, p_10+236, 16, q_11+222);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_10+200, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+236, 16, q_10+222);
	GF2X_MUL(32, temp, 16, p_11+236, 16, q_11+222);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_11+200, recombine+0, 32*DIGIT_SIZE_B);
	
// Calculating left operands: n:4080, depth: 2
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_00+200, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+390);
	memcpy(buffer+32, p_01+200, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+390);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(f_sum+590, temp2+64, 64*DIGIT_SIZE_B);
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_10+200, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+390);
	memcpy(buffer+32, p_11+200, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+390);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(g_sum+590, temp2+64, 64*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+618, g_sum+618, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+614);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+614);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+614);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+614);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+256, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 4
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+606);
	memcpy(buffer+8, p_01+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+606);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+606);
	memcpy(buffer+8, p_11+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+606);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+754, g_sum+754, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+238, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 4
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+236, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+236, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+236, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+236, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 3
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+590);
	memcpy(buffer+16, p_01+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+590);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+694, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+590);
	memcpy(buffer+16, p_11+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+590);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+694, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+706, g_sum+706, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+702);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+702);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+702);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+702);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+256, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 4
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+694);
	memcpy(buffer+8, p_01+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+694);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+694);
	memcpy(buffer+8, p_11+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+694);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+754, g_sum+754, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+238, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 4
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+222, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+222, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+222, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+222, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 3
	GF2X_MUL(32, recombine, 16, p_00+236, 16, q_00+222);
	GF2X_MUL(32, temp, 16, p_10+236, 16, q_01+222);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_00+190, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+236, 16, q_00+222);
	GF2X_MUL(32, temp, 16, p_11+236, 16, q_01+222);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_01+190, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+236, 16, q_10+222);
	GF2X_MUL(32, temp, 16, p_10+236, 16, q_11+222);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_10+190, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+236, 16, q_10+222);
	GF2X_MUL(32, temp, 16, p_11+236, 16, q_11+222);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_11+190, recombine+0, 32*DIGIT_SIZE_B);
	
// Recombining results: n:4080, depth: 2
	GF2X_MUL(64, recombine, 32, p_00+200, 32, q_00+190);
	GF2X_MUL(64, temp, 32, p_10+200, 32, q_01+190);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_00+126, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+200, 32, q_00+190);
	GF2X_MUL(64, temp, 32, p_11+200, 32, q_01+190);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_01+126, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_00+200, 32, q_10+190);
	GF2X_MUL(64, temp, 32, p_10+200, 32, q_11+190);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_10+126, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+200, 32, q_10+190);
	GF2X_MUL(64, temp, 32, p_11+200, 32, q_11+190);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_11+126, recombine+0, 64*DIGIT_SIZE_B);
	
// Recombining results: n:8415, depth: 1
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+126, 64*DIGIT_SIZE_B);
	GF2X_MUL(136, recombine, 68, p_00+132, 68, buffer);
	memcpy(buffer+4, q_01+126, 64*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_10+132, 68, buffer);
	gf2x_add(136, temp, 136, recombine, 136, temp);
	memcpy(recombine, temp+4, 132*DIGIT_SIZE_B);
	memcpy(p_00+0, recombine+0, 132*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_00+126, 64*DIGIT_SIZE_B);
	GF2X_MUL(136, recombine, 68, p_01+132, 68, buffer);
	memcpy(buffer+4, q_01+126, 64*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_11+132, 68, buffer);
	gf2x_add(136, temp, 136, recombine, 136, temp);
	memcpy(recombine, temp+4, 132*DIGIT_SIZE_B);
	memcpy(p_01+0, recombine+0, 132*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+126, 64*DIGIT_SIZE_B);
	GF2X_MUL(136, recombine, 68, p_00+132, 68, buffer);
	memcpy(buffer+4, q_11+126, 64*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_10+132, 68, buffer);
	gf2x_add(136, temp, 136, recombine, 136, temp);
	memcpy(recombine, temp+4, 132*DIGIT_SIZE_B);
	memcpy(p_10+0, recombine+0, 132*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, q_10+126, 64*DIGIT_SIZE_B);
	GF2X_MUL(136, recombine, 68, p_01+132, 68, buffer);
	memcpy(buffer+4, q_11+126, 64*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_11+132, 68, buffer);
	gf2x_add(136, temp, 136, recombine, 136, temp);
	memcpy(recombine, temp+4, 132*DIGIT_SIZE_B);
	memcpy(p_11+0, recombine+0, 132*DIGIT_SIZE_B);
	
// Calculating left operands: n:16473, depth: 0
	memset(buffer, 0x00, 126*DIGIT_SIZE_B);
	memcpy(buffer+126, p_00+0, 132*DIGIT_SIZE_B);
	GF2X_MUL(516, temp2, 258, buffer, 258, f+0);
	memcpy(buffer+126, p_01+0, 132*DIGIT_SIZE_B);
	GF2X_MUL(516, temp, 258, buffer, 258, g+0);
	gf2x_add(516, temp, 516, temp2, 516, temp);
	memcpy(temp2, temp+126, 390*DIGIT_SIZE_B);
	right_bit_shift_wide_n(390, temp2, 8415);
	memcpy(f_sum+0, temp2+264, 258*DIGIT_SIZE_B);
	memset(buffer, 0x00, 126*DIGIT_SIZE_B);
	memcpy(buffer+126, p_10+0, 132*DIGIT_SIZE_B);
	GF2X_MUL(516, temp2, 258, buffer, 258, f+0);
	memcpy(buffer+126, p_11+0, 132*DIGIT_SIZE_B);
	GF2X_MUL(516, temp, 258, buffer, 258, g+0);
	gf2x_add(516, temp, 516, temp2, 516, temp);
	memcpy(temp2, temp+126, 390*DIGIT_SIZE_B);
	right_bit_shift_wide_n(390, temp2, 8415);
	memcpy(g_sum+0, temp2+264, 258*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+122, g_sum+122, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+118);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+118);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+118);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+118);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+256, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 4
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+110);
	memcpy(buffer+8, p_01+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+110);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+110);
	memcpy(buffer+8, p_11+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+110);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+754, g_sum+754, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+238, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 4
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+236, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+236, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+236, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+236, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 3
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+94);
	memcpy(buffer+16, p_01+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+94);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+694, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+94);
	memcpy(buffer+16, p_11+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+94);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+694, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+706, g_sum+706, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+702);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+702);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+702);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+702);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+256, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 4
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+694);
	memcpy(buffer+8, p_01+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+694);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+694);
	memcpy(buffer+8, p_11+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+694);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+754, g_sum+754, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+238, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 4
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+222, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+222, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+222, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+222, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 3
	GF2X_MUL(32, recombine, 16, p_00+236, 16, q_00+222);
	GF2X_MUL(32, temp, 16, p_10+236, 16, q_01+222);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_00+200, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+236, 16, q_00+222);
	GF2X_MUL(32, temp, 16, p_11+236, 16, q_01+222);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_01+200, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+236, 16, q_10+222);
	GF2X_MUL(32, temp, 16, p_10+236, 16, q_11+222);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_10+200, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+236, 16, q_10+222);
	GF2X_MUL(32, temp, 16, p_11+236, 16, q_11+222);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_11+200, recombine+0, 32*DIGIT_SIZE_B);
	
// Calculating left operands: n:4080, depth: 2
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_00+200, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+62);
	memcpy(buffer+32, p_01+200, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+62);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(f_sum+590, temp2+64, 64*DIGIT_SIZE_B);
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_10+200, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+62);
	memcpy(buffer+32, p_11+200, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+62);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(g_sum+590, temp2+64, 64*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+618, g_sum+618, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+614);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+614);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+614);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+614);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+256, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 4
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+606);
	memcpy(buffer+8, p_01+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+606);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+606);
	memcpy(buffer+8, p_11+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+606);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+754, g_sum+754, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+238, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 4
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+236, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+236, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+236, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+236, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 3
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+590);
	memcpy(buffer+16, p_01+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+590);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+694, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+590);
	memcpy(buffer+16, p_11+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+590);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+694, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+706, g_sum+706, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+702);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+702);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+702);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+702);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+256, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 4
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+694);
	memcpy(buffer+8, p_01+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+694);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+694);
	memcpy(buffer+8, p_11+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+694);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+754, g_sum+754, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+238, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 4
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+222, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+222, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+222, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+222, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 3
	GF2X_MUL(32, recombine, 16, p_00+236, 16, q_00+222);
	GF2X_MUL(32, temp, 16, p_10+236, 16, q_01+222);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_00+190, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+236, 16, q_00+222);
	GF2X_MUL(32, temp, 16, p_11+236, 16, q_01+222);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_01+190, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+236, 16, q_10+222);
	GF2X_MUL(32, temp, 16, p_10+236, 16, q_11+222);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_10+190, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+236, 16, q_10+222);
	GF2X_MUL(32, temp, 16, p_11+236, 16, q_11+222);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_11+190, recombine+0, 32*DIGIT_SIZE_B);
	
// Recombining results: n:4080, depth: 2
	GF2X_MUL(64, recombine, 32, p_00+200, 32, q_00+190);
	GF2X_MUL(64, temp, 32, p_10+200, 32, q_01+190);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_00+132, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+200, 32, q_00+190);
	GF2X_MUL(64, temp, 32, p_11+200, 32, q_01+190);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_01+132, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_00+200, 32, q_10+190);
	GF2X_MUL(64, temp, 32, p_10+200, 32, q_11+190);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_10+132, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+200, 32, q_10+190);
	GF2X_MUL(64, temp, 32, p_11+200, 32, q_11+190);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_11+132, recombine+0, 64*DIGIT_SIZE_B);
	
// Calculating left operands: n:8058, depth: 1
	memset(buffer, 0x00, 62*DIGIT_SIZE_B);
	memcpy(buffer+62, p_00+132, 64*DIGIT_SIZE_B);
	GF2X_MUL(252, temp2, 126, buffer, 126, f_sum+0);
	memcpy(buffer+62, p_01+132, 64*DIGIT_SIZE_B);
	GF2X_MUL(252, temp, 126, buffer, 126, g_sum+0);
	gf2x_add(252, temp, 252, temp2, 252, temp);
	memcpy(temp2, temp+62, 190*DIGIT_SIZE_B);
	right_bit_shift_wide_n(190, temp2, 4080);
	memcpy(f_sum+390, temp2+127, 126*DIGIT_SIZE_B);
	memset(buffer, 0x00, 62*DIGIT_SIZE_B);
	memcpy(buffer+62, p_10+132, 64*DIGIT_SIZE_B);
	GF2X_MUL(252, temp2, 126, buffer, 126, f_sum+0);
	memcpy(buffer+62, p_11+132, 64*DIGIT_SIZE_B);
	GF2X_MUL(252, temp, 126, buffer, 126, g_sum+0);
	gf2x_add(252, temp, 252, temp2, 252, temp);
	memcpy(temp2, temp+62, 190*DIGIT_SIZE_B);
	right_bit_shift_wide_n(190, temp2, 4080);
	memcpy(g_sum+390, temp2+127, 126*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+449, g_sum+449, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+445);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+445);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+445);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+445);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+256, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 4
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+437);
	memcpy(buffer+8, p_01+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+437);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+437);
	memcpy(buffer+8, p_11+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+437);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+754, g_sum+754, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+238, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 4
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+236, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+236, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+236, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+236, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 3
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+421);
	memcpy(buffer+16, p_01+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+421);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+694, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+421);
	memcpy(buffer+16, p_11+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+421);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+694, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+706, g_sum+706, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+702);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+702);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+702);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+702);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+256, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 4
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+694);
	memcpy(buffer+8, p_01+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+694);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+694);
	memcpy(buffer+8, p_11+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+694);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+754, g_sum+754, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+238, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 4
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+222, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+222, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+222, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+222, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 3
	GF2X_MUL(32, recombine, 16, p_00+236, 16, q_00+222);
	GF2X_MUL(32, temp, 16, p_10+236, 16, q_01+222);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_00+200, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+236, 16, q_00+222);
	GF2X_MUL(32, temp, 16, p_11+236, 16, q_01+222);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_01+200, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+236, 16, q_10+222);
	GF2X_MUL(32, temp, 16, p_10+236, 16, q_11+222);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_10+200, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+236, 16, q_10+222);
	GF2X_MUL(32, temp, 16, p_11+236, 16, q_11+222);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_11+200, recombine+0, 32*DIGIT_SIZE_B);
	
// Calculating left operands: n:3978, depth: 2
	memset(buffer, 0x00, 31*DIGIT_SIZE_B);
	memcpy(buffer+31, p_00+200, 32*DIGIT_SIZE_B);
	GF2X_MUL(126, temp2, 63, buffer, 63, f_sum+390);
	memcpy(buffer+31, p_01+200, 32*DIGIT_SIZE_B);
	GF2X_MUL(126, temp, 63, buffer, 63, g_sum+390);
	gf2x_add(126, temp, 126, temp2, 126, temp);
	memcpy(temp2, temp+31, 95*DIGIT_SIZE_B);
	right_bit_shift_wide_n(95, temp2, 2040);
	memcpy(f_sum+590, temp2+64, 63*DIGIT_SIZE_B);
	memset(buffer, 0x00, 31*DIGIT_SIZE_B);
	memcpy(buffer+31, p_10+200, 32*DIGIT_SIZE_B);
	GF2X_MUL(126, temp2, 63, buffer, 63, f_sum+390);
	memcpy(buffer+31, p_11+200, 32*DIGIT_SIZE_B);
	GF2X_MUL(126, temp, 63, buffer, 63, g_sum+390);
	gf2x_add(126, temp, 126, temp2, 126, temp);
	memcpy(temp2, temp+31, 95*DIGIT_SIZE_B);
	right_bit_shift_wide_n(95, temp2, 2040);
	memcpy(g_sum+590, temp2+64, 63*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+617, g_sum+617, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+613);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+613);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+613);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+613);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+256, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 4
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+605);
	memcpy(buffer+8, p_01+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+605);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+605);
	memcpy(buffer+8, p_11+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+605);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+750, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+754, g_sum+754, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+750);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+750);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+238, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+238, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 4
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+236, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_00+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_01+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+236, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_10+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+236, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, q_10+238);
	GF2X_MUL(16, temp, 8, p_11+256, 8, q_11+238);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+236, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:1938, depth: 3
	memset(buffer, 0x00, 15*DIGIT_SIZE_B);
	memcpy(buffer+15, p_00+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(62, temp2, 31, buffer, 31, f_sum+590);
	memcpy(buffer+15, p_01+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(62, temp, 31, buffer, 31, g_sum+590);
	gf2x_add(62, temp, 62, temp2, 62, temp);
	memcpy(temp2, temp+15, 47*DIGIT_SIZE_B);
	right_bit_shift_wide_n(47, temp2, 1020);
	memcpy(f_sum+694, temp2+32, 31*DIGIT_SIZE_B);
	memset(buffer, 0x00, 15*DIGIT_SIZE_B);
	memcpy(buffer+15, p_10+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(62, temp2, 31, buffer, 31, f_sum+590);
	memcpy(buffer+15, p_11+236, 16*DIGIT_SIZE_B);
	GF2X_MUL(62, temp, 31, buffer, 31, g_sum+590);
	gf2x_add(62, temp, 62, temp2, 62, temp);
	memcpy(temp2, temp+15, 47*DIGIT_SIZE_B);
	right_bit_shift_wide_n(47, temp2, 1020);
	memcpy(g_sum+694, temp2+32, 31*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+705, g_sum+705, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:510, depth: 5
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+701);
	memcpy(buffer+4, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+701);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+701);
	memcpy(buffer+4, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+701);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+782, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246);
	
// Recombining results: n:510, depth: 5
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_00+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_01+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_10+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+256, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, q_10+246);
	GF2X_MUL(8, temp, 4, p_11+268, 4, q_11+246);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+256, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:918, depth: 4
	memset(buffer, 0x00, 7*DIGIT_SIZE_B);
	memcpy(buffer+7, p_00+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(30, temp2, 15, buffer, 15, f_sum+694);
	memcpy(buffer+7, p_01+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(30, temp, 15, buffer, 15, g_sum+694);
	gf2x_add(30, temp, 30, temp2, 30, temp);
	memcpy(temp2, temp+7, 23*DIGIT_SIZE_B);
	right_bit_shift_wide_n(23, temp2, 510);
	memcpy(f_sum+750, temp2+16, 15*DIGIT_SIZE_B);
	memset(buffer, 0x00, 7*DIGIT_SIZE_B);
	memcpy(buffer+7, p_10+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(30, temp2, 15, buffer, 15, f_sum+694);
	memcpy(buffer+7, p_11+256, 8*DIGIT_SIZE_B);
	GF2X_MUL(30, temp, 15, buffer, 15, g_sum+694);
	gf2x_add(30, temp, 30, temp2, 30, temp);
	memcpy(temp2, temp+7, 23*DIGIT_SIZE_B);
	right_bit_shift_wide_n(23, temp2, 510);
	memcpy(g_sum+750, temp2+16, 15*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+753, g_sum+753, p_00+268, p_01+268, p_10+268, p_11+268);
	
// Calculating left operands: n:408, depth: 5
	memset(buffer, 0x00, 3*DIGIT_SIZE_B);
	memcpy(buffer+3, p_00+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(14, temp2, 7, buffer, 7, f_sum+750);
	memcpy(buffer+3, p_01+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(14, temp, 7, buffer, 7, g_sum+750);
	gf2x_add(14, temp, 14, temp2, 14, temp);
	memcpy(temp2, temp+3, 11*DIGIT_SIZE_B);
	right_bit_shift_wide_n(11, temp2, 255);
	memcpy(f_sum+782, temp2+8, 7*DIGIT_SIZE_B);
	memset(buffer, 0x00, 3*DIGIT_SIZE_B);
	memcpy(buffer+3, p_10+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(14, temp2, 7, buffer, 7, f_sum+750);
	memcpy(buffer+3, p_11+268, 4*DIGIT_SIZE_B);
	GF2X_MUL(14, temp, 7, buffer, 7, g_sum+750);
	gf2x_add(14, temp, 14, temp2, 14, temp);
	memcpy(temp2, temp+3, 11*DIGIT_SIZE_B);
	right_bit_shift_wide_n(11, temp2, 255);
	memcpy(g_sum+782, temp2+8, 7*DIGIT_SIZE_B);
	delta = support_jumpdivstep(153, delta, 3, f_sum+782, g_sum+782, q_00+246, q_01+246, q_10+246, q_11+246, x);
	
// Recombining results: n:408, depth: 5
	memset(buffer, 0x00, 1*DIGIT_SIZE_B);
	memcpy(buffer+1, q_00+246, 3*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, buffer);
	memcpy(buffer+1, q_01+246, 3*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_10+268, 4, buffer);
	gf2x_add(8, temp, 8, recombine, 8, temp);
	memcpy(recombine, temp+1, 7*DIGIT_SIZE_B);
	memcpy(q_00+238, recombine+0, 7*DIGIT_SIZE_B);
	memset(buffer, 0x00, 1*DIGIT_SIZE_B);
	memcpy(buffer+1, q_00+246, 3*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, buffer);
	memcpy(buffer+1, q_01+246, 3*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_11+268, 4, buffer);
	gf2x_add(8, temp, 8, recombine, 8, temp);
	memcpy(recombine, temp+1, 7*DIGIT_SIZE_B);
	memcpy(q_01+238, recombine+0, 7*DIGIT_SIZE_B);
	memset(buffer, 0x00, 1*DIGIT_SIZE_B);
	memcpy(buffer+1, q_10+246, 3*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+268, 4, buffer);
	memcpy(buffer+1, q_11+246, 3*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_10+268, 4, buffer);
	gf2x_add(8, temp, 8, recombine, 8, temp);
	memcpy(recombine, temp+1, 7*DIGIT_SIZE_B);
	memcpy(q_10+238, recombine+0, 7*DIGIT_SIZE_B);
	memset(buffer, 0x00, 1*DIGIT_SIZE_B);
	memcpy(buffer+1, q_10+246, 3*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+268, 4, buffer);
	memcpy(buffer+1, q_11+246, 3*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_11+268, 4, buffer);
	gf2x_add(8, temp, 8, recombine, 8, temp);
	memcpy(recombine, temp+1, 7*DIGIT_SIZE_B);
	memcpy(q_11+238, recombine+0, 7*DIGIT_SIZE_B);
	
// Recombining results: n:918, depth: 4
	memset(buffer, 0x00, 1*DIGIT_SIZE_B);
	memcpy(buffer+1, q_00+238, 7*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+256, 8, buffer);
	memcpy(buffer+1, q_01+238, 7*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_10+256, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+1, 15*DIGIT_SIZE_B);
	memcpy(q_00+222, recombine+0, 15*DIGIT_SIZE_B);
	memset(buffer, 0x00, 1*DIGIT_SIZE_B);
	memcpy(buffer+1, q_00+238, 7*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, buffer);
	memcpy(buffer+1, q_01+238, 7*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_11+256, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+1, 15*DIGIT_SIZE_B);
	memcpy(q_01+222, recombine+0, 15*DIGIT_SIZE_B);
	memset(buffer, 0x00, 1*DIGIT_SIZE_B);
	memcpy(buffer+1, q_10+238, 7*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+256, 8, buffer);
	memcpy(buffer+1, q_11+238, 7*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_10+256, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+1, 15*DIGIT_SIZE_B);
	memcpy(q_10+222, recombine+0, 15*DIGIT_SIZE_B);
	memset(buffer, 0x00, 1*DIGIT_SIZE_B);
	memcpy(buffer+1, q_10+238, 7*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+256, 8, buffer);
	memcpy(buffer+1, q_11+238, 7*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_11+256, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+1, 15*DIGIT_SIZE_B);
	memcpy(q_11+222, recombine+0, 15*DIGIT_SIZE_B);
	
// Recombining results: n:1938, depth: 3
	memset(buffer, 0x00, 1*DIGIT_SIZE_B);
	memcpy(buffer+1, q_00+222, 15*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+236, 16, buffer);
	memcpy(buffer+1, q_01+222, 15*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_10+236, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+1, 31*DIGIT_SIZE_B);
	memcpy(q_00+190, recombine+0, 31*DIGIT_SIZE_B);
	memset(buffer, 0x00, 1*DIGIT_SIZE_B);
	memcpy(buffer+1, q_00+222, 15*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+236, 16, buffer);
	memcpy(buffer+1, q_01+222, 15*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_11+236, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+1, 31*DIGIT_SIZE_B);
	memcpy(q_01+190, recombine+0, 31*DIGIT_SIZE_B);
	memset(buffer, 0x00, 1*DIGIT_SIZE_B);
	memcpy(buffer+1, q_10+222, 15*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+236, 16, buffer);
	memcpy(buffer+1, q_11+222, 15*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_10+236, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+1, 31*DIGIT_SIZE_B);
	memcpy(q_10+190, recombine+0, 31*DIGIT_SIZE_B);
	memset(buffer, 0x00, 1*DIGIT_SIZE_B);
	memcpy(buffer+1, q_10+222, 15*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+236, 16, buffer);
	memcpy(buffer+1, q_11+222, 15*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_11+236, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+1, 31*DIGIT_SIZE_B);
	memcpy(q_11+190, recombine+0, 31*DIGIT_SIZE_B);
	
// Recombining results: n:3978, depth: 2
	memset(buffer, 0x00, 1*DIGIT_SIZE_B);
	memcpy(buffer+1, q_00+190, 31*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_00+200, 32, buffer);
	memcpy(buffer+1, q_01+190, 31*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_10+200, 32, buffer);
	gf2x_add(64, temp, 64, recombine, 64, temp);
	memcpy(recombine, temp+1, 63*DIGIT_SIZE_B);
	memcpy(q_00+126, recombine+0, 63*DIGIT_SIZE_B);
	memset(buffer, 0x00, 1*DIGIT_SIZE_B);
	memcpy(buffer+1, q_00+190, 31*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+200, 32, buffer);
	memcpy(buffer+1, q_01+190, 31*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_11+200, 32, buffer);
	gf2x_add(64, temp, 64, recombine, 64, temp);
	memcpy(recombine, temp+1, 63*DIGIT_SIZE_B);
	memcpy(q_01+126, recombine+0, 63*DIGIT_SIZE_B);
	memset(buffer, 0x00, 1*DIGIT_SIZE_B);
	memcpy(buffer+1, q_10+190, 31*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_00+200, 32, buffer);
	memcpy(buffer+1, q_11+190, 31*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_10+200, 32, buffer);
	gf2x_add(64, temp, 64, recombine, 64, temp);
	memcpy(recombine, temp+1, 63*DIGIT_SIZE_B);
	memcpy(q_10+126, recombine+0, 63*DIGIT_SIZE_B);
	memset(buffer, 0x00, 1*DIGIT_SIZE_B);
	memcpy(buffer+1, q_10+190, 31*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+200, 32, buffer);
	memcpy(buffer+1, q_11+190, 31*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_11+200, 32, buffer);
	gf2x_add(64, temp, 64, recombine, 64, temp);
	memcpy(recombine, temp+1, 63*DIGIT_SIZE_B);
	memcpy(q_11+126, recombine+0, 63*DIGIT_SIZE_B);
	
// Recombining results: n:8058, depth: 1
	memset(buffer, 0x00, 1*DIGIT_SIZE_B);
	memcpy(buffer+1, q_00+126, 63*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_00+132, 64, buffer);
	memcpy(buffer+1, q_01+126, 63*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, p_10+132, 64, buffer);
	gf2x_add(128, temp, 128, recombine, 128, temp);
	memcpy(recombine, temp+1, 127*DIGIT_SIZE_B);
	memcpy(q_00+0, recombine+1, 126*DIGIT_SIZE_B);
	memset(buffer, 0x00, 1*DIGIT_SIZE_B);
	memcpy(buffer+1, q_00+126, 63*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_01+132, 64, buffer);
	memcpy(buffer+1, q_01+126, 63*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, p_11+132, 64, buffer);
	gf2x_add(128, temp, 128, recombine, 128, temp);
	memcpy(recombine, temp+1, 127*DIGIT_SIZE_B);
	memcpy(q_01+0, recombine+1, 126*DIGIT_SIZE_B);
	memset(buffer, 0x00, 1*DIGIT_SIZE_B);
	memcpy(buffer+1, q_10+126, 63*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_00+132, 64, buffer);
	memcpy(buffer+1, q_11+126, 63*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, p_10+132, 64, buffer);
	gf2x_add(128, temp, 128, recombine, 128, temp);
	memcpy(recombine, temp+1, 127*DIGIT_SIZE_B);
	memcpy(q_10+0, recombine+1, 126*DIGIT_SIZE_B);
	memset(buffer, 0x00, 1*DIGIT_SIZE_B);
	memcpy(buffer+1, q_10+126, 63*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_01+132, 64, buffer);
	memcpy(buffer+1, q_11+126, 63*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, p_11+132, 64, buffer);
	gf2x_add(128, temp, 128, recombine, 128, temp);
	memcpy(recombine, temp+1, 127*DIGIT_SIZE_B);
	memcpy(q_11+0, recombine+1, 126*DIGIT_SIZE_B);
	
// Recombining results: n:16473, depth: 0
	memset(buffer, 0x00, 6*DIGIT_SIZE_B);
	memcpy(buffer+6, q_00+0, 126*DIGIT_SIZE_B);
	GF2X_MUL(264, recombine, 132, p_00+0, 132, buffer);
	memcpy(buffer+6, q_01+0, 126*DIGIT_SIZE_B);
	GF2X_MUL(264, temp, 132, p_10+0, 132, buffer);
	gf2x_add(264, temp, 264, recombine, 264, temp);
	memcpy(recombine, temp+6, 258*DIGIT_SIZE_B);
	memcpy(t_00+0, recombine+0, 258*DIGIT_SIZE_B);
	memset(buffer, 0x00, 6*DIGIT_SIZE_B);
	memcpy(buffer+6, q_00+0, 126*DIGIT_SIZE_B);
	GF2X_MUL(264, recombine, 132, p_01+0, 132, buffer);
	memcpy(buffer+6, q_01+0, 126*DIGIT_SIZE_B);
	GF2X_MUL(264, temp, 132, p_11+0, 132, buffer);
	gf2x_add(264, temp, 264, recombine, 264, temp);
	memcpy(recombine, temp+6, 258*DIGIT_SIZE_B);
	memcpy(t_01+0, recombine+0, 258*DIGIT_SIZE_B);
	memset(buffer, 0x00, 6*DIGIT_SIZE_B);
	memcpy(buffer+6, q_10+0, 126*DIGIT_SIZE_B);
	GF2X_MUL(264, recombine, 132, p_00+0, 132, buffer);
	memcpy(buffer+6, q_11+0, 126*DIGIT_SIZE_B);
	GF2X_MUL(264, temp, 132, p_10+0, 132, buffer);
	gf2x_add(264, temp, 264, recombine, 264, temp);
	memcpy(recombine, temp+6, 258*DIGIT_SIZE_B);
	memcpy(t_10+0, recombine+0, 258*DIGIT_SIZE_B);
	memset(buffer, 0x00, 6*DIGIT_SIZE_B);
	memcpy(buffer+6, q_10+0, 126*DIGIT_SIZE_B);
	GF2X_MUL(264, recombine, 132, p_01+0, 132, buffer);
	memcpy(buffer+6, q_11+0, 126*DIGIT_SIZE_B);
	GF2X_MUL(264, temp, 132, p_11+0, 132, buffer);
	gf2x_add(264, temp, 264, recombine, 264, temp);
	memcpy(recombine, temp+6, 258*DIGIT_SIZE_B);
	memcpy(t_11+0, recombine+0, 258*DIGIT_SIZE_B);
	return delta;
}