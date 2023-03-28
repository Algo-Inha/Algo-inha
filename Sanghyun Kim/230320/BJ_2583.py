# https://www.acmicpc.net/problem/2583
# 영역 구하기- BJ_2583

from collections import deque
import sys
input = sys.stdin.readline

y, x, num = map(int, input().split())
# x, y 크기 직사각형
graph = [[0] * (y + 1) for _ in range(x + 1)]

for i in range(num):
    x0, y0, x1, y1 = map(int, input().split())
    for j in range(x0 + 1, x1 + 1):
        for k in range(y0 + 1, y1 + 1):
            graph[j][k] = -1

# 서 동 남 북
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# 넓이 list
count_li = []
count = 0

q = deque()
for i in range(1, x + 1):
    for j in range(1, y + 1):
        count = 0
        if graph[i][j] == 0:
            count += 1
            q.append([i, j])
            graph[i][j] = 1

            while q:
                x_, y_ = q.popleft()
                for k in range(4):
                    nx = x_ + dx[k]
                    ny = y_ + dy[k]

                    if nx > 0 and ny > 0 and nx <= x and ny <= y:
                        if graph[nx][ny] == 0:
                            count += 1
                            q.append([nx, ny])
                            graph[nx][ny] = 1
        if count > 0:
            count_li.append(count)
count_li = sorted(count_li)
print(len(count_li))
print(*count_li)
