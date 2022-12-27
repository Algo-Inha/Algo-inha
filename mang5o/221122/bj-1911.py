# https://www.acmicpc.net/problem/1911
# 흙길 보수하기

import sys, math

N, L = map(int, sys.stdin.readline().rstrip().split())
all_case = [list(map(int, sys.stdin.readline().rstrip().split())) for _ in range(N)]
all_case.sort(key=lambda x: x[0])
all_val = 0
final_cursor = 0
for i in range(N):
    final_cursor = max(all_case[i][0], final_cursor)
    if all_case[i][1] > final_cursor:
        diff = all_case[i][1] - final_cursor
        grid = math.ceil(diff/L)
        final_cursor += grid*L
        all_val += grid
print(all_val)