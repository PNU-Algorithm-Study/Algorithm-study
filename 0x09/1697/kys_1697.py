from collections import deque
s,e=map(int,input().split())
q=deque([[s,0]])
v={}
while(1):
    n,f=q.popleft()
    if n==e:
        print(f)
        break
    elif n<0 or 10**5<n or v.get(n):
        continue
    v[n]=1
    q.extend([[n*2,f+1],[n-1,f+1],[n+1,f+1]])