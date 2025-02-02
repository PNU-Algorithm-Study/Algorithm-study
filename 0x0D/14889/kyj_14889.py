#14889
import itertools
N = int(input())
board = [list(map(int,input().split())) for i in range(N)]
result = []
arr = [i for i in range(N)]
team1 = list(itertools.combinations(arr,N//2))
team2 = []


def score(li):
  res = 0
  for i in range(len(li)):
    for j in range(i,len(li)):
      res = res + board[li[i]][li[j]] + board[li[j]][li[i]]
  return res


for i in range(len(team1)//2):
  for j in range(N):
    if j not in team1[i]:
      team2.append(j)
  one = (score(list(team1[i])))
  two = (score(team2))

  result.append(abs(one-two))
  team2 = []

print(min(result))
