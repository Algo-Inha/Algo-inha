# https://www.acmicpc.net/problem/2502
# 떡 먹는 호랑이

import sys
D, K = map(int, sys.stdin.readline().rstrip().split())
all_days = [[1,0], [0,1]] # Element -> [첫째날 준 떡의 개수, 둘째날 준 떡의 개수]
while len(all_days) < D:
    all_days.append([
        all_days[-1][0]+all_days[-2][0],
        all_days[-1][1]+all_days[-2][1]
    ])
x = all_days[-1] # 수학적으로 보면 x[0]*n + x[1]*m = K 가 된다
for i in range(1,K):
    # n이 i일 때 tmp_x1 = x[1]*m
    tmp_x1 = K - x[0]*i
    # tmp_x1 가 x[1]로 나누어 떨어지면 됨
    if tmp_x1 % x[1] == 0:
        if 1 <= i <= tmp_x1//x[1]:
            print(i)
            print(tmp_x1//x[1])
            break