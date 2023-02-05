# https://www.acmicpc.net/problem/14719
# 빗물
import sys

H, W = map(int, sys.stdin.readline().rstrip().split())
map_input = list(map(int, sys.stdin.readline().rstrip().split()))
map_matrix = [[1 if idx < i else 0 for idx in range(H)] for i in map_input]
water_cnt = 0
for y in range(1, W):
    for x in range(H):
        if map_matrix[y - 1][x] == 1 and map_matrix[y][x] == 0:
            tmp_flag = False
            tmp_x_max = 0
            for tmp_y in range(y, W):
                if map_matrix[tmp_y][x] == 1:
                    tmp_flag = True
                    tmp_x_max = tmp_y
            for tmp_y in range(y, tmp_x_max):
                if map_matrix[tmp_y][x] == 0:
                    map_matrix[tmp_y][x] = 2
                    water_cnt += 1
print(water_cnt)