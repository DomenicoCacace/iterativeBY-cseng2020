import treeUtils as tree
import constants as k

# Assembles the declaration part and the "execution" part
def assemble(root):
    code = ""
    code+=init(root)
    code+=unrollTree(root)

    print(code)

def unrollTree(node):
    code = ""
    if(node != None):
        if(tree.isLeaf(node)):
            # determining which offset to consider
            if(node.operandSource == "fgsum"):
                in_offset = k.fgsum_offset[-1]
            else:
                in_offset = k.fg_offset[-1]

            # calling divstep, splitting the cases to store the results in the correct 
            # arrays (P or Q)
            if(node == node.parent.right):
                code+=divstep(node, "p", in_offset, k.p_offset[-1])
            else:
                code+=divstep(node, "q", in_offset, k.q_offset[-1])
            return code

        code+=unrollTree(node.right)
        # calculate operands for the left subtree

        code+=unrollTree(node.left)
        # recombine the results
        return code

# Declaring all the necessary arrays to store the P and Q matrices, intermediate
# and temporary results and suboperands
def init(root):
    code = ""
    code+="DIGIT p_00[" + str(k.psize) +"];\n"
    code+="DIGIT p_01[" + str(k.psize) +"];\n"
    code+="DIGIT p_10[" + str(k.psize) +"];\n"
    code+="DIGIT p_11[" + str(k.psize) +"];\n"
    code+="\n"
    code+="DIGIT q_00[" + str(k.qsize) +"];\n"
    code+="DIGIT q_01[" + str(k.qsize) +"];\n"
    code+="DIGIT q_10[" + str(k.qsize) +"];\n"
    code+="DIGIT q_11[" + str(k.qsize) +"];\n"
    code+="\n"
    code+="DIGIT f_sum[" + str(k.fgsumSize) + "];\n"
    code+="DIGIT g_sum[" + str(k.fgsumSize) + "];\n"
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



########## GF2X OPERATIONS ##########

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



########## DIVSTEP FUNCTIONS ##########

# Generates the code for the divstep calls
def divstep(node, resDest, in_off, out_off):
    if(node.n < 192):
        return support_jumpdivstep(node, resDest, in_off, out_off)
    else:
        return divstepx_256(node, resDest, in_off, out_off)

# Divstep for n < 256
def divstepx_256(node, resDest, in_off, out_off):
    return ""
    pass

# Divstep for n < 192
def support_jumpdivstep(node, resDest, in_off, out_off):
    if (node.n < 128):
        return divstepx_128(node, resDest, in_off, out_off)
    else:
        # TODO: do stuff
        return ""
        pass

# Divstep for n < 128
def divstepx_128(node, resDest, in_off, out_off):
    if(node.n < 64):
        return divstepx(node, resDest, in_off, out_off)
    else:
        # TODO: do stuff
        return ""
        pass

# DIvstep for n < 64
def divstepx(node, resDest, in_off, out_off):
    #TODO: do stuff
    return ""
    pass