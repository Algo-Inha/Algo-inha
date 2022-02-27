# https://www.acmicpc.net/problem/17142
# 연구소 3
import sys
from queue import Queue
import itertools

dir_mat = ((0, 1), (1, 0), (0, -1), (-1, 0))
N, M = map(int, sys.stdin.readline().rstrip().split())
orig_map_matrix = []
virus_array = []
for i in range(N):
    tmp_input = list(map(int, sys.stdin.readline().rstrip().split()))
    for ti in range(len(tmp_input)):
        if tmp_input[ti] == 2:
            virus_array.append((i, ti))
    orig_map_matrix.append(tmp_input)
