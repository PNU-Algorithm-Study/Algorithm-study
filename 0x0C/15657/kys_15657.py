n,m = map(int,input().split())
s = list(map(int,input().split()))
ans = []
s.sort()
# print(s)
def back(x):
    if len(ans) == m:
        print(*ans)
        return
    for i in range (x,n):
        ans.append(s[i])
        back(i)
        ans.pop()

back(0)