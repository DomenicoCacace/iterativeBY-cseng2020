# Machine-related the current values apply for for machines allowing all the
# possible optimizations in terms of AVX instructions (computing 4 DIGITs
# in parallel)
# TODO: generalize to allow the code to be architecture-independent
DIGIT_SIZE_B = 8
DIGIT_SIZE_b = DIGIT_SIZE_B << 3
WS = 256

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
