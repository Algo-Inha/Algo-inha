# https://www.acmicpc.net/problem/2606
# 바이러스

import sys
from queue import Queue

nodes = int(sys.stdin.readline().rstrip())
edges = int(sys.stdin.readline().rstrip())
now_queue = Queue()

adj_matrix = [[False for i in range(nodes)] for j in range(nodes)]
visited_matrix = [False for i in range(nodes)]
for eg in range(edges):
    tmp_a, tmp_b = map(int, sys.stdin.readline().rstrip().split())
    adj_matrix[tmp_a-1][tmp_b-1] = True
    adj_matrix[tmp_b-1][tmp_a-1] = True

now_queue.put(0)
visited_matrix[0] = True

while now_queue.qsize() > 0:
    tmp_queue = now_queue.get()
    for i in range(nodes):
        if adj_matrix[tmp_queue][i] and not visited_matrix[i]:
            visited_matrix[i] = True
            now_queue.put(i)

cnt = 0
for eg in range(nodes):
    if visited_matrix[eg]:
        cnt += 1
print(cnt-1)