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
	
	DIGIT f_sum[1515];
	DIGIT g_sum[1515];
	
	DIGIT temp[1014];
	DIGIT recombine[1014];
	DIGIT temp2[1014];
	DIGIT buffer[1014];
	

	delta = divstepsx_256(255, delta, f+499, g+499, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f+495);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g+495);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f+495);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g+495);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f+487);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g+487);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f+487);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g+487);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f+471);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g+471);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f+471);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g+471);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+472, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_00+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_01+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_10+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_11+448, recombine+0, 32*DIGIT_SIZE_B);
	
// Calculating left operands: n:4080, depth: 3
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_00+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f+439);
	memcpy(buffer+32, p_01+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g+439);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(f_sum+1335, temp2+64, 64*DIGIT_SIZE_B);
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_10+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f+439);
	memcpy(buffer+32, p_11+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g+439);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(g_sum+1335, temp2+64, 64*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1363, g_sum+1363, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1359);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1359);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1359);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1359);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1351);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1351);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1351);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1351);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1335);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1335);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1335);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1335);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+472, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_00+440, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_01+440, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_10+440, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_11+440, recombine+0, 32*DIGIT_SIZE_B);
	
// Recombining results: n:4080, depth: 3
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_00+440);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_01+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_00+384, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_00+440);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_01+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_01+384, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_10+440);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_11+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_10+384, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_10+440);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_11+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_11+384, recombine+0, 64*DIGIT_SIZE_B);
	
// Calculating left operands: n:8160, depth: 2
	memset(buffer, 0x00, 64*DIGIT_SIZE_B);
	memcpy(buffer+64, p_00+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(256, temp2, 128, buffer, 128, f+375);
	memcpy(buffer+64, p_01+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(256, temp, 128, buffer, 128, g+375);
	gf2x_add(256, temp, 256, temp2, 256, temp);
	memcpy(temp2, temp+64, 192*DIGIT_SIZE_B);
	right_bit_shift_wide_n(192, temp2, 4080);
	memcpy(f_sum+1143, temp2+128, 128*DIGIT_SIZE_B);
	memset(buffer, 0x00, 64*DIGIT_SIZE_B);
	memcpy(buffer+64, p_10+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(256, temp2, 128, buffer, 128, f+375);
	memcpy(buffer+64, p_11+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(256, temp, 128, buffer, 128, g+375);
	gf2x_add(256, temp, 256, temp2, 256, temp);
	memcpy(temp2, temp+64, 192*DIGIT_SIZE_B);
	right_bit_shift_wide_n(192, temp2, 4080);
	memcpy(g_sum+1143, temp2+128, 128*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1203, g_sum+1203, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1199);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1199);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1199);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1199);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1191);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1191);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1191);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1191);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1175);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1175);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1175);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1175);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+472, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_00+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_01+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_10+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_11+448, recombine+0, 32*DIGIT_SIZE_B);
	
// Calculating left operands: n:4080, depth: 3
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_00+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+1143);
	memcpy(buffer+32, p_01+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+1143);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(f_sum+1335, temp2+64, 64*DIGIT_SIZE_B);
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_10+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+1143);
	memcpy(buffer+32, p_11+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+1143);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(g_sum+1335, temp2+64, 64*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1363, g_sum+1363, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1359);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1359);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1359);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1359);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1351);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1351);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1351);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1351);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1335);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1335);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1335);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1335);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+472, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_00+440, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_01+440, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_10+440, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_11+440, recombine+0, 32*DIGIT_SIZE_B);
	
// Recombining results: n:4080, depth: 3
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_00+440);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_01+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_00+376, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_00+440);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_01+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_01+376, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_10+440);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_11+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_10+376, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_10+440);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_11+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_11+376, recombine+0, 64*DIGIT_SIZE_B);
	
// Recombining results: n:8160, depth: 2
	GF2X_MUL(128, recombine, 64, p_00+384, 64, q_00+376);
	GF2X_MUL(128, temp, 64, p_10+384, 64, q_01+376);
	gf2x_add(128, recombine, 128, temp, 128, recombine);
	memcpy(p_00+256, recombine+0, 128*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_01+384, 64, q_00+376);
	GF2X_MUL(128, temp, 64, p_11+384, 64, q_01+376);
	gf2x_add(128, recombine, 128, temp, 128, recombine);
	memcpy(p_01+256, recombine+0, 128*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_00+384, 64, q_10+376);
	GF2X_MUL(128, temp, 64, p_10+384, 64, q_11+376);
	gf2x_add(128, recombine, 128, temp, 128, recombine);
	memcpy(p_10+256, recombine+0, 128*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_01+384, 64, q_10+376);
	GF2X_MUL(128, temp, 64, p_11+384, 64, q_11+376);
	gf2x_add(128, recombine, 128, temp, 128, recombine);
	memcpy(p_11+256, recombine+0, 128*DIGIT_SIZE_B);
	
