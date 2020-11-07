import os
import math
import treeUtils as tree
import codeBuilder as cb
import constants as k


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
        node.operandSource = "input"
        node = node.right

    k.fg_offset = off
    

# Calculates the amount of memory to be allocated to store all the P and
# Q matrices during the execution and the offsets to access the right portion
# of the matrices for each level of the tree
def calculatePQsize(node):
    ptree = node.right
    qtree = node.left

    psize = node.num_digits_n
    p_offset = []
    p_offset.append(0)
    while(ptree != None):
        p_offset.append(psize)
        psize+=ptree.num_digits_n
        ptree = ptree.right

    qsize = node.num_digits_nminusj
    q_offset = []
    q_offset.append(0)
    while(qtree != None):
        q_offset.append(qsize)
        qsize+=qtree.num_digits_n
        qtree = qtree.right
    
    k.psize = psize
    k.qsize = qsize
    k.p_offset = p_offset
    k.q_offset = q_offset


# Calculates the amount of memory to be allocated to store all the f_sum and
# g_sum arrays during the execution and the offsets to access the right portion
# of the arrays for each level of the tree
def calculateFGsumSize(node):
    size = node.num_digits_n+node.num_digits_j
    sumOffset = []
    sumOffset.append(0)
    while(node.left != None):
        sumOffset.append(size)
        size+=node.left.num_digits_n+node.left.num_digits_j
        node = node.right
    

    k.fgsumSize = size
    k.fgsum_offset = sumOffset


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


    return cb.assemble(root)



# Builds the source code for each prime and writes it to single files, then assembles the files
# into a final one 
def main():
    primes = [7187]
    #primes = [7187, 8237, 10853, 13109, 13397, 15331, 16067, 16229, 19709, 20981, 21611, 22901, 23371, 25579, 28277, 28411, 30803, 35117, 35507, 36629, 40787, 42677, 48371, 52667, 58171, 61717, 83579] 
    
    for prime in primes:
        code = generateSrc(prime)
        print(k.fg_offset)
        print(k.fgsum_offset)
        print(k.p_offset)
        print(k.q_offset)
        #f = open("generated_part/" + str(prime) + ".part", "w")
        #f.write(code)
        #f.close()

if __name__ == "__main__":
    main()
    