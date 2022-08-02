# https://www.acmicpc.net/problem/2468
# 안전 영역- BJ_2468

import sys
from collections import deque

n = int(input())
area = []
min_h = 100
max_h = 1
water = [[False for _ in range(n)] for _ in range(n)]
count = [0 for _ in range(101)]

# 동 서 남 북
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

for i in range(n):
    area.append(list(map(int, input().split())))
    min_h = min(min(area[i]), min_h)
    max_h = max(max(area[i]), max_h)

# 가장 낮은 높이보다 적은 양의 비가 내릴 경우를 깜빡할 수 있음!!
for i in range(min_h - 1, max_h):
    for y in range(n):
        for x in range(n):
            if area[y][x] > i and water[y][x] == False:
                water[y][x] = True
                count[i] += 1
                # dfs
                dfs = deque([(y, x)])
                while dfs:
                    y_, x_ = dfs.popleft()
                    for j in range(4):
                        nx = x_ + dx[j]
                        ny = y_ + dy[j]
                        if nx >= 0 and nx < n and ny >= 0 and ny < n and area[ny][nx] > i and water[ny][nx] == False:
                            dfs.append((ny, nx))
                            water[ny][nx] = True
    water = [[False for _ in range(n)] for _ in range(n)]

print(max(count))