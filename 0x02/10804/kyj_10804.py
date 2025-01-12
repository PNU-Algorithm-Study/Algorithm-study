cards = [i for i in range(1,21)]

for _ in range(10):
    i,j = map(int,input().split())
    cards[i-1:j] = reversed(cards[i-1:j])

print(*cards)