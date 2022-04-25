# https://www.acmicpc.net/problem/3184
# 양

import sys
from collections import deque

dir_matrix = ((0, 1), (0, -1), (1, 0), (-1, 0))
R, C = map(int, sys.stdin.readline().rstrip().split())
map_matrix = []
for i in range(R):
    map_matrix.append(
        list(  # input parsing
            map(int,
                sys.stdin.readline().rstrip()
                .replace(".", " 0")
                .replace("#", " 1")
                .replace("o", " 2")
                .replace("v", " 3")[1:]
                .split())))
visited_matrix = [[False for x in range(C)] for y in range(R)]  # Make visited

now_sheep = 0
now_wolves = 0
for y in range(R):
    for x in range(C):
        if not visited_matrix[y][x] and map_matrix[y][x] != 1:
            grouping_deque = deque()
            grouping_deque.append((y, x))
            tmp_sheep = 0
            tmp_wolves = 0
            now_boundary = False
            while len(grouping_deque) > 0:
                tmp_yx = grouping_deque.popleft()
                if visited_matrix[tmp_yx[0]][tmp_yx[1]]:
                    continue  # 중복처리 (visited를 설정하는 시점 문제)
                if tmp_yx[0] == 0 or tmp_yx[0] == R - 1 or tmp_yx[1] == 0 or tmp_yx[1] == C - 1:
                    now_boundary = True
                    break
                visited_matrix[tmp_yx[0]][tmp_yx[1]] = True
                if map_matrix[tmp_yx[0]][tmp_yx[1]] == 2:
                    tmp_sheep += 1
                elif map_matrix[tmp_yx[0]][tmp_yx[1]] == 3:
                    tmp_wolves += 1
                for dir_idx in range(4):
                    tmp_y = tmp_yx[0] + dir_matrix[dir_idx][0]
                    tmp_x = tmp_yx[1] + dir_matrix[dir_idx][1]
                    if 0 <= tmp_y < R and 0 <= tmp_x < C:
                        if map_matrix[tmp_y][tmp_x] != 1 and not visited_matrix[tmp_y][tmp_x]:
                            grouping_deque.append((tmp_y, tmp_x))
            if not now_boundary:
                # print("Sheep : {}, Wolves : {}".format(tmp_sheep, tmp_wolves))
                if tmp_sheep > tmp_wolves:
                    now_sheep += tmp_sheep
                else:
                    now_wolves += tmp_wolves

print("{} {}".format(now_sheep, now_wolves))
