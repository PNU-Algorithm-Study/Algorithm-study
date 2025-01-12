n = int(input())
li = []
crnt = 1
ans = []
flag = True
for _ in range(n):
    num = int(input())
    if crnt <= num:
        for i in range(crnt, num + 1):
            li.append(crnt)
            ans.append("+")
            crnt += 1

        ans.append("-")
        li.pop()

    else:
        if li.pop() == num:
            ans.append("-")
        else:
            print("NO")
            flag = False
            break

if flag:
    print(*ans, sep="\n")




