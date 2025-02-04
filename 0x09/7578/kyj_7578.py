import math
import sys

N=int(input())
A=[0]+list(map(int,sys.stdin.readline().rstrip().split()))
B=[0]+list(map(int,sys.stdin.readline().rstrip().split()))
BDic={}
for i in range(1,N+1):
    BDic[B[i]]=i

def treeSum(node,start,end,left,right):
    if left<=start and end<=right:
        return tree[node]
    elif right<start or end<left:
        return 0
    else:
        mid=(start+end)//2
        return treeSum(node*2,start,mid,left,right)+treeSum(node*2+1,mid+1,end,left,right)

def update(node,start,end,index):
    if not start<=index<=end:
        return

    tree[node]+=1
    if start==end:
        return

    mid=(start+end)//2
    update(node*2,start,mid,index)
    update(node*2+1,mid+1,end,index)


size=2**(math.ceil(math.log(N,2))+1)
tree=[0 for i in range(size)]
ans=0

for i in range(1,N+1):
    num=A[i]
    index=BDic[num]
    ans+=treeSum(1,1,N,index+1,N)
    update(1,1,N,index)

print(ans)