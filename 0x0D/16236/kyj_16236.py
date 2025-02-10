n=int(input())
g=[list(map(int,input().split())) for i in range(n)]
size = 2; t = 0

def bfs(g,start,n,eat):
    global size, t
    visit=[0]*(n**2)
    q=[start];
    x,y=start; move = [(-1,0),(0,-1),(0,1),(1,0)]
    visit[n*x+y]=1
    d= 0
    while q:
        d+=1; tmp=[];eats=[]
        for a,b in q:
            for i,j in move:
                if 0<=a+i<n and 0<=b+j<n:
                    if 0<g[a+i][b+j]<size and not visit[(a+i)*n+b+j]:
                        eats.append((a+i,b+j))
                    elif (g[a+i][b+j]==0 or g[a+i][b+j]==size) and not visit[(a+i)*n+b+j]:
                        tmp.append((a+i,b+j))
                        visit[(a+i)*n+b+j]=1
        if eats:
            eats.sort()
            p,q = eats[0]
            eat+=1; t+=d; g[p][q]=0; g[x][y]=0
            if eat==size:
                size+=1;eat=0;
            return bfs(g,eats[0],n,eat)
        q = tmp
    return
for i in range(n):
    for j in range(n):
        if g[i][j]==9:
            bfs(g,(i,j),n,0)
            break
print(t)