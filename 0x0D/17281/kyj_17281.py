import sys
from itertools import permutations
input = sys.stdin.readline
ining_num = int(input().rstrip())

ining_res = []
for _ in range(ining_num):
    ining_res.append(list(map(int, input().rstrip().split(" "))))


def getScore(ining, i, tmp_ans):
    out_count = 0
    base3, base2, base1 = 0, 0, 0
    while(out_count < 3):
        if(ining[order[i]] == 0):
            out_count += 1
        elif(ining[order[i]] == 1):
            tmp_ans += base3
            base3, base2, base1 = base2, base1, 1
        elif(ining[order[i]] == 2):
            tmp_ans += (base3+base2)
            base3, base2, base1 = base1, 1, 0
        elif(ining[order[i]] == 3):
            tmp_ans += (base3+base2+base1)
            base3, base2, base1 = 1, 0, 0
        elif(ining[order[i]] == 4):
            tmp_ans += (base1+base2+base3 + 1)
            base1, base2, base3 = 0, 0, 0

        i = (i+1) % 9
    return i, tmp_ans


answer = 0
for order in permutations(range(1, 9), 8):
    order = (*order[:3], 0, *order[3:])

    tmp_ans = 0

    i = 0
    for ining in ining_res:
        i, tmp_ans = getScore(ining, i, tmp_ans)

    answer = max(answer, tmp_ans)


print(answer)
