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


s = input().rstrip()
head = node = Node(-1)

for c in s:
    new = Node(c)
    node.right = new
    new.left = node
    node = new

n = int(input())
for _ in range(n):
    cmd = input().rstrip()

    if cmd[0] == "P":
        data = cmd[2:]
        new = Node(data)

        new.right = node.right
        if node.right is not None:
            node.right.left = new

        node.right = new
        new.left = node

        node = new
    elif cmd[0] == "L":
        if node.left:
            node = node.left

    elif cmd[0] == "D":
        if node.right:
            node = node.right

    else:
        if node == head:
            continue

        node.left.right = node.right
        if node.right is not None:
            node.right.left = node.left

        node = node.left


prt(head.right)
