# https://www.acmicpc.net/problem/11660
# 구간 합 구하기 5
import sys

N, M = map(int, sys.stdin.readline().rstrip().split())
all_map = []
for _ in range(N):
    all_map.append(list(map(int, sys.stdin.readline().rstrip().split())))

all_query = []
for _ in range(M):
    all_query.append(list(map(int, sys.stdin.readline().rstrip().split())))

all_accum = [[0 for _ in range(N+1)]]
for y in range(N):
    now_line = [0]
    for x in range(N):
        now_line.append(now_line[-1] + all_accum[-1][x+1] + all_map[y][x] - all_accum[-1][x])
    all_accum.append(now_line)

for query in all_query:
    now_answer = all_accum[query[2]][query[3]] - all_accum[query[2]][query[1]-1] - all_accum[query[0]-1][query[3]] + all_accum[query[0]-1][query[1]-1]
    print(now_answer)