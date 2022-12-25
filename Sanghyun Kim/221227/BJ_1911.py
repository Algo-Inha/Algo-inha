# https://www.acmicpc.net/problem/1911
# 흙길 보수하기- BJ_1911

import sys
input = sys.stdin.readline

n, l = map(int, input().split())
p = list()
for _ in range(n):
    p.append(list(map(int, input().split())))
p.sort(key=lambda x:x[0])

loc = 0     # 마지막 널빤지 위치
cnt = 0   # 널빤지 수

for start, end in p:    
    if loc > start: # 이전 웅덩이 덮고 남은 널빤지가 현재 웅덩이 덮을 경우
        start = loc
    while start < end:  # 널빤지 개수 count
        start += l
        cnt += 1
    loc = start

print(cnt)