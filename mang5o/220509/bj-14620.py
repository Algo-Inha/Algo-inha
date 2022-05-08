# 꽃길
# https://www.acmicpc.net/problem/14620

import sys
N = int(sys.stdin.readline().rstrip())
all_map = []
for i in range(N):
    all_map.append(list(map(int, sys.stdin.readline().rstrip().split())))
all_added = [[all_map[y][x] + all_map[y - 1][x] + all_map[y][x - 1] + all_map[y + 1][x] + all_map[y][x + 1]
              for x in range(1, N - 1)] for y in range(1, N - 1)]

all_case = (N - 2) ** 2
min_cost = -1
for flower_1 in range(all_case - 4):
    for flower_2 in range(flower_1 + 2, all_case - 2):
        for flower_3 in range(flower_2 + 2, all_case):
            flower_1_yx = [flower_1 % (N-2), flower_1 // (N-2)]
            flower_2_yx = [flower_2 % (N-2), flower_2 // (N-2)]
            flower_3_yx = [flower_3 % (N-2), flower_3 // (N-2)]
            if abs(flower_1_yx[0] - flower_2_yx[0]) + abs(flower_1_yx[1] - flower_2_yx[1]) < 3:
                continue
            elif abs(flower_1_yx[0] - flower_3_yx[0]) + abs(flower_1_yx[1] - flower_3_yx[1]) < 3:
                continue
            elif abs(flower_3_yx[0] - flower_2_yx[0]) + abs(flower_3_yx[1] - flower_2_yx[1]) < 3:
                continue
            else:
                all_cost = 0
                all_cost += all_added[flower_1_yx[0]][flower_1_yx[1]] + \
                            all_added[flower_2_yx[0]][flower_2_yx[1]] + \
                            all_added[flower_3_yx[0]][flower_3_yx[1]]
                if min_cost==-1:
                    min_cost = all_cost
                else:
                    min_cost = min(min_cost, all_cost)
print(min_cost)