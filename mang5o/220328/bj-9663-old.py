# https://www.acmicpc.net/problem/9663
# N-Queen

import itertools
import sys

N = int(sys.stdin.readline().rstrip())
# 모든 퀸은 위에서부터 각 행에 하나씩 존재함
now_perm = itertools.permutations([i for i in range(N)], N)
all_methods = 0
half_flag = N//2
for perm in now_perm:
    if perm[0] >= half_flag:
        continue
    end_flag = False
    for now_pivot in range(N):
        for other_queen in range(N):
            if now_pivot >= other_queen:
                continue
            column_diff = now_pivot - other_queen
            row_diff = perm[now_pivot] - perm[other_queen]
            check_float = column_diff / row_diff
            if check_float == 1 or check_float == -1:
                end_flag = True
                break
        if end_flag:
            break
    if not end_flag:
        all_methods += 1
print(all_methods*2)
