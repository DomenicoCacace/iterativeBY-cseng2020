/**
 * Software Artifact of the paper A Comprehensive Analysis of Constant-time
 * Polynomial Inversion for Post-quantum Cryptosystems
 *
 * @author Alessandro Barenghi <alessandro.barenghi@polimi.it>
 * @author Gerardo Pelosi <gerardo.pelosi@polimi.it>
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

#pragma once

void gf2x_scalarprod(int nr, DIGIT Res[],
                     int na, DIGIT a0[], DIGIT a1[],
                     int nb, DIGIT b0[], DIGIT b1[]);

int divstepsx(int n, int delta,
              DIGIT f64, DIGIT g64,
              DIGIT * p00, DIGIT * p01,
              DIGIT * p10, DIGIT * p11);

int divstepsx_128(int n, int delta,
                  DIGIT f[], DIGIT g[],
                  DIGIT * p00, DIGIT * p01,
                  DIGIT * p10, DIGIT * p11);

int divstepsx_256(int n, int delta,
                  DIGIT f[], DIGIT g[],
                  DIGIT * p00, DIGIT * p01,
                  DIGIT * p10, DIGIT * p11);

int support_jumpdivstep(int n, int delta,
                        int nf, DIGIT   f[], DIGIT g[],
                        DIGIT t00[], DIGIT t01[],
                        DIGIT t10[], DIGIT t11[], float x);

int jumpdivstep(int n_in, int delta,
                int nf, DIGIT   f[], DIGIT g[],
                DIGIT t00[], DIGIT t01[],
                DIGIT t10[], DIGIT t11[], float x);

int inverse_DJB(DIGIT out[], const DIGIT in[], float x);
