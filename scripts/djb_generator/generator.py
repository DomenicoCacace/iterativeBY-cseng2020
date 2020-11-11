import treeUtils as tree
import constants as k

# Assembles the declaration part and the "execution" part
def assemble(root):
    code = []
    code.extend(init(root))
    code.extend(unrollTree(root))
    code.append("return delta;\n")

    return code

def unrollTree(node):
    code = []
    if(node != None):
        if(tree.isLeaf(node)):
            # determining which offset to consider
            if(node.operandSource == "fgsum"):
                f = "f_sum+" + str(node.inputOffset)
                g = "g_sum+" + str(node.inputOffset)
            else:
                f = "f+" + str(node.inputOffset)
                g = "g+" + str(node.inputOffset)

            # calling divstep, splitting the cases to store the results in the correct 
            # arrays (P or Q)
            if(node == node.parent.right):
                code.extend(divstep(node, "p", f, g, k.p_offset[node.depth]))
            else:
                code.extend(divstep(node, "q", f, g, k.q_offset[node.depth]))
            return code

        code.extend(unrollTree(node.right))
        # calculate operands for the left subtree
        code.extend(calculateLeftOperands(node))

        code.extend(unrollTree(node.left))
        # recombine the results
        code.extend(recombine(node))

        return code

# Declaring all the necessary arrays to store the P and Q matrices, intermediate
# and temporary results and suboperands
def init(root):
    code = []
    code.append("DIGIT p_00[" + str(k.psize) +"];\n")
    code.append("DIGIT p_01[" + str(k.psize) +"];\n")
    code.append("DIGIT p_10[" + str(k.psize) +"];\n")
    code.append("DIGIT p_11[" + str(k.psize) +"];\n")
    code.append("\n")
    code.append("DIGIT q_00[" + str(k.qsize) +"];\n")
    code.append("DIGIT q_01[" + str(k.qsize) +"];\n")
    code.append("DIGIT q_10[" + str(k.qsize) +"];\n")
    code.append("DIGIT q_11[" + str(k.qsize) +"];\n")
    code.append("\n")
    code.append("DIGIT f_sum[" + str(k.fgsumSize) + "];\n")
    code.append("DIGIT g_sum[" + str(k.fgsumSize) + "];\n")
    code.append("\n")

    # TODO: adjust sizes
    code.append("DIGIT temp[" + str(k.psize) +"];\n")
    code.append("DIGIT recombine[" + str(root.num_digits_j*2) + "];\n")    # to be removed
    code.append("DIGIT temp2[" + str(k.psize) +"];\n")
    code.append("DIGIT buffer[" + str(root.num_digits_j*2) + "];\n")
    return code

def calculateLeftOperands(node):
    code = []
    code.append("\n// Calculating left operands: n:" + str(node.n) +", depth: " + str(node.depth) + "\n")
    fg_off  = node.inputOffset
    p_off = k.p_offset[node.depth+1]

    if(node.operandSource == "fgsum"):
        # f_sum
        code.append(scalarprod(node.num_digits_n + node.num_digits_j, "temp2", node.num_digits_j, "p_00+" + str(p_off), "p_01+" + str(p_off), node.num_digits_n, "f_sum+" + str(fg_off), "g_sum+" + str(fg_off)))
        #code.append("print_pol(temp2, \"f_sum\", " + str(node.num_digits_j+node.num_digits_n) + ");\n")
        code.append(digit_shift(node.num_digits_n+node.num_digits_j, "temp2", node.j))
        code.append(memcpy("f_sum+"+str(k.fgsum_offset[node.depth]), "temp2+" + str(node.num_digits_n + node.num_digits_j - node.num_digits_nminusj), node.num_digits_n))
        
        # g_sum
        code.append(scalarprod(node.num_digits_n + node.num_digits_j, "temp2", node.num_digits_j, "p_10+" + str(p_off), "p_11+" + str(p_off), node.num_digits_n, "f_sum+" + str(fg_off), "g_sum+" + str(fg_off)))
        #code.append("print_pol(temp2, \"g_sum\", " + str(node.num_digits_j+node.num_digits_n) + ");\n")
        code.append(digit_shift(node.num_digits_n+node.num_digits_j, "temp2", node.j))
        code.append(memcpy("g_sum+"+str(k.fgsum_offset[node.depth]), "temp2+" + str(node.num_digits_n + node.num_digits_j - node.num_digits_nminusj), node.num_digits_n))
    else:       # using f and g to calculate f_sum and g_sum        
        # f_sum
        code.append(scalarprod(node.num_digits_n + node.num_digits_j, "temp2", node.num_digits_j, "p_00+" + str(p_off), "p_01+" + str(p_off), node.num_digits_n, "f+" + str(fg_off), "g+" + str(fg_off)))
        #code.append("print_pol(temp2, \"f_sum\", " + str(node.num_digits_j+node.num_digits_n) + ");\n")
        code.append(digit_shift(node.num_digits_n+node.num_digits_j, "temp2", node.j))
        code.append(memcpy("f_sum+"+str(k.fgsum_offset[node.depth]), "temp2+" + str(node.num_digits_n + node.num_digits_j - node.num_digits_nminusj), node.num_digits_n))
        
        # g_sum
        code.append(scalarprod(node.num_digits_n + node.num_digits_j, "temp2", node.num_digits_j, "p_10+" + str(p_off), "p_11+" + str(p_off), node.num_digits_n, "f+" + str(fg_off), "g+" + str(fg_off)))
        #code.append("print_pol(temp2, \"g_sum\", " + str(node.num_digits_j+node.num_digits_n) + ");\n")
        code.append(digit_shift(node.num_digits_n+node.num_digits_j, "temp2", node.j))
        code.append(memcpy("g_sum+"+str(k.fgsum_offset[node.depth]), "temp2+" + str(node.num_digits_n + node.num_digits_j - node.num_digits_nminusj), node.num_digits_n))

    return code

