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
	
	DIGIT f_sum[700];
	DIGIT g_sum[700];
	
	DIGIT temp[456];
	DIGIT temp2[456];
	

	delta = divstepsx_256(255, delta, f+221, g+221, p_00+232, p_01+232, p_10+232, p_11+232);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f+217+4, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g+217+4, 4, p_01+232);
	gf2x_add(8, f_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+217+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g+217+0, 4, p_01+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+686, 4, f_sum+686, 4, temp+4);
	right_bit_shift_n(8, f_sum+686, 63);
	GF2X_MUL(8, temp, 4, f+217+4, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g+217+4, 4, p_11+232);
	gf2x_add(8, g_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+217+0, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g+217+0, 4, p_11+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+686, 4, g_sum+686, 4, temp+4);
	right_bit_shift_n(8, g_sum+686, 63);
	

	delta = divstepsx_256(255, delta, f_sum+687, g_sum+687, q_00+218, q_01+218, q_10+218, q_11+218);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_10+232);
	gf2x_add(8, p_00+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_11+232);
	gf2x_add(8, p_01+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_10+232);
	gf2x_add(8, p_10+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_11+232);
	gf2x_add(8, p_11+224+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f+209+8, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, g+209+8, 8, p_01+224);
	gf2x_add(16, f_sum+661+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f+209+0, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, g+209+0, 8, p_01+224);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+661, 8, f_sum+661, 8, temp+8);
	right_bit_shift_n(16, f_sum+661, 62);
	GF2X_MUL(16, temp, 8, f+209+8, 8, p_10+224);
	GF2X_MUL(16, temp2, 8, g+209+8, 8, p_11+224);
	gf2x_add(16, g_sum+661+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f+209+0, 8, p_10+224);
	GF2X_MUL(16, temp2, 8, g+209+0, 8, p_11+224);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+661, 8, g_sum+661, 8, temp+8);
	right_bit_shift_n(16, g_sum+661, 62);
	

	delta = divstepsx_256(255, delta, f_sum+666, g_sum+666, p_00+232, p_01+232, p_10+232, p_11+232);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+662+4, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+4, 4, p_01+232);
	gf2x_add(8, f_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+662+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+0, 4, p_01+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+686, 4, f_sum+686, 4, temp+4);
	right_bit_shift_n(8, f_sum+686, 63);
	GF2X_MUL(8, temp, 4, f_sum+662+4, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+4, 4, p_11+232);
	gf2x_add(8, g_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+662+0, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+0, 4, p_11+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+686, 4, g_sum+686, 4, temp+4);
	right_bit_shift_n(8, g_sum+686, 63);
	

	delta = divstepsx_256(255, delta, f_sum+687, g_sum+687, q_00+218, q_01+218, q_10+218, q_11+218);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_10+232);
	gf2x_add(8, q_00+210+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_11+232);
	gf2x_add(8, q_01+210+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_10+232);
	gf2x_add(8, q_10+210+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_11+232);
	gf2x_add(8, q_11+210+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 4
	GF2X_MUL(16, temp, 8, q_00+210+0, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, q_01+210+0, 8, p_10+224);
	gf2x_add(16, p_00+208+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+210+0, 8, p_01+224);
	GF2X_MUL(16, temp2, 8, q_01+210+0, 8, p_11+224);
	gf2x_add(16, p_01+208+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+210+0, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, q_11+210+0, 8, p_10+224);
	gf2x_add(16, p_10+208+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+210+0, 8, p_01+224);
	GF2X_MUL(16, temp2, 8, q_11+210+0, 8, p_11+224);
	gf2x_add(16, p_11+208+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 3
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f+193+16, 16, p_00+208);
	GF2X_MUL(32, temp2, 16, g+193+16, 16, p_01+208);
	gf2x_add(32, f_sum+612+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f+193+0, 16, p_00+208);
	GF2X_MUL(32, temp2, 16, g+193+0, 16, p_01+208);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+612, 16, f_sum+612, 16, temp+16);
	right_bit_shift_n(32, f_sum+612, 60);
	GF2X_MUL(32, temp, 16, f+193+16, 16, p_10+208);
	GF2X_MUL(32, temp2, 16, g+193+16, 16, p_11+208);
	gf2x_add(32, g_sum+612+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f+193+0, 16, p_10+208);
	GF2X_MUL(32, temp2, 16, g+193+0, 16, p_11+208);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+612, 16, g_sum+612, 16, temp+16);
	right_bit_shift_n(32, g_sum+612, 60);
	

	delta = divstepsx_256(255, delta, f_sum+625, g_sum+625, p_00+232, p_01+232, p_10+232, p_11+232);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+621+4, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+621+4, 4, p_01+232);
	gf2x_add(8, f_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+621+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+621+0, 4, p_01+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+686, 4, f_sum+686, 4, temp+4);
	right_bit_shift_n(8, f_sum+686, 63);
	GF2X_MUL(8, temp, 4, f_sum+621+4, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+621+4, 4, p_11+232);
	gf2x_add(8, g_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+621+0, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+621+0, 4, p_11+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+686, 4, g_sum+686, 4, temp+4);
	right_bit_shift_n(8, g_sum+686, 63);
	

	delta = divstepsx_256(255, delta, f_sum+687, g_sum+687, q_00+218, q_01+218, q_10+218, q_11+218);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_10+232);
	gf2x_add(8, p_00+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_11+232);
	gf2x_add(8, p_01+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_10+232);
	gf2x_add(8, p_10+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_11+232);
	gf2x_add(8, p_11+224+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+613+8, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, g_sum+613+8, 8, p_01+224);
	gf2x_add(16, f_sum+661+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+613+0, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, g_sum+613+0, 8, p_01+224);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+661, 8, f_sum+661, 8, temp+8);
	right_bit_shift_n(16, f_sum+661, 62);
	GF2X_MUL(16, temp, 8, f_sum+613+8, 8, p_10+224);
	GF2X_MUL(16, temp2, 8, g_sum+613+8, 8, p_11+224);
	gf2x_add(16, g_sum+661+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+613+0, 8, p_10+224);
	GF2X_MUL(16, temp2, 8, g_sum+613+0, 8, p_11+224);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+661, 8, g_sum+661, 8, temp+8);
	right_bit_shift_n(16, g_sum+661, 62);
	

	delta = divstepsx_256(255, delta, f_sum+666, g_sum+666, p_00+232, p_01+232, p_10+232, p_11+232);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+662+4, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+4, 4, p_01+232);
	gf2x_add(8, f_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+662+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+0, 4, p_01+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+686, 4, f_sum+686, 4, temp+4);
	right_bit_shift_n(8, f_sum+686, 63);
	GF2X_MUL(8, temp, 4, f_sum+662+4, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+4, 4, p_11+232);
	gf2x_add(8, g_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+662+0, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+0, 4, p_11+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+686, 4, g_sum+686, 4, temp+4);
	right_bit_shift_n(8, g_sum+686, 63);
	

	delta = divstepsx_256(255, delta, f_sum+687, g_sum+687, q_00+218, q_01+218, q_10+218, q_11+218);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_10+232);
	gf2x_add(8, q_00+210+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_11+232);
	gf2x_add(8, q_01+210+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_10+232);
	gf2x_add(8, q_10+210+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_11+232);
	gf2x_add(8, q_11+210+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 4
	GF2X_MUL(16, temp, 8, q_00+210+0, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, q_01+210+0, 8, p_10+224);
	gf2x_add(16, q_00+194+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+210+0, 8, p_01+224);
	GF2X_MUL(16, temp2, 8, q_01+210+0, 8, p_11+224);
	gf2x_add(16, q_01+194+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+210+0, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, q_11+210+0, 8, p_10+224);
	gf2x_add(16, q_10+194+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+210+0, 8, p_01+224);
	GF2X_MUL(16, temp2, 8, q_11+210+0, 8, p_11+224);
	gf2x_add(16, q_11+194+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 3
	GF2X_MUL(32, temp, 16, q_00+194+0, 16, p_00+208);
	GF2X_MUL(32, temp2, 16, q_01+194+0, 16, p_10+208);
	gf2x_add(32, p_00+176+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+194+0, 16, p_01+208);
	GF2X_MUL(32, temp2, 16, q_01+194+0, 16, p_11+208);
	gf2x_add(32, p_01+176+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+194+0, 16, p_00+208);
	GF2X_MUL(32, temp2, 16, q_11+194+0, 16, p_10+208);
	gf2x_add(32, p_10+176+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+194+0, 16, p_01+208);
	GF2X_MUL(32, temp2, 16, q_11+194+0, 16, p_11+208);
	gf2x_add(32, p_11+176+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 3825, depth: 2
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f+165+28, 32, p_00+176);
	GF2X_MUL(64, temp2, 32, g+165+28, 32, p_01+176);
	gf2x_add(60, f_sum+519, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_00+176+4, 28, f+165);
	GF2X_MUL(56, temp2, 28, p_01+176+4, 28, g+165);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+519, 28, f_sum+519, 28, temp+28);
	right_bit_shift_n(60, f_sum+519, 56);
	GF2X_MUL(64, temp, 32, f+165+28, 32, p_10+176);
	GF2X_MUL(64, temp2, 32, g+165+28, 32, p_11+176);
	gf2x_add(60, g_sum+519, 60, temp+4, 60, temp2+4);
	GF2X_MUL(56, temp, 28, p_10+176+4, 28, f+165);
	GF2X_MUL(56, temp2, 28, p_11+176+4, 28, g+165);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+519, 28, g_sum+519, 28, temp+28);
	right_bit_shift_n(60, g_sum+519, 56);
	

	delta = divstepsx_256(255, delta, f_sum+544, g_sum+544, p_00+232, p_01+232, p_10+232, p_11+232);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+540+4, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+540+4, 4, p_01+232);
	gf2x_add(8, f_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+540+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+540+0, 4, p_01+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+686, 4, f_sum+686, 4, temp+4);
	right_bit_shift_n(8, f_sum+686, 63);
	GF2X_MUL(8, temp, 4, f_sum+540+4, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+540+4, 4, p_11+232);
	gf2x_add(8, g_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+540+0, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+540+0, 4, p_11+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+686, 4, g_sum+686, 4, temp+4);
	right_bit_shift_n(8, g_sum+686, 63);
	

	delta = divstepsx_256(255, delta, f_sum+687, g_sum+687, q_00+218, q_01+218, q_10+218, q_11+218);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_10+232);
	gf2x_add(8, p_00+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_11+232);
	gf2x_add(8, p_01+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_10+232);
	gf2x_add(8, p_10+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_11+232);
	gf2x_add(8, p_11+224+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+532+8, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, g_sum+532+8, 8, p_01+224);
	gf2x_add(16, f_sum+661+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+532+0, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, g_sum+532+0, 8, p_01+224);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+661, 8, f_sum+661, 8, temp+8);
	right_bit_shift_n(16, f_sum+661, 62);
	GF2X_MUL(16, temp, 8, f_sum+532+8, 8, p_10+224);
	GF2X_MUL(16, temp2, 8, g_sum+532+8, 8, p_11+224);
	gf2x_add(16, g_sum+661+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+532+0, 8, p_10+224);
	GF2X_MUL(16, temp2, 8, g_sum+532+0, 8, p_11+224);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+661, 8, g_sum+661, 8, temp+8);
	right_bit_shift_n(16, g_sum+661, 62);
	

	delta = divstepsx_256(255, delta, f_sum+666, g_sum+666, p_00+232, p_01+232, p_10+232, p_11+232);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+662+4, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+4, 4, p_01+232);
	gf2x_add(8, f_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+662+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+0, 4, p_01+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+686, 4, f_sum+686, 4, temp+4);
	right_bit_shift_n(8, f_sum+686, 63);
	GF2X_MUL(8, temp, 4, f_sum+662+4, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+4, 4, p_11+232);
	gf2x_add(8, g_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+662+0, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+0, 4, p_11+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+686, 4, g_sum+686, 4, temp+4);
	right_bit_shift_n(8, g_sum+686, 63);
	

	delta = divstepsx_256(255, delta, f_sum+687, g_sum+687, q_00+218, q_01+218, q_10+218, q_11+218);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_10+232);
	gf2x_add(8, q_00+210+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_11+232);
	gf2x_add(8, q_01+210+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_10+232);
	gf2x_add(8, q_10+210+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_11+232);
	gf2x_add(8, q_11+210+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 4
	GF2X_MUL(16, temp, 8, q_00+210+0, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, q_01+210+0, 8, p_10+224);
	gf2x_add(16, p_00+208+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+210+0, 8, p_01+224);
	GF2X_MUL(16, temp2, 8, q_01+210+0, 8, p_11+224);
	gf2x_add(16, p_01+208+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+210+0, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, q_11+210+0, 8, p_10+224);
	gf2x_add(16, p_10+208+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+210+0, 8, p_01+224);
	GF2X_MUL(16, temp2, 8, q_11+210+0, 8, p_11+224);
	gf2x_add(16, p_11+208+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 3
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+520+12, 16, p_00+208);
	GF2X_MUL(32, temp2, 16, g_sum+520+12, 16, p_01+208);
	gf2x_add(28, f_sum+612, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+208+4, 12, f_sum+520);
	GF2X_MUL(24, temp2, 12, p_01+208+4, 12, g_sum+520);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+612, 12, f_sum+612, 12, temp+12);
	right_bit_shift_n(28, f_sum+612, 60);
	GF2X_MUL(32, temp, 16, f_sum+520+12, 16, p_10+208);
	GF2X_MUL(32, temp2, 16, g_sum+520+12, 16, p_11+208);
	gf2x_add(28, g_sum+612, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+208+4, 12, f_sum+520);
	GF2X_MUL(24, temp2, 12, p_11+208+4, 12, g_sum+520);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+612, 12, g_sum+612, 12, temp+12);
	right_bit_shift_n(28, g_sum+612, 60);
	

	delta = divstepsx_256(255, delta, f_sum+621, g_sum+621, p_00+232, p_01+232, p_10+232, p_11+232);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+617+4, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+617+4, 4, p_01+232);
	gf2x_add(8, f_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+617+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+617+0, 4, p_01+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+686, 4, f_sum+686, 4, temp+4);
	right_bit_shift_n(8, f_sum+686, 63);
	GF2X_MUL(8, temp, 4, f_sum+617+4, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+617+4, 4, p_11+232);
	gf2x_add(8, g_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+617+0, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+617+0, 4, p_11+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+686, 4, g_sum+686, 4, temp+4);
	right_bit_shift_n(8, g_sum+686, 63);
	

	delta = divstepsx_256(255, delta, f_sum+687, g_sum+687, q_00+218, q_01+218, q_10+218, q_11+218);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_10+232);
	gf2x_add(8, p_00+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_11+232);
	gf2x_add(8, p_01+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_10+232);
	gf2x_add(8, p_10+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_11+232);
	gf2x_add(8, p_11+224+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+613+4, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, g_sum+613+4, 8, p_01+224);
	gf2x_add(12, f_sum+661, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+224+4, 4, f_sum+613);
	GF2X_MUL(8, temp2, 4, p_01+224+4, 4, g_sum+613);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+661, 4, f_sum+661, 4, temp+4);
	right_bit_shift_n(12, f_sum+661, 62);
	GF2X_MUL(16, temp, 8, f_sum+613+4, 8, p_10+224);
	GF2X_MUL(16, temp2, 8, g_sum+613+4, 8, p_11+224);
	gf2x_add(12, g_sum+661, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+224+4, 4, f_sum+613);
	GF2X_MUL(8, temp2, 4, p_11+224+4, 4, g_sum+613);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+661, 4, g_sum+661, 4, temp+4);
	right_bit_shift_n(12, g_sum+661, 62);
	

	delta = divstepsx_256(255, delta, f_sum+662, g_sum+662, q_00+210, q_01+210, q_10+210, q_11+210);

	// Recombining results: n: 765, depth: 4
	memset(q_00+194, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+224+4, 4, q_00+210);
	GF2X_MUL(8, temp2, 4, p_10+224+4, 4, q_01+210);
	gf2x_add(8, q_00+194+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+210+0, 4, p_00+224);
	GF2X_MUL(8, temp2, 4, q_01+210+0, 4, p_10+224);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+194+0, 8, q_00+194+0, 8, temp);
	memset(q_01+194, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+224+4, 4, q_00+210);
	GF2X_MUL(8, temp2, 4, p_11+224+4, 4, q_01+210);
	gf2x_add(8, q_01+194+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+210+0, 4, p_01+224);
	GF2X_MUL(8, temp2, 4, q_01+210+0, 4, p_11+224);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+194+0, 8, q_01+194+0, 8, temp);
	memset(q_10+194, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+224+4, 4, q_10+210);
	GF2X_MUL(8, temp2, 4, p_10+224+4, 4, q_11+210);
	gf2x_add(8, q_10+194+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+210+0, 4, p_00+224);
	GF2X_MUL(8, temp2, 4, q_11+210+0, 4, p_10+224);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+194+0, 8, q_10+194+0, 8, temp);
	memset(q_11+194, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+224+4, 4, q_10+210);
	GF2X_MUL(8, temp2, 4, p_11+224+4, 4, q_11+210);
	gf2x_add(8, q_11+194+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+210+0, 4, p_01+224);
	GF2X_MUL(8, temp2, 4, q_11+210+0, 4, p_11+224);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+194+0, 8, q_11+194+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 3
	memset(q_00+166, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+208+4, 12, q_00+194);
	GF2X_MUL(24, temp2, 12, p_10+208+4, 12, q_01+194);
	gf2x_add(24, q_00+166+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+194+8, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_01+194+8, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+166+8, 8, q_00+166+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+194+4, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_01+194+4, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+166+4, 8, q_00+166+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+194+0, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_01+194+0, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+166+0, 8, q_00+166+0, 8, temp);
	memset(q_01+166, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+208+4, 12, q_00+194);
	GF2X_MUL(24, temp2, 12, p_11+208+4, 12, q_01+194);
	gf2x_add(24, q_01+166+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+194+8, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_01+194+8, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+166+8, 8, q_01+166+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+194+4, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_01+194+4, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+166+4, 8, q_01+166+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+194+0, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_01+194+0, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+166+0, 8, q_01+166+0, 8, temp);
	memset(q_10+166, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+208+4, 12, q_10+194);
	GF2X_MUL(24, temp2, 12, p_10+208+4, 12, q_11+194);
	gf2x_add(24, q_10+166+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+194+8, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_11+194+8, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+166+8, 8, q_10+166+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+194+4, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_11+194+4, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+166+4, 8, q_10+166+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+194+0, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_11+194+0, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+166+0, 8, q_10+166+0, 8, temp);
	memset(q_11+166, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+208+4, 12, q_10+194);
	GF2X_MUL(24, temp2, 12, p_11+208+4, 12, q_11+194);
	gf2x_add(24, q_11+166+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+194+8, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_11+194+8, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+166+8, 8, q_11+166+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+194+4, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_11+194+4, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+166+4, 8, q_11+166+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+194+0, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_11+194+0, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+166+0, 8, q_11+166+0, 8, temp);
	

	// Recombining results: n: 3825, depth: 2
	memset(p_00+116, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+176+4, 28, q_00+166);
	GF2X_MUL(56, temp2, 28, p_10+176+4, 28, q_01+166);
	gf2x_add(56, p_00+116+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+166+24, 4, p_00+176);
	GF2X_MUL(8, temp2, 4, q_01+166+24, 4, p_10+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+116+24, 8, p_00+116+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+166+20, 4, p_00+176);
	GF2X_MUL(8, temp2, 4, q_01+166+20, 4, p_10+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+116+20, 8, p_00+116+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+166+16, 4, p_00+176);
	GF2X_MUL(8, temp2, 4, q_01+166+16, 4, p_10+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+116+16, 8, p_00+116+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+166+12, 4, p_00+176);
	GF2X_MUL(8, temp2, 4, q_01+166+12, 4, p_10+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+116+12, 8, p_00+116+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+166+8, 4, p_00+176);
	GF2X_MUL(8, temp2, 4, q_01+166+8, 4, p_10+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+116+8, 8, p_00+116+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+166+4, 4, p_00+176);
	GF2X_MUL(8, temp2, 4, q_01+166+4, 4, p_10+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+116+4, 8, p_00+116+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+166+0, 4, p_00+176);
	GF2X_MUL(8, temp2, 4, q_01+166+0, 4, p_10+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+116+0, 8, p_00+116+0, 8, temp);
	memset(p_01+116, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+176+4, 28, q_00+166);
	GF2X_MUL(56, temp2, 28, p_11+176+4, 28, q_01+166);
	gf2x_add(56, p_01+116+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_00+166+24, 4, p_01+176);
	GF2X_MUL(8, temp2, 4, q_01+166+24, 4, p_11+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+116+24, 8, p_01+116+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+166+20, 4, p_01+176);
	GF2X_MUL(8, temp2, 4, q_01+166+20, 4, p_11+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+116+20, 8, p_01+116+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+166+16, 4, p_01+176);
	GF2X_MUL(8, temp2, 4, q_01+166+16, 4, p_11+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+116+16, 8, p_01+116+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+166+12, 4, p_01+176);
	GF2X_MUL(8, temp2, 4, q_01+166+12, 4, p_11+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+116+12, 8, p_01+116+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+166+8, 4, p_01+176);
	GF2X_MUL(8, temp2, 4, q_01+166+8, 4, p_11+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+116+8, 8, p_01+116+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+166+4, 4, p_01+176);
	GF2X_MUL(8, temp2, 4, q_01+166+4, 4, p_11+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+116+4, 8, p_01+116+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+166+0, 4, p_01+176);
	GF2X_MUL(8, temp2, 4, q_01+166+0, 4, p_11+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+116+0, 8, p_01+116+0, 8, temp);
	memset(p_10+116, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_00+176+4, 28, q_10+166);
	GF2X_MUL(56, temp2, 28, p_10+176+4, 28, q_11+166);
	gf2x_add(56, p_10+116+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+166+24, 4, p_00+176);
	GF2X_MUL(8, temp2, 4, q_11+166+24, 4, p_10+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+116+24, 8, p_10+116+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+166+20, 4, p_00+176);
	GF2X_MUL(8, temp2, 4, q_11+166+20, 4, p_10+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+116+20, 8, p_10+116+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+166+16, 4, p_00+176);
	GF2X_MUL(8, temp2, 4, q_11+166+16, 4, p_10+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+116+16, 8, p_10+116+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+166+12, 4, p_00+176);
	GF2X_MUL(8, temp2, 4, q_11+166+12, 4, p_10+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+116+12, 8, p_10+116+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+166+8, 4, p_00+176);
	GF2X_MUL(8, temp2, 4, q_11+166+8, 4, p_10+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+116+8, 8, p_10+116+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+166+4, 4, p_00+176);
	GF2X_MUL(8, temp2, 4, q_11+166+4, 4, p_10+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+116+4, 8, p_10+116+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+166+0, 4, p_00+176);
	GF2X_MUL(8, temp2, 4, q_11+166+0, 4, p_10+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+116+0, 8, p_10+116+0, 8, temp);
	memset(p_11+116, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(56, temp, 28, p_01+176+4, 28, q_10+166);
	GF2X_MUL(56, temp2, 28, p_11+176+4, 28, q_11+166);
	gf2x_add(56, p_11+116+4, 56, temp, 56, temp2);
	GF2X_MUL(8, temp, 4, q_10+166+24, 4, p_01+176);
	GF2X_MUL(8, temp2, 4, q_11+166+24, 4, p_11+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+116+24, 8, p_11+116+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+166+20, 4, p_01+176);
	GF2X_MUL(8, temp2, 4, q_11+166+20, 4, p_11+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+116+20, 8, p_11+116+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+166+16, 4, p_01+176);
	GF2X_MUL(8, temp2, 4, q_11+166+16, 4, p_11+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+116+16, 8, p_11+116+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+166+12, 4, p_01+176);
	GF2X_MUL(8, temp2, 4, q_11+166+12, 4, p_11+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+116+12, 8, p_11+116+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+166+8, 4, p_01+176);
	GF2X_MUL(8, temp2, 4, q_11+166+8, 4, p_11+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+116+8, 8, p_11+116+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+166+4, 4, p_01+176);
	GF2X_MUL(8, temp2, 4, q_11+166+4, 4, p_11+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+116+4, 8, p_11+116+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+166+0, 4, p_01+176);
	GF2X_MUL(8, temp2, 4, q_11+166+0, 4, p_11+176);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+116+0, 8, p_11+116+0, 8, temp);
	

	// Calculating left operands: n: 7395, depth: 1
	// Digits to shift: 59
	// Displacement: 60
	GF2X_MUL(120, temp, 60, f+109+56, 60, p_00+116);
	GF2X_MUL(120, temp2, 60, g+109+56, 60, p_01+116);
	gf2x_add(116, f_sum+342, 116, temp+4, 116, temp2+4);
	GF2X_MUL(112, temp, 56, p_00+116+4, 56, f+109);
	GF2X_MUL(112, temp2, 56, p_01+116+4, 56, g+109);
	gf2x_add(112, temp, 112, temp, 112, temp2);
	gf2x_add(56, f_sum+342, 56, f_sum+342, 56, temp+56);
	right_bit_shift_n(116, f_sum+342, 49);
	GF2X_MUL(120, temp, 60, f+109+56, 60, p_10+116);
	GF2X_MUL(120, temp2, 60, g+109+56, 60, p_11+116);
	gf2x_add(116, g_sum+342, 116, temp+4, 116, temp2+4);
	GF2X_MUL(112, temp, 56, p_10+116+4, 56, f+109);
	GF2X_MUL(112, temp2, 56, p_11+116+4, 56, g+109);
	gf2x_add(112, temp, 112, temp, 112, temp2);
	gf2x_add(56, g_sum+342, 56, g_sum+342, 56, temp+56);
	right_bit_shift_n(116, g_sum+342, 49);
	

	delta = divstepsx_256(255, delta, f_sum+395, g_sum+395, p_00+232, p_01+232, p_10+232, p_11+232);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+391+4, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+391+4, 4, p_01+232);
	gf2x_add(8, f_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+391+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+391+0, 4, p_01+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+686, 4, f_sum+686, 4, temp+4);
	right_bit_shift_n(8, f_sum+686, 63);
	GF2X_MUL(8, temp, 4, f_sum+391+4, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+391+4, 4, p_11+232);
	gf2x_add(8, g_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+391+0, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+391+0, 4, p_11+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+686, 4, g_sum+686, 4, temp+4);
	right_bit_shift_n(8, g_sum+686, 63);
	

	delta = divstepsx_256(255, delta, f_sum+687, g_sum+687, q_00+218, q_01+218, q_10+218, q_11+218);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_10+232);
	gf2x_add(8, p_00+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_11+232);
	gf2x_add(8, p_01+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_10+232);
	gf2x_add(8, p_10+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_11+232);
	gf2x_add(8, p_11+224+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+383+8, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, g_sum+383+8, 8, p_01+224);
	gf2x_add(16, f_sum+661+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+383+0, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, g_sum+383+0, 8, p_01+224);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+661, 8, f_sum+661, 8, temp+8);
	right_bit_shift_n(16, f_sum+661, 62);
	GF2X_MUL(16, temp, 8, f_sum+383+8, 8, p_10+224);
	GF2X_MUL(16, temp2, 8, g_sum+383+8, 8, p_11+224);
	gf2x_add(16, g_sum+661+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+383+0, 8, p_10+224);
	GF2X_MUL(16, temp2, 8, g_sum+383+0, 8, p_11+224);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+661, 8, g_sum+661, 8, temp+8);
	right_bit_shift_n(16, g_sum+661, 62);
	

	delta = divstepsx_256(255, delta, f_sum+666, g_sum+666, p_00+232, p_01+232, p_10+232, p_11+232);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+662+4, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+4, 4, p_01+232);
	gf2x_add(8, f_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+662+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+0, 4, p_01+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+686, 4, f_sum+686, 4, temp+4);
	right_bit_shift_n(8, f_sum+686, 63);
	GF2X_MUL(8, temp, 4, f_sum+662+4, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+4, 4, p_11+232);
	gf2x_add(8, g_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+662+0, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+0, 4, p_11+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+686, 4, g_sum+686, 4, temp+4);
	right_bit_shift_n(8, g_sum+686, 63);
	

	delta = divstepsx_256(255, delta, f_sum+687, g_sum+687, q_00+218, q_01+218, q_10+218, q_11+218);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_10+232);
	gf2x_add(8, q_00+210+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_11+232);
	gf2x_add(8, q_01+210+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_10+232);
	gf2x_add(8, q_10+210+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_11+232);
	gf2x_add(8, q_11+210+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 4
	GF2X_MUL(16, temp, 8, q_00+210+0, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, q_01+210+0, 8, p_10+224);
	gf2x_add(16, p_00+208+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+210+0, 8, p_01+224);
	GF2X_MUL(16, temp2, 8, q_01+210+0, 8, p_11+224);
	gf2x_add(16, p_01+208+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+210+0, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, q_11+210+0, 8, p_10+224);
	gf2x_add(16, p_10+208+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+210+0, 8, p_01+224);
	GF2X_MUL(16, temp2, 8, q_11+210+0, 8, p_11+224);
	gf2x_add(16, p_11+208+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 3
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+371+12, 16, p_00+208);
	GF2X_MUL(32, temp2, 16, g_sum+371+12, 16, p_01+208);
	gf2x_add(28, f_sum+612, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+208+4, 12, f_sum+371);
	GF2X_MUL(24, temp2, 12, p_01+208+4, 12, g_sum+371);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+612, 12, f_sum+612, 12, temp+12);
	right_bit_shift_n(28, f_sum+612, 60);
	GF2X_MUL(32, temp, 16, f_sum+371+12, 16, p_10+208);
	GF2X_MUL(32, temp2, 16, g_sum+371+12, 16, p_11+208);
	gf2x_add(28, g_sum+612, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+208+4, 12, f_sum+371);
	GF2X_MUL(24, temp2, 12, p_11+208+4, 12, g_sum+371);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+612, 12, g_sum+612, 12, temp+12);
	right_bit_shift_n(28, g_sum+612, 60);
	

	delta = divstepsx_256(255, delta, f_sum+621, g_sum+621, p_00+232, p_01+232, p_10+232, p_11+232);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+617+4, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+617+4, 4, p_01+232);
	gf2x_add(8, f_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+617+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+617+0, 4, p_01+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+686, 4, f_sum+686, 4, temp+4);
	right_bit_shift_n(8, f_sum+686, 63);
	GF2X_MUL(8, temp, 4, f_sum+617+4, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+617+4, 4, p_11+232);
	gf2x_add(8, g_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+617+0, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+617+0, 4, p_11+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+686, 4, g_sum+686, 4, temp+4);
	right_bit_shift_n(8, g_sum+686, 63);
	

	delta = divstepsx_256(255, delta, f_sum+687, g_sum+687, q_00+218, q_01+218, q_10+218, q_11+218);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_10+232);
	gf2x_add(8, p_00+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_11+232);
	gf2x_add(8, p_01+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_10+232);
	gf2x_add(8, p_10+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_11+232);
	gf2x_add(8, p_11+224+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+613+4, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, g_sum+613+4, 8, p_01+224);
	gf2x_add(12, f_sum+661, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+224+4, 4, f_sum+613);
	GF2X_MUL(8, temp2, 4, p_01+224+4, 4, g_sum+613);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+661, 4, f_sum+661, 4, temp+4);
	right_bit_shift_n(12, f_sum+661, 62);
	GF2X_MUL(16, temp, 8, f_sum+613+4, 8, p_10+224);
	GF2X_MUL(16, temp2, 8, g_sum+613+4, 8, p_11+224);
	gf2x_add(12, g_sum+661, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+224+4, 4, f_sum+613);
	GF2X_MUL(8, temp2, 4, p_11+224+4, 4, g_sum+613);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+661, 4, g_sum+661, 4, temp+4);
	right_bit_shift_n(12, g_sum+661, 62);
	

	delta = divstepsx_256(255, delta, f_sum+662, g_sum+662, q_00+210, q_01+210, q_10+210, q_11+210);

	// Recombining results: n: 765, depth: 4
	memset(q_00+194, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+224+4, 4, q_00+210);
	GF2X_MUL(8, temp2, 4, p_10+224+4, 4, q_01+210);
	gf2x_add(8, q_00+194+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+210+0, 4, p_00+224);
	GF2X_MUL(8, temp2, 4, q_01+210+0, 4, p_10+224);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+194+0, 8, q_00+194+0, 8, temp);
	memset(q_01+194, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+224+4, 4, q_00+210);
	GF2X_MUL(8, temp2, 4, p_11+224+4, 4, q_01+210);
	gf2x_add(8, q_01+194+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+210+0, 4, p_01+224);
	GF2X_MUL(8, temp2, 4, q_01+210+0, 4, p_11+224);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+194+0, 8, q_01+194+0, 8, temp);
	memset(q_10+194, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+224+4, 4, q_10+210);
	GF2X_MUL(8, temp2, 4, p_10+224+4, 4, q_11+210);
	gf2x_add(8, q_10+194+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+210+0, 4, p_00+224);
	GF2X_MUL(8, temp2, 4, q_11+210+0, 4, p_10+224);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+194+0, 8, q_10+194+0, 8, temp);
	memset(q_11+194, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+224+4, 4, q_10+210);
	GF2X_MUL(8, temp2, 4, p_11+224+4, 4, q_11+210);
	gf2x_add(8, q_11+194+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+210+0, 4, p_01+224);
	GF2X_MUL(8, temp2, 4, q_11+210+0, 4, p_11+224);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+194+0, 8, q_11+194+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 3
	memset(p_00+176, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+208+4, 12, q_00+194);
	GF2X_MUL(24, temp2, 12, p_10+208+4, 12, q_01+194);
	gf2x_add(24, p_00+176+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+194+8, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_01+194+8, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+176+8, 8, p_00+176+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+194+4, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_01+194+4, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+176+4, 8, p_00+176+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+194+0, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_01+194+0, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+176+0, 8, p_00+176+0, 8, temp);
	memset(p_01+176, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+208+4, 12, q_00+194);
	GF2X_MUL(24, temp2, 12, p_11+208+4, 12, q_01+194);
	gf2x_add(24, p_01+176+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+194+8, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_01+194+8, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+176+8, 8, p_01+176+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+194+4, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_01+194+4, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+176+4, 8, p_01+176+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+194+0, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_01+194+0, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+176+0, 8, p_01+176+0, 8, temp);
	memset(p_10+176, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+208+4, 12, q_10+194);
	GF2X_MUL(24, temp2, 12, p_10+208+4, 12, q_11+194);
	gf2x_add(24, p_10+176+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+194+8, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_11+194+8, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+176+8, 8, p_10+176+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+194+4, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_11+194+4, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+176+4, 8, p_10+176+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+194+0, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_11+194+0, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+176+0, 8, p_10+176+0, 8, temp);
	memset(p_11+176, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+208+4, 12, q_10+194);
	GF2X_MUL(24, temp2, 12, p_11+208+4, 12, q_11+194);
	gf2x_add(24, p_11+176+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+194+8, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_11+194+8, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+176+8, 8, p_11+176+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+194+4, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_11+194+4, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+176+4, 8, p_11+176+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+194+0, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_11+194+0, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+176+0, 8, p_11+176+0, 8, temp);
	

	// Calculating left operands: n: 3570, depth: 2
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+343+28, 28, p_00+176);
	GF2X_MUL(56, temp2, 28, g_sum+343+28, 28, p_01+176);
	gf2x_add(56, f_sum+519+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+343+0, 28, p_00+176);
	GF2X_MUL(56, temp2, 28, g_sum+343+0, 28, p_01+176);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+519, 28, f_sum+519, 28, temp+28);
	right_bit_shift_n(56, f_sum+519, 57);
	GF2X_MUL(56, temp, 28, f_sum+343+28, 28, p_10+176);
	GF2X_MUL(56, temp2, 28, g_sum+343+28, 28, p_11+176);
	gf2x_add(56, g_sum+519+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+343+0, 28, p_10+176);
	GF2X_MUL(56, temp2, 28, g_sum+343+0, 28, p_11+176);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+519, 28, g_sum+519, 28, temp+28);
	right_bit_shift_n(56, g_sum+519, 57);
	

	delta = divstepsx_256(255, delta, f_sum+544, g_sum+544, p_00+232, p_01+232, p_10+232, p_11+232);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+540+4, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+540+4, 4, p_01+232);
	gf2x_add(8, f_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+540+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+540+0, 4, p_01+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+686, 4, f_sum+686, 4, temp+4);
	right_bit_shift_n(8, f_sum+686, 63);
	GF2X_MUL(8, temp, 4, f_sum+540+4, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+540+4, 4, p_11+232);
	gf2x_add(8, g_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+540+0, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+540+0, 4, p_11+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+686, 4, g_sum+686, 4, temp+4);
	right_bit_shift_n(8, g_sum+686, 63);
	

	delta = divstepsx_256(255, delta, f_sum+687, g_sum+687, q_00+218, q_01+218, q_10+218, q_11+218);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_10+232);
	gf2x_add(8, p_00+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_11+232);
	gf2x_add(8, p_01+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_10+232);
	gf2x_add(8, p_10+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_11+232);
	gf2x_add(8, p_11+224+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+532+8, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, g_sum+532+8, 8, p_01+224);
	gf2x_add(16, f_sum+661+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+532+0, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, g_sum+532+0, 8, p_01+224);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+661, 8, f_sum+661, 8, temp+8);
	right_bit_shift_n(16, f_sum+661, 62);
	GF2X_MUL(16, temp, 8, f_sum+532+8, 8, p_10+224);
	GF2X_MUL(16, temp2, 8, g_sum+532+8, 8, p_11+224);
	gf2x_add(16, g_sum+661+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+532+0, 8, p_10+224);
	GF2X_MUL(16, temp2, 8, g_sum+532+0, 8, p_11+224);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+661, 8, g_sum+661, 8, temp+8);
	right_bit_shift_n(16, g_sum+661, 62);
	

	delta = divstepsx_256(255, delta, f_sum+666, g_sum+666, p_00+232, p_01+232, p_10+232, p_11+232);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+662+4, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+4, 4, p_01+232);
	gf2x_add(8, f_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+662+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+0, 4, p_01+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+686, 4, f_sum+686, 4, temp+4);
	right_bit_shift_n(8, f_sum+686, 63);
	GF2X_MUL(8, temp, 4, f_sum+662+4, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+4, 4, p_11+232);
	gf2x_add(8, g_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+662+0, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+0, 4, p_11+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+686, 4, g_sum+686, 4, temp+4);
	right_bit_shift_n(8, g_sum+686, 63);
	

	delta = divstepsx_256(255, delta, f_sum+687, g_sum+687, q_00+218, q_01+218, q_10+218, q_11+218);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_10+232);
	gf2x_add(8, q_00+210+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_11+232);
	gf2x_add(8, q_01+210+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_10+232);
	gf2x_add(8, q_10+210+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_11+232);
	gf2x_add(8, q_11+210+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 4
	GF2X_MUL(16, temp, 8, q_00+210+0, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, q_01+210+0, 8, p_10+224);
	gf2x_add(16, p_00+208+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+210+0, 8, p_01+224);
	GF2X_MUL(16, temp2, 8, q_01+210+0, 8, p_11+224);
	gf2x_add(16, p_01+208+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+210+0, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, q_11+210+0, 8, p_10+224);
	gf2x_add(16, p_10+208+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+210+0, 8, p_01+224);
	GF2X_MUL(16, temp2, 8, q_11+210+0, 8, p_11+224);
	gf2x_add(16, p_11+208+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 3
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+520+12, 16, p_00+208);
	GF2X_MUL(32, temp2, 16, g_sum+520+12, 16, p_01+208);
	gf2x_add(28, f_sum+612, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+208+4, 12, f_sum+520);
	GF2X_MUL(24, temp2, 12, p_01+208+4, 12, g_sum+520);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+612, 12, f_sum+612, 12, temp+12);
	right_bit_shift_n(28, f_sum+612, 60);
	GF2X_MUL(32, temp, 16, f_sum+520+12, 16, p_10+208);
	GF2X_MUL(32, temp2, 16, g_sum+520+12, 16, p_11+208);
	gf2x_add(28, g_sum+612, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+208+4, 12, f_sum+520);
	GF2X_MUL(24, temp2, 12, p_11+208+4, 12, g_sum+520);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+612, 12, g_sum+612, 12, temp+12);
	right_bit_shift_n(28, g_sum+612, 60);
	

	delta = divstepsx_256(255, delta, f_sum+621, g_sum+621, p_00+232, p_01+232, p_10+232, p_11+232);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+617+4, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+617+4, 4, p_01+232);
	gf2x_add(8, f_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+617+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+617+0, 4, p_01+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+686, 4, f_sum+686, 4, temp+4);
	right_bit_shift_n(8, f_sum+686, 63);
	GF2X_MUL(8, temp, 4, f_sum+617+4, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+617+4, 4, p_11+232);
	gf2x_add(8, g_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+617+0, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+617+0, 4, p_11+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+686, 4, g_sum+686, 4, temp+4);
	right_bit_shift_n(8, g_sum+686, 63);
	

	delta = divstepsx_256(255, delta, f_sum+687, g_sum+687, q_00+218, q_01+218, q_10+218, q_11+218);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_10+232);
	gf2x_add(8, p_00+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_11+232);
	gf2x_add(8, p_01+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_10+232);
	gf2x_add(8, p_10+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_11+232);
	gf2x_add(8, p_11+224+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+613+4, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, g_sum+613+4, 8, p_01+224);
	gf2x_add(12, f_sum+661, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+224+4, 4, f_sum+613);
	GF2X_MUL(8, temp2, 4, p_01+224+4, 4, g_sum+613);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+661, 4, f_sum+661, 4, temp+4);
	right_bit_shift_n(12, f_sum+661, 62);
	GF2X_MUL(16, temp, 8, f_sum+613+4, 8, p_10+224);
	GF2X_MUL(16, temp2, 8, g_sum+613+4, 8, p_11+224);
	gf2x_add(12, g_sum+661, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+224+4, 4, f_sum+613);
	GF2X_MUL(8, temp2, 4, p_11+224+4, 4, g_sum+613);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+661, 4, g_sum+661, 4, temp+4);
	right_bit_shift_n(12, g_sum+661, 62);
	

	delta = divstepsx_256(255, delta, f_sum+662, g_sum+662, q_00+210, q_01+210, q_10+210, q_11+210);

	// Recombining results: n: 765, depth: 4
	memset(q_00+194, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+224+4, 4, q_00+210);
	GF2X_MUL(8, temp2, 4, p_10+224+4, 4, q_01+210);
	gf2x_add(8, q_00+194+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+210+0, 4, p_00+224);
	GF2X_MUL(8, temp2, 4, q_01+210+0, 4, p_10+224);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+194+0, 8, q_00+194+0, 8, temp);
	memset(q_01+194, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+224+4, 4, q_00+210);
	GF2X_MUL(8, temp2, 4, p_11+224+4, 4, q_01+210);
	gf2x_add(8, q_01+194+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+210+0, 4, p_01+224);
	GF2X_MUL(8, temp2, 4, q_01+210+0, 4, p_11+224);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+194+0, 8, q_01+194+0, 8, temp);
	memset(q_10+194, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+224+4, 4, q_10+210);
	GF2X_MUL(8, temp2, 4, p_10+224+4, 4, q_11+210);
	gf2x_add(8, q_10+194+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+210+0, 4, p_00+224);
	GF2X_MUL(8, temp2, 4, q_11+210+0, 4, p_10+224);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+194+0, 8, q_10+194+0, 8, temp);
	memset(q_11+194, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+224+4, 4, q_10+210);
	GF2X_MUL(8, temp2, 4, p_11+224+4, 4, q_11+210);
	gf2x_add(8, q_11+194+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+210+0, 4, p_01+224);
	GF2X_MUL(8, temp2, 4, q_11+210+0, 4, p_11+224);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+194+0, 8, q_11+194+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 3
	memset(q_00+166, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+208+4, 12, q_00+194);
	GF2X_MUL(24, temp2, 12, p_10+208+4, 12, q_01+194);
	gf2x_add(24, q_00+166+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+194+8, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_01+194+8, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+166+8, 8, q_00+166+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+194+4, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_01+194+4, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+166+4, 8, q_00+166+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+194+0, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_01+194+0, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+166+0, 8, q_00+166+0, 8, temp);
	memset(q_01+166, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+208+4, 12, q_00+194);
	GF2X_MUL(24, temp2, 12, p_11+208+4, 12, q_01+194);
	gf2x_add(24, q_01+166+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+194+8, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_01+194+8, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+166+8, 8, q_01+166+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+194+4, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_01+194+4, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+166+4, 8, q_01+166+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+194+0, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_01+194+0, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+166+0, 8, q_01+166+0, 8, temp);
	memset(q_10+166, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+208+4, 12, q_10+194);
	GF2X_MUL(24, temp2, 12, p_10+208+4, 12, q_11+194);
	gf2x_add(24, q_10+166+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+194+8, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_11+194+8, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+166+8, 8, q_10+166+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+194+4, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_11+194+4, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+166+4, 8, q_10+166+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+194+0, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_11+194+0, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+166+0, 8, q_10+166+0, 8, temp);
	memset(q_11+166, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+208+4, 12, q_10+194);
	GF2X_MUL(24, temp2, 12, p_11+208+4, 12, q_11+194);
	gf2x_add(24, q_11+166+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+194+8, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_11+194+8, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+166+8, 8, q_11+166+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+194+4, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_11+194+4, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+166+4, 8, q_11+166+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+194+0, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_11+194+0, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+166+0, 8, q_11+166+0, 8, temp);
	

	// Recombining results: n: 3570, depth: 2
	GF2X_MUL(56, temp, 28, q_00+166+0, 28, p_00+176);
	GF2X_MUL(56, temp2, 28, q_01+166+0, 28, p_10+176);
	gf2x_add(56, q_00+110+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_00+166+0, 28, p_01+176);
	GF2X_MUL(56, temp2, 28, q_01+166+0, 28, p_11+176);
	gf2x_add(56, q_01+110+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+166+0, 28, p_00+176);
	GF2X_MUL(56, temp2, 28, q_11+166+0, 28, p_10+176);
	gf2x_add(56, q_10+110+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+166+0, 28, p_01+176);
	GF2X_MUL(56, temp2, 28, q_11+166+0, 28, p_11+176);
	gf2x_add(56, q_11+110+0, 56, temp, 56, temp2);
	

	// Recombining results: n: 7395, depth: 1
	memset(p_00+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(112, temp, 56, p_00+116+4, 56, q_00+110);
	GF2X_MUL(112, temp2, 56, p_10+116+4, 56, q_01+110);
	gf2x_add(112, p_00+0+4, 112, temp, 112, temp2);
	GF2X_MUL(8, temp, 4, q_00+110+52, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_01+110+52, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+52, 8, p_00+0+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+110+48, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_01+110+48, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+48, 8, p_00+0+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+110+44, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_01+110+44, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+44, 8, p_00+0+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+110+40, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_01+110+40, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+40, 8, p_00+0+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+110+36, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_01+110+36, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+36, 8, p_00+0+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+110+32, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_01+110+32, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+32, 8, p_00+0+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+110+28, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_01+110+28, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+28, 8, p_00+0+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+110+24, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_01+110+24, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+24, 8, p_00+0+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+110+20, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_01+110+20, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+20, 8, p_00+0+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+110+16, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_01+110+16, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+16, 8, p_00+0+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+110+12, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_01+110+12, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+12, 8, p_00+0+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+110+8, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_01+110+8, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+8, 8, p_00+0+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+110+4, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_01+110+4, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+4, 8, p_00+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+110+0, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_01+110+0, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+0, 8, p_00+0+0, 8, temp);
	memset(p_01+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(112, temp, 56, p_01+116+4, 56, q_00+110);
	GF2X_MUL(112, temp2, 56, p_11+116+4, 56, q_01+110);
	gf2x_add(112, p_01+0+4, 112, temp, 112, temp2);
	GF2X_MUL(8, temp, 4, q_00+110+52, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_01+110+52, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+52, 8, p_01+0+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+110+48, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_01+110+48, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+48, 8, p_01+0+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+110+44, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_01+110+44, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+44, 8, p_01+0+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+110+40, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_01+110+40, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+40, 8, p_01+0+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+110+36, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_01+110+36, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+36, 8, p_01+0+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+110+32, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_01+110+32, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+32, 8, p_01+0+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+110+28, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_01+110+28, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+28, 8, p_01+0+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+110+24, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_01+110+24, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+24, 8, p_01+0+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+110+20, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_01+110+20, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+20, 8, p_01+0+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+110+16, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_01+110+16, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+16, 8, p_01+0+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+110+12, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_01+110+12, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+12, 8, p_01+0+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+110+8, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_01+110+8, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+8, 8, p_01+0+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+110+4, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_01+110+4, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+4, 8, p_01+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+110+0, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_01+110+0, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+0, 8, p_01+0+0, 8, temp);
	memset(p_10+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(112, temp, 56, p_00+116+4, 56, q_10+110);
	GF2X_MUL(112, temp2, 56, p_10+116+4, 56, q_11+110);
	gf2x_add(112, p_10+0+4, 112, temp, 112, temp2);
	GF2X_MUL(8, temp, 4, q_10+110+52, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_11+110+52, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+52, 8, p_10+0+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+110+48, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_11+110+48, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+48, 8, p_10+0+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+110+44, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_11+110+44, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+44, 8, p_10+0+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+110+40, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_11+110+40, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+40, 8, p_10+0+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+110+36, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_11+110+36, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+36, 8, p_10+0+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+110+32, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_11+110+32, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+32, 8, p_10+0+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+110+28, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_11+110+28, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+28, 8, p_10+0+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+110+24, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_11+110+24, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+24, 8, p_10+0+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+110+20, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_11+110+20, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+20, 8, p_10+0+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+110+16, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_11+110+16, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+16, 8, p_10+0+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+110+12, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_11+110+12, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+12, 8, p_10+0+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+110+8, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_11+110+8, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+8, 8, p_10+0+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+110+4, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_11+110+4, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+4, 8, p_10+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+110+0, 4, p_00+116);
	GF2X_MUL(8, temp2, 4, q_11+110+0, 4, p_10+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+0, 8, p_10+0+0, 8, temp);
	memset(p_11+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(112, temp, 56, p_01+116+4, 56, q_10+110);
	GF2X_MUL(112, temp2, 56, p_11+116+4, 56, q_11+110);
	gf2x_add(112, p_11+0+4, 112, temp, 112, temp2);
	GF2X_MUL(8, temp, 4, q_10+110+52, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_11+110+52, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+52, 8, p_11+0+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+110+48, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_11+110+48, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+48, 8, p_11+0+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+110+44, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_11+110+44, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+44, 8, p_11+0+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+110+40, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_11+110+40, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+40, 8, p_11+0+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+110+36, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_11+110+36, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+36, 8, p_11+0+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+110+32, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_11+110+32, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+32, 8, p_11+0+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+110+28, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_11+110+28, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+28, 8, p_11+0+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+110+24, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_11+110+24, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+24, 8, p_11+0+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+110+20, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_11+110+20, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+20, 8, p_11+0+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+110+16, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_11+110+16, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+16, 8, p_11+0+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+110+12, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_11+110+12, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+12, 8, p_11+0+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+110+8, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_11+110+8, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+8, 8, p_11+0+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+110+4, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_11+110+4, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+4, 8, p_11+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+110+0, 4, p_01+116);
	GF2X_MUL(8, temp2, 4, q_11+110+0, 4, p_11+116);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+0, 8, p_11+0+0, 8, temp);
	

	// Calculating left operands: n: 14373, depth: 0
	// Digits to shift: 115
	// Displacement: 115
	GF2X_MUL(232, temp, 116, f+0+109, 116, p_00+0);
	GF2X_MUL(232, temp2, 116, g+0+109, 116, p_01+0);
	gf2x_add(226, f_sum+0, 226, temp+6, 226, temp2+6);
	GF2X_MUL(218, temp, 109, p_00+0+7, 109, f+0);
	GF2X_MUL(218, temp2, 109, p_01+0+7, 109, g+0);
	gf2x_add(218, temp, 218, temp, 218, temp2);
	gf2x_add(110, f_sum+0, 110, f_sum+0, 110, temp+108);
	GF2X_MUL(14, temp, 7, f+0+102, 7, p_00+0);
	GF2X_MUL(14, temp2, 7, g+0+102, 7, p_01+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(1, f_sum+0, 1, f_sum+0, 1, temp+13);
	right_bit_shift_n(225, f_sum+0, 35);
	GF2X_MUL(232, temp, 116, f+0+109, 116, p_10+0);
	GF2X_MUL(232, temp2, 116, g+0+109, 116, p_11+0);
	gf2x_add(226, g_sum+0, 226, temp+6, 226, temp2+6);
	GF2X_MUL(218, temp, 109, p_10+0+7, 109, f+0);
	GF2X_MUL(218, temp2, 109, p_11+0+7, 109, g+0);
	gf2x_add(218, temp, 218, temp, 218, temp2);
	gf2x_add(110, g_sum+0, 110, g_sum+0, 110, temp+108);
	GF2X_MUL(14, temp, 7, f+0+102, 7, p_10+0);
	GF2X_MUL(14, temp2, 7, g+0+102, 7, p_11+0);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(1, g_sum+0, 1, g_sum+0, 1, temp+13);
	right_bit_shift_n(225, g_sum+0, 35);
	

	delta = divstepsx_256(255, delta, f_sum+107, g_sum+107, p_00+232, p_01+232, p_10+232, p_11+232);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+103+4, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+103+4, 4, p_01+232);
	gf2x_add(8, f_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+103+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+103+0, 4, p_01+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+686, 4, f_sum+686, 4, temp+4);
	right_bit_shift_n(8, f_sum+686, 63);
	GF2X_MUL(8, temp, 4, f_sum+103+4, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+103+4, 4, p_11+232);
	gf2x_add(8, g_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+103+0, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+103+0, 4, p_11+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+686, 4, g_sum+686, 4, temp+4);
	right_bit_shift_n(8, g_sum+686, 63);
	

	delta = divstepsx_256(255, delta, f_sum+687, g_sum+687, q_00+218, q_01+218, q_10+218, q_11+218);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_10+232);
	gf2x_add(8, p_00+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_11+232);
	gf2x_add(8, p_01+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_10+232);
	gf2x_add(8, p_10+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_11+232);
	gf2x_add(8, p_11+224+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+95+8, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, g_sum+95+8, 8, p_01+224);
	gf2x_add(16, f_sum+661+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+95+0, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, g_sum+95+0, 8, p_01+224);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+661, 8, f_sum+661, 8, temp+8);
	right_bit_shift_n(16, f_sum+661, 62);
	GF2X_MUL(16, temp, 8, f_sum+95+8, 8, p_10+224);
	GF2X_MUL(16, temp2, 8, g_sum+95+8, 8, p_11+224);
	gf2x_add(16, g_sum+661+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+95+0, 8, p_10+224);
	GF2X_MUL(16, temp2, 8, g_sum+95+0, 8, p_11+224);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+661, 8, g_sum+661, 8, temp+8);
	right_bit_shift_n(16, g_sum+661, 62);
	

	delta = divstepsx_256(255, delta, f_sum+666, g_sum+666, p_00+232, p_01+232, p_10+232, p_11+232);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+662+4, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+4, 4, p_01+232);
	gf2x_add(8, f_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+662+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+0, 4, p_01+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+686, 4, f_sum+686, 4, temp+4);
	right_bit_shift_n(8, f_sum+686, 63);
	GF2X_MUL(8, temp, 4, f_sum+662+4, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+4, 4, p_11+232);
	gf2x_add(8, g_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+662+0, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+0, 4, p_11+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+686, 4, g_sum+686, 4, temp+4);
	right_bit_shift_n(8, g_sum+686, 63);
	

	delta = divstepsx_256(255, delta, f_sum+687, g_sum+687, q_00+218, q_01+218, q_10+218, q_11+218);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_10+232);
	gf2x_add(8, q_00+210+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_11+232);
	gf2x_add(8, q_01+210+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_10+232);
	gf2x_add(8, q_10+210+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_11+232);
	gf2x_add(8, q_11+210+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 4
	GF2X_MUL(16, temp, 8, q_00+210+0, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, q_01+210+0, 8, p_10+224);
	gf2x_add(16, p_00+208+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+210+0, 8, p_01+224);
	GF2X_MUL(16, temp2, 8, q_01+210+0, 8, p_11+224);
	gf2x_add(16, p_01+208+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+210+0, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, q_11+210+0, 8, p_10+224);
	gf2x_add(16, p_10+208+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+210+0, 8, p_01+224);
	GF2X_MUL(16, temp2, 8, q_11+210+0, 8, p_11+224);
	gf2x_add(16, p_11+208+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 3
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+83+12, 16, p_00+208);
	GF2X_MUL(32, temp2, 16, g_sum+83+12, 16, p_01+208);
	gf2x_add(28, f_sum+612, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+208+4, 12, f_sum+83);
	GF2X_MUL(24, temp2, 12, p_01+208+4, 12, g_sum+83);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+612, 12, f_sum+612, 12, temp+12);
	right_bit_shift_n(28, f_sum+612, 60);
	GF2X_MUL(32, temp, 16, f_sum+83+12, 16, p_10+208);
	GF2X_MUL(32, temp2, 16, g_sum+83+12, 16, p_11+208);
	gf2x_add(28, g_sum+612, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+208+4, 12, f_sum+83);
	GF2X_MUL(24, temp2, 12, p_11+208+4, 12, g_sum+83);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+612, 12, g_sum+612, 12, temp+12);
	right_bit_shift_n(28, g_sum+612, 60);
	

	delta = divstepsx_256(255, delta, f_sum+621, g_sum+621, p_00+232, p_01+232, p_10+232, p_11+232);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+617+4, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+617+4, 4, p_01+232);
	gf2x_add(8, f_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+617+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+617+0, 4, p_01+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+686, 4, f_sum+686, 4, temp+4);
	right_bit_shift_n(8, f_sum+686, 63);
	GF2X_MUL(8, temp, 4, f_sum+617+4, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+617+4, 4, p_11+232);
	gf2x_add(8, g_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+617+0, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+617+0, 4, p_11+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+686, 4, g_sum+686, 4, temp+4);
	right_bit_shift_n(8, g_sum+686, 63);
	

	delta = divstepsx_256(255, delta, f_sum+687, g_sum+687, q_00+218, q_01+218, q_10+218, q_11+218);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_10+232);
	gf2x_add(8, p_00+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_11+232);
	gf2x_add(8, p_01+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_10+232);
	gf2x_add(8, p_10+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_11+232);
	gf2x_add(8, p_11+224+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+613+4, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, g_sum+613+4, 8, p_01+224);
	gf2x_add(12, f_sum+661, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+224+4, 4, f_sum+613);
	GF2X_MUL(8, temp2, 4, p_01+224+4, 4, g_sum+613);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+661, 4, f_sum+661, 4, temp+4);
	right_bit_shift_n(12, f_sum+661, 62);
	GF2X_MUL(16, temp, 8, f_sum+613+4, 8, p_10+224);
	GF2X_MUL(16, temp2, 8, g_sum+613+4, 8, p_11+224);
	gf2x_add(12, g_sum+661, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+224+4, 4, f_sum+613);
	GF2X_MUL(8, temp2, 4, p_11+224+4, 4, g_sum+613);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+661, 4, g_sum+661, 4, temp+4);
	right_bit_shift_n(12, g_sum+661, 62);
	

	delta = divstepsx_256(255, delta, f_sum+662, g_sum+662, q_00+210, q_01+210, q_10+210, q_11+210);

	// Recombining results: n: 765, depth: 4
	memset(q_00+194, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+224+4, 4, q_00+210);
	GF2X_MUL(8, temp2, 4, p_10+224+4, 4, q_01+210);
	gf2x_add(8, q_00+194+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+210+0, 4, p_00+224);
	GF2X_MUL(8, temp2, 4, q_01+210+0, 4, p_10+224);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+194+0, 8, q_00+194+0, 8, temp);
	memset(q_01+194, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+224+4, 4, q_00+210);
	GF2X_MUL(8, temp2, 4, p_11+224+4, 4, q_01+210);
	gf2x_add(8, q_01+194+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+210+0, 4, p_01+224);
	GF2X_MUL(8, temp2, 4, q_01+210+0, 4, p_11+224);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+194+0, 8, q_01+194+0, 8, temp);
	memset(q_10+194, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+224+4, 4, q_10+210);
	GF2X_MUL(8, temp2, 4, p_10+224+4, 4, q_11+210);
	gf2x_add(8, q_10+194+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+210+0, 4, p_00+224);
	GF2X_MUL(8, temp2, 4, q_11+210+0, 4, p_10+224);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+194+0, 8, q_10+194+0, 8, temp);
	memset(q_11+194, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+224+4, 4, q_10+210);
	GF2X_MUL(8, temp2, 4, p_11+224+4, 4, q_11+210);
	gf2x_add(8, q_11+194+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+210+0, 4, p_01+224);
	GF2X_MUL(8, temp2, 4, q_11+210+0, 4, p_11+224);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+194+0, 8, q_11+194+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 3
	memset(p_00+176, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+208+4, 12, q_00+194);
	GF2X_MUL(24, temp2, 12, p_10+208+4, 12, q_01+194);
	gf2x_add(24, p_00+176+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+194+8, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_01+194+8, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+176+8, 8, p_00+176+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+194+4, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_01+194+4, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+176+4, 8, p_00+176+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+194+0, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_01+194+0, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+176+0, 8, p_00+176+0, 8, temp);
	memset(p_01+176, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+208+4, 12, q_00+194);
	GF2X_MUL(24, temp2, 12, p_11+208+4, 12, q_01+194);
	gf2x_add(24, p_01+176+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+194+8, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_01+194+8, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+176+8, 8, p_01+176+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+194+4, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_01+194+4, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+176+4, 8, p_01+176+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+194+0, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_01+194+0, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+176+0, 8, p_01+176+0, 8, temp);
	memset(p_10+176, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+208+4, 12, q_10+194);
	GF2X_MUL(24, temp2, 12, p_10+208+4, 12, q_11+194);
	gf2x_add(24, p_10+176+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+194+8, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_11+194+8, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+176+8, 8, p_10+176+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+194+4, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_11+194+4, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+176+4, 8, p_10+176+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+194+0, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_11+194+0, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+176+0, 8, p_10+176+0, 8, temp);
	memset(p_11+176, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+208+4, 12, q_10+194);
	GF2X_MUL(24, temp2, 12, p_11+208+4, 12, q_11+194);
	gf2x_add(24, p_11+176+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+194+8, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_11+194+8, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+176+8, 8, p_11+176+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+194+4, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_11+194+4, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+176+4, 8, p_11+176+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+194+0, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_11+194+0, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+176+0, 8, p_11+176+0, 8, temp);
	

	// Calculating left operands: n: 3570, depth: 2
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+55+28, 28, p_00+176);
	GF2X_MUL(56, temp2, 28, g_sum+55+28, 28, p_01+176);
	gf2x_add(56, f_sum+519+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+55+0, 28, p_00+176);
	GF2X_MUL(56, temp2, 28, g_sum+55+0, 28, p_01+176);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, f_sum+519, 28, f_sum+519, 28, temp+28);
	right_bit_shift_n(56, f_sum+519, 57);
	GF2X_MUL(56, temp, 28, f_sum+55+28, 28, p_10+176);
	GF2X_MUL(56, temp2, 28, g_sum+55+28, 28, p_11+176);
	gf2x_add(56, g_sum+519+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, f_sum+55+0, 28, p_10+176);
	GF2X_MUL(56, temp2, 28, g_sum+55+0, 28, p_11+176);
	gf2x_add(56, temp, 56, temp, 56, temp2);
	gf2x_add(28, g_sum+519, 28, g_sum+519, 28, temp+28);
	right_bit_shift_n(56, g_sum+519, 57);
	

	delta = divstepsx_256(255, delta, f_sum+544, g_sum+544, p_00+232, p_01+232, p_10+232, p_11+232);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+540+4, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+540+4, 4, p_01+232);
	gf2x_add(8, f_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+540+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+540+0, 4, p_01+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+686, 4, f_sum+686, 4, temp+4);
	right_bit_shift_n(8, f_sum+686, 63);
	GF2X_MUL(8, temp, 4, f_sum+540+4, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+540+4, 4, p_11+232);
	gf2x_add(8, g_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+540+0, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+540+0, 4, p_11+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+686, 4, g_sum+686, 4, temp+4);
	right_bit_shift_n(8, g_sum+686, 63);
	

	delta = divstepsx_256(255, delta, f_sum+687, g_sum+687, q_00+218, q_01+218, q_10+218, q_11+218);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_10+232);
	gf2x_add(8, p_00+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_11+232);
	gf2x_add(8, p_01+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_10+232);
	gf2x_add(8, p_10+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_11+232);
	gf2x_add(8, p_11+224+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+532+8, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, g_sum+532+8, 8, p_01+224);
	gf2x_add(16, f_sum+661+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+532+0, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, g_sum+532+0, 8, p_01+224);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+661, 8, f_sum+661, 8, temp+8);
	right_bit_shift_n(16, f_sum+661, 62);
	GF2X_MUL(16, temp, 8, f_sum+532+8, 8, p_10+224);
	GF2X_MUL(16, temp2, 8, g_sum+532+8, 8, p_11+224);
	gf2x_add(16, g_sum+661+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+532+0, 8, p_10+224);
	GF2X_MUL(16, temp2, 8, g_sum+532+0, 8, p_11+224);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+661, 8, g_sum+661, 8, temp+8);
	right_bit_shift_n(16, g_sum+661, 62);
	

	delta = divstepsx_256(255, delta, f_sum+666, g_sum+666, p_00+232, p_01+232, p_10+232, p_11+232);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+662+4, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+4, 4, p_01+232);
	gf2x_add(8, f_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+662+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+0, 4, p_01+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+686, 4, f_sum+686, 4, temp+4);
	right_bit_shift_n(8, f_sum+686, 63);
	GF2X_MUL(8, temp, 4, f_sum+662+4, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+4, 4, p_11+232);
	gf2x_add(8, g_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+662+0, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+0, 4, p_11+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+686, 4, g_sum+686, 4, temp+4);
	right_bit_shift_n(8, g_sum+686, 63);
	

	delta = divstepsx_256(255, delta, f_sum+687, g_sum+687, q_00+218, q_01+218, q_10+218, q_11+218);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_10+232);
	gf2x_add(8, q_00+210+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_11+232);
	gf2x_add(8, q_01+210+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_10+232);
	gf2x_add(8, q_10+210+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_11+232);
	gf2x_add(8, q_11+210+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 4
	GF2X_MUL(16, temp, 8, q_00+210+0, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, q_01+210+0, 8, p_10+224);
	gf2x_add(16, p_00+208+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+210+0, 8, p_01+224);
	GF2X_MUL(16, temp2, 8, q_01+210+0, 8, p_11+224);
	gf2x_add(16, p_01+208+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+210+0, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, q_11+210+0, 8, p_10+224);
	gf2x_add(16, p_10+208+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+210+0, 8, p_01+224);
	GF2X_MUL(16, temp2, 8, q_11+210+0, 8, p_11+224);
	gf2x_add(16, p_11+208+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 3
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+520+12, 16, p_00+208);
	GF2X_MUL(32, temp2, 16, g_sum+520+12, 16, p_01+208);
	gf2x_add(28, f_sum+612, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+208+4, 12, f_sum+520);
	GF2X_MUL(24, temp2, 12, p_01+208+4, 12, g_sum+520);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+612, 12, f_sum+612, 12, temp+12);
	right_bit_shift_n(28, f_sum+612, 60);
	GF2X_MUL(32, temp, 16, f_sum+520+12, 16, p_10+208);
	GF2X_MUL(32, temp2, 16, g_sum+520+12, 16, p_11+208);
	gf2x_add(28, g_sum+612, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+208+4, 12, f_sum+520);
	GF2X_MUL(24, temp2, 12, p_11+208+4, 12, g_sum+520);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+612, 12, g_sum+612, 12, temp+12);
	right_bit_shift_n(28, g_sum+612, 60);
	

	delta = divstepsx_256(255, delta, f_sum+621, g_sum+621, p_00+232, p_01+232, p_10+232, p_11+232);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+617+4, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+617+4, 4, p_01+232);
	gf2x_add(8, f_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+617+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+617+0, 4, p_01+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+686, 4, f_sum+686, 4, temp+4);
	right_bit_shift_n(8, f_sum+686, 63);
	GF2X_MUL(8, temp, 4, f_sum+617+4, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+617+4, 4, p_11+232);
	gf2x_add(8, g_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+617+0, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+617+0, 4, p_11+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+686, 4, g_sum+686, 4, temp+4);
	right_bit_shift_n(8, g_sum+686, 63);
	

	delta = divstepsx_256(255, delta, f_sum+687, g_sum+687, q_00+218, q_01+218, q_10+218, q_11+218);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_10+232);
	gf2x_add(8, p_00+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_11+232);
	gf2x_add(8, p_01+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_10+232);
	gf2x_add(8, p_10+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_11+232);
	gf2x_add(8, p_11+224+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+613+4, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, g_sum+613+4, 8, p_01+224);
	gf2x_add(12, f_sum+661, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+224+4, 4, f_sum+613);
	GF2X_MUL(8, temp2, 4, p_01+224+4, 4, g_sum+613);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+661, 4, f_sum+661, 4, temp+4);
	right_bit_shift_n(12, f_sum+661, 62);
	GF2X_MUL(16, temp, 8, f_sum+613+4, 8, p_10+224);
	GF2X_MUL(16, temp2, 8, g_sum+613+4, 8, p_11+224);
	gf2x_add(12, g_sum+661, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+224+4, 4, f_sum+613);
	GF2X_MUL(8, temp2, 4, p_11+224+4, 4, g_sum+613);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+661, 4, g_sum+661, 4, temp+4);
	right_bit_shift_n(12, g_sum+661, 62);
	

	delta = divstepsx_256(255, delta, f_sum+662, g_sum+662, q_00+210, q_01+210, q_10+210, q_11+210);

	// Recombining results: n: 765, depth: 4
	memset(q_00+194, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+224+4, 4, q_00+210);
	GF2X_MUL(8, temp2, 4, p_10+224+4, 4, q_01+210);
	gf2x_add(8, q_00+194+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+210+0, 4, p_00+224);
	GF2X_MUL(8, temp2, 4, q_01+210+0, 4, p_10+224);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+194+0, 8, q_00+194+0, 8, temp);
	memset(q_01+194, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+224+4, 4, q_00+210);
	GF2X_MUL(8, temp2, 4, p_11+224+4, 4, q_01+210);
	gf2x_add(8, q_01+194+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+210+0, 4, p_01+224);
	GF2X_MUL(8, temp2, 4, q_01+210+0, 4, p_11+224);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+194+0, 8, q_01+194+0, 8, temp);
	memset(q_10+194, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+224+4, 4, q_10+210);
	GF2X_MUL(8, temp2, 4, p_10+224+4, 4, q_11+210);
	gf2x_add(8, q_10+194+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+210+0, 4, p_00+224);
	GF2X_MUL(8, temp2, 4, q_11+210+0, 4, p_10+224);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+194+0, 8, q_10+194+0, 8, temp);
	memset(q_11+194, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+224+4, 4, q_10+210);
	GF2X_MUL(8, temp2, 4, p_11+224+4, 4, q_11+210);
	gf2x_add(8, q_11+194+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+210+0, 4, p_01+224);
	GF2X_MUL(8, temp2, 4, q_11+210+0, 4, p_11+224);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+194+0, 8, q_11+194+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 3
	memset(q_00+166, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+208+4, 12, q_00+194);
	GF2X_MUL(24, temp2, 12, p_10+208+4, 12, q_01+194);
	gf2x_add(24, q_00+166+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+194+8, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_01+194+8, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+166+8, 8, q_00+166+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+194+4, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_01+194+4, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+166+4, 8, q_00+166+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+194+0, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_01+194+0, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+166+0, 8, q_00+166+0, 8, temp);
	memset(q_01+166, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+208+4, 12, q_00+194);
	GF2X_MUL(24, temp2, 12, p_11+208+4, 12, q_01+194);
	gf2x_add(24, q_01+166+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+194+8, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_01+194+8, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+166+8, 8, q_01+166+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+194+4, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_01+194+4, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+166+4, 8, q_01+166+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+194+0, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_01+194+0, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+166+0, 8, q_01+166+0, 8, temp);
	memset(q_10+166, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+208+4, 12, q_10+194);
	GF2X_MUL(24, temp2, 12, p_10+208+4, 12, q_11+194);
	gf2x_add(24, q_10+166+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+194+8, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_11+194+8, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+166+8, 8, q_10+166+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+194+4, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_11+194+4, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+166+4, 8, q_10+166+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+194+0, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_11+194+0, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+166+0, 8, q_10+166+0, 8, temp);
	memset(q_11+166, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+208+4, 12, q_10+194);
	GF2X_MUL(24, temp2, 12, p_11+208+4, 12, q_11+194);
	gf2x_add(24, q_11+166+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+194+8, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_11+194+8, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+166+8, 8, q_11+166+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+194+4, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_11+194+4, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+166+4, 8, q_11+166+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+194+0, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_11+194+0, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+166+0, 8, q_11+166+0, 8, temp);
	

	// Recombining results: n: 3570, depth: 2
	GF2X_MUL(56, temp, 28, q_00+166+0, 28, p_00+176);
	GF2X_MUL(56, temp2, 28, q_01+166+0, 28, p_10+176);
	gf2x_add(56, p_00+116+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_00+166+0, 28, p_01+176);
	GF2X_MUL(56, temp2, 28, q_01+166+0, 28, p_11+176);
	gf2x_add(56, p_01+116+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+166+0, 28, p_00+176);
	GF2X_MUL(56, temp2, 28, q_11+166+0, 28, p_10+176);
	gf2x_add(56, p_10+116+0, 56, temp, 56, temp2);
	GF2X_MUL(56, temp, 28, q_10+166+0, 28, p_01+176);
	GF2X_MUL(56, temp2, 28, q_11+166+0, 28, p_11+176);
	gf2x_add(56, p_11+116+0, 56, temp, 56, temp2);
	

	// Calculating left operands: n: 6978, depth: 1
	// Digits to shift: 55
	// Displacement: 56
	GF2X_MUL(112, temp, 56, f_sum+1+54, 56, p_00+116);
	GF2X_MUL(112, temp2, 56, g_sum+1+54, 56, p_01+116);
	gf2x_add(110, f_sum+342, 110, temp+2, 110, temp2+2);
	GF2X_MUL(108, temp, 54, p_00+116+2, 54, f_sum+1);
	GF2X_MUL(108, temp2, 54, p_01+116+2, 54, g_sum+1);
	gf2x_add(108, temp, 108, temp, 108, temp2);
	gf2x_add(54, f_sum+342, 54, f_sum+342, 54, temp+54);
	right_bit_shift_n(110, f_sum+342, 50);
	GF2X_MUL(112, temp, 56, f_sum+1+54, 56, p_10+116);
	GF2X_MUL(112, temp2, 56, g_sum+1+54, 56, p_11+116);
	gf2x_add(110, g_sum+342, 110, temp+2, 110, temp2+2);
	GF2X_MUL(108, temp, 54, p_10+116+2, 54, f_sum+1);
	GF2X_MUL(108, temp2, 54, p_11+116+2, 54, g_sum+1);
	gf2x_add(108, temp, 108, temp, 108, temp2);
	gf2x_add(54, g_sum+342, 54, g_sum+342, 54, temp+54);
	right_bit_shift_n(110, g_sum+342, 50);
	

	delta = divstepsx_256(255, delta, f_sum+393, g_sum+393, p_00+232, p_01+232, p_10+232, p_11+232);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+389+4, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+389+4, 4, p_01+232);
	gf2x_add(8, f_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+389+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+389+0, 4, p_01+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+686, 4, f_sum+686, 4, temp+4);
	right_bit_shift_n(8, f_sum+686, 63);
	GF2X_MUL(8, temp, 4, f_sum+389+4, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+389+4, 4, p_11+232);
	gf2x_add(8, g_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+389+0, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+389+0, 4, p_11+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+686, 4, g_sum+686, 4, temp+4);
	right_bit_shift_n(8, g_sum+686, 63);
	

	delta = divstepsx_256(255, delta, f_sum+687, g_sum+687, q_00+218, q_01+218, q_10+218, q_11+218);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_10+232);
	gf2x_add(8, p_00+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_11+232);
	gf2x_add(8, p_01+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_10+232);
	gf2x_add(8, p_10+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_11+232);
	gf2x_add(8, p_11+224+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+381+8, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, g_sum+381+8, 8, p_01+224);
	gf2x_add(16, f_sum+661+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+381+0, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, g_sum+381+0, 8, p_01+224);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+661, 8, f_sum+661, 8, temp+8);
	right_bit_shift_n(16, f_sum+661, 62);
	GF2X_MUL(16, temp, 8, f_sum+381+8, 8, p_10+224);
	GF2X_MUL(16, temp2, 8, g_sum+381+8, 8, p_11+224);
	gf2x_add(16, g_sum+661+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+381+0, 8, p_10+224);
	GF2X_MUL(16, temp2, 8, g_sum+381+0, 8, p_11+224);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+661, 8, g_sum+661, 8, temp+8);
	right_bit_shift_n(16, g_sum+661, 62);
	

	delta = divstepsx_256(255, delta, f_sum+666, g_sum+666, p_00+232, p_01+232, p_10+232, p_11+232);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+662+4, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+4, 4, p_01+232);
	gf2x_add(8, f_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+662+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+0, 4, p_01+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+686, 4, f_sum+686, 4, temp+4);
	right_bit_shift_n(8, f_sum+686, 63);
	GF2X_MUL(8, temp, 4, f_sum+662+4, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+4, 4, p_11+232);
	gf2x_add(8, g_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+662+0, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+0, 4, p_11+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+686, 4, g_sum+686, 4, temp+4);
	right_bit_shift_n(8, g_sum+686, 63);
	

	delta = divstepsx_256(255, delta, f_sum+687, g_sum+687, q_00+218, q_01+218, q_10+218, q_11+218);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_10+232);
	gf2x_add(8, q_00+210+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_11+232);
	gf2x_add(8, q_01+210+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_10+232);
	gf2x_add(8, q_10+210+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_11+232);
	gf2x_add(8, q_11+210+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 4
	GF2X_MUL(16, temp, 8, q_00+210+0, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, q_01+210+0, 8, p_10+224);
	gf2x_add(16, p_00+208+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+210+0, 8, p_01+224);
	GF2X_MUL(16, temp2, 8, q_01+210+0, 8, p_11+224);
	gf2x_add(16, p_01+208+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+210+0, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, q_11+210+0, 8, p_10+224);
	gf2x_add(16, p_10+208+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+210+0, 8, p_01+224);
	GF2X_MUL(16, temp2, 8, q_11+210+0, 8, p_11+224);
	gf2x_add(16, p_11+208+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 3
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+369+12, 16, p_00+208);
	GF2X_MUL(32, temp2, 16, g_sum+369+12, 16, p_01+208);
	gf2x_add(28, f_sum+612, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+208+4, 12, f_sum+369);
	GF2X_MUL(24, temp2, 12, p_01+208+4, 12, g_sum+369);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+612, 12, f_sum+612, 12, temp+12);
	right_bit_shift_n(28, f_sum+612, 60);
	GF2X_MUL(32, temp, 16, f_sum+369+12, 16, p_10+208);
	GF2X_MUL(32, temp2, 16, g_sum+369+12, 16, p_11+208);
	gf2x_add(28, g_sum+612, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+208+4, 12, f_sum+369);
	GF2X_MUL(24, temp2, 12, p_11+208+4, 12, g_sum+369);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+612, 12, g_sum+612, 12, temp+12);
	right_bit_shift_n(28, g_sum+612, 60);
	

	delta = divstepsx_256(255, delta, f_sum+621, g_sum+621, p_00+232, p_01+232, p_10+232, p_11+232);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+617+4, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+617+4, 4, p_01+232);
	gf2x_add(8, f_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+617+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+617+0, 4, p_01+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+686, 4, f_sum+686, 4, temp+4);
	right_bit_shift_n(8, f_sum+686, 63);
	GF2X_MUL(8, temp, 4, f_sum+617+4, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+617+4, 4, p_11+232);
	gf2x_add(8, g_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+617+0, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+617+0, 4, p_11+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+686, 4, g_sum+686, 4, temp+4);
	right_bit_shift_n(8, g_sum+686, 63);
	

	delta = divstepsx_256(255, delta, f_sum+687, g_sum+687, q_00+218, q_01+218, q_10+218, q_11+218);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_10+232);
	gf2x_add(8, p_00+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_11+232);
	gf2x_add(8, p_01+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_10+232);
	gf2x_add(8, p_10+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_11+232);
	gf2x_add(8, p_11+224+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+613+4, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, g_sum+613+4, 8, p_01+224);
	gf2x_add(12, f_sum+661, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+224+4, 4, f_sum+613);
	GF2X_MUL(8, temp2, 4, p_01+224+4, 4, g_sum+613);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+661, 4, f_sum+661, 4, temp+4);
	right_bit_shift_n(12, f_sum+661, 62);
	GF2X_MUL(16, temp, 8, f_sum+613+4, 8, p_10+224);
	GF2X_MUL(16, temp2, 8, g_sum+613+4, 8, p_11+224);
	gf2x_add(12, g_sum+661, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+224+4, 4, f_sum+613);
	GF2X_MUL(8, temp2, 4, p_11+224+4, 4, g_sum+613);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+661, 4, g_sum+661, 4, temp+4);
	right_bit_shift_n(12, g_sum+661, 62);
	

	delta = divstepsx_256(255, delta, f_sum+662, g_sum+662, q_00+210, q_01+210, q_10+210, q_11+210);

	// Recombining results: n: 765, depth: 4
	memset(q_00+194, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+224+4, 4, q_00+210);
	GF2X_MUL(8, temp2, 4, p_10+224+4, 4, q_01+210);
	gf2x_add(8, q_00+194+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+210+0, 4, p_00+224);
	GF2X_MUL(8, temp2, 4, q_01+210+0, 4, p_10+224);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+194+0, 8, q_00+194+0, 8, temp);
	memset(q_01+194, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+224+4, 4, q_00+210);
	GF2X_MUL(8, temp2, 4, p_11+224+4, 4, q_01+210);
	gf2x_add(8, q_01+194+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+210+0, 4, p_01+224);
	GF2X_MUL(8, temp2, 4, q_01+210+0, 4, p_11+224);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+194+0, 8, q_01+194+0, 8, temp);
	memset(q_10+194, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+224+4, 4, q_10+210);
	GF2X_MUL(8, temp2, 4, p_10+224+4, 4, q_11+210);
	gf2x_add(8, q_10+194+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+210+0, 4, p_00+224);
	GF2X_MUL(8, temp2, 4, q_11+210+0, 4, p_10+224);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+194+0, 8, q_10+194+0, 8, temp);
	memset(q_11+194, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+224+4, 4, q_10+210);
	GF2X_MUL(8, temp2, 4, p_11+224+4, 4, q_11+210);
	gf2x_add(8, q_11+194+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+210+0, 4, p_01+224);
	GF2X_MUL(8, temp2, 4, q_11+210+0, 4, p_11+224);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+194+0, 8, q_11+194+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 3
	memset(p_00+176, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+208+4, 12, q_00+194);
	GF2X_MUL(24, temp2, 12, p_10+208+4, 12, q_01+194);
	gf2x_add(24, p_00+176+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+194+8, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_01+194+8, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+176+8, 8, p_00+176+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+194+4, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_01+194+4, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+176+4, 8, p_00+176+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+194+0, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_01+194+0, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+176+0, 8, p_00+176+0, 8, temp);
	memset(p_01+176, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+208+4, 12, q_00+194);
	GF2X_MUL(24, temp2, 12, p_11+208+4, 12, q_01+194);
	gf2x_add(24, p_01+176+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+194+8, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_01+194+8, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+176+8, 8, p_01+176+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+194+4, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_01+194+4, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+176+4, 8, p_01+176+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+194+0, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_01+194+0, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+176+0, 8, p_01+176+0, 8, temp);
	memset(p_10+176, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+208+4, 12, q_10+194);
	GF2X_MUL(24, temp2, 12, p_10+208+4, 12, q_11+194);
	gf2x_add(24, p_10+176+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+194+8, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_11+194+8, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+176+8, 8, p_10+176+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+194+4, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_11+194+4, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+176+4, 8, p_10+176+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+194+0, 4, p_00+208);
	GF2X_MUL(8, temp2, 4, q_11+194+0, 4, p_10+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+176+0, 8, p_10+176+0, 8, temp);
	memset(p_11+176, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+208+4, 12, q_10+194);
	GF2X_MUL(24, temp2, 12, p_11+208+4, 12, q_11+194);
	gf2x_add(24, p_11+176+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+194+8, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_11+194+8, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+176+8, 8, p_11+176+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+194+4, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_11+194+4, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+176+4, 8, p_11+176+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+194+0, 4, p_01+208);
	GF2X_MUL(8, temp2, 4, q_11+194+0, 4, p_11+208);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+176+0, 8, p_11+176+0, 8, temp);
	

	// Calculating left operands: n: 3408, depth: 2
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+343+26, 28, p_00+176);
	GF2X_MUL(56, temp2, 28, g_sum+343+26, 28, p_01+176);
	gf2x_add(54, f_sum+519, 54, temp+2, 54, temp2+2);
	GF2X_MUL(52, temp, 26, p_00+176+2, 26, f_sum+343);
	GF2X_MUL(52, temp2, 26, p_01+176+2, 26, g_sum+343);
	gf2x_add(52, temp, 52, temp, 52, temp2);
	gf2x_add(26, f_sum+519, 26, f_sum+519, 26, temp+26);
	right_bit_shift_n(54, f_sum+519, 57);
	GF2X_MUL(56, temp, 28, f_sum+343+26, 28, p_10+176);
	GF2X_MUL(56, temp2, 28, g_sum+343+26, 28, p_11+176);
	gf2x_add(54, g_sum+519, 54, temp+2, 54, temp2+2);
	GF2X_MUL(52, temp, 26, p_10+176+2, 26, f_sum+343);
	GF2X_MUL(52, temp2, 26, p_11+176+2, 26, g_sum+343);
	gf2x_add(52, temp, 52, temp, 52, temp2);
	gf2x_add(26, g_sum+519, 26, g_sum+519, 26, temp+26);
	right_bit_shift_n(54, g_sum+519, 57);
	

	delta = divstepsx_256(255, delta, f_sum+542, g_sum+542, p_00+232, p_01+232, p_10+232, p_11+232);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+538+4, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+538+4, 4, p_01+232);
	gf2x_add(8, f_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+538+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+538+0, 4, p_01+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+686, 4, f_sum+686, 4, temp+4);
	right_bit_shift_n(8, f_sum+686, 63);
	GF2X_MUL(8, temp, 4, f_sum+538+4, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+538+4, 4, p_11+232);
	gf2x_add(8, g_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+538+0, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+538+0, 4, p_11+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+686, 4, g_sum+686, 4, temp+4);
	right_bit_shift_n(8, g_sum+686, 63);
	

	delta = divstepsx_256(255, delta, f_sum+687, g_sum+687, q_00+218, q_01+218, q_10+218, q_11+218);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_10+232);
	gf2x_add(8, p_00+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_11+232);
	gf2x_add(8, p_01+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_10+232);
	gf2x_add(8, p_10+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_11+232);
	gf2x_add(8, p_11+224+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+530+8, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, g_sum+530+8, 8, p_01+224);
	gf2x_add(16, f_sum+661+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+530+0, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, g_sum+530+0, 8, p_01+224);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+661, 8, f_sum+661, 8, temp+8);
	right_bit_shift_n(16, f_sum+661, 62);
	GF2X_MUL(16, temp, 8, f_sum+530+8, 8, p_10+224);
	GF2X_MUL(16, temp2, 8, g_sum+530+8, 8, p_11+224);
	gf2x_add(16, g_sum+661+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+530+0, 8, p_10+224);
	GF2X_MUL(16, temp2, 8, g_sum+530+0, 8, p_11+224);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+661, 8, g_sum+661, 8, temp+8);
	right_bit_shift_n(16, g_sum+661, 62);
	

	delta = divstepsx_256(255, delta, f_sum+666, g_sum+666, p_00+232, p_01+232, p_10+232, p_11+232);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+662+4, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+4, 4, p_01+232);
	gf2x_add(8, f_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+662+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+0, 4, p_01+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+686, 4, f_sum+686, 4, temp+4);
	right_bit_shift_n(8, f_sum+686, 63);
	GF2X_MUL(8, temp, 4, f_sum+662+4, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+4, 4, p_11+232);
	gf2x_add(8, g_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+662+0, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+662+0, 4, p_11+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+686, 4, g_sum+686, 4, temp+4);
	right_bit_shift_n(8, g_sum+686, 63);
	

	delta = divstepsx_256(255, delta, f_sum+687, g_sum+687, q_00+218, q_01+218, q_10+218, q_11+218);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_10+232);
	gf2x_add(8, q_00+210+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_11+232);
	gf2x_add(8, q_01+210+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_10+232);
	gf2x_add(8, q_10+210+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_11+232);
	gf2x_add(8, q_11+210+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 4
	GF2X_MUL(16, temp, 8, q_00+210+0, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, q_01+210+0, 8, p_10+224);
	gf2x_add(16, p_00+208+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+210+0, 8, p_01+224);
	GF2X_MUL(16, temp2, 8, q_01+210+0, 8, p_11+224);
	gf2x_add(16, p_01+208+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+210+0, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, q_11+210+0, 8, p_10+224);
	gf2x_add(16, p_10+208+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+210+0, 8, p_01+224);
	GF2X_MUL(16, temp2, 8, q_11+210+0, 8, p_11+224);
	gf2x_add(16, p_11+208+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1623, depth: 3
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+520+10, 16, p_00+208);
	GF2X_MUL(32, temp2, 16, g_sum+520+10, 16, p_01+208);
	gf2x_add(26, f_sum+612, 26, temp+6, 26, temp2+6);
	GF2X_MUL(20, temp, 10, p_00+208+6, 10, f_sum+520);
	GF2X_MUL(20, temp2, 10, p_01+208+6, 10, g_sum+520);
	gf2x_add(20, temp, 20, temp, 20, temp2);
	gf2x_add(10, f_sum+612, 10, f_sum+612, 10, temp+10);
	right_bit_shift_n(26, f_sum+612, 60);
	GF2X_MUL(32, temp, 16, f_sum+520+10, 16, p_10+208);
	GF2X_MUL(32, temp2, 16, g_sum+520+10, 16, p_11+208);
	gf2x_add(26, g_sum+612, 26, temp+6, 26, temp2+6);
	GF2X_MUL(20, temp, 10, p_10+208+6, 10, f_sum+520);
	GF2X_MUL(20, temp2, 10, p_11+208+6, 10, g_sum+520);
	gf2x_add(20, temp, 20, temp, 20, temp2);
	gf2x_add(10, g_sum+612, 10, g_sum+612, 10, temp+10);
	right_bit_shift_n(26, g_sum+612, 60);
	

	delta = divstepsx_256(255, delta, f_sum+619, g_sum+619, p_00+232, p_01+232, p_10+232, p_11+232);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+615+4, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+615+4, 4, p_01+232);
	gf2x_add(8, f_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+615+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, g_sum+615+0, 4, p_01+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+686, 4, f_sum+686, 4, temp+4);
	right_bit_shift_n(8, f_sum+686, 63);
	GF2X_MUL(8, temp, 4, f_sum+615+4, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+615+4, 4, p_11+232);
	gf2x_add(8, g_sum+686+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+615+0, 4, p_10+232);
	GF2X_MUL(8, temp2, 4, g_sum+615+0, 4, p_11+232);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+686, 4, g_sum+686, 4, temp+4);
	right_bit_shift_n(8, g_sum+686, 63);
	

	delta = divstepsx_256(255, delta, f_sum+687, g_sum+687, q_00+218, q_01+218, q_10+218, q_11+218);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_10+232);
	gf2x_add(8, p_00+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_01+218+0, 4, p_11+232);
	gf2x_add(8, p_01+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_00+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_10+232);
	gf2x_add(8, p_10+224+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+218+0, 4, p_01+232);
	GF2X_MUL(8, temp2, 4, q_11+218+0, 4, p_11+232);
	gf2x_add(8, p_11+224+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 603, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+613+2, 8, p_00+224);
	GF2X_MUL(16, temp2, 8, g_sum+613+2, 8, p_01+224);
	gf2x_add(10, f_sum+661, 10, temp+6, 10, temp2+6);
	GF2X_MUL(4, temp, 2, p_00+224+6, 2, f_sum+613);
	GF2X_MUL(4, temp2, 2, p_01+224+6, 2, g_sum+613);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(2, f_sum+661, 2, f_sum+661, 2, temp+2);
	right_bit_shift_n(10, f_sum+661, 62);
	GF2X_MUL(16, temp, 8, f_sum+613+2, 8, p_10+224);
	GF2X_MUL(16, temp2, 8, g_sum+613+2, 8, p_11+224);
	gf2x_add(10, g_sum+661, 10, temp+6, 10, temp2+6);
	GF2X_MUL(4, temp, 2, p_10+224+6, 2, f_sum+613);
	GF2X_MUL(4, temp2, 2, p_11+224+6, 2, g_sum+613);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(2, g_sum+661, 2, g_sum+661, 2, temp+2);
	right_bit_shift_n(10, g_sum+661, 62);
	

	delta = divstepsx_128(93, delta, f_sum+662, g_sum+662, q_00+210, q_01+210, q_10+210, q_11+210);

	// Recombining results: n: 603, depth: 4
	memset(q_00+194, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(4, temp, 2, p_00+224+6, 2, q_00+210);
	GF2X_MUL(4, temp2, 2, p_10+224+6, 2, q_01+210);
	gf2x_add(4, q_00+194+6, 4, temp, 4, temp2);
	GF2X_MUL(4, temp, 2, p_00+224+4, 2, q_00+210);
	GF2X_MUL(4, temp2, 2, p_10+224+4, 2, q_01+210);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+194+4, 4, q_00+194+4, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+224+2, 2, q_00+210);
	GF2X_MUL(4, temp2, 2, p_10+224+2, 2, q_01+210);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+194+2, 4, q_00+194+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+210+0, 2, p_00+224);
	GF2X_MUL(4, temp2, 2, q_01+210+0, 2, p_10+224);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+194+0, 4, q_00+194+0, 4, temp);
	memset(q_01+194, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(4, temp, 2, p_01+224+6, 2, q_00+210);
	GF2X_MUL(4, temp2, 2, p_11+224+6, 2, q_01+210);
	gf2x_add(4, q_01+194+6, 4, temp, 4, temp2);
	GF2X_MUL(4, temp, 2, p_01+224+4, 2, q_00+210);
	GF2X_MUL(4, temp2, 2, p_11+224+4, 2, q_01+210);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+194+4, 4, q_01+194+4, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+224+2, 2, q_00+210);
	GF2X_MUL(4, temp2, 2, p_11+224+2, 2, q_01+210);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+194+2, 4, q_01+194+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+210+0, 2, p_01+224);
	GF2X_MUL(4, temp2, 2, q_01+210+0, 2, p_11+224);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+194+0, 4, q_01+194+0, 4, temp);
	memset(q_10+194, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(4, temp, 2, p_00+224+6, 2, q_10+210);
	GF2X_MUL(4, temp2, 2, p_10+224+6, 2, q_11+210);
	gf2x_add(4, q_10+194+6, 4, temp, 4, temp2);
	GF2X_MUL(4, temp, 2, p_00+224+4, 2, q_10+210);
	GF2X_MUL(4, temp2, 2, p_10+224+4, 2, q_11+210);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+194+4, 4, q_10+194+4, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+224+2, 2, q_10+210);
	GF2X_MUL(4, temp2, 2, p_10+224+2, 2, q_11+210);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+194+2, 4, q_10+194+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+210+0, 2, p_00+224);
	GF2X_MUL(4, temp2, 2, q_11+210+0, 2, p_10+224);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+194+0, 4, q_10+194+0, 4, temp);
	memset(q_11+194, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(4, temp, 2, p_01+224+6, 2, q_10+210);
	GF2X_MUL(4, temp2, 2, p_11+224+6, 2, q_11+210);
	gf2x_add(4, q_11+194+6, 4, temp, 4, temp2);
	GF2X_MUL(4, temp, 2, p_01+224+4, 2, q_10+210);
	GF2X_MUL(4, temp2, 2, p_11+224+4, 2, q_11+210);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+194+4, 4, q_11+194+4, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+224+2, 2, q_10+210);
	GF2X_MUL(4, temp2, 2, p_11+224+2, 2, q_11+210);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+194+2, 4, q_11+194+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+210+0, 2, p_01+224);
	GF2X_MUL(4, temp2, 2, q_11+210+0, 2, p_11+224);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+194+0, 4, q_11+194+0, 4, temp);
	

	// Recombining results: n: 1623, depth: 3
	memset(q_00+166, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(20, temp, 10, p_00+208+6, 10, q_00+194);
	GF2X_MUL(20, temp2, 10, p_10+208+6, 10, q_01+194);
	gf2x_add(20, q_00+166+6, 20, temp, 20, temp2);
	GF2X_MUL(12, temp, 6, q_00+194+4, 6, p_00+208);
	GF2X_MUL(12, temp2, 6, q_01+194+4, 6, p_10+208);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+166+4, 12, q_00+166+4, 12, temp);
	GF2X_MUL(8, temp, 4, p_00+208+2, 4, q_00+194);
	GF2X_MUL(8, temp2, 4, p_10+208+2, 4, q_01+194);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+166+2, 8, q_00+166+2, 8, temp);
	GF2X_MUL(4, temp, 2, q_00+194+2, 2, p_00+208);
	GF2X_MUL(4, temp2, 2, q_01+194+2, 2, p_10+208);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+166+2, 4, q_00+166+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+194+0, 2, p_00+208);
	GF2X_MUL(4, temp2, 2, q_01+194+0, 2, p_10+208);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+166+0, 4, q_00+166+0, 4, temp);
	memset(q_01+166, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(20, temp, 10, p_01+208+6, 10, q_00+194);
	GF2X_MUL(20, temp2, 10, p_11+208+6, 10, q_01+194);
	gf2x_add(20, q_01+166+6, 20, temp, 20, temp2);
	GF2X_MUL(12, temp, 6, q_00+194+4, 6, p_01+208);
	GF2X_MUL(12, temp2, 6, q_01+194+4, 6, p_11+208);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+166+4, 12, q_01+166+4, 12, temp);
	GF2X_MUL(8, temp, 4, p_01+208+2, 4, q_00+194);
	GF2X_MUL(8, temp2, 4, p_11+208+2, 4, q_01+194);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+166+2, 8, q_01+166+2, 8, temp);
	GF2X_MUL(4, temp, 2, q_00+194+2, 2, p_01+208);
	GF2X_MUL(4, temp2, 2, q_01+194+2, 2, p_11+208);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+166+2, 4, q_01+166+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+194+0, 2, p_01+208);
	GF2X_MUL(4, temp2, 2, q_01+194+0, 2, p_11+208);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+166+0, 4, q_01+166+0, 4, temp);
	memset(q_10+166, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(20, temp, 10, p_00+208+6, 10, q_10+194);
	GF2X_MUL(20, temp2, 10, p_10+208+6, 10, q_11+194);
	gf2x_add(20, q_10+166+6, 20, temp, 20, temp2);
	GF2X_MUL(12, temp, 6, q_10+194+4, 6, p_00+208);
	GF2X_MUL(12, temp2, 6, q_11+194+4, 6, p_10+208);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+166+4, 12, q_10+166+4, 12, temp);
	GF2X_MUL(8, temp, 4, p_00+208+2, 4, q_10+194);
	GF2X_MUL(8, temp2, 4, p_10+208+2, 4, q_11+194);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+166+2, 8, q_10+166+2, 8, temp);
	GF2X_MUL(4, temp, 2, q_10+194+2, 2, p_00+208);
	GF2X_MUL(4, temp2, 2, q_11+194+2, 2, p_10+208);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+166+2, 4, q_10+166+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+194+0, 2, p_00+208);
	GF2X_MUL(4, temp2, 2, q_11+194+0, 2, p_10+208);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+166+0, 4, q_10+166+0, 4, temp);
	memset(q_11+166, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(20, temp, 10, p_01+208+6, 10, q_10+194);
	GF2X_MUL(20, temp2, 10, p_11+208+6, 10, q_11+194);
	gf2x_add(20, q_11+166+6, 20, temp, 20, temp2);
	GF2X_MUL(12, temp, 6, q_10+194+4, 6, p_01+208);
	GF2X_MUL(12, temp2, 6, q_11+194+4, 6, p_11+208);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+166+4, 12, q_11+166+4, 12, temp);
	GF2X_MUL(8, temp, 4, p_01+208+2, 4, q_10+194);
	GF2X_MUL(8, temp2, 4, p_11+208+2, 4, q_11+194);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+166+2, 8, q_11+166+2, 8, temp);
	GF2X_MUL(4, temp, 2, q_10+194+2, 2, p_01+208);
	GF2X_MUL(4, temp2, 2, q_11+194+2, 2, p_11+208);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+166+2, 4, q_11+166+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+194+0, 2, p_01+208);
	GF2X_MUL(4, temp2, 2, q_11+194+0, 2, p_11+208);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+166+0, 4, q_11+166+0, 4, temp);
	

	// Recombining results: n: 3408, depth: 2
	memset(q_00+110, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(52, temp, 26, p_00+176+2, 26, q_00+166);
	GF2X_MUL(52, temp2, 26, p_10+176+2, 26, q_01+166);
	gf2x_add(52, q_00+110+2, 52, temp, 52, temp2);
	GF2X_MUL(4, temp, 2, q_00+166+24, 2, p_00+176);
	GF2X_MUL(4, temp2, 2, q_01+166+24, 2, p_10+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+110+24, 4, q_00+110+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+166+22, 2, p_00+176);
	GF2X_MUL(4, temp2, 2, q_01+166+22, 2, p_10+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+110+22, 4, q_00+110+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+166+20, 2, p_00+176);
	GF2X_MUL(4, temp2, 2, q_01+166+20, 2, p_10+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+110+20, 4, q_00+110+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+166+18, 2, p_00+176);
	GF2X_MUL(4, temp2, 2, q_01+166+18, 2, p_10+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+110+18, 4, q_00+110+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+166+16, 2, p_00+176);
	GF2X_MUL(4, temp2, 2, q_01+166+16, 2, p_10+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+110+16, 4, q_00+110+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+166+14, 2, p_00+176);
	GF2X_MUL(4, temp2, 2, q_01+166+14, 2, p_10+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+110+14, 4, q_00+110+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+166+12, 2, p_00+176);
	GF2X_MUL(4, temp2, 2, q_01+166+12, 2, p_10+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+110+12, 4, q_00+110+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+166+10, 2, p_00+176);
	GF2X_MUL(4, temp2, 2, q_01+166+10, 2, p_10+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+110+10, 4, q_00+110+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+166+8, 2, p_00+176);
	GF2X_MUL(4, temp2, 2, q_01+166+8, 2, p_10+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+110+8, 4, q_00+110+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+166+6, 2, p_00+176);
	GF2X_MUL(4, temp2, 2, q_01+166+6, 2, p_10+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+110+6, 4, q_00+110+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+166+4, 2, p_00+176);
	GF2X_MUL(4, temp2, 2, q_01+166+4, 2, p_10+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+110+4, 4, q_00+110+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+166+2, 2, p_00+176);
	GF2X_MUL(4, temp2, 2, q_01+166+2, 2, p_10+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+110+2, 4, q_00+110+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+166+0, 2, p_00+176);
	GF2X_MUL(4, temp2, 2, q_01+166+0, 2, p_10+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+110+0, 4, q_00+110+0, 4, temp);
	memset(q_01+110, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(52, temp, 26, p_01+176+2, 26, q_00+166);
	GF2X_MUL(52, temp2, 26, p_11+176+2, 26, q_01+166);
	gf2x_add(52, q_01+110+2, 52, temp, 52, temp2);
	GF2X_MUL(4, temp, 2, q_00+166+24, 2, p_01+176);
	GF2X_MUL(4, temp2, 2, q_01+166+24, 2, p_11+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+110+24, 4, q_01+110+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+166+22, 2, p_01+176);
	GF2X_MUL(4, temp2, 2, q_01+166+22, 2, p_11+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+110+22, 4, q_01+110+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+166+20, 2, p_01+176);
	GF2X_MUL(4, temp2, 2, q_01+166+20, 2, p_11+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+110+20, 4, q_01+110+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+166+18, 2, p_01+176);
	GF2X_MUL(4, temp2, 2, q_01+166+18, 2, p_11+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+110+18, 4, q_01+110+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+166+16, 2, p_01+176);
	GF2X_MUL(4, temp2, 2, q_01+166+16, 2, p_11+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+110+16, 4, q_01+110+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+166+14, 2, p_01+176);
	GF2X_MUL(4, temp2, 2, q_01+166+14, 2, p_11+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+110+14, 4, q_01+110+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+166+12, 2, p_01+176);
	GF2X_MUL(4, temp2, 2, q_01+166+12, 2, p_11+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+110+12, 4, q_01+110+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+166+10, 2, p_01+176);
	GF2X_MUL(4, temp2, 2, q_01+166+10, 2, p_11+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+110+10, 4, q_01+110+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+166+8, 2, p_01+176);
	GF2X_MUL(4, temp2, 2, q_01+166+8, 2, p_11+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+110+8, 4, q_01+110+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+166+6, 2, p_01+176);
	GF2X_MUL(4, temp2, 2, q_01+166+6, 2, p_11+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+110+6, 4, q_01+110+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+166+4, 2, p_01+176);
	GF2X_MUL(4, temp2, 2, q_01+166+4, 2, p_11+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+110+4, 4, q_01+110+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+166+2, 2, p_01+176);
	GF2X_MUL(4, temp2, 2, q_01+166+2, 2, p_11+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+110+2, 4, q_01+110+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+166+0, 2, p_01+176);
	GF2X_MUL(4, temp2, 2, q_01+166+0, 2, p_11+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+110+0, 4, q_01+110+0, 4, temp);
	memset(q_10+110, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(52, temp, 26, p_00+176+2, 26, q_10+166);
	GF2X_MUL(52, temp2, 26, p_10+176+2, 26, q_11+166);
	gf2x_add(52, q_10+110+2, 52, temp, 52, temp2);
	GF2X_MUL(4, temp, 2, q_10+166+24, 2, p_00+176);
	GF2X_MUL(4, temp2, 2, q_11+166+24, 2, p_10+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+110+24, 4, q_10+110+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+166+22, 2, p_00+176);
	GF2X_MUL(4, temp2, 2, q_11+166+22, 2, p_10+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+110+22, 4, q_10+110+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+166+20, 2, p_00+176);
	GF2X_MUL(4, temp2, 2, q_11+166+20, 2, p_10+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+110+20, 4, q_10+110+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+166+18, 2, p_00+176);
	GF2X_MUL(4, temp2, 2, q_11+166+18, 2, p_10+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+110+18, 4, q_10+110+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+166+16, 2, p_00+176);
	GF2X_MUL(4, temp2, 2, q_11+166+16, 2, p_10+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+110+16, 4, q_10+110+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+166+14, 2, p_00+176);
	GF2X_MUL(4, temp2, 2, q_11+166+14, 2, p_10+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+110+14, 4, q_10+110+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+166+12, 2, p_00+176);
	GF2X_MUL(4, temp2, 2, q_11+166+12, 2, p_10+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+110+12, 4, q_10+110+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+166+10, 2, p_00+176);
	GF2X_MUL(4, temp2, 2, q_11+166+10, 2, p_10+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+110+10, 4, q_10+110+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+166+8, 2, p_00+176);
	GF2X_MUL(4, temp2, 2, q_11+166+8, 2, p_10+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+110+8, 4, q_10+110+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+166+6, 2, p_00+176);
	GF2X_MUL(4, temp2, 2, q_11+166+6, 2, p_10+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+110+6, 4, q_10+110+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+166+4, 2, p_00+176);
	GF2X_MUL(4, temp2, 2, q_11+166+4, 2, p_10+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+110+4, 4, q_10+110+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+166+2, 2, p_00+176);
	GF2X_MUL(4, temp2, 2, q_11+166+2, 2, p_10+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+110+2, 4, q_10+110+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+166+0, 2, p_00+176);
	GF2X_MUL(4, temp2, 2, q_11+166+0, 2, p_10+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+110+0, 4, q_10+110+0, 4, temp);
	memset(q_11+110, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(52, temp, 26, p_01+176+2, 26, q_10+166);
	GF2X_MUL(52, temp2, 26, p_11+176+2, 26, q_11+166);
	gf2x_add(52, q_11+110+2, 52, temp, 52, temp2);
	GF2X_MUL(4, temp, 2, q_10+166+24, 2, p_01+176);
	GF2X_MUL(4, temp2, 2, q_11+166+24, 2, p_11+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+110+24, 4, q_11+110+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+166+22, 2, p_01+176);
	GF2X_MUL(4, temp2, 2, q_11+166+22, 2, p_11+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+110+22, 4, q_11+110+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+166+20, 2, p_01+176);
	GF2X_MUL(4, temp2, 2, q_11+166+20, 2, p_11+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+110+20, 4, q_11+110+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+166+18, 2, p_01+176);
	GF2X_MUL(4, temp2, 2, q_11+166+18, 2, p_11+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+110+18, 4, q_11+110+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+166+16, 2, p_01+176);
	GF2X_MUL(4, temp2, 2, q_11+166+16, 2, p_11+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+110+16, 4, q_11+110+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+166+14, 2, p_01+176);
	GF2X_MUL(4, temp2, 2, q_11+166+14, 2, p_11+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+110+14, 4, q_11+110+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+166+12, 2, p_01+176);
	GF2X_MUL(4, temp2, 2, q_11+166+12, 2, p_11+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+110+12, 4, q_11+110+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+166+10, 2, p_01+176);
	GF2X_MUL(4, temp2, 2, q_11+166+10, 2, p_11+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+110+10, 4, q_11+110+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+166+8, 2, p_01+176);
	GF2X_MUL(4, temp2, 2, q_11+166+8, 2, p_11+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+110+8, 4, q_11+110+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+166+6, 2, p_01+176);
	GF2X_MUL(4, temp2, 2, q_11+166+6, 2, p_11+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+110+6, 4, q_11+110+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+166+4, 2, p_01+176);
	GF2X_MUL(4, temp2, 2, q_11+166+4, 2, p_11+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+110+4, 4, q_11+110+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+166+2, 2, p_01+176);
	GF2X_MUL(4, temp2, 2, q_11+166+2, 2, p_11+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+110+2, 4, q_11+110+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+166+0, 2, p_01+176);
	GF2X_MUL(4, temp2, 2, q_11+166+0, 2, p_11+176);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+110+0, 4, q_11+110+0, 4, temp);
	

	// Recombining results: n: 6978, depth: 1
	memset(q_00+0, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(108, temp, 54, p_00+116+2, 54, q_00+110);
	GF2X_MUL(108, temp2, 54, p_10+116+2, 54, q_01+110);
	gf2x_add(108, q_00+0+2, 108, temp, 108, temp2);
	GF2X_MUL(4, temp, 2, q_00+110+52, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_01+110+52, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+52, 4, q_00+0+52, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+50, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_01+110+50, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+50, 4, q_00+0+50, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+48, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_01+110+48, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+48, 4, q_00+0+48, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+46, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_01+110+46, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+46, 4, q_00+0+46, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+44, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_01+110+44, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+44, 4, q_00+0+44, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+42, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_01+110+42, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+42, 4, q_00+0+42, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+40, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_01+110+40, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+40, 4, q_00+0+40, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+38, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_01+110+38, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+38, 4, q_00+0+38, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+36, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_01+110+36, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+36, 4, q_00+0+36, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+34, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_01+110+34, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+34, 4, q_00+0+34, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+32, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_01+110+32, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+32, 4, q_00+0+32, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+30, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_01+110+30, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+30, 4, q_00+0+30, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+28, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_01+110+28, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+28, 4, q_00+0+28, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+26, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_01+110+26, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+26, 4, q_00+0+26, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+24, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_01+110+24, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+24, 4, q_00+0+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+22, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_01+110+22, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+22, 4, q_00+0+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+20, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_01+110+20, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+20, 4, q_00+0+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+18, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_01+110+18, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+18, 4, q_00+0+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+16, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_01+110+16, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+16, 4, q_00+0+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+14, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_01+110+14, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+14, 4, q_00+0+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+12, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_01+110+12, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+12, 4, q_00+0+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+10, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_01+110+10, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+10, 4, q_00+0+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+8, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_01+110+8, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+8, 4, q_00+0+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+6, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_01+110+6, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+6, 4, q_00+0+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+4, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_01+110+4, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+4, 4, q_00+0+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+2, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_01+110+2, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+2, 4, q_00+0+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+0, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_01+110+0, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+0, 4, q_00+0+0, 4, temp);
	memset(q_01+0, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(108, temp, 54, p_01+116+2, 54, q_00+110);
	GF2X_MUL(108, temp2, 54, p_11+116+2, 54, q_01+110);
	gf2x_add(108, q_01+0+2, 108, temp, 108, temp2);
	GF2X_MUL(4, temp, 2, q_00+110+52, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_01+110+52, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+52, 4, q_01+0+52, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+50, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_01+110+50, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+50, 4, q_01+0+50, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+48, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_01+110+48, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+48, 4, q_01+0+48, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+46, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_01+110+46, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+46, 4, q_01+0+46, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+44, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_01+110+44, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+44, 4, q_01+0+44, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+42, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_01+110+42, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+42, 4, q_01+0+42, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+40, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_01+110+40, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+40, 4, q_01+0+40, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+38, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_01+110+38, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+38, 4, q_01+0+38, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+36, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_01+110+36, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+36, 4, q_01+0+36, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+34, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_01+110+34, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+34, 4, q_01+0+34, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+32, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_01+110+32, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+32, 4, q_01+0+32, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+30, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_01+110+30, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+30, 4, q_01+0+30, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+28, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_01+110+28, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+28, 4, q_01+0+28, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+26, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_01+110+26, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+26, 4, q_01+0+26, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+24, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_01+110+24, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+24, 4, q_01+0+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+22, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_01+110+22, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+22, 4, q_01+0+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+20, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_01+110+20, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+20, 4, q_01+0+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+18, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_01+110+18, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+18, 4, q_01+0+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+16, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_01+110+16, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+16, 4, q_01+0+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+14, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_01+110+14, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+14, 4, q_01+0+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+12, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_01+110+12, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+12, 4, q_01+0+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+10, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_01+110+10, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+10, 4, q_01+0+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+8, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_01+110+8, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+8, 4, q_01+0+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+6, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_01+110+6, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+6, 4, q_01+0+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+4, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_01+110+4, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+4, 4, q_01+0+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+2, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_01+110+2, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+2, 4, q_01+0+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+110+0, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_01+110+0, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+0, 4, q_01+0+0, 4, temp);
	memset(q_10+0, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(108, temp, 54, p_00+116+2, 54, q_10+110);
	GF2X_MUL(108, temp2, 54, p_10+116+2, 54, q_11+110);
	gf2x_add(108, q_10+0+2, 108, temp, 108, temp2);
	GF2X_MUL(4, temp, 2, q_10+110+52, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_11+110+52, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+52, 4, q_10+0+52, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+50, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_11+110+50, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+50, 4, q_10+0+50, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+48, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_11+110+48, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+48, 4, q_10+0+48, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+46, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_11+110+46, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+46, 4, q_10+0+46, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+44, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_11+110+44, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+44, 4, q_10+0+44, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+42, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_11+110+42, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+42, 4, q_10+0+42, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+40, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_11+110+40, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+40, 4, q_10+0+40, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+38, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_11+110+38, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+38, 4, q_10+0+38, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+36, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_11+110+36, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+36, 4, q_10+0+36, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+34, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_11+110+34, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+34, 4, q_10+0+34, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+32, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_11+110+32, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+32, 4, q_10+0+32, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+30, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_11+110+30, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+30, 4, q_10+0+30, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+28, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_11+110+28, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+28, 4, q_10+0+28, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+26, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_11+110+26, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+26, 4, q_10+0+26, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+24, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_11+110+24, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+24, 4, q_10+0+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+22, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_11+110+22, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+22, 4, q_10+0+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+20, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_11+110+20, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+20, 4, q_10+0+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+18, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_11+110+18, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+18, 4, q_10+0+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+16, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_11+110+16, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+16, 4, q_10+0+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+14, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_11+110+14, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+14, 4, q_10+0+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+12, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_11+110+12, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+12, 4, q_10+0+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+10, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_11+110+10, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+10, 4, q_10+0+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+8, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_11+110+8, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+8, 4, q_10+0+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+6, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_11+110+6, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+6, 4, q_10+0+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+4, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_11+110+4, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+4, 4, q_10+0+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+2, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_11+110+2, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+2, 4, q_10+0+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+0, 2, p_00+116);
	GF2X_MUL(4, temp2, 2, q_11+110+0, 2, p_10+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+0, 4, q_10+0+0, 4, temp);
	memset(q_11+0, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(108, temp, 54, p_01+116+2, 54, q_10+110);
	GF2X_MUL(108, temp2, 54, p_11+116+2, 54, q_11+110);
	gf2x_add(108, q_11+0+2, 108, temp, 108, temp2);
	GF2X_MUL(4, temp, 2, q_10+110+52, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_11+110+52, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+52, 4, q_11+0+52, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+50, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_11+110+50, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+50, 4, q_11+0+50, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+48, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_11+110+48, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+48, 4, q_11+0+48, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+46, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_11+110+46, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+46, 4, q_11+0+46, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+44, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_11+110+44, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+44, 4, q_11+0+44, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+42, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_11+110+42, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+42, 4, q_11+0+42, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+40, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_11+110+40, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+40, 4, q_11+0+40, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+38, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_11+110+38, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+38, 4, q_11+0+38, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+36, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_11+110+36, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+36, 4, q_11+0+36, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+34, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_11+110+34, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+34, 4, q_11+0+34, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+32, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_11+110+32, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+32, 4, q_11+0+32, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+30, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_11+110+30, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+30, 4, q_11+0+30, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+28, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_11+110+28, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+28, 4, q_11+0+28, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+26, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_11+110+26, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+26, 4, q_11+0+26, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+24, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_11+110+24, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+24, 4, q_11+0+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+22, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_11+110+22, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+22, 4, q_11+0+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+20, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_11+110+20, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+20, 4, q_11+0+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+18, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_11+110+18, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+18, 4, q_11+0+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+16, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_11+110+16, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+16, 4, q_11+0+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+14, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_11+110+14, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+14, 4, q_11+0+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+12, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_11+110+12, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+12, 4, q_11+0+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+10, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_11+110+10, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+10, 4, q_11+0+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+8, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_11+110+8, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+8, 4, q_11+0+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+6, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_11+110+6, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+6, 4, q_11+0+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+4, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_11+110+4, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+4, 4, q_11+0+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+2, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_11+110+2, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+2, 4, q_11+0+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+110+0, 2, p_01+116);
	GF2X_MUL(4, temp2, 2, q_11+110+0, 2, p_11+116);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+0, 4, q_11+0+0, 4, temp);
	

	// Recombining results: n: 14373, depth: 0
	memset(t_00+0, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(220, temp, 110, p_00+0+6, 110, q_00+0);
	GF2X_MUL(220, temp2, 110, p_10+0+6, 110, q_01+0);
	gf2x_add(220, t_00+0+5, 220, temp, 220, temp2);
	GF2X_MUL(12, temp, 6, q_00+0+104, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+104, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+103, 12, t_00+0+103, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+98, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+98, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+97, 12, t_00+0+97, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+92, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+92, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+91, 12, t_00+0+91, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+86, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+86, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+85, 12, t_00+0+85, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+80, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+80, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+79, 12, t_00+0+79, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+74, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+74, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+73, 12, t_00+0+73, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+68, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+68, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+67, 12, t_00+0+67, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+62, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+62, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+61, 12, t_00+0+61, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+56, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+56, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+55, 12, t_00+0+55, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+50, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+50, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+49, 12, t_00+0+49, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+44, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+44, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+43, 12, t_00+0+43, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+38, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+38, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+37, 12, t_00+0+37, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+32, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+32, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+31, 12, t_00+0+31, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+26, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+26, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+25, 12, t_00+0+25, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+20, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+20, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+19, 12, t_00+0+19, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+14, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+14, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+13, 12, t_00+0+13, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+8, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+8, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+7, 12, t_00+0+7, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+2, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+2, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+1, 12, t_00+0+1, 12, temp);
	GF2X_MUL(4, temp, 2, p_00+0+4, 2, q_00+0);
	GF2X_MUL(4, temp2, 2, p_10+0+4, 2, q_01+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+3, 4, t_00+0+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+0+2, 2, q_00+0);
	GF2X_MUL(4, temp2, 2, p_10+0+2, 2, q_01+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+1, 4, t_00+0+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+0, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+0, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, t_00+0, 3, t_00+0, 3, temp+1);
	memset(t_01+0, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(220, temp, 110, p_01+0+6, 110, q_00+0);
	GF2X_MUL(220, temp2, 110, p_11+0+6, 110, q_01+0);
	gf2x_add(220, t_01+0+5, 220, temp, 220, temp2);
	GF2X_MUL(12, temp, 6, q_00+0+104, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+104, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+103, 12, t_01+0+103, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+98, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+98, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+97, 12, t_01+0+97, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+92, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+92, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+91, 12, t_01+0+91, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+86, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+86, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+85, 12, t_01+0+85, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+80, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+80, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+79, 12, t_01+0+79, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+74, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+74, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+73, 12, t_01+0+73, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+68, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+68, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+67, 12, t_01+0+67, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+62, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+62, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+61, 12, t_01+0+61, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+56, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+56, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+55, 12, t_01+0+55, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+50, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+50, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+49, 12, t_01+0+49, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+44, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+44, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+43, 12, t_01+0+43, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+38, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+38, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+37, 12, t_01+0+37, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+32, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+32, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+31, 12, t_01+0+31, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+26, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+26, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+25, 12, t_01+0+25, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+20, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+20, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+19, 12, t_01+0+19, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+14, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+14, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+13, 12, t_01+0+13, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+8, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+8, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+7, 12, t_01+0+7, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+2, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+2, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+1, 12, t_01+0+1, 12, temp);
	GF2X_MUL(4, temp, 2, p_01+0+4, 2, q_00+0);
	GF2X_MUL(4, temp2, 2, p_11+0+4, 2, q_01+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+3, 4, t_01+0+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+0+2, 2, q_00+0);
	GF2X_MUL(4, temp2, 2, p_11+0+2, 2, q_01+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+1, 4, t_01+0+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+0, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+0, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, t_01+0, 3, t_01+0, 3, temp+1);
	memset(t_10+0, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(220, temp, 110, p_00+0+6, 110, q_10+0);
	GF2X_MUL(220, temp2, 110, p_10+0+6, 110, q_11+0);
	gf2x_add(220, t_10+0+5, 220, temp, 220, temp2);
	GF2X_MUL(12, temp, 6, q_10+0+104, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+104, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+103, 12, t_10+0+103, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+98, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+98, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+97, 12, t_10+0+97, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+92, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+92, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+91, 12, t_10+0+91, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+86, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+86, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+85, 12, t_10+0+85, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+80, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+80, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+79, 12, t_10+0+79, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+74, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+74, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+73, 12, t_10+0+73, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+68, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+68, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+67, 12, t_10+0+67, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+62, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+62, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+61, 12, t_10+0+61, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+56, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+56, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+55, 12, t_10+0+55, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+50, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+50, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+49, 12, t_10+0+49, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+44, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+44, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+43, 12, t_10+0+43, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+38, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+38, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+37, 12, t_10+0+37, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+32, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+32, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+31, 12, t_10+0+31, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+26, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+26, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+25, 12, t_10+0+25, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+20, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+20, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+19, 12, t_10+0+19, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+14, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+14, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+13, 12, t_10+0+13, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+8, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+8, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+7, 12, t_10+0+7, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+2, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+2, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+1, 12, t_10+0+1, 12, temp);
	GF2X_MUL(4, temp, 2, p_00+0+4, 2, q_10+0);
	GF2X_MUL(4, temp2, 2, p_10+0+4, 2, q_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+3, 4, t_10+0+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+0+2, 2, q_10+0);
	GF2X_MUL(4, temp2, 2, p_10+0+2, 2, q_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+1, 4, t_10+0+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+0, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+0, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, t_10+0, 3, t_10+0, 3, temp+1);
	memset(t_11+0, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(220, temp, 110, p_01+0+6, 110, q_10+0);
	GF2X_MUL(220, temp2, 110, p_11+0+6, 110, q_11+0);
	gf2x_add(220, t_11+0+5, 220, temp, 220, temp2);
	GF2X_MUL(12, temp, 6, q_10+0+104, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+104, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+103, 12, t_11+0+103, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+98, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+98, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+97, 12, t_11+0+97, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+92, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+92, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+91, 12, t_11+0+91, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+86, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+86, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+85, 12, t_11+0+85, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+80, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+80, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+79, 12, t_11+0+79, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+74, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+74, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+73, 12, t_11+0+73, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+68, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+68, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+67, 12, t_11+0+67, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+62, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+62, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+61, 12, t_11+0+61, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+56, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+56, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+55, 12, t_11+0+55, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+50, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+50, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+49, 12, t_11+0+49, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+44, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+44, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+43, 12, t_11+0+43, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+38, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+38, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+37, 12, t_11+0+37, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+32, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+32, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+31, 12, t_11+0+31, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+26, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+26, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+25, 12, t_11+0+25, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+20, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+20, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+19, 12, t_11+0+19, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+14, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+14, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+13, 12, t_11+0+13, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+8, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+8, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+7, 12, t_11+0+7, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+2, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+2, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+1, 12, t_11+0+1, 12, temp);
	GF2X_MUL(4, temp, 2, p_01+0+4, 2, q_10+0);
	GF2X_MUL(4, temp2, 2, p_11+0+4, 2, q_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+3, 4, t_11+0+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+0+2, 2, q_10+0);
	GF2X_MUL(4, temp2, 2, p_11+0+2, 2, q_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+1, 4, t_11+0+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+0, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+0, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, t_11+0, 3, t_11+0, 3, temp+1);
	

	return delta;
}