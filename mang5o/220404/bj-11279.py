# https://www.acmicpc.net/problem/11279
# 최대 힙

import sys, heapq
N = int(sys.stdin.readline().rstrip())
pq = []
heapq.heapify(pq)
for case in range(N):
    x = int(sys.stdin.readline().rstrip())
    if x == 0:
        if len(pq)==0:
            print(0)
        else:
            print(heapq.heappop(pq)*(-1))
    else:
        heapq.heappush(pq, x*(-1))