def recombine(node):
    # Recombining the final result

    if(node.parent == None):    # final recombine, results are stored in the t_xy arrays 
        resDest = "t"
        resOff = 0
    elif(node == node.parent.right):    # the node is a right child, storing the results in p_xy
        resDest = "p"
        resOff = k.p_offset[node.depth]
    else:   # left child, storing results in q_xy
        resDest = "q"
        resOff = k.q_offset[node.depth]

    # operands sources
    p_off = k.p_offset[node.depth+1]
    q_off = k.q_offset[node.depth+1]

    code = []
    code.append("\n// Recombining results: n:" + str(node.n) +", depth: " + str(node.depth) + "num digits n, num digits j:" + str(node.num_digits_n) +" " + str(node.num_digits_j) + " " + str(node.num_digits_nminusj) + "\n")
    
    code.append(scalarprod(node.num_digits_nminusj + node.num_digits_j, "recombine", node.num_digits_j, "p_00+" + str(p_off), "p_10+" + str(p_off), node.num_digits_nminusj, "q_00+" + str(q_off), "q_01+" + str(q_off)))
    code.append(memcpy(resDest + "_00+" + str(resOff), "recombine+" + str(node.num_digits_nminusj+node.num_digits_j-node.num_digits_n), node.num_digits_n))
    #code.append("print_pol(" + resDest + "_00+" + str(resOff) + ", \"t00\", " + str(node.num_digits_n) +");\n"))
    
    code.append(scalarprod(node.num_digits_nminusj + node.num_digits_j,"recombine", node.num_digits_j, "p_01+" + str(p_off), "p_11+" + str(p_off), node.num_digits_nminusj, "q_00+" + str(q_off), "q_01+" + str(q_off)))
    code.append(memcpy(resDest + "_01+" + str(resOff), "recombine+" + str(node.num_digits_nminusj+node.num_digits_j-node.num_digits_n), node.num_digits_n) )
    #code.append("print_pol(" + resDest + "_01+" + str(resOff) + ", \"t01\", " + str(node.num_digits_n) +");\n")
    
    code.append(scalarprod(node.num_digits_nminusj + node.num_digits_j, "recombine", node.num_digits_j, "p_00+" + str(p_off), "p_10+" + str(p_off), node.num_digits_nminusj, "q_10+" + str(q_off), "q_11+" + str(q_off)))
    code.append(memcpy(resDest + "_10+" + str(resOff), "recombine+" + str(node.num_digits_nminusj+node.num_digits_j-node.num_digits_n), node.num_digits_n))
    #code.append("print_pol(" + resDest + "_10+" + str(resOff) + ", \"t10\", " + str(node.num_digits_n) +");\n")
    
    code.append(scalarprod(node.num_digits_nminusj + node.num_digits_j, "recombine", node.num_digits_j, "p_01+" + str(p_off), "p_11+" + str(p_off), node.num_digits_nminusj, "q_10+" + str(q_off), "q_11+" + str(q_off)))
    code.append(memcpy(resDest + "_11+" + str(resOff), "recombine+" + str(node.num_digits_nminusj+node.num_digits_j-node.num_digits_n), node.num_digits_n))
    #code.append("print_pol(" + resDest + "_11+" + str(resOff) + ", \"t11\", " + str(node.num_digits_n) +");\n")
    
    return code



########## GF2X OPERATIONS ##########

