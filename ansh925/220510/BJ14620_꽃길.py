# https://www.acmicpc.net/problem/14620
# 꽃길

import sys
input=sys.stdin.readline

N=int(input())
graph=[list(map(int,input().split())) for _ in range(N)]

ans=99999
dx=[0,0,0,1,-1]
dy=[0,1,-1,0,0]     # 그대로,위,아래,오,왼

def sol(lst):
    result=0
    tmp=[]

    for t in lst:       # 각가의 좌표에 번호를 부여
        x = t//N
        y = t%N

        if x==0 or x==N-1 or y==0 or y==N-1:    # 가장자리에 위치하면 끝
            return 99999

        for i in range(5):
            nx=x+dx[i]
            ny=y+dy[i]                  # 꽃이 피었을 경우 차지하는 좌표
            tmp.append((nx,ny))           # 꽃 좌표 list에 append
            result += graph[nx][ny]     # 해당 좌표 비용 ++
        
    if len(set(tmp)) != 15:
        return 99999                    # 꽃 좌표 겹치면 끝
    return result                       # 안겹치면 return

for i in range(N*N):
    for j in range(i+1,N*N):
        for k in range(j+1,N*N):        # 꽃 3개에 대해 전체 탐색
            ans=min(ans,sol([i,j,k]))   # 최소값 선택

print(ans)