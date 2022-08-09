# https://www.acmicpc.net/problem/17298
# 오큰수- BJ_17298

from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
A = list(map(int, input().split()))

big = [-1 for _ in range(n)]
stack = deque()

for i in range(n):
    while stack and (stack[-1][0] < A[i]):
        temp, temp_idx = stack.pop()
        big[temp_idx] = A[i]
    stack.append([A[i], i])

print(*big)