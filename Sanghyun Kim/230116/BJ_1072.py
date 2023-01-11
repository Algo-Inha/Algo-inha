# https://www.acmicpc.net/problem/1072
# 게임- BJ_1072.py

import sys
input = sys.stdin.readline

x, y = map(int, input().rsplit())
victory = y * 100 // x
ans = sys.maxsize   # 파이썬 최대 정수값: 9223372036854775807
l, r = 1, x

while l <= r:   # 이분탐색
    mid = (l + r) // 2

    curr_vic = (y + mid) * 100 // (x + mid)
   
    if curr_vic > victory:
        ans = min(mid,ans)
        r = mid - 1
    else:
        l = mid + 1

if ans == sys.maxsize:
    print(-1)
else:
    print(ans)