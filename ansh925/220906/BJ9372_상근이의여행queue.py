# https://www.acmicpc.net/problem/9372
# 상근이의 여행
import sys
input = sys.stdin.readline

def bfs(x):
    q=[x]
    visit[x]=1
    cnt=0
    while q:
        tmp=q.pop()
        for nx in lst[tmp]:
            if visit[nx]==0:
                visit[nx]=1
                cnt += 1
                q.append(nx)
    return cnt

t=int(input())
for _ in range(t):
    n,m = map(int,input().split())
    lst = [[] for _ in range(n+1)]
    visit = [0 for _ in range(n+1)]
    for _ in range(m):
        a,b = map(int,input().split())
        lst[a].append(b)
        lst[b].append(a)
    
    ans=0
    for i in range(1,n+1):
        if visit[i]==0:
            ans += bfs(i)
    print(ans)