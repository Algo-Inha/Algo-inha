# https://www.acmicpc.net/problem/18222
# 투에-모스 문자열

import sys
k = int(sys.stdin.readline().rstrip()) -1
minus_flag = False

# 점화식
# f(x*2) = f(x)
# f(x*2 + 1) = !f(x)

while k != 0:
    if k%2 == 1:
        k //= 2
        minus_flag = not minus_flag
    else:
        k //= 2

if minus_flag:
    print(1)
else:
    print(0)