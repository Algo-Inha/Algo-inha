# https://www.acmicpc.net/problem/1495
# 기타리스트- BJ_1495

from collections import deque
import sys
input = sys.stdin.readline

n, s, m = map(int, input().split())
v = list(map(int, input().split()))
# (n x m) 의 deque으로 만든 n줄짜리 list
temp = deque([[False for _ in range(m + 1)] for _ in range(n + 1)])
temp[0][s] = True

# list 한줄씩 넘어가면서 v[i - 1] 빼고, 더하며 
# 조건 만족하면 True 체크
for i in range(1, n + 1):
    for j in range(m + 1):
        if temp[i - 1][j] == True:
            if j - v[i - 1] >= 0:
                temp[i][j - v[i - 1]] = True
            if j + v[i - 1] <= m:
                temp[i][j + v[i - 1]] = True

total = deque()
# 가장 마지막 list에 대해 True 일 경우 total list에 입력
for i in range(m + 1):
    if temp[-1][i] == True:
        total.append(i)
# total list의 최댓값 출력
if total:
    print(max(total))
# total이 비어있으면, -1 출력
else:
    print(-1)

# 전혀 생각지도 못한 메모리 활용... 감탄이 나온다...