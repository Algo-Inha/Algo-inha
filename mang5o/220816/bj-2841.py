# https://www.acmicpc.net/problem/2841
# 외계인의 기타 연주

import sys
N, P = map(int, sys.stdin.readline().rstrip().split())
all_querys = []
for i in range(N):
    n, p = map(int, sys.stdin.readline().rstrip().split())
    all_querys.append([n-1,p])
finger_status = [[0], [0], [0], [0], [0], [0]]
movement_fig = 0
for query in all_querys:
    while True:
        if finger_status[query[0]][-1] > query[1]:
            finger_status[query[0]].pop()
            movement_fig += 1
        else:
            break
    if finger_status[query[0]][-1] < query[1]:
        finger_status[query[0]].append(query[1])
        movement_fig += 1
print(movement_fig)