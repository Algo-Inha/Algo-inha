# https://www.acmicpc.net/problem/16987
# 계란으로 계란치기

import sys

N = int(sys.stdin.readline().rstrip())
dfs_stack = [[list(map(int, sys.stdin.readline().rstrip().split())) for _ in range(N)] + [0]] # 마지막 : 다음에 칠 계란위치
max_broken = 0
while len(dfs_stack) > 0:
    tmp_elem = dfs_stack.pop()

    if tmp_elem[-1] == N:
        now_broken = 0
        for egg in range(N):
            if tmp_elem[egg][0] <= 0:
                now_broken += 1
        max_broken = max(max_broken, now_broken)
        if max_broken == N:
            break
        continue

    if tmp_elem[tmp_elem[-1]][0] < 0:
        new_list = [[tmp_elem[x][s] for s in range(2)] for x in range(N)] + [tmp_elem[-1]]
        new_list[-1] += 1
        dfs_stack.append(new_list)
        continue

    crushed = False
    for egg_idx in range(N):
        if tmp_elem[-1] != egg_idx and tmp_elem[egg_idx][0] > 0 and tmp_elem[tmp_elem[-1]][0] > 0:
            new_list = [[tmp_elem[x][s] for s in range(2)] for x in range(N)] + [tmp_elem[-1]]
            # new_list[egg_idx]와 new_list[tmp_elem[-1]]의 충돌
            new_list[egg_idx][0] -= new_list[new_list[-1]][1]
            new_list[new_list[-1]][0] -= new_list[egg_idx][1]
            new_list[-1] += 1
            dfs_stack.append(new_list)
            crushed = True

    if not crushed:
        new_list = [[tmp_elem[x][s] for s in range(2)] for x in range(N)] + [tmp_elem[-1]]
        new_list[-1] += 1
        dfs_stack.append(new_list)

print(max_broken)