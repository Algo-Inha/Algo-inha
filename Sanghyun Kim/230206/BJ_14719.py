# https://www.acmicpc.net/problem/14719
# 빗물

import sys
input = sys.stdin.readline

h, w = map(int, input().split())
temp = list(map(int, input().split()))

ans = 0
for i in range(1, w - 1):   # i 기준 
    leftMax = max(temp[:i])        # 왼쪽으로 가장 높은
    rightMax = max(temp[i+1:])     # 오른쪽으로 가장 높은

    comp = min(leftMax, rightMax)    # 왼쪽, 오른쪽 중 더 낮은

    if temp[i] < comp:      # i번째보다 낮으면 빗물 존재
        ans += comp - temp[i]

print(ans)