// Calculating left operands: n:16320, depth: 1
	memset(buffer, 0x00, 128*DIGIT_SIZE_B);
	memcpy(buffer+128, p_00+256, 128*DIGIT_SIZE_B);
	GF2X_MUL(512, temp2, 256, buffer, 256, f+247);
	memcpy(buffer+128, p_01+256, 128*DIGIT_SIZE_B);
	GF2X_MUL(512, temp, 256, buffer, 256, g+247);
	gf2x_add(512, temp, 512, temp2, 512, temp);
	memcpy(temp2, temp+128, 384*DIGIT_SIZE_B);
	right_bit_shift_wide_n(384, temp2, 8160);
	memcpy(f_sum+759, temp2+256, 256*DIGIT_SIZE_B);
	memset(buffer, 0x00, 128*DIGIT_SIZE_B);
	memcpy(buffer+128, p_10+256, 128*DIGIT_SIZE_B);
	GF2X_MUL(512, temp2, 256, buffer, 256, f+247);
	memcpy(buffer+128, p_11+256, 128*DIGIT_SIZE_B);
	GF2X_MUL(512, temp, 256, buffer, 256, g+247);
	gf2x_add(512, temp, 512, temp2, 512, temp);
	memcpy(temp2, temp+128, 384*DIGIT_SIZE_B);
	right_bit_shift_wide_n(384, temp2, 8160);
	memcpy(g_sum+759, temp2+256, 256*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+883, g_sum+883, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+879);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+879);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+879);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+879);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+871);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+871);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+871);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+871);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+855);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+855);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+855);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+855);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+472, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_00+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_01+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_10+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_11+448, recombine+0, 32*DIGIT_SIZE_B);
	
// Calculating left operands: n:4080, depth: 3
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_00+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+823);
	memcpy(buffer+32, p_01+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+823);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(f_sum+1335, temp2+64, 64*DIGIT_SIZE_B);
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_10+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+823);
	memcpy(buffer+32, p_11+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+823);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(g_sum+1335, temp2+64, 64*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1363, g_sum+1363, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1359);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1359);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1359);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1359);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1351);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1351);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1351);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1351);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1335);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1335);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1335);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1335);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+472, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_00+440, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_01+440, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_10+440, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_11+440, recombine+0, 32*DIGIT_SIZE_B);
	
// Recombining results: n:4080, depth: 3
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_00+440);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_01+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_00+384, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_00+440);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_01+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_01+384, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_10+440);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_11+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_10+384, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_10+440);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_11+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_11+384, recombine+0, 64*DIGIT_SIZE_B);
	
// Calculating left operands: n:8160, depth: 2
	memset(buffer, 0x00, 64*DIGIT_SIZE_B);
	memcpy(buffer+64, p_00+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(256, temp2, 128, buffer, 128, f_sum+759);
	memcpy(buffer+64, p_01+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(256, temp, 128, buffer, 128, g_sum+759);
	gf2x_add(256, temp, 256, temp2, 256, temp);
	memcpy(temp2, temp+64, 192*DIGIT_SIZE_B);
	right_bit_shift_wide_n(192, temp2, 4080);
	memcpy(f_sum+1143, temp2+128, 128*DIGIT_SIZE_B);
	memset(buffer, 0x00, 64*DIGIT_SIZE_B);
	memcpy(buffer+64, p_10+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(256, temp2, 128, buffer, 128, f_sum+759);
	memcpy(buffer+64, p_11+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(256, temp, 128, buffer, 128, g_sum+759);
	gf2x_add(256, temp, 256, temp2, 256, temp);
	memcpy(temp2, temp+64, 192*DIGIT_SIZE_B);
	right_bit_shift_wide_n(192, temp2, 4080);
	memcpy(g_sum+1143, temp2+128, 128*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1203, g_sum+1203, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1199);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1199);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1199);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1199);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1191);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1191);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1191);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1191);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1175);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1175);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1175);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1175);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+472, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_00+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_01+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_10+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_11+448, recombine+0, 32*DIGIT_SIZE_B);
	
// Calculating left operands: n:4080, depth: 3
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_00+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+1143);
	memcpy(buffer+32, p_01+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+1143);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(f_sum+1335, temp2+64, 64*DIGIT_SIZE_B);
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_10+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+1143);
	memcpy(buffer+32, p_11+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+1143);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(g_sum+1335, temp2+64, 64*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1363, g_sum+1363, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1359);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1359);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1359);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1359);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1351);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1351);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1351);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1351);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1335);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1335);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1335);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1335);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+472, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_00+440, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_01+440, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_10+440, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_11+440, recombine+0, 32*DIGIT_SIZE_B);
	
// Recombining results: n:4080, depth: 3
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_00+440);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_01+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_00+376, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_00+440);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_01+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_01+376, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_10+440);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_11+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_10+376, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_10+440);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_11+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_11+376, recombine+0, 64*DIGIT_SIZE_B);
	
