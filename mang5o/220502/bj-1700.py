# https://www.acmicpc.net/problem/1700
# 멀티탭 스케줄링

import sys
N, K = map(int, sys.stdin.readline().rstrip().split())
all_schedule = list(map(int, sys.stdin.readline().rstrip().split()))
schedule_map = dict()

max_device = 0
min_device = 100
for idx in range(K):
    max_device = max(all_schedule[idx], max_device)
    min_device = min(all_schedule[idx], min_device)
max_device -= min_device - 1
for schedule in range(K):
    all_schedule[schedule] -= min_device
# 0번 device 부터 max_device 번 까지의 device
all_schedule_diff = []
for i in range(K-1):
    now_start = i
    now_added = False
    for j in range(i+1, K):
        if all_schedule[i] == all_schedule[j]:
            all_schedule_diff.append([all_schedule[i], j-1])
            now_added = True
            break
    if not now_added:
        all_schedule_diff.append([all_schedule[i], 999])
all_schedule_diff.append([all_schedule[-1], 999])
# print(all_schedule_diff)
all_multitab = [False for i in range(max_device)] # 멀티탭 철자가 이게 맞나
now_multitab = []
now_multitab_with_diff = []
change_fig = 0
for i in range(K):
    # print("\n\n}}")
    tmp_multitab = [now_multitab[x]+min_device for x in range(len(now_multitab))]
    tmp_multitab.append([all_schedule[i] + min_device])
    # print(tmp_multitab)
    if all_schedule[i] in now_multitab:
        # 실수했던 부분
        now_idx = 0
        for sdx in range(len(now_multitab)):
            if now_multitab[sdx] == all_schedule[i]:
                now_idx = sdx
                break
        now_multitab_with_diff[sdx][1] = all_schedule_diff[i][1]
        continue
    else:
        for idx in range(len(now_multitab_with_diff)):
            now_multitab_with_diff[idx][1] -= 1
        if len(now_multitab) < N:
            now_multitab.append(all_schedule[i])
            now_multitab_with_diff.append([all_schedule[i], all_schedule_diff[i][1]])
            all_multitab[all_schedule[i]] = True
        else:
            now_longest_device = -1  # 뺄 장비
            now_longest_slot = -1    # 뺄 콘센트 번호
            now_longest_val = -1
            for now_div in range(N):
                if now_multitab_with_diff[now_div][1] > now_longest_val:
                    now_longest_device = now_multitab[now_div]
                    now_longest_slot = now_div
                    now_longest_val = now_multitab_with_diff[now_div][1]
            # print("뺄 장비, 뺄 콘센트 : {}, {}".format(now_longest_device, now_longest_slot))
            all_multitab[now_longest_device] = False
            all_multitab[all_schedule[i]] = True
            now_multitab[now_longest_slot] = all_schedule_diff[i][0]
            now_multitab_with_diff[now_longest_slot] = all_schedule_diff[i]
            # print("changed >>")
            change_fig += 1
print(change_fig)