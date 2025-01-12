#1021
from collections import deque
n, m = map(int,input().split())
f = list(map(int,input().split()))
deq = deque([i + 1 for i in range(n)])
count = 0
i = 0
while(i < m):
  num = f[i]
  idx = deq.index(num)

  if(idx == 0):
    deq.popleft()
    i += 1

  else:
    if(idx <= len(deq) - idx):
      deq.append(deq.popleft())
      count += 1

    else:
      deq.appendleft(deq.pop())
      count += 1

print(count)