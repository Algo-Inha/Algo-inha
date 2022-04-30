# https://www.acmicpc.net/problem/21609
# 상어 중학교

import sys
from collections import deque

dir_matrix = ((1, 0), (0, 1), (-1, 0), (0, -1))

N, M = map(int, sys.stdin.readline().rstrip().split())
all_map = []  # 빈 칸은 -2
for y in range(N):
    all_map.append(list(map(int, sys.stdin.readline().rstrip().split())))

all_score = 0

while True:

    max_block_size = 0
    max_yx = [0, 0]
    max_color = 0
    max_rainbow_block = 0
    visited_map = [[False for x in range(N)] for y in range(N)]

    for y in range(N):  # 기준블록 : [y,x]
        for x in range(N): # 이거때문에 4번을 틀렸다... N을 M으로 써서
            if all_map[y][x] > 0 and not visited_map[y][x]:  # 일반 블록이 무조건 하나는 있어야 하므로 시작점은 일반블록
                now_deque = deque()
                visited_map[y][x] = True
                now_color = all_map[y][x]
                now_block_size = 1
                now_deque.append([y, x])
                now_rainbow_block = 0
                while len(now_deque) > 0:
                    now_elem = now_deque.pop()
                    for dir_idx in range(4):
                        tmp_y = now_elem[0] + dir_matrix[dir_idx][0]
                        tmp_x = now_elem[1] + dir_matrix[dir_idx][1]
                        if 0 <= tmp_y < N and 0 <= tmp_x < N:
                            if not visited_map[tmp_y][tmp_x]:
                                if all_map[tmp_y][tmp_x] == now_color:
                                    visited_map[tmp_y][tmp_x] = True
                                    now_block_size += 1
                                    now_deque.append([tmp_y,tmp_x])
                                elif all_map[tmp_y][tmp_x] == 0:
                                    visited_map[tmp_y][tmp_x] = True
                                    now_block_size += 1
                                    now_deque.append([tmp_y, tmp_x])
                                    now_rainbow_block += 1

                if now_block_size > max_block_size:  # 크기가 가장 큰 블록
                    max_block_size = now_block_size
                    max_yx = [y, x]
                    max_color = now_color
                    max_rainbow_block = now_rainbow_block
                elif now_block_size == max_block_size:
                    if now_rainbow_block > max_rainbow_block:  # 포함된 무지개 블록 수가 많은 블록
                        max_block_size = now_block_size
                        max_yx = [y, x]
                        max_color = now_color
                        max_rainbow_block = now_rainbow_block
                    elif now_rainbow_block == max_rainbow_block:
                        if max_yx[0] < y:  # 행이 가장 큰 것
                            max_block_size = now_block_size
                            max_yx = [y, x]
                            max_color = now_color
                            max_rainbow_block = now_rainbow_block
                        elif max_yx[0] == y:
                            if max_yx[1] < x: # 열이 가장 큰 것
                                max_block_size = now_block_size
                                max_yx = [y, x]
                                max_color = now_color
                                max_rainbow_block = now_rainbow_block
                # 무지개 블록 visited 초기화
                for tmp_tmp_y in range(N):
                    for tmp_tmp_x in range(N):
                        if all_map[tmp_tmp_y][tmp_tmp_x] == 0:
                            visited_map[tmp_tmp_y][tmp_tmp_x] = False

    if max_block_size < 2:  # 블록이 만들어지지 않았을 때
        break

    # 시작점이 max_yx인 block을 제거하기
    now_deque = deque()
    now_deque.append(max_yx)
    all_map[max_yx[0]][max_yx[1]] = -2
    visited_map = [[False for x in range(N)] for y in range(N)]
    visited_map[max_yx[0]][max_yx[1]] = True
    while len(now_deque) > 0:
        tmp_elem = now_deque.popleft()
        for dir_idx in range(4):
            tmp_y = tmp_elem[0] + dir_matrix[dir_idx][0]
            tmp_x = tmp_elem[1] + dir_matrix[dir_idx][1]
            if 0 <= tmp_y < N and 0 <= tmp_x < N:
                if not visited_map[tmp_y][tmp_x]:
                    if all_map[tmp_y][tmp_x] == max_color or all_map[tmp_y][tmp_x] == 0:
                        all_map[tmp_y][tmp_x] = -2
                        visited_map[tmp_y][tmp_x] = True
                        now_deque.append([tmp_y, tmp_x])
    # 점수 추가
    all_score += max_block_size ** 2
    # print(max_block_size ** 2)

    # all_map 중력적용
    for y in range(N):
        tmp_y = N - y - 1  # 최대한 아래에 있는 블록부터 이동해야하기 때문에
        for x in range(N):
            if all_map[tmp_y][x] > -1:  # 검은 블록이거나 빈 칸이 아닐 경우
                tmp_tmp_y = tmp_y
                while True:
                    tmp_tmp_y += 1
                    if tmp_tmp_y == N:
                        tmp_tmp_y -= 1
                        break
                    elif all_map[tmp_tmp_y][x] != -2:
                        tmp_tmp_y -= 1
                        break
                if tmp_tmp_y != tmp_y:
                    all_map[tmp_tmp_y][x] = all_map[tmp_y][x]
                    all_map[tmp_y][x] = -2

    # all_map 회전
    all_rotated_map = [[all_map[x][N-y-1] for x in range(N)] for y in range(N)]
    all_map = all_rotated_map

    # all_map 다시 중력 적용
    for y in range(N):
        tmp_y = N - y - 1  # 최대한 아래에 있는 블록부터 이동해야하기 때문에
        for x in range(N):
            if all_map[tmp_y][x] > -1:  # 검은 블록이거나 빈 칸이 아닐 경우
                tmp_tmp_y = tmp_y
                while True:
                    tmp_tmp_y += 1
                    if tmp_tmp_y == N:
                        tmp_tmp_y -= 1
                        break
                    elif all_map[tmp_tmp_y][x] != -2:
                        tmp_tmp_y -= 1
                        break
                if tmp_tmp_y != tmp_y:
                    all_map[tmp_tmp_y][x] = all_map[tmp_y][x]
                    all_map[tmp_y][x] = -2

print(all_score)