# https://www.acmicpc.net/problem/2164
# 카드2- BJ_2164

from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
card = deque((i + 1) for i in range(n))

while len(card) > 1:
    card.popleft()
    x = card.popleft()
    card.append(x)

print(*card)
