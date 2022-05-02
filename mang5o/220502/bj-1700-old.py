# https://www.acmicpc.net/problem/1700
# 멀티탭 스케줄링

import sys
from collections import deque
N, K = map(int, sys.stdin.readline().rstrip().split())
all_schedule = list(map(int, sys.stdin.readline().rstrip().split()))
schedule_map = dict()

max_device = 0
min_device = 100
for idx in range(K):
    max_device = max(all_schedule[idx], max_device)
    min_device = min(all_schedule[idx], min_device)
max_device -= min_device
for schedule in range(K):
    all_schedule[schedule] -= min_device

# 0번 device 부터 max_device 번 까지의 device
# deque => element => [현재 schedule idx, 현재 꼽혀있는 장치에 대한 list]
all_deque = deque()
all_deque.append([0, [all_schedule[0]], 0])
min_change = 999999999999999
while len(all_deque) > 0:
    tmp_elem = all_deque.pop()
    # print(tmp_elem)
    now_idx = tmp_elem[0] + 1
    if now_idx == K:
        min_change = min(min_change, tmp_elem[2])
        continue
    now_tab = tmp_elem[1]
    now_change = tmp_elem[2]
    if all_schedule[now_idx] in now_tab:
        all_deque.append([now_idx, now_tab, now_change])
    else:
        if len(now_tab) < N:
            now_tab.append(all_schedule[now_idx])
            all_deque.append([now_idx, now_tab, now_change])
        else:
            for dev in range(N):
                tmp_tab = [now_tab[x] for x in range(N)]
                tmp_tab[dev] = all_schedule[now_idx]
                all_deque.append([now_idx, tmp_tab, now_change + 1])
print(min_change)