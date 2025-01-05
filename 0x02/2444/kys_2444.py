n = int(input())
for i in range(n):
    print(' '*(n-i-1)+'*'*(1+2*i))
for i in range(n-1,2*n-2):
    print(' '*(i-n+2)+'*'*(1+2*(2*n-i-3)))
    