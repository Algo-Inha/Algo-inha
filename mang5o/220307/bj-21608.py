# https://www.acmicpc.net/problem/21608
# 상어초등학교
import sys

dir_matrix = ((0, 1), (0, -1), (1, 0), (-1, 0))
adj_score_table = [0, 1, 10, 100, 1000]
order_index_map = {}  # order_index_map[K] => K 학생이 몇 번째로 입력을 받았는지
N = int(sys.stdin.readline().rstrip())
map_matrix = [[0 for i in range(N)] for j in range(N)]
now_all_score = 0
input_matrix = []
for i in range(N ** 2):
    tmp_input = list(map(int, sys.stdin.readline().rstrip().split()))
    order_index_map[tmp_input[0]] = i
    max_y = -1
    max_x = -1
    adj_score = 0  # 주변 친구 점수
    blank_score = 0  # 주변 빈칸 점수
    for y in range(N):
        for x in range(N):
            if map_matrix[y][x] == 0:
                tmp_adj_score = 0
                tmp_blank_score = 0
                for j in range(4):
                    tmp_y = y + dir_matrix[j][0]
                    tmp_x = x + dir_matrix[j][1]
                    if 0 <= tmp_y < N and 0 <= tmp_x < N:
                        if map_matrix[tmp_y][tmp_x] == 0:
                            tmp_blank_score += 1
                        elif map_matrix[tmp_y][tmp_x] in tmp_input:
                            tmp_adj_score += 1
                if max_y == -1: # 맨 처음 빈 칸
                    max_y = y
                    max_x = x
                    adj_score = tmp_adj_score
                    blank_score = tmp_blank_score
                elif adj_score < tmp_adj_score:
                    max_y = y
                    max_x = x
                    adj_score = tmp_adj_score
                    blank_score = tmp_blank_score
                elif adj_score == tmp_adj_score and blank_score < tmp_blank_score:
                    max_y = y
                    max_x = x
                    adj_score = tmp_adj_score
                    blank_score = tmp_blank_score
    map_matrix[max_y][max_x] = tmp_input[0]
    order_index_map[tmp_input[0]] = i
    input_matrix.append(tmp_input)


for y in range(N):
    for x in range(N):
        tmp_adj_calc = 0
        for i in range(4):
            tmp_y = y + dir_matrix[i][0]
            tmp_x = x + dir_matrix[i][1]
            if 0 <= tmp_y < N and 0 <= tmp_x < N:
                # 인접한 학생 : map_matrix[tmp_y][tmp_x]
                tmp_idx =  order_index_map[map_matrix[y][x]]
                if map_matrix[tmp_y][tmp_x] in input_matrix[tmp_idx]:
                    tmp_adj_calc += 1
        now_all_score += adj_score_table[tmp_adj_calc]

print(now_all_score)
