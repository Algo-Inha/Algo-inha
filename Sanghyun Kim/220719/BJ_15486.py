# https://www.acmicpc.net/problem/15486
# 퇴사 2

import sys
input = sys.stdin.readline

n = int(input())
t_ = list()
p_ = list()
dp = [0 for _ in range(n + 1)]
total = 0

for _ in range(n):
    t, p = map(int, input().split())
    t_.append(t)
    p_.append(p)

for i in range(n):
    total = max(total, dp[i])
    if i  + t_[i] <= n:
        dp[i + t_[i]] = max(total + p_[i], dp[i + t_[i]])

print(max(dp))