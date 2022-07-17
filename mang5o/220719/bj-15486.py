# 퇴사2
# https://www.acmicpc.net/problem/15486

import sys
N = int(sys.stdin.readline().rstrip())
all_list = []
for i in range(N):
    tmp_elem = list(map(int, sys.stdin.readline().rstrip().split()))
    tmp_elem.append(0)
    all_list.append(tmp_elem)
all_list.append([0,0,0])

max_value = 0 # 최대 이익

for i in range(N):
    now_cost = all_list[i][2]
    max_cost = now_cost + all_list[i][1]
    for j in range(all_list[i][0]):
        if i + j <= N:
            all_list[i+j][2] = max(now_cost, all_list[i+j][2])
            max_value = max(max_value,all_list[i+j][2])
    if all_list[i][0] + i <= N:
        all_list[all_list[i][0] + i][2] = max(all_list[all_list[i][0] + i][2], max_cost)
        max_value = max(max_value,all_list[all_list[i][0] + i][2])

print(max_value)