# https://www.acmicpc.net/problem/7562
# 나이트의 이동
from collections import deque
import sys
input = sys.stdin.readline

dx = [-1, -2, -2, -1, 1, 2, 2, 1]
dy = [2, 1, -1, -2, -2, -1, 1, 2]

def bfs(sx, sy, ax, ay):
    q = deque()
    q.append([sx, sy])
    s[sx][sy] = 1
    while q:
        a, b = q.popleft()
        if a == ax and b == ay:
            print(s[ax][ay] -1)
            return

        for i in range(8):
            x = a + dx[i]
            y = b + dy[i]
            if 0<=x<n and 0<=y<n and s[x][y] == 0:
                q.append([x, y])
                s[x][y] = s[a][b] + 1


t = int(input())
for _ in range(t):
    n = int(input())
    x, y = map(int, input().split())
    xx, yy = map(int, input().split())
    
    s = [[0] * n for i in range(n)]
    bfs(x, y, xx, yy)