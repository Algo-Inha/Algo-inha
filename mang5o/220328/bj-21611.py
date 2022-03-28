# https://www.acmicpc.net/problem/21611
# 마법사 상어와 블리자드

import sys
from collections import deque

# 굳이 N*N 행렬로 문제를 풀 이유가 없다
dir_matrix = ((0, -1), (1, 0), (0, 1), (-1, 0))
N, M = map(int, sys.stdin.readline().rstrip().split())
tmp_map_matrix = []
for i in range(N):
    tmp_map_matrix.append(list(map(int, sys.stdin.readline().rstrip().split())))
blizzard_matrix = []
for i in range(M):
    blizzard_matrix.append(list(map(int, sys.stdin.readline().rstrip().split())))

all_map = ""
tmp_y = N // 2
tmp_x = N // 2
now_dir = 0
now_second = False
now_step = 1
end_flag = False
while not end_flag: # 맵을 일자로 바꿔줌
    for steps in range(now_step):
        tmp_y += dir_matrix[now_dir][0]
        tmp_x += dir_matrix[now_dir][1]
        all_map += str(tmp_map_matrix[tmp_y][tmp_x])
        if tmp_x == 0 and tmp_y == 0:
            end_flag = True
            break
    now_dir = (now_dir + 1) % 4
    if now_second:
        now_step += 1
    now_second = not now_second

# 파이어볼
# 위쪽방향이라면 인덱스 6,21,44,75 diff 15,23,31 (8씩 증가)...
# 아래방향이라면 인덱스 2,13,32,.. diff 11,19,   (8씩 증가)...
# 왼쪽방향이라면 인덱스 0,9,26,51  diff 9,17,25  (8씩 증가)...
# 오른방향이라면 인덱스 4,17,38... diff 13,21,   (8씩 증가)...
blizzard_dir_matrix = ((), (6,15),(2,11),(0,9),(4,13)) # 첫 인덱스, diff시작

# 터뜨린 양 저장
exploded = [-1,0,0,0]
for blizzard in range(M):
    # 볼 터뜨리기
    tmp_idx = blizzard_matrix[blizzard][0]
    tmp_step = blizzard_matrix[blizzard][1]
    now_idx = blizzard_dir_matrix[tmp_idx][0]
    now_diff = blizzard_dir_matrix[tmp_idx][1]
    for i in range(tmp_step): # 처음 구슬 지우기
        all_map = all_map[:now_idx] + "D" + all_map[now_idx + 1:]
        now_idx += now_diff
        now_diff += 8
        if now_idx > N ** 2 - 2:
            break
    all_map = all_map.replace("D","")
    # 볼 터뜨리기
    while True:
        all_map += "0"
        now_flag = False
        now_figure = "0"
        now_cursor_start = 0
        del_index_mat = deque()
        for idx in range(len(all_map)):
            if all_map[idx] == now_figure:
                continue
            else:
                if idx  - now_cursor_start >= 4:
                    del_index_mat.append((now_cursor_start, idx - 1, all_map[idx - 1]))
                now_figure = all_map[idx]
                now_cursor_start = idx
        while len(del_index_mat) > 0:
            tmp_del_idx = del_index_mat.pop()
            now_flag = True
            now_del_len = tmp_del_idx[1] - tmp_del_idx[0] + 1
            now_del_figure = int(tmp_del_idx[2])
            exploded[now_del_figure] += now_del_len
            all_map = all_map[:tmp_del_idx[0]] + all_map[tmp_del_idx[1] + 1:]
        all_map = all_map[:len(all_map)-2]
        if not now_flag:
            break
    # 볼 그룹화
    all_map = all_map.replace("0","")
    all_map = all_map.replace("12","1S2")
    all_map = all_map.replace("13","1S3")
    all_map = all_map.replace("21","2S1")
    all_map = all_map.replace("23","2S3")
    all_map = all_map.replace("31","3S1")
    all_map = all_map.replace("32","3S2")
    all_grouped = all_map.split("S")
    # 그룹화한 볼 다시 일렬로
    all_map = ""
    for i in range(len(all_grouped)):
        if len(all_grouped[i])>0:
            all_map += str(len(all_grouped[i])) + all_grouped[i][0]
    all_map += "0" * ((N**2-1) - len(all_map)) # 부족한 길이만큼 0 채우기
    all_map = all_map[:N**2-1] # 넘은만큼 지우기

del_output = exploded[1]*1 + exploded[2]*2 + exploded[3]*3
print(del_output)