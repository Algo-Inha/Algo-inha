# https://www.acmicpc.net/problem/2096
# 내려가기

import sys
N = int(sys.stdin.readline().rstrip())
now_line = list(map(int, sys.stdin.readline().rstrip().split()))
min_dp = [now_line[x] for x in range(3)]
max_dp = [now_line[x] for x in range(3)]
for i in range(N-1):
    now_line = list(map(int, sys.stdin.readline().rstrip().split()))
    min_dp_tmp = [
        min(min_dp[0], min_dp[1]) + now_line[0],
        min(min_dp[0], min_dp[1], min_dp[2]) + now_line[1],
        min(min_dp[1], min_dp[2]) + now_line[2]
    ]
    max_dp_tmp = [
        max(max_dp[0], max_dp[1]) + now_line[0],
        max(max_dp[0], max_dp[1], max_dp[2]) + now_line[1],
        max(max_dp[1], max_dp[2]) + now_line[2]
    ]
    min_dp = min_dp_tmp
    max_dp = max_dp_tmp
print("{} {}".format(max(max_dp), min(min_dp)))