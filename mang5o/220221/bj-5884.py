# https://www.acmicpc.net/problem/5884
# 감시카메라
import sys

N = int(sys.stdin.readline().rstrip())
positions = []
for i in range(N):
    cow_x, cow_y = map(int, sys.stdin.readline().rstrip().split())
    positions.append((cow_x, cow_y))  # append with tuples

while_cnt = 0
while while_cnt < 3:
    while_cnt += 1
    max_xy = False  # true : x, false : y
    max_val = 0
    max_idx = 0
    dict_x = {}
    dict_y = {}
    for i in positions:
        if i[0] in dict_x:
            dict_x[i[0]] += 1
        else:
            dict_x[i[0]] = 1
        if dict_x[i[0]] > max_val:
            max_val = dict_x[i[0]]
            max_xy = True
            max_idx = i[0]
        if i[1] in dict_y:
            dict_y[i[1]] += 1
        else:
            dict_y[i[1]] = 1
        if dict_y[i[1]] > max_val:
            max_val = dict_y[i[1]]
            max_xy = False
            max_idx = i[1]
    if max_xy:
        positions = [p_item for p_item in positions if p_item[0]!=max_idx]
    else:
        positions = [p_item for p_item in positions if p_item[1]!=max_idx]
    if len(positions)==0:
        break

if len(positions) == 0:
    print(1)
else:
    print(0)