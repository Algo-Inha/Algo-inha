# https://www.acmicpc.net/problem/2467
# 용액- BJ_2467

import sys
input = sys.stdin.readline

n = int(input())
koi = list(map(int, input().split()))

start, end = 0, n - 1
ansStart = start
ansEnd = end
ans = abs(koi[start] + koi[end])

while start < end:                  # start, end가 반전되면 안됨
    sumKoi = koi[start] + koi[end]  # 용액 특성값의 합
    
    if abs(sumKoi) < ans:           # 용액 특성절댓값이 최솟값보다 작으면,
        ansStart = start            # 교체
        ansEnd = end
        ans = abs(sumKoi)

        if ans == 0:                # 0이면 끝
            break
    
    if sumKoi < 0:                  # 용액 특성값의 합이 음수일 경우
        start += 1
    else:                           # 용액 특성값의 합이 0 또는 양수일 경우
        end -= 1

print(koi[ansStart], koi[ansEnd])