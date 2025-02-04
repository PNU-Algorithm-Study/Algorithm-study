L,C = map(int,input().split())
arr = list(map(str,input().split()))
ans = []
arr.sort()

def check(arr):
    v_cnt = c_cnt = 0
    for ch in arr:
        if ch in ['a', 'e', 'i', 'o', 'u']:
            v_cnt +=1
        else:
            c_cnt +=1
    if v_cnt >=1 and c_cnt >=2:
        return True
    else:
        return False
            
def back(x):
    if len(ans) == L:
        if check(ans):
            print(*ans)
        return
    for i in range (x,C):
        ans.append(arr[i])
        back(i+1)
        ans.pop()

back(0)
    