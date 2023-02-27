# https://www.acmicpc.net/problem/7682
# 틱택토- BJ_7682

import sys
input = sys.stdin.readline

while 1:
    testCase = input()
    if testCase[0] == 'e':  # end일 경우 끝
        break
    else:
        graph = [[0 for _ in range(3)] for _ in range(3)]
        numO = 0    # O 개수
        numX = 0    # X 개수
        for i in range(9):
            if testCase[i] == 'O':
                numO += 1
            elif testCase[i] == 'X':
                numX += 1
            graph[i // 3][i % 3] = testCase[i]      # 테스트 케이스

        # print('numX: ', numX)
        # print('numO: ', numO)
        if numO + numX == 9:    # 9칸 모두 찰 경우
            if (numO + 1 == numX):      # X개수가 5개일 경우 무조건 Valid
                print('valid')
            else:                       # 이외의 경우: Invalid 
                print('invalid')
        else:                   # 9칸 모두 차지 않을 경우
            if (numO + 1 == numX) or (numX == numO):    # X개수가 O개수와 같거나 1개 많을 경우
                if numX + numO < 5:         # 4칸까지는 완성될 수 없음, 무조건 Invalid
                    print('invalid')
                # elif numX + numO == 5:      # 5칸 차지할 때 까지는 무조건 Valid
                #     print('valid')
                else:
                    xGraph = [[False for _ in range(3)] for _ in range(3)]      # dfs 지나간 칸: True
                    oGraph = [[False for _ in range(3)] for _ in range(3)]      
                    xWin = 0        # X 3칸~5칸 
                    oWin = 0        # O 3칸~4칸
                    
                    # 우측, 우측대각아래, 아래, 좌측대각아래
                    dy = [0, 1, 1, 1]
                    dx = [1, 1, 0, -1]
                    
                    # xWin
                    for y in range(3):
                        for x in range(3):
                            if graph[y][x] == 'X' and xGraph[y][x] == False:
                                yy, xx = y, x
                                for j in range(4):
                                    if 0<=yy+dy[j]<3 and 0<=xx+dx[j]<3 and graph[yy+dy[j]][xx+dx[j]] == 'X':
                                        ny, nx = yy+dy[j], xx+dx[j]
                                        if 0<=ny+dy[j]<3 and 0<=nx+dx[j]<3 and graph[ny+dy[j]][nx+dx[j]] == 'X':
                                            xGraph[yy][xx] = True
                                            xGraph[ny][nx] = True
                                            xGraph[ny+dy[j]][nx+dx[j]] = True
                                            xWin += 1       # X 3칸 가로 or 세로 or 대각선 만족

                    # oWin
                    for y in range(3):
                        for x in range(3):
                            if graph[y][x] == 'O' and oGraph[y][x] == False:
                                yy, xx = y, x
                                for j in range(4):
                                    if 0<=yy+dy[j]<3 and 0<=xx+dx[j]<3 and graph[yy+dy[j]][xx+dx[j]] == 'O':
                                        ny, nx = yy+dy[j], xx+dx[j]
                                        if 0<=ny+dy[j]<3 and 0<=nx+dx[j]<3 and graph[ny+dy[j]][nx+dx[j]] == 'O':
                                            oGraph[yy][xx] = True
                                            oGraph[ny][nx] = True
                                            oGraph[ny+dy[j]][nx+dx[j]] = True
                                            oWin += 1

                    if xWin == 1 and oWin == 0 and numX > numO:     # X만 3칸 가로/세로/대각선 만족: Valid
                        print('valid')
                    elif xWin == 0 and oWin == 1 and numX == numO:  # O만 3칸 가로/세로/대각선 만족: Valid
                        print('valid')
                    else:                                           # 이외의 경우: Invalid
                        print('invalid')
            else:
                print('invalid')                        # 이외의 경우: Invalid