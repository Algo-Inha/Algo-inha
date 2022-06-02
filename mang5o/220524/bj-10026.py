# https://www.acmicpc.net/problem/10026
# 적록색약

import sys
from collections import deque

dir_matrix = ((0, -1), (0, 1), (1, 0), (-1, 0))
N = int(sys.stdin.readline().rstrip())
all_map = []
all_RG_map = []
for i in range(N):
    tmp_str = sys.stdin.readline().rstrip()
    tmp_list = []  # 일반 행렬
    tmp_RG_list = []  # 적록색약 행렬
    for j in range(N):
        if tmp_str[j] == 'R':
            tmp_list.append(0)
            tmp_RG_list.append(0)
        elif tmp_str[j] == 'G':
            tmp_list.append(1)
            tmp_RG_list.append(0)
        else:
            tmp_list.append(2)
            tmp_RG_list.append(1)
    all_map.append(tmp_list)
    all_RG_map.append(tmp_RG_list)

visited_list = [[False for x in range(N)] for y in range(N)]
visited_RG_list = [[False for x in range(N)] for y in range(N)]

normal_group = 0
RG_group = 0
for y in range(N):
    for x in range(N):
        if not visited_list[y][x]:
            tmp_deque = deque()
            tmp_deque.append([y, x])
            now_color = all_map[y][x]
            visited_list[y][x] = True
            normal_group += 1
            while tmp_deque:
                tmp_elem = tmp_deque.pop()
                for dir_idx in range(4):
                    tmp_y = tmp_elem[0] + dir_matrix[dir_idx][0]
                    tmp_x = tmp_elem[1] + dir_matrix[dir_idx][1]
                    if 0<=tmp_y<N and 0<=tmp_x<N:
                        if not visited_list[tmp_y][tmp_x] and all_map[tmp_y][tmp_x] == now_color:
                            visited_list[tmp_y][tmp_x] = True
                            tmp_deque.append([tmp_y, tmp_x])

for y in range(N):
    for x in range(N):
        if not visited_RG_list[y][x]:
            tmp_deque = deque()
            tmp_deque.append([y, x])
            now_color = all_RG_map[y][x]
            visited_RG_list[y][x] = True
            RG_group += 1
            while tmp_deque:
                tmp_elem = tmp_deque.pop()
                for dir_idx in range(4):
                    tmp_y = tmp_elem[0] + dir_matrix[dir_idx][0]
                    tmp_x = tmp_elem[1] + dir_matrix[dir_idx][1]
                    if 0<=tmp_y<N and 0<=tmp_x<N:
                        if not visited_RG_list[tmp_y][tmp_x] and all_RG_map[tmp_y][tmp_x] == now_color:
                            visited_RG_list[tmp_y][tmp_x] = True
                            tmp_deque.append([tmp_y, tmp_x])

print("{} {}".format(normal_group,RG_group))
