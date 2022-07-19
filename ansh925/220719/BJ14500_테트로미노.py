# https://www.acmicpc.net/problem/14500
# 테트로미노
import sys
input=sys.stdin.readline

def dfs(x, y, idx, total):
    global ans
    if ans >= total+tmp*(3-idx):
        return
    if idx==3:
        ans = max(ans, total)
        return
    else:
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0<=nx<n and 0<=ny<m and visit[nx][ny] == 0:
                if idx==1:
                    visit[nx][ny] = 1
                    dfs(x, y, idx+1, total + lst[nx][ny])
                    visit[nx][ny]= 0
                
                visit[nx][ny] = 1
                dfs(nx, ny, idx+1, total + lst[nx][ny])
                visit[nx][ny] = 0

n,m=map(int,input().split())
lst=[list(map(int,input().split())) for _ in range(n)]

dx=[-1,0,1,0]
dy=[0,1,0,-1]
visit=[([0]*m) for _ in range(n)]
ans=0
tmp=max(map(max,lst))

for x in range(n):
    for y in range(m):
        visit[x][y] = 1
        dfs(x, y, 0, lst[x][y])
        visit[x][y] = 0

print(ans)