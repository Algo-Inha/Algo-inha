# https://www.acmicpc.net/problem/20056
# 마법사 상어와 파이어볼

import sys, math

dir_matrix = ((-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1))

N, M, K = map(int, sys.stdin.readline().rstrip().split())
map_matrix = [[list() for i in range(N)] for j in range(N)]
for i in range(M):
    tmp_r, tmp_c, tmp_m, tmp_s, tmp_d = map(int, sys.stdin.readline().rstrip().split())
    tmp_r -= 1
    tmp_c -= 1
    map_matrix[tmp_r][tmp_c].append([tmp_m, tmp_s, tmp_d, 0])

for step in range(K):
    # 스탭 1. d방향대로 이동
    for yy in range(N):
        for xx in range(N):
            for balls in range(len(map_matrix[yy][xx])):
                if map_matrix[yy][xx][balls][3] == step:
                    now_ball_info = map_matrix[yy][xx][balls]
                    now_dir = dir_matrix[now_ball_info[2]]
                    tmp_yy = yy + now_dir[0] * now_ball_info[1]
                    tmp_xx = xx + now_dir[1] * now_ball_info[1]
                    tmp_yy = tmp_yy % N
                    tmp_xx = tmp_xx % N
                    map_matrix[tmp_yy][tmp_xx].append([
                        now_ball_info[0], now_ball_info[1], now_ball_info[2], step + 1
                    ])
            # 그 칸의 현재 스탭 원소 지우기 (뒤부터 지우기)
            tmp_len = len(map_matrix[yy][xx])
            for balls in range(tmp_len):
                tmp_idx = tmp_len - balls - 1
                if map_matrix[yy][xx][tmp_idx][3] == step:
                    del map_matrix[yy][xx][tmp_idx]
    # 스탭 2. 같은 칸에 여러개가 존재할 경우
    for yy in range(N):
        for xx in range(N):
            if len(map_matrix[yy][xx]) > 1:
                tmp_equal_flag = True
                tmp_even = True
                if map_matrix[yy][xx][0][2] % 2 == 1:
                    tmp_even = False
                # 방향 지정
                if tmp_even:
                    for i in map_matrix[yy][xx]:
                        if i[2] % 2 == 1:
                            tmp_equal_flag = False
                            break
                if not tmp_even:
                    for i in map_matrix[yy][xx]:
                        if i[2] % 2 == 0:
                            tmp_equal_flag = False
                            break
                all_m = 0
                all_s = 0
                for i in map_matrix[yy][xx]:
                    all_m += i[0]
                    all_s += i[1]
                all_m = int(math.floor(all_m/5))
                all_s = int(math.floor(all_s/len(map_matrix[yy][xx])))
                if all_m != 0:
                    if tmp_equal_flag:
                        map_matrix[yy][xx] = [[all_m, all_s, dir_tmp, step + 1] for dir_tmp in [0, 2, 4, 6]]
                    else:
                        map_matrix[yy][xx] = [[all_m, all_s, dir_tmp, step + 1] for dir_tmp in [1, 3, 5, 7]]
                else:
                    map_matrix[yy][xx] = []
sum_of_m = 0
for yy in range(N):
    for xx in range(N):
        for i in map_matrix[yy][xx]:
            sum_of_m += i[0]

print(sum_of_m)
