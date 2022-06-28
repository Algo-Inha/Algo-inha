# https://www.acmicpc.net/problem/11286
# 절댓값 힙

import sys
import heapq
input=sys.stdin.readline

lst=[]
n=int(input())
for _ in range(n):
    x=int(input())
    if x==0:
        if lst:
            print(heapq.heappop(lst)[1])
        else:
            print(0)
    else:
        heapq.heappush(lst,(abs(x),x))