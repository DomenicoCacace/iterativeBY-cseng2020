import math

# Contains the fundamental information needed for each recursive step
class Node(object):
    def __init__(self, n, digit_size, ws):
        self.n = n
        self.j = math.floor(n/2)
        self.j = math.floor((self.j+ws-2)/(ws-1))
        self.j = math.floor(self.j*(ws-1))
        self.nminusj = n - self.j

        self.num_digits_n = math.floor(n/digit_size)+1
        self.num_digits_j = math.floor(self.j/digit_size)+1
        self.num_digits_nminusj = math.floor(self.nminusj/digit_size)+1

        self.right = None
        self.left = None

# Recursively determines the core parameters used in the various recursive
# calls, building a sort of recursion tree to be later analyzed
def buildTree(parent, digit_size, ws):
    if (parent.n >= ws):
        parent.right = Node(parent.j, digit_size, ws)
        buildTree(parent.right, digit_size, ws)

        parent.left = Node(parent.nminusj, digit_size, ws)
        buildTree(parent.left, digit_size, ws)
    return None

def printTree(root):
    if (root != None):
        printTree(root.right)
        print(root.num_digits_j)
        printTree(root.left)
    return

def dfs(root):
    return root
    