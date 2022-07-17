# 테트로미노
# https://www.acmicpc.net/problem/14500

import sys

all_fig = [
    # 4스텝동안 4방향으로 BFS등으로 처리하려 했으나 마지막 도형의 구조상 general하게 구현하기 지저분함
    [[True, True, True, True]],
    [[True], [True], [True], [True]],
    [[True, True], [True, True]],
    [[True, True, True], [True, False, False]],
    [[True, True, True], [False, False, True]],
    [[True, False, False], [True, True, True]],
    [[False, False, True], [True, True, True]],
    [[True, True], [True, False], [True, False]],
    [[True, True], [False, True], [False, True]],
    [[True, False], [True, False], [True, True]],
    [[False, True], [False, True], [True, True]],
    [[True, True, False], [False, True, True]],
    [[False, True, True], [True, True, False]],
    [[True, False], [True, True], [False, True]],
    [[False, True], [True, True], [True, False]],
    [[True, True, True], [False, True, False]],
    [[False, True, False], [True, True, True]],
    [[True, False], [True, True], [True, False]],
    [[False, True], [True, True], [False, True]]
]

N, M = map(int, sys.stdin.readline().rstrip().split())
all_map_list = []
for i in range(N):
    tmp_elem = list(map(int, sys.stdin.readline().rstrip().split()))
    tmp_elem.append(-99999)
    tmp_elem.append(-99999)
    tmp_elem.append(-99999)
    all_map_list.append(tmp_elem)
for i in range(3):
    all_map_list.append([-99999 for _ in range(M + 3)])

max_val = 0
for y in range(N):
    for x in range(M):
        for fig in all_fig:
            tmp_val = 0
            for fig_y in range(len(fig)):
                for fig_x in range(len(fig[0])):
                    if fig[fig_y][fig_x]:
                        tmp_val += all_map_list[y + fig_y][x + fig_x]
            max_val = max(max_val, tmp_val)

print(max_val)