// Recombining results: n:8160, depth: 2
	GF2X_MUL(128, recombine, 64, p_00+384, 64, q_00+376);
	GF2X_MUL(128, temp, 64, p_10+384, 64, q_01+376);
	gf2x_add(128, recombine, 128, temp, 128, recombine);
	memcpy(q_00+248, recombine+0, 128*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_01+384, 64, q_00+376);
	GF2X_MUL(128, temp, 64, p_11+384, 64, q_01+376);
	gf2x_add(128, recombine, 128, temp, 128, recombine);
	memcpy(q_01+248, recombine+0, 128*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_00+384, 64, q_10+376);
	GF2X_MUL(128, temp, 64, p_10+384, 64, q_11+376);
	gf2x_add(128, recombine, 128, temp, 128, recombine);
	memcpy(q_10+248, recombine+0, 128*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_01+384, 64, q_10+376);
	GF2X_MUL(128, temp, 64, p_11+384, 64, q_11+376);
	gf2x_add(128, recombine, 128, temp, 128, recombine);
	memcpy(q_11+248, recombine+0, 128*DIGIT_SIZE_B);
	
// Recombining results: n:16320, depth: 1
	GF2X_MUL(256, recombine, 128, p_00+256, 128, q_00+248);
	GF2X_MUL(256, temp, 128, p_10+256, 128, q_01+248);
	gf2x_add(256, recombine, 256, temp, 256, recombine);
	memcpy(p_00+0, recombine+0, 256*DIGIT_SIZE_B);
	GF2X_MUL(256, recombine, 128, p_01+256, 128, q_00+248);
	GF2X_MUL(256, temp, 128, p_11+256, 128, q_01+248);
	gf2x_add(256, recombine, 256, temp, 256, recombine);
	memcpy(p_01+0, recombine+0, 256*DIGIT_SIZE_B);
	GF2X_MUL(256, recombine, 128, p_00+256, 128, q_10+248);
	GF2X_MUL(256, temp, 128, p_10+256, 128, q_11+248);
	gf2x_add(256, recombine, 256, temp, 256, recombine);
	memcpy(p_10+0, recombine+0, 256*DIGIT_SIZE_B);
	GF2X_MUL(256, recombine, 128, p_01+256, 128, q_10+248);
	GF2X_MUL(256, temp, 128, p_11+256, 128, q_11+248);
	gf2x_add(256, recombine, 256, temp, 256, recombine);
	memcpy(p_11+0, recombine+0, 256*DIGIT_SIZE_B);
	
// Calculating left operands: n:32133, depth: 0
	memset(buffer, 0x00, 247*DIGIT_SIZE_B);
	memcpy(buffer+247, p_00+0, 256*DIGIT_SIZE_B);
	GF2X_MUL(1006, temp2, 503, buffer, 503, f+0);
	memcpy(buffer+247, p_01+0, 256*DIGIT_SIZE_B);
	GF2X_MUL(1006, temp, 503, buffer, 503, g+0);
	gf2x_add(1006, temp, 1006, temp2, 1006, temp);
	memcpy(temp2, temp+247, 759*DIGIT_SIZE_B);
	right_bit_shift_wide_n(759, temp2, 16320);
	memcpy(f_sum+0, temp2+511, 503*DIGIT_SIZE_B);
	memset(buffer, 0x00, 247*DIGIT_SIZE_B);
	memcpy(buffer+247, p_10+0, 256*DIGIT_SIZE_B);
	GF2X_MUL(1006, temp2, 503, buffer, 503, f+0);
	memcpy(buffer+247, p_11+0, 256*DIGIT_SIZE_B);
	GF2X_MUL(1006, temp, 503, buffer, 503, g+0);
	gf2x_add(1006, temp, 1006, temp2, 1006, temp);
	memcpy(temp2, temp+247, 759*DIGIT_SIZE_B);
	right_bit_shift_wide_n(759, temp2, 16320);
	memcpy(g_sum+0, temp2+511, 503*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+244, g_sum+244, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+240);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+240);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+240);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+240);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+232);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+232);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+232);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+232);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+216);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+216);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+216);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+216);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+472, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_00+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_01+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_10+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_11+448, recombine+0, 32*DIGIT_SIZE_B);
	
// Calculating left operands: n:4080, depth: 3
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_00+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+184);
	memcpy(buffer+32, p_01+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+184);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(f_sum+1335, temp2+64, 64*DIGIT_SIZE_B);
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_10+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+184);
	memcpy(buffer+32, p_11+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+184);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(g_sum+1335, temp2+64, 64*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1363, g_sum+1363, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1359);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1359);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1359);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1359);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1351);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1351);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1351);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1351);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1335);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1335);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1335);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1335);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+472, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_00+440, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_01+440, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_10+440, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_11+440, recombine+0, 32*DIGIT_SIZE_B);
	
// Recombining results: n:4080, depth: 3
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_00+440);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_01+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_00+384, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_00+440);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_01+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_01+384, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_10+440);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_11+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_10+384, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_10+440);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_11+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_11+384, recombine+0, 64*DIGIT_SIZE_B);
	
