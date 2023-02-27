# Solving

## 틱택토
https://www.acmicpc.net/problem/7682
### 문제풀이
```python
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
```
조건에 만족하면: valid
만족하지 않으면: invalid 출력
### 의견
문제를 고민하면 할 수록 따져봐야 하는 경우의 수가 계쏙 늘어난다. 코드를 수정에 수정을 거쳤지만, 10%에서 실패.. 반례 케이스를 알고 싶다.


## 용액
https://www.acmicpc.net/problem/2467
### 문제풀이
```python
import sys
input = sys.stdin.readline

n = int(input())
koi = list(map(int, input().split()))

start, end = 0, n - 1
ansStart = start
ansEnd = end
ans = abs(koi[start] + koi[end])

while start < end:                  # start, end가 반전되면 안됨
    sumKoi = koi[start] + koi[end]  # 용액 특성값의 합
    
    if abs(sumKoi) < ans:           # 용액 특성절댓값이 최솟값보다 작으면,
        ansStart = start            # 교체
        ansEnd = end
        ans = abs(sumKoi)

        if ans == 0:                # 0이면 끝
            break
    
    if sumKoi < 0:                  # 용액 특성값의 합이 음수일 경우
        start += 1
    else:                           # 용액 특성값의 합이 0 또는 양수일 경우
        end -= 1

print(koi[ansStart], koi[ansEnd])
```
투포인터 사용
### 의견
투포인터를 알고 사용한 것은 아니지만, 사용해보니 투포인터였다. 이분탐색으로 푸는 방법도 존재한다는데 투포인터가 더 깔끔한 것 같다.


## 상어 초등학교
https://www.acmicpc.net/problem/21608
### 문제풀이
```python
# https://www.acmicpc.net/problem/21608
# 상어 초등학교- BJ_21608

import sys

input = sys.stdin.readline

n = int(input())
graph = [[0 for _ in range(n)] for _ in range(n)]
graphLike = [[[] for _ in range(n)] for _ in range(n)]

# 동 서 남 북
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

for i in range(n ** 2):
    stu, li1, li2, li3, li4 = map(int, input().split())
    stuLike = [li1, li2, li3, li4]

    maxLike = 0     # max 좋아하는 학생수
    subGraph = [[0 for _ in range(n)] for _ in range(n)]       # 인접한 칸에 좋아하는 학생 수
    graphNextCond = [[False for _ in range(n)] for _ in range(n)]   # True끼리 다음 조건 비교
    for y in range(n):
        for x in range(n):
            cntLike = 0
            if graph[y][x] == 0:    # 한칸에는 한명씩!
                for j in range(4):  # 인접한 4칸에 좋아하는 학생 있는지 판별
                    if 0<=y+dy[j]<n and 0<=x+dx[j]<n:   # 범위 벗어나지 않도록
                        nx = x + dx[j]
                        ny = y + dy[j]
                        if graph[ny][nx] in stuLike:    # 좋아하는 학생칸일 경우, cntLike += 1
                            cntLike += 1
                if maxLike < cntLike:   # 좋아하는 학생 max 값 바뀜
                    maxLike = cntLike
                subGraph[y][x] = cntLike
    # print('subGraph: ',subGraph)
    # print('maxLike: ', maxLike)
    cnt1 = 0
    x1, y1 = -1, -1
    for y in range(n):      ## 1번 조건
        for x in range(n):
            if subGraph[y][x] == maxLike and graph[y][x] == 0:   # 1번조건 만족할 경우, True
                cnt1 += 1   # 1번 조건 만족하는 칸 개수: 1보다 클 경우 2번 조건 탐색
                if cnt1 == 1:   # cnt 1일때 x, y 값 저장: 1번 조건으로 정해질 경우!!
                    x1, y1 = x, y
                
                graphNextCond[y][x] = True
            else:                              # 1번 조건 만족하지 않을 경우, False
                graphNextCond[y][x] = False
    # print('cnt1 값: ', cnt1)
    if cnt1 == 1:   # 1번 조건으로 끝나는 경우
        graph[y1][x1] = stu
        graphLike[y1][x1] = stuLike

    else:           # 2번 조건 이상 가야 할 경우
        ## 2번 조건
        maxCntEmpty = 0 # max 인접한 칸이 빈칸인 칸의 수
        subSubGraph = [[0 for _ in range(n)] for _ in range(n)]     # 인접한 칸에 빈칸 수
        for y in range(n):      
            for x in range(n):
                cntEmpty = 0
                if graphNextCond[y][x] and graph[y][x] == 0:     # 1번 조건 만족하는 칸, 비어있는 칸 중
                    for j in range(4):      # 인접한 4칸에 빈 칸수
                        if 0<=y+dy[j]<n and 0<=x+dx[j]<n:
                            nx = x + dx[j]
                            ny = y + dy[j]
                            if graph[ny][nx] == 0:
                                cntEmpty += 1
                    if maxCntEmpty < cntEmpty:
                        maxCntEmpty = cntEmpty
                    subSubGraph[y][x] = cntEmpty
        # print('subSubGraph: ', subSubGraph)
        cnt2 = 0
        x2, y2 = -1, -1
        stop = False
        for y in range(n):
            for x in range(n):
                if subSubGraph[y][x] == maxCntEmpty and graph[y][x] == 0:
                    x2, y2 = x, y
                    stop = True
                    break
            if stop:
                break

        graph[y2][x2] = stu
        graphLike[y2][x2] = stuLike
    # print('graphNextCond: ', graphNextCond)
#     print('graph: ', graph)

# print('graph: ', graph)
# print('graphLike: ', graphLike)

ans = 0
for y in range(n):
    for x in range(n):
        subAns = 0
        for j in range(4):
            if 0<=y+dy[j]<n and 0<=x+dx[j]<n:
                nx = x + dx[j]
                ny = y + dy[j]
                if graph[ny][nx] in graphLike[y][x]:
                    subAns += 1
        if subAns == 0:
            ans += 0
        elif subAns == 1:
            ans += 1
        elif subAns == 2:
            ans += 10
        elif subAns == 3:
            ans += 100
        elif subAns == 4:
            ans += 1000

print(ans)
```
빡센 구현문제, 1, 2, 3번 조건을 차례차례 따져가며 자리 배치를 하면 된다. 3번 조건의 경우 for문을 돌면서 자동으로 정해지기에 따로 지정하지 않아도 된다. 
### 의견
예제 및 반례 케이스까지 모두 통과하여 풀었다고 생각했지만.. 틀렸다. 왜 틀렸을까.. 아기 상어 문제처럼... 혼란스럽다. 4시간은 투자한 것 같은데 뭐가 부족했던걸까