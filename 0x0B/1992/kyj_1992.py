#1992
n = int(input())
arr = [list(input()) for _ in range(n)]
def divide(x,y,m):
  s = arr[x][y]
  flag = 1
  for i in range(x, x + m):
    for j in range(y, y + m):
      if(arr[i][j] != s):
        print('(',end='')
        divide(x,y,m//2)
        divide(x,y + m//2,m//2)
        divide(x + m//2,y,m//2)
        divide(x + m//2,y + m//2,m//2)
        print(')',end='')
        flag = 0
        return

  if(flag == 1):
    if(s == '1'):
      print(1,end='')

    elif(s=='0'):
      print(0,end='')


divide(0,0,n)