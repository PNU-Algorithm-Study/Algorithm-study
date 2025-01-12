import sys
input = sys.stdin.readline
li = []
n = int(input())
for _ in range(n):
    c = int(input())
    if c == 0:
        if len(li) != 0 :
            li.pop()

    else:
        li.append(c)

print(sum(li))