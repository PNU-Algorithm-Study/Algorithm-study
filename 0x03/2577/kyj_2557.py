a = int(input())
b = int(input())
c = int(input())

li = [0 for _ in range(10)]

s = str(a*b*c)

for c in s:
    li[int(c)] += 1

print(*li,sep='\n')