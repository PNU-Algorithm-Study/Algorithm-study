n, m = map(int, input().split())
arr = [0] * m
nums = list(map(int, input().split()))
nums.sort()
checked = [0] * (n+1)

def func(ind):
    if ind == m:
        print(*arr)
        return


    for i in range(0,n):
        if checked[i] == 0:
            if ind > 0 and nums[i] < arr[ind-1]:
                continue
            arr[ind] = nums[i]
            checked[i] = 1
            func(ind + 1)
            checked[i] = 0

func(0)