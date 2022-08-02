# https://www.acmicpc.net/problem/2133
# 타일 채우기

import sys
N = int(sys.stdin.readline().rstrip())

all_mat = [0 for _ in range(max(N+1,3))]
all_mat[0], all_mat[2] = (1, 3)
if N % 2 != 0:
    print(0)
else:
    N_ptr = 3
    while N_ptr < N:
        N_ptr += 1
        all_mat[N_ptr] = all_mat[N_ptr - 2] * 3
        N_sub_ptr = 2
        while N_sub_ptr <= N_ptr:
            N_sub_ptr += 2
            all_mat[N_ptr] += all_mat[N_ptr - N_sub_ptr] * 2
    print(all_mat[N])