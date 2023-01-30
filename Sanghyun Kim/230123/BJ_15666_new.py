# https://www.acmicpc.net/problem/15666
# N과 M (12)- BJ_15666

from itertools import combinations_with_replacement
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
nLi = list(set(list(map(int, input().split()))))
nLi.sort()

ans = list(set(list(combinations_with_replacement(nLi, m))))
for i in reversed(range(m)):
    ans.sort(key=lambda x:x[i])

for i in range(len(ans)):
    print(*ans[i])