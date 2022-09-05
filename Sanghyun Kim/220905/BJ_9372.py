# https://www.acmicpc.net/problem/9372
# 상근이의 여행- BJ_9372

from collections import deque
import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    n_graph = [[] for _ in range(n + 1)]
    count = 0
    for _ in range(m):
        a, b = map(int, input().split())
        n_graph[a].append(b)
        n_graph[b].append(a)
    visited = [False for _ in range(n + 1)]
    dfs = deque([1])
    visited[1] = True
    while dfs:
        x = dfs.popleft()
        count += 1
        for i in n_graph[x]:
            if visited[i] == False:
                dfs.append(i)
                visited[i] = True
    print(count - 1)