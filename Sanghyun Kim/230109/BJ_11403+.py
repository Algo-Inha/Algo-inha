# https://www.acmicpc.net/problem/11403
# 경로 찾기- BJ_11403

import sys
input = sys.stdin.readline

n = int(input())
graph = []
for _ in range(n):
    graph.append(list(map(int, input().split())))
    
#플로이드-워셜 알고리즘
for k in range(n): #경로 for문이 가장 상위 단계여야 누락되지 않는다
    for i in range(n):
        for j in range(n): 
            if graph[i][j] == 1 or (graph[i][k] == 1 and graph[k][j] == 1):
                graph[i][j] = 1

for i in range(n):
    print(*graph[i])