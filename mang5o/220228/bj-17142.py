# https://www.acmicpc.net/problem/17142
# 연구소 3
import sys
from queue import Queue
import itertools

dir_mat = ((0, 1), (1, 0), (0, -1), (-1, 0))
N, M = map(int, sys.stdin.readline().rstrip().split())
now_zero_flag = False
orig_map_matrix = []
virus_array = []
for i in range(N):
    tmp_input = list(map(int, sys.stdin.readline().rstrip().split()))
    for ti in range(len(tmp_input)):
        if tmp_input[ti] == 0:
            now_zero_flag = True
        elif tmp_input[ti] == 2:
            virus_array.append((i, ti))
    orig_map_matrix.append(tmp_input)

virus_fig = len(virus_array)
# time_matrix : 3차원 array (2차원의 MAP 형태에서 Elements가 각 바이러스에 의한 확산속도)
time_matrix = [[[100000 for i in range(virus_fig)] for j in range(N)] for k in range(N)]

if now_zero_flag:
    for i in range(len(virus_array)):
        # 바이러스 하나하나에 의해 몇 시간 만에 퍼지는지에 관해 계산
        tmp_visited_matrix = [[False for i in range(N)] for j in range(N)]  # deep copy
        virus_queue = Queue()
        unactivated_virus_queue = Queue()
        virus_queue.put(virus_array[i])
        tmp_visited_matrix[virus_array[i][0]][virus_array[i][1]] = True
        time_matrix[virus_array[i][0]][virus_array[i][1]][i] = 0
        now_step = 0
        while virus_queue.qsize() != 0:
            now_step += 1
            tmp_virus_len = virus_queue.qsize()
            for j in range(tmp_virus_len):
                tmp_virus_elem = virus_queue.get()
                for dir_elem in range(4):
                    tmp_y = tmp_virus_elem[0] + dir_mat[dir_elem][0]
                    tmp_x = tmp_virus_elem[1] + dir_mat[dir_elem][1]
                    if 0 <= tmp_y < N and 0 <= tmp_x < N:
                        if not tmp_visited_matrix[tmp_y][tmp_x]:
                            if orig_map_matrix[tmp_y][tmp_x] == 0 or orig_map_matrix[tmp_y][tmp_x] == 2:
                                virus_queue.put((tmp_y, tmp_x))
                                tmp_visited_matrix[tmp_y][tmp_x] = True
                                time_matrix[tmp_y][tmp_x][i] = now_step


    min_fig_all = 100000
    now_all_comb = itertools.combinations([i for i in range(virus_fig)], M)
    for nac in now_all_comb:
        tmp_matrix = [[100000 for i in range(N)] for j in range(N)]
        for tmp_y in range(len(time_matrix)):
            for tmp_x in range(len(time_matrix[tmp_y])):
                if orig_map_matrix[tmp_y][tmp_x] == 0:
                    min_fig = 100000
                    for vir_idx in nac:
                        tmp_time = time_matrix[tmp_y][tmp_x][vir_idx]
                        if tmp_time < min_fig:
                            min_fig = tmp_time
                    tmp_matrix[tmp_y][tmp_x] = min_fig
        now_comb_max_time = 0
        for i in range(N):
            for j in range(N):
                if orig_map_matrix[i][j] == 0:
                    tmp_t = time_matrix[i][j]
                    min_tmp_elem = 100000
                    for nc_elem in nac:
                        if tmp_t[nc_elem] < min_tmp_elem:
                            min_tmp_elem = tmp_t[nc_elem]
                    if now_comb_max_time < min_tmp_elem:
                        now_comb_max_time = min_tmp_elem

        if min_fig_all > now_comb_max_time:
            min_fig_all = now_comb_max_time

    if min_fig_all == 100000:
        min_fig_all = -1
    print(min_fig_all)
else:
    print(0)
