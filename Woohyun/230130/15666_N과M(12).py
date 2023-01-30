#중복조합 사용

import sys
input = sys.stdin.readline

from itertools import combinations_with_replacement

n, m = map(int,input().split())

li = sorted(set(list(map(int,input().split()))))


for com in combinations_with_replacement(li, m):
        print(*com)