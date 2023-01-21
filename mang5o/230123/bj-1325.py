# https://www.acmicpc.net/problem/1325
# 효율적인 해킹

import sys
from collections import deque
N, M = map(int, sys.stdin.readline().rstrip().split())
all_matrix = [[] for _ in range(N)]
for case in range(M):
    tmp_case = list(map(int, sys.stdin.readline().rstrip().split()))
    all_matrix[tmp_case[1]-1].append(tmp_case[0]-1)
all_surround = []
max_visited = 0
for start in range(N):
    now_visited = [False for _ in range(N)]
    now_visited[start] = True
    visited_fig = 1
    inj_deque = deque()
    inj_deque.append(start)
    while inj_deque:
        tmp_elem = inj_deque.popleft()
        for tmp_idx in all_matrix[tmp_elem]:
            if not now_visited[tmp_idx]:
                now_visited[tmp_idx] = True
                visited_fig += 1
                inj_deque.append(tmp_idx)
    all_surround.append(visited_fig)
    max_visited = max(max_visited, visited_fig)

for i in range(N):
    if all_surround[i] == max_visited:
        print(i+1, end=' ')