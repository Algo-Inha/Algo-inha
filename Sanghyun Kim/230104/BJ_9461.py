# https://www.acmicpc.net/problem/9461
# 파도반 수열- BJ_9461

import sys
input = sys.stdin.readline

nCase = [0 for _ in range(101)]
nCase[1] = 1
nCase[2] = 1
nCase[3] = 1
nCase[4] = 2
nCase[5] = 2
for i in range(6, len(nCase)):
    nCase[i] = nCase[i - 1] + nCase[i - 5]

t = int(input())
for _ in range(t):
    print(nCase[int(input())])