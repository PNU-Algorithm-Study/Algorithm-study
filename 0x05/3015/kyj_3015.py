n = int(input())
people = []
for i in range(n):
    people.append(int(input()))

stack = []
cnt = 0
for i in range(n):
    same_height = 1

    while stack:
        if stack[-1][0] < people[i]:
            cnt += stack[-1][1]
            stack.pop()
        elif stack[-1][0] == people[i]:
            cnt += stack[-1][1]
            same_height += stack[-1][1]
            stack.pop()
        else:
            cnt += 1
            break
    stack.append((people[i], same_height))
print(cnt)