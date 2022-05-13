# https://www.acmicpc.net/problem/2589
# 보물섬

import sys
from collections import deque

dir_matrix = ((-1, 0), (1, 0), (0, -1), (0, 1))
H, W = map(int, sys.stdin.readline().rstrip().split())
all_map = []  # True는 땅
for i in range(H):
    tmp_map = sys.stdin.readline().rstrip()
    tmp_map_list = [(tmp_map[x] == 'L') for x in range(W)]
    all_map.append(tmp_map_list)

all_max = 0
for y in range(H):
    for x in range(W):
        if all_map[y][x]:
            tmp_visited = [[False for xx in range(W)] for yy in range(H)]
            tmp_visited[y][x] = True
            tmp_deque = deque()
            tmp_deque.append([y, x, 0])
            max_distance = 0
            while len(tmp_deque) > 0:
                tmp_elem = tmp_deque.popleft()
                tmp_distance = tmp_elem[2]
                max_distance = max(max_distance, tmp_distance)
                for dir_idx in range(4):
                    tmp_y = tmp_elem[0] + dir_matrix[dir_idx][0]
                    tmp_x = tmp_elem[1] + dir_matrix[dir_idx][1]
                    if 0 <= tmp_y < H and 0 <= tmp_x < W:
                        if not tmp_visited[tmp_y][tmp_x] and all_map[tmp_y][tmp_x]:
                            tmp_visited[tmp_y][tmp_x] = True
                            tmp_deque.append([tmp_y, tmp_x, tmp_distance + 1])
            all_max = max(all_max, max_distance)

print(all_max)
