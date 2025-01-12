heights = []
for _ in range(9):
    heights.append(int(input()))

s = sum(heights)

found = False
for i in range(8):
    for j in range(i + 1, 9):
        if s - heights[i] - heights[j] == 100:
            x, y = heights[i], heights[j]
            found = True
            break
    if found:
        break

heights.remove(x)
heights.remove(y)

heights.sort()

print(*heights,sep="\n")