n, m = map(int, input().split())
arr = [0] * m
nums = list(map(int, input().split()))
nums.sort()
checked = [0] * (n+1)

def func(ind):
    if ind == m:
        print(*arr)
        return

    tmp = 0
    for i in range(0,n):
        if checked[i] == 0 and tmp != nums[i]:
            arr[ind] = nums[i]
            checked[i] = 1
            tmp = nums[i]
            func(ind + 1)
            checked[i] = 0

func(0)