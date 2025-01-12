# 10866
t = int(input())
li = []
res = []

for _ in range(t):
    a = input().split()
    l = len(li)
    if (a[0] == 'push_front'):
        li = [a[1]] + li
    elif (a[0] == 'push_back'):
        li = li + [a[1]]
    elif (a[0] == 'pop_front'):
        if (l == 0):
            res.append(-1)
        else:
            res.append(li[0])
            li = li[1:]
    elif (a[0] == 'pop_back'):
        if (l == 0):
            res.append(-1)
        else:
            res.append(li.pop())

    elif (a[0] == 'size'):
        res.append(l)

    elif (a[0] == 'empty'):
        if (l == 0):
            res.append(1)
        else:
            res.append(0)

    elif (a[0] == 'front'):
        if (l == 0):
            res.append(-1)
        else:
            res.append(li[0])
    else:
        if (l == 0):
            res.append(-1)
        else:
            res.append(li[-1])

for i in res:
    print(i)