// Calculating left operands: n:8160, depth: 2
	memset(buffer, 0x00, 64*DIGIT_SIZE_B);
	memcpy(buffer+64, p_00+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(256, temp2, 128, buffer, 128, f_sum+120);
	memcpy(buffer+64, p_01+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(256, temp, 128, buffer, 128, g_sum+120);
	gf2x_add(256, temp, 256, temp2, 256, temp);
	memcpy(temp2, temp+64, 192*DIGIT_SIZE_B);
	right_bit_shift_wide_n(192, temp2, 4080);
	memcpy(f_sum+1143, temp2+128, 128*DIGIT_SIZE_B);
	memset(buffer, 0x00, 64*DIGIT_SIZE_B);
	memcpy(buffer+64, p_10+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(256, temp2, 128, buffer, 128, f_sum+120);
	memcpy(buffer+64, p_11+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(256, temp, 128, buffer, 128, g_sum+120);
	gf2x_add(256, temp, 256, temp2, 256, temp);
	memcpy(temp2, temp+64, 192*DIGIT_SIZE_B);
	right_bit_shift_wide_n(192, temp2, 4080);
	memcpy(g_sum+1143, temp2+128, 128*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1203, g_sum+1203, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1199);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1199);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1199);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1199);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1191);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1191);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1191);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1191);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1175);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1175);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1175);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1175);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+472, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_00+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_01+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_10+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_11+448, recombine+0, 32*DIGIT_SIZE_B);
	
// Calculating left operands: n:4080, depth: 3
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_00+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+1143);
	memcpy(buffer+32, p_01+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+1143);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(f_sum+1335, temp2+64, 64*DIGIT_SIZE_B);
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_10+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+1143);
	memcpy(buffer+32, p_11+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+1143);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(g_sum+1335, temp2+64, 64*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1363, g_sum+1363, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1359);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1359);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1359);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1359);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1351);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1351);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1351);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1351);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1335);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1335);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1335);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1335);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+472, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_00+440, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_01+440, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_10+440, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_11+440, recombine+0, 32*DIGIT_SIZE_B);
	
// Recombining results: n:4080, depth: 3
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_00+440);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_01+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_00+376, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_00+440);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_01+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_01+376, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_10+440);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_11+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_10+376, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_10+440);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_11+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(q_11+376, recombine+0, 64*DIGIT_SIZE_B);
	
// Recombining results: n:8160, depth: 2
	GF2X_MUL(128, recombine, 64, p_00+384, 64, q_00+376);
	GF2X_MUL(128, temp, 64, p_10+384, 64, q_01+376);
	gf2x_add(128, recombine, 128, temp, 128, recombine);
	memcpy(p_00+256, recombine+0, 128*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_01+384, 64, q_00+376);
	GF2X_MUL(128, temp, 64, p_11+384, 64, q_01+376);
	gf2x_add(128, recombine, 128, temp, 128, recombine);
	memcpy(p_01+256, recombine+0, 128*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_00+384, 64, q_10+376);
	GF2X_MUL(128, temp, 64, p_10+384, 64, q_11+376);
	gf2x_add(128, recombine, 128, temp, 128, recombine);
	memcpy(p_10+256, recombine+0, 128*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_01+384, 64, q_10+376);
	GF2X_MUL(128, temp, 64, p_11+384, 64, q_11+376);
	gf2x_add(128, recombine, 128, temp, 128, recombine);
	memcpy(p_11+256, recombine+0, 128*DIGIT_SIZE_B);
	
// Calculating left operands: n:15813, depth: 1
	memset(buffer, 0x00, 120*DIGIT_SIZE_B);
	memcpy(buffer+120, p_00+256, 128*DIGIT_SIZE_B);
	GF2X_MUL(496, temp2, 248, buffer, 248, f_sum+0);
	memcpy(buffer+120, p_01+256, 128*DIGIT_SIZE_B);
	GF2X_MUL(496, temp, 248, buffer, 248, g_sum+0);
	gf2x_add(496, temp, 496, temp2, 496, temp);
	memcpy(temp2, temp+120, 376*DIGIT_SIZE_B);
	right_bit_shift_wide_n(376, temp2, 8160);
	memcpy(f_sum+759, temp2+256, 248*DIGIT_SIZE_B);
	memset(buffer, 0x00, 120*DIGIT_SIZE_B);
	memcpy(buffer+120, p_10+256, 128*DIGIT_SIZE_B);
	GF2X_MUL(496, temp2, 248, buffer, 248, f_sum+0);
	memcpy(buffer+120, p_11+256, 128*DIGIT_SIZE_B);
	GF2X_MUL(496, temp, 248, buffer, 248, g_sum+0);
	gf2x_add(496, temp, 496, temp2, 496, temp);
	memcpy(temp2, temp+120, 376*DIGIT_SIZE_B);
	right_bit_shift_wide_n(376, temp2, 8160);
	memcpy(g_sum+759, temp2+256, 248*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+875, g_sum+875, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+871);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+871);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+871);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+871);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+863);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+863);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+863);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+863);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+847);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+847);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+847);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+847);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+472, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_00+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_01+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_10+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_11+448, recombine+0, 32*DIGIT_SIZE_B);
	
