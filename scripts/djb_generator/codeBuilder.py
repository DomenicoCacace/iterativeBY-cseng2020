import treeUtils as tree

# Assembles the declaration part and the "execution" part
def assemble(root, pSize, qSize, p_off, q_off, fg_off, fgsumSize, fgsum_off):
    code = ""
    code+=init(root, pSize, qSize, fgsumSize)
    code+=unrollTree(root, p_off, q_off, fg_off, fgsum_off)

    print(code)

def unrollTree(node, p_off, q_off, fg_off, fgsum_off):
    code = ""
    if(tree.isLeaf(node)):
        # determining which offset to consider
        if(node.operandSource == "fgsum"):
            in_offset = fgsum_off[-1]
        else:
            in_offset = fg_off[-1]

        # calling divstep, splitting the cases to store the results in the correct 
        # arrays (P or Q)
        if(node == node.parent.right):
            code+=divstep(node, "p", in_offset, p_off[-1])
        else:
            code+=divstep(node, "q", in_offset, q_off[-1])

    code+=unrollTree(node.right, p_off, q_off. fg_off. fgsum_off)
    # calculate operands for the left subtree

    code+=unrollTree(node.left, p_off, q_off. fg_off. fgsum_off)
    # recombine the results


def divstep(node, resDest, in_off, out_off):
    


# Declaring all the necessary arrays to store the P and Q matrices, intermediate
# and temporary results and suboperands
def init(root, pSize, qSize, fgsumSize):
    code = ""
    code+="DIGIT p_00[" + str(pSize) +"];\n"
    code+="DIGIT p_01[" + str(pSize) +"];\n"
    code+="DIGIT p_10[" + str(pSize) +"];\n"
    code+="DIGIT p_11[" + str(pSize) +"];\n"
    code+="\n"
    code+="DIGIT q_00[" + str(qSize) +"];\n"
    code+="DIGIT q_01[" + str(qSize) +"];\n"
    code+="DIGIT q_10[" + str(qSize) +"];\n"
    code+="DIGIT q_11[" + str(qSize) +"];\n"
    code+="\n"
    code+="DIGIT  f_sum[" + str(fgsumSize) + "];\n"
    code+="DIGIT  g_sum[" + str(fgsumSize) + "];\n"
    code+="\n"
    code+="DIGIT temp[" + str(root.num_digits_j+root.num_digits_nminusj) +"];\n"
    code+="DIGIT buffer[" + str(root.num_digits_j*2) + "];\n"
    return code

def calcFGsum(node, res_off, input_off):
    code = ""
    code+=""
    pass

def recombine(node, res_off, input_off):
    pass

# Writes the code for the scalar product between two couples of arrays,
# eventually using a buffer to have same length operands and guarantee
#a costant time execution
def scalarprod(node, nr, res, na, a0, a1, nb, b0, b1):
    code = ""
    if(na == nb):
        code+=GF2X_MUL(nr, res, na, a0, nb, b0)
        code+=GF2X_MUL(nr, "temp", na, a1, nb, b1)
        code+=GF2X_ADD(nr, res, "temp", res)
    elif(na > nb):
        code+=memset(na-nb)
        code+=memcpy("buffer+" + str(na-nb),  b0, nb)
        code+=GF2X_MUL(na*2, res, na, a0, na, "buffer")
        code+=memcpy("buffer+" + str(na-nb),  b1, nb)
        code+=GF2X_MUL(na*2, "temp", na, a1, na, "buffer")
        code+=GF2X_ADD(na*2, "temp", res, "temp")
        code+=memcpy(res, "temp+" + str(na-nb), nr)
    else:
        code+=memset(nb-na)
        code+=memcpy("buffer+" + str(nb-na),  a0, na)
        code+=GF2X_MUL(nb*2, res, nb, "buffer", nb, b0)
        code+=memcpy("buffer+" + str(nb-na),  a1, na)
        code+=GF2X_MUL(nb*2, "temp", nb, "buffer", nb, b1)
        code+=GF2X_ADD(nb*2, "temp", res, "temp")
        code+=memcpy(res, "temp+" + str(nb-na), nr)
    
    return code

# Generates the code for a base multiplication
def GF2X_MUL(nr, res, na, a, nb, b):
    return "GF2X_MUL(" + str(nr) + ", " + res + ", " + str(na) + ", " + a + str(nb) + ", " + b + ");\n"

# Generates the code for a base addition
def GF2X_ADD(size, res, a0, a1):
    return "gf2x_add(" + str(size) + ", " + res + ", " + str(size) + ", " + a0 + ", " + str(size) + ", " + a1 + ");\n"

# Generates the code to set the buffer initial values to zero
def memset(size):
    return "memset(buffer, 0x00, " + str(size) +" + DIGIT_SIZE_B);\n"

# Generates the code to copy len DIGITs of src to dest
def memcpy(dest, src, len):
    return "memcpy(" + dest + ", " + src + ", " + str(len) + " * DIGIT_SIZE_B);\n"

# Generates the code to perform a right shift; the function called is an inline,
# no need to "decompose" it into its parts
def digit_shift(len, input, amount):
    return "right_bit_shift_wide_n(" + str(len) + ", " + input + ", " + str(amount) + ");\n"