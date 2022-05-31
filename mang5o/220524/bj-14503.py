# 로봇 청소기
# https://www.acmicpc.net/problem/14503

import sys

dir_matrix = ((-1, 0), (0, 1), (1, 0), (0, -1))  # 북 동 남 서
N, M = map(int, sys.stdin.readline().rstrip().split())
R, C, dir_idx = map(int, sys.stdin.readline().rstrip().split())
all_map = []
all_map_cleaned = [[False for x in range(M)] for y in range(N)]
for i in range(N):
    all_map.append(list(map(int, sys.stdin.readline().rstrip().split())))

start_ptr = [R, C, dir_idx,  0]  # 현재 행, 열, 방향,  청소한 칸 수
# 좌표에 관한 설명이 없지만 그래도 TC로 파악 가능
while True:
    # print(start_ptr)
    # 현재 위치를 청소한다.
    if not all_map_cleaned[start_ptr[0]][start_ptr[1]]:
        all_map_cleaned[start_ptr[0]][start_ptr[1]] = True
        start_ptr[3] += 1
    # 현재 위치에서 다음을 반복하면서 인접한 칸을 탐색한다.
    now_2a_step = 0
    while True:
        left_idx = (start_ptr[2] - 1) % 4
        left_y = start_ptr[0] + dir_matrix[left_idx][0]
        left_x = start_ptr[1] + dir_matrix[left_idx][1]
        # 현재 위치의 바로 왼쪽에 아직 청소하지 않은 빈 공간이 존재한다면
        if all_map[left_y][left_x] == 0 and not all_map_cleaned[left_y][left_x]:
            # 왼쪽 방향으로 회전한 다음 한 칸을 전진하고 1번으로 돌아간다
            now_2a_step = 0
            start_ptr = [left_y, left_x, left_idx, start_ptr[3]]
            break
        else:
            now_2a_step += 1
            start_ptr[2] = left_idx
            if now_2a_step == 4:
                break
    if now_2a_step == 4:
        back_idx = (start_ptr[2] - 2) % 4
        back_y = start_ptr[0] + dir_matrix[back_idx][0]
        back_x = start_ptr[1] + dir_matrix[back_idx][1]
        if all_map[back_y][back_x] == 1:  # 바로 뒤쪽이 벽이라면
            break
        else:  # 그렇지 않다면
            start_ptr[0] = back_y
            start_ptr[1] = back_x
    # print(now_2a_step)

print(start_ptr[3])
