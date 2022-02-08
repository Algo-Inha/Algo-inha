# https://www.acmicpc.net/problem/15686
# 치킨 배달

import sys, itertools

N, M = map(int, sys.stdin.readline().rstrip().split())
houses = []
chickens = []
houses_num = 0
chickens_num = 0

for i in range(N):
    tmp_input = list(map(int, sys.stdin.readline().rstrip().split()))
    for j in range(len(tmp_input)):
        if tmp_input[j] == 1:
            houses.append((i, j))
            houses_num += 1
        elif tmp_input[j] == 2:
            chickens.append((i, j))
            chickens_num += 1

all_distances = [[(abs(houses[i][0] - chickens[j][0]) + abs(houses[i][1] - chickens[j][1]))
                  for j in range(chickens_num)] for i in range(houses_num)]
# all_distances[i][j] -> i번째 집과 j번째 치킨집과의 거리

all_iters = itertools.combinations([i for i in range(len(chickens))], M)
all_min_path = 1000000
for ai in all_iters:
    now_path_sum = 0
    for house in range(houses_num):
        min_path = 1000000
        for chic_idx in ai:
            tmp_path = all_distances[house][chic_idx]
            if min_path>tmp_path:
                min_path = tmp_path
        now_path_sum += min_path
    if all_min_path>now_path_sum:
        all_min_path = now_path_sum

print(all_min_path)
