# https://www.acmicpc.net/problem/2206
# 벽 부수고 이동하기
import sys
from queue import Queue

dir_matrix = ((0, 1), (0, -1), (1, 0), (-1, 0))
N, M = map(int, sys.stdin.readline().rstrip().split())
map_input = {}
for i in range(N):
    tmp_input = sys.stdin.readline().rstrip()
    tmp_arr = {}
    for j in range(len(tmp_input)):
        tmp_arr[j] = int(tmp_input[j])
    map_input[i] = tmp_arr

visited_matrix = {}
for j in range(N):
    tmp_dict = {}
    for i in range(M):
        tmp_dict[i] = [False, False]
    visited_matrix[j] = tmp_dict

visited_matrix[0][0] = [True, True]
bfs_queue = Queue()
bfs_queue.put([0, 0, 0])  # y행, x열, 현재 벽 넘어간 수
now_step = 2 # 시작 및 끝 포함
end_flag = False
while bfs_queue.qsize() != 0:
    now_stage = bfs_queue.qsize()
    for i in range(now_stage):
        tmp_queue_elem = bfs_queue.get()
        for dir_fig in range(4):
            tmp_y = tmp_queue_elem[0] + dir_matrix[dir_fig][0]
            tmp_x = tmp_queue_elem[1] + dir_matrix[dir_fig][1]
            if 0 <= tmp_y < N and 0 <= tmp_x < M:
                if tmp_y == N - 1 and tmp_x == M - 1:
                    end_flag = True
                    break
                elif tmp_queue_elem[2] == 0:
                    if map_input[tmp_y][tmp_x] == 0:
                        if not visited_matrix[tmp_y][tmp_x][0]:
                            visited_matrix[tmp_y][tmp_x][0] = True
                            bfs_queue.put([tmp_y, tmp_x, 0])
                    if map_input[tmp_y][tmp_x] == 1:
                        if not visited_matrix[tmp_y][tmp_x][1]:
                            visited_matrix[tmp_y][tmp_x][1] = True
                            bfs_queue.put([tmp_y, tmp_x, 1])
                else: # 벽을 뚫은 상태
                    if map_input[tmp_y][tmp_x] == 0:
                        if visited_matrix[tmp_y][tmp_x][0]:  # 벽을 뚫었는데 안뚫은게 이미 도착했다면 확인 불필요
                            continue
                        if not visited_matrix[tmp_y][tmp_x][1]:
                            visited_matrix[tmp_y][tmp_x][1] = True
                            bfs_queue.put([tmp_y, tmp_x, 1])
        if end_flag:
            break
    if end_flag:
        break
    now_step += 1

if end_flag:
    print(now_step)
else:
    print("-1")
