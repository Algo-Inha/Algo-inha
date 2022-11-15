# https://www.acmicpc.net/problem/17070
# 파이프 옮기기 1

import sys

N = int(sys.stdin.readline().rstrip())
all_matrix = [list(map(int, sys.stdin.readline().rstrip().split())) for _ in range(N)]
all_dp_table = [[[0, 0, 0] for x in range(N)] for y in range(N)] # 차례대로 오른쪽, 오른쪽아래, 아래 방향으로 옴
all_dp_table[0][1][0] = 1
for y in range(N):
    for x in range(N):
        if x == 0:
            continue
        if all_matrix[y][x] == 1:
            continue
        # 오른쪽
        if x>0: # always true
            if all_matrix[y][x-1] == 0:
                all_dp_table[y][x][0] += all_dp_table[y][x-1][0] + all_dp_table[y][x-1][1]
        # 오른쪽 아래
        if x>0 and y>0:
            if all_matrix[y-1][x-1] == 0 and all_matrix[y][x-1] == 0 and all_matrix[y-1][x] == 0:
                all_dp_table[y][x][1] += all_dp_table[y-1][x-1][0] + all_dp_table[y-1][x-1][1] + all_dp_table[y-1][x-1][2]
        # 아래
        if y>0:
            if all_matrix[y-1][x] == 0:
                all_dp_table[y][x][2] += all_dp_table[y-1][x][1] + all_dp_table[y-1][x][2]
print(sum(all_dp_table[N-1][N-1]))