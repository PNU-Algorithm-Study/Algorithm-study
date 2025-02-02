n = int(input())
arr = []
for _ in range(n):
  arr.append(int(input()))

for i in range(len(arr)):
  m = arr[i]
  ind = 0
  for j in range(i+1,len(arr)):
    if(m > arr[j]):
      m = arr[j]
      ind = j
  if(ind):
    arr[ind] = arr[i]
    arr[i] = m
for _ in range(n):
    print(arr[_])