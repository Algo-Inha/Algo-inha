# https://www.acmicpc.net/problem/2293
# 동전 1

n,k = map(int,input().split())
cost=[]
for _ in range(n):
    cost.append(int(input()))

dp=[0]*(k+1)
dp[0] = 1
for i in cost:
    for j in range(i, k+1):
        if j - i >= 0:
            dp[j] += dp[j-i]
print(dp[k])