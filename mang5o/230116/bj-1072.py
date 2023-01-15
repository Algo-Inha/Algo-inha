# https://www.acmicpc.net/problem/1072
# 게임

import sys, math
X, Y = map(int, sys.stdin.readline().rstrip().split())
if Y*100 >= 99*X:
    print(-1)
else:
    now_ratio = math.floor(round(100*Y/X, 10))/100
    # (Y+n)/(X+n) 이 now_ratio+0.01보다 크거나 같다
    # (Y+n)/(X+n) = now_ratio+0.01
    # (Y+n) = (now_ratio+0.01)*X + (now_ratio+0.01)*n
    # Y - (now_ratio+0.01)*X = (now_ratio+0.01 - 1) * n
    n = (Y - (now_ratio+0.01)*X) / (now_ratio - 0.99)
    n = round(n, 3)
    print(math.ceil(n))