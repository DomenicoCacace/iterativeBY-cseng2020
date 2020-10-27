import os
import math
import treeUtils as tree
import codeBuilder as cb


# Constants; the current values apply for for machines allowing all the
# possible optimizations in terms of AVX instructions (computing 4 DIGITs
# in parallel)
DIGIT_SIZE_B = 8
DIGIT_SIZE_b = DIGIT_SIZE_B << 3
WS = 256


# Starting from the prime number to treat reconstructs the recursive
# calls tree, using the buildTree function
# returns the tree root and its depth (the root is not included in the count)
def generateTree(p):
    n = 2*p-1

    root = tree.Node(n, None, DIGIT_SIZE_b, WS)
    tree.buildTree(root, DIGIT_SIZE_b, WS)

    return root, math.floor(math.log2(n/WS)) + 1


# Calculates the offsets for f and g for the rightmost branch of the tree,
# changing the operandSource attribute of those nodes
def calculateFGoffsets(node):
    off = []
    sum = 0
    while (node != None):
        off.append(sum)
        sum+=(node.num_digits_n - node.num_digits_j)
        node.operandSource = "input"
        node = node.right

    return off
    

# Calculates the amount of memory to be allocated to store all the P and
# Q matrices during the execution and the offsets to access the right portion
# of the matrices for each level of the tree
def calculatePQsize(node):
    ptree = node.right
    qtree = node.left

    psize = 0
    p_offset = []
    while(ptree != None):
        p_offset.append(psize)
        psize+=ptree.num_digits_n
        ptree = ptree.right

    qsize = 0
    q_offset = []
    while(qtree != None):
        q_offset.append(qsize)
        qsize+=qtree.num_digits_n
        qtree = qtree.right

    return psize, qsize, p_offset, q_offset

# Calculates the amount of memory to be allocated to store all the f_sum and
# g_sum arrays during the execution and the offsets to access the right portion
# of the arrays for each level of the tree
def calculateFGsumSize(node):
    size = 0
    sumOffset = []

    while(node.left != None):
        sumOffset.append(size)
        size+=node.left.num_digits_n+node.left.num_digits_j
        node = node.right
    
    return size, sumOffset


# Calculates all the parameters specific for the given prime p and invokes a method
# to build the code relative to it
def generateSrc(p):
    
    root, depth = generateTree(p)

    # P and Q sizes and access offsets (based on the node depth)
    pSize, qSize, p_off, q_off = calculatePQsize(root)

    print(p_off, pSize)
    print(q_off, qSize)

    fg_off = calculateFGoffsets(root)
    print(fg_off)

    # using a single array for the f_sum and g_sum polynomials, which
    # is split in subarrays like the input polynomials f and g
    fgsumSize, fgsum_off = calculateFGsumSize(root)


    return cb.assemble(root, pSize, qSize, p_off, q_off, fg_off, fgsumSize, fgsum_off)



# Builds the source code for each prime and writes it to single files, then assembles the files
# into a final one 
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
    