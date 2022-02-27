# https://www.acmicpc.net/problem/17142
# 연구소 3
import sys
from queue import Queue
import itertools

dir_mat = ((0, 1), (1, 0), (0, -1), (-1, 0))
N, M = map(int, sys.stdin.readline().rstrip().split())
orig_map_matrix = []
virus_array = []
for i in range(N):
    tmp_input = list(map(int, sys.stdin.readline().rstrip().split()))
    for ti in range(len(tmp_input)):
        if tmp_input[ti] == 2:
            virus_array.append((i, ti))
    orig_map_matrix.append(tmp_input)

comb_virus = [i for i in range(len(virus_array))]
comb_iter = itertools.combinations(comb_virus, M)
overall_output = -1
for ci in comb_iter:
    map_matrix = [[orig_map_matrix[j][i] for i in range(N)]for j in range(N)]
    now_step = 0
    virus_queue = Queue()
    for i in ci:
        virus_queue.put(virus_array[i])
        map_matrix[virus_array[i][0]][virus_array[i][1]] = 3
    while virus_queue.qsize() != 0:
        tmp_queue_size = virus_queue.qsize()
        for tqs in range(tmp_queue_size):
            tmp_virus_queue = virus_queue.get()
            for i in range(4):
                tmp_y = dir_mat[i][0] + tmp_virus_queue[0]
                tmp_x = dir_mat[i][1] + tmp_virus_queue[1]
                if 0 <= tmp_y < N and 0 <= tmp_x < N:
                    if map_matrix[tmp_y][tmp_x] == 0:
                        map_matrix[tmp_y][tmp_x] = 3
                        virus_queue.put((tmp_y, tmp_x))
                    elif map_matrix[tmp_y][tmp_x] == 2:
                        map_matrix[tmp_y][tmp_x] = 3
                        tmp_virus_immediate_queue = Queue()
                        tmp_virus_immediate_queue.put((tmp_y,tmp_x))
                        while tmp_virus_immediate_queue.qsize()>0:
                            tmp_get_virus = tmp_virus_immediate_queue.get()
                            for ii in range(4):
                                tmp_yy = dir_mat[ii][0] + tmp_get_virus[0]
                                tmp_xx = dir_mat[ii][1] + tmp_get_virus[1]
                                if 0 <= tmp_yy < N and 0 <= tmp_xx < N:
                                    if map_matrix[tmp_yy][tmp_xx] == 2:
                                        tmp_virus_immediate_queue.put((tmp_yy, tmp_xx))
                                        map_matrix[tmp_yy][tmp_xx] = 3
        now_step += 1
    for i in range(N):
        for j in range(N):
            if map_matrix[i][j] == 0:
                now_step = -1
                break
        if now_step == -1:
            break

    if overall_output == -1:
        overall_output = now_step
    else:
        if overall_output > now_step != -1:
            overall_output = now_step

if overall_output>0:
    overall_output -= 1
print(overall_output)


