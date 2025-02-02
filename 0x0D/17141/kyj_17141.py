from itertools import combinations
from collections import deque


N, M = map(int, input().split())

lab_origin = []
virus = []
blank_cnt_static = 0
for i in range(N):
    lab_origin.append(list(map(int, input().split())))
    for j in range(N):
        if lab_origin[i][j] == 2:
            virus.append((i, j))

virus_comb = list(combinations(virus, M))

dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

result = int(1e9)
for vc in virus_comb:
    visited = [[0] * N for _ in range(N)]
    q = deque()
    for v in vc:
        q.append((v[0], v[1], 0))
        visited[v[0]][v[1]] = -1

    while q:
        row, col, time = q.popleft()

        for d in range(4):
            ny = row + dy[d]
            nx = col + dx[d]

            if 0 <= ny < N and 0 <= nx < N and visited[ny][nx] == 0:
                if (lab_origin[ny][nx] == 0 or lab_origin[ny][nx] == 2):
                    q.append((ny, nx, time + 1))
                    visited[ny][nx] = time + 1

    comb_max_time = -1
    for i in range(N):
        for j in range(N):
            if visited[i][j] == 0 and lab_origin[i][j] != 1:
                comb_max_time = int(1e9)
                break
            if comb_max_time < visited[i][j]:
                comb_max_time = visited[i][j]

    if comb_max_time != int(1e9):
        if result > comb_max_time:
            result = comb_max_time

if result == int(1e9):
    print(-1)
else:
    print(result)