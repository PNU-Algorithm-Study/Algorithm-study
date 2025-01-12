# 18258
import sys
input = sys.stdin.readline

n = int(input())
que = []
p = 0
for _ in range(n):
    s = input().rstrip().split()
    word = s[0]

    if (word == "push"):
        que.append(s[1])

    elif (word == "pop"):
        if (len(que) - p > 0):
            print(que[p])
            p += 1
        else:
            print(-1)

    elif (word == "size"):
        print(len(que) - p)

    elif (word == "empty"):
        if (len(que) - p > 0):
            print(0)
        else:
            print(1)

    elif (word == "front"):
        if (len(que) - p > 0):
            print(que[p])
        else:
            print(-1)

    elif (word == "back"):
        if (len(que) - p > 0):
            print(que[len(que) - 1])
        else:
            print(-1)

