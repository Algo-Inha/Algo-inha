# https://www.acmicpc.net/problem/14500
# 테트로미노

from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
tet = []

for i in range(n):
    tet.append(list(map(int, input().split())))

# 동 서 남 북
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

# 테트로미노 지나간 자리: True
temp = [[False for _ in range(m)] for _ in range(n)]

count = 0
sum_max = 0
total = 0

for i in range(n):
    for j in range(m):
        temp[i][j] = True
        count += 1
        total += tet[i][j]
        q = deque([(i, j)])
        while(q):
            # 동 서 남 북 3번 이동: 가능한 모든 경우의 수를 비교?
            if count == 4:
                sum_max = max(sum_max, total)
                break
            x, y = q.popleft()
            # 브루트 포스 알고리즘
            for a in range(4):
                nx = x + dx[a]
                ny = y + dy[a]
                # 범위 넘어가지 않게
                if nx >= 0 and nx < n and ny >= 0 and ny < m:
                    if temp[nx][ny] == False:
                        # 겹치지 않게
                        temp[nx][ny] = True
                        # 이동된 칸에 쓰인 수들의 합
                        total += tet[nx][ny]

                        q.append((nx, ny))
                        count += 1

# DFS 알고리즘을 사용한 브루트 포스 알고리즘
# ㅗ 모양의 경우 DFS 알고리즘 사용이 힘들어 따로 처리