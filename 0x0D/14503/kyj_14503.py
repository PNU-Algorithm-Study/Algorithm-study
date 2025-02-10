import sys

input = sys.stdin.readline

n, m = map(int, input().split())
r, c, d = map(int, input().split())
board = [list(map(int, input().split())) for i in range(n)]

move = [(0, -1), (-1, 0), (0, 1), (1, 0)]
ans = 0
while True:
    if not board[r][c]:
        board[r][c] = 2
        ans += 1

    for x, y in move:
        dx = r + x
        dy = c + y
        if not board[dx][dy]:
            break
    else:
        x, y = move[(d - 1) % 4]
        dx = r + x
        dy = c + y
        if board[dx][dy] == 1:
            break
        else:
            r = dx
            c = dy
            continue

    x, y = move[d]
    dx = r + x
    dy = c + y
    d = (d - 1) % 4
    if not board[dx][dy]:
        r = dx
        c = dy
        continue

print(ans)