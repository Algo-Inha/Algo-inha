# https://www.acmicpc.net/problem/2206
# 벽 부수고 이동하기

# Queue->deque로 바꾸고 타임리밋 통과
import sys
from collections import deque

dir_matrix = ((0, 1), (0, -1), (1, 0), (-1, 0))
N, M = map(int, sys.stdin.readline().rstrip().split())
map_input = []
for i in range(N):
    map_input.append(list(map(int, sys.stdin.readline().rstrip()[::1])))

if N == 1 and M == 1:
    print(1)
else:
    visited_matrix = [[[1000000, 1000000] for i in range(M)] for j in range(N)]
    visited_matrix[0][0] = [1, 1]
    bfs_queue = deque()
    bfs_queue.append((0, 0, 0))  # y행, x열, 현재 벽 넘어간 수
    now_step = 2  # 시작 및 끝 포함
    end_flag = False
    while len(bfs_queue) != 0:
        now_stage = len(bfs_queue)
        for i in range(now_stage):
            tmp_queue_elem = bfs_queue.popleft()
            for dir_fig in range(4):
                tmp_y = tmp_queue_elem[0] + dir_matrix[dir_fig][0]
                tmp_x = tmp_queue_elem[1] + dir_matrix[dir_fig][1]
                if 0 <= tmp_y < N and 0 <= tmp_x < M:
                    if tmp_y == N - 1 and tmp_x == M - 1:
                        end_flag = True
                        break
                    elif map_input[tmp_y][tmp_x] == 0:
                        if visited_matrix[tmp_y][tmp_x][tmp_queue_elem[2]] > now_step:
                            visited_matrix[tmp_y][tmp_x][tmp_queue_elem[2]] = now_step
                            bfs_queue.append((tmp_y, tmp_x, tmp_queue_elem[2]))
                    else:
                        if visited_matrix[tmp_y][tmp_x][1] > now_step and tmp_queue_elem[2] == 0:
                            visited_matrix[tmp_y][tmp_x][1] = now_step
                            bfs_queue.append((tmp_y, tmp_x, 1))
            if end_flag:
                break
        if end_flag:
            break
        now_step += 1

    if end_flag:
        print(now_step)
    else:
        print(-1)
