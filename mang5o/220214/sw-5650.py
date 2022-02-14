# https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRF8s6ezEDFAUo&
# 핀볼 게임
from queue import Queue

direction_arr = [  # 오 아래 왼 위
    (0, 1), (1, 0), (0, -1), (-1, 0)
]
change_direc = [  # change_direc[i][j] = i방향을 가진 게 j블록을 만났을 때 바뀌는 direction
    [0, 2, 2, 1, 3, 2, 0, 0, 0, 0, 0],
    [1, 0, 3, 3, 2, 3, 1, 1, 1, 1, 1],
    [2, 3, 1, 0, 0, 0, 2, 2, 2, 2, 2],
    [3, 1, 0, 2, 1, 1, 3, 3, 3, 3, 3]
]

T = int(input())
for test_case in range(1, T + 1):
    N = int(input())
    map_matrix = [
        [5 for i in range(N + 2)]
    ]
    start_point = Queue()
    warm_hole = [[], [], [], [], [], [], [], [], [], [], []]
    for i in range(N):
        tmp_input_arr = [5]
        tmp_input = list(map(int, input().split()))
        for j in range(len(tmp_input)):
            tmp_input_arr.append(tmp_input[j])
            if tmp_input[j] <= 0:  # -1이나 0일 때에
                for k in (0, 1, 2, 3):
                    start_point.put((i + 1, j + 1, k))
            elif tmp_input[j] >= 6:
                warm_hole[tmp_input[j]].append((i + 1, j + 1))
        tmp_input_arr.append(5)
        map_matrix.append(tmp_input_arr)
    map_matrix.append([5 for i in range(N + 2)])
    max_score = 0
    while start_point.qsize() > 0:
        tmp_black_hole = start_point.get()
        tmp_score = 0
        start_y = tmp_black_hole[0]
        start_x = tmp_black_hole[1]
        tmp_y = start_y
        tmp_x = start_x
        tmp_dir = tmp_black_hole[2]
        if map_matrix[tmp_y + direction_arr[tmp_dir][0]][tmp_x + direction_arr[tmp_dir][1]] != 0\
                and map_matrix[tmp_y][tmp_x] == -1:
            continue
        while True:
            # moving
            tmp_y += direction_arr[tmp_dir][0]
            tmp_x += direction_arr[tmp_dir][1]
            # 제자리
            if tmp_y == start_y and tmp_x == start_x:
                break
            # direction
            tmp_dir = change_direc[tmp_dir][map_matrix[tmp_y][tmp_x]]
            # 웜홀
            if map_matrix[tmp_y][tmp_x] >= 6:
                now_warm_hole = warm_hole[map_matrix[tmp_y][tmp_x]]
                if tmp_y == now_warm_hole[0][0] and tmp_x == now_warm_hole[0][1]:
                    tmp_y = now_warm_hole[1][0]
                    tmp_x = now_warm_hole[1][1]
                else:
                    tmp_y = now_warm_hole[0][0]
                    tmp_x = now_warm_hole[0][1]
            elif map_matrix[tmp_y][tmp_x] > 0:  # 블록 만났을 때
                tmp_score += 1
            elif map_matrix[tmp_y][tmp_x] == -1:
                break
        if max_score < tmp_score:
            max_score = tmp_score
    print("#{} {}".format(test_case, max_score))
