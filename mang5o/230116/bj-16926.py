# https://www.acmicpc.net/problem/16926
# 배열 돌리기 1

import sys

N, M, R = map(int, sys.stdin.readline().rstrip().split())
matrix = [list(map(int, sys.stdin.readline().rstrip().split())) for _ in range(N)]
for rotate in range(R):
    x1, x2, y1, y2 = 0, M - 1, 0, N - 1
    while x1 < x2 and y1 < y2:
        left_top = matrix[y1][x1]
        # upper
        for xx in range(x1, x2):
            matrix[y1][xx] = matrix[y1][xx+1]
        # right
        for yy in range(y1, y2):
            matrix[yy][x2] = matrix[yy+1][x2]
        # lower
        for xx in range(x2 - x1):
            tmp_xx = x2 - xx
            matrix[y2][tmp_xx] = matrix[y2][tmp_xx-1]
        # left
        for yy in range(y2 - y1):
            tmp_yy = y2 - yy
            matrix[tmp_yy][x1] = matrix[tmp_yy-1][x1]
        # left_top
        matrix[y1+1][x1] = left_top
        x1, x2, y1, y2 = x1 + 1, x2 - 1, y1 + 1, y2 - 1
for line in range(N):
    print(' '.join(list(map(str,matrix[line]))))