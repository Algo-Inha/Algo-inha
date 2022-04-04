# https://www.acmicpc.net/problem/11279
# 최대 힙

import heapq
import sys
input=sys.stdin.readline

lst=[]
n=int(input())
for _ in range(n):
    x=int(input())
    
    if x==0:
        if lst:
            print(-1*heapq.heappop(lst))
            # heappush에서 반대로 넣어줬으므로, pop할 때도 다시 -를 붙여준다
        else:
            print(0)
    else:
        heapq.heappush(lst,-x)
        # heap에 push할 때, -를 붙여줌으로써 실제 우선순위와 반대로 들어가게함