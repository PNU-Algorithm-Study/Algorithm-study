nums = []
s = 0
for _ in range(7):
    num = int(input())
    if num % 2 == 1:
        nums.append(num)

        s += num

nums.sort()

if len(nums) == 0:
    print(-1)

else:
    print(s)
    print(nums[0])