n = int(input())
towers = list(map(int, input().split()))
ans = [0] * n
stack = []
for i in range(n):
    while stack:
        if stack[-1][1] > towers[i]:
            ans[i] = stack[-1][0] + 1
            break
        else:
            stack.pop()

    stack.append((i, towers[i]))
print(*ans)