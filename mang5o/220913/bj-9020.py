# https://www.acmicpc.net/problem/9020
# 골드바흐의 추측

import sys

T = int(sys.stdin.readline().rstrip())
all_query = []
for _ in range(T):
    all_query.append(int(sys.stdin.readline().rstrip()))
all_result = []

max_n = max(all_query)
all_fig = [True for _ in range(max_n + 1)]
all_fig[0] = False
all_fig[1] = False
for i in range(max_n + 1):
    if not all_fig[i]:
        continue
    interval = i
    now_start = i
    while True:
        now_start += interval
        if now_start <= max_n:
            all_fig[now_start] = False
        else:
            break

for query in all_query:
    now_insert = [0,0]
    min_ptr = 2
    max_ptr = query-2
    while min_ptr <= max_ptr:
        if all_fig[min_ptr] and all_fig[max_ptr]:
            now_insert = [min_ptr, max_ptr]
        min_ptr += 1
        max_ptr -= 1
    all_result.append(now_insert)

for result in all_result:
    print("{} {}".format(result[0], result[1]))