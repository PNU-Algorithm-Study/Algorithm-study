n, m = map(int, input().split())
arr = [0] * m
checked = [0] * (n+1)

def func(ind):
    if ind == m:
        print(*arr)
        return

    for i in range(1,n+1):
        if checked[i] == 0:
            arr[ind] = i
            checked[i] = 1
            func(ind + 1)
            checked[i] = 0

func(0)
