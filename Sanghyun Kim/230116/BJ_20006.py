# https://www.acmicpc.net/problem/20006
# 랭킹전 대기열- BJ_20006

import sys
input = sys.stdin.readline

p, m = map(int, input().split())
player = [[] for _ in range(p)]
graph = [False for _ in range(p)]
# 5명의 플레이어 들어갈 때 마다 게임 실행: Started!
# 전체 player 다 돌았는데 게임 실행 안될 경우: Waiting!
gameStk = []
for i in range(p):
    player[i] = list(map(str, input().split()))
    player[i][0] = int(player[i][0])

temp = False
for j in range(len(player)):
    if graph[j] == False:   # 방 만들기
        gameStk.append(player[j])
        graph[j] = True
        temp = True

        for i in range(j, len(player)):    # 만들어진 방에 플레이어 채우기
            if graph[i] == False and gameStk[0][0] - 10 <= player[i][0] <= gameStk[0][0] + 10:
                graph[i] = True
                gameStk.append(player[i])

            if len(gameStk) == m:   # 만들어진 방에 플레이어 모두 참
                break

    if temp:
        if len(gameStk) == m:   # 게임 시작
            print('Started!')
        else:                   # 게임 시작 못함
            print('Waiting!')
        
        gameStk.sort(key = lambda x : x[1])
        for i in range(len(gameStk)):
            print(*gameStk[i])
        gameStk = []
        temp = False