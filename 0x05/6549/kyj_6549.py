# 6549
def square(l, r):
    if (l == r):
        return num[l]

    else:
        m = (l + r) // 2
        left = m
        right = m + 1
        cnt = 2
        h = min(num[left], num[right])
        tmp = h * cnt
        while True:
            if ((num[left] == 0 or left == l) and (num[right] == 0 or right == r)):
                break
            elif (num[left] == 0 or left == l):
                if (num[right + 1] < h):
                    h = num[right + 1]
                right += 1

            elif (num[right] == 0 or right == r):
                if (num[left - 1] < h):
                    h = num[left - 1]
                left -= 1

            else:
                if (num[right + 1] < num[left - 1]):
                    if (num[left - 1] < h):
                        h = num[left - 1]
                    left -= 1

                else:
                    if (num[right + 1] < h):
                        h = num[right + 1]
                    right += 1

            cnt += 1
            tmp = max(tmp, h * cnt)

        return (max(square(l, m), square(m + 1, r), tmp))


while (True):
    arr = list(map(int, input().split()))
    if (arr[0] == 0):
        break

    else:
        num = arr[1:]
        print(square(0, len(num) - 1))
