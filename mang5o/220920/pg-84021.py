# https://school.programmers.co.kr/learn/courses/30/lessons/84021
# 퍼즐 조각 채우기

dir_matrix = (
    (-1, 0), (1, 0), (0, -1), (0, 1)
)


def solution(game_board, table):
    comp_table = [game_board, table]
    comp_blocks = [[], []]
    len_side = len(game_board)
    all_sum_size = 0
    # Separate blocks
    for comp_val in range(2):
        visited_table = [[False for x in range(len(table[y]))] for y in range(len(table))]
        for y in range(len(table)):
            for x in range(len(table[0])):
                if not visited_table[y][x] and comp_table[comp_val][y][x] == comp_val:
                    tmp_dfs_area = []
                    tmp_block_area = [[False for x in range(len(table[y]))] for y in range(len(table))]
                    tmp_block_area[y][x] = True
                    visited_table[y][x] = True
                    tmp_dfs_area.append([y, x])
                    while len(tmp_dfs_area) > 0:
                        tmp_yx = tmp_dfs_area.pop()
                        for dir_idx in range(4):
                            tmp_yy = tmp_yx[0] + dir_matrix[dir_idx][0]
                            tmp_xx = tmp_yx[1] + dir_matrix[dir_idx][1]
                            if 0 <= tmp_yy < len(table) and 0 <= tmp_xx < len(table[0]):
                                if not visited_table[tmp_yy][tmp_xx] and comp_table[comp_val][tmp_yy][tmp_xx] == comp_val:
                                    tmp_block_area[tmp_yy][tmp_xx] = True
                                    visited_table[tmp_yy][tmp_xx] = True
                                    tmp_dfs_area.append([tmp_yy, tmp_xx])
                    # Crop blocks (now block -> tmp_block_area)
                    y_min = len(table)
                    y_max = 0
                    x_min = len(table[0])
                    x_max = 0
                    for yyy in range(len(table)):
                        for xxx in range(len(table[0])):
                            if tmp_block_area[yyy][xxx]:
                                y_min = min(y_min, yyy)
                                y_max = max(y_max, yyy)
                                x_min = min(x_min, xxx)
                                x_max = max(x_max, xxx)
                    tmp_block_cropped = [[tmp_block_area[yyy][xxx] for xxx in range(x_min, x_max+1)] for yyy in range(y_min, y_max+1)]
                    comp_blocks[comp_val].append(tmp_block_cropped)
    # Compare blocks
    for board_blank in range(len(comp_blocks[0])):
        now_same_break = -1
        for table_block in range(len(comp_blocks[1])):
            board_blank_elem = comp_blocks[0][board_blank]
            table_block_elem = comp_blocks[1][table_block]
            for dir_idx in range(4): # Just rotate comp_blocks
                if dir_idx == 0 or dir_idx == 2: # 0 deg & 180 deg rotation
                    if len(board_blank_elem) != len(table_block_elem):
                        continue
                    if len(board_blank_elem[0]) != len(table_block_elem[0]):
                        continue
                if dir_idx == 1 or dir_idx == 3: # 0 deg & 180 deg rotation
                    if len(board_blank_elem) != len(table_block_elem[0]):
                        continue
                    if len(board_blank_elem[0]) != len(table_block_elem):
                        continue
                now_same_flag = True
                now_break_flag = False
                for yyy in range(len(board_blank_elem)):
                    if now_break_flag:
                        now_same_flag = False
                        break
                    for xxx in range(len(board_blank_elem[0])):
                        if dir_idx == 0:  # 0 clockwise deg direction
                            if board_blank_elem[yyy][xxx] != table_block_elem[yyy][xxx]:
                                now_same_flag = False
                                now_break_flag = True
                                break
                        if dir_idx == 1:  # 90 clockwise deg direction
                            if board_blank_elem[yyy][xxx] != table_block_elem[-1-xxx][yyy]:
                                now_same_flag = False
                                now_break_flag = True
                                break
                        if dir_idx == 2:  # 180 clockwise deg direction
                            if board_blank_elem[yyy][xxx] != table_block_elem[-1 -yyy][-1 - xxx]:
                                now_same_flag = False
                                now_break_flag = True
                                break
                        if dir_idx == 3:  # 270 clockwise deg direction
                            if board_blank_elem[yyy][xxx] != table_block_elem[xxx][-1 - yyy]:
                                now_same_flag = False
                                now_break_flag = True
                                break
                if now_same_flag:
                    now_same_break = table_block
                    break
            if now_same_break >= 0:
                # Test print
                # print("DELETED blank {}, block {}".format(board_blank, now_same_break))
                # print(comp_blocks[0][board_blank])
                # print(comp_blocks[1][now_same_break])

                del comp_blocks[1][now_same_break]
                # Calculate removed block size
                now_block_size = 0
                for yyy in range(len(comp_blocks[0][board_blank])):
                    for xxx in range(len(comp_blocks[0][board_blank][0])):
                        if comp_blocks[0][board_blank][yyy][xxx]:
                            now_block_size += 1
                all_sum_size += now_block_size

                break

    return all_sum_size


print(solution(
    [[1,1,0,0,1,0],[0,0,1,0,1,0],[0,1,0,0,1,1],[1,1,0,1,1,1],[1,0,0,0,1,0],[0,1,1,1,0,0]],
    [[1, 0, 0, 1, 1, 0], [1, 0, 1, 1, 1, 0], [1, 1, 1, 0, 1, 1], [0, 1, 1, 0, 0, 0], [1, 1, 1, 1, 1, 0],
     [0, 1, 1, 0, 0, 1]]
))
# print(solution(
#     [[1, 1, 1, 0, 0, 0], [0, 0, 1, 0, 1, 0], [0, 1, 1, 0, 0, 1], [1, 1, 0, 1, 1, 1], [1, 0, 0, 0, 1, 0],
#      [0, 1, 1, 1, 0, 0]],
#     [[1, 0, 0, 1, 1, 0], [1, 0, 1, 0, 1, 0], [0, 1, 1, 0, 1, 1], [0, 0, 1, 0, 0, 0], [1, 1, 0, 1, 1, 0],
#      [0, 1, 0, 0, 0, 0]]
# ))
print(solution(
    [[0, 0, 0], [1, 0, 1], [1, 1, 1]],
    [[1, 1, 1], [1, 0, 0], [0, 0, 0]]
))
# print(solution(
#     [[0,0], [0, 1]], [[1, 1], [1, 0]]
# ))

