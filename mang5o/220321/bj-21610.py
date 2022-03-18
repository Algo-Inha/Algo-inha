# 마법사 상어와 비바라기
# https://www.acmicpc.net/problem/21610

import sys

dir_matrix = ((0, 0), (0, -1), (-1, -1), (-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1))  # 1부터 사용
cross_matrix = ((-1, -1), (1, 1), (-1, 1), (1, -1))
N, M = map(int, sys.stdin.readline().rstrip().split())
map_matrix = []
mov_matrix = []
for i in range(N):
    tmp_line = list(map(int, sys.stdin.readline().rstrip().split()))
    map_matrix.append(tmp_line)
for i in range(M):
    tmp_line = list(map(int, sys.stdin.readline().rstrip().split()))
    mov_matrix.append(tmp_line)

# 초기 구름 설정
cloud_mat = [[N - 2, 0], [N - 1, 0], [N - 2, 1], [N - 1, 1]]
cloud_check = [[False for i in range(N)] for j in range(N)]
for steps in range(M):
    now_mov = mov_matrix[steps]
    # 비내리기
    for cloud in range(len(cloud_mat)):
        tmp_y = (cloud_mat[cloud][0] + dir_matrix[now_mov[0]][0] * now_mov[1]) % N
        tmp_x = (cloud_mat[cloud][1] + dir_matrix[now_mov[0]][1] * now_mov[1]) % N
        map_matrix[tmp_y][tmp_x] += 1
        cloud_check[tmp_y][tmp_x] = True
    # 물복사버그
    for cloud in range(len(cloud_mat)):
        tmp_y = (cloud_mat[cloud][0] + dir_matrix[now_mov[0]][0] * now_mov[1]) % N
        tmp_x = (cloud_mat[cloud][1] + dir_matrix[now_mov[0]][1] * now_mov[1]) % N
        tmp_add_cnt = 0
        for dir_idx in range(4):
            tmp_yy = tmp_y + cross_matrix[dir_idx][0]
            tmp_xx = tmp_x + cross_matrix[dir_idx][1]
            if 0<=tmp_yy<N and 0<=tmp_xx<N:
                if map_matrix[tmp_yy][tmp_xx]>0:
                    tmp_add_cnt+= 1
        map_matrix[tmp_y][tmp_x] += tmp_add_cnt
    # 다음 스탭의 구름위치
    next_cloud = []
    for y in range(N):
         for x in range(N):
             if map_matrix[y][x]>=2 and not cloud_check[y][x]:
                next_cloud.append([y,x])
                map_matrix[y][x] -= 2
    cloud_check = [[False for i in range(N)] for j in range(N)]
    cloud_mat = next_cloud

    # print("Now step : {}".format(steps))
    # for i in range(N):
    #     print(map_matrix[i])

all_water = 0
for y in range(N):
    for x in range(N):
        all_water += map_matrix[y][x]
print(all_water)


