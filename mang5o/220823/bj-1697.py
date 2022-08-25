# https://www.acmicpc.net/problem/1697
# 숨바꼭질

import sys
from collections import deque
N,K = map(int, sys.stdin.readline().rstrip().split())
max_idx = max(N,K)+1
step_val = [-1 for _ in range(max_idx*2)]
all_bfs_deque = deque()
all_bfs_deque.append(N)
step_val[N] = 0
while len(all_bfs_deque) > 0:
    tmp_elem = all_bfs_deque.popleft()
    if tmp_elem-1 >= 0:
        if step_val[tmp_elem-1] == -1:
            step_val[tmp_elem - 1] = step_val[tmp_elem] + 1
            all_bfs_deque.append(tmp_elem - 1)
    if tmp_elem+1 <= K*2:
        if step_val[tmp_elem+1] == -1:
            step_val[tmp_elem + 1] = step_val[tmp_elem] + 1
            all_bfs_deque.append(tmp_elem + 1)
    if 0<=tmp_elem*2<=K*2:
        if step_val[tmp_elem*2] == -1:
            step_val[tmp_elem*2] = step_val[tmp_elem] + 1
            all_bfs_deque.append(tmp_elem*2)
print(step_val[K])
