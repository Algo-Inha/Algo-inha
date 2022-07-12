# https://www.acmicpc.net/problem/11053
# 가장 긴 증가하는 부분수열

import sys

N = int(sys.stdin.readline().rstrip())
all_list = list(map(int, sys.stdin.readline().rstrip().split()))
all_figs = [0 for _ in range(N)]
all_figs[0] = 1

max_count = 0

for i in range(1,N):
    max_fig = 0
    for j in range(i):
        if all_list[j] < all_list[i] and all_figs[j] > max_fig:
            max_fig = all_figs[j]
    all_figs[i] = max_fig + 1

print(max(all_figs))