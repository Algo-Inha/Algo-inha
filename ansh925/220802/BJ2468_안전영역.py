# https://www.acmicpc.net/problem/2468
# 안전 영역
from collections import deque

n = int(input())
graph = [list(map(int,input().split())) for _ in range(n)]
dx = [-1,1,0,0]
dy = [0,0,-1,1]


def bfs(x,y,rain):
    q=deque()
    q.append((x,y))
    visit[x][y] = 1         # 방문했는지 체크하는 배열, 방문하면 1로 갱신

    while q:
        x,y = q.popleft()
        for i in range(4):  # 4방향 돌며
            nx = x + dx[i]
            ny = y + dy[i]

            # 범위 안쪽이면서, 방문하지 않았고, 지역의 높이가 강수량 이상일 때
            if 0<=nx<n and 0<=ny<n and visit[nx][ny]==0 and graph[nx][ny] > rain:
                visit[nx][ny] = 1       # 방문 체크
                q.append((nx,ny))       # 해당 위치 저장

max_g=0
for i in range(n):
    for j in range(n):
        max_g = max(max_g, graph[i][j])     # 가장 높은 지역의 높이 -> 최대 강수량

ans=[]
for k in range(max_g):
    visit = [[0]*n for _ in range(n)]
    cnt=0

    for i in range(n):
        for j in range(n):
            if graph[i][j] > k and visit[i][j]==0:  # 방문 안했고, 강수량보다 높은 지역
                bfs(i,j,k)      # bfs돌면서 안전지대 파악
                cnt += 1        # 안전지대 갯수 count
    ans.append(cnt)

print(max(ans))                 # 안전지대 최대치 출력