// Calculating left operands: n:4080, depth: 3
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_00+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+815);
	memcpy(buffer+32, p_01+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+815);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(f_sum+1335, temp2+64, 64*DIGIT_SIZE_B);
	memset(buffer, 0x00, 32*DIGIT_SIZE_B);
	memcpy(buffer+32, p_10+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp2, 64, buffer, 64, f_sum+815);
	memcpy(buffer+32, p_11+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, buffer, 64, g_sum+815);
	gf2x_add(128, temp, 128, temp2, 128, temp);
	memcpy(temp2, temp+32, 96*DIGIT_SIZE_B);
	right_bit_shift_wide_n(96, temp2, 2040);
	memcpy(g_sum+1335, temp2+64, 64*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1363, g_sum+1363, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1359);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1359);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1359);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1359);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1351);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1351);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1351);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1351);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1335);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1335);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1335);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1335);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+472, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_00+440, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_01+440, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_10+440, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(q_11+440, recombine+0, 32*DIGIT_SIZE_B);
	
// Recombining results: n:4080, depth: 3
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_00+440);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_01+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_00+384, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_00+440);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_01+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_01+384, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_00+448, 32, q_10+440);
	GF2X_MUL(64, temp, 32, p_10+448, 32, q_11+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_10+384, recombine+0, 64*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, q_10+440);
	GF2X_MUL(64, temp, 32, p_11+448, 32, q_11+440);
	gf2x_add(64, recombine, 64, temp, 64, recombine);
	memcpy(p_11+384, recombine+0, 64*DIGIT_SIZE_B);
	
// Calculating left operands: n:7653, depth: 2
	memset(buffer, 0x00, 56*DIGIT_SIZE_B);
	memcpy(buffer+56, p_00+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(240, temp2, 120, buffer, 120, f_sum+759);
	memcpy(buffer+56, p_01+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(240, temp, 120, buffer, 120, g_sum+759);
	gf2x_add(240, temp, 240, temp2, 240, temp);
	memcpy(temp2, temp+56, 184*DIGIT_SIZE_B);
	right_bit_shift_wide_n(184, temp2, 4080);
	memcpy(f_sum+1143, temp2+128, 120*DIGIT_SIZE_B);
	memset(buffer, 0x00, 56*DIGIT_SIZE_B);
	memcpy(buffer+56, p_10+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(240, temp2, 120, buffer, 120, f_sum+759);
	memcpy(buffer+56, p_11+384, 64*DIGIT_SIZE_B);
	GF2X_MUL(240, temp, 120, buffer, 120, g_sum+759);
	gf2x_add(240, temp, 240, temp2, 240, temp);
	memcpy(temp2, temp+56, 184*DIGIT_SIZE_B);
	right_bit_shift_wide_n(184, temp2, 4080);
	memcpy(g_sum+1143, temp2+128, 120*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1195, g_sum+1195, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1191);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1191);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1191);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1191);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1183);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1183);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1183);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1183);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:2040, depth: 4
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1167);
	memcpy(buffer+16, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1167);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(f_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	memset(buffer, 0x00, 16*DIGIT_SIZE_B);
	memcpy(buffer+16, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp2, 32, buffer, 32, f_sum+1167);
	memcpy(buffer+16, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, buffer, 32, g_sum+1167);
	gf2x_add(64, temp, 64, temp2, 64, temp);
	memcpy(temp2, temp+16, 48*DIGIT_SIZE_B);
	right_bit_shift_wide_n(48, temp2, 1020);
	memcpy(g_sum+1431, temp2+32, 32*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1439);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1439);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1431);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1431);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_00+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_01+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_10+472, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(q_11+472, recombine+0, 16*DIGIT_SIZE_B);
	
// Recombining results: n:2040, depth: 4
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_00+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_00+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_01+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_01+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_10+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_10+448, recombine+0, 32*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, q_10+472);
	GF2X_MUL(32, temp, 16, p_11+480, 16, q_11+472);
	gf2x_add(32, recombine, 32, temp, 32, recombine);
	memcpy(p_11+448, recombine+0, 32*DIGIT_SIZE_B);
	
// Calculating left operands: n:3573, depth: 3
	memset(buffer, 0x00, 24*DIGIT_SIZE_B);
	memcpy(buffer+24, p_00+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(112, temp2, 56, buffer, 56, f_sum+1143);
	memcpy(buffer+24, p_01+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(112, temp, 56, buffer, 56, g_sum+1143);
	gf2x_add(112, temp, 112, temp2, 112, temp);
	memcpy(temp2, temp+24, 88*DIGIT_SIZE_B);
	right_bit_shift_wide_n(88, temp2, 2040);
	memcpy(f_sum+1335, temp2+64, 56*DIGIT_SIZE_B);
	memset(buffer, 0x00, 24*DIGIT_SIZE_B);
	memcpy(buffer+24, p_10+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(112, temp2, 56, buffer, 56, f_sum+1143);
	memcpy(buffer+24, p_11+448, 32*DIGIT_SIZE_B);
	GF2X_MUL(112, temp, 56, buffer, 56, g_sum+1143);
	gf2x_add(112, temp, 112, temp2, 112, temp);
	memcpy(temp2, temp+24, 88*DIGIT_SIZE_B);
	right_bit_shift_wide_n(88, temp2, 2040);
	memcpy(g_sum+1335, temp2+64, 56*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1355, g_sum+1355, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1351);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1351);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1351);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1351);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:1020, depth: 5
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1343);
	memcpy(buffer+8, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1343);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp2, 16, buffer, 16, f_sum+1343);
	memcpy(buffer+8, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, buffer, 16, g_sum+1343);
	gf2x_add(32, temp, 32, temp2, 32, temp);
	memcpy(temp2, temp+8, 24*DIGIT_SIZE_B);
	right_bit_shift_wide_n(24, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 16*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1479);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1479);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_00+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_01+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_10+488, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(q_11+488, recombine+0, 8*DIGIT_SIZE_B);
	
