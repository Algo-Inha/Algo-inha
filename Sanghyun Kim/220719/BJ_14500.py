# https://www.acmicpc.net/problem/14500
# 테트로미노

# 브루트 포스
# count가 4가 되는순간 최대합을 갱신한다.
# dfs, 시작지점 0,0, 이동가능한지 확인,

dx = [-1,1,0,0]
dy = [0,0,1,-1]

result = 0

def dfs(s_x, s_y, cnt, sum):
    global result, max_val
    visited[s_x][s_y] = True

    # 남은 블럭이 모두 최댓값이라 해도 현재의 최대를 넘길수 없을때 조기종료 해버림
    if sum + max_val * (4-cnt) <= result:
        return

    # 사각형 4개가 된 순간 최댓값을 갱신한다.
    if cnt == 4:
        result = max(result, sum)
        return

    # 상하좌우 이동
    for i in range(4):
        # 이동가능하면
        d_x, d_y = s_x+dx[i], s_y+dy[i]
        if 0<=d_x<n and 0<= d_y <m and not visited[d_x][d_y]:
                dfs(d_x,d_y, cnt+1, sum+graph[d_x][d_y])
                visited[d_x][d_y] = False # 목적지를 풀어주는것임

def adjust(graph, s_x, s_y):
    global result
    adj = []
    for i in range(4):
        # 이동가능하면
        if s_x+dx[i] >=0 and s_x+dx[i]<n and s_y+dy[i] >=0 and s_y+dy[i] <m:
            adj.append(graph[s_x+dx[i]][s_y+dy[i]])

    if len(adj)>=3:
        temp = graph[s_x][s_y]+sum(sorted(adj, reverse=True)[:3])
        result = max(result, temp)


import sys
input = sys.stdin.readline

n, m = map(int, input().split()) 

graph = []

visited = [[False] * m for _ in range(n)]

for _ in range(n):
    graph.append(list(map(int, input().split())))

max_val = max(max(*graph))

for i in range(n):
    for j in range(m):
        dfs(i,j,1,graph[i][j])
        visited[i][j] = False
        adjust(graph, i,j)

print(result)