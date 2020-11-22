import treeUtils as tree
import constants as k

# Assembles the declaration part and the "execution" part
def assemble(root, p):
    code = []
    output = ""
    code.append("/**")
    code.append("  * Software Artifact of the paper A Comprehensive Analysis of Constant-time")
    code.append("  * Polynomial Inversion for Post-quantum Cryptosystems")
    code.append("  *")
    code.append("  * @author Domenico Cacace <domenico.cacace@mail.polimi.it>")
    code.append("  * ")
    code.append("  * This code has been automatically generated")
    code.append("  *")
    code.append("  * This code is hereby placed in the public domain.")
    code.append("  *")
    code.append("  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ''AS IS'' AND ANY EXPRESS")
    code.append("  * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED")
    code.append("  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE")
    code.append("  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE")
    code.append("  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR")
    code.append("  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF")
    code.append("  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR")
    code.append("  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,")
    code.append("  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE")
    code.append("  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,")
    code.append("  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.")
    code.append("  *")
    code.append("  **/")

    for line in code:
        output+= str(line) + "\n"
    output+="\n"
    code.clear()

    code.extend(init(root))
    code.append("\n")
    code.extend(unrollTree(root))
    code.append("return delta;")

    output+="#include \"../../include/inverse_DJB_facilities.h\"\n\n"
    output+="int jumpdivstep_" + str(p) + "(int n, int delta, int nf, DIGIT *f, DIGIT *g, DIGIT *t_00, DIGIT *t_01, DIGIT *t_10, DIGIT *t_11, float x) {\n"
    for line in code:
        if(not k.debug):
            if line.startswith("print_pol"):
                continue
        output+="\t" + str(line) + "\n"
    output+="}"

    return output

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
                code.extend(divstep(node, "p", f, g, k.p_offset[node.depth-1]))
            else:
                code.extend(divstep(node, "q", f, g, k.q_offset[node.depth-1]))
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
    code.append("DIGIT p_00[" + str(k.psize) +"];")
    code.append("DIGIT p_01[" + str(k.psize) +"];")
    code.append("DIGIT p_10[" + str(k.psize) +"];")
    code.append("DIGIT p_11[" + str(k.psize) +"];")
    code.append("")
    code.append("DIGIT q_00[" + str(k.qsize) +"];")
    code.append("DIGIT q_01[" + str(k.qsize) +"];")
    code.append("DIGIT q_10[" + str(k.qsize) +"];")
    code.append("DIGIT q_11[" + str(k.qsize) +"];")
    code.append("")
    code.append("DIGIT f_sum[" + str(k.fgsumSize) + "];")
    code.append("DIGIT g_sum[" + str(k.fgsumSize) + "];")
    code.append("")

    # TODO: adjust sizes
    code.append("DIGIT temp[" + str(root.num_digits_n*2 + root.num_digits_j - root.num_digits_nminusj) +"];")
    code.append("DIGIT recombine[" + str(root.num_digits_n*2 + root.num_digits_j - root.num_digits_nminusj) + "];")    # to be removed
    code.append("DIGIT temp2[" + str(root.num_digits_n*2 + root.num_digits_j - root.num_digits_nminusj) +"];")
    return code

def calculateLeftOperands(node):
    code = []
    code.append("// Calculating left operands: n: " + str(node.n) +", depth: " + str(node.depth))
    fg_off  = node.inputOffset
    p_off = k.p_offset[node.depth]

    if(node.operandSource == "fgsum"):
        # f_sum
        code.extend(scalarprod(node.num_digits_n + node.num_digits_j, "recombine", node.num_digits_j, "p_00+" + str(p_off), "p_01+" + str(p_off), node.num_digits_n, "f_sum+" + str(fg_off), "g_sum+" + str(fg_off)))
        code.append(print_pol("recombine", "f_sum", node.num_digits_j+node.num_digits_n))
        code.append(digit_shift(node.num_digits_n+node.num_digits_j, "recombine", node.j))
        code.append(memcpy("f_sum+"+str(k.fgsum_offset[node.depth]), "recombine+" + str(node.num_digits_n + node.num_digits_j - node.num_digits_nminusj), node.num_digits_n))
        
        # g_sum
        code.extend(scalarprod(node.num_digits_n + node.num_digits_j, "recombine", node.num_digits_j, "p_10+" + str(p_off), "p_11+" + str(p_off), node.num_digits_n, "f_sum+" + str(fg_off), "g_sum+" + str(fg_off)))
        code.append(print_pol("recombine", "g_sum", node.num_digits_j+node.num_digits_n))
        code.append(digit_shift(node.num_digits_n+node.num_digits_j, "recombine", node.j))
        code.append(memcpy("g_sum+"+str(k.fgsum_offset[node.depth]), "recombine+" + str(node.num_digits_n + node.num_digits_j - node.num_digits_nminusj), node.num_digits_n))
    else:       # using f and g to calculate f_sum and g_sum        
        # f_sum
        code.extend(scalarprod(node.num_digits_n + node.num_digits_j, "recombine", node.num_digits_j, "p_00+" + str(p_off), "p_01+" + str(p_off), node.num_digits_n, "f+" + str(fg_off), "g+" + str(fg_off)))
        code.append(print_pol("recombine", "f_sum", node.num_digits_j+node.num_digits_n))
        code.append(digit_shift(node.num_digits_n+node.num_digits_j, "recombine", node.j))
        code.append(memcpy("f_sum+"+str(k.fgsum_offset[node.depth]), "recombine+" + str(node.num_digits_n + node.num_digits_j - node.num_digits_nminusj), node.num_digits_n))
        
        # g_sum
        code.extend(scalarprod(node.num_digits_n + node.num_digits_j, "recombine", node.num_digits_j, "p_10+" + str(p_off), "p_11+" + str(p_off), node.num_digits_n, "f+" + str(fg_off), "g+" + str(fg_off)))
        code.append(print_pol("recombine", "g_sum", node.num_digits_j+node.num_digits_n))
        code.append(digit_shift(node.num_digits_n+node.num_digits_j, "recombine", node.j))
        code.append(memcpy("g_sum+"+str(k.fgsum_offset[node.depth]), "recombine+" + str(node.num_digits_n + node.num_digits_j - node.num_digits_nminusj), node.num_digits_n))
    code.append("\n")
    return code

