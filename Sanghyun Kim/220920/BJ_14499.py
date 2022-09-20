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

dice = [0 for _ in range(6)]

moves = list(list(map(int, input().split())))
for move in moves:
    if x + dx[move] < 0 or x + dx[move] > n-1 or y + dy[move] < 0 or y + dy[move] > m-1:
        continue

    nx = x + dx[move]
    ny = y + dy[move]

    diceIdx_0 = dice[0]
    diceIdx_1 = dice[1]
    diceIdx_2 = dice[2]
    diceIdx_3 = dice[3]
    diceIdx_4 = dice[4]
    diceIdx_5 = dice[5]
    
    if   move==1: # 동
        dice[0]=diceIdx_2
        dice[1]=diceIdx_0
        dice[2]=diceIdx_5
        dice[5]=diceIdx_1
    elif move==2: # 서
        dice[0]=diceIdx_1
        dice[1]=diceIdx_5
        dice[2]=diceIdx_0
        dice[5]=diceIdx_2
    elif move==3: # 북
        dice[0]=diceIdx_4
        dice[3]=diceIdx_0
        dice[4]=diceIdx_5
        dice[5]=diceIdx_3
    elif move==4: # 남
        dice[0]=diceIdx_3
        dice[3]=diceIdx_5
        dice[4]=diceIdx_0
        dice[5]=diceIdx_4
    
    if graph[nx][ny]==0:
        graph[nx][ny]=dice[0]
    else:
        dice[0]=graph[nx][ny]
        graph[nx][ny]=0
    
    print(dice[5])
    x, y = nx, ny