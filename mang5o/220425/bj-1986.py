# https://www.acmicpc.net/problem/1986
# 체스

import sys
# 말의 이동범위
queen_dir = ((-1,-1), (1,-1), (-1,1), (1,1), (0,1), (0,-1), (1,0), (-1,0))
knight_diff = (
    (1,2), (1,-2), (-1,2), (-1,-2), (2,1), (-2,1), (2,-1), (-2,-1)
)
N, M = map(int, sys.stdin.readline().rstrip().split())
map_matrix = [[-1 for i in range(M)] for j in range(N)]  # N이 행인지 N이 열인지 조건이 안주어짐
# -1 = 안전구역, 0 = Queen, 1 = Knight, 2 = Pawn, 3 = 안전하지 않은 구역
for i in range(3):
    tmp_input = list(map(int, sys.stdin.readline().rstrip().split()))
    for j in range(tmp_input[0]):
        map_matrix[tmp_input[2*j + 1] - 1][tmp_input[2*j + 2] - 1] = i
for y in range(N):
    for x in range(M):
        if map_matrix[y][x] == 0:
            for diff in range(8):
                tmp_y = y
                tmp_x = x
                while True:
                    tmp_y += queen_dir[diff][0]
                    tmp_x += queen_dir[diff][1]
                    if 0<=tmp_y<N and 0<=tmp_x<M:
                        if map_matrix[tmp_y][tmp_x] == -1:
                            map_matrix[tmp_y][tmp_x] = 3
                        elif map_matrix[tmp_y][tmp_x] != 3:
                            break
                    else:
                        break
        elif map_matrix[y][x] == 1:
            for diff in range(8):
                tmp_y = y + knight_diff[diff][0]
                tmp_x = x + knight_diff[diff][1]
                if 0<=tmp_y<N and 0<=tmp_x<M:
                    if  map_matrix[tmp_y][tmp_x]==-1:
                        map_matrix[tmp_y][tmp_x] = 3

all_count = 0
for y in range(N):
    for x in range(M):
        if map_matrix[y][x] == -1:
            all_count += 1

print(all_count)