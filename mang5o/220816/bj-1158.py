# https://www.acmicpc.net/problem/1158
# 요세푸스 문제

import sys
from collections import deque
N, K = map(int, sys.stdin.readline().rstrip().split())
order_queue = deque()
ret_str = "<"
for i in range(N):
    order_queue.append(i+1)
while order_queue:
    for i in range(K-1):
        tmp_elem = order_queue.popleft()
        order_queue.append(tmp_elem)
    ret_str += "{}, ".format(order_queue.popleft())
ret_str = ret_str[:-2] + ">"
print(ret_str)