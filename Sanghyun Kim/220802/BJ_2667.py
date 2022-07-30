# https://www.acmicpc.net/problem/2667
# 단지번호붙이기- BJ_2667
import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
home = list()
house = [[False for _ in range(n)] for _ in range(n)]
total_count = []

# 동 서 남 북
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

for i in range(n):
    home.append(input().rstrip())

for i in range(n):
    for j in range(n):
        count = 0
        if home[j][i] == '1' and house[j][i] == False:
            count += 1
            house[j][i] = True
            dfs = deque([(j, i)])
            while dfs:
                y, x = dfs.popleft()
                for k in range(4):
                    nx = x + dx[k]
                    ny = y + dy[k]
                    if nx >= 0 and nx < n and ny >= 0 and ny < n:
                        if home[ny][nx] == '1' and house[ny][nx] == False:
                            count += 1
                            dfs.append((ny, nx))
                            house[ny][nx] = True
        if count > 0:
            total_count.append(count)

total = sorted(total_count)
print(len(total))
if len(total) == 0:
    print(0)
else:
    for i in range(len(total)):
        print(total[i])
