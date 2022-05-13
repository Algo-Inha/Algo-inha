# https://www.acmicpc.net/problem/2163
# 초콜릿 자르기

import sys
N, M = map(int, sys.stdin.readline().rstrip().split())
print(N-1 + N*(M-1))