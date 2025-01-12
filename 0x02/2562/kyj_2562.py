nums = []
for _ in range(9):
    nums.append(int(input()))

m = max(nums)

print(m)
print(nums.index(m) + 1)