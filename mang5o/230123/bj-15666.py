# https://www.acmicpc.net/problem/15666
# N과 M(12)

import sys
from itertools import combinations_with_replacement
N, M = map(int, sys.stdin.readline().rstrip().split())
fig_list = list(map(int, sys.stdin.readline().rstrip().split()))

all_list = set()
for case in combinations_with_replacement(fig_list, M):
    sorted_case = list(case)
    sorted_case.sort()
    for case_idx in range(len(sorted_case)):
        sorted_case[case_idx] = '{0:06d}'.format(sorted_case[case_idx])
    tmp_case = str(sorted_case).replace("(","").replace(")","").replace(" ","")
    if not tmp_case in all_list:
        all_list.add(tmp_case)
all_list = list(all_list)
all_list.sort()
for elem in all_list:
    tmp_replaced = elem.replace("[","").replace("]","").replace("'","")
    tmp_list = list(map(str, map(int, tmp_replaced.split(","))))
    print(' '.join(tmp_list))