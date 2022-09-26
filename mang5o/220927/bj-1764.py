# https://www.acmicpc.net/problem/1764
# 듣보잡

import sys
N, M = map(int, sys.stdin.readline().rstrip().split())
N_set, M_set = set(), set()
for _ in range(N):
    N_set.add(sys.stdin.readline().rstrip())
for _ in range(M):
    M_set.add(sys.stdin.readline().rstrip())
union = list(N_set & M_set)
union.sort()

print(len(union))
for name in union:
    print(name)