# https://www.acmicpc.net/problem/20058
# 마법사 상어와 파이어스톰

import sys
from collections import deque

dir_matrix = ((0,1),(0,-1),(1,0),(-1,0))
N, Q = map(int, sys.stdin.readline().rstrip().split())
N = 2**N
map_matrix = []
for i in range(N):
    map_matrix.append(list(map(int, sys.stdin.readline().rstrip().split())))
questions = list(map(int, sys.stdin.readline().rstrip().split()))
diff_matrix = [[False for i in range(N)] for j in range(N)]  # True일 경우 녹는다
for firestorm in questions:
    if firestorm != 0:
        # 회전
        tmp_matrix = [[0 for i in range(N)] for j in range(N)]
        now_grid = 2 ** firestorm
        now_y_grid = N//now_grid
        now_x_grid = N//now_grid
        for y_grid in range(now_y_grid):
            for x_grid in range(now_x_grid):
                for y in range(now_grid):
                    for x in range(now_grid):
                        tmp_y = now_grid * y_grid + y
                        tmp_x = now_grid * x_grid + x
                        tmp_rotated_y = now_grid * y_grid + x
                        tmp_rotated_x = now_grid * x_grid + now_grid - 1 - y
                        tmp_matrix[tmp_rotated_y][tmp_rotated_x] = map_matrix[tmp_y][tmp_x]

        map_matrix = tmp_matrix  # shallow copy라 assign에 시간이 오래걸리지 않음

    # 얼음 녹기
    now_all_melted = True
    for y in range(N):
        for x in range(N):
            now_surrounding = 0
            for dir_idx in range(4):
                tmp_y = y + dir_matrix[dir_idx][0]
                tmp_x = x + dir_matrix[dir_idx][1]
                if 0<=tmp_y<N and 0<=tmp_x<N:
                    if map_matrix[tmp_y][tmp_x]>0:
                        now_surrounding += 1
            if now_surrounding<3:
                diff_matrix[y][x] = True
            else:
                diff_matrix[y][x] = False
    for y in range(N):
        for x in range(N):
            if diff_matrix[y][x] and map_matrix[y][x]>0:
                map_matrix[y][x] -= 1
            if map_matrix[y][x] > 0:
                now_all_melted = False
    if now_all_melted:
        break

# 총 얼음량 및 덩어리 구하기
deque_bfs = deque()
visited_matrix = [[False for i in range(N)] for j in range(N)]
for y in range(N):
    for x in range(N):
        if map_matrix[y][x] == 0:
            visited_matrix[y][x] = True

max_area = 0
all_ice = 0
for y in range(N):
    for x in range(N):
        if map_matrix[y][x] != 0 and not visited_matrix[y][x]:
            now_area = 1
            all_ice += map_matrix[y][x]
            deque_bfs.append((y,x))
            visited_matrix[y][x] = True
            while len(deque_bfs) > 0:
                tmp_position = deque_bfs.popleft()
                for dir_idx in range(4):
                    tmp_y = tmp_position[0] + dir_matrix[dir_idx][0]
                    tmp_x = tmp_position[1] + dir_matrix[dir_idx][1]
                    if 0<=tmp_y<N and 0<=tmp_x<N:
                        if not visited_matrix[tmp_y][tmp_x]:
                            visited_matrix[tmp_y][tmp_x] = True
                            deque_bfs.append((tmp_y,tmp_x))
                            all_ice += map_matrix[tmp_y][tmp_x]
                            now_area += 1
            if max_area < now_area:
                max_area = now_area

print(all_ice)
print(max_area)