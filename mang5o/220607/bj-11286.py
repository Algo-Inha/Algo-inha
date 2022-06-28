# https://www.acmicpc.net/problem/11286
# 절댓값 힙

import sys
import heapq
N = int(sys.stdin.readline().rstrip())
all_list = []
heapq.heapify(all_list)
heapq_size = 0
return_list = []
for i in range(N):
    tmp_elem = float(sys.stdin.readline().rstrip())
    if tmp_elem != 0:
        if tmp_elem > 0:
            heapq_size += 1
            heapq.heappush(all_list, tmp_elem + 0.5)
        else:
            heapq_size += 1
            heapq.heappush(all_list, tmp_elem*(-1))
    else:
        if heapq_size == 0:
            return_list.append(0)
        else:
            heapq_size += -1
            smallest = heapq.heappop(all_list)
            if smallest % 1 == 0.5:
                return_list.append(int(smallest))
            else:
                return_list.append(int(smallest*(-1)))
for i in return_list:
    print(i)


