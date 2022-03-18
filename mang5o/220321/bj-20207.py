# 달력
# https://www.acmicpc.net/problem/20207

import sys
N = int(sys.stdin.readline().rstrip())
max_day = 0
schedules = []
for i in range(N):
    S, E = map(int, sys.stdin.readline().rstrip().split())
    max_day = max(E + 1, max_day)
    schedules.append([S, E])
schedules.sort(key=lambda x: x[0] * 366 + -x[1] + x[0])

schedule_matrix = [[False for i in range(max_day + 1)] for j in range(N)]
for sche in schedules:
    for y in range(N):
        now_can = True
        for x in range(sche[0], sche[1] + 1):
            if schedule_matrix[y][x]:
                now_can = False
                break
        if now_can:
            for x in range(sche[0], sche[1] + 1):
                schedule_matrix[y][x] = True
            break

schedule_min_max= []
for x in range(max_day + 1):
    min_y = N
    max_y = 0
    flag = False
    for y in range(N):
        if schedule_matrix[y][x]:
            min_y = min(min_y, y)
            max_y = max(max_y, y)
            flag = True
    if flag:
        schedule_min_max.append([min_y,max_y])
    else:
        schedule_min_max.append([-1,-1])
schedule_min_max.append([-1,-1]) # 마지막 점


blocks = []
now_flag = False
tmp_block = []
for x in range(max_day + 1):
    if schedule_min_max[x][0]==-1:
        if now_flag:
            now_flag = False
            tmp_block.sort()
            blocks.append(tmp_block)
            tmp_block = []
    else:
        if not now_flag:
            now_flag = True
            tmp_block.append(schedule_min_max[x][0])
            tmp_block.append(schedule_min_max[x][1])
        else:
            tmp_block.append(schedule_min_max[x][0])
            tmp_block.append(schedule_min_max[x][1])

all_area = 0
for i in range(len(blocks)):
    all_area += (len(blocks[i])//2) * (blocks[i][-1]-blocks[i][0]+1)

print(all_area)