def recombine(node):
    # Recombining the final result

    if(node.parent == None):    # final recombine, results are stored in the t_xy arrays 
        resDest = "t"
        resOff = 0
    elif(node == node.parent.right):    # the node is a right child, storing the results in p_xy
        resDest = "p"
        resOff = k.p_offset[node.depth-1]
    else:   # left child, storing results in q_xy
        resDest = "q"
        resOff = k.q_offset[node.depth-1]

    # operands sources
    p_off = k.p_offset[node.depth]
    q_off = k.q_offset[node.depth]

    code = []
    code.append("// Recombining results: n: " + str(node.n) +", depth: " + str(node.depth))
    if (node.num_digits_nminusj+node.num_digits_j-node.num_digits_n == 0):
        code.extend(scalarprod(node.num_digits_nminusj + node.num_digits_j, resDest + "_00+" + str(resOff), node.num_digits_j, "p_00+" + str(p_off), "p_10+" + str(p_off), node.num_digits_nminusj, "q_00+" + str(q_off), "q_01+" + str(q_off)))
        
        code.extend(scalarprod(node.num_digits_nminusj + node.num_digits_j, resDest + "_01+" + str(resOff), node.num_digits_j, "p_01+" + str(p_off), "p_11+" + str(p_off), node.num_digits_nminusj, "q_00+" + str(q_off), "q_01+" + str(q_off)))
        
        code.extend(scalarprod(node.num_digits_nminusj + node.num_digits_j, resDest + "_10+" + str(resOff), node.num_digits_j, "p_00+" + str(p_off), "p_10+" + str(p_off), node.num_digits_nminusj, "q_10+" + str(q_off), "q_11+" + str(q_off)))
        
        code.extend(scalarprod(node.num_digits_nminusj + node.num_digits_j, resDest + "_11+" + str(resOff), node.num_digits_j, "p_01+" + str(p_off), "p_11+" + str(p_off), node.num_digits_nminusj, "q_10+" + str(q_off), "q_11+" + str(q_off)))
    else:
        code.extend(scalarprod(node.num_digits_nminusj + node.num_digits_j, "recombine", node.num_digits_j, "p_00+" + str(p_off), "p_10+" + str(p_off), node.num_digits_nminusj, "q_00+" + str(q_off), "q_01+" + str(q_off)))
        code.append(memcpy(resDest + "_00+" + str(resOff), "recombine+" + str(node.num_digits_nminusj+node.num_digits_j-node.num_digits_n), node.num_digits_n))
        
        code.extend(scalarprod(node.num_digits_nminusj + node.num_digits_j,"recombine", node.num_digits_j, "p_01+" + str(p_off), "p_11+" + str(p_off), node.num_digits_nminusj, "q_00+" + str(q_off), "q_01+" + str(q_off)))
        code.append(memcpy(resDest + "_01+" + str(resOff), "recombine+" + str(node.num_digits_nminusj+node.num_digits_j-node.num_digits_n), node.num_digits_n) )
        
        code.extend(scalarprod(node.num_digits_nminusj + node.num_digits_j, "recombine", node.num_digits_j, "p_00+" + str(p_off), "p_10+" + str(p_off), node.num_digits_nminusj, "q_10+" + str(q_off), "q_11+" + str(q_off)))
        code.append(memcpy(resDest + "_10+" + str(resOff), "recombine+" + str(node.num_digits_nminusj+node.num_digits_j-node.num_digits_n), node.num_digits_n))
        
        code.extend(scalarprod(node.num_digits_nminusj + node.num_digits_j, "recombine", node.num_digits_j, "p_01+" + str(p_off), "p_11+" + str(p_off), node.num_digits_nminusj, "q_10+" + str(q_off), "q_11+" + str(q_off)))
        code.append(memcpy(resDest + "_11+" + str(resOff), "recombine+" + str(node.num_digits_nminusj+node.num_digits_j-node.num_digits_n), node.num_digits_n))

    code.append(print_pol(resDest+"_00+"+str(resOff), "t00", node.num_digits_n))
    code.append(print_pol(resDest+"_01+"+str(resOff), "t01", node.num_digits_n))
    code.append(print_pol(resDest+"_10+"+str(resOff), "t10", node.num_digits_n))
    code.append(print_pol(resDest+"_11+"+str(resOff), "t11", node.num_digits_n))



    
    code.append("\n")
    return code



