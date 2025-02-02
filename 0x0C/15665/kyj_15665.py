n, m = map(int, input().split())
arr = [0] * m
nums = list(map(int, input().split()))
nums.sort()

def func(ind):
    if ind == m:
        print(*arr)
        return

    tmp = 0
    for i in range(0,n):
        if tmp != nums[i]:
            if ind > 0 and arr[ind-1] > nums[i]:
                continue
            arr[ind] = nums[i]
            tmp = nums[i]
            func(ind + 1)

func(0)