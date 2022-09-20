# https://www.acmicpc.net/problem/2293
# 동전 1

import sys
N, K = map(int, sys.stdin.readline().rstrip().split())
all_cost = []
for i in range(N):
    all_cost.append(int(sys.stdin.readline().rstrip()))

dp_table = [0 for x in range(K+1)]
dp_table[0] = 1
for coin in range(N):
    for cost in range(all_cost[coin], K+1):
        dp_table[cost] += dp_table[cost - all_cost[coin]]

print(dp_table[-1])