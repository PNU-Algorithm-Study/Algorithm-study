# 9012
t = int(input())
for _ in range(t):
    a = input()
    cnt = 0
    f = 0
    if (a[0] == ')'):
        f = 1
    else:
        for i in range(len(a)):
            if (a[i] == '('):
                cnt += 1

            else:
                cnt -= 1
                if (cnt < 0):
                    f = 1
                    break
        if (cnt != 0):
            f = 1
    if (f):
        print("NO")
    else:
        print("YES")