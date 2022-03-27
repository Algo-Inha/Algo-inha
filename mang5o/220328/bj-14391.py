# https://www.acmicpc.net/problem/14391
# 종이조각
import sys
from collections import deque
N, M = map(int, sys.stdin.readline().rstrip().split())
map_matrix = []
for i in range(N):
    now_line = sys.stdin.readline().rstrip()
    now_line_arr = []
    for j in now_line:
        now_line_arr.append(int(j))
    map_matrix.append(now_line_arr)
now_search_deque = deque()
now_search_deque.append([map_matrix,0])
max_cost = 0
while len(now_search_deque)>0:
    tmp_search_elem = now_search_deque.pop()
    tmp_map = tmp_search_elem[0]
    tmp_cost = tmp_search_elem[1]
    all_flag = True
    min_y = -1
    min_x = -1
    for y in range(N):
        for x in range(M):
            if tmp_map[y][x] > 0:
                all_flag = False
                if min_y == -1 or min_y >= y:  # 시간절약부분
                    min_y = y
                    # 아래로 쭉
                    now_tmp_map = [[tmp_map[i][j] for j in range(M)] for i in range(N)]
                    now_str = ""
                    tmp_y = y
                    tmp_x = x
                    while tmp_y < N and now_tmp_map[tmp_y][tmp_x] >= 0:
                        now_str += str(now_tmp_map[tmp_y][tmp_x])
                        now_tmp_map[tmp_y][tmp_x] = -1
                        tmp_y += 1
                    now_search_deque.append([now_tmp_map, tmp_cost + int(now_str)])
                if min_x == -1 or min_x >= x:  # 시간절약부분
                    min_x = x
                    # start : {y,x}
                    # 오른쪽으로 쭉
                    now_tmp_map = [[tmp_map[i][j] for j in range(M)] for i in range(N)]
                    now_str = ""
                    tmp_y = y
                    tmp_x = x
                    while tmp_x < M and now_tmp_map[tmp_y][tmp_x] >= 0:
                        now_str += str(now_tmp_map[tmp_y][tmp_x])
                        now_tmp_map[tmp_y][tmp_x] = -1
                        tmp_x += 1
                    now_search_deque.append([now_tmp_map, tmp_cost + int(now_str)])
    if all_flag:
        max_cost = max(max_cost, tmp_cost)
print(max_cost)

