n, m = map(int, input().split())
arr = [0] * m

def func(ind):
    if ind == m:
        print(*arr)
        return
    k = 1
    if ind != 0:
        k = arr[ind-1]
    for i in range(k,n+1):
        arr[ind] = i
        func(ind + 1)

func(0)