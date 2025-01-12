n, k = map(int, input().split())

table = {1: [0,0], 2: [0,0], 3: [0,0], 4: [0,0], 5: [0,0], 6: [0,0]}
for _ in range(n):
    s, g = map(int, input().split())
    table[g][s] += 1

cnt = 0
for i in range(1,7):
    for j in range(2):
        if table[i][j] % k == 0:
            cnt += table[i][j] // k
        else:
            cnt += (table[i][j] // k) + 1

print(cnt)