# Writes the code for the scalar product between two couples of arrays,
# eventually using a buffer to have same length operands and guarantee
#a costant time execution
def scalarprod(nr, res, na, a0, a1, nb, b0, b1):
    code = []
    #code.append("print_pol(" + a0 +", \"a0\", " + str(na) + ");\n")
    #code.append("print_pol(" + a1 +", \"a1\", " + str(na) + ");\n")
    #code.append("print_pol(" + b0 +", \"b0\", " + str(nb) + ");\n")
    #code.append("print_pol(" + b1 +", \"b1\", " + str(nb) + ");\n")

    if(na == nb):
        code.append(GF2X_MUL(nr, res, na, a0, nb, b0))
        code.append(GF2X_MUL(nr, "temp", na, a1, nb, b1))
        code.append(GF2X_ADD(nr, res, "temp", res))
    elif(na > nb):
        code.append(memset(na-nb))
        code.append(memcpy("buffer+" + str(na-nb),  b0, nb))
        code.append(GF2X_MUL(na*2, res, na, a0, na, "buffer"))
        code.append(memcpy("buffer+" + str(na-nb),  b1, nb))
        code.append(GF2X_MUL(na*2, "temp", na, a1, na, "buffer"))
        code.append(GF2X_ADD(na*2, "temp", res, "temp"))
        code.append(memcpy(res, "temp+" + str(na-nb), nr))
    else:
        code.append(memset(nb-na))
        code.append(memcpy("buffer+" + str(nb-na),  a0, na))
        code.append(GF2X_MUL(nb*2, res, nb, "buffer", nb, b0))
        code.append(memcpy("buffer+" + str(nb-na),  a1, na))
        code.append(GF2X_MUL(nb*2, "temp", nb, "buffer", nb, b1))
        code.append(GF2X_ADD(nb*2, "temp", res, "temp"))
        code.append(memcpy(res, "temp+" + str(nb-na), nr))
    
    return code

# Generates the code for a base multiplication
def GF2X_MUL(nr, res, na, a, nb, b):
    return "GF2X_MUL(" + str(nr) + ", " + res + ", " + str(na) + ", " + a + ", " + str(nb) + ", " + b + ");\n"

# Generates the code for a base addition
def GF2X_ADD(size, res, a0, a1):
    return "gf2x_add(" + str(size) + ", " + res + ", " + str(size) + ", " + a0 + ", " + str(size) + ", " + a1 + ");\n"

# Generates the code to set the buffer initial values to zero
def memset(size):
    return "memset(buffer, 0x00, " + str(size) +"*DIGIT_SIZE_B);\n"

# Generates the code to copy len DIGITs of src to dest
def memcpy(dest, src, len):
    return "memcpy(" + dest + ", " + src + ", " + str(len) + "*DIGIT_SIZE_B);\n"

# Generates the code to perform a right shift; the function called is an inline,
# no need to "decompose" it into its parts
def digit_shift(len, input, amount):
    return "right_bit_shift_wide_n(" + str(len) + ", " + input + ", " + str(amount) + ");\n"



########## DIVSTEP FUNCTIONS ##########

# Generates the code for the divstep calls
def divstep(node, resDest, f, g, out_off):
    code = []
    code.append("\n")
    if(node.n < 192):
        code.append(support_jumpdivstep(node, resDest, f, g, out_off))
    else:
        code.append(divstepsx_256(node, resDest, f, g, out_off))
    return code

# Divstep for n < 256
def divstepsx_256(node, resDest, f, g, out_off):
    if(node.n < 128):
        return divstepsx_128(node, resDest, f, g, out_off)
    else:
        code = ""
        code += "delta = divstepsx_256(" + str(node.n) + ", delta, " + f +", " + g + ", "
        code += resDest + "_00+" + str(out_off) + ", "
        code += resDest + "_01+" + str(out_off) + ", "
        code += resDest + "_10+" + str(out_off) + ", "
        code += resDest + "_11+" + str(out_off) + ");\n"
        return code

# Divstep for n < 192
def support_jumpdivstep(node, resDest, f, g, out_off):
    if (node.n < 128):
        return divstepsx_128(node, resDest, f, g, out_off)
    else:
        code = ""
        code += "delta = support_jumpdivstep(" + str(node.n) + ", delta, " + f +", " + g + ", "
        code += resDest + "_00+" + str(out_off) + ", "
        code += resDest + "_01+" + str(out_off) + ", "
        code += resDest + "_10+" + str(out_off) + ", "
        code += resDest + "_11+" + str(out_off) + ", x);\n"
        return code

# Divstep for n < 128
def divstepsx_128(node, resDest, f, g, out_off):
    if(node.n < 64):
        return divstepsx(node, resDest, f, g, out_off)
    else:
        code = ""
        code += "delta = divstepsx_128(" + str(node.n) + ", delta, " + f +", " + g + ", "
        code += resDest + "_00+" + str(out_off) + ", "
        code += resDest + "_01+" + str(out_off) + ", "
        code += resDest + "_10+" + str(out_off) + ", "
        code += resDest + "_11+" + str(out_off) + ");\n"
        return  code

# DIvstep for n < 64
def divstepsx(node, resDest, f, g, out_off):
    code = ""
    code += "delta = divstepsx(" + str(node.n) + ", delta, " + f +", " + g + ", "
    code += resDest + "_00+" + str(out_off) + ", "
    code += resDest + "_01+" + str(out_off) + ", "
    code += resDest + "_10+" + str(out_off) + ", "
    code += resDest + "_11+" + str(out_off) + ");\n"
    return code