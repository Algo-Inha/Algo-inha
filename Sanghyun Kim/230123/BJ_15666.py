# https://www.acmicpc.net/problem/15666
# N과 M (12)- BJ_15666

from itertools import combinations
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
nLi = list(set(list(map(int, input().split()))))
nLiCopy = nLi.copy()

if m > 1:
    for _ in range(m - 1):
        nLi += nLiCopy      # 메모리 초과 원인 1
nLi.sort()

ans = list(set(list(combinations(nLi, m))))     # 메모리 초과 원인 2
for i in reversed(range(m)):
    ans.sort(key=lambda x:x[i])

for i in range(len(ans)):
    print(*ans[i])