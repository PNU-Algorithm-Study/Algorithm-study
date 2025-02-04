N=int(input())
array=[]
for i in range(N):
    array.append(int(input()))
for i in range(N):
    i=N-i-1
    for j in range(i):
        if array[j]>array[j+1]:
            array[j],array[j+1]=array[j+1],array[j]
for i in array:
    print(i)
