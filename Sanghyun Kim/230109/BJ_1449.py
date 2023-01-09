# https://www.acmicpc.net/problem/1449
# 수리공 항승- BJ_1449

import sys
input = sys.stdin.readline

n, l = map(int, input().split())
graph = [False for _ in range(1001)]
cnt = 1

water = list(map(int, input().split()))
water.sort()

for i in water:
    graph[i] = True

end = water[0] + l - 1
for i in range(1, len(water)):
    if water[i] > end:
        end = water[i] + l - 1
        cnt += 1
print(cnt)