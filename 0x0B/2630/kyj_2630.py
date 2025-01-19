#2630
blue = 0
white = 0
def divide(x, y, m):
  global blue, white
  s = arr[x][y]
  flag = 1
  for i in range(x,x + m):
    for j in range(y,y + m):
      if(s != arr[i][j]):
        divide(x,y,m//2)
        divide(x,y + m//2,m//2)
        divide(x + m//2,y,m//2)
        divide(x + m//2,y + m//2,m//2)
        flag = 0
        return

  if(flag == 1):
    if(s == 1):
      blue += 1

    elif(s == 0):
      white += 1
  return

n = int(input())
arr = [list(map(int,input().split())) for _ in range(n)]
divide(0, 0, n)
print(white)
print(blue)