# https://www.acmicpc.net/problem/16957
# 체스판
import sys

dir_matrix = [[-1, -1], [-1, 0], [-1, 1], [0, -1], [0, 0], [0, 1], [1, -1], [1, 0], [1, 1]]
R, C = map(int, sys.stdin.readline().split())
map_matrix = []
for i in range(R):
    map_matrix.append(list(map(int, sys.stdin.readline().split())))
now_ball = [[1 for x in range(C)] for y in range(R)]
end_point = [[[-1, -1] for x in range(C)] for y in range(R)]
for y in range(R):
    for x in range(C):
        if now_ball[y][x] > 0:
            now_cursor = [y, x]
            all_route = [[y,x]]
            now_ball_fig = now_ball[y][x]
            while True:
                if end_point[now_cursor[0]][now_cursor[1]][0] != -1:
                    tmp_end_point = end_point[now_cursor[0]][now_cursor[1]]
                    if tmp_end_point[0] == now_cursor[0] and tmp_end_point[1] == now_cursor[1]:
                        break
                    else:
                        now_ball[tmp_end_point[0]][tmp_end_point[1]] += now_ball[now_cursor[0]][now_cursor[1]]
                        now_ball[now_cursor[0]][now_cursor[1]] = 0
                        break
                min_dir = 0
                min_fig = 300001
                tmp_yy = 0
                tmp_xx = 0
                for dir_idx in range(9):
                    tmp_yy = now_cursor[0] + dir_matrix[dir_idx][0]
                    tmp_xx = now_cursor[1] + dir_matrix[dir_idx][1]
                    if 0 <= tmp_yy < R and 0 <= tmp_xx < C:
                        if map_matrix[tmp_yy][tmp_xx] < min_fig:
                            min_fig = map_matrix[tmp_yy][tmp_xx]
                            min_dir = dir_idx
                if min_dir == 4:
                    while len(all_route)>0:
                        tmp_route = all_route.pop()
                        end_point[tmp_route[0]][tmp_route[1]] = now_cursor
                    break
                else:
                    tmp_yy = now_cursor[0] + dir_matrix[min_dir][0]
                    tmp_xx = now_cursor[1] + dir_matrix[min_dir][1]
                    now_ball[tmp_yy][tmp_xx] += now_ball[now_cursor[0]][now_cursor[1]]
                    now_ball[now_cursor[0]][now_cursor[1]] = 0
                    now_cursor = [tmp_yy, tmp_xx]
                    all_route.append([tmp_yy, tmp_xx])

for i in range(R):
    print(" ".join(map(str, now_ball[i])))