########## GF2X OPERATIONS ##########

# Writes the code for the scalar product between two couples of arrays,
# splitting the multiplication in smaller operations if the operands are asymmetrical
def scalarprod(nr, res, na, a0, a1, nb, b0, b1):
    code = []
    #code.append("print_pol(" + a0 +", \"a0\", " + str(na) + ");")
    #code.append("print_pol(" + a1 +", \"a1\", " + str(na) + ");")
    #code.append("print_pol(" + b0 +", \"b0\", " + str(nb) + ");")
    #code.append("print_pol(" + b1 +", \"b1\", " + str(nb) + ");")
   
    if(na > nb):        
        if (nr - 2*nb > 0):
            code.append(memset(res, nr-2*nb))
        code.append(GF2X_MUL(2*nb, "temp", nb, a0+"+"+str(na-nb), nb, b0))
        code.append(GF2X_MUL(2*nb, "temp2", nb, a1+"+"+str(na-nb), nb, b1))
        code.append(GF2X_ADD(2*nb, res+"+"+str(nr-2*nb), "temp", "temp2"))
        na-=nb
        nr-=nb
    else:
        if (nr - 2*na > 0):
            code.append(memset(res, nr-2*na))
        code.append(GF2X_MUL(2*na, "temp", na, b0+"+"+str(nb-na), na, a0))
        code.append(GF2X_MUL(2*na, "temp2", na, b1+"+"+str(nb-na), na, a1))
        code.append(GF2X_ADD(2*na, res+"+"+str(nr-2*na), "temp", "temp2"))
        nb-=na
        nr-=na
        
    
    while (na > 0 and nb > 0):
        if(na > nb):
            code.append(GF2X_MUL(2*nb, "temp", nb, a0+"+"+str(na-nb), nb, b0))
            code.append(GF2X_MUL(2*nb, "temp2", nb, a1+"+"+str(na-nb), nb, b1))
            code.append(GF2X_ADD(2*nb, "temp", "temp", "temp2"))
            code.append(GF2X_ADD(2*nb, res+"+"+str(nr-2*nb), res+"+"+str(nr-2*nb), "temp"))
            na-=nb
            nr-=nb
        else:
            code.append(GF2X_MUL(2*na, "temp", na, b0+"+"+str(nb-na), na, a0))
            code.append(GF2X_MUL(2*na, "temp2", na, b1+"+"+str(nb-na), na, a1))
            code.append(GF2X_ADD(2*na, "temp", "temp", "temp2"))
            code.append(GF2X_ADD(2*na, res+"+"+str(nr-2*na), res+"+"+str(nr-2*na), "temp"))
            nb-=na
            nr-=na

    return code

# Generates the code for a base multiplication
def GF2X_MUL(nr, res, na, a, nb, b):
    return "GF2X_MUL(" + str(nr) + ", " + res + ", " + str(na) + ", " + a + ", " + str(nb) + ", " + b + ");"

# Generates the code for a base addition
def GF2X_ADD(size, res, a0, a1):
    return "gf2x_add(" + str(size) + ", " + res + ", " + str(size) + ", " + a0 + ", " + str(size) + ", " + a1 + ");"

# Generates the code to set the buffer initial values to zero
def memset(target, size):
    return "memset("+target+", 0x00, " + str(size) +"*DIGIT_SIZE_B);"

# Generates the code to copy len DIGITs of src to dest
def memcpy(dest, src, len):
    return "memcpy(" + dest + ", " + src + ", " + str(len) + "*DIGIT_SIZE_B);"

# Generates the code to perform a right shift; the function called is an inline,
# no need to "decompose" it into its parts
def digit_shift(len, input, amount):
    return "right_bit_shift_wide_n(" + str(len) + ", " + input + ", " + str(amount) + ");"

# Prints out the polynomial, split in DIGITs and in hexadecimal format
def print_pol(poly, label, size):
    return "print_pol(" + poly +", \"" + label +"\", " + str(size) +");"


########## DIVSTEP FUNCTIONS ##########

# Generates the code for the divstep calls
def divstep(node, resDest, f, g, out_off):
    code = []
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
        code += "delta = support_jumpdivstep(" + str(node.n) + ", delta, " + str(node.num_digits_n) + ", " + f +", " + g + ", "
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
    code += "delta = divstepsx(" + str(node.n) + ", delta, *(" + f +"), *(" + g + "), "
    code += resDest + "_00+" + str(out_off) + ", "
    code += resDest + "_01+" + str(out_off) + ", "
    code += resDest + "_10+" + str(out_off) + ", "
    code += resDest + "_11+" + str(out_off) + ");\n"
    return code