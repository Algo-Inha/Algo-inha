# https://www.acmicpc.net/problem/11403
# 경로 찾기- BJ_11403

import sys
input = sys.stdin.readline

n = int(input())
roadMap = [[] for _ in range(n)]    # 경로 맵
ans = [[0 for _ in range(n)] for _ in range(n)]
cnt = 0

for i in range(n):
    iMap = list(map(int, input().split()))
    for j in range(len(iMap)):
        if iMap[j] == 1:
            roadMap[i].append(j)

def hasRoad(ans, roadMap, i, ith, cnt):
    cnt += 1
    if roadMap[i]:
        for j in roadMap[i]:
            ans[ith][j] = 1
            if cnt <= n:
                hasRoad(ans, roadMap, j, ith, cnt)


for i in range(n):
    ith = i
    hasRoad(ans, roadMap, i, ith, cnt)
    print(*ans[i])