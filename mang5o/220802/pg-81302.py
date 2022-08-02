# https://school.programmers.co.kr/learn/courses/30/lessons/81302
# 거리두기 확인하기

from collections import deque

dir_matrix = ((0,1),(1,0),(0,-1),(-1,0))
def solution(places):
    ret_list = []
    for place in places:
        now_map = place
        now_flag = 1
        for y in range(5):
            for x in range(5):
                if now_map[y][x] == "P":
                    BFS_deque = deque()
                    BFS_deque.append([y,x,0])
                    while BFS_deque:
                        tmp_BFS_deque = BFS_deque.popleft()
                        for dir_idx in range(4):
                            tmp_y = tmp_BFS_deque[0] + dir_matrix[dir_idx][0]
                            tmp_x = tmp_BFS_deque[1] + dir_matrix[dir_idx][1]
                            if 0 <= tmp_y < 5 and 0 <= tmp_x < 5:
                                if now_map[tmp_y][tmp_x] == "O" and tmp_BFS_deque[2]==0:
                                    BFS_deque.append([tmp_y, tmp_x, tmp_BFS_deque[2]+1])
                                    continue
                                if now_map[tmp_y][tmp_x] == "P" and not (tmp_y==y and tmp_x==x):
                                    now_flag = 0
                                    break
                if now_flag == 0: # Escape condition
                    break
            if now_flag == 0: # Escape condition
                break
        ret_list.append(now_flag)
    return ret_list

print(solution([["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"],
               ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"],
               ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]))


print(solution([["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"]]))