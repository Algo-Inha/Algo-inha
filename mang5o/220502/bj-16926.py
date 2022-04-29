# https://www.acmicpc.net/problem/16926
# 배열 돌리기

import sys
N, M, R = map(int, sys.stdin.readline().rstrip().split())
all_map = []
for i in range(N):
    tmp_line = list(map(int, sys.stdin.readline().rstrip().split()))
    all_map.append(tmp_line)

for rotate_idx in range(R):
    start_y = 0
    end_y = N-1
    start_x = 0
    end_x = M-1
    while True:
        # Rotate
        left_top = all_map[start_y][start_x]
        for dir_idx in range(4):
            # now rotate to [start_y, start_x, end_y, end_x]
            if dir_idx == 0:
                for tmp_x in range(start_x, end_x):
                    all_map[start_y][tmp_x] = all_map[start_y][tmp_x + 1]
            elif dir_idx == 1:
                for tmp_y in range(start_y, end_y):
                    all_map[tmp_y][end_x] = all_map[tmp_y + 1][end_x]
            elif dir_idx == 2:
                for tmp_x in range(end_x-start_x):
                    tmp_tmp_x = end_x - tmp_x
                    all_map[end_y][tmp_tmp_x] = all_map[end_y][tmp_tmp_x-1]
            else:
                for tmp_y in range(end_y-start_y):
                    tmp_tmp_y = end_y - tmp_y
                    all_map[tmp_tmp_y][start_x] = all_map[tmp_tmp_y-1][start_x]
        all_map[start_y + 1][start_x] = left_top
        # move cursor
        start_y += 1
        end_y   -= 1
        start_x += 1
        end_x   -= 1
        if start_y>=end_y or start_x>=end_x:
            break

for y in range(N):
    tmp_str = ""
    for x in range(M):
        tmp_str += str(all_map[y][x])
        if x != M-1:
            tmp_str += " "
    print(tmp_str)