# Software Artifact of the paper Fast constant-time binary polynomial modular inversion
# for post-quantum cryptosystems
#
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


import os
import math
import treeUtils as tree
import generator as gen
import constants as k
import argparse


# Starting from the prime number to treat reconstructs the recursive
# calls tree, using the buildTree function
# returns the tree root and its depth (the root is not included in the count)
def generateTree(p):
    n = 2*p-1

    root = tree.Node(n, None, k.DIGIT_SIZE_b, k.WS)
    tree.buildTree(root, k.DIGIT_SIZE_b, k.WS)

    return root, math.floor(math.log2(n/k.WS)) + 1


# Calculates the offsets for f and g for the rightmost branch of the tree,
# changing the operandSource attribute of those nodes
def calculateFGoffsets(node):
    off = []
    sum = 0
    while (node != None):
        off.append(sum)
        sum+=(node.num_digits_n - node.num_digits_j)
        node.operandSource = "input"    # to differentiate when calculating the "left" operands
        node = node.right

    k.fg_offset = off
    

# Calculates the amount of memory to be allocated to store all the P and
# Q matrices during the execution and the offsets to access the right portion
# of the matrices for each level of the tree
def calculatePQsize(node):
    psize = 0
    qsize = 0
    p_offset = []
    q_offset = []

    while(node.left != None):
        p_offset.append(psize)
        q_offset.append(qsize)
        qsize+=node.left.num_digits_n
        psize+=node.right.num_digits_n
        
        node = node.right

        
    p_offset.append(psize)
    q_offset.append(qsize)

    k.psize = psize
    k.qsize = qsize
    k.p_offset = p_offset
    k.q_offset = q_offset


# Calculates the amount of memory to be allocated to store all the f_sum and
# g_sum arrays during the execution and the offsets to access the right portion
# of the arrays for each level of the tree
def calculateFGsumSize(node):
    size = 1
    sumOffset = []

    while(node.left != None):
        sumOffset.append(size)
        size+=node.num_digits_n+node.num_digits_j
        size+=1
        node = node.right
    
    k.fgsumSize = size
    k.fgsum_offset = sumOffset

# Determines the input operands offsets of a node based on the parent-child relation of the tree nodes
def setOperandsOffsets(node):
    if(node == None):
        return
    elif(node.parent != None):
        if(node.parent.right == node):
            node.inputOffset = node.parent.inputOffset + node.parent.num_digits_n - node.parent.num_digits_j
        else:
            node.inputOffset = k.fgsum_offset[node.depth-1]
    else:
        pass
    setOperandsOffsets(node.right)
    setOperandsOffsets(node.left)

# Calculates all the parameters specific for the given prime p and invokes a method
# to build the code relative to it
def generateSrc(p):
    
    root, depth = generateTree(p)

    # P and Q sizes and access offsets (based on the node depth)
    calculatePQsize(root)
    calculateFGoffsets(root)

    # using a single array for the f_sum and g_sum polynomials, which
    # is split in subarrays like the input polynomials f and g
    calculateFGsumSize(root)

    setOperandsOffsets(root)

    return gen.assemble(root, p)



# Builds the source code for each prime and writes it to single files, then assembles the files
# into a final one 
def main():
    dirName = os.path.dirname(__file__)

    argParser = argparse.ArgumentParser()
    argParser.add_argument("-ws", "--wordsize", help="The number of bits addressable by the CPU at once (default: 256)", default=256, type=int, dest="ws")
    argParser.add_argument("-s", "--digit-size", help="The number of bits per digit (default: 64)", default=64, type=int, dest="size")
    args = argParser.parse_args()
    
    # Setting memory word size related parameters
    k.WS = args.ws
    k.DIGIT_SIZE_b = args.size
    k.DIGIT_SIZE_B = k.DIGIT_SIZE_b >> 3
    

    # Loading the license as an array of strings
    licenseFile = os.path.join(dirName, "license.txt")
    f = open(licenseFile)
    k.swLicense = f.read().splitlines()
    f.close()

    # Loading the primes to implement in an array
    primes = []
    primesFile = os.path.join(dirName, "primes.txt")
    f = open(primesFile)
    while True:
        prime = f.readline()
        if prime:
            primes.append(int(prime))
        else:
            break
    f.close()
    
    # Generating and writing the jumpdivstep functions
    outputPath = os.path.join(dirName, "../../src/inverse/library/djb_support/")
    for prime in primes:
        k.resetConstants()
        code = generateSrc(prime)
        f = open(outputPath + "jumpdivstep_" + str(prime) + ".c", "w")
        f.write(code)
        f.close()

    # Generating the header file
    headerPath = os.path.join(dirName, "../../src/inverse/include/")
    f = open(headerPath + "inverse_DJB_specific.h", "w")
    f.writelines(map(lambda x:x+'\n', k.swLicense))
    f.write("\n")
    f.write("#include \"../../gf2x/include/gf2x_limbs.h\"\n")
    f.write("#include \"inverse_DJB_facilities.h\"\n\n\n")
    f.writelines(map(lambda x:x+'\n', k.signatures))
    f.close()


if __name__ == "__main__":
    main()
    