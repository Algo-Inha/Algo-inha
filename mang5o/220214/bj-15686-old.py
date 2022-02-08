# https://www.acmicpc.net/problem/15686
# 시간초과 계속뜸 이유 확인 불가능
"""
import sys
N, M = map(int, sys.stdin.readline().rstrip().split())
all_chicken = {}
all_house = {}
chicken_num = 0
house_num = 0
for i in range(N):
    now_input = sys.stdin.readline().rstrip().split()
    for j in range(len(now_input)):
        if now_input[j] == '1':
            all_chicken[chicken_num] = (i, j)
            chicken_num += 1
        elif now_input[j] == '2':
            all_house[house_num] = (i, j)
            house_num += 1
now_cnt = -1
size_chicken = chicken_num
all_iter = [i for i in range(M)]
while all_iter[0] < size_chicken:
    if all_iter[-1] < size_chicken:
        now_all_tmp = 0
        for j in range(house_num):
            now_tmp_path = -1
            for i in all_iter:
                if now_tmp_path == -1:
                    now_tmp_path = abs(all_chicken[i][0] - all_house[j][0]) + abs(all_chicken[i][1] - all_house[j][1])
                else:
                    tmp_vals = abs(all_chicken[i][0] - all_house[j][0]) + abs(all_chicken[i][1] - all_house[j][1])
                    if now_tmp_path > tmp_vals:
                        now_tmp_path = tmp_vals
            now_all_tmp += now_tmp_path
        if now_cnt == -1:
            now_cnt = now_all_tmp
        elif now_cnt > now_all_tmp:
            now_cnt = now_all_tmp
    all_iter[-1] += 1
    up_pointer = -1
    for i in range(M - 1):
        if all_iter[-1 - i] >= size_chicken:
            all_iter[-2 - i] += 1
            all_iter[-1 - i] = all_iter[-2 - i] + 1
            up_pointer = M - i - 1
        else:
            break
    if up_pointer != -1:
        for i in range(up_pointer, M):
            all_iter[i] = all_iter[i - 1] + 1
    if all_iter[-1] >= size_chicken:
        continue

print(now_cnt)
"""


# 이 코드도 다르게 풀었는데 시간초과
"""
import sys, itertools
from queue import Queue

N, M = map(int, sys.stdin.readline().rstrip().split())
map_matrix = []
chickens = []
houses = []
for i in range(N):
    tmp_input = list(map(int, sys.stdin.readline().rstrip().split()))
    for j in range(len(tmp_input)):
        if tmp_input[j] == 1:
            houses.append((i, j))
        elif tmp_input[j] == 2:
            chickens.append((i, j))
    map_matrix.append(tmp_input)

all_iters = itertools.combinations([i for i in range(len(chickens))], M)
min_path = -1
for i in all_iters:
    for j in i:
        # 이번에 포함되는 치킨집은 3으로 둠
        map_matrix[chickens[j][0]][chickens[j][1]] = 3
    # 남아있는 치킨집을 가지고 계산하는 치킨거리
    now_house_path_sum = 0
    for house in houses:
        tmp_house_queue = Queue()
        tmp_house_queue.put(house)
        nearest_chicken = (-1, -1)
        while tmp_house_queue.qsize() > 0:
            tmp_queue = tmp_house_queue.get()
            for dir_point in ((-1, 0), (0, 1), (0, -1), (1, 0)):
                tmp_y = tmp_queue[0] + dir_point[0]
                tmp_x = tmp_queue[1] + dir_point[1]
                if 0 <= tmp_y < N and 0 <= tmp_x < N:
                    if map_matrix[tmp_y][tmp_x] == 3:
                        nearest_chicken = (tmp_y, tmp_x)
                        break
                    else:
                        tmp_house_queue.put((tmp_y, tmp_x))
            if nearest_chicken[1] != -1:
                break
        now_house_path_sum += abs(nearest_chicken[0] - house[0]) + abs(nearest_chicken[1] - house[1])
    if min_path >= now_house_path_sum:
        min_path = now_house_path_sum
    elif min_path == -1:
        min_path = now_house_path_sum
    for j in i:
        # 이번에 포함됐던 치킨집을 2로 원복
        map_matrix[chickens[j][0]][chickens[j][1]] = 2

print(min_path)
"""