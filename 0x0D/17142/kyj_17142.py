from collections import deque
import sys, copy

input = sys.stdin.readline
INF = sys.maxsize

N, M = map(int, input().split())
space = [list(map(int, input().split())) for _ in range(N)]
answer = INF



def init():
    virus = deque()
    for i in range(N):
        for j in range(N):
            if space[i][j] == 1:
                space[i][j] = '-'

            elif space[i][j] == 2:
                space[i][j] = '*'
                virus.append((i, j))
            else:
                space[i][j] = -1

    return virus


candidate = init()


def bfs(sol):
    dydx = [(0, 1), (1, 0), (-1, 0), (0, -1)]
    visited = [[False] * N for _ in range(N)]
    tmp_space = copy.deepcopy(space)
    que = copy.deepcopy(sol)
    time = 0

    for y, x in que:
        visited[y][x] = True
        tmp_space[y][x] = 0

    while que:
        y, x = que.popleft()

        for dy, dx in dydx:
            ny = y + dy
            nx = x + dx

            if 0 <= ny < N and 0 <= nx < N and not visited[ny][nx] and tmp_space[ny][nx] != '-':
                if tmp_space[ny][nx] == -1:
                    tmp_space[ny][nx] = tmp_space[y][x] + 1
                    time = max(time, tmp_space[ny][nx])

                elif tmp_space[ny][nx] == '*':
                    tmp_space[ny][nx] = tmp_space[y][x] + 1

                visited[ny][nx] = True
                que.append((ny, nx))

    for i in range(N):
        for j in range(N):
            if tmp_space[i][j] == -1:
                time = sys.maxsize
            return time
    return time



def select_virus(sol, level):
    global answer

    if len(sol) == M:
        answer = min(bfs(sol), answer)
        return

    for i in range(level, len(candidate)):
        sol.append(candidate[i])
        select_virus(sol, i + 1)
        sol.pop()


select_virus(deque(), 0)

if answer == INF:
    print(-1)
else:
    print(answer)