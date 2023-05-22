import sys
input = sys.stdin.readline

n, m = map(int, input().split())

cards = list(map(int, input().split()))


for i in range(m):
    cards.sort()
    min_first = cards[0]
    min_second = cards[1]
    cards[0] = min_first + min_second
    cards[1] = min_first + min_second

print(sum(cards))