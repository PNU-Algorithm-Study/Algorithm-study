from collections import deque

def bfs(start, end):
    dx = [up, -down]
    q = deque()
    q.append(start)
    while q:
        now = q.popleft()
        if now == end:
            return board[now]-1
        for x in dx:
            moved = x + now
            if moved < 1 or moved > n:
                continue
            if board[moved] == 0:
                board[moved] = board[now]+1
                q.append(moved)
    return 'use the stairs'

n, start, end, up, down = map(int, input().split(' '))
board = [0]*(n+1)
board[0] = -1
board[start] = 1

ans = bfs(start, end)
print(ans)