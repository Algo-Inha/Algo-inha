# https://www.acmicpc.net/problem/11055
# 가장 큰 증가하는 부분 수열

import sys

N = int(sys.stdin.readline().rstrip())
all_matrix = list(map(int, sys.stdin.readline().rstrip().split()))
all_dp = [-1 for _ in range(N)]
all_dp[0] = all_matrix[0]

for i in range(1,N):
    max_val = -1
    for j in range(i):
        if max_val < all_dp[j] and all_matrix[i] > all_matrix[j]:
            max_val = all_dp[j]
    if max_val == -1:
        all_dp[i] = all_matrix[i]
    else:
        max_val += all_matrix[i]
        all_dp[i] = max_val

print(max(all_dp))