# https://www.acmicpc.net/problem/17144
# 미세먼지 안녕!

# python3 -> 시간초과
# pypy3   -> 통과 (?)

import sys, math

dir_matrix = ((0, 1), (0, -1), (1, 0), (-1, 0))
R, C, T = map(int, sys.stdin.readline().rstrip().split())
map_matrix = []
tmp_matrix = [[0 for i in range(C)] for j in range(R)]

conditioner = []  # 청정기 y값
for i in range(R):
    tmp_input_list = list(map(int, sys.stdin.readline().rstrip().split()))
    if tmp_input_list[0] == -1:
        conditioner.append(i)
    map_matrix.append(tmp_input_list)

for step in range(T):
    # 미세먼지가 확산된다. 확산은 미세먼지가 있는 모든 칸에서 동시에 일어난다.
    for y in range(R):
        for x in range(C):
            if map_matrix[y][x] != -1:
                tmp_now_dust = map_matrix[y][x]  # 처음 그 곳의 dust
                spread_dust = int(math.floor(tmp_now_dust / 5))  # 퍼지는 양
                tmp_now_dust_diff = 0  # 한 스탭에 그 dust의 변화량
                for i in range(4):
                    tmp_y = y + dir_matrix[i][0]
                    tmp_x = x + dir_matrix[i][1]
                    if 0 <= tmp_y < R and 0 <= tmp_x < C:
                        if map_matrix[tmp_y][tmp_x] != -1:
                            tmp_matrix[tmp_y][tmp_x] += spread_dust
                            tmp_now_dust_diff -= spread_dust
                tmp_matrix[y][x] += tmp_now_dust_diff
    for y in range(R):
        for x in range(C):
            if map_matrix[y][x] != -1:
                map_matrix[y][x] += tmp_matrix[y][x]
                tmp_matrix[y][x] = 0

    # print("AFTER diffuse" + "=" * 10)
    # for y in range(R):
    #     print(map_matrix[y])

    # 공기청정기가 작동한다.
    # stable하게 matrix를 사용하기 위해선 공기청정기로 들어가는 부분부터 역순으로 들어가는게 필요함

    # upper circular cycle
    for tmp_y in range(1, conditioner[0]):
        now_y = conditioner[0] - tmp_y
        map_matrix[now_y][0] = map_matrix[now_y - 1][0]
    for tmp_x in range(C - 1):
        map_matrix[0][tmp_x] = map_matrix[0][tmp_x + 1]
    for tmp_y in range(conditioner[0]):
        map_matrix[tmp_y][C - 1] = map_matrix[tmp_y + 1][C - 1]
    for tmp_x in range(C - 2):
        now_x = C - tmp_x - 1
        map_matrix[conditioner[0]][now_x] = map_matrix[conditioner[0]][now_x - 1]
    map_matrix[conditioner[0]][0] = -1
    map_matrix[conditioner[0]][1] = 0

    # lower circular cycle
    for tmp_y in range(conditioner[1] + 1, R - 1):
        map_matrix[tmp_y][0] = map_matrix[tmp_y + 1][0]
    for tmp_x in range(C - 1):
        map_matrix[R - 1][tmp_x] = map_matrix[R - 1][tmp_x + 1]
    for tmp_y in range(R - conditioner[1] - 1):
        now_y = R - tmp_y - 1
        map_matrix[now_y][C - 1] = map_matrix[now_y - 1][C - 1]
    for tmp_x in range(C - 2):
        now_x = C - tmp_x - 1
        map_matrix[conditioner[1]][now_x] = map_matrix[conditioner[1]][now_x - 1]
    map_matrix[conditioner[1]][0] = -1
    map_matrix[conditioner[1]][1] = 0

    # print("After moving" + "="*10)
    # for y in range(R):
    #     print(map_matrix[y])

all_dust = 0
map_matrix[conditioner[0]][0] = 0
map_matrix[conditioner[1]][0] = 0
for y in range(R):
    for x in range(C):
        all_dust += map_matrix[y][x]

print(all_dust)
