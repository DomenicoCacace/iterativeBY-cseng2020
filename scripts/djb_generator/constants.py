# Machine-related the current values apply for for machines allowing all the
# possible optimizations in terms of AVX instructions (computing 4 DIGITs
# in parallel)
DIGIT_SIZE_B = 8
DIGIT_SIZE_b = DIGIT_SIZE_B << 3
WS = 2

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
