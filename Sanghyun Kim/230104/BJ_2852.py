# https://www.acmicpc.net/problem/2852
# NBA 농구- BJ_2852

import sys
input = sys.stdin.readline

n = int(input())
time_1, time_2 = [0,0], [0,0]
temp = True
cnt_win = 0 # 양수: 1 이길때, 음수: 2 이길때
pres_time = list() # 현재 시간

for _ in range(n):
    win, time = map(str, input().split())
    win = int(win)
    time = list(map(int, time.split(':')))
    if win == 1:
        cnt_win += 1
    elif win == 2:
        cnt_win -= 1
    
    if cnt_win == 1 and win == 1:   # 1이 이기고 있을 경우
        temp = True
        pres_time = time
    elif cnt_win == -1 and win == 2:    # 2가 이기고 있을 경우
        temp = False
        pres_time = time
    elif cnt_win == 0:  # 비기게 될 경우: 이기고 있던 player 시간 계산
        if temp:    # 1이 이겼던 시간 계산
            if time[1] >= pres_time[1]:
                time_1[1] += time[1] - pres_time[1]
            else:
                time_1[1] += time[1] + 60 - pres_time[1]
                time[0] -= 1
            time_1[0] += time[0] - pres_time[0]
            if time_1[1] > 59:
                time_1[0] += time_1[1] % 60
                time_1[1] %= 60

        else:   # 2가 이겼던 시간 계산
            if time[1] >= pres_time[1]:
                time_2[1] = time[1] - pres_time[1]
            else:
                time_2[1] += time[1] + 60 - pres_time[1]
                time[0] -= 1
            time_2[0] += time[0] - pres_time[0]
            if time_2[1] > 59:
                time_2[0] += time_2[1] % 60
                time_2[1] %= 60

if cnt_win != 0:    # 마지막에 무승부 아닐 경우
    time = [48, 0]
    if temp:
        if time[1] >= pres_time[1]:
            time_1[1] += time[1] - pres_time[1]
        else:
            time_1[1] += time[1] + 60 - pres_time[1]
            time[0] -= 1
        time_1[0] += time[0] - pres_time[0]
        if time_1[1] > 59:
            time_1[0] += time_1[1] % 60
            time_1[1] %= 60
    else:
        if time[1] >= pres_time[1]:
            time_2[1] = time[1] - pres_time[1]
        else:
            time_2[1] += time[1] + 60 - pres_time[1]
            time[0] -= 1
        time_2[0] += time[0] - pres_time[0]
        if time_2[1] > 59:
            time_2[0] += time_2[1] % 60
            time_2[1] %= 60

print('{:0>2}:{:0>2}'.format(time_1[0], time_1[1]))
print('{:0>2}:{:0>2}'.format(time_2[0], time_2[1]))