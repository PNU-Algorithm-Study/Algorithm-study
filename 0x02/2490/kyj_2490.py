for _ in range(3):
    nums = list(map(int, input().split()))

    s = sum(nums)
    if s == 0:
        print("D")

    elif s == 1:
        print("C")

    elif s == 2:
        print("B")

    elif s == 3:
        print("A")

    else:
        print("E")
