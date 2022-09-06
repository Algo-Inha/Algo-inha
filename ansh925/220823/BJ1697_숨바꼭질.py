# https://www.acmicpc.net/problem/1697
# 숨바꼭질
import sys
from collections import deque
input=sys.stdin.readline

def bfs(x):
    q=deque()
    q.append(x)                   # 수빈이 위치에서 시작
    while q:
        x=q.popleft()

        if x==k:                  # 동생을 잡으면 return 
            return check[x]       # 방문 체크를 노드 깊이로 설정 시,
                                  # 여기까지 걸린 시간을 의미하기도 함
        for nx in (x-1,x+1,2*x):  # 뒤로, 앞으로, 순간이동 3가지 경우 고려
            if 0<=nx<100001 and not check[nx]:  # 범위 제한 & 방문 체크
                check[nx] = check[x]+1          # 방문 안했으면 이전 위치값 +1
                q.append(nx)      # deque에 다음 위치 push

check=[0]*100001
n,k=map(int,input().split())
print(bfs(n))