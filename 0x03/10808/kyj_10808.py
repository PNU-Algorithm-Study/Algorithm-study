li = [0 for _ in range(26)]
s = input()
for c in s:
    li[ord(c)-ord("a")] += 1

print(*li)