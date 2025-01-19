def hanoi(mx,st,ed,to):
    if mx ==1:
        print(st, ed)
    else:
        hanoi(mx-1,st,to,ed)
        print(st,ed)
        hanoi(mx-1,to,ed,st)
n = int(input())
print(2**n-1)
hanoi(n,1,3,2)