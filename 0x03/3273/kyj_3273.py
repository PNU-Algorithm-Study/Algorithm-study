import sys
input = sys.stdin.readline
n = int(input())
nums = list(map(int, input().split()))
x = int(input())

li = [0 for _ in range(1000000+1)]

for num in nums:
    li[num] += 1

cnt = 0
for num in nums:
    if x - num <= 1000000 and li[x-num] == 1:
        cnt += 1

print(cnt//2)