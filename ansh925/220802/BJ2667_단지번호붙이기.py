# https://www.acmicpc.net/problem/2667
# 단지번호 붙이기
from collections import deque

n = int(input())
graph = [list(map(int,input().rstrip())) for _ in range(n)]

dx = [1,-1,0,0]
dy = [0,0,1,-1]

def bfs(x,y):
    q=deque()
    q.append((x,y))
    graph[x][y] = 0         # 방문하면 0으로 갱신
    cnt = 1                 # 처음 집부터 count 1

    while q:
        x,y=q.popleft()     # deque(q)에서 하나씩 빼며
        for i in range(4):  # 4방향 돌면서
            nx = x + dx[i]
            ny = y + dy[i]

            if 0<=nx<n and 0<=ny<n and graph[nx][ny] == 1:  # 범위 안에서 graph=1 이면
                graph[nx][ny] = 0       # 방문하면 0으로 갱신
                q.append((nx,ny))       # 집이 있으므로(graph=1) 해당 위치 deque에 push 
                cnt += 1                # cnt++
    return cnt

ans=[]
for i in range(n):
    for j in range(n):
        if graph[i][j]==1:              # 집이 있는 경우
            ans.append(bfs(i,j))        # bfs 실행

ans.sort()                  # 정렬하고
print(len(ans))             # 단지 수 출력
print(*ans, sep='\n')       # 각 단지의 집 수 출력