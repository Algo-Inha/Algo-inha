# https://www.acmicpc.net/problem/11053
# 가장 긴 증가하는 부분 수열- BJ_11053

import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
a_ = [0 for _ in range(n)]

for i in range(n):
    for j in range(i):
        if a[i]>a[j] and a_[i]<a_[j]:
            a_[i] = a_[j]
    a_[i] += 1
print(max(a_))