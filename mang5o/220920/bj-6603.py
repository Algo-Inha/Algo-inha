# https://www.acmicpc.net/problem/6603
# 로또
import sys
import itertools


all_query = []
while True:
    inp_str = sys.stdin.readline().rstrip().split()
    if inp_str[0] == '0':
        break
    all_query.append(inp_str[1:])

for query in range(len(all_query)):
    comb = itertools.combinations(all_query[query], 6)
    for case in comb:
        print(" ".join(case))
    if query < len(all_query) - 1:
        print("")