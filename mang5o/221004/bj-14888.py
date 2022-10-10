# https://www.acmicpc.net/problem/14888
# 연산자 끼워넣기

import sys
from collections import deque

N = int(sys.stdin.readline())
figures = list(map(int, sys.stdin.readline().split()))
operators = list(map(int, sys.stdin.readline().split()))

all_queue = deque()
all_queue.append([[], operators])

min_cost = 1000000000
max_cost = -1000000000
while all_queue:
    tmp_elem = all_queue.popleft()
    if len(tmp_elem[0]) == N - 1:
        now_cost = figures[0]
        for i in range(N - 1):
            if tmp_elem[0][i] == 0:
                now_cost += figures[i + 1]
            elif tmp_elem[0][i] == 1:
                now_cost -= figures[i + 1]
            elif tmp_elem[0][i] == 2:
                now_cost *= figures[i + 1]
            else:
                now_plus = [True if now_cost >= 0 else False, True if figures[i + 1] >= 0 else False]
                now_figs = [now_cost if now_plus[0] else -1*now_cost, figures[i+1] if now_plus[1] else -1*figures[i+1]]
                now_cost = now_figs[0] // now_figs[1]
                if not now_plus[0]: now_cost *= -1
                if not now_plus[1]: now_cost *= -1
        min_cost = min(min_cost, now_cost)
        max_cost = max(max_cost, now_cost)
        continue
    for oper_idx in range(4):
        if tmp_elem[1][oper_idx] > 0:
            new_elem = [[tmp_elem[0][x] for x in range(len(tmp_elem[0]))], [tmp_elem[1][x] for x in range(4)]]
            new_elem[0].append(oper_idx)
            new_elem[1][oper_idx] -= 1
            all_queue.append(new_elem)

print(max_cost)
print(min_cost)
