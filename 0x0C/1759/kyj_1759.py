l, c = map(int, input().split())
char = list(input().split())
ans = []
checked = [0] * c
char.sort()
gather = ['a','e','i','o','u']

def func(ind):
    if ind == l:
        cnt_g = 0
        cnt_c = 0
        for s in ans:
            if s in gather:
                cnt_g += 1
            else:
                cnt_c += 1
        if cnt_g >= 1 and cnt_c >= 2:
            print(''.join(ans))
        return

    for i in range(c):
        if checked[i] == 0:
            if ind > 0 and ans[-1] > char[i] :
                continue
            checked[i] = 1
            ans.append(char[i])
            func(ind + 1)
            checked[i] = 0
            ans.pop()

func(0)