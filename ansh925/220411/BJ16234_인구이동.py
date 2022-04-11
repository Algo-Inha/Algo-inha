# https://www.acmicpc.net/problem/16234
# 인구 이동
from collections import deque
import sys
input=sys.stdin.readline

lst=[]
dx=[1,-1,0,0]
dy=[0,0,-1,1]

n,l,r=map(int,input().split())
for _ in range(n):
    lst.append(list(map(int,input().split())))

def bfs(a,b):
    q=deque()
    q.append([a,b])
    tmp=[]
    tmp.append([a,b])

    # deque가 빌때까지 4방향을 탐색하며 조건을 충족할 때 visit=1로 바꿔주고 q,tmp list에 좌표값 append
    while q:
        x,y=q.popleft()
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            if 0<=nx<n and 0<=ny<n and visit[nx][ny]==0:
                if l <= abs(lst[nx][ny]-lst[x][y]) <= r:
                    visit[nx][ny]=1
                    q.append([nx,ny])
                    tmp.append([nx,ny])
    return tmp

cnt=0
while True:
    visit=[[0]*n for _ in range(n)]
    check=False
    for i in range(n):
        for j in range(n):
            if visit[i][j]==0:
                visit[i][j]=1
                k=bfs(i,j)
                if len(k)>1:
                    check=True
                    num=sum(lst[x][y] for x,y in k)//len(k)
                    for x,y in k:
                        lst[x][y]=num
    if check==False:
        break
    cnt+=1
print(cnt)