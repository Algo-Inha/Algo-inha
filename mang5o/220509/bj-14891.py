# 톱니바퀴
# https://www.acmicpc.net/problem/14891

import sys
all_map = []
for i in range(4):
    tmp_map = sys.stdin.readline().rstrip()
    tmp_list = []
    for j in range(8):
        tmp_list.append(int(tmp_map[j]))
    all_map.append(tmp_list)
N = int(sys.stdin.readline().rstrip())
all_rotate = []
for i in range(N):
    all_rotate.append(list(map(int, sys.stdin.readline().rstrip().split())))

left_right = [[6,2],[6,2],[6,2],[6,2]]

for i in range(N):
    # print("*"*10)
    start_gear = all_rotate[i][0]-1
    clockwise = all_rotate[i][1]
    tmp_rotate = [999,999,999,999]
    tmp_rotate[start_gear] = clockwise
    for j in range(start_gear):
        now_gear = start_gear-j-1
        # print("now_gear1 : {}".format(now_gear))
        if all_map[now_gear][left_right[now_gear][1]] != all_map[now_gear + 1][left_right[now_gear+1][0]]:
            tmp_rotate[now_gear] = tmp_rotate[now_gear+1] * (-1)
        else:
            tmp_rotate[now_gear] = 0
    for j in range(start_gear+1, 4):
        now_gear = j
        # print("now_gear2 : {}".format(now_gear))
        if all_map[now_gear][left_right[now_gear][0]] != all_map[now_gear-1][left_right[now_gear-1][1]]:
            tmp_rotate[now_gear] = tmp_rotate[now_gear - 1] * (-1)
        else:
            tmp_rotate[now_gear] = 0
    for j in range(4):
        left_right[j][0] -= tmp_rotate[j]
        left_right[j][1] -= tmp_rotate[j]
        left_right[j][0] = left_right[j][0] % 8
        left_right[j][1] = left_right[j][1] % 8
    # print(tmp_rotate)

score = 0
if all_map[0][(left_right[0][0]+2)%8] == 1:
    score += 1
if all_map[1][(left_right[1][0]+2)%8] == 1:
    score += 2
if all_map[2][(left_right[2][0]+2)%8] == 1:
    score += 4
if all_map[3][(left_right[3][0]+2)%8] == 1:
    score += 8

print(score)