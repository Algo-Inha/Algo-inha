# https://www.acmicpc.net/problem/1197
# 최소 스패닝 트리
import sys
import heapq
input=sys.stdin.readline

v,e = map(int,input().split())
lst=[[] for _ in range(v+1)]
visit=[0]*(v+1)
ans=0

for _ in range(e):
    a,b,c = map(int,input().split())
    lst[a].append((c,b))
    lst[b].append((c,a))

q=[(0,1)]
while q:
    node = heapq.heappop(q)
    if visit[node[1]]==False:
        visit[node[1]]=True
        ans += node[0]
        for i in lst[node[1]]:
            heapq.heappush(q,i)

print(ans)