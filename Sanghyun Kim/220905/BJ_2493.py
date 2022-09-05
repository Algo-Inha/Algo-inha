# https://www.acmicpc.net/problem/2493
# 탑- BJ_2493

import sys
input = sys.stdin.readline

n = int(input())
tower = list(map(int, input().split()))
stack = []
temp = [0] * n

# 전체 탑을 돌며
for i in range(n):
    t = tower[i]
    # stack이 존재하고, 스택의 가장 마지막 원소값이 현재 탑보다 작으면
    # 무시한다
    while stack and tower[stack[-1]] < t:
        stack.pop()
    # stack이 존재하면,
    # 스택의 가장 마지막 원소값 + 1 높이의 탑 레이저 수신
    if stack:
        temp[i] = stack[-1] + 1
    stack.append(i)

print(' '.join(list(map(str, temp))))