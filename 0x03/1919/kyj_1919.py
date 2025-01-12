a = input()
b = input()
li1 = [0] * 26
li2 = [0] * 26
for c in a:
    li1[ord(c) - 97] += 1

for c in b:
    li2[ord(c) - 97] += 1

ans = len(a) + len(b)
for i in range(26):
    ans -= min(li1[i], li2[i]) * 2

print(ans)

