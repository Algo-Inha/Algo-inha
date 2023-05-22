# https://www.acmicpc.net/problem/15903
# 카드 합체 놀이

import sys
from queue import PriorityQueue
n, m = map(int, sys.stdin.readline().rstrip().split())
all_list = list(map(int, sys.stdin.readline().rstrip().split()))
p_que = PriorityQueue()
for i in all_list:
    p_que.put(i)

for i in range(m):
    tmp_elem = p_que.get() + p_que.get()
    p_que.put(tmp_elem)
    p_que.put(tmp_elem)

all_sum = 0
while not p_que.empty():
    all_sum += p_que.get()

print(all_sum)