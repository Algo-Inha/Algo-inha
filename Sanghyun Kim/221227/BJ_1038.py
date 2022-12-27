# https://www.acmicpc.net/problem/1038
# 감소하는 수- BJ_1038

import sys
from itertools import combinations

input = sys.stdin.readline

n = int(input())

temp = list()
for i in range(1, 11):  # 1부터 10까지
    for j in combinations(range(0, 10), i): # 10개 중 i개씩 모든 경우의 수
        comb = list(j)
        comb.sort(reverse=True) # 각 내림차순 정렬
        temp.append(int("".join(map(str, comb))))   # string으로 바꿔 합치고 다시 int로

temp.sort() # 전체 정렬

if n >= len(temp):  # 9876543210보다 큰 수는 없음
    print(-1)
else:
    print(temp[n])