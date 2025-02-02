n, s = map(int, input().split())
nums = list(map(int, input().split()))
cnt = 0

def func(ind, arr_sum):
    if ind == n :
        if arr_sum == s:
            global cnt
            cnt += 1
        return
    func(ind+1, arr_sum)
    func(ind+1, arr_sum + nums[ind])

func(0,0)
if s == 0:
    cnt -= 1
print(cnt)