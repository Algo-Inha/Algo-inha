# https://www.acmicpc.net/problem/5884
# 감시카메라 - 타임아웃
import sys

N = int(sys.stdin.readline().rstrip())
positions = []
for i in range(N):
    cow_x, cow_y = map(int, sys.stdin.readline().rstrip().split())
    positions.append((cow_x, cow_y))  # append with tuples

position_xy = [False for i in range(N)]  # if false : x_camera
end_flag = False
min_cam = False
while True:
    set_x = set()
    set_y = set()
    for i in range(N):
        if position_xy[i]:
            set_x.add(positions[i][0])
        else:
            set_y.add(positions[i][1])
    now_cam = len(set_x) + len(set_y)
    if now_cam <= 3:
        min_cam = True
        break

    # next step
    for idx in range(N):
        if idx == (N - 1) and position_xy[idx]:
            end_flag = True
            break
        if not position_xy[idx]:
            position_xy[idx] = True
            break
        else:
            position_xy[idx] = False
    if end_flag:
        break

if min_cam:
    print(1)
else:
    print(0)
