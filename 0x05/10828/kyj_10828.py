import sys
input = sys.stdin.readline
n = int(input())
li = []
for _ in range(n):
    cmd = input().rstrip().split()

    if cmd[0] == "push":
        li.append(cmd[1])
        
    elif cmd[0] == "pop":
        if len(li) > 0:
            print(li.pop())
        else:
            print("-1")

    elif cmd[0] == "size":
        print(len(li))

    elif cmd[0] == "empty":
        if len(li) == 0:
            print("1")
        else:
            print("0")
    else:
        if len(li) == 0:
            print("-1")
        else:
            print(li[-1])


