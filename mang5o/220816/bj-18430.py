# https://www.acmicpc.net/problem/18430
# 무기 공학

import sys

N, M = map(int, sys.stdin.readline().rstrip().split())
map_matrix = []
dir_matrix = (
    ((1,0), (0,-1)),
    ((-1,0), (0,-1)),
    ((-1,0), (0,1)),
    ((1,0), (0,1))
)
for i in range(N):
    map_matrix.append(list(map(int, sys.stdin.readline().rstrip().split())))
if N == 1 or M == 1:
    print(0)
else:
    max_score = 0
    all_dfs = [
        [
            [[False for x in range(M)] for y in range(N)],  # Visited matrix
            [0, 0, 0]  # start y, x, now_score
        ]
    ]
    while len(all_dfs) > 0:
        now_elem = all_dfs.pop()
        now_visited = now_elem[0]
        now_board = now_elem[1]
        max_score = max(max_score, now_board[2])
        for yy in range(N):
            if yy < now_board[0]:
                continue
            for xx in range(M):
                if yy == now_board[0] and xx < now_board[1]:
                    continue
                if now_visited[yy][xx]:
                    continue
                now_center = map_matrix[yy][xx]
                for dir_idx in range(4):
                    now_1 = [yy + dir_matrix[dir_idx][0][0], xx + dir_matrix[dir_idx][0][1]]
                    now_2 = [yy + dir_matrix[dir_idx][1][0], xx + dir_matrix[dir_idx][1][1]]
                    if 0<=now_1[0]<N and 0<=now_2[0]<N and 0<=now_1[1]<M and 0<=now_2[1]<M:
                        if not now_visited[now_1[0]][now_1[1]] and not now_visited[now_2[0]][now_2[1]]:
                            tmp_visited = [[now_visited[yyy][xxx] for xxx in range(M)] for yyy in range(N)]
                            tmp_visited[now_1[0]][now_1[1]] = True
                            tmp_visited[now_2[0]][now_2[1]] = True
                            tmp_visited[yy][xx] = True
                            tmp_board = [yy, xx, now_board[2]]
                            tmp_board[2] += 2*now_center + map_matrix[now_1[0]][now_1[1]] + map_matrix[now_2[0]][now_2[1]]
                            all_dfs.append([tmp_visited, tmp_board])

    print(max_score)