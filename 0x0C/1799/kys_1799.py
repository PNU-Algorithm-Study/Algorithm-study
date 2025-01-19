import sys
input = sys.stdin.readline

n = int(input())
ls = [list(map(int, input().split())) for _ in range(n)]
vs, vs2 = [1]*(2*n-1), [1]*(2*n-1)

def f(c, i, j):
    if j >= n:
        i += 1
        if i == n:
            return c
        j = 1 if j%2 == 0 else 0
    
    ret, a, b = 0, i+j, n-1-i+j
    if ls[i][j] and vs[a] and vs2[b]:
        vs[a] = vs2[b] = 0
        ret = max(ret, f(c+1, i, j+2))
        vs[a] = vs2[b] = 1
    ret = max(ret, f(c, i, j+2))
    
    return ret

print(f(0, 0, 0) + f(0, 0, 1))