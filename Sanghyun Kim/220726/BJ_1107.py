# https://www.acmicpc.net/problem/1107
# 리모컨- BJ_1107

from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
broken = deque(map(int, input().split()))
min_count = abs(100 - n)

# 가능한 모든 경우의 수에 대해
# 고장난 숫자가 포함된 채널을 제외하고
# 가장 적게 리모콘을 누른 경우
for i in range(1000001):
    i = str(i)
    for j in range(len(i)):
        if int(i[j]) in broken:
            break
        elif j == len(i) - 1:
            min_count = min(min_count, abs(int(i) - n) + len(i))
print(min_count)
