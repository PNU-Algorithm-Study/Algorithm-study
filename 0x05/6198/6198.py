n = int(input())
buildings = []
for _ in range(n):
    buildings.append(int(input()))

stack = []
cnt = 0
for i in range(n):
    while stack:
        if stack[-1] <= buildings[i]:
            stack.pop()
        else:
            break

    cnt += len(stack)
    stack.append(buildings[i])

print(cnt)

