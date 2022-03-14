# https://programmers.co.kr/learn/courses/30/lessons/1829
# 카카오 프렌즈 컬러링북
from collections import deque

dir_matrix = ((0,1),(0,-1),(-1,0),(1,0))

def solution(m,n,picture):
    visited_matrix = [[False for i in range(n)] for j in range(m)]
    fig_area = 0 # 범위의 개수
    max_color_area = 0
    for i in range(m):
        for j in range(n):
            if picture[i][j]==0:
                visited_matrix[i][j] = True
    for y in range(m):
        for x in range(n):
            if not visited_matrix[y][x]:
                tmp_deque = deque()
                tmp_deque.append((y,x))
                visited_matrix[y][x] = True
                now_color = picture[y][x]
                now_color_area = 1
                fig_area += 1
                while len(tmp_deque)>0:
                    tmp_elem = tmp_deque.popleft()
                    for dir_idx in range(4):
                        tmp_y = tmp_elem[0] + dir_matrix[dir_idx][0]
                        tmp_x = tmp_elem[1] + dir_matrix[dir_idx][1]
                        if 0<=tmp_y<m and 0<=tmp_x<n:
                            if not visited_matrix[tmp_y][tmp_x] and picture[tmp_y][tmp_x]==now_color:
                                visited_matrix[tmp_y][tmp_x] = True
                                now_color_area += 1
                                tmp_deque.append((tmp_y,tmp_x))
                max_color_area = max(max_color_area, now_color_area)
    return [fig_area,max_color_area]


print(solution(6,4,[[1, 1, 1, 0], [1, 2, 2, 0], [1, 0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 3], [0, 0, 0, 3]]))