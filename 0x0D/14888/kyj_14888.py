# 14888
import sys

input = sys.stdin.readline
n = int(input().rstrip())
nums = list(map(int, input().rstrip().split()))
li = list(map(int, input().rstrip().split()))
operator = []

for i in range(4):
    if (li[i] == 0):
        pass

    else:
        for _ in range(li[i]):
            operator.append(i)

mi = int(1e9)
ma = int(1e9) * (-1)

res = nums[0]


def dfs(idx):
    global ma, mi, res
    if (idx == n):

        if (res > ma):
            ma = res

        if (res < mi):
            mi = res

        return

    else:
        for i in range(len(operator)):
            b = res
            x = operator[i]
            if (operator[i] == 0):
                res += nums[idx]
            elif (operator[i] == 1):
                res -= nums[idx]
            elif (operator[i] == 2):
                res *= nums[idx]
            else:
                res /= nums[idx]
            res = int(res)

            operator.remove(operator[i])
            dfs(idx + 1)
            res = b
            operator.insert(i, x)


dfs(1)

print(ma)
print(mi)




