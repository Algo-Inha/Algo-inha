# https://www.acmicpc.net/problem/16234
# 인구 이동
import sys
from collections import deque
dir_matrix = ((0,1), (1,0), (0,-1), (-1,0))
N, L, R = map(int, sys.stdin.readline().rstrip().split())
map_matrix = []
for i in range(N):
    tmp_map = list(map(int, sys.stdin.readline().rstrip().split()))
    map_matrix.append(tmp_map)

step_counter = 0
while True:
    step_counter += 1
    group_people = [] # 그룹 별 인구수
    now_group = -1
    now_group_map = [[-1 for x in range(N)] for y in range(N)]
    for y in range(N):
        for x in range(N):
            if now_group_map[y][x] == -1:
                now_group += 1
                now_group_map[y][x] = now_group
                tmp_deque = deque()
                tmp_deque.append([y,x])
                now_group_sum = map_matrix[y][x] # 현재 그룹의 총 인구 수 합
                now_group_cont = 1  # 현재 그룹의 구역 수
                while len(tmp_deque) >0:
                    tmp_elem = tmp_deque.popleft()
                    for dir_idx in range(4):
                        tmp_y = tmp_elem[0] + dir_matrix[dir_idx][0]
                        tmp_x = tmp_elem[1] + dir_matrix[dir_idx][1]
                        if 0<=tmp_y<N and 0<=tmp_x<N:
                            if now_group_map[tmp_y][tmp_x] == -1 and L<= abs(map_matrix[tmp_elem[0]][tmp_elem[1]]- map_matrix[tmp_y][tmp_x]) <= R:
                                now_group_map[tmp_y][tmp_x] = now_group
                                tmp_deque.append([tmp_y,tmp_x])
                                now_group_sum += map_matrix[tmp_y][tmp_x]
                                now_group_cont += 1
                group_people.append(now_group_sum//now_group_cont)
    now_moved = False
    for y in range(N):
        for x in range(N):
            # 인구 이동이 있는지 확인
            now_area_people = group_people[now_group_map[y][x]]
            if map_matrix[y][x] != now_area_people:
                now_moved = True
                map_matrix[y][x] = now_area_people
    # print("*"*10)
    # for y in range(N):
    #     print(map_matrix[y])
    if not now_moved:
        break
print(step_counter-1)
