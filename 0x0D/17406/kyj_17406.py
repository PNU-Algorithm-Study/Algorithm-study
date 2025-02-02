from itertools import permutations

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
val = []


def matrix_value(ans):
    for i in range(n):
        ans = min(ans, sum(matrix[i]))
    return ans


def rotate(rcs):
    r, c, s = rcs
    for i in range(1, s+1):
        tmp = matrix[r - 1 - i][c - 1 - i]
        x = r - i - 1
        y = c - i - 1
        for j in range(4):
            for k in range(2*i):
                nx = x + dx[j]
                ny = y + dy[j]
                matrix[x][y] = matrix[nx][ny]
                x, y = nx, ny
        matrix[r-1-i][c-i] = tmp


n, m, k = map(int, input().split())
a = [[] for _ in range(n)]
for h in range(n):
    a[h] = list(map(int, input().split()))
rotation = [[] for _ in range(k)]
for i in range(k):
    rotation[i] = list(map(int, input().split()))
answer = 1e9
orders = permutations(rotation)

for order in orders:
    matrix = [a[row][:] for row in range(n)]
    for rcs in order:
        rotate(rcs)
    answer = matrix_value(answer)

print(answer)