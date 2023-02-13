# https://www.acmicpc.net/problem/14620
# 꽃길- BJ_14620

from itertools import combinations
import sys
input = sys.stdin.readline

n = int(input())
graph = [[] for _ in range(n)]
for i in range(n):
    graph[i] = list(map(int, input().split()))
# 동 서 남 북 으로 체크
dxdy = [(1, 0), (-1, 0), (0, 1), (0, -1)]

# 가능한 모든 좌표 경우의수
dot = list(combinations([(x, y) for x in range(1, n - 1) for y in range(1, n - 1)], 3))
ans = []

for i in range(len(dot)):
    flower = [[False for _ in range(n)] for _ in range(n)]  # 꽃이 있는 자리: True
    subAns = 0
    temp = False
    for x, y in dot[i]:
        if flower[x][y] == False:   # 꽃 씨앗 없을 경우
            flower[x][y] = True
            subAns += graph[x][y]
            for dx, dy in dxdy:     
                if flower[x + dx][y + dy] == False:     # 꽃잎 없을 경우
                    flower[x + dx][y + dy] = True
                    subAns += graph[x + dx][y + dy]
                else:                                   # 꽃잎 이미 있을 경우
                    temp = True
        else:                       # 꽃 씨앗 이미 있는 경우
            temp = True
        if temp:
            break
    if not temp:        # 꽃이 지지 않고 모두 필 경우
        ans.append(subAns)

if ans:
    print(min(ans))
else:
    print(0)

