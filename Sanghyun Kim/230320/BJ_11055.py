# https://www.acmicpc.net/problem/11055
# 가장 큰 증가하는 부분 수열- BJ_11055

import sys
input = sys.stdin.readline

n = int(input().strip())
a = [int(x) for x in input().split()]
dp = a[:]

for i in range(n):
    for j in range(i):
        if a[i] > a[j]:
            dp[i] = max(dp[i], dp[j] + a[i])    # dp문제

print(max(dp))