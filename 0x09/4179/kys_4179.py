from collections import deque

bfs = deque()
ls = []

R, C = map(int, input().split())

for i in range(R):
    s = list(input())
    if s.count('J'):
        bfs.appendleft((i, s.index('J'),0))
    idx = [index for index, value in enumerate(s) if value == 'F']
    for j in idx:
        bfs.append([i, j, 0])
    ls.append(s) 

nx_ls = [-1,1,0,0]
ny_ls = [0,0,-1,1]

while bfs:
    x,y,n = bfs.popleft()
    for i in range(4):
        nx = x + nx_ls[i]
        ny = y + ny_ls[i]
        if nx < 0 or nx >= R or ny < 0 or ny >= C:
            if ls[x][y] == 'J':
                print(n+1)
                exit(0)
            continue
        if ls[x][y] == 'F':
            if not ls[nx][ny] == '#' and not ls[nx][ny] == 'F':
                bfs.append([nx,ny,0])
                ls[nx][ny] = 'F'
        elif ls[x][y] =='J':
            if ls[nx][ny] == '.':
                bfs.append([nx,ny,n+1])
                ls[nx][ny] = 'J'
print('IMPOSSIBLE')