// Recombining results: n:1020, depth: 5
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_00+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_00+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_01+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_01+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_10+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_10+480, recombine+0, 16*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, q_10+488);
	GF2X_MUL(16, temp, 8, p_11+496, 8, q_11+488);
	gf2x_add(16, recombine, 16, temp, 16, recombine);
	memcpy(p_11+480, recombine+0, 16*DIGIT_SIZE_B);
	
// Calculating left operands: n:1533, depth: 4
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_00+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(48, temp2, 24, buffer, 24, f_sum+1335);
	memcpy(buffer+8, p_01+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, buffer, 24, g_sum+1335);
	gf2x_add(48, temp, 48, temp2, 48, temp);
	memcpy(temp2, temp+8, 40*DIGIT_SIZE_B);
	right_bit_shift_wide_n(40, temp2, 1020);
	memcpy(f_sum+1431, temp2+31, 24*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, p_10+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(48, temp2, 24, buffer, 24, f_sum+1335);
	memcpy(buffer+8, p_11+480, 16*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, buffer, 24, g_sum+1335);
	gf2x_add(48, temp, 48, temp2, 48, temp);
	memcpy(temp2, temp+8, 40*DIGIT_SIZE_B);
	right_bit_shift_wide_n(40, temp2, 1020);
	memcpy(g_sum+1431, temp2+31, 24*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1436, g_sum+1436, p_00+504, p_01+504, p_10+504, p_11+504);
	
// Calculating left operands: n:510, depth: 6
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_00+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1432);
	memcpy(buffer+4, p_01+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1432);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(f_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	memset(buffer, 0x00, 4*DIGIT_SIZE_B);
	memcpy(buffer+4, p_10+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp2, 8, buffer, 8, f_sum+1432);
	memcpy(buffer+4, p_11+504, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, buffer, 8, g_sum+1432);
	gf2x_add(16, temp, 16, temp2, 16, temp);
	memcpy(temp2, temp+4, 12*DIGIT_SIZE_B);
	right_bit_shift_wide_n(12, temp2, 255);
	memcpy(g_sum+1503, temp2+8, 8*DIGIT_SIZE_B);
	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);
	
// Recombining results: n:510, depth: 6
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_00+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_00+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_01+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_01+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_00+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_10+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_10+496, recombine+0, 8*DIGIT_SIZE_B);
	GF2X_MUL(8, recombine, 4, p_01+504, 4, q_10+496);
	GF2X_MUL(8, temp, 4, p_11+504, 4, q_11+496);
	gf2x_add(8, recombine, 8, temp, 8, recombine);
	memcpy(p_11+496, recombine+0, 8*DIGIT_SIZE_B);
	
