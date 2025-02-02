#11651
import sys
n = int(sys.stdin.readline())
li = list()
for _ in range(n):
  a,b=map(int,sys.stdin.readline().split())
  c=[b,a]
  li.append(c)

li.sort()

for k in li:
  print(k[1],k[0])
