# 10845
t = int(input())
res = []
li = []
for _ in range(t):
    l = len(li)
    a = input().split()
    if(a[0] == 'push'):
        li.append(a[1])
    elif(a[0] == 'pop'):
        if(l == 0):
            res.append(-1)
        else:
            res.append(li[0])
            li = li[1:]
    elif(a[0] == 'size'):
        res.append(l)
    elif(a[0] == 'empty'):
        if(l == 0):
            res.append(1)
        else:
            res.append(0)
    elif(a[0] == 'front'):
        if(l == 0):
            res.append(-1)
        else:
            res.append(li[0])
    else:
        if(l == 0):
            res.append(-1)
        else:
            res.append(li[-1])

for i in res:
    print(i)