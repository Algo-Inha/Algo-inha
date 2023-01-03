# https://www.acmicpc.net/problem/1012
# 유기농 배추

import sys
from collections import deque
T = int(sys.stdin.readline().rstrip())
dir_matrix = (
    (0,-1), (0,1), (1,0), (-1,0)
)
all_result = []
for i in range(T):
    M, N, K = map(int, sys.stdin.readline().rstrip().split())
    all_map = [[0 for x in range(M)] for y in range(N)]
    for cab in range(K):
        tmp_inp = list(map(int, sys.stdin.readline().rstrip().split()))
        all_map[tmp_inp[1]][tmp_inp[0]] = 1
    all_cluster = 0
    for y in range(N):
        for x in range(M):
            if all_map[y][x] == 1:
                all_cluster += 1
                tmp_deque = deque()
                tmp_deque.append((y,x))
                while tmp_deque:
                    pop_elem = tmp_deque.popleft()
                    for dir_idx in range(4):
                        tmp_y = pop_elem[0] + dir_matrix[dir_idx][0]
                        tmp_x = pop_elem[1] + dir_matrix[dir_idx][1]
                        if 0<=tmp_y<N and 0<=tmp_x<M:
                            if all_map[tmp_y][tmp_x] == 1:
                                tmp_deque.append((tmp_y, tmp_x))
                                all_map[tmp_y][tmp_x] = 0
    all_result.append(all_cluster)

for result in all_result:
    print(result)