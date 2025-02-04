n = int(input())
nums = list(map(int, input().split()))

nums.reverse()

stack = []
ans = [-1] * n

for i in range(n):
    while stack:
        if stack[-1] <= nums[i]:
            stack.pop()

        else:
            ans[i] = stack[-1]
            break

    stack.append(nums[i])

ans.reverse()
print(*ans)