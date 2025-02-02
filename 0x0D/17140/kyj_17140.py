R, C, K = map(int, input().split())

graph = []
for _ in range(3):
    graph.append(list(map(int, input().split())))

ans = 0


def graphSort(graph):
    for i in range(len(graph)):
        numArr = [0] * 101
        temp = []
        maxNum = 0
        for j in range(len(graph[i])):
            numArr[graph[i][j]] += 1
        for k in range(1, 101):
            if numArr[k] != 0:
                temp.append((k, numArr[k]))
                maxNum += 2
        temp.sort(key=lambda x: (x[1], x[0]))
        if maxNum >= 100:
            maxNum = 100
        tempArr = []
        for k in range(0, maxNum, 2):
            tempArr.append(temp[k // 2][0])
            tempArr.append(temp[k // 2][1])
        graph[i] = tempArr
    maxCol = 0
    for i in range(len(graph)):
        maxCol = max(maxCol, len(graph[i]))
    for i in range(len(graph)):
        tempNum = maxCol - len(graph[i])
        for j in range(tempNum):
            graph[i].append(0)


while True:
    if ans > 100:
        ans = -1
        break
    if len(graph) >= R and len(graph[0]) >= C:
        if graph[R - 1][C - 1] == K:
            break
    ans += 1
    rowCnt = len(graph)
    colCnt = len(graph[0])
    if rowCnt >= colCnt:
        graphSort(graph)
    else:
        a = len(graph)
        b = len(graph[0])
        tempGraph = [[0] * a for _ in range(b)]
        for i in range(b):
            for j in range(a):
                tempGraph[i][j] = graph[j][i]
        graphSort(tempGraph)
        a = len(tempGraph)
        b = len(tempGraph[0])
        orgGraph = [[0] * a for _ in range(b)]
        for i in range(b):
            for j in range(a):
                orgGraph[i][j] = tempGraph[j][i]
        graph = orgGraph

print(ans)