// Calculating left operands: n:513, depth: 5
	memset(buffer, 0x00, 1*DIGIT_SIZE_B);
	memcpy(buffer+1, p_00+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(18, temp2, 9, buffer, 9, f_sum+1431);
	memcpy(buffer+1, p_01+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(18, temp, 9, buffer, 9, g_sum+1431);
	gf2x_add(18, temp, 18, temp2, 18, temp);
	memcpy(temp2, temp+1, 17*DIGIT_SIZE_B);
	right_bit_shift_wide_n(17, temp2, 510);
	memcpy(f_sum+1479, temp2+16, 9*DIGIT_SIZE_B);
	memset(buffer, 0x00, 1*DIGIT_SIZE_B);
	memcpy(buffer+1, p_10+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(18, temp2, 9, buffer, 9, f_sum+1431);
	memcpy(buffer+1, p_11+496, 8*DIGIT_SIZE_B);
	GF2X_MUL(18, temp, 9, buffer, 9, g_sum+1431);
	gf2x_add(18, temp, 18, temp2, 18, temp);
	memcpy(temp2, temp+1, 17*DIGIT_SIZE_B);
	right_bit_shift_wide_n(17, temp2, 510);
	memcpy(g_sum+1479, temp2+16, 9*DIGIT_SIZE_B);
	delta = divstepsx(3, delta, *(f_sum+1479), *(g_sum+1479), q_00+488, q_01+488, q_10+488, q_11+488);
	
// Recombining results: n:513, depth: 5
	memset(buffer, 0x00, 7*DIGIT_SIZE_B);
	memcpy(buffer+7, q_00+488, 1*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, buffer);
	memcpy(buffer+7, q_01+488, 1*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_10+496, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+7, 9*DIGIT_SIZE_B);
	memcpy(q_00+472, recombine+0, 9*DIGIT_SIZE_B);
	memset(buffer, 0x00, 7*DIGIT_SIZE_B);
	memcpy(buffer+7, q_00+488, 1*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, buffer);
	memcpy(buffer+7, q_01+488, 1*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_11+496, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+7, 9*DIGIT_SIZE_B);
	memcpy(q_01+472, recombine+0, 9*DIGIT_SIZE_B);
	memset(buffer, 0x00, 7*DIGIT_SIZE_B);
	memcpy(buffer+7, q_10+488, 1*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_00+496, 8, buffer);
	memcpy(buffer+7, q_11+488, 1*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_10+496, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+7, 9*DIGIT_SIZE_B);
	memcpy(q_10+472, recombine+0, 9*DIGIT_SIZE_B);
	memset(buffer, 0x00, 7*DIGIT_SIZE_B);
	memcpy(buffer+7, q_10+488, 1*DIGIT_SIZE_B);
	GF2X_MUL(16, recombine, 8, p_01+496, 8, buffer);
	memcpy(buffer+7, q_11+488, 1*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_11+496, 8, buffer);
	gf2x_add(16, temp, 16, recombine, 16, temp);
	memcpy(recombine, temp+7, 9*DIGIT_SIZE_B);
	memcpy(q_11+472, recombine+0, 9*DIGIT_SIZE_B);
	
// Recombining results: n:1533, depth: 4
	memset(buffer, 0x00, 7*DIGIT_SIZE_B);
	memcpy(buffer+7, q_00+472, 9*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, buffer);
	memcpy(buffer+7, q_01+472, 9*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_10+480, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+7, 25*DIGIT_SIZE_B);
	memcpy(q_00+440, recombine+1, 24*DIGIT_SIZE_B);
	memset(buffer, 0x00, 7*DIGIT_SIZE_B);
	memcpy(buffer+7, q_00+472, 9*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, buffer);
	memcpy(buffer+7, q_01+472, 9*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_11+480, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+7, 25*DIGIT_SIZE_B);
	memcpy(q_01+440, recombine+1, 24*DIGIT_SIZE_B);
	memset(buffer, 0x00, 7*DIGIT_SIZE_B);
	memcpy(buffer+7, q_10+472, 9*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_00+480, 16, buffer);
	memcpy(buffer+7, q_11+472, 9*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_10+480, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+7, 25*DIGIT_SIZE_B);
	memcpy(q_10+440, recombine+1, 24*DIGIT_SIZE_B);
	memset(buffer, 0x00, 7*DIGIT_SIZE_B);
	memcpy(buffer+7, q_10+472, 9*DIGIT_SIZE_B);
	GF2X_MUL(32, recombine, 16, p_01+480, 16, buffer);
	memcpy(buffer+7, q_11+472, 9*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_11+480, 16, buffer);
	gf2x_add(32, temp, 32, recombine, 32, temp);
	memcpy(recombine, temp+7, 25*DIGIT_SIZE_B);
	memcpy(q_11+440, recombine+1, 24*DIGIT_SIZE_B);
	
// Recombining results: n:3573, depth: 3
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, q_00+440, 24*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_00+448, 32, buffer);
	memcpy(buffer+8, q_01+440, 24*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_10+448, 32, buffer);
	gf2x_add(64, temp, 64, recombine, 64, temp);
	memcpy(recombine, temp+8, 56*DIGIT_SIZE_B);
	memcpy(q_00+376, recombine+0, 56*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, q_00+440, 24*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, buffer);
	memcpy(buffer+8, q_01+440, 24*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_11+448, 32, buffer);
	gf2x_add(64, temp, 64, recombine, 64, temp);
	memcpy(recombine, temp+8, 56*DIGIT_SIZE_B);
	memcpy(q_01+376, recombine+0, 56*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, q_10+440, 24*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_00+448, 32, buffer);
	memcpy(buffer+8, q_11+440, 24*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_10+448, 32, buffer);
	gf2x_add(64, temp, 64, recombine, 64, temp);
	memcpy(recombine, temp+8, 56*DIGIT_SIZE_B);
	memcpy(q_10+376, recombine+0, 56*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, q_10+440, 24*DIGIT_SIZE_B);
	GF2X_MUL(64, recombine, 32, p_01+448, 32, buffer);
	memcpy(buffer+8, q_11+440, 24*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_11+448, 32, buffer);
	gf2x_add(64, temp, 64, recombine, 64, temp);
	memcpy(recombine, temp+8, 56*DIGIT_SIZE_B);
	memcpy(q_11+376, recombine+0, 56*DIGIT_SIZE_B);
	
// Recombining results: n:7653, depth: 2
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, q_00+376, 56*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_00+384, 64, buffer);
	memcpy(buffer+8, q_01+376, 56*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, p_10+384, 64, buffer);
	gf2x_add(128, temp, 128, recombine, 128, temp);
	memcpy(recombine, temp+8, 120*DIGIT_SIZE_B);
	memcpy(q_00+248, recombine+0, 120*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, q_00+376, 56*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_01+384, 64, buffer);
	memcpy(buffer+8, q_01+376, 56*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, p_11+384, 64, buffer);
	gf2x_add(128, temp, 128, recombine, 128, temp);
	memcpy(recombine, temp+8, 120*DIGIT_SIZE_B);
	memcpy(q_01+248, recombine+0, 120*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, q_10+376, 56*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_00+384, 64, buffer);
	memcpy(buffer+8, q_11+376, 56*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, p_10+384, 64, buffer);
	gf2x_add(128, temp, 128, recombine, 128, temp);
	memcpy(recombine, temp+8, 120*DIGIT_SIZE_B);
	memcpy(q_10+248, recombine+0, 120*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, q_10+376, 56*DIGIT_SIZE_B);
	GF2X_MUL(128, recombine, 64, p_01+384, 64, buffer);
	memcpy(buffer+8, q_11+376, 56*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, p_11+384, 64, buffer);
	gf2x_add(128, temp, 128, recombine, 128, temp);
	memcpy(recombine, temp+8, 120*DIGIT_SIZE_B);
	memcpy(q_11+248, recombine+0, 120*DIGIT_SIZE_B);
	
// Recombining results: n:15813, depth: 1
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, q_00+248, 120*DIGIT_SIZE_B);
	GF2X_MUL(256, recombine, 128, p_00+256, 128, buffer);
	memcpy(buffer+8, q_01+248, 120*DIGIT_SIZE_B);
	GF2X_MUL(256, temp, 128, p_10+256, 128, buffer);
	gf2x_add(256, temp, 256, recombine, 256, temp);
	memcpy(recombine, temp+8, 248*DIGIT_SIZE_B);
	memcpy(q_00+0, recombine+0, 248*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, q_00+248, 120*DIGIT_SIZE_B);
	GF2X_MUL(256, recombine, 128, p_01+256, 128, buffer);
	memcpy(buffer+8, q_01+248, 120*DIGIT_SIZE_B);
	GF2X_MUL(256, temp, 128, p_11+256, 128, buffer);
	gf2x_add(256, temp, 256, recombine, 256, temp);
	memcpy(recombine, temp+8, 248*DIGIT_SIZE_B);
	memcpy(q_01+0, recombine+0, 248*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, q_10+248, 120*DIGIT_SIZE_B);
	GF2X_MUL(256, recombine, 128, p_00+256, 128, buffer);
	memcpy(buffer+8, q_11+248, 120*DIGIT_SIZE_B);
	GF2X_MUL(256, temp, 128, p_10+256, 128, buffer);
	gf2x_add(256, temp, 256, recombine, 256, temp);
	memcpy(recombine, temp+8, 248*DIGIT_SIZE_B);
	memcpy(q_10+0, recombine+0, 248*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, q_10+248, 120*DIGIT_SIZE_B);
	GF2X_MUL(256, recombine, 128, p_01+256, 128, buffer);
	memcpy(buffer+8, q_11+248, 120*DIGIT_SIZE_B);
	GF2X_MUL(256, temp, 128, p_11+256, 128, buffer);
	gf2x_add(256, temp, 256, recombine, 256, temp);
	memcpy(recombine, temp+8, 248*DIGIT_SIZE_B);
	memcpy(q_11+0, recombine+0, 248*DIGIT_SIZE_B);
	
