# 11650
import sys
input = sys.stdin.readline
n = int(input())
nums = []
for _ in range(n):
    nums.append(list(map(int,input().split())))
nums.sort(key = lambda x:x[1])
nums.sort(key = lambda x:x[0])
for i in nums:
    print(*i)