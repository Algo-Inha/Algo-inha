# https://www.acmicpc.net/problem/3085
# 사탕 게임

import sys

N = int(sys.stdin.readline().rstrip())
all_matrix = [list(sys.stdin.readline().rstrip()) for i in range(N)]
dir_matrix = (
    (1,0), (0,1)
)

max_val = 0
for y in range(N):
    for x in range(N):
        for dir_idx in range(len(dir_matrix)):
            tmp_y = y + dir_matrix[dir_idx][0]
            tmp_x = x + dir_matrix[dir_idx][1]
            if tmp_y == N or tmp_x == N:
                continue
            if all_matrix[y][x] != all_matrix[tmp_y][tmp_x]:
                all_matrix[y][x], all_matrix[tmp_y][tmp_x] = all_matrix[tmp_y][tmp_x], all_matrix[y][x]
                # Calc Max Val
                for now_y in range(N): # 가로로 이동하며 체크
                    tmp_val = "-1"
                    tmp_same = 0
                    for now_x in range(N):
                        if all_matrix[now_y][now_x] == tmp_val:
                            tmp_same += 1
                            max_val = max(max_val, tmp_same)
                        else:
                            tmp_val = all_matrix[now_y][now_x]
                            tmp_same = 1
                for now_x in range(N):
                    tmp_val = "-1"
                    tmp_same = 0
                    for now_y in range(N):
                        if all_matrix[now_y][now_x] == tmp_val:
                            tmp_same += 1
                            max_val = max(max_val, tmp_same)
                        else:
                            tmp_val = all_matrix[now_y][now_x]
                            tmp_same = 1
                all_matrix[y][x], all_matrix[tmp_y][tmp_x] = all_matrix[tmp_y][tmp_x], all_matrix[y][x]

print(max_val)