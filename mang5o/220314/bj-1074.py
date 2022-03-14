# https://www.acmicpc.net/problem/1074
# Z
import sys

N, r, c = map(int, sys.stdin.readline().rstrip().split())
now_area = [[0, 2 ** N], [0, 2 ** N]]  # height, width
now_step = 0
while now_area[0][1] - now_area[0][0] > 1:
    tmp_height_width = (now_area[0][1] - now_area[0][0])//2
    tmp_area = [
        [[now_area[0][0], now_area[0][0] + tmp_height_width], [now_area[1][0], now_area[1][0] + tmp_height_width]],
        [[now_area[0][0], now_area[0][0] + tmp_height_width], [now_area[1][0] + tmp_height_width, now_area[1][1]]],
        [[now_area[0][0] + tmp_height_width, now_area[0][1]], [now_area[1][0], now_area[1][0] + tmp_height_width]],
        [[now_area[0][0] + tmp_height_width, now_area[0][1]], [now_area[1][0] + tmp_height_width, now_area[1][1]]]
    ]
    for i in range(4):
        if tmp_area[i][0][0] <= r < tmp_area[i][0][1] and tmp_area[i][1][0] <= c < tmp_area[i][1][1]:
            now_area = tmp_area[i]
            continue_flag = True
            break
        else:
            now_step += tmp_height_width ** 2
if now_area[0][0] == r and now_area[1][0] == c:
    now_step += 0
elif now_area[0][0] == r and now_area[1][1] == c:
    now_step += 1
elif now_area[0][1] == r and now_area[1][0] == c:
    now_step += 2
elif now_area[0][1] == r and now_area[1][1] == c:
    now_step += 3

print(now_step)