# https://www.acmicpc.net/problem/11047
# 동전 0- BJ_11047

import sys
input = sys.stdin.readline

n, k = map(int, input().split())
aList = [0 for _ in range(n)]
cnt = 0
for i in reversed(range(n)):
    aList[i] = int(input())

for i in aList:
    if k < i:
        continue
    else:
        cnt += k // i
        k %= i

print(cnt)