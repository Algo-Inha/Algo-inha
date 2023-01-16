# https://www.acmicpc.net/problem/1485
# 정사각형- BJ_1485

import sys
input = sys.stdin.readline

for _ in range(int(input())):
    ans = 0
    points = [[] for _ in range(4)]
    for i in range(4):
        points[i] = list(map(int, input().split()))
        
    points.sort(key = lambda x : x[1])
    points.sort(key = lambda x : x[0])

    diag1 = abs(points[-1][0] - points[0][0]) ** 2 + abs(points[-1][1] - points[0][1]) ** 2
    diag2 = abs(points[2][0] - points[1][0]) ** 2 + abs(points[1][1] - points[2][1]) ** 2
    len1 = abs(points[1][0] - points[0][0]) ** 2 + abs(points[1][1] - points[0][1]) ** 2
    len2 = abs(points[2][0] - points[0][0]) ** 2 + abs(points[2][1] - points[0][1]) ** 2

    # 두 변의 길이, 두 대각선의 길이가 같을 경우
    if diag1 == diag2 and diag1 > 0 and diag2 > 0 and len1 == len2 and len1 > 0 and len2 > 0:
        ans = 1
    print(ans)