// Recombining results: n:32133, depth: 0
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, q_00+0, 248*DIGIT_SIZE_B);
	GF2X_MUL(512, recombine, 256, p_00+0, 256, buffer);
	memcpy(buffer+8, q_01+0, 248*DIGIT_SIZE_B);
	GF2X_MUL(512, temp, 256, p_10+0, 256, buffer);
	gf2x_add(512, temp, 512, recombine, 512, temp);
	memcpy(recombine, temp+8, 504*DIGIT_SIZE_B);
	memcpy(t_00+0, recombine+1, 503*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, q_00+0, 248*DIGIT_SIZE_B);
	GF2X_MUL(512, recombine, 256, p_01+0, 256, buffer);
	memcpy(buffer+8, q_01+0, 248*DIGIT_SIZE_B);
	GF2X_MUL(512, temp, 256, p_11+0, 256, buffer);
	gf2x_add(512, temp, 512, recombine, 512, temp);
	memcpy(recombine, temp+8, 504*DIGIT_SIZE_B);
	memcpy(t_01+0, recombine+1, 503*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, q_10+0, 248*DIGIT_SIZE_B);
	GF2X_MUL(512, recombine, 256, p_00+0, 256, buffer);
	memcpy(buffer+8, q_11+0, 248*DIGIT_SIZE_B);
	GF2X_MUL(512, temp, 256, p_10+0, 256, buffer);
	gf2x_add(512, temp, 512, recombine, 512, temp);
	memcpy(recombine, temp+8, 504*DIGIT_SIZE_B);
	memcpy(t_10+0, recombine+1, 503*DIGIT_SIZE_B);
	memset(buffer, 0x00, 8*DIGIT_SIZE_B);
	memcpy(buffer+8, q_10+0, 248*DIGIT_SIZE_B);
	GF2X_MUL(512, recombine, 256, p_01+0, 256, buffer);
	memcpy(buffer+8, q_11+0, 248*DIGIT_SIZE_B);
	GF2X_MUL(512, temp, 256, p_11+0, 256, buffer);
	gf2x_add(512, temp, 512, recombine, 512, temp);
	memcpy(recombine, temp+8, 504*DIGIT_SIZE_B);
	memcpy(t_11+0, recombine+1, 503*DIGIT_SIZE_B);
	return delta;
}