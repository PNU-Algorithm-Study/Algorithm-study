from sys import stdin,stdout
N,*A=map(int,stdin.read().split())
stack=[]
for i in A:
    if i!=0:
        stack.append(i)
    else:
        stack.pop()
print(sum(stack))