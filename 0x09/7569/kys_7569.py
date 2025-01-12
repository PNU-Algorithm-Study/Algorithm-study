import sys
from collections import deque

def breadth_first_seach() -> list:
    while queue:
        z, x, y = queue.popleft()

        for i in range(6):
            a = z + dz[i]
            b = x  +dx[i]
            c = y + dy[i]

            if 0<=a<H and 0<=b<N and 0<=c<M and graph[a][b][c] == 0:
                queue.append([a, b, c])
                graph[a][b][c] = graph[z][x][y] + 1

    return graph


if __name__ == "__main__":

    M, N, H = list(map(int, sys.stdin.readline().split()))
    queue = deque()
    graph = [[[0 for i in range(M)] for j in range(N)] for k in range(H)]

    dx = [-1, 1, 0, 0, 0, 0]
    dy = [0, 0, 1, -1, 0, 0]
    dz = [0, 0, 0, 0, 1, -1]

    for z in range(H):
        for x in range(N):
            graph[z][x] = list(map(int, sys.stdin.readline().split()))
            for y in range(M):
                if graph[z][x][y] == 1:
                    queue.append([z, x, y])

    graph = breadth_first_seach()    
    
    day = 0
    for i in graph:
        for j in i:
            for k in j:
                if k == 0:
                    print (-1)
                    exit(0)
            day = max(day, max(j))
    print (day-1)