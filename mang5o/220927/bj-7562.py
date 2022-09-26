# https://www.acmicpc.net/problem/7562
# 나이트의 이동

import sys
from collections import deque


mov_dir = (
    (-1,-2), (-2,-1), (1,-2), (2,-1),
    (-1,2), (-2,1), (1,2), (2,1)
)
answers = []


cases = int(sys.stdin.readline().rstrip())
for case in range(cases):
    map_size = int(sys.stdin.readline().rstrip())
    map_visited = [[False for x in range(map_size)] for y in range(map_size)]
    start_ptr = list(map(int, sys.stdin.readline().rstrip().split()))
    end_ptr = list(map(int, sys.stdin.readline().rstrip().split()))
    if start_ptr[0] == end_ptr[0] and start_ptr[1] == end_ptr[1]:
        answers.append(0)
        continue
    map_visited[start_ptr[0]][start_ptr[1]] = True
    start_ptr.append(0)
    end_ptr.append(0)
    path_deque = deque()  # for BFS
    path_deque.append(start_ptr)
    path_interval = 0
    while len(path_deque) > 0:
        tmp_elem = path_deque.popleft()
        for dir_idx in range(8):
            tmp_y = tmp_elem[0] + mov_dir[dir_idx][0]
            tmp_x = tmp_elem[1] + mov_dir[dir_idx][1]
            # 도착점일때
            if tmp_y == end_ptr[0] and tmp_x == end_ptr[1]:
                path_interval = tmp_elem[2] + 1
                break
            elif 0<=tmp_y<map_size and 0<=tmp_x<map_size:
                if not map_visited[tmp_y][tmp_x]:
                    map_visited[tmp_y][tmp_x] = True
                    path_deque.append([tmp_y,tmp_x, tmp_elem[2]+1])
        if path_interval>0:
            break
    answers.append(path_interval)

for answer in answers:
    print(answer)