import sys
list = list(map(int,sys.stdin.readline().split()))
list.sort()
print(*list)