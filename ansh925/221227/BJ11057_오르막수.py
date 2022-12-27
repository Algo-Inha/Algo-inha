# https://www.acmicpc.net/problem/11057
# 오르막수

n = int(input())
dp = [1 for i in range(10)]

for i in range(n-1):
    for j in range(10):
        dp[j] = sum(dp[j:])
print(sum(dp) % 10007)