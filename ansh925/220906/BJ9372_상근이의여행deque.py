# https://www.acmicpc.net/problem/9372
# 상근이의 여행
import sys
from collections import deque
input = sys.stdin.readline

def bfs(x):
    q = deque([x])
    visit[x] = 1
    cnt = 0

    while q:
        q.popleft()
        for i in range(1, n + 1):
            if visit[i] == 0:
                q.append(i)
                visit[i] = 1
                cnt += 1
    return cnt

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    graph = [[0] * (n + 1) for i in range(n + 1)]

    for i in range(m):
        a, b = map(int, input().split())
        graph[b][a] = 1
    visit = [0] * (n + 1)

    print(bfs(1))