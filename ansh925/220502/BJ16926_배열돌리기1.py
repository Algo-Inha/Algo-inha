# acmicpc.net/problem/16926
# 배열 돌리기 1

import sys
input = sys.stdin.readline

n,m,r = map(int,input().split())
graph = [list(map(int,input().split())) for _ in range(n)]

for _ in range(r):
    for i in range(min(n, m) // 2):
        x, y = i, i
        temp = graph[x][y]

        for j in range(i + 1, n - i):  # 아래 방향 이동
            x = j
            prev_value = graph[x][y]
            graph[x][y] = temp
            temp = prev_value
        for j in range(i + 1, m - i):  # 오른쪽 방향 이동
            y = j
            prev_value = graph[x][y]
            graph[x][y] = temp
            temp = prev_value
        for j in range(i + 1, n - i):  # 위 방향 이동
            x = n - j - 1
            prev_value = graph[x][y]
            graph[x][y] = temp
            temp = prev_value
        for j in range(i + 1, m - i):  # 왼쪽 방향 이동
            y = m - j -1
            prev_value = graph[x][y]
            graph[x][y] = temp
            temp = prev_value
    # 바깥 사각형 다 돌린 후, 안쪽 사각형에서 반복 수행

for i in range(n):
    for j in range(m):
        print(graph[i][j], end=' ')
    print()