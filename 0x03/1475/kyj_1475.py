n = input()

li = [0 for _ in range(10)]

for c in n:
    li[int(c)] += 1

x = (li[6] + li[9] + 1 )//2
li[6] = x
li[9] = x

m = max(li)
print(m)

