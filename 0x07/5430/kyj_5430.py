#5430
from collections import deque
t = int(input())
for _ in range(t):
  func = list(input())
  n = int(input())
  if(n == 0):
    x = input()
    num = []
  else:
    num = deque(list(input()[1:-1].split(',')))
  rev = 0
  flag = 0
  for i in func:
    if(i == 'R'):
      rev += 1

    elif(i == 'D'):
      if(len(num) == 0):
        print("error")
        flag = 1
        break
      if(rev % 2 ==0):
        num.popleft()

      else:
        num.pop()

  if(flag == 1):
    continue
  num = list(num)

  if(rev % 2 == 0):
    print('[',end='')
    print(','.join(num),end='')
    print(']')
  else:
    num.reverse()
    print('[',end='')
    print(','.join(num),end='')
    print(']')