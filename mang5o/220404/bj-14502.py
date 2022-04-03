# https://www.acmicpc.net/problem/14502
# 연구소

import sys, itertools
from collections import deque

dir_mat = (
    (-1,0), (0,1), (1,0), (0,-1)
)

N, M = map(int, sys.stdin.readline().rstrip().split())
all_map = []
for i in range(N):
    all_map.append(list(map(int, sys.stdin.readline().rstrip().split())))

all_blank = []
all_virus = []
for y in range(N):
    for x in range(M):
        if all_map[y][x]==0:
            all_blank.append((y,x))
        elif all_map[y][x]==2:
            all_virus.append((y,x))

all_blank_len = len(all_blank)
all_virus_len = len(all_virus)

all_comb = itertools.combinations([i for i in range(all_blank_len)], 3)
max_safety = 0
for ac in all_comb:
    tmp_queue = deque()
    for i in range(3): # 임시로 벽 만들기
        all_map[all_blank[ac[i]][0]][all_blank[ac[i]][1]] = 1
    for vir in range(all_virus_len): # 바이러스 모두 Queue에 넣어주기
        tmp_queue.append(all_virus[vir])
    while len(tmp_queue)>0: # 퍼뜨려주기
        tmp_vir = tmp_queue.popleft()
        for dir_idx in range(4):
            tmp_y = tmp_vir[0] + dir_mat[dir_idx][0]
            tmp_x = tmp_vir[1] + dir_mat[dir_idx][1]
            if 0<=tmp_y<N and 0<=tmp_x<M:
                if all_map[tmp_y][tmp_x] == 0:
                    tmp_queue.append((tmp_y,tmp_x))
                    all_map[tmp_y][tmp_x] = 1
    # 행렬 리셋하면서 안전영역 크기 확인
    safety = 0
    for ab in range(all_blank_len):
        if all_map[all_blank[ab][0]][all_blank[ab][1]] == 0:
            safety += 1
        else:
            all_map[all_blank[ab][0]][all_blank[ab][1]] = 0
    max_safety = max(max_safety, safety)


print(max_safety)