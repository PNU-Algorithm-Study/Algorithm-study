n, m = map(int, input().split())
arr = [0] * m
nums = list(map(int, input().split()))
nums.sort()

def func(ind):
    if ind == m:
        print(*arr)
        return

    for i in range(0,n):
        if ind > 0 and  arr[ind-1] > nums[i]:
            continue
        arr[ind] = nums[i]
        func(ind + 1)

func(0)
