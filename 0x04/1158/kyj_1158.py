import sys
input = sys.stdin.readline
class Node:
    def __init__(self, data):
        self.left = None
        self.data = data
        self.right = None

def prt(node):
    while node is not None:
        print(node.data,end="")
        node = node.right

n, k = map(int,input().split())
head = node = Node(1)
for i in range(2, n+1):
    new = Node(i)
    node.right = new
    new.left = node

    node = node.right


node.right = head
head.left = node
node = head
print("<",end="")

for i in range(n):
    for j in range(k-1):
        node = node.right
    if i != n-1:
        print(node.data,end=", ")
    else:
        print(node.data, end=">")
    node.left.right = node.right
    node.right.left = node.left

    node = node.right
