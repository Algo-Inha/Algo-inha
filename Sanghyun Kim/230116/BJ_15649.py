# https://www.acmicpc.net/problem/15649
# N과 M (1)- BJ_15649

from itertools import permutations
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
li = permutations(range(n), m)

for i in li:
    for j in i:
        print(j + 1, end=' ')
    print()