# https://www.acmicpc.net/problem/2583
# 영역 구하기

import sys
from collections import deque

M, N, K = map(int, sys.stdin.readline().rstrip().split())
all_matrix = [[False for x in range(N)] for y in range(M)]
for _ in range(K):
    # 위아래로 바뀔 필요없음
    x1, y1, x2, y2 = map(int, sys.stdin.readline().rstrip().split())
    for yy in range(y1, y2):
        for xx in range(x1, x2):
            all_matrix[yy][xx] = True

all_cluster = 0
dir_matrix = [[0,1],[1,0],[0,-1],[-1,0]]
size_arr = []
for yy in range(M):
    for xx in range(N):
        if not all_matrix[yy][xx]:
            all_cluster += 1
            now_area = 1
            graph_deque = deque()
            graph_deque.append([yy,xx])
            all_matrix[yy][xx] = True
            while graph_deque:
                tmp_elem = graph_deque.popleft()
                for dir_idx in range(4):
                    tmp_yy = tmp_elem[0] + dir_matrix[dir_idx][0]
                    tmp_xx = tmp_elem[1] + dir_matrix[dir_idx][1]
                    if 0<=tmp_yy<M and 0<=tmp_xx<N:
                        if not all_matrix[tmp_yy][tmp_xx]:
                            all_matrix[tmp_yy][tmp_xx] = True
                            now_area += 1
                            graph_deque.append([tmp_yy,tmp_xx])
            size_arr.append(now_area)
size_arr.sort()
size_arr = list(map(str, size_arr))
size_print = ' '.join(size_arr)
print(all_cluster)
print(size_print)