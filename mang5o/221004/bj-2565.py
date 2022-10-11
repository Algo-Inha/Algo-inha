# https://www.acmicpc.net/problem/2565
# 전깃줄

import sys
N = int(sys.stdin.readline().rstrip())
all_line = []
for i in range(N):
    all_line.append(list(map(int, sys.stdin.readline().rstrip().split())))
all_line.sort(key=lambda x:x[0])
all_second = []
for i in range(N):
    all_second.append(all_line[i][1])

LIS_DP = [1]
LIS_list = [all_second[0]]
max_ans = 0
for i in range(1, N):
    LIS_max = 0
    for j in range(i):
        if all_second[j] < all_second[i]:
            LIS_max = max(LIS_max, LIS_DP[j])
    LIS_DP.append(LIS_max + 1)
    max_ans = max(LIS_max + 1, max_ans)

print(N-max_ans)