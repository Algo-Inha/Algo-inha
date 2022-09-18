# https://www.acmicpc.net/problem/14499
# 주사위 굴리기- BJ_14499

import sys
input = sys.stdin.readline

n, m, x, y, k = map(int, input().split())
graph = [[] for _ in range(n)]
for i in range(n):
    graph[i] = list(map(int, input().split()))

# x: row, y: col
# 동 서 북 남
dx = [0, 0, 0, -1, 1]
dy = [0, 1, -1, 0, 0]

# value:   4      3      5      1      0      2

#          5      0      0      0      2      4
# key:   1 0 3  5 1 2  1 2 3  2 3 5  1 4 3  1 5 3
#          2      4      4      4      5      0

# dice[2]로 시작, 주사위 원소 모두 0
key = 2
value = 5
dice = [[0 for _ in range(6)] for _ in range(6)]

moves = list(list(map(int, input().split())))
for move in moves:
    if x + dx[move] < 0 or x + dx[move] > n-1 or y + dy[move] < 0 or y + dy[move] > m-1:
        continue

    nx = x + dx[move]
    ny = y + dy[move]

    if   move==1: # 동
        if   key==0: key=3
        elif key==1: key=2
        elif key==2: key=3
        elif key==3: key=5
        elif key==4: key=3
        elif key==5: key=3
    elif move==2: # 서
        if   key==0: key=1
        elif key==1: key=5
        elif key==2: key=1
        elif key==3: key=2
        elif key==4: key=1
        elif key==5: key=1
    elif move==3: # 북
        if   key==0: key=5
        elif key==1: key=0
        elif key==2: key=0
        elif key==3: key=0
        elif key==4: key=2
        elif key==5: key=4
    elif move==4: # 남
        if   key==0: key=2
        elif key==1: key=4
        elif key==2: key=4
        elif key==3: key=4
        elif key==4: key=5
        elif key==5: key=0
    
    if graph[nx][ny]==0:
        graph[nx][ny] = dice[key][key]
    else:
        for i in range(6):
            dice[i][key] = graph[nx][ny]
        graph[nx][ny] = 0

    # 주사위 윗면
    if   key==0: print(dice[key][4])
    elif key==1: print(dice[key][3])
    elif key==2: print(dice[key][5])
    elif key==3: print(dice[key][1])
    elif key==4: print(dice[key][0])
    elif key==5: print(dice[key][2])

    x, y = nx, ny

    # 주사위 방향 돌아갈 상황 고려 X
    # 주사위 코드로 구현...