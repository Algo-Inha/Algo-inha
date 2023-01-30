import sys
input = sys.stdin.readline

from collections import deque

def bfs(s):
    cnt = 1
    q = deque()
    q.append(s)
    visit = [False for _ in range(n+1)]
    visit[s] = True
    
    while q:
        now = q.popleft()

        for next_node in graph[now]:
            if visit[next_node] == False:
                visit[next_node] = True
                cnt += 1
                q.append(next_node)
    
    return cnt

n, m = map(int,input().split())

max = 1
answer = []

graph = [[] for _ in range(n+1)]

for i in range(m):
    a,b = map(int,input().split())
    graph[b].append(a)

for i in range(1,n+1):
    cnt = bfs(i)
    if cnt > max:
        max = cnt
        answer = []
        answer.append(i)
    elif cnt == max:
        answer.append(i)
        

for i in answer:
    print(i,end=" ")