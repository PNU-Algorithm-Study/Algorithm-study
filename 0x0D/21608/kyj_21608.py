N = int(input())

students = {}
for _ in range(N ** 2):
    input_lst = list(map(int, input().split()))
    students[input_lst[0]] = input_lst[1:]

room = [[0 for _ in range(N)] for _ in range(N)]
like_cnt = [[0 for _ in range(N)] for _ in range(N)]  

dij = [(0, 1), (1, 0), (0, -1), (-1, 0)]

for num, likes in students.items():
    temp = []
    for i in range(N):
        for j in range(N):
            if room[i][j]:
                continue

            like = 0
            empty = 0

            for di, dj in dij:
                ni, nj = i + di, j + dj

                if 0 <= ni < N and 0 <= nj < N:
                    if not room[ni][nj]:
                        empty += 1
                    elif room[ni][nj] in likes:
                        like += 1

            temp.append((like, empty, i, j))

    temp.sort(key=lambda x: (-x[0], -x[1], x[2], x[3]))

    room[temp[0][2]][temp[0][3]] = num


    like_cnt[temp[0][2]][temp[0][3]] = temp[0][0]
    for di, dj in dij:
        ni, nj = temp[0][2] + di, temp[0][3] + dj
        if 0 <= ni < N and 0 <= nj < N and room[ni][nj]:
            if room[temp[0][2]][temp[0][3]] in students[room[ni][nj]]:
                like_cnt[ni][nj] += 1


answer = 0
for i in range(N):
    for j in range(N):
        if like_cnt[i][j] == 1:
            answer += 1
        elif like_cnt[i][j] == 2:
            answer += 10
        elif like_cnt[i][j] == 3:
            answer += 100
        elif like_cnt[i][j] == 4:
            answer += 1000

print(answer)