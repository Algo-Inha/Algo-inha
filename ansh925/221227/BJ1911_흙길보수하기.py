# https://www.acmicpc.net/problem/1911
# 흙길 보수하기
import sys
input = sys.stdin.readline

N, L = map(int, input().split())
pool = [list(map(int, input().split())) for _ in range(N)]

pool.sort(key=lambda x:x[0])    # 웅덩이 좌표 정렬
cur,cnt = 0,0       # 마지막 널빤지 위치, 널빤지 갯수

for s, e in pool:
    if s > e:
        continue    
    if cur > s:     # 이전 널빤지가 해당 웅덩이를 덮고있는 경우 
        s = cur
    while s < e:    # 널빤지의 개수
        s += L
        cnt += 1
    cur = s

print(cnt)