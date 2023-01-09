# https://www.acmicpc.net/problem/19621
# 회의실 배정 2- BJ_19621

import sys
input = sys.stdin.readline

n = int(input())
time = [0]  # 회의 진행 시간
total = [0]     # 최대 인원
for _ in range(n):
    a, b, t = map(int, input().split())
    time.append(t)
time.append(0)

# i 번째 회의를 진행할 경우 
# (i - 1)번째 최댓값이었던 회의 시간과 비교하여 
# 큰 경우를 i번째 회의 시간의 최댓값으로 
total.append(time[1])
for i in range(2, n + 1):   
    total.append(max(total[i - 2] + time[i], total[i - 1]))

print(total[-1])