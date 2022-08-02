# https://www.acmicpc.net/problem/1931
# 회의실 배정

import sys
N = int(sys.stdin.readline().rstrip())
all_meet = []
for i in range(N):
    all_meet.append(list(map(int, sys.stdin.readline().rstrip().split())))



# Make output
all_meet.sort(key = lambda x : float(x[0]) + (x[1] - x[0])/1000000)
all_meet.sort(key = lambda x : x[1])
now_time = 0
now_idx = 0
now_meet = 0
while now_idx < len(all_meet):
    if now_time <= all_meet[now_idx][0]:
        now_time = all_meet[now_idx][1]
        now_idx += 1
        now_meet += 1
    else:
        now_idx += 1

print(now_meet)