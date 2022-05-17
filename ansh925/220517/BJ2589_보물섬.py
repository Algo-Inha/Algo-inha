# https://www.acmicpc.net/problem/2589
# 보물섬

import sys
input=sys.stdin.readline
from collections import deque

n,m=map(int,input().split())
lst=[list(input()) for _ in range(n)]

dx=[1,-1,0,0]
dy=[0,0,-1,1]

def bfs(i,j):
    q=deque()
    q.append([i,j])
    result=0

    while q:
        a,b=q.popleft()
        for k in range(4):
            x=a+dx[k]
            y=b+dy[k]
            if 0<=x<n and 0<=y<m and visit[x][y]==0 and lst[x][y]!='W':
                visit[x][y]=1
                lst[x][y]=lst[a][b]+1
                result=max(result,lst[x][y])
                q.append([x,y])
    return result

ans=0
for i in range(n):
    for j in range(m):
        if lst[i][j] != 'W':
            visit=[[0]*m for _ in range(n)]
            lst[i][j]=0
            visit[i][j]=1
            ans=max(ans,bfs(i,j))
            
print(ans)