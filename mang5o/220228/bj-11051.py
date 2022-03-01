# https://www.acmicpc.net/problem/11051
# 이항계수 2

# 날먹on (DP x)
import sys
N, K = map(int, sys.stdin.readline().rstrip().split())
if N/2 > float(K):
    K = N-K
up_fig = 1
down_fig = 1
for i in range(K+1,N+1):
    up_fig *= i
for i in range(N-K):
    down_fig *= i+1
print((up_fig//down_fig)%10007)