# https://www.acmicpc.net/problem/3019
# 테트리스

import sys
C, P = map(int, sys.stdin.readline().split())
all_height = list(map(int, sys.stdin.readline().split()))
all_case = 0

if P == 1:
    # block 1 vertical
    all_case += C

    # block 1 horizontal
    for i in range(C - 3):
        if all_height[i] == all_height[i + 1] == all_height[i + 2] == all_height[i + 3]:
            all_case += 1
elif P == 2:
    # block 2
    for i in range(C - 1):
        if all_height[i] == all_height[i + 1]:
            all_case += 1
elif P == 3:
    # block 3 vertical
    for i in range(C - 1):
        if all_height[i] == all_height[i + 1]+1:
            all_case += 1

    # block 3 horizontal
    for i in range(C - 2):
        if all_height[i] + 1 == all_height[i + 1] + 1 == all_height[i + 2]:
            all_case += 1
elif P == 4:
    # block 4 vertical
    for i in range(C - 1):
        if all_height[i]+1 == all_height[i + 1]:
            all_case += 1

    # block 4 horizontal
    for i in range(C - 2):
        if all_height[i] == all_height[i + 1] + 1 == all_height[i + 2] + 1:
            all_case += 1
elif P == 5:
    # block 5 ㅗ
    for i in range(C - 2):
        if all_height[i] == all_height[i + 1] == all_height[i + 2]:
            all_case += 1

    # block 5 ㅓ
    for i in range(C - 1):
        if all_height[i] + 1 == all_height[i + 1]:
            all_case += 1

    # block 5 ㅜ
    for i in range(C - 2):
        if all_height[i] == all_height[i + 1] + 1 == all_height[i + 2]:
            all_case += 1

    # block 5 ㅏ
    for i in range(C - 1):
        if all_height[i] == all_height[i + 1] + 1:
            all_case += 1
elif P == 6:
    # block 6 degree 0 (clockwise)
    for i in range(C - 2):
        if all_height[i] == all_height[i + 1] == all_height[i + 2]:
            all_case += 1

    # block 6 degree 90 (clockwise)
    for i in range(C - 1):
        if all_height[i] == all_height[i + 1]:
            all_case += 1

    # block 6 degree 180 (clockwise)
    for i in range(C - 2):
        if all_height[i] + 1 == all_height[i + 1] == all_height[i + 2]:
            all_case += 1

    # block 6 degree 270 (clockwise)
    for i in range(C - 1):
        if all_height[i] == all_height[i + 1] + 2:
            all_case += 1
else:
    # block 7 degree 0 (clockwise)
    for i in range(C - 2):
        if all_height[i] == all_height[i + 1] == all_height[i + 2]:
            all_case += 1

    # block 7 degree 90 (clockwise)
    for i in range(C - 1):
        if all_height[i]+2 == all_height[i + 1]:
            all_case += 1

    # block 7 degree 180 (clockwise)
    for i in range(C - 2):
        if all_height[i] == all_height[i + 1] == all_height[i + 2] + 1:
            all_case += 1

    # block 7 degree 270 (clockwise)
    for i in range(C - 1):
        if all_height[i] == all_height[i + 1]:
            all_case += 1

print(all_case)