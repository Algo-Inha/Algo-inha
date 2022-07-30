# https://school.programmers.co.kr/learn/courses/30/lessons/81302
# 거리두기 확인하기- PG_81302

from collections import deque

places = [  ["XOXPX", "OOPXX", "XXXXX", "XXXXX", "XXXXX"], 
            ["POOPX", "OXPXX", "XXXXX", "OXXXO", "OOOXP"], 
            ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"], 
            ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], 
            ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]  ]

def solution(places):
    answer = []
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    temp = [[False for _ in range(5)] for _ in range(5)]

    for i in range(5):
        found_error = False
        for row in range(5):
            if found_error == True:
                break
            for col in range(5):
                if found_error == True:
                    break
                # 면접자에 대해 dfs 알고리즘 적용
                if places[i][row][col] == 'P':
                    dfs = deque([(row, col)])
                    temp[row][col] = True
                
                    while dfs:
                        if found_error == True:
                            break
                        y, x = dfs.popleft()
                        # 맨해튼 거리 넘어가면 break
                        dist = abs(row - y) + abs(col - x)
                        if dist >= 2:
                            break
                        # 맨해튼 거리 넘어가지 않으면
                        # 면접자가 존재하지 않을 때 queue에 추가, 지나간 경로 표시
                        # 면접자가 존재할 때 found_error = True, answer에 0을 담는다.
                        for j in range(4):
                            nx = x + dx[j]
                            ny = y + dy[j]
                            if nx >= 0 and nx < 5 and ny >= 0 and ny < 5 and temp[ny][nx] == False:
                                if places[i][ny][nx] == 'O':
                                    dfs.append((ny, nx))
                                    temp[ny][nx] = True
                                elif places[i][ny][nx] == 'P':
                                    answer.append(0)
                                    found_error = True
                                    break
                    temp = [[False for _ in range(5)] for _ in range(5)]
        # 5 x 5 크기의 대기실을 모두 돌았음에도 answer에 0이 추가되지 않을 경우
        # answer에 1을 담는다.
        if len(answer) == i:
            answer.append(1)
    return answer

print(solution(places))
