x, y = map(int,input().split())
if x > y:
    x,y = y,x
li = [i for i in range(x+1, y)]
print(len(li))
print(*li)