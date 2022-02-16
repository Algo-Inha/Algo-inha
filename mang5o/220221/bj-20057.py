# https://www.acmicpc.net/problem/20057
# 마법사 상어와 토네이도

# 격자 밖으로 나가는 것을 실시간으로 구할지, 맨 마지막에 첫 모래와 비교할지 선택
# 연산에 편하도록 padding을 2로 주고 계산 진행 (마지막에 패딩 위치만 더하기)

# alpha로 넘어가는 모래 = 55%
import math
import sys

dir_mv = [[  # 왼 아래 오른 위 순서
    [0, 0, 2, 0, 0],
    [0, 10, 7, 1, 0],
    [5, 55, 0, 0, 0],
    [0, 10, 7, 1, 0],
    [0, 0, 2, 0, 0]
], [
    [0, 0, 0, 0, 0],
    [0, 1, 0, 1, 0],
    [2, 7, 0, 7, 2],
    [0, 10, 55, 10, 0],
    [0, 0, 5, 0, 0]

], [
    [0, 0, 2, 0, 0],
    [0, 1, 7, 10, 0],
    [0, 0, 0, 55, 5],
    [0, 1, 7, 10, 0],
    [0, 0, 2, 0, 0]
], [
    [0, 0, 5, 0, 0],
    [0, 10, 55, 10, 0],
    [2, 7, 0, 7, 2],
    [0, 1, 0, 1, 0],
    [0, 0, 0, 0, 0]
]]

dir_mv_pix = [
    (0, -1), (1, 0), (0, 1), (-1, 0)
]

N = int(sys.stdin.readline().rstrip())
map_matrix = [[0 for i in range(N + 4)] for j in range(2)]
for i in range(N):
    map_matrix.append(
        list(map(int, ("0 0 " + sys.stdin.readline().rstrip() + " 0 0").split()))
    )
map_matrix.append([0 for i in range(N + 4)])
map_matrix.append([0 for i in range(N + 4)])

tmp_x = int((N + 3) / 2)
tmp_y = int((N + 3) / 2)
mv_step = 1
mv_flag = 0  # mv_step만큼 이동하는 카운트
mv_secn = 0  # 2번마다 step을 늘리기 위한 카운트
now_dir = 0  # 0,1,2,3
while True:
    if tmp_x == 2 and tmp_y == 2:
        break
    next_x = tmp_x + dir_mv_pix[now_dir][1]
    next_y = tmp_y + dir_mv_pix[now_dir][0]
    # print("{},{} to {},{}, dir:{}".format(tmp_x - 2, tmp_y - 2, next_x - 2, next_y - 2, now_dir))

    now_y_sand = map_matrix[next_y][next_x]
    now_y_sand_cnt = 0
    for y in range(5):
        for x in range(5):
            tmp_mv_sand = math.floor(now_y_sand * dir_mv[now_dir][y][x] / 100)
            map_matrix[next_y - 2 + y][next_x - 2 + x] += tmp_mv_sand
            now_y_sand_cnt += tmp_mv_sand
    map_matrix[next_y][next_x] = 0
    map_matrix[next_y + dir_mv_pix[now_dir][0]][next_x + dir_mv_pix[now_dir][1]] += now_y_sand - now_y_sand_cnt

    # make next step & direction
    mv_flag += 1
    if mv_flag >= mv_step:
        mv_flag = 0
        mv_secn += 1
        now_dir = (now_dir + 1) % 4
    if mv_secn == 2:
        mv_secn = 0
        mv_step += 1
    tmp_x = next_x
    tmp_y = next_y

all_cnt = 0
for i in range(N+4):
    for j in range(N+4):
        if i < 2 or i >= N + 2 or j < 2 or j >= N + 2:
            all_cnt += map_matrix[i][j]
print(all_cnt)
