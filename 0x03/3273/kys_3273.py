# from itertools import combinations

# n,list,x=int(input()),list(map(int,input().split( ))),int(input())
# list_c=combinations(list,2)
# s=0
# for i in list_c:
#     if sum(i) == x:
#         s+=1
# print(s)
import sys
n,list,x=int(input()),list(map(int,sys.stdin.readline().rstrip().split(" "))),int(input())
s=st=0
end=n-1
list.sort()
while st<end:
    r = list[st]+list[end]
    if x== r:
        s+=1
    if x>=r:
        st+=1
    else:
        end-=1
print(s)