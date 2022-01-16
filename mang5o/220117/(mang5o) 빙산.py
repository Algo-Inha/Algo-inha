# https://www.acmicpc.net/problem/2573

import copy  # to process deep copy

row_col = input()  # input
row_num, col_num = row_col.split(" ")
row_num = int(row_num)  # type casting
col_num = int(col_num)  # type casting

map_matrix = []
not_zero = []
for y in range(row_num):
    map_line = input().split(" ")
    for x in range(len(map_line)):
        map_line[x] = int(map_line[x])  # type casting
        if map_line[x] != 0:
            not_zero.append((y, x))
    map_matrix.append(map_line)

year_count = 0
divided = False
while True:
    tmp_matrix = copy.deepcopy(map_matrix)
    now_zeros = True
    for nz in not_zero:
        y, x = nz
        if tmp_matrix[y][x] != 0:
            now_zeros = False
            for xy_diff in ((y, x - 1), (y, x + 1), (y - 1, x), (y + 1, x)):
                if map_matrix[xy_diff[0]][xy_diff[1]] == 0:
                    tmp_matrix[y][x] = tmp_matrix[y][x] - 1
                if tmp_matrix[y][x] == 0:
                    break
    if now_zeros:
        year_count = 0
        break
    map_matrix = copy.deepcopy(tmp_matrix)
    year_count = year_count + 1

    now_group = 0
    now_x = 0
    while True:
        # check group
        check_queue = []
        now_zeros = True
        for nz in not_zero:
            y, x = nz
            if tmp_matrix[y][x] != 0:
                now_zeros = False
                tmp_matrix[y][x] = 0
                check_queue.append((y, x))
                break
        if now_zeros:
            break
        now_group = now_group + 1
        now_queue_count = 0
        while len(check_queue) > now_queue_count:
            y, x = check_queue[now_queue_count]
            for xy_diff in ((y, x - 1), (y, x + 1), (y - 1, x), (y + 1, x)):
                if tmp_matrix[xy_diff[0]][xy_diff[1]] != 0:
                    tmp_matrix[xy_diff[0]][xy_diff[1]] = 0
                    check_queue.append(xy_diff)
            now_queue_count = now_queue_count + 1
    if now_group > 1:
        print(year_count)
        divided = True
        break
if not divided:
    print(0)
