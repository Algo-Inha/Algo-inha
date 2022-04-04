# https://www.acmicpc.net/problem/11000
# 강의실 배정

import sys
import heapq
input=sys.stdin.readline

heap,lst=[],[]
n=int(input())
for i in range(n):
    a, b = map(int, input().split())
    lst.append([a, b])

lst.sort(key=lambda x: x[0])    # 강의시작시간 기준으로 sort
                                # 각 배열에서 0번째를 기준으로 정렬. ex) [[a,b],[c,d],[e,f]] -> a,c,e를 기준으로 정렬

heapq.heappush(heap, lst[0][1])
cnt=1

for i in range(1, n):
    if heap[0] > lst[i][0]:
        heapq.heappush(heap, lst[i][1])     # heap에 push할때마다 cnt++
        cnt+=1
    else:
        heapq.heappop(heap)
        heapq.heappush(heap, lst[i][1])     # 이때는 pop한 뒤 push이므로 cnt++ 안함

print(cnt)  #print(len(heap))