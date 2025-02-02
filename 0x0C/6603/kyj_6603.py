def func(ind):
    if ind == 6:
        print(*arr)
        return

    for i in range(li[0]):
        if checked[i] == 0:
            if ind > 0 and arr[-1] > li[i+1]:
                continue
            checked[i] = 1
            arr.append(li[i+1])
            func(ind + 1)
            arr.pop()
            checked[i] = 0


while True:
    li = list(map(int, input().split()))
    if li[0] == 0:
        break

    nums = li[1:]
    arr = []
    checked = [0] * li[0]
    func(0)
    print()

