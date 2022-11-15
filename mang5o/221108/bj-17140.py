# https://www.acmicpc.net/problem/17140
# 이차원 배열과 연산

import sys

def sort_arr(ats):
    new_dict = dict()
    for i in ats:
        if i == 0:
            continue
        if i in new_dict:
            new_dict[i] += 1
        else:
            new_dict[i] = 1
    new_list = []
    for i in new_dict.keys():
        new_list.append([i, new_dict[i]])
    new_list.sort(key=lambda x:(x[1], x[0]))
    return_list = []
    for elem in new_list:
        return_list += elem
    return return_list


R, C, K = map(int, sys.stdin.readline().rstrip().split())
A = [list(map(int, sys.stdin.readline().rstrip().split())) for _ in range(3)]

now_time = 0
while True:
    if A[R-1][C-1] == K:
        break
    if now_time > 100:
        now_time = -1
        break
    now_time += 1
    width = len(A[0])
    height = len(A)

    if width <= height:
        max_len = 0
        for y in range(height):
            A[y] = sort_arr(A[y])
            max_len = max(max_len, len(A[y]))
        for y in range(height):
            if len(A[y]) != max_len:
                A[y] += [0 for _ in range(max_len - len(A[y]))]
    else:
        for x in range(width):
            new_vertical_arr = []
            for y in range(height):
                new_vertical_arr.append(A[y][x])
            new_vertical_arr = sort_arr(new_vertical_arr)
            for cnt in range(len(new_vertical_arr) - height):
                A.append([0 for _ in range(width)])
            for yy in range(len(new_vertical_arr)):
                A[yy][x] = new_vertical_arr[yy]
    for y in range(len(A)):
        now_y = len(A)-y-1
        if sum(A[now_y]) == 0:
            del A[now_y]
    for x in range(len(A[0])):
        now_x = len(A[0])-x-1
        del_flag = True
        for y in range(len(A)):
            if A[y][now_x] != 0:
                del_flag = False
                break
        if del_flag:
            for y in range(len(A)):
                del A[y][now_x]
print(now_time)