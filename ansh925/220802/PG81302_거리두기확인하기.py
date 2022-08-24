# https://school.programmers.co.kr/learn/courses/30/lessons/81302
# 거리두기 확인하기
from collections import deque

dx = [-1,1,0,0]
dy = [0,0,-1,1]

def bfs(x,y,p):
    visit = [[0]*5 for _ in range(5)]
    q = deque()
    q.append((x,y,0))
    visit[x][y] = 1

    while q:
        x,y,dist = q.popleft()

        if 0<dist<=2 and p[x][y]=='P':
            return 0
        if dist>2:
            break

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            ndist = dist + 1
            if 0<=nx<5 and 0<=ny<5 and p[nx][ny]!='X' and visit[nx][ny]==0:
                q.append((nx,ny,ndist))
                visit[nx][ny] = 1
    return 1


def solution(places):
    answer = []
    for p in places:
        tmp=0
        for i in range(5):
            for j in range(5):
                if p[i][j]=='P':
                    if bfs(i,j,p)==0:
                        answer.append(0)
                        tmp=1
                        break
            if tmp==1:
                break
        else:
            answer.append(1)
    return answer


print(solution([["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], 
                ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], 
                ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"], 
                ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], 
                ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]))