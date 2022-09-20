# https://www.acmicpc.net/problem/11660
# 구간 합 구하기 5
import sys
input = sys.stdin.readline

n,m=map(int,input().split())
box_sum=[[0]*(n+1)]

for _ in range(n):
    tmp = [0] + list(map(int,input().split()))
    box_sum.append(tmp)

# 전체 행 구간 합
for i in range(1, n + 1):
    for j in range(1, n):
        box_sum[i][j + 1] += box_sum[i][j]
# 전체 열 구간 합
for j in range(1, n + 1):
    for i in range(1, n):
        box_sum[i + 1][j] += box_sum[i][j]

# (x1,y1) ~ (x2,y2) 구간 합
for _ in range(m):
    x1, y1, x2, y2 = map(int, input().split())
    print(box_sum[x2][y2] - box_sum[x1 - 1][y2] 
         - box_sum[x2][y1 - 1] + box_sum[x1 - 1][y1 - 1])