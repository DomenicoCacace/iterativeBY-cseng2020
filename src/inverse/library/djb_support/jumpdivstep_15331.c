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

int jumpdivstep_15331(int n, int delta, int nf, DIGIT *f, DIGIT *g, DIGIT *t_00, DIGIT *t_01, DIGIT *t_10, DIGIT *t_11, float x) {
	DIGIT p_00[492];
	DIGIT p_01[492];
	DIGIT p_10[492];
	DIGIT p_11[492];
	
	DIGIT q_00[477];
	DIGIT q_01[477];
	DIGIT q_10[477];
	DIGIT q_11[477];
	
	DIGIT f_sum[1468];
	DIGIT g_sum[1468];
	
	DIGIT temp[967];
	DIGIT temp2[967];
	

	delta = divstepsx_256(255, delta, f+476, g+476, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f+472+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g+472+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+472+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g+472+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f+472+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g+472+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+472+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g+472+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f+464+8, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g+464+8, 8, p_01+480);
	gf2x_add(16, f_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f+464+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g+464+0, 8, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1429, 8, f_sum+1429, 8, temp+8);
	right_bit_shift_n(16, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f+464+8, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g+464+8, 8, p_11+480);
	gf2x_add(16, g_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f+464+0, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g+464+0, 8, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1429, 8, g_sum+1429, 8, temp+8);
	right_bit_shift_n(16, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1434, g_sum+1434, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, q_00+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, q_01+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, q_10+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, q_11+465+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_10+480);
	gf2x_add(16, p_00+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_11+480);
	gf2x_add(16, p_01+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_10+480);
	gf2x_add(16, p_10+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_11+480);
	gf2x_add(16, p_11+464+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f+448+16, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, g+448+16, 16, p_01+464);
	gf2x_add(32, f_sum+1380+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f+448+0, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, g+448+0, 16, p_01+464);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1380, 16, f_sum+1380, 16, temp+16);
	right_bit_shift_n(32, f_sum+1380, 60);
	GF2X_MUL(32, temp, 16, f+448+16, 16, p_10+464);
	GF2X_MUL(32, temp2, 16, g+448+16, 16, p_11+464);
	gf2x_add(32, g_sum+1380+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f+448+0, 16, p_10+464);
	GF2X_MUL(32, temp2, 16, g+448+0, 16, p_11+464);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1380, 16, g_sum+1380, 16, temp+16);
	right_bit_shift_n(32, g_sum+1380, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1393, g_sum+1393, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1389+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1389+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1389+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1389+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1381+8, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+8, 8, p_01+480);
	gf2x_add(16, f_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1381+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+0, 8, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1429, 8, f_sum+1429, 8, temp+8);
	right_bit_shift_n(16, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1381+8, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+8, 8, p_11+480);
	gf2x_add(16, g_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1381+0, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+0, 8, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1429, 8, g_sum+1429, 8, temp+8);
	right_bit_shift_n(16, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1434, g_sum+1434, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, q_00+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, q_01+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, q_10+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, q_11+465+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_10+480);
	gf2x_add(16, q_00+449+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_11+480);
	gf2x_add(16, q_01+449+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_10+480);
	gf2x_add(16, q_10+449+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_11+480);
	gf2x_add(16, q_11+449+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+449+0, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, q_01+449+0, 16, p_10+464);
	gf2x_add(32, p_00+432+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+449+0, 16, p_01+464);
	GF2X_MUL(32, temp2, 16, q_01+449+0, 16, p_11+464);
	gf2x_add(32, p_01+432+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+449+0, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, q_11+449+0, 16, p_10+464);
	gf2x_add(32, p_10+432+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+449+0, 16, p_01+464);
	GF2X_MUL(32, temp2, 16, q_11+449+0, 16, p_11+464);
	gf2x_add(32, p_11+432+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 4080, depth: 3
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f+416+32, 32, p_00+432);
	GF2X_MUL(64, temp2, 32, g+416+32, 32, p_01+432);
	gf2x_add(64, f_sum+1283+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f+416+0, 32, p_00+432);
	GF2X_MUL(64, temp2, 32, g+416+0, 32, p_01+432);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+1283, 32, f_sum+1283, 32, temp+32);
	right_bit_shift_n(64, f_sum+1283, 56);
	GF2X_MUL(64, temp, 32, f+416+32, 32, p_10+432);
	GF2X_MUL(64, temp2, 32, g+416+32, 32, p_11+432);
	gf2x_add(64, g_sum+1283+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f+416+0, 32, p_10+432);
	GF2X_MUL(64, temp2, 32, g+416+0, 32, p_11+432);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+1283, 32, g_sum+1283, 32, temp+32);
	right_bit_shift_n(64, g_sum+1283, 56);
	

	delta = divstepsx_256(255, delta, f_sum+1312, g_sum+1312, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1308+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1308+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1308+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1308+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1308+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1308+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1308+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1308+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1300+8, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1300+8, 8, p_01+480);
	gf2x_add(16, f_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1300+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1300+0, 8, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1429, 8, f_sum+1429, 8, temp+8);
	right_bit_shift_n(16, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1300+8, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1300+8, 8, p_11+480);
	gf2x_add(16, g_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1300+0, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1300+0, 8, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1429, 8, g_sum+1429, 8, temp+8);
	right_bit_shift_n(16, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1434, g_sum+1434, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, q_00+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, q_01+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, q_10+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, q_11+465+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_10+480);
	gf2x_add(16, p_00+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_11+480);
	gf2x_add(16, p_01+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_10+480);
	gf2x_add(16, p_10+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_11+480);
	gf2x_add(16, p_11+464+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1284+16, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, g_sum+1284+16, 16, p_01+464);
	gf2x_add(32, f_sum+1380+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1284+0, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, g_sum+1284+0, 16, p_01+464);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1380, 16, f_sum+1380, 16, temp+16);
	right_bit_shift_n(32, f_sum+1380, 60);
	GF2X_MUL(32, temp, 16, f_sum+1284+16, 16, p_10+464);
	GF2X_MUL(32, temp2, 16, g_sum+1284+16, 16, p_11+464);
	gf2x_add(32, g_sum+1380+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1284+0, 16, p_10+464);
	GF2X_MUL(32, temp2, 16, g_sum+1284+0, 16, p_11+464);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1380, 16, g_sum+1380, 16, temp+16);
	right_bit_shift_n(32, g_sum+1380, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1393, g_sum+1393, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1389+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1389+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1389+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1389+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1381+8, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+8, 8, p_01+480);
	gf2x_add(16, f_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1381+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+0, 8, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1429, 8, f_sum+1429, 8, temp+8);
	right_bit_shift_n(16, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1381+8, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+8, 8, p_11+480);
	gf2x_add(16, g_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1381+0, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+0, 8, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1429, 8, g_sum+1429, 8, temp+8);
	right_bit_shift_n(16, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1434, g_sum+1434, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, q_00+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, q_01+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, q_10+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, q_11+465+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_10+480);
	gf2x_add(16, q_00+449+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_11+480);
	gf2x_add(16, q_01+449+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_10+480);
	gf2x_add(16, q_10+449+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_11+480);
	gf2x_add(16, q_11+449+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+449+0, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, q_01+449+0, 16, p_10+464);
	gf2x_add(32, q_00+417+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+449+0, 16, p_01+464);
	GF2X_MUL(32, temp2, 16, q_01+449+0, 16, p_11+464);
	gf2x_add(32, q_01+417+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+449+0, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, q_11+449+0, 16, p_10+464);
	gf2x_add(32, q_10+417+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+449+0, 16, p_01+464);
	GF2X_MUL(32, temp2, 16, q_11+449+0, 16, p_11+464);
	gf2x_add(32, q_11+417+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, q_00+417+0, 32, p_00+432);
	GF2X_MUL(64, temp2, 32, q_01+417+0, 32, p_10+432);
	gf2x_add(64, p_00+368+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_00+417+0, 32, p_01+432);
	GF2X_MUL(64, temp2, 32, q_01+417+0, 32, p_11+432);
	gf2x_add(64, p_01+368+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+417+0, 32, p_00+432);
	GF2X_MUL(64, temp2, 32, q_11+417+0, 32, p_10+432);
	gf2x_add(64, p_10+368+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+417+0, 32, p_01+432);
	GF2X_MUL(64, temp2, 32, q_11+417+0, 32, p_11+432);
	gf2x_add(64, p_11+368+0, 64, temp, 64, temp2);
	

	// Calculating left operands: n: 7905, depth: 2
	// Digits to shift: 63
	// Displacement: 64
	GF2X_MUL(128, temp, 64, f+356+60, 64, p_00+368);
	GF2X_MUL(128, temp2, 64, g+356+60, 64, p_01+368);
	gf2x_add(124, f_sum+1094, 124, temp+4, 124, temp2+4);
	GF2X_MUL(120, temp, 60, p_00+368+4, 60, f+356);
	GF2X_MUL(120, temp2, 60, p_01+368+4, 60, g+356);
	gf2x_add(120, temp, 120, temp, 120, temp2);
	gf2x_add(60, f_sum+1094, 60, f_sum+1094, 60, temp+60);
	right_bit_shift_n(124, f_sum+1094, 48);
	GF2X_MUL(128, temp, 64, f+356+60, 64, p_10+368);
	GF2X_MUL(128, temp2, 64, g+356+60, 64, p_11+368);
	gf2x_add(124, g_sum+1094, 124, temp+4, 124, temp2+4);
	GF2X_MUL(120, temp, 60, p_10+368+4, 60, f+356);
	GF2X_MUL(120, temp2, 60, p_11+368+4, 60, g+356);
	gf2x_add(120, temp, 120, temp, 120, temp2);
	gf2x_add(60, g_sum+1094, 60, g_sum+1094, 60, temp+60);
	right_bit_shift_n(124, g_sum+1094, 48);
	

	delta = divstepsx_256(255, delta, f_sum+1151, g_sum+1151, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1147+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1147+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1147+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1147+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1147+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1147+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1147+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1147+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1139+8, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1139+8, 8, p_01+480);
	gf2x_add(16, f_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1139+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1139+0, 8, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1429, 8, f_sum+1429, 8, temp+8);
	right_bit_shift_n(16, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1139+8, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1139+8, 8, p_11+480);
	gf2x_add(16, g_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1139+0, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1139+0, 8, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1429, 8, g_sum+1429, 8, temp+8);
	right_bit_shift_n(16, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1434, g_sum+1434, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, q_00+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, q_01+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, q_10+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, q_11+465+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_10+480);
	gf2x_add(16, p_00+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_11+480);
	gf2x_add(16, p_01+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_10+480);
	gf2x_add(16, p_10+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_11+480);
	gf2x_add(16, p_11+464+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1123+16, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, g_sum+1123+16, 16, p_01+464);
	gf2x_add(32, f_sum+1380+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1123+0, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, g_sum+1123+0, 16, p_01+464);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1380, 16, f_sum+1380, 16, temp+16);
	right_bit_shift_n(32, f_sum+1380, 60);
	GF2X_MUL(32, temp, 16, f_sum+1123+16, 16, p_10+464);
	GF2X_MUL(32, temp2, 16, g_sum+1123+16, 16, p_11+464);
	gf2x_add(32, g_sum+1380+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1123+0, 16, p_10+464);
	GF2X_MUL(32, temp2, 16, g_sum+1123+0, 16, p_11+464);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1380, 16, g_sum+1380, 16, temp+16);
	right_bit_shift_n(32, g_sum+1380, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1393, g_sum+1393, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1389+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1389+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1389+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1389+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1381+8, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+8, 8, p_01+480);
	gf2x_add(16, f_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1381+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+0, 8, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1429, 8, f_sum+1429, 8, temp+8);
	right_bit_shift_n(16, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1381+8, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+8, 8, p_11+480);
	gf2x_add(16, g_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1381+0, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+0, 8, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1429, 8, g_sum+1429, 8, temp+8);
	right_bit_shift_n(16, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1434, g_sum+1434, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, q_00+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, q_01+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, q_10+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, q_11+465+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_10+480);
	gf2x_add(16, q_00+449+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_11+480);
	gf2x_add(16, q_01+449+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_10+480);
	gf2x_add(16, q_10+449+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_11+480);
	gf2x_add(16, q_11+449+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+449+0, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, q_01+449+0, 16, p_10+464);
	gf2x_add(32, p_00+432+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+449+0, 16, p_01+464);
	GF2X_MUL(32, temp2, 16, q_01+449+0, 16, p_11+464);
	gf2x_add(32, p_01+432+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+449+0, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, q_11+449+0, 16, p_10+464);
	gf2x_add(32, p_10+432+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+449+0, 16, p_01+464);
	GF2X_MUL(32, temp2, 16, q_11+449+0, 16, p_11+464);
	gf2x_add(32, p_11+432+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 3825, depth: 3
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+1095+28, 32, p_00+432);
	GF2X_MUL(64, temp2, 32, g_sum+1095+28, 32, p_01+432);
	gf2x_add(60, f_sum+1283, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_00+432+4, 28, f_sum+1095);
	GF2X_MUL(56, temp2, 28, p_01+432+4, 28, g_sum+1095);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+1283, 28, f_sum+1283, 28, temp+28);
	right_bit_shift_n(60, f_sum+1283, 56);
	GF2X_MUL(64, temp, 32, f_sum+1095+28, 32, p_10+432);
	GF2X_MUL(64, temp2, 32, g_sum+1095+28, 32, p_11+432);
	gf2x_add(60, g_sum+1283, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_10+432+4, 28, f_sum+1095);
	GF2X_MUL(56, temp2, 28, p_11+432+4, 28, g_sum+1095);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+1283, 28, g_sum+1283, 28, temp+28);
	right_bit_shift_n(60, g_sum+1283, 56);
	

	delta = divstepsx_256(255, delta, f_sum+1308, g_sum+1308, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1304+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1304+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1304+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1304+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1304+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1304+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1304+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1304+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1296+8, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1296+8, 8, p_01+480);
	gf2x_add(16, f_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1296+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1296+0, 8, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1429, 8, f_sum+1429, 8, temp+8);
	right_bit_shift_n(16, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1296+8, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1296+8, 8, p_11+480);
	gf2x_add(16, g_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1296+0, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1296+0, 8, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1429, 8, g_sum+1429, 8, temp+8);
	right_bit_shift_n(16, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1434, g_sum+1434, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, q_00+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, q_01+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, q_10+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, q_11+465+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_10+480);
	gf2x_add(16, p_00+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_11+480);
	gf2x_add(16, p_01+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_10+480);
	gf2x_add(16, p_10+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_11+480);
	gf2x_add(16, p_11+464+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1284+12, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, g_sum+1284+12, 16, p_01+464);
	gf2x_add(28, f_sum+1380, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+464+4, 12, f_sum+1284);
	GF2X_MUL(24, temp2, 12, p_01+464+4, 12, g_sum+1284);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1380, 12, f_sum+1380, 12, temp+12);
	right_bit_shift_n(28, f_sum+1380, 60);
	GF2X_MUL(32, temp, 16, f_sum+1284+12, 16, p_10+464);
	GF2X_MUL(32, temp2, 16, g_sum+1284+12, 16, p_11+464);
	gf2x_add(28, g_sum+1380, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+464+4, 12, f_sum+1284);
	GF2X_MUL(24, temp2, 12, p_11+464+4, 12, g_sum+1284);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1380, 12, g_sum+1380, 12, temp+12);
	right_bit_shift_n(28, g_sum+1380, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1389, g_sum+1389, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1385+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1385+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1385+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1385+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1385+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1385+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1385+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1385+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1381+4, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+4, 8, p_01+480);
	gf2x_add(12, f_sum+1429, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+480+4, 4, f_sum+1381);
	GF2X_MUL(8, temp2, 4, p_01+480+4, 4, g_sum+1381);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1429, 4, f_sum+1429, 4, temp+4);
	right_bit_shift_n(12, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1381+4, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+4, 8, p_11+480);
	gf2x_add(12, g_sum+1429, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+480+4, 4, f_sum+1381);
	GF2X_MUL(8, temp2, 4, p_11+480+4, 4, g_sum+1381);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1429, 4, g_sum+1429, 4, temp+4);
	right_bit_shift_n(12, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1430, g_sum+1430, q_00+465, q_01+465, q_10+465, q_11+465);

	// Recombining results: n: 765, depth: 5
	memset(q_00+449, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+480+4, 4, q_00+465);
	GF2X_MUL(8, temp2, 4, p_10+480+4, 4, q_01+465);
	gf2x_add(8, q_00+449+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+465+0, 4, p_00+480);
	GF2X_MUL(8, temp2, 4, q_01+465+0, 4, p_10+480);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+449+0, 8, q_00+449+0, 8, temp);
	memset(q_01+449, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+480+4, 4, q_00+465);
	GF2X_MUL(8, temp2, 4, p_11+480+4, 4, q_01+465);
	gf2x_add(8, q_01+449+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+465+0, 4, p_01+480);
	GF2X_MUL(8, temp2, 4, q_01+465+0, 4, p_11+480);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+449+0, 8, q_01+449+0, 8, temp);
	memset(q_10+449, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+480+4, 4, q_10+465);
	GF2X_MUL(8, temp2, 4, p_10+480+4, 4, q_11+465);
	gf2x_add(8, q_10+449+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+465+0, 4, p_00+480);
	GF2X_MUL(8, temp2, 4, q_11+465+0, 4, p_10+480);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+449+0, 8, q_10+449+0, 8, temp);
	memset(q_11+449, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+480+4, 4, q_10+465);
	GF2X_MUL(8, temp2, 4, p_11+480+4, 4, q_11+465);
	gf2x_add(8, q_11+449+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+465+0, 4, p_01+480);
	GF2X_MUL(8, temp2, 4, q_11+465+0, 4, p_11+480);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+449+0, 8, q_11+449+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 4
	memset(q_00+417, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+464+4, 12, q_00+449);
	GF2X_MUL(24, temp2, 12, p_10+464+4, 12, q_01+449);
	gf2x_add(24, q_00+417+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+449+8, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_01+449+8, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+417+8, 8, q_00+417+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+449+4, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_01+449+4, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+417+4, 8, q_00+417+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+449+0, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_01+449+0, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+417+0, 8, q_00+417+0, 8, temp);
	memset(q_01+417, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+464+4, 12, q_00+449);
	GF2X_MUL(24, temp2, 12, p_11+464+4, 12, q_01+449);
	gf2x_add(24, q_01+417+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+449+8, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_01+449+8, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+417+8, 8, q_01+417+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+449+4, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_01+449+4, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+417+4, 8, q_01+417+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+449+0, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_01+449+0, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+417+0, 8, q_01+417+0, 8, temp);
	memset(q_10+417, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+464+4, 12, q_10+449);
	GF2X_MUL(24, temp2, 12, p_10+464+4, 12, q_11+449);
	gf2x_add(24, q_10+417+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+449+8, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_11+449+8, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+417+8, 8, q_10+417+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+449+4, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_11+449+4, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+417+4, 8, q_10+417+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+449+0, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_11+449+0, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+417+0, 8, q_10+417+0, 8, temp);
	memset(q_11+417, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+464+4, 12, q_10+449);
	GF2X_MUL(24, temp2, 12, p_11+464+4, 12, q_11+449);
	gf2x_add(24, q_11+417+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+449+8, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_11+449+8, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+417+8, 8, q_11+417+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+449+4, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_11+449+4, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+417+4, 8, q_11+417+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+449+0, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_11+449+0, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+417+0, 8, q_11+417+0, 8, temp);
	

	// Recombining results: n: 3825, depth: 3
	memset(q_00+357, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+432+4, 28, q_00+417);
	GF2X_MUL(56, temp2, 28, p_10+432+4, 28, q_01+417);
	gf2x_add(56, q_00+357+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+417+24, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+24, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+357+24, 8, q_00+357+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+20, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+20, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+357+20, 8, q_00+357+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+16, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+16, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+357+16, 8, q_00+357+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+12, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+12, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+357+12, 8, q_00+357+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+8, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+8, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+357+8, 8, q_00+357+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+4, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+4, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+357+4, 8, q_00+357+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+0, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+0, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+357+0, 8, q_00+357+0, 8, temp);
	memset(q_01+357, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+432+4, 28, q_00+417);
	GF2X_MUL(56, temp2, 28, p_11+432+4, 28, q_01+417);
	gf2x_add(56, q_01+357+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+417+24, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+24, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+357+24, 8, q_01+357+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+20, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+20, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+357+20, 8, q_01+357+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+16, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+16, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+357+16, 8, q_01+357+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+12, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+12, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+357+12, 8, q_01+357+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+8, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+8, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+357+8, 8, q_01+357+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+4, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+4, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+357+4, 8, q_01+357+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+0, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+0, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+357+0, 8, q_01+357+0, 8, temp);
	memset(q_10+357, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+432+4, 28, q_10+417);
	GF2X_MUL(56, temp2, 28, p_10+432+4, 28, q_11+417);
	gf2x_add(56, q_10+357+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+417+24, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+24, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+357+24, 8, q_10+357+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+20, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+20, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+357+20, 8, q_10+357+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+16, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+16, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+357+16, 8, q_10+357+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+12, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+12, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+357+12, 8, q_10+357+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+8, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+8, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+357+8, 8, q_10+357+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+4, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+4, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+357+4, 8, q_10+357+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+0, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+0, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+357+0, 8, q_10+357+0, 8, temp);
	memset(q_11+357, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+432+4, 28, q_10+417);
	GF2X_MUL(56, temp2, 28, p_11+432+4, 28, q_11+417);
	gf2x_add(56, q_11+357+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+417+24, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+24, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+357+24, 8, q_11+357+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+20, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+20, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+357+20, 8, q_11+357+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+16, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+16, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+357+16, 8, q_11+357+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+12, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+12, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+357+12, 8, q_11+357+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+8, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+8, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+357+8, 8, q_11+357+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+4, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+4, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+357+4, 8, q_11+357+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+0, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+0, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+357+0, 8, q_11+357+0, 8, temp);
	

	// Recombining results: n: 7905, depth: 2
	memset(p_00+244, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(120, temp, 60, p_00+368+4, 60, q_00+357);
	GF2X_MUL(120, temp2, 60, p_10+368+4, 60, q_01+357);
	gf2x_add(120, p_00+244+4, 120, temp, 120, temp2);
	GF2X_MUL(8, temp, 4, q_00+357+56, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_01+357+56, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+244+56, 8, p_00+244+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+52, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_01+357+52, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+244+52, 8, p_00+244+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+48, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_01+357+48, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+244+48, 8, p_00+244+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+44, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_01+357+44, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+244+44, 8, p_00+244+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+40, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_01+357+40, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+244+40, 8, p_00+244+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+36, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_01+357+36, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+244+36, 8, p_00+244+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+32, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_01+357+32, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+244+32, 8, p_00+244+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+28, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_01+357+28, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+244+28, 8, p_00+244+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+24, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_01+357+24, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+244+24, 8, p_00+244+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+20, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_01+357+20, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+244+20, 8, p_00+244+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+16, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_01+357+16, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+244+16, 8, p_00+244+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+12, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_01+357+12, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+244+12, 8, p_00+244+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+8, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_01+357+8, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+244+8, 8, p_00+244+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+4, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_01+357+4, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+244+4, 8, p_00+244+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+0, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_01+357+0, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+244+0, 8, p_00+244+0, 8, temp);
	memset(p_01+244, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(120, temp, 60, p_01+368+4, 60, q_00+357);
	GF2X_MUL(120, temp2, 60, p_11+368+4, 60, q_01+357);
	gf2x_add(120, p_01+244+4, 120, temp, 120, temp2);
	GF2X_MUL(8, temp, 4, q_00+357+56, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_01+357+56, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+244+56, 8, p_01+244+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+52, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_01+357+52, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+244+52, 8, p_01+244+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+48, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_01+357+48, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+244+48, 8, p_01+244+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+44, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_01+357+44, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+244+44, 8, p_01+244+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+40, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_01+357+40, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+244+40, 8, p_01+244+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+36, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_01+357+36, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+244+36, 8, p_01+244+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+32, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_01+357+32, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+244+32, 8, p_01+244+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+28, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_01+357+28, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+244+28, 8, p_01+244+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+24, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_01+357+24, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+244+24, 8, p_01+244+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+20, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_01+357+20, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+244+20, 8, p_01+244+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+16, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_01+357+16, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+244+16, 8, p_01+244+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+12, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_01+357+12, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+244+12, 8, p_01+244+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+8, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_01+357+8, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+244+8, 8, p_01+244+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+4, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_01+357+4, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+244+4, 8, p_01+244+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+357+0, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_01+357+0, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+244+0, 8, p_01+244+0, 8, temp);
	memset(p_10+244, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(120, temp, 60, p_00+368+4, 60, q_10+357);
	GF2X_MUL(120, temp2, 60, p_10+368+4, 60, q_11+357);
	gf2x_add(120, p_10+244+4, 120, temp, 120, temp2);
	GF2X_MUL(8, temp, 4, q_10+357+56, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_11+357+56, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+244+56, 8, p_10+244+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+52, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_11+357+52, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+244+52, 8, p_10+244+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+48, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_11+357+48, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+244+48, 8, p_10+244+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+44, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_11+357+44, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+244+44, 8, p_10+244+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+40, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_11+357+40, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+244+40, 8, p_10+244+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+36, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_11+357+36, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+244+36, 8, p_10+244+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+32, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_11+357+32, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+244+32, 8, p_10+244+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+28, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_11+357+28, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+244+28, 8, p_10+244+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+24, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_11+357+24, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+244+24, 8, p_10+244+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+20, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_11+357+20, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+244+20, 8, p_10+244+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+16, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_11+357+16, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+244+16, 8, p_10+244+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+12, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_11+357+12, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+244+12, 8, p_10+244+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+8, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_11+357+8, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+244+8, 8, p_10+244+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+4, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_11+357+4, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+244+4, 8, p_10+244+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+0, 4, p_00+368);
	GF2X_MUL(8, temp2, 4, q_11+357+0, 4, p_10+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+244+0, 8, p_10+244+0, 8, temp);
	memset(p_11+244, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(120, temp, 60, p_01+368+4, 60, q_10+357);
	GF2X_MUL(120, temp2, 60, p_11+368+4, 60, q_11+357);
	gf2x_add(120, p_11+244+4, 120, temp, 120, temp2);
	GF2X_MUL(8, temp, 4, q_10+357+56, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_11+357+56, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+244+56, 8, p_11+244+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+52, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_11+357+52, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+244+52, 8, p_11+244+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+48, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_11+357+48, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+244+48, 8, p_11+244+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+44, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_11+357+44, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+244+44, 8, p_11+244+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+40, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_11+357+40, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+244+40, 8, p_11+244+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+36, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_11+357+36, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+244+36, 8, p_11+244+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+32, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_11+357+32, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+244+32, 8, p_11+244+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+28, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_11+357+28, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+244+28, 8, p_11+244+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+24, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_11+357+24, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+244+24, 8, p_11+244+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+20, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_11+357+20, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+244+20, 8, p_11+244+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+16, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_11+357+16, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+244+16, 8, p_11+244+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+12, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_11+357+12, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+244+12, 8, p_11+244+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+8, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_11+357+8, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+244+8, 8, p_11+244+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+4, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_11+357+4, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+244+4, 8, p_11+244+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+357+0, 4, p_01+368);
	GF2X_MUL(8, temp2, 4, q_11+357+0, 4, p_11+368);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+244+0, 8, p_11+244+0, 8, temp);
	

	// Calculating left operands: n: 15555, depth: 1
	// Digits to shift: 123
	// Displacement: 124
	GF2X_MUL(248, temp, 124, f+236+120, 124, p_00+244);
	GF2X_MUL(248, temp2, 124, g+236+120, 124, p_01+244);
	gf2x_add(244, f_sum+725, 244, temp+4, 244, temp2+4);
	GF2X_MUL(240, temp, 120, p_00+244+4, 120, f+236);
	GF2X_MUL(240, temp2, 120, p_01+244+4, 120, g+236);
	gf2x_add(240, temp, 240, temp, 240, temp2);
	gf2x_add(120, f_sum+725, 120, f_sum+725, 120, temp+120);
	right_bit_shift_n(244, f_sum+725, 33);
	GF2X_MUL(248, temp, 124, f+236+120, 124, p_10+244);
	GF2X_MUL(248, temp2, 124, g+236+120, 124, p_11+244);
	gf2x_add(244, g_sum+725, 244, temp+4, 244, temp2+4);
	GF2X_MUL(240, temp, 120, p_10+244+4, 120, f+236);
	GF2X_MUL(240, temp2, 120, p_11+244+4, 120, g+236);
	gf2x_add(240, temp, 240, temp, 240, temp2);
	gf2x_add(120, g_sum+725, 120, g_sum+725, 120, temp+120);
	right_bit_shift_n(244, g_sum+725, 33);
	

	delta = divstepsx_256(255, delta, f_sum+842, g_sum+842, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+838+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+838+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+838+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+838+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+838+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+838+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+838+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+838+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+830+8, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+830+8, 8, p_01+480);
	gf2x_add(16, f_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+830+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+830+0, 8, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1429, 8, f_sum+1429, 8, temp+8);
	right_bit_shift_n(16, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+830+8, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+830+8, 8, p_11+480);
	gf2x_add(16, g_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+830+0, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+830+0, 8, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1429, 8, g_sum+1429, 8, temp+8);
	right_bit_shift_n(16, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1434, g_sum+1434, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, q_00+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, q_01+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, q_10+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, q_11+465+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_10+480);
	gf2x_add(16, p_00+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_11+480);
	gf2x_add(16, p_01+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_10+480);
	gf2x_add(16, p_10+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_11+480);
	gf2x_add(16, p_11+464+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+814+16, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, g_sum+814+16, 16, p_01+464);
	gf2x_add(32, f_sum+1380+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+814+0, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, g_sum+814+0, 16, p_01+464);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1380, 16, f_sum+1380, 16, temp+16);
	right_bit_shift_n(32, f_sum+1380, 60);
	GF2X_MUL(32, temp, 16, f_sum+814+16, 16, p_10+464);
	GF2X_MUL(32, temp2, 16, g_sum+814+16, 16, p_11+464);
	gf2x_add(32, g_sum+1380+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+814+0, 16, p_10+464);
	GF2X_MUL(32, temp2, 16, g_sum+814+0, 16, p_11+464);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1380, 16, g_sum+1380, 16, temp+16);
	right_bit_shift_n(32, g_sum+1380, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1393, g_sum+1393, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1389+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1389+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1389+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1389+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1381+8, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+8, 8, p_01+480);
	gf2x_add(16, f_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1381+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+0, 8, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1429, 8, f_sum+1429, 8, temp+8);
	right_bit_shift_n(16, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1381+8, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+8, 8, p_11+480);
	gf2x_add(16, g_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1381+0, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+0, 8, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1429, 8, g_sum+1429, 8, temp+8);
	right_bit_shift_n(16, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1434, g_sum+1434, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, q_00+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, q_01+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, q_10+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, q_11+465+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_10+480);
	gf2x_add(16, q_00+449+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_11+480);
	gf2x_add(16, q_01+449+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_10+480);
	gf2x_add(16, q_10+449+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_11+480);
	gf2x_add(16, q_11+449+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+449+0, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, q_01+449+0, 16, p_10+464);
	gf2x_add(32, p_00+432+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+449+0, 16, p_01+464);
	GF2X_MUL(32, temp2, 16, q_01+449+0, 16, p_11+464);
	gf2x_add(32, p_01+432+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+449+0, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, q_11+449+0, 16, p_10+464);
	gf2x_add(32, p_10+432+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+449+0, 16, p_01+464);
	GF2X_MUL(32, temp2, 16, q_11+449+0, 16, p_11+464);
	gf2x_add(32, p_11+432+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 3825, depth: 3
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+786+28, 32, p_00+432);
	GF2X_MUL(64, temp2, 32, g_sum+786+28, 32, p_01+432);
	gf2x_add(60, f_sum+1283, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_00+432+4, 28, f_sum+786);
	GF2X_MUL(56, temp2, 28, p_01+432+4, 28, g_sum+786);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+1283, 28, f_sum+1283, 28, temp+28);
	right_bit_shift_n(60, f_sum+1283, 56);
	GF2X_MUL(64, temp, 32, f_sum+786+28, 32, p_10+432);
	GF2X_MUL(64, temp2, 32, g_sum+786+28, 32, p_11+432);
	gf2x_add(60, g_sum+1283, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_10+432+4, 28, f_sum+786);
	GF2X_MUL(56, temp2, 28, p_11+432+4, 28, g_sum+786);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+1283, 28, g_sum+1283, 28, temp+28);
	right_bit_shift_n(60, g_sum+1283, 56);
	

	delta = divstepsx_256(255, delta, f_sum+1308, g_sum+1308, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1304+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1304+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1304+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1304+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1304+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1304+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1304+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1304+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1296+8, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1296+8, 8, p_01+480);
	gf2x_add(16, f_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1296+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1296+0, 8, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1429, 8, f_sum+1429, 8, temp+8);
	right_bit_shift_n(16, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1296+8, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1296+8, 8, p_11+480);
	gf2x_add(16, g_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1296+0, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1296+0, 8, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1429, 8, g_sum+1429, 8, temp+8);
	right_bit_shift_n(16, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1434, g_sum+1434, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, q_00+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, q_01+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, q_10+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, q_11+465+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_10+480);
	gf2x_add(16, p_00+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_11+480);
	gf2x_add(16, p_01+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_10+480);
	gf2x_add(16, p_10+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_11+480);
	gf2x_add(16, p_11+464+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1284+12, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, g_sum+1284+12, 16, p_01+464);
	gf2x_add(28, f_sum+1380, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+464+4, 12, f_sum+1284);
	GF2X_MUL(24, temp2, 12, p_01+464+4, 12, g_sum+1284);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1380, 12, f_sum+1380, 12, temp+12);
	right_bit_shift_n(28, f_sum+1380, 60);
	GF2X_MUL(32, temp, 16, f_sum+1284+12, 16, p_10+464);
	GF2X_MUL(32, temp2, 16, g_sum+1284+12, 16, p_11+464);
	gf2x_add(28, g_sum+1380, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+464+4, 12, f_sum+1284);
	GF2X_MUL(24, temp2, 12, p_11+464+4, 12, g_sum+1284);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1380, 12, g_sum+1380, 12, temp+12);
	right_bit_shift_n(28, g_sum+1380, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1389, g_sum+1389, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1385+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1385+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1385+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1385+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1385+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1385+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1385+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1385+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1381+4, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+4, 8, p_01+480);
	gf2x_add(12, f_sum+1429, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+480+4, 4, f_sum+1381);
	GF2X_MUL(8, temp2, 4, p_01+480+4, 4, g_sum+1381);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1429, 4, f_sum+1429, 4, temp+4);
	right_bit_shift_n(12, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1381+4, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+4, 8, p_11+480);
	gf2x_add(12, g_sum+1429, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+480+4, 4, f_sum+1381);
	GF2X_MUL(8, temp2, 4, p_11+480+4, 4, g_sum+1381);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1429, 4, g_sum+1429, 4, temp+4);
	right_bit_shift_n(12, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1430, g_sum+1430, q_00+465, q_01+465, q_10+465, q_11+465);

	// Recombining results: n: 765, depth: 5
	memset(q_00+449, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+480+4, 4, q_00+465);
	GF2X_MUL(8, temp2, 4, p_10+480+4, 4, q_01+465);
	gf2x_add(8, q_00+449+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+465+0, 4, p_00+480);
	GF2X_MUL(8, temp2, 4, q_01+465+0, 4, p_10+480);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+449+0, 8, q_00+449+0, 8, temp);
	memset(q_01+449, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+480+4, 4, q_00+465);
	GF2X_MUL(8, temp2, 4, p_11+480+4, 4, q_01+465);
	gf2x_add(8, q_01+449+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+465+0, 4, p_01+480);
	GF2X_MUL(8, temp2, 4, q_01+465+0, 4, p_11+480);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+449+0, 8, q_01+449+0, 8, temp);
	memset(q_10+449, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+480+4, 4, q_10+465);
	GF2X_MUL(8, temp2, 4, p_10+480+4, 4, q_11+465);
	gf2x_add(8, q_10+449+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+465+0, 4, p_00+480);
	GF2X_MUL(8, temp2, 4, q_11+465+0, 4, p_10+480);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+449+0, 8, q_10+449+0, 8, temp);
	memset(q_11+449, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+480+4, 4, q_10+465);
	GF2X_MUL(8, temp2, 4, p_11+480+4, 4, q_11+465);
	gf2x_add(8, q_11+449+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+465+0, 4, p_01+480);
	GF2X_MUL(8, temp2, 4, q_11+465+0, 4, p_11+480);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+449+0, 8, q_11+449+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 4
	memset(q_00+417, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+464+4, 12, q_00+449);
	GF2X_MUL(24, temp2, 12, p_10+464+4, 12, q_01+449);
	gf2x_add(24, q_00+417+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+449+8, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_01+449+8, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+417+8, 8, q_00+417+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+449+4, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_01+449+4, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+417+4, 8, q_00+417+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+449+0, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_01+449+0, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+417+0, 8, q_00+417+0, 8, temp);
	memset(q_01+417, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+464+4, 12, q_00+449);
	GF2X_MUL(24, temp2, 12, p_11+464+4, 12, q_01+449);
	gf2x_add(24, q_01+417+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+449+8, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_01+449+8, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+417+8, 8, q_01+417+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+449+4, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_01+449+4, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+417+4, 8, q_01+417+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+449+0, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_01+449+0, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+417+0, 8, q_01+417+0, 8, temp);
	memset(q_10+417, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+464+4, 12, q_10+449);
	GF2X_MUL(24, temp2, 12, p_10+464+4, 12, q_11+449);
	gf2x_add(24, q_10+417+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+449+8, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_11+449+8, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+417+8, 8, q_10+417+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+449+4, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_11+449+4, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+417+4, 8, q_10+417+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+449+0, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_11+449+0, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+417+0, 8, q_10+417+0, 8, temp);
	memset(q_11+417, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+464+4, 12, q_10+449);
	GF2X_MUL(24, temp2, 12, p_11+464+4, 12, q_11+449);
	gf2x_add(24, q_11+417+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+449+8, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_11+449+8, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+417+8, 8, q_11+417+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+449+4, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_11+449+4, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+417+4, 8, q_11+417+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+449+0, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_11+449+0, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+417+0, 8, q_11+417+0, 8, temp);
	

	// Recombining results: n: 3825, depth: 3
	memset(p_00+368, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+432+4, 28, q_00+417);
	GF2X_MUL(56, temp2, 28, p_10+432+4, 28, q_01+417);
	gf2x_add(56, p_00+368+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+417+24, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+24, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+368+24, 8, p_00+368+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+20, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+20, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+368+20, 8, p_00+368+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+16, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+16, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+368+16, 8, p_00+368+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+12, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+12, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+368+12, 8, p_00+368+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+8, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+8, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+368+8, 8, p_00+368+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+4, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+4, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+368+4, 8, p_00+368+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+0, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+0, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+368+0, 8, p_00+368+0, 8, temp);
	memset(p_01+368, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+432+4, 28, q_00+417);
	GF2X_MUL(56, temp2, 28, p_11+432+4, 28, q_01+417);
	gf2x_add(56, p_01+368+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+417+24, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+24, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+368+24, 8, p_01+368+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+20, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+20, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+368+20, 8, p_01+368+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+16, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+16, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+368+16, 8, p_01+368+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+12, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+12, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+368+12, 8, p_01+368+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+8, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+8, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+368+8, 8, p_01+368+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+4, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+4, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+368+4, 8, p_01+368+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+0, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+0, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+368+0, 8, p_01+368+0, 8, temp);
	memset(p_10+368, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+432+4, 28, q_10+417);
	GF2X_MUL(56, temp2, 28, p_10+432+4, 28, q_11+417);
	gf2x_add(56, p_10+368+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+417+24, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+24, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+368+24, 8, p_10+368+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+20, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+20, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+368+20, 8, p_10+368+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+16, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+16, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+368+16, 8, p_10+368+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+12, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+12, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+368+12, 8, p_10+368+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+8, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+8, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+368+8, 8, p_10+368+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+4, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+4, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+368+4, 8, p_10+368+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+0, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+0, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+368+0, 8, p_10+368+0, 8, temp);
	memset(p_11+368, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+432+4, 28, q_10+417);
	GF2X_MUL(56, temp2, 28, p_11+432+4, 28, q_11+417);
	gf2x_add(56, p_11+368+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+417+24, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+24, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+368+24, 8, p_11+368+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+20, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+20, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+368+20, 8, p_11+368+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+16, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+16, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+368+16, 8, p_11+368+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+12, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+12, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+368+12, 8, p_11+368+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+8, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+8, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+368+8, 8, p_11+368+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+4, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+4, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+368+4, 8, p_11+368+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+0, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+0, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+368+0, 8, p_11+368+0, 8, temp);
	

	// Calculating left operands: n: 7650, depth: 2
	// Digits to shift: 59
	// Displacement: 60
	GF2X_MUL(120, temp, 60, f_sum+726+60, 60, p_00+368);
	GF2X_MUL(120, temp2, 60, g_sum+726+60, 60, p_01+368);
	gf2x_add(120, f_sum+1094+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, f_sum+726+0, 60, p_00+368);
	GF2X_MUL(120, temp2, 60, g_sum+726+0, 60, p_01+368);
	gf2x_add(120, temp, 120, temp, 120, temp2);
	gf2x_add(60, f_sum+1094, 60, f_sum+1094, 60, temp+60);
	right_bit_shift_n(120, f_sum+1094, 49);
	GF2X_MUL(120, temp, 60, f_sum+726+60, 60, p_10+368);
	GF2X_MUL(120, temp2, 60, g_sum+726+60, 60, p_11+368);
	gf2x_add(120, g_sum+1094+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, f_sum+726+0, 60, p_10+368);
	GF2X_MUL(120, temp2, 60, g_sum+726+0, 60, p_11+368);
	gf2x_add(120, temp, 120, temp, 120, temp2);
	gf2x_add(60, g_sum+1094, 60, g_sum+1094, 60, temp+60);
	right_bit_shift_n(120, g_sum+1094, 49);
	

	delta = divstepsx_256(255, delta, f_sum+1151, g_sum+1151, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1147+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1147+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1147+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1147+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1147+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1147+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1147+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1147+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1139+8, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1139+8, 8, p_01+480);
	gf2x_add(16, f_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1139+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1139+0, 8, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1429, 8, f_sum+1429, 8, temp+8);
	right_bit_shift_n(16, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1139+8, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1139+8, 8, p_11+480);
	gf2x_add(16, g_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1139+0, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1139+0, 8, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1429, 8, g_sum+1429, 8, temp+8);
	right_bit_shift_n(16, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1434, g_sum+1434, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, q_00+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, q_01+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, q_10+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, q_11+465+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_10+480);
	gf2x_add(16, p_00+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_11+480);
	gf2x_add(16, p_01+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_10+480);
	gf2x_add(16, p_10+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_11+480);
	gf2x_add(16, p_11+464+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1123+16, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, g_sum+1123+16, 16, p_01+464);
	gf2x_add(32, f_sum+1380+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1123+0, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, g_sum+1123+0, 16, p_01+464);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1380, 16, f_sum+1380, 16, temp+16);
	right_bit_shift_n(32, f_sum+1380, 60);
	GF2X_MUL(32, temp, 16, f_sum+1123+16, 16, p_10+464);
	GF2X_MUL(32, temp2, 16, g_sum+1123+16, 16, p_11+464);
	gf2x_add(32, g_sum+1380+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1123+0, 16, p_10+464);
	GF2X_MUL(32, temp2, 16, g_sum+1123+0, 16, p_11+464);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1380, 16, g_sum+1380, 16, temp+16);
	right_bit_shift_n(32, g_sum+1380, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1393, g_sum+1393, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1389+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1389+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1389+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1389+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1381+8, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+8, 8, p_01+480);
	gf2x_add(16, f_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1381+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+0, 8, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1429, 8, f_sum+1429, 8, temp+8);
	right_bit_shift_n(16, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1381+8, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+8, 8, p_11+480);
	gf2x_add(16, g_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1381+0, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+0, 8, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1429, 8, g_sum+1429, 8, temp+8);
	right_bit_shift_n(16, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1434, g_sum+1434, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, q_00+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, q_01+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, q_10+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, q_11+465+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_10+480);
	gf2x_add(16, q_00+449+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_11+480);
	gf2x_add(16, q_01+449+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_10+480);
	gf2x_add(16, q_10+449+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_11+480);
	gf2x_add(16, q_11+449+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+449+0, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, q_01+449+0, 16, p_10+464);
	gf2x_add(32, p_00+432+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+449+0, 16, p_01+464);
	GF2X_MUL(32, temp2, 16, q_01+449+0, 16, p_11+464);
	gf2x_add(32, p_01+432+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+449+0, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, q_11+449+0, 16, p_10+464);
	gf2x_add(32, p_10+432+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+449+0, 16, p_01+464);
	GF2X_MUL(32, temp2, 16, q_11+449+0, 16, p_11+464);
	gf2x_add(32, p_11+432+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 3825, depth: 3
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+1095+28, 32, p_00+432);
	GF2X_MUL(64, temp2, 32, g_sum+1095+28, 32, p_01+432);
	gf2x_add(60, f_sum+1283, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_00+432+4, 28, f_sum+1095);
	GF2X_MUL(56, temp2, 28, p_01+432+4, 28, g_sum+1095);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+1283, 28, f_sum+1283, 28, temp+28);
	right_bit_shift_n(60, f_sum+1283, 56);
	GF2X_MUL(64, temp, 32, f_sum+1095+28, 32, p_10+432);
	GF2X_MUL(64, temp2, 32, g_sum+1095+28, 32, p_11+432);
	gf2x_add(60, g_sum+1283, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_10+432+4, 28, f_sum+1095);
	GF2X_MUL(56, temp2, 28, p_11+432+4, 28, g_sum+1095);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+1283, 28, g_sum+1283, 28, temp+28);
	right_bit_shift_n(60, g_sum+1283, 56);
	

	delta = divstepsx_256(255, delta, f_sum+1308, g_sum+1308, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1304+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1304+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1304+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1304+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1304+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1304+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1304+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1304+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1296+8, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1296+8, 8, p_01+480);
	gf2x_add(16, f_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1296+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1296+0, 8, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1429, 8, f_sum+1429, 8, temp+8);
	right_bit_shift_n(16, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1296+8, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1296+8, 8, p_11+480);
	gf2x_add(16, g_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1296+0, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1296+0, 8, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1429, 8, g_sum+1429, 8, temp+8);
	right_bit_shift_n(16, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1434, g_sum+1434, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, q_00+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, q_01+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, q_10+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, q_11+465+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_10+480);
	gf2x_add(16, p_00+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_11+480);
	gf2x_add(16, p_01+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_10+480);
	gf2x_add(16, p_10+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_11+480);
	gf2x_add(16, p_11+464+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1284+12, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, g_sum+1284+12, 16, p_01+464);
	gf2x_add(28, f_sum+1380, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+464+4, 12, f_sum+1284);
	GF2X_MUL(24, temp2, 12, p_01+464+4, 12, g_sum+1284);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1380, 12, f_sum+1380, 12, temp+12);
	right_bit_shift_n(28, f_sum+1380, 60);
	GF2X_MUL(32, temp, 16, f_sum+1284+12, 16, p_10+464);
	GF2X_MUL(32, temp2, 16, g_sum+1284+12, 16, p_11+464);
	gf2x_add(28, g_sum+1380, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+464+4, 12, f_sum+1284);
	GF2X_MUL(24, temp2, 12, p_11+464+4, 12, g_sum+1284);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1380, 12, g_sum+1380, 12, temp+12);
	right_bit_shift_n(28, g_sum+1380, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1389, g_sum+1389, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1385+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1385+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1385+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1385+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1385+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1385+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1385+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1385+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1381+4, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+4, 8, p_01+480);
	gf2x_add(12, f_sum+1429, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+480+4, 4, f_sum+1381);
	GF2X_MUL(8, temp2, 4, p_01+480+4, 4, g_sum+1381);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1429, 4, f_sum+1429, 4, temp+4);
	right_bit_shift_n(12, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1381+4, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+4, 8, p_11+480);
	gf2x_add(12, g_sum+1429, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+480+4, 4, f_sum+1381);
	GF2X_MUL(8, temp2, 4, p_11+480+4, 4, g_sum+1381);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1429, 4, g_sum+1429, 4, temp+4);
	right_bit_shift_n(12, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1430, g_sum+1430, q_00+465, q_01+465, q_10+465, q_11+465);

	// Recombining results: n: 765, depth: 5
	memset(q_00+449, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+480+4, 4, q_00+465);
	GF2X_MUL(8, temp2, 4, p_10+480+4, 4, q_01+465);
	gf2x_add(8, q_00+449+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+465+0, 4, p_00+480);
	GF2X_MUL(8, temp2, 4, q_01+465+0, 4, p_10+480);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+449+0, 8, q_00+449+0, 8, temp);
	memset(q_01+449, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+480+4, 4, q_00+465);
	GF2X_MUL(8, temp2, 4, p_11+480+4, 4, q_01+465);
	gf2x_add(8, q_01+449+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+465+0, 4, p_01+480);
	GF2X_MUL(8, temp2, 4, q_01+465+0, 4, p_11+480);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+449+0, 8, q_01+449+0, 8, temp);
	memset(q_10+449, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+480+4, 4, q_10+465);
	GF2X_MUL(8, temp2, 4, p_10+480+4, 4, q_11+465);
	gf2x_add(8, q_10+449+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+465+0, 4, p_00+480);
	GF2X_MUL(8, temp2, 4, q_11+465+0, 4, p_10+480);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+449+0, 8, q_10+449+0, 8, temp);
	memset(q_11+449, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+480+4, 4, q_10+465);
	GF2X_MUL(8, temp2, 4, p_11+480+4, 4, q_11+465);
	gf2x_add(8, q_11+449+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+465+0, 4, p_01+480);
	GF2X_MUL(8, temp2, 4, q_11+465+0, 4, p_11+480);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+449+0, 8, q_11+449+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 4
	memset(q_00+417, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+464+4, 12, q_00+449);
	GF2X_MUL(24, temp2, 12, p_10+464+4, 12, q_01+449);
	gf2x_add(24, q_00+417+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+449+8, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_01+449+8, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+417+8, 8, q_00+417+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+449+4, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_01+449+4, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+417+4, 8, q_00+417+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+449+0, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_01+449+0, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+417+0, 8, q_00+417+0, 8, temp);
	memset(q_01+417, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+464+4, 12, q_00+449);
	GF2X_MUL(24, temp2, 12, p_11+464+4, 12, q_01+449);
	gf2x_add(24, q_01+417+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+449+8, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_01+449+8, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+417+8, 8, q_01+417+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+449+4, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_01+449+4, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+417+4, 8, q_01+417+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+449+0, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_01+449+0, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+417+0, 8, q_01+417+0, 8, temp);
	memset(q_10+417, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+464+4, 12, q_10+449);
	GF2X_MUL(24, temp2, 12, p_10+464+4, 12, q_11+449);
	gf2x_add(24, q_10+417+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+449+8, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_11+449+8, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+417+8, 8, q_10+417+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+449+4, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_11+449+4, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+417+4, 8, q_10+417+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+449+0, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_11+449+0, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+417+0, 8, q_10+417+0, 8, temp);
	memset(q_11+417, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+464+4, 12, q_10+449);
	GF2X_MUL(24, temp2, 12, p_11+464+4, 12, q_11+449);
	gf2x_add(24, q_11+417+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+449+8, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_11+449+8, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+417+8, 8, q_11+417+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+449+4, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_11+449+4, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+417+4, 8, q_11+417+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+449+0, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_11+449+0, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+417+0, 8, q_11+417+0, 8, temp);
	

	// Recombining results: n: 3825, depth: 3
	memset(q_00+357, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+432+4, 28, q_00+417);
	GF2X_MUL(56, temp2, 28, p_10+432+4, 28, q_01+417);
	gf2x_add(56, q_00+357+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+417+24, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+24, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+357+24, 8, q_00+357+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+20, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+20, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+357+20, 8, q_00+357+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+16, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+16, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+357+16, 8, q_00+357+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+12, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+12, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+357+12, 8, q_00+357+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+8, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+8, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+357+8, 8, q_00+357+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+4, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+4, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+357+4, 8, q_00+357+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+0, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+0, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+357+0, 8, q_00+357+0, 8, temp);
	memset(q_01+357, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+432+4, 28, q_00+417);
	GF2X_MUL(56, temp2, 28, p_11+432+4, 28, q_01+417);
	gf2x_add(56, q_01+357+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+417+24, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+24, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+357+24, 8, q_01+357+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+20, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+20, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+357+20, 8, q_01+357+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+16, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+16, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+357+16, 8, q_01+357+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+12, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+12, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+357+12, 8, q_01+357+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+8, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+8, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+357+8, 8, q_01+357+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+4, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+4, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+357+4, 8, q_01+357+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+0, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+0, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+357+0, 8, q_01+357+0, 8, temp);
	memset(q_10+357, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+432+4, 28, q_10+417);
	GF2X_MUL(56, temp2, 28, p_10+432+4, 28, q_11+417);
	gf2x_add(56, q_10+357+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+417+24, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+24, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+357+24, 8, q_10+357+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+20, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+20, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+357+20, 8, q_10+357+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+16, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+16, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+357+16, 8, q_10+357+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+12, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+12, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+357+12, 8, q_10+357+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+8, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+8, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+357+8, 8, q_10+357+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+4, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+4, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+357+4, 8, q_10+357+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+0, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+0, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+357+0, 8, q_10+357+0, 8, temp);
	memset(q_11+357, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+432+4, 28, q_10+417);
	GF2X_MUL(56, temp2, 28, p_11+432+4, 28, q_11+417);
	gf2x_add(56, q_11+357+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+417+24, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+24, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+357+24, 8, q_11+357+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+20, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+20, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+357+20, 8, q_11+357+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+16, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+16, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+357+16, 8, q_11+357+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+12, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+12, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+357+12, 8, q_11+357+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+8, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+8, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+357+8, 8, q_11+357+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+4, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+4, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+357+4, 8, q_11+357+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+0, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+0, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+357+0, 8, q_11+357+0, 8, temp);
	

	// Recombining results: n: 7650, depth: 2
	GF2X_MUL(120, temp, 60, q_00+357+0, 60, p_00+368);
	GF2X_MUL(120, temp2, 60, q_01+357+0, 60, p_10+368);
	gf2x_add(120, q_00+237+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, q_00+357+0, 60, p_01+368);
	GF2X_MUL(120, temp2, 60, q_01+357+0, 60, p_11+368);
	gf2x_add(120, q_01+237+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, q_10+357+0, 60, p_00+368);
	GF2X_MUL(120, temp2, 60, q_11+357+0, 60, p_10+368);
	gf2x_add(120, q_10+237+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, q_10+357+0, 60, p_01+368);
	GF2X_MUL(120, temp2, 60, q_11+357+0, 60, p_11+368);
	gf2x_add(120, q_11+237+0, 120, temp, 120, temp2);
	

	// Recombining results: n: 15555, depth: 1
	memset(p_00+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(240, temp, 120, p_00+244+4, 120, q_00+237);
	GF2X_MUL(240, temp2, 120, p_10+244+4, 120, q_01+237);
	gf2x_add(240, p_00+0+4, 240, temp, 240, temp2);
	GF2X_MUL(8, temp, 4, q_00+237+116, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+116, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+116, 8, p_00+0+116, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+112, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+112, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+112, 8, p_00+0+112, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+108, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+108, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+108, 8, p_00+0+108, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+104, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+104, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+104, 8, p_00+0+104, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+100, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+100, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+100, 8, p_00+0+100, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+96, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+96, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+96, 8, p_00+0+96, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+92, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+92, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+92, 8, p_00+0+92, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+88, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+88, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+88, 8, p_00+0+88, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+84, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+84, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+84, 8, p_00+0+84, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+80, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+80, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+80, 8, p_00+0+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+76, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+76, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+76, 8, p_00+0+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+72, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+72, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+72, 8, p_00+0+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+68, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+68, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+68, 8, p_00+0+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+64, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+64, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+64, 8, p_00+0+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+60, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+60, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+60, 8, p_00+0+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+56, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+56, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+56, 8, p_00+0+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+52, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+52, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+52, 8, p_00+0+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+48, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+48, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+48, 8, p_00+0+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+44, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+44, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+44, 8, p_00+0+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+40, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+40, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+40, 8, p_00+0+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+36, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+36, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+36, 8, p_00+0+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+32, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+32, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+32, 8, p_00+0+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+28, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+28, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+28, 8, p_00+0+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+24, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+24, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+24, 8, p_00+0+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+20, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+20, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+20, 8, p_00+0+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+16, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+16, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+16, 8, p_00+0+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+12, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+12, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+12, 8, p_00+0+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+8, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+8, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+8, 8, p_00+0+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+4, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+4, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+4, 8, p_00+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+0, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_01+237+0, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+0, 8, p_00+0+0, 8, temp);
	memset(p_01+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(240, temp, 120, p_01+244+4, 120, q_00+237);
	GF2X_MUL(240, temp2, 120, p_11+244+4, 120, q_01+237);
	gf2x_add(240, p_01+0+4, 240, temp, 240, temp2);
	GF2X_MUL(8, temp, 4, q_00+237+116, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+116, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+116, 8, p_01+0+116, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+112, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+112, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+112, 8, p_01+0+112, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+108, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+108, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+108, 8, p_01+0+108, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+104, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+104, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+104, 8, p_01+0+104, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+100, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+100, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+100, 8, p_01+0+100, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+96, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+96, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+96, 8, p_01+0+96, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+92, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+92, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+92, 8, p_01+0+92, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+88, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+88, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+88, 8, p_01+0+88, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+84, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+84, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+84, 8, p_01+0+84, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+80, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+80, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+80, 8, p_01+0+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+76, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+76, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+76, 8, p_01+0+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+72, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+72, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+72, 8, p_01+0+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+68, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+68, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+68, 8, p_01+0+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+64, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+64, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+64, 8, p_01+0+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+60, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+60, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+60, 8, p_01+0+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+56, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+56, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+56, 8, p_01+0+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+52, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+52, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+52, 8, p_01+0+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+48, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+48, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+48, 8, p_01+0+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+44, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+44, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+44, 8, p_01+0+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+40, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+40, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+40, 8, p_01+0+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+36, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+36, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+36, 8, p_01+0+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+32, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+32, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+32, 8, p_01+0+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+28, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+28, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+28, 8, p_01+0+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+24, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+24, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+24, 8, p_01+0+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+20, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+20, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+20, 8, p_01+0+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+16, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+16, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+16, 8, p_01+0+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+12, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+12, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+12, 8, p_01+0+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+8, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+8, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+8, 8, p_01+0+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+4, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+4, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+4, 8, p_01+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+237+0, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_01+237+0, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+0, 8, p_01+0+0, 8, temp);
	memset(p_10+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(240, temp, 120, p_00+244+4, 120, q_10+237);
	GF2X_MUL(240, temp2, 120, p_10+244+4, 120, q_11+237);
	gf2x_add(240, p_10+0+4, 240, temp, 240, temp2);
	GF2X_MUL(8, temp, 4, q_10+237+116, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+116, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+116, 8, p_10+0+116, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+112, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+112, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+112, 8, p_10+0+112, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+108, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+108, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+108, 8, p_10+0+108, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+104, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+104, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+104, 8, p_10+0+104, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+100, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+100, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+100, 8, p_10+0+100, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+96, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+96, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+96, 8, p_10+0+96, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+92, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+92, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+92, 8, p_10+0+92, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+88, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+88, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+88, 8, p_10+0+88, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+84, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+84, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+84, 8, p_10+0+84, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+80, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+80, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+80, 8, p_10+0+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+76, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+76, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+76, 8, p_10+0+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+72, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+72, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+72, 8, p_10+0+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+68, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+68, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+68, 8, p_10+0+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+64, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+64, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+64, 8, p_10+0+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+60, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+60, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+60, 8, p_10+0+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+56, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+56, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+56, 8, p_10+0+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+52, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+52, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+52, 8, p_10+0+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+48, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+48, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+48, 8, p_10+0+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+44, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+44, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+44, 8, p_10+0+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+40, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+40, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+40, 8, p_10+0+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+36, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+36, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+36, 8, p_10+0+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+32, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+32, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+32, 8, p_10+0+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+28, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+28, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+28, 8, p_10+0+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+24, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+24, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+24, 8, p_10+0+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+20, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+20, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+20, 8, p_10+0+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+16, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+16, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+16, 8, p_10+0+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+12, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+12, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+12, 8, p_10+0+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+8, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+8, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+8, 8, p_10+0+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+4, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+4, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+4, 8, p_10+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+0, 4, p_00+244);
	GF2X_MUL(8, temp2, 4, q_11+237+0, 4, p_10+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+0, 8, p_10+0+0, 8, temp);
	memset(p_11+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(240, temp, 120, p_01+244+4, 120, q_10+237);
	GF2X_MUL(240, temp2, 120, p_11+244+4, 120, q_11+237);
	gf2x_add(240, p_11+0+4, 240, temp, 240, temp2);
	GF2X_MUL(8, temp, 4, q_10+237+116, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+116, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+116, 8, p_11+0+116, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+112, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+112, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+112, 8, p_11+0+112, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+108, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+108, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+108, 8, p_11+0+108, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+104, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+104, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+104, 8, p_11+0+104, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+100, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+100, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+100, 8, p_11+0+100, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+96, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+96, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+96, 8, p_11+0+96, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+92, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+92, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+92, 8, p_11+0+92, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+88, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+88, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+88, 8, p_11+0+88, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+84, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+84, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+84, 8, p_11+0+84, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+80, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+80, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+80, 8, p_11+0+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+76, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+76, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+76, 8, p_11+0+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+72, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+72, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+72, 8, p_11+0+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+68, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+68, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+68, 8, p_11+0+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+64, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+64, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+64, 8, p_11+0+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+60, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+60, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+60, 8, p_11+0+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+56, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+56, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+56, 8, p_11+0+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+52, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+52, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+52, 8, p_11+0+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+48, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+48, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+48, 8, p_11+0+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+44, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+44, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+44, 8, p_11+0+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+40, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+40, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+40, 8, p_11+0+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+36, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+36, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+36, 8, p_11+0+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+32, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+32, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+32, 8, p_11+0+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+28, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+28, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+28, 8, p_11+0+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+24, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+24, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+24, 8, p_11+0+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+20, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+20, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+20, 8, p_11+0+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+16, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+16, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+16, 8, p_11+0+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+12, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+12, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+12, 8, p_11+0+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+8, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+8, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+8, 8, p_11+0+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+4, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+4, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+4, 8, p_11+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+237+0, 4, p_01+244);
	GF2X_MUL(8, temp2, 4, q_11+237+0, 4, p_11+244);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+0, 8, p_11+0+0, 8, temp);
	

	// Calculating left operands: n: 30661, depth: 0
	// Digits to shift: 243
	// Displacement: 243
	GF2X_MUL(488, temp, 244, f+0+236, 244, p_00+0);
	GF2X_MUL(488, temp2, 244, g+0+236, 244, p_01+0);
	gf2x_add(481, f_sum+0, 481, temp+7, 481, temp2+7);
	GF2X_MUL(472, temp, 236, p_00+0+8, 236, f+0);
	GF2X_MUL(472, temp2, 236, p_01+0+8, 236, g+0);
	gf2x_add(472, temp, 472, temp, 472, temp2);
	gf2x_add(237, f_sum+0, 237, f_sum+0, 237, temp+235);
	GF2X_MUL(16, temp, 8, f+0+228, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, g+0+228, 8, p_01+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(1, f_sum+0, 1, f_sum+0, 1, temp+15);
	right_bit_shift_n(480, f_sum+0, 3);
	GF2X_MUL(488, temp, 244, f+0+236, 244, p_10+0);
	GF2X_MUL(488, temp2, 244, g+0+236, 244, p_11+0);
	gf2x_add(481, g_sum+0, 481, temp+7, 481, temp2+7);
	GF2X_MUL(472, temp, 236, p_10+0+8, 236, f+0);
	GF2X_MUL(472, temp2, 236, p_11+0+8, 236, g+0);
	gf2x_add(472, temp, 472, temp, 472, temp2);
	gf2x_add(237, g_sum+0, 237, g_sum+0, 237, temp+235);
	GF2X_MUL(16, temp, 8, f+0+228, 8, p_10+0);
	GF2X_MUL(16, temp2, 8, g+0+228, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(1, g_sum+0, 1, g_sum+0, 1, temp+15);
	right_bit_shift_n(480, g_sum+0, 3);
	

	delta = divstepsx_256(255, delta, f_sum+234, g_sum+234, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+230+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+230+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+230+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+230+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+230+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+230+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+230+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+230+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+222+8, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+222+8, 8, p_01+480);
	gf2x_add(16, f_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+222+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+222+0, 8, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1429, 8, f_sum+1429, 8, temp+8);
	right_bit_shift_n(16, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+222+8, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+222+8, 8, p_11+480);
	gf2x_add(16, g_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+222+0, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+222+0, 8, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1429, 8, g_sum+1429, 8, temp+8);
	right_bit_shift_n(16, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1434, g_sum+1434, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, q_00+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, q_01+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, q_10+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, q_11+465+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_10+480);
	gf2x_add(16, p_00+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_11+480);
	gf2x_add(16, p_01+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_10+480);
	gf2x_add(16, p_10+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_11+480);
	gf2x_add(16, p_11+464+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+206+16, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, g_sum+206+16, 16, p_01+464);
	gf2x_add(32, f_sum+1380+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+206+0, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, g_sum+206+0, 16, p_01+464);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1380, 16, f_sum+1380, 16, temp+16);
	right_bit_shift_n(32, f_sum+1380, 60);
	GF2X_MUL(32, temp, 16, f_sum+206+16, 16, p_10+464);
	GF2X_MUL(32, temp2, 16, g_sum+206+16, 16, p_11+464);
	gf2x_add(32, g_sum+1380+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+206+0, 16, p_10+464);
	GF2X_MUL(32, temp2, 16, g_sum+206+0, 16, p_11+464);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1380, 16, g_sum+1380, 16, temp+16);
	right_bit_shift_n(32, g_sum+1380, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1393, g_sum+1393, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1389+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1389+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1389+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1389+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1381+8, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+8, 8, p_01+480);
	gf2x_add(16, f_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1381+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+0, 8, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1429, 8, f_sum+1429, 8, temp+8);
	right_bit_shift_n(16, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1381+8, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+8, 8, p_11+480);
	gf2x_add(16, g_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1381+0, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+0, 8, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1429, 8, g_sum+1429, 8, temp+8);
	right_bit_shift_n(16, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1434, g_sum+1434, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, q_00+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, q_01+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, q_10+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, q_11+465+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_10+480);
	gf2x_add(16, q_00+449+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_11+480);
	gf2x_add(16, q_01+449+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_10+480);
	gf2x_add(16, q_10+449+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_11+480);
	gf2x_add(16, q_11+449+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+449+0, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, q_01+449+0, 16, p_10+464);
	gf2x_add(32, p_00+432+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+449+0, 16, p_01+464);
	GF2X_MUL(32, temp2, 16, q_01+449+0, 16, p_11+464);
	gf2x_add(32, p_01+432+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+449+0, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, q_11+449+0, 16, p_10+464);
	gf2x_add(32, p_10+432+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+449+0, 16, p_01+464);
	GF2X_MUL(32, temp2, 16, q_11+449+0, 16, p_11+464);
	gf2x_add(32, p_11+432+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 3825, depth: 3
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+178+28, 32, p_00+432);
	GF2X_MUL(64, temp2, 32, g_sum+178+28, 32, p_01+432);
	gf2x_add(60, f_sum+1283, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_00+432+4, 28, f_sum+178);
	GF2X_MUL(56, temp2, 28, p_01+432+4, 28, g_sum+178);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+1283, 28, f_sum+1283, 28, temp+28);
	right_bit_shift_n(60, f_sum+1283, 56);
	GF2X_MUL(64, temp, 32, f_sum+178+28, 32, p_10+432);
	GF2X_MUL(64, temp2, 32, g_sum+178+28, 32, p_11+432);
	gf2x_add(60, g_sum+1283, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_10+432+4, 28, f_sum+178);
	GF2X_MUL(56, temp2, 28, p_11+432+4, 28, g_sum+178);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+1283, 28, g_sum+1283, 28, temp+28);
	right_bit_shift_n(60, g_sum+1283, 56);
	

	delta = divstepsx_256(255, delta, f_sum+1308, g_sum+1308, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1304+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1304+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1304+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1304+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1304+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1304+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1304+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1304+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1296+8, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1296+8, 8, p_01+480);
	gf2x_add(16, f_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1296+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1296+0, 8, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1429, 8, f_sum+1429, 8, temp+8);
	right_bit_shift_n(16, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1296+8, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1296+8, 8, p_11+480);
	gf2x_add(16, g_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1296+0, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1296+0, 8, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1429, 8, g_sum+1429, 8, temp+8);
	right_bit_shift_n(16, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1434, g_sum+1434, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, q_00+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, q_01+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, q_10+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, q_11+465+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_10+480);
	gf2x_add(16, p_00+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_11+480);
	gf2x_add(16, p_01+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_10+480);
	gf2x_add(16, p_10+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_11+480);
	gf2x_add(16, p_11+464+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1284+12, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, g_sum+1284+12, 16, p_01+464);
	gf2x_add(28, f_sum+1380, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+464+4, 12, f_sum+1284);
	GF2X_MUL(24, temp2, 12, p_01+464+4, 12, g_sum+1284);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1380, 12, f_sum+1380, 12, temp+12);
	right_bit_shift_n(28, f_sum+1380, 60);
	GF2X_MUL(32, temp, 16, f_sum+1284+12, 16, p_10+464);
	GF2X_MUL(32, temp2, 16, g_sum+1284+12, 16, p_11+464);
	gf2x_add(28, g_sum+1380, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+464+4, 12, f_sum+1284);
	GF2X_MUL(24, temp2, 12, p_11+464+4, 12, g_sum+1284);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1380, 12, g_sum+1380, 12, temp+12);
	right_bit_shift_n(28, g_sum+1380, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1389, g_sum+1389, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1385+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1385+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1385+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1385+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1385+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1385+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1385+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1385+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1381+4, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+4, 8, p_01+480);
	gf2x_add(12, f_sum+1429, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+480+4, 4, f_sum+1381);
	GF2X_MUL(8, temp2, 4, p_01+480+4, 4, g_sum+1381);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1429, 4, f_sum+1429, 4, temp+4);
	right_bit_shift_n(12, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1381+4, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+4, 8, p_11+480);
	gf2x_add(12, g_sum+1429, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+480+4, 4, f_sum+1381);
	GF2X_MUL(8, temp2, 4, p_11+480+4, 4, g_sum+1381);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1429, 4, g_sum+1429, 4, temp+4);
	right_bit_shift_n(12, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1430, g_sum+1430, q_00+465, q_01+465, q_10+465, q_11+465);

	// Recombining results: n: 765, depth: 5
	memset(q_00+449, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+480+4, 4, q_00+465);
	GF2X_MUL(8, temp2, 4, p_10+480+4, 4, q_01+465);
	gf2x_add(8, q_00+449+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+465+0, 4, p_00+480);
	GF2X_MUL(8, temp2, 4, q_01+465+0, 4, p_10+480);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+449+0, 8, q_00+449+0, 8, temp);
	memset(q_01+449, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+480+4, 4, q_00+465);
	GF2X_MUL(8, temp2, 4, p_11+480+4, 4, q_01+465);
	gf2x_add(8, q_01+449+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+465+0, 4, p_01+480);
	GF2X_MUL(8, temp2, 4, q_01+465+0, 4, p_11+480);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+449+0, 8, q_01+449+0, 8, temp);
	memset(q_10+449, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+480+4, 4, q_10+465);
	GF2X_MUL(8, temp2, 4, p_10+480+4, 4, q_11+465);
	gf2x_add(8, q_10+449+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+465+0, 4, p_00+480);
	GF2X_MUL(8, temp2, 4, q_11+465+0, 4, p_10+480);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+449+0, 8, q_10+449+0, 8, temp);
	memset(q_11+449, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+480+4, 4, q_10+465);
	GF2X_MUL(8, temp2, 4, p_11+480+4, 4, q_11+465);
	gf2x_add(8, q_11+449+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+465+0, 4, p_01+480);
	GF2X_MUL(8, temp2, 4, q_11+465+0, 4, p_11+480);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+449+0, 8, q_11+449+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 4
	memset(q_00+417, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+464+4, 12, q_00+449);
	GF2X_MUL(24, temp2, 12, p_10+464+4, 12, q_01+449);
	gf2x_add(24, q_00+417+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+449+8, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_01+449+8, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+417+8, 8, q_00+417+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+449+4, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_01+449+4, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+417+4, 8, q_00+417+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+449+0, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_01+449+0, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+417+0, 8, q_00+417+0, 8, temp);
	memset(q_01+417, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+464+4, 12, q_00+449);
	GF2X_MUL(24, temp2, 12, p_11+464+4, 12, q_01+449);
	gf2x_add(24, q_01+417+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+449+8, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_01+449+8, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+417+8, 8, q_01+417+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+449+4, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_01+449+4, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+417+4, 8, q_01+417+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+449+0, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_01+449+0, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+417+0, 8, q_01+417+0, 8, temp);
	memset(q_10+417, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+464+4, 12, q_10+449);
	GF2X_MUL(24, temp2, 12, p_10+464+4, 12, q_11+449);
	gf2x_add(24, q_10+417+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+449+8, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_11+449+8, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+417+8, 8, q_10+417+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+449+4, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_11+449+4, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+417+4, 8, q_10+417+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+449+0, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_11+449+0, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+417+0, 8, q_10+417+0, 8, temp);
	memset(q_11+417, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+464+4, 12, q_10+449);
	GF2X_MUL(24, temp2, 12, p_11+464+4, 12, q_11+449);
	gf2x_add(24, q_11+417+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+449+8, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_11+449+8, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+417+8, 8, q_11+417+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+449+4, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_11+449+4, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+417+4, 8, q_11+417+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+449+0, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_11+449+0, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+417+0, 8, q_11+417+0, 8, temp);
	

	// Recombining results: n: 3825, depth: 3
	memset(p_00+368, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+432+4, 28, q_00+417);
	GF2X_MUL(56, temp2, 28, p_10+432+4, 28, q_01+417);
	gf2x_add(56, p_00+368+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+417+24, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+24, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+368+24, 8, p_00+368+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+20, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+20, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+368+20, 8, p_00+368+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+16, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+16, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+368+16, 8, p_00+368+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+12, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+12, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+368+12, 8, p_00+368+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+8, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+8, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+368+8, 8, p_00+368+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+4, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+4, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+368+4, 8, p_00+368+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+0, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+0, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+368+0, 8, p_00+368+0, 8, temp);
	memset(p_01+368, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+432+4, 28, q_00+417);
	GF2X_MUL(56, temp2, 28, p_11+432+4, 28, q_01+417);
	gf2x_add(56, p_01+368+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+417+24, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+24, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+368+24, 8, p_01+368+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+20, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+20, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+368+20, 8, p_01+368+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+16, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+16, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+368+16, 8, p_01+368+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+12, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+12, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+368+12, 8, p_01+368+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+8, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+8, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+368+8, 8, p_01+368+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+4, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+4, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+368+4, 8, p_01+368+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+0, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+0, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+368+0, 8, p_01+368+0, 8, temp);
	memset(p_10+368, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+432+4, 28, q_10+417);
	GF2X_MUL(56, temp2, 28, p_10+432+4, 28, q_11+417);
	gf2x_add(56, p_10+368+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+417+24, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+24, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+368+24, 8, p_10+368+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+20, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+20, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+368+20, 8, p_10+368+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+16, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+16, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+368+16, 8, p_10+368+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+12, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+12, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+368+12, 8, p_10+368+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+8, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+8, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+368+8, 8, p_10+368+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+4, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+4, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+368+4, 8, p_10+368+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+0, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+0, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+368+0, 8, p_10+368+0, 8, temp);
	memset(p_11+368, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+432+4, 28, q_10+417);
	GF2X_MUL(56, temp2, 28, p_11+432+4, 28, q_11+417);
	gf2x_add(56, p_11+368+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+417+24, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+24, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+368+24, 8, p_11+368+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+20, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+20, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+368+20, 8, p_11+368+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+16, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+16, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+368+16, 8, p_11+368+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+12, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+12, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+368+12, 8, p_11+368+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+8, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+8, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+368+8, 8, p_11+368+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+4, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+4, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+368+4, 8, p_11+368+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+0, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+0, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+368+0, 8, p_11+368+0, 8, temp);
	

	// Calculating left operands: n: 7650, depth: 2
	// Digits to shift: 59
	// Displacement: 60
	GF2X_MUL(120, temp, 60, f_sum+118+60, 60, p_00+368);
	GF2X_MUL(120, temp2, 60, g_sum+118+60, 60, p_01+368);
	gf2x_add(120, f_sum+1094+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, f_sum+118+0, 60, p_00+368);
	GF2X_MUL(120, temp2, 60, g_sum+118+0, 60, p_01+368);
	gf2x_add(120, temp, 120, temp, 120, temp2);
	gf2x_add(60, f_sum+1094, 60, f_sum+1094, 60, temp+60);
	right_bit_shift_n(120, f_sum+1094, 49);
	GF2X_MUL(120, temp, 60, f_sum+118+60, 60, p_10+368);
	GF2X_MUL(120, temp2, 60, g_sum+118+60, 60, p_11+368);
	gf2x_add(120, g_sum+1094+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, f_sum+118+0, 60, p_10+368);
	GF2X_MUL(120, temp2, 60, g_sum+118+0, 60, p_11+368);
	gf2x_add(120, temp, 120, temp, 120, temp2);
	gf2x_add(60, g_sum+1094, 60, g_sum+1094, 60, temp+60);
	right_bit_shift_n(120, g_sum+1094, 49);
	

	delta = divstepsx_256(255, delta, f_sum+1151, g_sum+1151, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1147+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1147+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1147+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1147+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1147+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1147+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1147+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1147+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1139+8, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1139+8, 8, p_01+480);
	gf2x_add(16, f_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1139+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1139+0, 8, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1429, 8, f_sum+1429, 8, temp+8);
	right_bit_shift_n(16, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1139+8, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1139+8, 8, p_11+480);
	gf2x_add(16, g_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1139+0, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1139+0, 8, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1429, 8, g_sum+1429, 8, temp+8);
	right_bit_shift_n(16, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1434, g_sum+1434, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, q_00+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, q_01+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, q_10+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, q_11+465+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_10+480);
	gf2x_add(16, p_00+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_11+480);
	gf2x_add(16, p_01+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_10+480);
	gf2x_add(16, p_10+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_11+480);
	gf2x_add(16, p_11+464+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1123+16, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, g_sum+1123+16, 16, p_01+464);
	gf2x_add(32, f_sum+1380+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1123+0, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, g_sum+1123+0, 16, p_01+464);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1380, 16, f_sum+1380, 16, temp+16);
	right_bit_shift_n(32, f_sum+1380, 60);
	GF2X_MUL(32, temp, 16, f_sum+1123+16, 16, p_10+464);
	GF2X_MUL(32, temp2, 16, g_sum+1123+16, 16, p_11+464);
	gf2x_add(32, g_sum+1380+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1123+0, 16, p_10+464);
	GF2X_MUL(32, temp2, 16, g_sum+1123+0, 16, p_11+464);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1380, 16, g_sum+1380, 16, temp+16);
	right_bit_shift_n(32, g_sum+1380, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1393, g_sum+1393, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1389+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1389+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1389+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1389+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1381+8, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+8, 8, p_01+480);
	gf2x_add(16, f_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1381+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+0, 8, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1429, 8, f_sum+1429, 8, temp+8);
	right_bit_shift_n(16, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1381+8, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+8, 8, p_11+480);
	gf2x_add(16, g_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1381+0, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+0, 8, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1429, 8, g_sum+1429, 8, temp+8);
	right_bit_shift_n(16, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1434, g_sum+1434, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, q_00+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, q_01+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, q_10+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, q_11+465+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_10+480);
	gf2x_add(16, q_00+449+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_11+480);
	gf2x_add(16, q_01+449+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_10+480);
	gf2x_add(16, q_10+449+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_11+480);
	gf2x_add(16, q_11+449+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+449+0, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, q_01+449+0, 16, p_10+464);
	gf2x_add(32, p_00+432+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+449+0, 16, p_01+464);
	GF2X_MUL(32, temp2, 16, q_01+449+0, 16, p_11+464);
	gf2x_add(32, p_01+432+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+449+0, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, q_11+449+0, 16, p_10+464);
	gf2x_add(32, p_10+432+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+449+0, 16, p_01+464);
	GF2X_MUL(32, temp2, 16, q_11+449+0, 16, p_11+464);
	gf2x_add(32, p_11+432+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 3825, depth: 3
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+1095+28, 32, p_00+432);
	GF2X_MUL(64, temp2, 32, g_sum+1095+28, 32, p_01+432);
	gf2x_add(60, f_sum+1283, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_00+432+4, 28, f_sum+1095);
	GF2X_MUL(56, temp2, 28, p_01+432+4, 28, g_sum+1095);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+1283, 28, f_sum+1283, 28, temp+28);
	right_bit_shift_n(60, f_sum+1283, 56);
	GF2X_MUL(64, temp, 32, f_sum+1095+28, 32, p_10+432);
	GF2X_MUL(64, temp2, 32, g_sum+1095+28, 32, p_11+432);
	gf2x_add(60, g_sum+1283, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_10+432+4, 28, f_sum+1095);
	GF2X_MUL(56, temp2, 28, p_11+432+4, 28, g_sum+1095);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+1283, 28, g_sum+1283, 28, temp+28);
	right_bit_shift_n(60, g_sum+1283, 56);
	

	delta = divstepsx_256(255, delta, f_sum+1308, g_sum+1308, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1304+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1304+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1304+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1304+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1304+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1304+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1304+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1304+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1296+8, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1296+8, 8, p_01+480);
	gf2x_add(16, f_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1296+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1296+0, 8, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1429, 8, f_sum+1429, 8, temp+8);
	right_bit_shift_n(16, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1296+8, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1296+8, 8, p_11+480);
	gf2x_add(16, g_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1296+0, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1296+0, 8, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1429, 8, g_sum+1429, 8, temp+8);
	right_bit_shift_n(16, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1434, g_sum+1434, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, q_00+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, q_01+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, q_10+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, q_11+465+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_10+480);
	gf2x_add(16, p_00+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_11+480);
	gf2x_add(16, p_01+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_10+480);
	gf2x_add(16, p_10+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_11+480);
	gf2x_add(16, p_11+464+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1284+12, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, g_sum+1284+12, 16, p_01+464);
	gf2x_add(28, f_sum+1380, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+464+4, 12, f_sum+1284);
	GF2X_MUL(24, temp2, 12, p_01+464+4, 12, g_sum+1284);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1380, 12, f_sum+1380, 12, temp+12);
	right_bit_shift_n(28, f_sum+1380, 60);
	GF2X_MUL(32, temp, 16, f_sum+1284+12, 16, p_10+464);
	GF2X_MUL(32, temp2, 16, g_sum+1284+12, 16, p_11+464);
	gf2x_add(28, g_sum+1380, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+464+4, 12, f_sum+1284);
	GF2X_MUL(24, temp2, 12, p_11+464+4, 12, g_sum+1284);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1380, 12, g_sum+1380, 12, temp+12);
	right_bit_shift_n(28, g_sum+1380, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1389, g_sum+1389, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1385+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1385+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1385+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1385+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1385+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1385+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1385+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1385+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1381+4, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+4, 8, p_01+480);
	gf2x_add(12, f_sum+1429, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+480+4, 4, f_sum+1381);
	GF2X_MUL(8, temp2, 4, p_01+480+4, 4, g_sum+1381);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1429, 4, f_sum+1429, 4, temp+4);
	right_bit_shift_n(12, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1381+4, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+4, 8, p_11+480);
	gf2x_add(12, g_sum+1429, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+480+4, 4, f_sum+1381);
	GF2X_MUL(8, temp2, 4, p_11+480+4, 4, g_sum+1381);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1429, 4, g_sum+1429, 4, temp+4);
	right_bit_shift_n(12, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1430, g_sum+1430, q_00+465, q_01+465, q_10+465, q_11+465);

	// Recombining results: n: 765, depth: 5
	memset(q_00+449, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+480+4, 4, q_00+465);
	GF2X_MUL(8, temp2, 4, p_10+480+4, 4, q_01+465);
	gf2x_add(8, q_00+449+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+465+0, 4, p_00+480);
	GF2X_MUL(8, temp2, 4, q_01+465+0, 4, p_10+480);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+449+0, 8, q_00+449+0, 8, temp);
	memset(q_01+449, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+480+4, 4, q_00+465);
	GF2X_MUL(8, temp2, 4, p_11+480+4, 4, q_01+465);
	gf2x_add(8, q_01+449+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+465+0, 4, p_01+480);
	GF2X_MUL(8, temp2, 4, q_01+465+0, 4, p_11+480);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+449+0, 8, q_01+449+0, 8, temp);
	memset(q_10+449, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+480+4, 4, q_10+465);
	GF2X_MUL(8, temp2, 4, p_10+480+4, 4, q_11+465);
	gf2x_add(8, q_10+449+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+465+0, 4, p_00+480);
	GF2X_MUL(8, temp2, 4, q_11+465+0, 4, p_10+480);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+449+0, 8, q_10+449+0, 8, temp);
	memset(q_11+449, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+480+4, 4, q_10+465);
	GF2X_MUL(8, temp2, 4, p_11+480+4, 4, q_11+465);
	gf2x_add(8, q_11+449+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+465+0, 4, p_01+480);
	GF2X_MUL(8, temp2, 4, q_11+465+0, 4, p_11+480);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+449+0, 8, q_11+449+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 4
	memset(q_00+417, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+464+4, 12, q_00+449);
	GF2X_MUL(24, temp2, 12, p_10+464+4, 12, q_01+449);
	gf2x_add(24, q_00+417+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+449+8, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_01+449+8, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+417+8, 8, q_00+417+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+449+4, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_01+449+4, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+417+4, 8, q_00+417+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+449+0, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_01+449+0, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+417+0, 8, q_00+417+0, 8, temp);
	memset(q_01+417, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+464+4, 12, q_00+449);
	GF2X_MUL(24, temp2, 12, p_11+464+4, 12, q_01+449);
	gf2x_add(24, q_01+417+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+449+8, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_01+449+8, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+417+8, 8, q_01+417+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+449+4, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_01+449+4, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+417+4, 8, q_01+417+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+449+0, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_01+449+0, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+417+0, 8, q_01+417+0, 8, temp);
	memset(q_10+417, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+464+4, 12, q_10+449);
	GF2X_MUL(24, temp2, 12, p_10+464+4, 12, q_11+449);
	gf2x_add(24, q_10+417+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+449+8, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_11+449+8, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+417+8, 8, q_10+417+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+449+4, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_11+449+4, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+417+4, 8, q_10+417+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+449+0, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_11+449+0, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+417+0, 8, q_10+417+0, 8, temp);
	memset(q_11+417, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+464+4, 12, q_10+449);
	GF2X_MUL(24, temp2, 12, p_11+464+4, 12, q_11+449);
	gf2x_add(24, q_11+417+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+449+8, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_11+449+8, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+417+8, 8, q_11+417+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+449+4, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_11+449+4, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+417+4, 8, q_11+417+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+449+0, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_11+449+0, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+417+0, 8, q_11+417+0, 8, temp);
	

	// Recombining results: n: 3825, depth: 3
	memset(q_00+357, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+432+4, 28, q_00+417);
	GF2X_MUL(56, temp2, 28, p_10+432+4, 28, q_01+417);
	gf2x_add(56, q_00+357+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+417+24, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+24, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+357+24, 8, q_00+357+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+20, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+20, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+357+20, 8, q_00+357+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+16, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+16, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+357+16, 8, q_00+357+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+12, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+12, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+357+12, 8, q_00+357+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+8, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+8, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+357+8, 8, q_00+357+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+4, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+4, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+357+4, 8, q_00+357+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+0, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+0, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+357+0, 8, q_00+357+0, 8, temp);
	memset(q_01+357, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+432+4, 28, q_00+417);
	GF2X_MUL(56, temp2, 28, p_11+432+4, 28, q_01+417);
	gf2x_add(56, q_01+357+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+417+24, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+24, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+357+24, 8, q_01+357+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+20, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+20, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+357+20, 8, q_01+357+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+16, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+16, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+357+16, 8, q_01+357+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+12, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+12, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+357+12, 8, q_01+357+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+8, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+8, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+357+8, 8, q_01+357+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+4, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+4, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+357+4, 8, q_01+357+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+0, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+0, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+357+0, 8, q_01+357+0, 8, temp);
	memset(q_10+357, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+432+4, 28, q_10+417);
	GF2X_MUL(56, temp2, 28, p_10+432+4, 28, q_11+417);
	gf2x_add(56, q_10+357+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+417+24, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+24, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+357+24, 8, q_10+357+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+20, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+20, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+357+20, 8, q_10+357+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+16, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+16, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+357+16, 8, q_10+357+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+12, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+12, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+357+12, 8, q_10+357+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+8, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+8, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+357+8, 8, q_10+357+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+4, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+4, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+357+4, 8, q_10+357+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+0, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+0, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+357+0, 8, q_10+357+0, 8, temp);
	memset(q_11+357, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+432+4, 28, q_10+417);
	GF2X_MUL(56, temp2, 28, p_11+432+4, 28, q_11+417);
	gf2x_add(56, q_11+357+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+417+24, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+24, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+357+24, 8, q_11+357+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+20, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+20, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+357+20, 8, q_11+357+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+16, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+16, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+357+16, 8, q_11+357+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+12, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+12, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+357+12, 8, q_11+357+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+8, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+8, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+357+8, 8, q_11+357+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+4, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+4, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+357+4, 8, q_11+357+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+0, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+0, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+357+0, 8, q_11+357+0, 8, temp);
	

	// Recombining results: n: 7650, depth: 2
	GF2X_MUL(120, temp, 60, q_00+357+0, 60, p_00+368);
	GF2X_MUL(120, temp2, 60, q_01+357+0, 60, p_10+368);
	gf2x_add(120, p_00+244+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, q_00+357+0, 60, p_01+368);
	GF2X_MUL(120, temp2, 60, q_01+357+0, 60, p_11+368);
	gf2x_add(120, p_01+244+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, q_10+357+0, 60, p_00+368);
	GF2X_MUL(120, temp2, 60, q_11+357+0, 60, p_10+368);
	gf2x_add(120, p_10+244+0, 120, temp, 120, temp2);
	GF2X_MUL(120, temp, 60, q_10+357+0, 60, p_01+368);
	GF2X_MUL(120, temp2, 60, q_11+357+0, 60, p_11+368);
	gf2x_add(120, p_11+244+0, 120, temp, 120, temp2);
	

	// Calculating left operands: n: 15106, depth: 1
	// Digits to shift: 119
	// Displacement: 120
	GF2X_MUL(240, temp, 120, f_sum+1+117, 120, p_00+244);
	GF2X_MUL(240, temp2, 120, g_sum+1+117, 120, p_01+244);
	gf2x_add(237, f_sum+725, 237, temp+3, 237, temp2+3);
	GF2X_MUL(234, temp, 117, p_00+244+3, 117, f_sum+1);
	GF2X_MUL(234, temp2, 117, p_01+244+3, 117, g_sum+1);
	gf2x_add(234, temp, 234, temp, 234, temp2);
	gf2x_add(117, f_sum+725, 117, f_sum+725, 117, temp+117);
	right_bit_shift_n(237, f_sum+725, 34);
	GF2X_MUL(240, temp, 120, f_sum+1+117, 120, p_10+244);
	GF2X_MUL(240, temp2, 120, g_sum+1+117, 120, p_11+244);
	gf2x_add(237, g_sum+725, 237, temp+3, 237, temp2+3);
	GF2X_MUL(234, temp, 117, p_10+244+3, 117, f_sum+1);
	GF2X_MUL(234, temp2, 117, p_11+244+3, 117, g_sum+1);
	gf2x_add(234, temp, 234, temp, 234, temp2);
	gf2x_add(117, g_sum+725, 117, g_sum+725, 117, temp+117);
	right_bit_shift_n(237, g_sum+725, 34);
	

	delta = divstepsx_256(255, delta, f_sum+839, g_sum+839, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+835+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+835+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+835+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+835+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+835+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+835+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+835+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+835+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+827+8, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+827+8, 8, p_01+480);
	gf2x_add(16, f_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+827+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+827+0, 8, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1429, 8, f_sum+1429, 8, temp+8);
	right_bit_shift_n(16, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+827+8, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+827+8, 8, p_11+480);
	gf2x_add(16, g_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+827+0, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+827+0, 8, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1429, 8, g_sum+1429, 8, temp+8);
	right_bit_shift_n(16, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1434, g_sum+1434, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, q_00+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, q_01+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, q_10+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, q_11+465+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_10+480);
	gf2x_add(16, p_00+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_11+480);
	gf2x_add(16, p_01+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_10+480);
	gf2x_add(16, p_10+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_11+480);
	gf2x_add(16, p_11+464+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+811+16, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, g_sum+811+16, 16, p_01+464);
	gf2x_add(32, f_sum+1380+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+811+0, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, g_sum+811+0, 16, p_01+464);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1380, 16, f_sum+1380, 16, temp+16);
	right_bit_shift_n(32, f_sum+1380, 60);
	GF2X_MUL(32, temp, 16, f_sum+811+16, 16, p_10+464);
	GF2X_MUL(32, temp2, 16, g_sum+811+16, 16, p_11+464);
	gf2x_add(32, g_sum+1380+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+811+0, 16, p_10+464);
	GF2X_MUL(32, temp2, 16, g_sum+811+0, 16, p_11+464);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1380, 16, g_sum+1380, 16, temp+16);
	right_bit_shift_n(32, g_sum+1380, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1393, g_sum+1393, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1389+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1389+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1389+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1389+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1381+8, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+8, 8, p_01+480);
	gf2x_add(16, f_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1381+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+0, 8, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1429, 8, f_sum+1429, 8, temp+8);
	right_bit_shift_n(16, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1381+8, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+8, 8, p_11+480);
	gf2x_add(16, g_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1381+0, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+0, 8, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1429, 8, g_sum+1429, 8, temp+8);
	right_bit_shift_n(16, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1434, g_sum+1434, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, q_00+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, q_01+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, q_10+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, q_11+465+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_10+480);
	gf2x_add(16, q_00+449+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_11+480);
	gf2x_add(16, q_01+449+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_10+480);
	gf2x_add(16, q_10+449+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_11+480);
	gf2x_add(16, q_11+449+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+449+0, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, q_01+449+0, 16, p_10+464);
	gf2x_add(32, p_00+432+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+449+0, 16, p_01+464);
	GF2X_MUL(32, temp2, 16, q_01+449+0, 16, p_11+464);
	gf2x_add(32, p_01+432+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+449+0, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, q_11+449+0, 16, p_10+464);
	gf2x_add(32, p_10+432+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+449+0, 16, p_01+464);
	GF2X_MUL(32, temp2, 16, q_11+449+0, 16, p_11+464);
	gf2x_add(32, p_11+432+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 3825, depth: 3
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+783+28, 32, p_00+432);
	GF2X_MUL(64, temp2, 32, g_sum+783+28, 32, p_01+432);
	gf2x_add(60, f_sum+1283, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_00+432+4, 28, f_sum+783);
	GF2X_MUL(56, temp2, 28, p_01+432+4, 28, g_sum+783);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+1283, 28, f_sum+1283, 28, temp+28);
	right_bit_shift_n(60, f_sum+1283, 56);
	GF2X_MUL(64, temp, 32, f_sum+783+28, 32, p_10+432);
	GF2X_MUL(64, temp2, 32, g_sum+783+28, 32, p_11+432);
	gf2x_add(60, g_sum+1283, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_10+432+4, 28, f_sum+783);
	GF2X_MUL(56, temp2, 28, p_11+432+4, 28, g_sum+783);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+1283, 28, g_sum+1283, 28, temp+28);
	right_bit_shift_n(60, g_sum+1283, 56);
	

	delta = divstepsx_256(255, delta, f_sum+1308, g_sum+1308, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1304+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1304+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1304+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1304+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1304+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1304+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1304+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1304+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1296+8, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1296+8, 8, p_01+480);
	gf2x_add(16, f_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1296+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1296+0, 8, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1429, 8, f_sum+1429, 8, temp+8);
	right_bit_shift_n(16, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1296+8, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1296+8, 8, p_11+480);
	gf2x_add(16, g_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1296+0, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1296+0, 8, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1429, 8, g_sum+1429, 8, temp+8);
	right_bit_shift_n(16, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1434, g_sum+1434, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, q_00+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, q_01+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, q_10+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, q_11+465+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_10+480);
	gf2x_add(16, p_00+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_11+480);
	gf2x_add(16, p_01+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_10+480);
	gf2x_add(16, p_10+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_11+480);
	gf2x_add(16, p_11+464+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1284+12, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, g_sum+1284+12, 16, p_01+464);
	gf2x_add(28, f_sum+1380, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+464+4, 12, f_sum+1284);
	GF2X_MUL(24, temp2, 12, p_01+464+4, 12, g_sum+1284);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1380, 12, f_sum+1380, 12, temp+12);
	right_bit_shift_n(28, f_sum+1380, 60);
	GF2X_MUL(32, temp, 16, f_sum+1284+12, 16, p_10+464);
	GF2X_MUL(32, temp2, 16, g_sum+1284+12, 16, p_11+464);
	gf2x_add(28, g_sum+1380, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+464+4, 12, f_sum+1284);
	GF2X_MUL(24, temp2, 12, p_11+464+4, 12, g_sum+1284);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1380, 12, g_sum+1380, 12, temp+12);
	right_bit_shift_n(28, g_sum+1380, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1389, g_sum+1389, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1385+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1385+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1385+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1385+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1385+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1385+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1385+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1385+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1381+4, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+4, 8, p_01+480);
	gf2x_add(12, f_sum+1429, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+480+4, 4, f_sum+1381);
	GF2X_MUL(8, temp2, 4, p_01+480+4, 4, g_sum+1381);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1429, 4, f_sum+1429, 4, temp+4);
	right_bit_shift_n(12, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1381+4, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+4, 8, p_11+480);
	gf2x_add(12, g_sum+1429, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+480+4, 4, f_sum+1381);
	GF2X_MUL(8, temp2, 4, p_11+480+4, 4, g_sum+1381);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1429, 4, g_sum+1429, 4, temp+4);
	right_bit_shift_n(12, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1430, g_sum+1430, q_00+465, q_01+465, q_10+465, q_11+465);

	// Recombining results: n: 765, depth: 5
	memset(q_00+449, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+480+4, 4, q_00+465);
	GF2X_MUL(8, temp2, 4, p_10+480+4, 4, q_01+465);
	gf2x_add(8, q_00+449+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+465+0, 4, p_00+480);
	GF2X_MUL(8, temp2, 4, q_01+465+0, 4, p_10+480);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+449+0, 8, q_00+449+0, 8, temp);
	memset(q_01+449, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+480+4, 4, q_00+465);
	GF2X_MUL(8, temp2, 4, p_11+480+4, 4, q_01+465);
	gf2x_add(8, q_01+449+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+465+0, 4, p_01+480);
	GF2X_MUL(8, temp2, 4, q_01+465+0, 4, p_11+480);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+449+0, 8, q_01+449+0, 8, temp);
	memset(q_10+449, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+480+4, 4, q_10+465);
	GF2X_MUL(8, temp2, 4, p_10+480+4, 4, q_11+465);
	gf2x_add(8, q_10+449+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+465+0, 4, p_00+480);
	GF2X_MUL(8, temp2, 4, q_11+465+0, 4, p_10+480);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+449+0, 8, q_10+449+0, 8, temp);
	memset(q_11+449, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+480+4, 4, q_10+465);
	GF2X_MUL(8, temp2, 4, p_11+480+4, 4, q_11+465);
	gf2x_add(8, q_11+449+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+465+0, 4, p_01+480);
	GF2X_MUL(8, temp2, 4, q_11+465+0, 4, p_11+480);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+449+0, 8, q_11+449+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 4
	memset(q_00+417, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+464+4, 12, q_00+449);
	GF2X_MUL(24, temp2, 12, p_10+464+4, 12, q_01+449);
	gf2x_add(24, q_00+417+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+449+8, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_01+449+8, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+417+8, 8, q_00+417+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+449+4, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_01+449+4, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+417+4, 8, q_00+417+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+449+0, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_01+449+0, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+417+0, 8, q_00+417+0, 8, temp);
	memset(q_01+417, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+464+4, 12, q_00+449);
	GF2X_MUL(24, temp2, 12, p_11+464+4, 12, q_01+449);
	gf2x_add(24, q_01+417+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+449+8, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_01+449+8, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+417+8, 8, q_01+417+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+449+4, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_01+449+4, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+417+4, 8, q_01+417+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+449+0, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_01+449+0, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+417+0, 8, q_01+417+0, 8, temp);
	memset(q_10+417, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+464+4, 12, q_10+449);
	GF2X_MUL(24, temp2, 12, p_10+464+4, 12, q_11+449);
	gf2x_add(24, q_10+417+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+449+8, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_11+449+8, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+417+8, 8, q_10+417+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+449+4, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_11+449+4, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+417+4, 8, q_10+417+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+449+0, 4, p_00+464);
	GF2X_MUL(8, temp2, 4, q_11+449+0, 4, p_10+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+417+0, 8, q_10+417+0, 8, temp);
	memset(q_11+417, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+464+4, 12, q_10+449);
	GF2X_MUL(24, temp2, 12, p_11+464+4, 12, q_11+449);
	gf2x_add(24, q_11+417+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+449+8, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_11+449+8, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+417+8, 8, q_11+417+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+449+4, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_11+449+4, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+417+4, 8, q_11+417+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+449+0, 4, p_01+464);
	GF2X_MUL(8, temp2, 4, q_11+449+0, 4, p_11+464);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+417+0, 8, q_11+417+0, 8, temp);
	

	// Recombining results: n: 3825, depth: 3
	memset(p_00+368, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+432+4, 28, q_00+417);
	GF2X_MUL(56, temp2, 28, p_10+432+4, 28, q_01+417);
	gf2x_add(56, p_00+368+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+417+24, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+24, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+368+24, 8, p_00+368+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+20, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+20, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+368+20, 8, p_00+368+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+16, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+16, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+368+16, 8, p_00+368+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+12, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+12, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+368+12, 8, p_00+368+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+8, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+8, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+368+8, 8, p_00+368+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+4, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+4, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+368+4, 8, p_00+368+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+0, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_01+417+0, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+368+0, 8, p_00+368+0, 8, temp);
	memset(p_01+368, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+432+4, 28, q_00+417);
	GF2X_MUL(56, temp2, 28, p_11+432+4, 28, q_01+417);
	gf2x_add(56, p_01+368+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+417+24, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+24, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+368+24, 8, p_01+368+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+20, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+20, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+368+20, 8, p_01+368+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+16, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+16, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+368+16, 8, p_01+368+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+12, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+12, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+368+12, 8, p_01+368+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+8, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+8, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+368+8, 8, p_01+368+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+4, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+4, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+368+4, 8, p_01+368+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+417+0, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_01+417+0, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+368+0, 8, p_01+368+0, 8, temp);
	memset(p_10+368, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+432+4, 28, q_10+417);
	GF2X_MUL(56, temp2, 28, p_10+432+4, 28, q_11+417);
	gf2x_add(56, p_10+368+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+417+24, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+24, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+368+24, 8, p_10+368+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+20, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+20, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+368+20, 8, p_10+368+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+16, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+16, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+368+16, 8, p_10+368+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+12, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+12, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+368+12, 8, p_10+368+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+8, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+8, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+368+8, 8, p_10+368+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+4, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+4, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+368+4, 8, p_10+368+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+0, 4, p_00+432);
	GF2X_MUL(8, temp2, 4, q_11+417+0, 4, p_10+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+368+0, 8, p_10+368+0, 8, temp);
	memset(p_11+368, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+432+4, 28, q_10+417);
	GF2X_MUL(56, temp2, 28, p_11+432+4, 28, q_11+417);
	gf2x_add(56, p_11+368+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+417+24, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+24, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+368+24, 8, p_11+368+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+20, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+20, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+368+20, 8, p_11+368+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+16, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+16, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+368+16, 8, p_11+368+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+12, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+12, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+368+12, 8, p_11+368+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+8, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+8, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+368+8, 8, p_11+368+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+4, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+4, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+368+4, 8, p_11+368+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+417+0, 4, p_01+432);
	GF2X_MUL(8, temp2, 4, q_11+417+0, 4, p_11+432);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+368+0, 8, p_11+368+0, 8, temp);
	

	// Calculating left operands: n: 7456, depth: 2
	// Digits to shift: 59
	// Displacement: 60
	GF2X_MUL(120, temp, 60, f_sum+726+57, 60, p_00+368);
	GF2X_MUL(120, temp2, 60, g_sum+726+57, 60, p_01+368);
	gf2x_add(117, f_sum+1094, 117, temp+3, 117, temp2+3);
	GF2X_MUL(114, temp, 57, p_00+368+3, 57, f_sum+726);
	GF2X_MUL(114, temp2, 57, p_01+368+3, 57, g_sum+726);
	gf2x_add(114, temp, 114, temp, 114, temp2);
	gf2x_add(57, f_sum+1094, 57, f_sum+1094, 57, temp+57);
	right_bit_shift_n(117, f_sum+1094, 49);
	GF2X_MUL(120, temp, 60, f_sum+726+57, 60, p_10+368);
	GF2X_MUL(120, temp2, 60, g_sum+726+57, 60, p_11+368);
	gf2x_add(117, g_sum+1094, 117, temp+3, 117, temp2+3);
	GF2X_MUL(114, temp, 57, p_10+368+3, 57, f_sum+726);
	GF2X_MUL(114, temp2, 57, p_11+368+3, 57, g_sum+726);
	gf2x_add(114, temp, 114, temp, 114, temp2);
	gf2x_add(57, g_sum+1094, 57, g_sum+1094, 57, temp+57);
	right_bit_shift_n(117, g_sum+1094, 49);
	

	delta = divstepsx_256(255, delta, f_sum+1148, g_sum+1148, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1144+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1144+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1144+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1144+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1144+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1144+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1144+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1144+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1136+8, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1136+8, 8, p_01+480);
	gf2x_add(16, f_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1136+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1136+0, 8, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1429, 8, f_sum+1429, 8, temp+8);
	right_bit_shift_n(16, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1136+8, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1136+8, 8, p_11+480);
	gf2x_add(16, g_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1136+0, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1136+0, 8, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1429, 8, g_sum+1429, 8, temp+8);
	right_bit_shift_n(16, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1434, g_sum+1434, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, q_00+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, q_01+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, q_10+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, q_11+465+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_10+480);
	gf2x_add(16, p_00+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_11+480);
	gf2x_add(16, p_01+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_10+480);
	gf2x_add(16, p_10+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_11+480);
	gf2x_add(16, p_11+464+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1120+16, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, g_sum+1120+16, 16, p_01+464);
	gf2x_add(32, f_sum+1380+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1120+0, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, g_sum+1120+0, 16, p_01+464);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1380, 16, f_sum+1380, 16, temp+16);
	right_bit_shift_n(32, f_sum+1380, 60);
	GF2X_MUL(32, temp, 16, f_sum+1120+16, 16, p_10+464);
	GF2X_MUL(32, temp2, 16, g_sum+1120+16, 16, p_11+464);
	gf2x_add(32, g_sum+1380+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1120+0, 16, p_10+464);
	GF2X_MUL(32, temp2, 16, g_sum+1120+0, 16, p_11+464);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1380, 16, g_sum+1380, 16, temp+16);
	right_bit_shift_n(32, g_sum+1380, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1393, g_sum+1393, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1389+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1389+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1389+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1389+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1389+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1381+8, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+8, 8, p_01+480);
	gf2x_add(16, f_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1381+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+0, 8, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1429, 8, f_sum+1429, 8, temp+8);
	right_bit_shift_n(16, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1381+8, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+8, 8, p_11+480);
	gf2x_add(16, g_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1381+0, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+0, 8, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1429, 8, g_sum+1429, 8, temp+8);
	right_bit_shift_n(16, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1434, g_sum+1434, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, q_00+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, q_01+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, q_10+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, q_11+465+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_10+480);
	gf2x_add(16, q_00+449+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_11+480);
	gf2x_add(16, q_01+449+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_10+480);
	gf2x_add(16, q_10+449+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_11+480);
	gf2x_add(16, q_11+449+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+449+0, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, q_01+449+0, 16, p_10+464);
	gf2x_add(32, p_00+432+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+449+0, 16, p_01+464);
	GF2X_MUL(32, temp2, 16, q_01+449+0, 16, p_11+464);
	gf2x_add(32, p_01+432+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+449+0, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, q_11+449+0, 16, p_10+464);
	gf2x_add(32, p_10+432+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+449+0, 16, p_01+464);
	GF2X_MUL(32, temp2, 16, q_11+449+0, 16, p_11+464);
	gf2x_add(32, p_11+432+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 3631, depth: 3
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+1095+25, 32, p_00+432);
	GF2X_MUL(64, temp2, 32, g_sum+1095+25, 32, p_01+432);
	gf2x_add(57, f_sum+1283, 57, temp+7, 57, temp2+7);
	GF2X_MUL(50, temp, 25, p_00+432+7, 25, f_sum+1095);
	GF2X_MUL(50, temp2, 25, p_01+432+7, 25, g_sum+1095);
	gf2x_add(50, temp, 50, temp, 50, temp2);
	gf2x_add(25, f_sum+1283, 25, f_sum+1283, 25, temp+25);
	right_bit_shift_n(57, f_sum+1283, 56);
	GF2X_MUL(64, temp, 32, f_sum+1095+25, 32, p_10+432);
	GF2X_MUL(64, temp2, 32, g_sum+1095+25, 32, p_11+432);
	gf2x_add(57, g_sum+1283, 57, temp+7, 57, temp2+7);
	GF2X_MUL(50, temp, 25, p_10+432+7, 25, f_sum+1095);
	GF2X_MUL(50, temp2, 25, p_11+432+7, 25, g_sum+1095);
	gf2x_add(50, temp, 50, temp, 50, temp2);
	gf2x_add(25, g_sum+1283, 25, g_sum+1283, 25, temp+25);
	right_bit_shift_n(57, g_sum+1283, 56);
	

	delta = divstepsx_256(255, delta, f_sum+1305, g_sum+1305, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1301+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1301+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1301+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1301+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1301+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1301+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1301+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1301+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1293+8, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1293+8, 8, p_01+480);
	gf2x_add(16, f_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1293+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1293+0, 8, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1429, 8, f_sum+1429, 8, temp+8);
	right_bit_shift_n(16, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1293+8, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1293+8, 8, p_11+480);
	gf2x_add(16, g_sum+1429+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1293+0, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1293+0, 8, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1429, 8, g_sum+1429, 8, temp+8);
	right_bit_shift_n(16, g_sum+1429, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1434, g_sum+1434, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1430+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1430+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1430+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, q_00+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, q_01+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, q_10+465+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, q_11+465+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_10+480);
	gf2x_add(16, p_00+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_01+465+0, 8, p_11+480);
	gf2x_add(16, p_01+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_10+480);
	gf2x_add(16, p_10+464+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+465+0, 8, p_01+480);
	GF2X_MUL(16, temp2, 8, q_11+465+0, 8, p_11+480);
	gf2x_add(16, p_11+464+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1591, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1284+9, 16, p_00+464);
	GF2X_MUL(32, temp2, 16, g_sum+1284+9, 16, p_01+464);
	gf2x_add(25, f_sum+1380, 25, temp+7, 25, temp2+7);
	GF2X_MUL(18, temp, 9, p_00+464+7, 9, f_sum+1284);
	GF2X_MUL(18, temp2, 9, p_01+464+7, 9, g_sum+1284);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(9, f_sum+1380, 9, f_sum+1380, 9, temp+9);
	right_bit_shift_n(25, f_sum+1380, 60);
	GF2X_MUL(32, temp, 16, f_sum+1284+9, 16, p_10+464);
	GF2X_MUL(32, temp2, 16, g_sum+1284+9, 16, p_11+464);
	gf2x_add(25, g_sum+1380, 25, temp+7, 25, temp2+7);
	GF2X_MUL(18, temp, 9, p_10+464+7, 9, f_sum+1284);
	GF2X_MUL(18, temp2, 9, p_11+464+7, 9, g_sum+1284);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(9, g_sum+1380, 9, g_sum+1380, 9, temp+9);
	right_bit_shift_n(25, g_sum+1380, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1386, g_sum+1386, p_00+488, p_01+488, p_10+488, p_11+488);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1382+4, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1382+4, 4, p_01+488);
	gf2x_add(8, f_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1382+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, g_sum+1382+0, 4, p_01+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1454, 4, f_sum+1454, 4, temp+4);
	right_bit_shift_n(8, f_sum+1454, 63);
	GF2X_MUL(8, temp, 4, f_sum+1382+4, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1382+4, 4, p_11+488);
	gf2x_add(8, g_sum+1454+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1382+0, 4, p_10+488);
	GF2X_MUL(8, temp2, 4, g_sum+1382+0, 4, p_11+488);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1454, 4, g_sum+1454, 4, temp+4);
	right_bit_shift_n(8, g_sum+1454, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1455, g_sum+1455, q_00+473, q_01+473, q_10+473, q_11+473);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_10+488);
	gf2x_add(8, p_00+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_01+473+0, 4, p_11+488);
	gf2x_add(8, p_01+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_00+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_10+488);
	gf2x_add(8, p_10+480+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+473+0, 4, p_01+488);
	GF2X_MUL(8, temp2, 4, q_11+473+0, 4, p_11+488);
	gf2x_add(8, p_11+480+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 571, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1381+1, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+1, 8, p_01+480);
	gf2x_add(9, f_sum+1429, 9, temp+7, 9, temp2+7);
	GF2X_MUL(2, temp, 1, p_00+480+7, 1, f_sum+1381);
	GF2X_MUL(2, temp2, 1, p_01+480+7, 1, g_sum+1381);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, f_sum+1429, 1, f_sum+1429, 1, temp+1);
	right_bit_shift_n(9, f_sum+1429, 62);
	GF2X_MUL(16, temp, 8, f_sum+1381+1, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1381+1, 8, p_11+480);
	gf2x_add(9, g_sum+1429, 9, temp+7, 9, temp2+7);
	GF2X_MUL(2, temp, 1, p_10+480+7, 1, f_sum+1381);
	GF2X_MUL(2, temp2, 1, p_11+480+7, 1, g_sum+1381);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, g_sum+1429, 1, g_sum+1429, 1, temp+1);
	right_bit_shift_n(9, g_sum+1429, 62);
	

	delta = divstepsx(61, delta, *(f_sum+1430), *(g_sum+1430), q_00+465, q_01+465, q_10+465, q_11+465);

	// Recombining results: n: 571, depth: 5
	memset(q_00+449, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(2, temp, 1, p_00+480+7, 1, q_00+465);
	GF2X_MUL(2, temp2, 1, p_10+480+7, 1, q_01+465);
	gf2x_add(2, q_00+449+7, 2, temp, 2, temp2);
	GF2X_MUL(2, temp, 1, p_00+480+6, 1, q_00+465);
	GF2X_MUL(2, temp2, 1, p_10+480+6, 1, q_01+465);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+449+6, 2, q_00+449+6, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+480+5, 1, q_00+465);
	GF2X_MUL(2, temp2, 1, p_10+480+5, 1, q_01+465);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+449+5, 2, q_00+449+5, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+480+4, 1, q_00+465);
	GF2X_MUL(2, temp2, 1, p_10+480+4, 1, q_01+465);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+449+4, 2, q_00+449+4, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+480+3, 1, q_00+465);
	GF2X_MUL(2, temp2, 1, p_10+480+3, 1, q_01+465);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+449+3, 2, q_00+449+3, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+480+2, 1, q_00+465);
	GF2X_MUL(2, temp2, 1, p_10+480+2, 1, q_01+465);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+449+2, 2, q_00+449+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+480+1, 1, q_00+465);
	GF2X_MUL(2, temp2, 1, p_10+480+1, 1, q_01+465);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+449+1, 2, q_00+449+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+465+0, 1, p_00+480);
	GF2X_MUL(2, temp2, 1, q_01+465+0, 1, p_10+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+449+0, 2, q_00+449+0, 2, temp);
	memset(q_01+449, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(2, temp, 1, p_01+480+7, 1, q_00+465);
	GF2X_MUL(2, temp2, 1, p_11+480+7, 1, q_01+465);
	gf2x_add(2, q_01+449+7, 2, temp, 2, temp2);
	GF2X_MUL(2, temp, 1, p_01+480+6, 1, q_00+465);
	GF2X_MUL(2, temp2, 1, p_11+480+6, 1, q_01+465);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+449+6, 2, q_01+449+6, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+480+5, 1, q_00+465);
	GF2X_MUL(2, temp2, 1, p_11+480+5, 1, q_01+465);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+449+5, 2, q_01+449+5, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+480+4, 1, q_00+465);
	GF2X_MUL(2, temp2, 1, p_11+480+4, 1, q_01+465);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+449+4, 2, q_01+449+4, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+480+3, 1, q_00+465);
	GF2X_MUL(2, temp2, 1, p_11+480+3, 1, q_01+465);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+449+3, 2, q_01+449+3, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+480+2, 1, q_00+465);
	GF2X_MUL(2, temp2, 1, p_11+480+2, 1, q_01+465);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+449+2, 2, q_01+449+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+480+1, 1, q_00+465);
	GF2X_MUL(2, temp2, 1, p_11+480+1, 1, q_01+465);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+449+1, 2, q_01+449+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+465+0, 1, p_01+480);
	GF2X_MUL(2, temp2, 1, q_01+465+0, 1, p_11+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+449+0, 2, q_01+449+0, 2, temp);
	memset(q_10+449, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(2, temp, 1, p_00+480+7, 1, q_10+465);
	GF2X_MUL(2, temp2, 1, p_10+480+7, 1, q_11+465);
	gf2x_add(2, q_10+449+7, 2, temp, 2, temp2);
	GF2X_MUL(2, temp, 1, p_00+480+6, 1, q_10+465);
	GF2X_MUL(2, temp2, 1, p_10+480+6, 1, q_11+465);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+449+6, 2, q_10+449+6, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+480+5, 1, q_10+465);
	GF2X_MUL(2, temp2, 1, p_10+480+5, 1, q_11+465);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+449+5, 2, q_10+449+5, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+480+4, 1, q_10+465);
	GF2X_MUL(2, temp2, 1, p_10+480+4, 1, q_11+465);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+449+4, 2, q_10+449+4, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+480+3, 1, q_10+465);
	GF2X_MUL(2, temp2, 1, p_10+480+3, 1, q_11+465);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+449+3, 2, q_10+449+3, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+480+2, 1, q_10+465);
	GF2X_MUL(2, temp2, 1, p_10+480+2, 1, q_11+465);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+449+2, 2, q_10+449+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+480+1, 1, q_10+465);
	GF2X_MUL(2, temp2, 1, p_10+480+1, 1, q_11+465);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+449+1, 2, q_10+449+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+465+0, 1, p_00+480);
	GF2X_MUL(2, temp2, 1, q_11+465+0, 1, p_10+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+449+0, 2, q_10+449+0, 2, temp);
	memset(q_11+449, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(2, temp, 1, p_01+480+7, 1, q_10+465);
	GF2X_MUL(2, temp2, 1, p_11+480+7, 1, q_11+465);
	gf2x_add(2, q_11+449+7, 2, temp, 2, temp2);
	GF2X_MUL(2, temp, 1, p_01+480+6, 1, q_10+465);
	GF2X_MUL(2, temp2, 1, p_11+480+6, 1, q_11+465);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+449+6, 2, q_11+449+6, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+480+5, 1, q_10+465);
	GF2X_MUL(2, temp2, 1, p_11+480+5, 1, q_11+465);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+449+5, 2, q_11+449+5, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+480+4, 1, q_10+465);
	GF2X_MUL(2, temp2, 1, p_11+480+4, 1, q_11+465);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+449+4, 2, q_11+449+4, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+480+3, 1, q_10+465);
	GF2X_MUL(2, temp2, 1, p_11+480+3, 1, q_11+465);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+449+3, 2, q_11+449+3, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+480+2, 1, q_10+465);
	GF2X_MUL(2, temp2, 1, p_11+480+2, 1, q_11+465);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+449+2, 2, q_11+449+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+480+1, 1, q_10+465);
	GF2X_MUL(2, temp2, 1, p_11+480+1, 1, q_11+465);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+449+1, 2, q_11+449+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+465+0, 1, p_01+480);
	GF2X_MUL(2, temp2, 1, q_11+465+0, 1, p_11+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+449+0, 2, q_11+449+0, 2, temp);
	

	// Recombining results: n: 1591, depth: 4
	memset(q_00+417, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(18, temp, 9, p_00+464+7, 9, q_00+449);
	GF2X_MUL(18, temp2, 9, p_10+464+7, 9, q_01+449);
	gf2x_add(18, q_00+417+7, 18, temp, 18, temp2);
	GF2X_MUL(14, temp, 7, q_00+449+2, 7, p_00+464);
	GF2X_MUL(14, temp2, 7, q_01+449+2, 7, p_10+464);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_00+417+2, 14, q_00+417+2, 14, temp);
	GF2X_MUL(4, temp, 2, p_00+464+5, 2, q_00+449);
	GF2X_MUL(4, temp2, 2, p_10+464+5, 2, q_01+449);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+417+5, 4, q_00+417+5, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+464+3, 2, q_00+449);
	GF2X_MUL(4, temp2, 2, p_10+464+3, 2, q_01+449);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+417+3, 4, q_00+417+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+464+1, 2, q_00+449);
	GF2X_MUL(4, temp2, 2, p_10+464+1, 2, q_01+449);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+417+1, 4, q_00+417+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_00+449+1, 1, p_00+464);
	GF2X_MUL(2, temp2, 1, q_01+449+1, 1, p_10+464);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+417+1, 2, q_00+417+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+449+0, 1, p_00+464);
	GF2X_MUL(2, temp2, 1, q_01+449+0, 1, p_10+464);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+417+0, 2, q_00+417+0, 2, temp);
	memset(q_01+417, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(18, temp, 9, p_01+464+7, 9, q_00+449);
	GF2X_MUL(18, temp2, 9, p_11+464+7, 9, q_01+449);
	gf2x_add(18, q_01+417+7, 18, temp, 18, temp2);
	GF2X_MUL(14, temp, 7, q_00+449+2, 7, p_01+464);
	GF2X_MUL(14, temp2, 7, q_01+449+2, 7, p_11+464);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_01+417+2, 14, q_01+417+2, 14, temp);
	GF2X_MUL(4, temp, 2, p_01+464+5, 2, q_00+449);
	GF2X_MUL(4, temp2, 2, p_11+464+5, 2, q_01+449);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+417+5, 4, q_01+417+5, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+464+3, 2, q_00+449);
	GF2X_MUL(4, temp2, 2, p_11+464+3, 2, q_01+449);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+417+3, 4, q_01+417+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+464+1, 2, q_00+449);
	GF2X_MUL(4, temp2, 2, p_11+464+1, 2, q_01+449);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+417+1, 4, q_01+417+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_00+449+1, 1, p_01+464);
	GF2X_MUL(2, temp2, 1, q_01+449+1, 1, p_11+464);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+417+1, 2, q_01+417+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+449+0, 1, p_01+464);
	GF2X_MUL(2, temp2, 1, q_01+449+0, 1, p_11+464);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+417+0, 2, q_01+417+0, 2, temp);
	memset(q_10+417, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(18, temp, 9, p_00+464+7, 9, q_10+449);
	GF2X_MUL(18, temp2, 9, p_10+464+7, 9, q_11+449);
	gf2x_add(18, q_10+417+7, 18, temp, 18, temp2);
	GF2X_MUL(14, temp, 7, q_10+449+2, 7, p_00+464);
	GF2X_MUL(14, temp2, 7, q_11+449+2, 7, p_10+464);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_10+417+2, 14, q_10+417+2, 14, temp);
	GF2X_MUL(4, temp, 2, p_00+464+5, 2, q_10+449);
	GF2X_MUL(4, temp2, 2, p_10+464+5, 2, q_11+449);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+417+5, 4, q_10+417+5, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+464+3, 2, q_10+449);
	GF2X_MUL(4, temp2, 2, p_10+464+3, 2, q_11+449);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+417+3, 4, q_10+417+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+464+1, 2, q_10+449);
	GF2X_MUL(4, temp2, 2, p_10+464+1, 2, q_11+449);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+417+1, 4, q_10+417+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_10+449+1, 1, p_00+464);
	GF2X_MUL(2, temp2, 1, q_11+449+1, 1, p_10+464);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+417+1, 2, q_10+417+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+449+0, 1, p_00+464);
	GF2X_MUL(2, temp2, 1, q_11+449+0, 1, p_10+464);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+417+0, 2, q_10+417+0, 2, temp);
	memset(q_11+417, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(18, temp, 9, p_01+464+7, 9, q_10+449);
	GF2X_MUL(18, temp2, 9, p_11+464+7, 9, q_11+449);
	gf2x_add(18, q_11+417+7, 18, temp, 18, temp2);
	GF2X_MUL(14, temp, 7, q_10+449+2, 7, p_01+464);
	GF2X_MUL(14, temp2, 7, q_11+449+2, 7, p_11+464);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_11+417+2, 14, q_11+417+2, 14, temp);
	GF2X_MUL(4, temp, 2, p_01+464+5, 2, q_10+449);
	GF2X_MUL(4, temp2, 2, p_11+464+5, 2, q_11+449);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+417+5, 4, q_11+417+5, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+464+3, 2, q_10+449);
	GF2X_MUL(4, temp2, 2, p_11+464+3, 2, q_11+449);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+417+3, 4, q_11+417+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+464+1, 2, q_10+449);
	GF2X_MUL(4, temp2, 2, p_11+464+1, 2, q_11+449);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+417+1, 4, q_11+417+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_10+449+1, 1, p_01+464);
	GF2X_MUL(2, temp2, 1, q_11+449+1, 1, p_11+464);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+417+1, 2, q_11+417+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+449+0, 1, p_01+464);
	GF2X_MUL(2, temp2, 1, q_11+449+0, 1, p_11+464);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+417+0, 2, q_11+417+0, 2, temp);
	

	// Recombining results: n: 3631, depth: 3
	memset(q_00+357, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(50, temp, 25, p_00+432+7, 25, q_00+417);
	GF2X_MUL(50, temp2, 25, p_10+432+7, 25, q_01+417);
	gf2x_add(50, q_00+357+7, 50, temp, 50, temp2);
	GF2X_MUL(14, temp, 7, q_00+417+18, 7, p_00+432);
	GF2X_MUL(14, temp2, 7, q_01+417+18, 7, p_10+432);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_00+357+18, 14, q_00+357+18, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+417+11, 7, p_00+432);
	GF2X_MUL(14, temp2, 7, q_01+417+11, 7, p_10+432);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_00+357+11, 14, q_00+357+11, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+417+4, 7, p_00+432);
	GF2X_MUL(14, temp2, 7, q_01+417+4, 7, p_10+432);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_00+357+4, 14, q_00+357+4, 14, temp);
	GF2X_MUL(8, temp, 4, p_00+432+3, 4, q_00+417);
	GF2X_MUL(8, temp2, 4, p_10+432+3, 4, q_01+417);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+357+3, 8, q_00+357+3, 8, temp);
	GF2X_MUL(6, temp, 3, q_00+417+1, 3, p_00+432);
	GF2X_MUL(6, temp2, 3, q_01+417+1, 3, p_10+432);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+357+1, 6, q_00+357+1, 6, temp);
	GF2X_MUL(2, temp, 1, p_00+432+2, 1, q_00+417);
	GF2X_MUL(2, temp2, 1, p_10+432+2, 1, q_01+417);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+357+2, 2, q_00+357+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+432+1, 1, q_00+417);
	GF2X_MUL(2, temp2, 1, p_10+432+1, 1, q_01+417);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+357+1, 2, q_00+357+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+417+0, 1, p_00+432);
	GF2X_MUL(2, temp2, 1, q_01+417+0, 1, p_10+432);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+357+0, 2, q_00+357+0, 2, temp);
	memset(q_01+357, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(50, temp, 25, p_01+432+7, 25, q_00+417);
	GF2X_MUL(50, temp2, 25, p_11+432+7, 25, q_01+417);
	gf2x_add(50, q_01+357+7, 50, temp, 50, temp2);
	GF2X_MUL(14, temp, 7, q_00+417+18, 7, p_01+432);
	GF2X_MUL(14, temp2, 7, q_01+417+18, 7, p_11+432);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_01+357+18, 14, q_01+357+18, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+417+11, 7, p_01+432);
	GF2X_MUL(14, temp2, 7, q_01+417+11, 7, p_11+432);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_01+357+11, 14, q_01+357+11, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+417+4, 7, p_01+432);
	GF2X_MUL(14, temp2, 7, q_01+417+4, 7, p_11+432);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_01+357+4, 14, q_01+357+4, 14, temp);
	GF2X_MUL(8, temp, 4, p_01+432+3, 4, q_00+417);
	GF2X_MUL(8, temp2, 4, p_11+432+3, 4, q_01+417);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+357+3, 8, q_01+357+3, 8, temp);
	GF2X_MUL(6, temp, 3, q_00+417+1, 3, p_01+432);
	GF2X_MUL(6, temp2, 3, q_01+417+1, 3, p_11+432);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+357+1, 6, q_01+357+1, 6, temp);
	GF2X_MUL(2, temp, 1, p_01+432+2, 1, q_00+417);
	GF2X_MUL(2, temp2, 1, p_11+432+2, 1, q_01+417);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+357+2, 2, q_01+357+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+432+1, 1, q_00+417);
	GF2X_MUL(2, temp2, 1, p_11+432+1, 1, q_01+417);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+357+1, 2, q_01+357+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+417+0, 1, p_01+432);
	GF2X_MUL(2, temp2, 1, q_01+417+0, 1, p_11+432);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+357+0, 2, q_01+357+0, 2, temp);
	memset(q_10+357, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(50, temp, 25, p_00+432+7, 25, q_10+417);
	GF2X_MUL(50, temp2, 25, p_10+432+7, 25, q_11+417);
	gf2x_add(50, q_10+357+7, 50, temp, 50, temp2);
	GF2X_MUL(14, temp, 7, q_10+417+18, 7, p_00+432);
	GF2X_MUL(14, temp2, 7, q_11+417+18, 7, p_10+432);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_10+357+18, 14, q_10+357+18, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+417+11, 7, p_00+432);
	GF2X_MUL(14, temp2, 7, q_11+417+11, 7, p_10+432);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_10+357+11, 14, q_10+357+11, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+417+4, 7, p_00+432);
	GF2X_MUL(14, temp2, 7, q_11+417+4, 7, p_10+432);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_10+357+4, 14, q_10+357+4, 14, temp);
	GF2X_MUL(8, temp, 4, p_00+432+3, 4, q_10+417);
	GF2X_MUL(8, temp2, 4, p_10+432+3, 4, q_11+417);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+357+3, 8, q_10+357+3, 8, temp);
	GF2X_MUL(6, temp, 3, q_10+417+1, 3, p_00+432);
	GF2X_MUL(6, temp2, 3, q_11+417+1, 3, p_10+432);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+357+1, 6, q_10+357+1, 6, temp);
	GF2X_MUL(2, temp, 1, p_00+432+2, 1, q_10+417);
	GF2X_MUL(2, temp2, 1, p_10+432+2, 1, q_11+417);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+357+2, 2, q_10+357+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+432+1, 1, q_10+417);
	GF2X_MUL(2, temp2, 1, p_10+432+1, 1, q_11+417);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+357+1, 2, q_10+357+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+417+0, 1, p_00+432);
	GF2X_MUL(2, temp2, 1, q_11+417+0, 1, p_10+432);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+357+0, 2, q_10+357+0, 2, temp);
	memset(q_11+357, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(50, temp, 25, p_01+432+7, 25, q_10+417);
	GF2X_MUL(50, temp2, 25, p_11+432+7, 25, q_11+417);
	gf2x_add(50, q_11+357+7, 50, temp, 50, temp2);
	GF2X_MUL(14, temp, 7, q_10+417+18, 7, p_01+432);
	GF2X_MUL(14, temp2, 7, q_11+417+18, 7, p_11+432);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_11+357+18, 14, q_11+357+18, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+417+11, 7, p_01+432);
	GF2X_MUL(14, temp2, 7, q_11+417+11, 7, p_11+432);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_11+357+11, 14, q_11+357+11, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+417+4, 7, p_01+432);
	GF2X_MUL(14, temp2, 7, q_11+417+4, 7, p_11+432);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_11+357+4, 14, q_11+357+4, 14, temp);
	GF2X_MUL(8, temp, 4, p_01+432+3, 4, q_10+417);
	GF2X_MUL(8, temp2, 4, p_11+432+3, 4, q_11+417);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+357+3, 8, q_11+357+3, 8, temp);
	GF2X_MUL(6, temp, 3, q_10+417+1, 3, p_01+432);
	GF2X_MUL(6, temp2, 3, q_11+417+1, 3, p_11+432);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+357+1, 6, q_11+357+1, 6, temp);
	GF2X_MUL(2, temp, 1, p_01+432+2, 1, q_10+417);
	GF2X_MUL(2, temp2, 1, p_11+432+2, 1, q_11+417);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+357+2, 2, q_11+357+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+432+1, 1, q_10+417);
	GF2X_MUL(2, temp2, 1, p_11+432+1, 1, q_11+417);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+357+1, 2, q_11+357+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+417+0, 1, p_01+432);
	GF2X_MUL(2, temp2, 1, q_11+417+0, 1, p_11+432);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+357+0, 2, q_11+357+0, 2, temp);
	

	// Recombining results: n: 7456, depth: 2
	memset(q_00+237, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(114, temp, 57, p_00+368+3, 57, q_00+357);
	GF2X_MUL(114, temp2, 57, p_10+368+3, 57, q_01+357);
	gf2x_add(114, q_00+237+3, 114, temp, 114, temp2);
	GF2X_MUL(6, temp, 3, q_00+357+54, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_01+357+54, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+237+54, 6, q_00+237+54, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+51, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_01+357+51, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+237+51, 6, q_00+237+51, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+48, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_01+357+48, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+237+48, 6, q_00+237+48, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+45, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_01+357+45, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+237+45, 6, q_00+237+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+42, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_01+357+42, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+237+42, 6, q_00+237+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+39, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_01+357+39, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+237+39, 6, q_00+237+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+36, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_01+357+36, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+237+36, 6, q_00+237+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+33, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_01+357+33, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+237+33, 6, q_00+237+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+30, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_01+357+30, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+237+30, 6, q_00+237+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+27, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_01+357+27, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+237+27, 6, q_00+237+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+24, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_01+357+24, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+237+24, 6, q_00+237+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+21, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_01+357+21, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+237+21, 6, q_00+237+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+18, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_01+357+18, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+237+18, 6, q_00+237+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+15, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_01+357+15, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+237+15, 6, q_00+237+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+12, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_01+357+12, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+237+12, 6, q_00+237+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+9, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_01+357+9, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+237+9, 6, q_00+237+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+6, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_01+357+6, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+237+6, 6, q_00+237+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+3, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_01+357+3, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+237+3, 6, q_00+237+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+0, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_01+357+0, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+237+0, 6, q_00+237+0, 6, temp);
	memset(q_01+237, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(114, temp, 57, p_01+368+3, 57, q_00+357);
	GF2X_MUL(114, temp2, 57, p_11+368+3, 57, q_01+357);
	gf2x_add(114, q_01+237+3, 114, temp, 114, temp2);
	GF2X_MUL(6, temp, 3, q_00+357+54, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_01+357+54, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+237+54, 6, q_01+237+54, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+51, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_01+357+51, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+237+51, 6, q_01+237+51, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+48, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_01+357+48, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+237+48, 6, q_01+237+48, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+45, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_01+357+45, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+237+45, 6, q_01+237+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+42, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_01+357+42, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+237+42, 6, q_01+237+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+39, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_01+357+39, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+237+39, 6, q_01+237+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+36, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_01+357+36, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+237+36, 6, q_01+237+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+33, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_01+357+33, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+237+33, 6, q_01+237+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+30, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_01+357+30, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+237+30, 6, q_01+237+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+27, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_01+357+27, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+237+27, 6, q_01+237+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+24, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_01+357+24, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+237+24, 6, q_01+237+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+21, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_01+357+21, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+237+21, 6, q_01+237+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+18, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_01+357+18, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+237+18, 6, q_01+237+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+15, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_01+357+15, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+237+15, 6, q_01+237+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+12, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_01+357+12, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+237+12, 6, q_01+237+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+9, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_01+357+9, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+237+9, 6, q_01+237+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+6, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_01+357+6, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+237+6, 6, q_01+237+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+3, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_01+357+3, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+237+3, 6, q_01+237+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+357+0, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_01+357+0, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+237+0, 6, q_01+237+0, 6, temp);
	memset(q_10+237, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(114, temp, 57, p_00+368+3, 57, q_10+357);
	GF2X_MUL(114, temp2, 57, p_10+368+3, 57, q_11+357);
	gf2x_add(114, q_10+237+3, 114, temp, 114, temp2);
	GF2X_MUL(6, temp, 3, q_10+357+54, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_11+357+54, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+237+54, 6, q_10+237+54, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+51, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_11+357+51, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+237+51, 6, q_10+237+51, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+48, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_11+357+48, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+237+48, 6, q_10+237+48, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+45, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_11+357+45, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+237+45, 6, q_10+237+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+42, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_11+357+42, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+237+42, 6, q_10+237+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+39, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_11+357+39, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+237+39, 6, q_10+237+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+36, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_11+357+36, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+237+36, 6, q_10+237+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+33, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_11+357+33, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+237+33, 6, q_10+237+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+30, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_11+357+30, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+237+30, 6, q_10+237+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+27, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_11+357+27, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+237+27, 6, q_10+237+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+24, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_11+357+24, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+237+24, 6, q_10+237+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+21, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_11+357+21, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+237+21, 6, q_10+237+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+18, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_11+357+18, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+237+18, 6, q_10+237+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+15, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_11+357+15, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+237+15, 6, q_10+237+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+12, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_11+357+12, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+237+12, 6, q_10+237+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+9, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_11+357+9, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+237+9, 6, q_10+237+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+6, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_11+357+6, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+237+6, 6, q_10+237+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+3, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_11+357+3, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+237+3, 6, q_10+237+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+0, 3, p_00+368);
	GF2X_MUL(6, temp2, 3, q_11+357+0, 3, p_10+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+237+0, 6, q_10+237+0, 6, temp);
	memset(q_11+237, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(114, temp, 57, p_01+368+3, 57, q_10+357);
	GF2X_MUL(114, temp2, 57, p_11+368+3, 57, q_11+357);
	gf2x_add(114, q_11+237+3, 114, temp, 114, temp2);
	GF2X_MUL(6, temp, 3, q_10+357+54, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_11+357+54, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+237+54, 6, q_11+237+54, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+51, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_11+357+51, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+237+51, 6, q_11+237+51, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+48, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_11+357+48, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+237+48, 6, q_11+237+48, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+45, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_11+357+45, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+237+45, 6, q_11+237+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+42, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_11+357+42, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+237+42, 6, q_11+237+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+39, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_11+357+39, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+237+39, 6, q_11+237+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+36, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_11+357+36, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+237+36, 6, q_11+237+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+33, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_11+357+33, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+237+33, 6, q_11+237+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+30, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_11+357+30, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+237+30, 6, q_11+237+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+27, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_11+357+27, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+237+27, 6, q_11+237+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+24, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_11+357+24, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+237+24, 6, q_11+237+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+21, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_11+357+21, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+237+21, 6, q_11+237+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+18, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_11+357+18, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+237+18, 6, q_11+237+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+15, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_11+357+15, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+237+15, 6, q_11+237+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+12, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_11+357+12, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+237+12, 6, q_11+237+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+9, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_11+357+9, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+237+9, 6, q_11+237+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+6, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_11+357+6, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+237+6, 6, q_11+237+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+3, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_11+357+3, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+237+3, 6, q_11+237+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+357+0, 3, p_01+368);
	GF2X_MUL(6, temp2, 3, q_11+357+0, 3, p_11+368);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+237+0, 6, q_11+237+0, 6, temp);
	

	// Recombining results: n: 15106, depth: 1
	memset(q_00+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(234, temp, 117, p_00+244+3, 117, q_00+237);
	GF2X_MUL(234, temp2, 117, p_10+244+3, 117, q_01+237);
	gf2x_add(234, q_00+0+3, 234, temp, 234, temp2);
	GF2X_MUL(6, temp, 3, q_00+237+114, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+114, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+114, 6, q_00+0+114, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+111, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+111, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+111, 6, q_00+0+111, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+108, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+108, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+108, 6, q_00+0+108, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+105, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+105, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+105, 6, q_00+0+105, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+102, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+102, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+102, 6, q_00+0+102, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+99, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+99, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+99, 6, q_00+0+99, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+96, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+96, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+96, 6, q_00+0+96, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+93, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+93, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+93, 6, q_00+0+93, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+90, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+90, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+90, 6, q_00+0+90, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+87, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+87, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+87, 6, q_00+0+87, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+84, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+84, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+84, 6, q_00+0+84, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+81, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+81, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+81, 6, q_00+0+81, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+78, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+78, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+78, 6, q_00+0+78, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+75, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+75, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+75, 6, q_00+0+75, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+72, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+72, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+72, 6, q_00+0+72, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+69, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+69, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+69, 6, q_00+0+69, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+66, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+66, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+66, 6, q_00+0+66, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+63, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+63, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+63, 6, q_00+0+63, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+60, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+60, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+60, 6, q_00+0+60, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+57, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+57, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+57, 6, q_00+0+57, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+54, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+54, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+54, 6, q_00+0+54, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+51, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+51, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+51, 6, q_00+0+51, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+48, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+48, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+48, 6, q_00+0+48, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+45, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+45, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+45, 6, q_00+0+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+42, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+42, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+42, 6, q_00+0+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+39, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+39, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+39, 6, q_00+0+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+36, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+36, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+36, 6, q_00+0+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+33, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+33, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+33, 6, q_00+0+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+30, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+30, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+30, 6, q_00+0+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+27, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+27, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+27, 6, q_00+0+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+24, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+24, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+24, 6, q_00+0+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+21, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+21, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+21, 6, q_00+0+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+18, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+18, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+18, 6, q_00+0+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+15, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+15, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+15, 6, q_00+0+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+12, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+12, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+12, 6, q_00+0+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+9, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+9, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+9, 6, q_00+0+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+6, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+6, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+6, 6, q_00+0+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+3, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+3, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+3, 6, q_00+0+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+0, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_01+237+0, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+0, 6, q_00+0+0, 6, temp);
	memset(q_01+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(234, temp, 117, p_01+244+3, 117, q_00+237);
	GF2X_MUL(234, temp2, 117, p_11+244+3, 117, q_01+237);
	gf2x_add(234, q_01+0+3, 234, temp, 234, temp2);
	GF2X_MUL(6, temp, 3, q_00+237+114, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+114, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+114, 6, q_01+0+114, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+111, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+111, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+111, 6, q_01+0+111, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+108, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+108, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+108, 6, q_01+0+108, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+105, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+105, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+105, 6, q_01+0+105, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+102, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+102, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+102, 6, q_01+0+102, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+99, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+99, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+99, 6, q_01+0+99, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+96, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+96, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+96, 6, q_01+0+96, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+93, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+93, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+93, 6, q_01+0+93, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+90, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+90, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+90, 6, q_01+0+90, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+87, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+87, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+87, 6, q_01+0+87, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+84, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+84, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+84, 6, q_01+0+84, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+81, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+81, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+81, 6, q_01+0+81, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+78, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+78, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+78, 6, q_01+0+78, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+75, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+75, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+75, 6, q_01+0+75, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+72, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+72, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+72, 6, q_01+0+72, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+69, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+69, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+69, 6, q_01+0+69, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+66, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+66, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+66, 6, q_01+0+66, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+63, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+63, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+63, 6, q_01+0+63, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+60, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+60, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+60, 6, q_01+0+60, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+57, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+57, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+57, 6, q_01+0+57, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+54, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+54, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+54, 6, q_01+0+54, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+51, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+51, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+51, 6, q_01+0+51, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+48, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+48, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+48, 6, q_01+0+48, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+45, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+45, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+45, 6, q_01+0+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+42, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+42, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+42, 6, q_01+0+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+39, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+39, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+39, 6, q_01+0+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+36, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+36, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+36, 6, q_01+0+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+33, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+33, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+33, 6, q_01+0+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+30, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+30, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+30, 6, q_01+0+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+27, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+27, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+27, 6, q_01+0+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+24, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+24, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+24, 6, q_01+0+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+21, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+21, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+21, 6, q_01+0+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+18, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+18, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+18, 6, q_01+0+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+15, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+15, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+15, 6, q_01+0+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+12, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+12, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+12, 6, q_01+0+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+9, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+9, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+9, 6, q_01+0+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+6, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+6, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+6, 6, q_01+0+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+3, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+3, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+3, 6, q_01+0+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+237+0, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_01+237+0, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+0, 6, q_01+0+0, 6, temp);
	memset(q_10+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(234, temp, 117, p_00+244+3, 117, q_10+237);
	GF2X_MUL(234, temp2, 117, p_10+244+3, 117, q_11+237);
	gf2x_add(234, q_10+0+3, 234, temp, 234, temp2);
	GF2X_MUL(6, temp, 3, q_10+237+114, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+114, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+114, 6, q_10+0+114, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+111, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+111, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+111, 6, q_10+0+111, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+108, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+108, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+108, 6, q_10+0+108, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+105, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+105, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+105, 6, q_10+0+105, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+102, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+102, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+102, 6, q_10+0+102, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+99, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+99, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+99, 6, q_10+0+99, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+96, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+96, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+96, 6, q_10+0+96, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+93, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+93, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+93, 6, q_10+0+93, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+90, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+90, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+90, 6, q_10+0+90, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+87, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+87, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+87, 6, q_10+0+87, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+84, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+84, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+84, 6, q_10+0+84, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+81, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+81, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+81, 6, q_10+0+81, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+78, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+78, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+78, 6, q_10+0+78, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+75, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+75, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+75, 6, q_10+0+75, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+72, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+72, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+72, 6, q_10+0+72, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+69, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+69, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+69, 6, q_10+0+69, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+66, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+66, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+66, 6, q_10+0+66, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+63, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+63, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+63, 6, q_10+0+63, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+60, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+60, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+60, 6, q_10+0+60, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+57, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+57, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+57, 6, q_10+0+57, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+54, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+54, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+54, 6, q_10+0+54, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+51, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+51, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+51, 6, q_10+0+51, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+48, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+48, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+48, 6, q_10+0+48, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+45, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+45, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+45, 6, q_10+0+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+42, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+42, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+42, 6, q_10+0+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+39, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+39, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+39, 6, q_10+0+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+36, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+36, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+36, 6, q_10+0+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+33, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+33, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+33, 6, q_10+0+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+30, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+30, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+30, 6, q_10+0+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+27, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+27, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+27, 6, q_10+0+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+24, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+24, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+24, 6, q_10+0+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+21, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+21, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+21, 6, q_10+0+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+18, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+18, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+18, 6, q_10+0+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+15, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+15, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+15, 6, q_10+0+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+12, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+12, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+12, 6, q_10+0+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+9, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+9, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+9, 6, q_10+0+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+6, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+6, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+6, 6, q_10+0+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+3, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+3, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+3, 6, q_10+0+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+0, 3, p_00+244);
	GF2X_MUL(6, temp2, 3, q_11+237+0, 3, p_10+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+0, 6, q_10+0+0, 6, temp);
	memset(q_11+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(234, temp, 117, p_01+244+3, 117, q_10+237);
	GF2X_MUL(234, temp2, 117, p_11+244+3, 117, q_11+237);
	gf2x_add(234, q_11+0+3, 234, temp, 234, temp2);
	GF2X_MUL(6, temp, 3, q_10+237+114, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+114, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+114, 6, q_11+0+114, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+111, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+111, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+111, 6, q_11+0+111, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+108, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+108, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+108, 6, q_11+0+108, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+105, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+105, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+105, 6, q_11+0+105, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+102, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+102, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+102, 6, q_11+0+102, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+99, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+99, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+99, 6, q_11+0+99, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+96, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+96, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+96, 6, q_11+0+96, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+93, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+93, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+93, 6, q_11+0+93, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+90, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+90, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+90, 6, q_11+0+90, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+87, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+87, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+87, 6, q_11+0+87, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+84, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+84, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+84, 6, q_11+0+84, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+81, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+81, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+81, 6, q_11+0+81, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+78, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+78, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+78, 6, q_11+0+78, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+75, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+75, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+75, 6, q_11+0+75, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+72, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+72, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+72, 6, q_11+0+72, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+69, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+69, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+69, 6, q_11+0+69, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+66, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+66, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+66, 6, q_11+0+66, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+63, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+63, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+63, 6, q_11+0+63, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+60, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+60, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+60, 6, q_11+0+60, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+57, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+57, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+57, 6, q_11+0+57, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+54, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+54, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+54, 6, q_11+0+54, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+51, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+51, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+51, 6, q_11+0+51, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+48, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+48, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+48, 6, q_11+0+48, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+45, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+45, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+45, 6, q_11+0+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+42, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+42, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+42, 6, q_11+0+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+39, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+39, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+39, 6, q_11+0+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+36, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+36, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+36, 6, q_11+0+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+33, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+33, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+33, 6, q_11+0+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+30, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+30, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+30, 6, q_11+0+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+27, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+27, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+27, 6, q_11+0+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+24, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+24, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+24, 6, q_11+0+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+21, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+21, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+21, 6, q_11+0+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+18, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+18, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+18, 6, q_11+0+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+15, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+15, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+15, 6, q_11+0+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+12, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+12, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+12, 6, q_11+0+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+9, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+9, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+9, 6, q_11+0+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+6, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+6, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+6, 6, q_11+0+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+3, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+3, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+3, 6, q_11+0+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+237+0, 3, p_01+244);
	GF2X_MUL(6, temp2, 3, q_11+237+0, 3, p_11+244);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+0, 6, q_11+0+0, 6, temp);
	

	// Recombining results: n: 30661, depth: 0
	memset(t_00+0, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(474, temp, 237, p_00+0+7, 237, q_00+0);
	GF2X_MUL(474, temp2, 237, p_10+0+7, 237, q_01+0);
	gf2x_add(474, t_00+0+6, 474, temp, 474, temp2);
	GF2X_MUL(14, temp, 7, q_00+0+230, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+230, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+229, 14, t_00+0+229, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+223, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+223, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+222, 14, t_00+0+222, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+216, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+216, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+215, 14, t_00+0+215, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+209, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+209, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+208, 14, t_00+0+208, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+202, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+202, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+201, 14, t_00+0+201, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+195, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+195, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+194, 14, t_00+0+194, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+188, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+188, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+187, 14, t_00+0+187, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+181, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+181, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+180, 14, t_00+0+180, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+174, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+174, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+173, 14, t_00+0+173, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+167, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+167, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+166, 14, t_00+0+166, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+160, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+160, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+159, 14, t_00+0+159, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+153, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+153, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+152, 14, t_00+0+152, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+146, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+146, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+145, 14, t_00+0+145, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+139, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+139, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+138, 14, t_00+0+138, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+132, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+132, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+131, 14, t_00+0+131, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+125, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+125, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+124, 14, t_00+0+124, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+118, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+118, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+117, 14, t_00+0+117, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+111, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+111, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+110, 14, t_00+0+110, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+104, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+104, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+103, 14, t_00+0+103, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+97, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+97, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+96, 14, t_00+0+96, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+90, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+90, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+89, 14, t_00+0+89, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+83, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+83, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+82, 14, t_00+0+82, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+76, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+76, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+75, 14, t_00+0+75, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+69, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+69, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+68, 14, t_00+0+68, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+62, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+62, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+61, 14, t_00+0+61, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+55, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+55, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+54, 14, t_00+0+54, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+48, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+48, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+47, 14, t_00+0+47, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+41, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+41, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+40, 14, t_00+0+40, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+34, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+34, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+33, 14, t_00+0+33, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+27, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+27, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+26, 14, t_00+0+26, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+20, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+20, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+19, 14, t_00+0+19, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+13, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+13, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+12, 14, t_00+0+12, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+6, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_01+0+6, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_00+0+5, 14, t_00+0+5, 14, temp);
	GF2X_MUL(12, temp, 6, p_00+0+1, 6, q_00+0);
	GF2X_MUL(12, temp2, 6, p_10+0+1, 6, q_01+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+0, 12, t_00+0+0, 12, temp);
	GF2X_MUL(2, temp, 1, q_00+0+5, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, q_01+0+5, 1, p_10+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_00+0+4, 2, t_00+0+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+0+4, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, q_01+0+4, 1, p_10+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_00+0+3, 2, t_00+0+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+0+3, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, q_01+0+3, 1, p_10+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_00+0+2, 2, t_00+0+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+0+2, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, q_01+0+2, 1, p_10+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_00+0+1, 2, t_00+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+0+1, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, q_01+0+1, 1, p_10+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_00+0+0, 2, t_00+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+0+0, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, q_01+0+0, 1, p_10+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, t_00+0, 1, t_00+0, 1, temp+1);
	memset(t_01+0, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(474, temp, 237, p_01+0+7, 237, q_00+0);
	GF2X_MUL(474, temp2, 237, p_11+0+7, 237, q_01+0);
	gf2x_add(474, t_01+0+6, 474, temp, 474, temp2);
	GF2X_MUL(14, temp, 7, q_00+0+230, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+230, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+229, 14, t_01+0+229, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+223, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+223, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+222, 14, t_01+0+222, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+216, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+216, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+215, 14, t_01+0+215, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+209, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+209, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+208, 14, t_01+0+208, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+202, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+202, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+201, 14, t_01+0+201, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+195, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+195, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+194, 14, t_01+0+194, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+188, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+188, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+187, 14, t_01+0+187, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+181, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+181, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+180, 14, t_01+0+180, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+174, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+174, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+173, 14, t_01+0+173, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+167, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+167, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+166, 14, t_01+0+166, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+160, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+160, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+159, 14, t_01+0+159, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+153, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+153, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+152, 14, t_01+0+152, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+146, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+146, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+145, 14, t_01+0+145, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+139, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+139, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+138, 14, t_01+0+138, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+132, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+132, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+131, 14, t_01+0+131, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+125, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+125, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+124, 14, t_01+0+124, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+118, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+118, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+117, 14, t_01+0+117, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+111, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+111, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+110, 14, t_01+0+110, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+104, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+104, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+103, 14, t_01+0+103, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+97, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+97, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+96, 14, t_01+0+96, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+90, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+90, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+89, 14, t_01+0+89, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+83, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+83, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+82, 14, t_01+0+82, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+76, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+76, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+75, 14, t_01+0+75, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+69, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+69, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+68, 14, t_01+0+68, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+62, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+62, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+61, 14, t_01+0+61, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+55, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+55, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+54, 14, t_01+0+54, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+48, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+48, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+47, 14, t_01+0+47, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+41, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+41, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+40, 14, t_01+0+40, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+34, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+34, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+33, 14, t_01+0+33, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+27, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+27, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+26, 14, t_01+0+26, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+20, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+20, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+19, 14, t_01+0+19, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+13, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+13, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+12, 14, t_01+0+12, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+0+6, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_01+0+6, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_01+0+5, 14, t_01+0+5, 14, temp);
	GF2X_MUL(12, temp, 6, p_01+0+1, 6, q_00+0);
	GF2X_MUL(12, temp2, 6, p_11+0+1, 6, q_01+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+0, 12, t_01+0+0, 12, temp);
	GF2X_MUL(2, temp, 1, q_00+0+5, 1, p_01+0);
	GF2X_MUL(2, temp2, 1, q_01+0+5, 1, p_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_01+0+4, 2, t_01+0+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+0+4, 1, p_01+0);
	GF2X_MUL(2, temp2, 1, q_01+0+4, 1, p_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_01+0+3, 2, t_01+0+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+0+3, 1, p_01+0);
	GF2X_MUL(2, temp2, 1, q_01+0+3, 1, p_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_01+0+2, 2, t_01+0+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+0+2, 1, p_01+0);
	GF2X_MUL(2, temp2, 1, q_01+0+2, 1, p_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_01+0+1, 2, t_01+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+0+1, 1, p_01+0);
	GF2X_MUL(2, temp2, 1, q_01+0+1, 1, p_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_01+0+0, 2, t_01+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+0+0, 1, p_01+0);
	GF2X_MUL(2, temp2, 1, q_01+0+0, 1, p_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, t_01+0, 1, t_01+0, 1, temp+1);
	memset(t_10+0, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(474, temp, 237, p_00+0+7, 237, q_10+0);
	GF2X_MUL(474, temp2, 237, p_10+0+7, 237, q_11+0);
	gf2x_add(474, t_10+0+6, 474, temp, 474, temp2);
	GF2X_MUL(14, temp, 7, q_10+0+230, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+230, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+229, 14, t_10+0+229, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+223, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+223, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+222, 14, t_10+0+222, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+216, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+216, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+215, 14, t_10+0+215, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+209, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+209, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+208, 14, t_10+0+208, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+202, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+202, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+201, 14, t_10+0+201, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+195, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+195, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+194, 14, t_10+0+194, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+188, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+188, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+187, 14, t_10+0+187, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+181, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+181, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+180, 14, t_10+0+180, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+174, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+174, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+173, 14, t_10+0+173, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+167, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+167, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+166, 14, t_10+0+166, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+160, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+160, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+159, 14, t_10+0+159, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+153, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+153, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+152, 14, t_10+0+152, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+146, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+146, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+145, 14, t_10+0+145, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+139, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+139, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+138, 14, t_10+0+138, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+132, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+132, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+131, 14, t_10+0+131, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+125, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+125, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+124, 14, t_10+0+124, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+118, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+118, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+117, 14, t_10+0+117, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+111, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+111, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+110, 14, t_10+0+110, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+104, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+104, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+103, 14, t_10+0+103, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+97, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+97, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+96, 14, t_10+0+96, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+90, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+90, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+89, 14, t_10+0+89, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+83, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+83, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+82, 14, t_10+0+82, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+76, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+76, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+75, 14, t_10+0+75, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+69, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+69, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+68, 14, t_10+0+68, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+62, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+62, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+61, 14, t_10+0+61, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+55, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+55, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+54, 14, t_10+0+54, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+48, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+48, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+47, 14, t_10+0+47, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+41, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+41, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+40, 14, t_10+0+40, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+34, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+34, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+33, 14, t_10+0+33, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+27, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+27, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+26, 14, t_10+0+26, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+20, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+20, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+19, 14, t_10+0+19, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+13, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+13, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+12, 14, t_10+0+12, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+6, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, q_11+0+6, 7, p_10+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_10+0+5, 14, t_10+0+5, 14, temp);
	GF2X_MUL(12, temp, 6, p_00+0+1, 6, q_10+0);
	GF2X_MUL(12, temp2, 6, p_10+0+1, 6, q_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+0, 12, t_10+0+0, 12, temp);
	GF2X_MUL(2, temp, 1, q_10+0+5, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, q_11+0+5, 1, p_10+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_10+0+4, 2, t_10+0+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+0+4, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, q_11+0+4, 1, p_10+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_10+0+3, 2, t_10+0+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+0+3, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, q_11+0+3, 1, p_10+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_10+0+2, 2, t_10+0+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+0+2, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, q_11+0+2, 1, p_10+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_10+0+1, 2, t_10+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+0+1, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, q_11+0+1, 1, p_10+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_10+0+0, 2, t_10+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+0+0, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, q_11+0+0, 1, p_10+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, t_10+0, 1, t_10+0, 1, temp+1);
	memset(t_11+0, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(474, temp, 237, p_01+0+7, 237, q_10+0);
	GF2X_MUL(474, temp2, 237, p_11+0+7, 237, q_11+0);
	gf2x_add(474, t_11+0+6, 474, temp, 474, temp2);
	GF2X_MUL(14, temp, 7, q_10+0+230, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+230, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+229, 14, t_11+0+229, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+223, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+223, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+222, 14, t_11+0+222, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+216, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+216, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+215, 14, t_11+0+215, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+209, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+209, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+208, 14, t_11+0+208, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+202, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+202, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+201, 14, t_11+0+201, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+195, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+195, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+194, 14, t_11+0+194, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+188, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+188, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+187, 14, t_11+0+187, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+181, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+181, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+180, 14, t_11+0+180, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+174, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+174, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+173, 14, t_11+0+173, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+167, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+167, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+166, 14, t_11+0+166, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+160, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+160, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+159, 14, t_11+0+159, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+153, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+153, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+152, 14, t_11+0+152, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+146, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+146, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+145, 14, t_11+0+145, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+139, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+139, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+138, 14, t_11+0+138, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+132, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+132, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+131, 14, t_11+0+131, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+125, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+125, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+124, 14, t_11+0+124, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+118, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+118, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+117, 14, t_11+0+117, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+111, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+111, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+110, 14, t_11+0+110, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+104, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+104, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+103, 14, t_11+0+103, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+97, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+97, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+96, 14, t_11+0+96, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+90, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+90, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+89, 14, t_11+0+89, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+83, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+83, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+82, 14, t_11+0+82, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+76, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+76, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+75, 14, t_11+0+75, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+69, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+69, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+68, 14, t_11+0+68, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+62, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+62, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+61, 14, t_11+0+61, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+55, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+55, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+54, 14, t_11+0+54, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+48, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+48, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+47, 14, t_11+0+47, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+41, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+41, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+40, 14, t_11+0+40, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+34, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+34, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+33, 14, t_11+0+33, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+27, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+27, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+26, 14, t_11+0+26, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+20, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+20, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+19, 14, t_11+0+19, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+13, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+13, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+12, 14, t_11+0+12, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+0+6, 7, p_01+0);
	GF2X_MUL(14, temp2, 7, q_11+0+6, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, t_11+0+5, 14, t_11+0+5, 14, temp);
	GF2X_MUL(12, temp, 6, p_01+0+1, 6, q_10+0);
	GF2X_MUL(12, temp2, 6, p_11+0+1, 6, q_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+0, 12, t_11+0+0, 12, temp);
	GF2X_MUL(2, temp, 1, q_10+0+5, 1, p_01+0);
	GF2X_MUL(2, temp2, 1, q_11+0+5, 1, p_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_11+0+4, 2, t_11+0+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+0+4, 1, p_01+0);
	GF2X_MUL(2, temp2, 1, q_11+0+4, 1, p_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_11+0+3, 2, t_11+0+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+0+3, 1, p_01+0);
	GF2X_MUL(2, temp2, 1, q_11+0+3, 1, p_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_11+0+2, 2, t_11+0+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+0+2, 1, p_01+0);
	GF2X_MUL(2, temp2, 1, q_11+0+2, 1, p_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_11+0+1, 2, t_11+0+1, 2, temp);
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