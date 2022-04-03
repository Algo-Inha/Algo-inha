# https://www.acmicpc.net/problem/11000
# 강의실 배정

import sys, heapq
N = int(sys.stdin.readline().rstrip())
all_case = []
heapq.heapify(all_case)
for i in range(N):
    tmp_case = list(map(int, sys.stdin.readline().rstrip().split()))
    tmp_elem = tmp_case[0]*10000000000 + tmp_case[1]
    heapq.heappush(all_case, tmp_elem)

all_classes = []
heapq.heapify(all_classes)
while len(all_case)>0:
    now_fastest = heapq.heappop(all_case)
    now_start = now_fastest//10000000000
    now_end = now_fastest % 10000000000

    if len(all_classes) == 0:
        heapq.heappush(all_classes, now_end)
    else:
        now_fastest_class = heapq.heappop(all_classes)
        if now_fastest_class <= now_start:
            heapq.heappush(all_classes, now_end)
        else:
            heapq.heappush(all_classes, now_end)
            heapq.heappush(all_classes, now_fastest_class)

print(len(all_classes))
