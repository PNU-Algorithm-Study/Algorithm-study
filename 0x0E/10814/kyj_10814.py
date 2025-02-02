# 10814
import sys
input = sys.stdin.readline
t = int(input())
name = []
for _ in range(t):
    x = list(input().split())
    x[0] = int(x[0])
    name.append(x)

name.sort(key = lambda x : x[0])

for i in name:
    print(*i)