# https://www.acmicpc.net/problem/1931
# 회의실 배정- BJ_1931

import sys
input = sys.stdin.readline

n = int(input())
q = []
count = 0
end = 0
for _ in range(n):
    q.append(list(map(int, input().split())))

q = sorted(q, key = lambda x:x[0])
q = sorted(q, key = lambda x:x[1])

for i, j in q:
    if i >= end:
        count += 1
        end = j
print(count)
            