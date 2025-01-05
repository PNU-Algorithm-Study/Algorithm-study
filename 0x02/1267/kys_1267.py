'''
영식 요금제는 30초마다 10원씩 청구된다.
이 말은 만약 29초 또는 그 보다 적은 시간 통화를 했으면 10원이 청구된다. 
만약 30초부터 59초 사이로 통화를 했으면 20원이 청구된다.

민식 요금제는 60초마다 15원씩 청구된다. 
이 말은 만약 59초 또는 그 보다 적은 시간 통화를 했으면 15원이 청구된다.
만약 60초부터 119초 사이로 통화를 했으면 30원이 청구된다.
'''

import sys
n=int(input())
li = list(map(int,sys.stdin.readline().rstrip("/n").split(" ")))
Y=10*n
M=15*n
for i in li:
    Y+=(i // 30)*10
    M+=(i// 60)*15
if M==Y:
    print('Y M',M)
else:
    if M>Y:
        print('Y',Y)
    else:
        print('M',M)