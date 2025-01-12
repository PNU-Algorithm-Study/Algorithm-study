n = int(input())

for _ in range(n):
    a, b = input().split()
    li = [0] * 26
    for c in a:
        li[ord(c) - 97] += 1

    for c in b:
        li[ord(c) - 97] -= 1

    flag = True
    for i in range(26):
        if li[i] != 0:
            print("Impossible")
            flag = False
            break
    if flag:
        print("Possible")

