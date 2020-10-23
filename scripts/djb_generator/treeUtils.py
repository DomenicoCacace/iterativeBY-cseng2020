import math

class Node(object):
    def __init__(self, n, j, num_digits_n, num_digits_j):
        self.n = n
        self.j = j
        self.num_digits_n = num_digits_n
        self.num_digits_j = num_digits_j
        self.visits = 0
        self.right = None
        self.left = None


def buildTree(parent, digit_size, ws):
    if (parent.n >= ws):
        n = parent.j
        j = math.floor(n/2)
        j = math.floor((j+ws-2)/(ws-1))
        j = math.floor(j*(ws-1))
        num_digits_n = math.floor(n/digit_size) + 1
        num_digits_j = math.floor(j/digit_size) + 1

        parent.right = Node(n, j, num_digits_n, num_digits_j)
        buildTree(parent.right, digit_size, ws)

        n = parent.n - parent.j
        j = math.floor(n/2)
        j = math.floor((j+ws-2)/(ws-1))
        j = math.floor(j*(ws-1))
        num_digits_n = math.floor(n/digit_size) + 1
        num_digits_j = math.floor(j/digit_size) + 1

        parent.left = Node(n, j, num_digits_n, num_digits_j)
        buildTree(parent.left, digit_size, ws)

    else:
        return None

def printTree(root):
    if (root != None):
        printTree(root.right)
        print(root.num_digits_n)
        printTree(root.left)
    return

def dfs(root):
    return root
    