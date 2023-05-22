# https://www.acmicpc.net/problem/17615
# 볼 모으기

import sys
N = int(sys.stdin.readline().rstrip())
balls = list(sys.stdin.readline().rstrip())
balls_check = [
    [1 if balls[x] == 'R' else 0 for x in range(N)],
    [1 if balls[-x-1] == 'R' else 0 for x in range(N)],
    [0 if balls[x] == 'R' else 1 for x in range(N)],
    [0 if balls[-x-1] == 'R' else 1 for x in range(N)]
]

min_val = 9999999999
for i in range(4):
    now_case = 0
    now_balls = balls_check[i]
    now_1 = False
    for j in range(N):
        if now_balls[j] == 1:
            now_1 = True
        else:
            if now_1:
                now_case += 1
    min_val = min(min_val, now_case)
print(min_val)
