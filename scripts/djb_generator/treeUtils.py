import math
from enum import Enum

# Contains the fundamental information needed for each recursive step
class Node(object):
    def __init__(self, n, parent, digit_size, ws):
        self.n = n
        self.j = math.floor(n/2)
        self.j = math.floor((self.j+ws-2)/(ws-1))
        self.j = math.floor(self.j*(ws-1))
        self.nminusj = n - self.j

        self.num_digits_n = math.floor(n/digit_size)+1
        self.num_digits_j = math.floor(self.j/digit_size)+1
        self.num_digits_nminusj = math.floor(self.nminusj/digit_size)+1

        self.parent = parent
        self.right = None
        self.left = None
        self.operandSource = "fgsum"

        if (parent == None):
            self.depth = 0
        else:
            self.depth = parent.depth + 1

# Recursively determines the core parameters used in the various recursive
# calls, building a sort of recursion tree to be later analyzed
def buildTree(parent, digit_size, ws):
    if (parent.n >= ws):
        parent.right = Node(parent.j, parent, digit_size, ws)
        buildTree(parent.right, digit_size, ws)

        parent.left = Node(parent.nminusj, parent, digit_size, ws)
        buildTree(parent.left, digit_size, ws)

    return None

# Determines if a node is a leaf, requiring to "run" the divstep function
def isLeaf(node):
    return (node.left == None and node.right == None)

