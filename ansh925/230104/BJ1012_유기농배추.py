# https://www.acmicpc.net/problem/1012
# 유기농 배추

dx = [-1,1,0,0]
dy = [0,0,-1,1]

def bfs(x,y):
    q = [(x,y)]
    visit[x][y] = 0
    while q:
        x,y = q.pop(0)
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]            
            if 0<=nx<m and 0<=ny<n and visit[nx][ny] == 1:
                    q.append((nx,ny))
                    visit[nx][ny] = 0

t = int(input())
for _ in range(t):
    m,n,k = map(int,input().split())
    visit = [[0]*n for _ in range(m)]
    
    for _ in range(k):
        a,b = map(int,input().split())
        visit[a][b] = 1
        
    cnt = 0
    for i in range(m):
        for j in range(n):
            if visit[i][j] == 1:
                bfs(i,j)
                cnt += 1
    print(cnt)