import sys
input = sys.stdin.readline

n = int(input())
A = list(map(int, input().split()))


dp = [0] * n 


dp[0] = A[0]
print(dp)
# DP
for i in range(1, n):
    for j in range(i):
        if A[j] < A[i] and dp[j] > dp[i]:
            dp[i] = dp[j] 
    dp[i] += A[i]


print(max(dp)) 