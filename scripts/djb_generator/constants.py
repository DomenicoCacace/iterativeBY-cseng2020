# @author Domenico Cacace <domenico.cacace@mail.polimi.it>
# 
# This code is hereby placed in the public domain.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHORS ''AS IS'' AND ANY EXPRESS
# OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
# BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
# WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
# OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
# EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

# Memory related constants
DIGIT_SIZE_B = 0
DIGIT_SIZE_b =0
WS = 0
AVX = True

# Maximum size for direct multiplications
CHUNK_SIZE = 9

# Software license
swLicense = []

# Enables the print_pol functions
debug = False

# P and Q sizes and offsets
psize = 0
qsize = 0
p_offset = []
q_offset = []

#f_sum and g_sum size and offset
fgsumSize = 0
fgsum_offset = []

# f and g offsets
fg_offset = []

# Resets the constants between rounds
def resetConstants():
    global qsize, psize, fgsumSize
    psize = 0
    qsize = 0
    fgsumSize = 0

    global p_offset, q_offset, fgsum_offset, fg_offset
    p_offset.clear()
    q_offset.clear()
    fgsum_offset.clear()
    fg_offset.clear()

# To assemble the header file
signatures = []
