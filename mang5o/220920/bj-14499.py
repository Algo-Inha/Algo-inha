# https://www.acmicpc.net/problem/14499
# 주사위 굴리기

import sys

now_dice = [
    [0],
    [0, 0, 0],
    [0],
    [0]
]
N, M, X, Y, K = map(int, sys.stdin.readline().rstrip().split())
all_map = []
for i in range(N):
    all_map.append(list(map(int, sys.stdin.readline().rstrip().split())))
all_mov = list(map(int, sys.stdin.readline().rstrip().split()))

for move in all_mov:
    if move == 1:  # Mov right
        if Y < M - 1:
            Y += 1
            new_dice = [
                [now_dice[0][0]],
                [now_dice[3][0], now_dice[1][0], now_dice[1][1]],
                [now_dice[2][0]],
                [now_dice[1][2]]
            ]
            now_dice = new_dice
            print(now_dice[1][1])
            if all_map[X][Y] == 0:
                all_map[X][Y] = now_dice[3][0]
            else:
                now_dice[3][0] = all_map[X][Y]
                all_map[X][Y] = 0

    elif move == 2:  # Mov left
        if Y > 0:
            Y -= 1
            new_dice = [
                [now_dice[0][0]],
                [now_dice[1][1], now_dice[1][2], now_dice[3][0]],
                [now_dice[2][0]],
                [now_dice[1][0]]
            ]
            now_dice = new_dice
            print(now_dice[1][1])
            if all_map[X][Y] == 0:
                all_map[X][Y] = now_dice[3][0]
            else:
                now_dice[3][0] = all_map[X][Y]
                all_map[X][Y] = 0

    elif move == 3:  # Mov up
        if X > 0:
            X -= 1
            new_dice = [
                [now_dice[1][1]],
                [now_dice[1][0], now_dice[2][0], now_dice[1][2]],
                [now_dice[3][0]],
                [now_dice[0][0]]
            ]
            now_dice = new_dice
            print(now_dice[1][1])
            if all_map[X][Y] == 0:
                all_map[X][Y] = now_dice[3][0]
            else:
                now_dice[3][0] = all_map[X][Y]
                all_map[X][Y] = 0

    else:  # Mov down
        if X < N - 1:
            X += 1
            new_dice = [
                [now_dice[3][0]],
                [now_dice[1][0], now_dice[0][0], now_dice[1][2]],
                [now_dice[1][1]],
                [now_dice[2][0]]
            ]
            now_dice = new_dice
            print(now_dice[1][1])
            if all_map[X][Y] == 0:
                all_map[X][Y] = now_dice[3][0]
            else:
                now_dice[3][0] = all_map[X][Y]
                all_map[X][Y] = 0
