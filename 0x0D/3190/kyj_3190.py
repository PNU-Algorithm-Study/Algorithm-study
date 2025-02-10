N = int(input())
board = [[0] * N for _ in range(N)]
snake_info = []
y, x, d = 0, 0, 0
snake_list = [[0, 0]]
dirs = [[0, 1], [-1, 0], [0, -1], [1, 0]]
info = 0
time = 0


for _ in range(int(input())):
    i, j = map(int, input().split())
    board[i - 1][j - 1] = 1


for _ in range(int(input())):
    X, C = map(str, input().split())
    snake_info.append([int(X), C])

while True:
    time += 1
    y, x = y + dirs[d][0], x + dirs[d][1]

    if [y, x] in snake_list: break
    if y < 0 or x < 0 or y >= N or x >= N:
        break

    if board[y][x] == 1:
        board[y][x] = 0
    else:
        snake_list.pop(0)

    snake_list.append([y, x])

    if info < len(snake_info) and time == snake_info[info][0]:
        if snake_info[info][1] == "L":
            d = (d + 1) % 4
        else:
            d = (d + 3) % 4
        info += 1

print(time)