import os
import math
import treeUtils as tree

DIGIT_SIZE_B = 8
DIGIT_SIZE_b = DIGIT_SIZE_B << 3
WS = 256


def generate(p):
    n = 2*p-1
    j = math.floor(n/2)
    j = math.floor((j+WS-2)/(WS-1))
    j = math.floor(j*(WS-1))
    num_digits_n = math.floor(n/DIGIT_SIZE_b) + 1
    num_digits_j = math.floor(j/DIGIT_SIZE_b) + 1

    root = tree.Node(n, j, num_digits_n, num_digits_j)
    tree.buildTree(root, DIGIT_SIZE_b, WS)

    tree.printTree(root)


    #while root.left != None:



    return str(p*2-1)

def main():
    primes = [7187] # needs to be expanded
    
    for prime in primes:
        code = generate(prime)
        #f = open("generated_part/" + str(prime) + ".part", "w")
        #f.write(code)
        #f.close()

if __name__ == "__main__":
    main()
    