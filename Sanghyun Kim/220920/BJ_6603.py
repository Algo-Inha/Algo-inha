# https://www.acmicpc.net/problem/6603
# 로또- BJ_6603

from itertools import combinations
from collections import deque
import sys
input = sys.stdin.readline

while 1:
    k_s = deque(deque(map(int, input().split())))
    if k_s[0] == 0:
        break

    k = k_s[0]
    k_s.popleft()
    sCombK = list(combinations(k_s, 6))
    for i in sCombK:
        print(*i)
    print()