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