# https://www.acmicpc.net/problem/2468
# 안전 영역

import sys
from collections import deque
dir_matrix = ((0,1),(1,0),(0,-1),(-1,0))
N = int(sys.stdin.readline().rstrip())
all_map = []
min_fig = 100
max_fig = 0
for i in range(N):
    tmp_inp = list(map(int, sys.stdin.readline().rstrip().split()))
    all_map.append(tmp_inp)
    min_fig = min(min(tmp_inp), min_fig)
    max_fig = max(max(tmp_inp), max_fig)

max_groups = 1
for now_water in range(min_fig, max_fig+1):
    is_visited = [[False for x in range(N)] for y in range(N)]
    all_group = 0
    for y in range(N):
        for x in range(N):
            if not is_visited[y][x] and all_map[y][x]>=now_water:
                now_deque = deque()
                is_visited[y][x] = True
                now_deque.append([y,x])
                all_group += 1
                while now_deque:
                    tmp_elem = now_deque.popleft()
                    for dir_idx in range(4):
                        tmp_y = tmp_elem[0] + dir_matrix[dir_idx][0]
                        tmp_x = tmp_elem[1] + dir_matrix[dir_idx][1]
                        if 0<=tmp_y<N and 0<=tmp_x<N:
                            if not is_visited[tmp_y][tmp_x] and all_map[tmp_y][tmp_x]>=now_water:
                                is_visited[tmp_y][tmp_x] = True
                                now_deque.append([tmp_y,tmp_x])
    max_groups = max(max_groups, all_group)

print(max_groups)
