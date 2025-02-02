n = int(input())
cnt = 0
isused1 = [0] * 14
isused2 = [0] * 28
isused3 = [0] * 28


def func(cur):
    if cur == n:
        global cnt
        cnt += 1
        return

    for i in range(n):
        if isused1[i] or isused2[i+cur] or isused3[cur - i + n - 1]:
            continue
        isused1[i] = 1
        isused2[i+cur] = 1
        isused3[cur - i + n - 1] = 1
        func(cur + 1)
        isused1[i] = 0
        isused2[i + cur] = 0
        isused3[cur - i + n - 1] = 0

func(0)
print(cnt)