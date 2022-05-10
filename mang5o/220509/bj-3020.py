# 개똥벌레
# https://www.acmicpc.net/problem/3020

import sys
N, H = map(int, sys.stdin.readline().rstrip().split())
all_disable = []
for i in range(N):
    all_disable.append(int(sys.stdin.readline().rstrip()))
all_map_up = [0 for x in range(H)]
all_map_down = [0 for x in range(H)]
for i in range(N):
    if i%2 == 0:
        all_map_up[H - 1 - (all_disable[i]-1)] += 1
    else:
        all_map_down[H - 1 - (all_disable[i]-1)] += 1

for i in range(H-1):
    all_map_down[i+1] += all_map_down[i]
    all_map_up[i+1] += all_map_up[i]

all_map = [all_map_up[y] + all_map_down[H-y-1] for y in range(H)]
# print(all_map)

min_val = 999999999
min_pos = 0
for i in range(H):
    if min_val > all_map[i]:
        min_val = all_map[i]
        min_pos = 1
    elif min_val == all_map[i]:
        min_pos += 1

print("{} {}".format(min_val, min_pos))
