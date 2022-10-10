# https://www.acmicpc.net/problem/16198
# 에너지 모으기

import sys
from collections import deque

N = int(sys.stdin.readline())
marbles = list(map(int, sys.stdin.readline().split()))
all_queue = deque()

all_queue.append(([0] + [marbles[x] for x in range(N)]))  # + 현재 에너지

max_val = 0
while all_queue:
    tmp_elem = all_queue.popleft()
    if len(tmp_elem) == 3:
        max_val = max(max_val, tmp_elem[0])
        continue
    for i in range(2, len(tmp_elem)-1):
        new_elem = []
        for idx in range(len(tmp_elem)):
            if idx == i:
                continue
            else:
                new_elem.append(tmp_elem[idx])
        new_elem[0] += new_elem[i-1] * new_elem[i]
        all_queue.append(new_elem)

print(max_val)