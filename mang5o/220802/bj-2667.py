# https://www.acmicpc.net/problem/2667
# 단지번호 붙이기

import sys
from collections import deque

dir_matrix = ((0,1),(1,0),(0,-1),(-1,0))

N = int(sys.stdin.readline().rstrip())
all_map = []
for i in range(N):
    all_map.append(list(map(int, list(sys.stdin.readline().rstrip()))))
is_visited = [[False for x in range(N)]for y in range(N)]

all_group = 0
size_list = []
for y in range(N):
    for x in range(N):
        if all_map[y][x] == 1 and not is_visited[y][x]:
            now_size = 1
            all_group += 1
            is_visited[y][x] = True
            now_deque = deque()
            now_deque.append([y,x])
            while now_deque:
                tmp_elem = now_deque.popleft()
                for dir_idx in range(4):
                    tmp_y = tmp_elem[0] + dir_matrix[dir_idx][0]
                    tmp_x = tmp_elem[1] + dir_matrix[dir_idx][1]
                    if 0<=tmp_y<N and 0<=tmp_x<N:
                        if not is_visited[tmp_y][tmp_x] and all_map[tmp_y][tmp_x] == 1:
                            is_visited[tmp_y][tmp_x] = True
                            now_deque.append([tmp_y,tmp_x])
                            now_size += 1
            if now_size>0:
                size_list.append(now_size)
size_list.sort()

print(all_group)
for size in size_list:
    print(size)



