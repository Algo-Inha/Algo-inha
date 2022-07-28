# https://www.acmicpc.net/problem/2133
# 타일 채우기

# 점화식 : dp[n] = dp[2]*dp[n-2] + 2*dp[n-4] + 2*dp[n-6] + ... + 2*dp[2] + 2

n = int(input())

dp=[0]*31
dp[2]=3

for i in range(4,n+1,2):
    dp[i] = dp[2] * dp[i-2]
    for j in range(4,i,2):
        dp[i] += 2 * dp[i-j]
    dp[i] += 2

print(dp[n])