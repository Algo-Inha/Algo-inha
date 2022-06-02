# https://www.acmicpc.net/problem/14500
# 테트로미노

import sys
from collections import deque
N, M = map(int, sys.stdin.readline().rstrip().split())
all_map = []
for i in range(N):
    all_map.append(list(map(int, sys.stdin.readline().rstrip().split())))

poliomino = [
    # [[0, 0], [0, 1], [0, 2], [0, 3]], 이부분은 코드상으로 직접 사용
    [[0, 0], [0, 1], [1, 0], [1, 1]],
    [[0, 0], [1, 0], [2, 0], [2, 1]],
    [[0, 0], [1, 0], [1, 1], [2, 1]],
    [[0, 0], [0, 1], [0, 2], [1, 1]]
]

all_deque = deque()
for y in range(N):
    for x in range(M-3):
        all_deque.append([[(y,x)],1]) # 도형 시작점 리스트, 현재 들어간 도형

while all_deque:
    tmp_deque = all_deque.pop()

# 풀다가 일단 정지... 다음주에 이어서 풀이