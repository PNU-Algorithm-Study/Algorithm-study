#10989
import sys
input = sys.stdin.readline
n = int(input())
nums = [0]*10001
for _ in range(n):
    nums[int(input())] += 1

for i in range(10001):
    while(nums[i] != 0):
        print(i)
        nums[i] -= 1
