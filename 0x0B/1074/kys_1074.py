import sys
input = sys.stdin.readline

n,r,c = map(int,input().split())
sum = 0

def count(x,y,n):
    global sum
    if x==r and y==c:
        print(sum)
        exit(0)
        
    if n==1:
        sum+=1
        return
    if not (x<=r<x+n and y<=c<y+n):
        sum+= n*n
        return
    temp = n//2
    count(x,y,temp)
    count(x,y+temp,temp)
    count(x+temp,y,temp)
    count(x+temp,y+temp,temp)


count(0,0,2**n)
print(sum)