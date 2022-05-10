# https://www.acmicpc.net/problem/3020
# 개똥벌레

import sys
input=sys.stdin.readline

N,H=map(int,input().split())

up=[0]*(H+1)    # 종유석
down=[0]*(H+1)  # 석순
crash=N         # 파괴한 장애물 수
ans=0           # 날아간 구간(높이)

for i in range(N):
    if i%2==0:
        down[int(input())]+=1       # 석순 길이
    else:
        up[int(input())]+=1         # 종유석 길이

for j in range(H-1,0,-1):       
    up[j] += up[j+1]
    down[j] += down[j+1]

for k in range(1,H+1):
    if crash > (down[k]+up[H-k+1]):
        crash = (down[k]+up[H-k+1])
        ans=1
    elif crash == (down[k]+up[H-k+1]):
        ans+=1

print(crash, ans)