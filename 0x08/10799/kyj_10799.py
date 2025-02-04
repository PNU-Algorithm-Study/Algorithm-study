# 10799
a = input()
cnt = 0
s = 0
for i in range(len(a)):
    if (a[i] == '('):
        cnt += 1

    else:
        if (a[i - 1] == '('):
            cnt -= 1
            s += cnt

        else:
            cnt -= 1
            s += 1
print(s)