# Puyo Puyo
# https://www.acmicpc.net/problem/11559

import sys
from collections import deque

dir_matrix = ((0, 1), (0, -1), (1, 0), (-1, 0))
all_map = []
for i in range(12):
    tmp_inp = sys.stdin.readline().rstrip()
    tmp_arr = []
    for j in range(6):
        if tmp_inp[j] == ".":
            tmp_arr.append(0)
        elif tmp_inp[j] == "R":
            tmp_arr.append(1)
        elif tmp_inp[j] == "G":
            tmp_arr.append(2)
        elif tmp_inp[j] == "B":
            tmp_arr.append(3)
        elif tmp_inp[j] == "P":
            tmp_arr.append(4)
        else:
            tmp_arr.append(5)
    all_map.append(tmp_arr)

all_chain = 0
visited_gc = []
while True:
    now_chain = False
    for y in range(12):
        for x in range(6):
            if all_map[y][x] != 0:
                visited_gc = [[False for xx in range(6)] for yy in range(12)]
                visited_gc[y][x] = True
                bfs_deque = deque()
                bfs_deque.append([y,x])
                now_block = 1
                now_color = all_map[y][x]
                while len(bfs_deque) > 0:
                    tmp_elem = bfs_deque.popleft()
                    for dir_idx in range(4):
                        tmp_yy = tmp_elem[0] + dir_matrix[dir_idx][0]
                        tmp_xx = tmp_elem[1] + dir_matrix[dir_idx][1]
                        if 0<=tmp_yy<12 and 0<=tmp_xx<6:
                            if visited_gc[tmp_yy][tmp_xx] == False and all_map[tmp_yy][tmp_xx] == now_color:
                                visited_gc[tmp_yy][tmp_xx] = True
                                now_block += 1
                                bfs_deque.append([tmp_yy,tmp_xx])
                if now_block >= 4:
                    for yyy in range(12):
                        for xxx in range(6):
                            if visited_gc[yyy][xxx]:
                                all_map[yyy][xxx] = 0
                                now_chain = True


    if not now_chain:
        break
    else: # Gravity
        all_chain += 1
        for y_elem in range(12):
            for x in range(6):
                y = 11-y_elem
                if all_map[y][x] == 0:
                    for yy_elem in range(y):
                        now_yy = y-yy_elem-1
                        if all_map[now_yy][x] != 0:
                            all_map[y][x] = all_map[now_yy][x]
                            all_map[now_yy][x] = 0
                            break
print(all_chain)