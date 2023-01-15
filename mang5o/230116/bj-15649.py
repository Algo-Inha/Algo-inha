# https://www.acmicpc.net/problem/15649
# N과 M

import sys, itertools
N, M = map(int, sys.stdin.readline().rstrip().split())
perm = itertools.permutations([x+1 for x in range(N)], M)
for i in perm:
    print(str(i).replace("(","").replace(")","").replace(",",""))