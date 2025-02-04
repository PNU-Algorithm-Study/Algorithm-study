# 1780
n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
zero = 0
one = 0
minus = 0


def divide(x, y, m):
    global zero, one, minus
    s = arr[x][y]
    mm = m // 3
    flag = 1

    for i in range(x, x + m):
        for j in range(y, y + m):
            if (arr[i][j] != s):
                divide(x, y, mm)
                divide(x, y + mm, mm)
                divide(x, y + mm + mm, mm)
                divide(x + mm, y, mm)
                divide(x + mm, y + mm, mm)
                divide(x + mm, y + mm + mm, mm)
                divide(x + mm + mm, y, mm)
                divide(x + mm + mm, y + mm, mm)
                divide(x + mm + mm, y + mm + mm, mm)
                return

    if (flag == 1):
        if (s == 0):
            zero += 1

        elif (s == 1):
            one += 1

        elif (s == -1):
            minus += 1

    return


divide(0, 0, n)
print(minus)
print(zero)
print(one)