# https://www.acmicpc.net/problem/1245
# 농장 관리
# 이게 무슨소리니

import sys
from collections import deque
# dir_matrix = [[1,0],[1,1],[1,-1],[0,-1],[0,1],[-1,-1],[-1,0],[-1,1]]
dir_matrix = [[1,0],[0,-1],[0,1],[-1,0]]
N, M = map(int, sys.stdin.readline().rstrip().split())
all_matrix = [list(map(int, sys.stdin.readline().rstrip().split())) for _ in range(N)]

all_figs = 0
for yy in range(N):
    for xx in range(M):
        if all_matrix[yy][xx] != 0:
            all_figs += 1
            all_matrix[yy][xx] = 0
            tmp_deque = deque()
            tmp_deque.append([yy,xx])
            while tmp_deque:
                tmp_elem = tmp_deque.popleft()
                for dir_idx in range(len(dir_matrix)):
                    tmp_yy = tmp_elem[0] + dir_matrix[dir_idx][0]
                    tmp_xx = tmp_elem[1] + dir_matrix[dir_idx][1]
                    if 0 <= tmp_yy < N and 0 <= tmp_xx < M:
                        if all_matrix[tmp_yy][tmp_xx] != 0:
                            all_matrix[tmp_yy][tmp_xx] = 0
                            tmp_deque.append([tmp_yy, tmp_xx])

print(all_figs)