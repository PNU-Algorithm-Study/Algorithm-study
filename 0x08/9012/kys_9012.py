N=int(input())
for _ in range(N):
    sum=0
    pstr=input()
    for i in pstr:
        if i=="(":
            sum+=1
        else:
            sum-=1
        if sum<0:
            break
    if sum!=0:
        print("NO")
    else:
        print("YES")