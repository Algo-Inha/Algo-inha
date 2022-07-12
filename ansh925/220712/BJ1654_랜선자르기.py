# https://www.acmicpc.net/problem/1654
# 랜선 자르기
import sys
input=sys.stdin.readline

k,n = map(int,input().split())
lan = [int(input()) for _ in range(k)]
start=1; end=max(lan)       # 이분 탐색 처음,끝 설정

while start <= end:
    mid = (start+end)//2    # 이분 탐색 중간 설정
    cnt=0
    for i in lan:
        cnt += i//mid       # 나눠진 랜선의 수

    if cnt >= n:
        start = mid+1
    else:
        end = mid-1

print(end)