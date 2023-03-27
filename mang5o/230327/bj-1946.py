# https://www.acmicpc.net/problem/1946
# 신입 사원

import sys
T = int(sys.stdin.readline().rstrip())
all_figs = []
for i in range(T):
    N = int(sys.stdin.readline().rstrip())
    all_people = [list(map(int, sys.stdin.readline().rstrip().split())) for _ in range(N)]
    all_people.sort(key = lambda x : x[0])
    fig = 0
    min_2nd = 999999
    for ii in range(N):
        if min_2nd > all_people[ii][1]:
            min_2nd = all_people[ii][1]
            fig += 1
    all_figs.append(fig)
for i in range(T):
    print(all_figs[i])