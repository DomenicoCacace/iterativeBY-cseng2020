import os
import math
import treeUtils as tree

# Constants; the current values apply for for machines allowing all the
# possible optimizations in terms of AVX operations (computing 4 DIGITs
# in parallel)
DIGIT_SIZE_B = 8
DIGIT_SIZE_b = DIGIT_SIZE_B << 3
WS = 256

# Starting from the prime number to treat reconstructs the recursive
# calls tree, using the buildTree function
def generateTree(p):
    n = 2*p-1

    root = tree.Node(n, None, DIGIT_SIZE_b, WS)
    tree.buildTree(root, DIGIT_SIZE_b, WS)

    return root

# Calculates the amount of memory to be allocated to store all the P and
# Q matrices during the execution
def calculatePQsize(root):

    size = root.num_digits_n + root.num_digits_j

    return size, size

    # if (root != None):
    #     pr, qr = calculatePQsize(root.right)
    #     pl, ql = calculatePQsize(root.left)
    #     if (root.left != None or root.right != None):   # analyzing an intermediate node
    #         p = pr + pl + root.num_digits_j
    #         q = qr + ql + root.num_digits_nminusj
    #     else:   # leaf nodes do not contribute to the p and q sizes
    #         p = pr + pl
    #         q = qr + ql
    #     return p, q
    # else:
    #     return 0, 0
    

# tbd
def generateSrc(p):
    
    depth = math.floor(math.log2((2*p-1)/WS)) + 1
    recTree = generateTree(p)
    tree.printTree(recTree)
    psize, qsize = calculatePQsize(recTree)

    # only one couple of fsum and gsum polynomials at any time, same for temp
    # using the biggest size for obvious reasons
    fsumSize = recTree.num_digits_n + recTree.num_digits_j
    tempSize = recTree.num_digits_j + recTree.num_digits_nminusj 
    
    #while root.left != None:



    return str(p*2-1)

def main():
    primes = [7187]
    #primes = [7187, 8237, 10853, 13109, 13397, 15331, 16067, 16229, 19709, 20981, 21611, 22901, 23371, 25579, 28277, 28411, 30803, 35117, 35507, 36629, 40787, 42677, 48371, 52667, 58171, 61717, 83579] 
    
    for prime in primes:
        code = generateSrc(prime)
        #f = open("generated_part/" + str(prime) + ".part", "w")
        #f.write(code)
        #f.close()

if __name__ == "__main__":
    main()
    