n, m = map(int, input().split())
arr = [0] * m

def func(ind):
    if ind == m:
        print(*arr)
        return

    for i in range(1,n+1):
        arr[ind] = i
        func(ind + 1)

func(0)
