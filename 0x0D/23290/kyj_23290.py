import sys
input = sys.stdin.readline


M, S = map(int, input().split())
info = [[[] for _ in range(4)] for _ in range(4)]
for _ in range(M):
    a, b, c = map(int, input().split())
    info[a-1][b-1].append(c-1)
sy, sx = map(int, input().split())
sy, sx = sy-1, sx-1
smell = [[0]*4 for _ in range(4)]

dy = [0, -1, -1, -1, 0, 1, 1, 1]
dx = [-1, -1, 0, 1, 1, 1, 0, -1]
da = [-1, 0, 1, 0]
db = [0, -1, 0, 1]


def move_shark(i, j, visited, cnt, check):
    if len(visited) == 3:
        nxt.append(visited[:]+[cnt])
        return

    for k in range(4):
        a, b = i + da[k], j + db[k]
        if 0 <= a < 4 and 0 <= b < 4:
            visited.append(k)
            if (a, b) not in check:
                check.add((a, b))
                move_shark(a, b, visited, cnt+len(temp[a][b]), check)
                check.remove((a, b))
            else:
                move_shark(a, b, visited,cnt, check)
            visited.pop()


for s in range(1, S+1):
    copy_info  = [i[:] for i in info]


    temp = [[[] for _ in range(4)] for _ in range(4)]
    for i in range(4):
        for j in range(4):
            if info[i][j]:
                for d in info[i][j]:
                    cnt = 0
                    while cnt < 8:
                        y, x = i + dy[d], j + dx[d]
                        if 0 <= y < 4 and 0 <= x < 4:
                            if [y, x] != [sy, sx] and smell[y][x] == 0:
                                temp[y][x].append(d)
                                break
                        d = (d+7) % 8
                        cnt += 1
                    if cnt == 8:
                        temp[i][j].append(d)

    nxt = []
    check = set()
    move_shark(sy, sx, [], 0, check)
    nxt.sort(key=lambda x: (-x[3], x[0], x[1], x[2]))

    for i in range(3):
        sy += da[nxt[0][i]]
        sx += db[nxt[0][i]]
        if temp[sy][sx]:
            smell[sy][sx] = s
            temp[sy][sx] = []

    for i in range(4):
        for j in range(4):
            if smell[i][j] and smell[i][j]+2 == s:
                smell[i][j] = 0

            if temp[i][j]:
                copy_info[i][j] += temp[i][j]

    info = copy_info

answer = 0
for i in range(4):
    for j in range(4):
        answer += len(info[i][j])

print(answer)