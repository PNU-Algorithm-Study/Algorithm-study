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
    print()

n = int(input())
for _ in range(n):
    cmd = input().rstrip()
    head = Node(0)
    node = head
    for c in cmd:
        if c == "-":
            if node == head:
                continue

            node.left.right = node.right
            if node.right is not None:
                node.right.left = node.left

            node = node.left

        elif c == "<":
            if node.left:
                node = node.left

        elif c == ">":
            if node.right:
                node = node.right

        else:
            data = c
            new = Node(data)

            new.right = node.right
            if node.right is not None:
                node.right.left = new

            node.right = new
            new.left = node

            node = new


    prt(head.right)
