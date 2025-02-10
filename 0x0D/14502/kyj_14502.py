import sys
import copy
from collections import deque
input = sys.stdin.readline

def bfs():
    queue = deque()
    trial = copy.deepcopy(grid)
    for i in range(len(virus)):
        queue.append(virus[i])

    while queue:
        y, x = queue.popleft()

        for i in range(4):
            ny = dy[i] + y
            nx = dx[i] + x

            if ny <= -1 or ny >= n or nx <= -1 or nx >= m:
                continue
            if trial[ny][nx] == 0:
                trial[ny][nx] = 2
                queue.append([ny, nx])

    global safe
    safe_current = 0

    for i in range(n):
        safe_current += trial[i].count(0)

    safe = max(safe, safe_current)


def walls(count):
    if count == 3:
        bfs()
        return

    for y in range(n):
        for x in range(m):
            if grid[y][x] == 0:
                grid[y][x] = 1
                walls(count + 1)
                grid[y][x] = 0


n, m = map(int, input().split())
grid = []
virus = []
safe = 0
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for _ in range(n):
    grid.append(list(map(int, input().split())))

for y in range(n):
    for x in range(m):
        if grid[y][x] == 2:
            virus.append([y, x])

walls(0)
print(safe)