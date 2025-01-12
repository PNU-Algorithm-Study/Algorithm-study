n = int(input())
ys = 0
ms = 0

times = list(map(int, input().split()))
for i in range(n):
    ys += 10 + (times[i] // 30) * 10
    ms += 15 + (times[i] // 60) * 15

if ms > ys:
    print("Y",ys)
elif ms == ys:
    print("Y M",ys)
else:
    print("M", ms)