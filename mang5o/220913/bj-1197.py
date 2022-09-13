# https://www.acmicpc.net/problem/1197
# 최소 스패닝 트리

import sys

# PRIM
V, E = map(int, sys.stdin.readline().rstrip().split())
all_edge = []
for _ in range(E):
    now_edge = list(map(int, sys.stdin.readline().rstrip().split()))
    if now_edge[0] > now_edge[1]:  # 문제엔 경우가 나오지 않았지만 두 정점이 오름차순이 아닐 수 있어서

        all_edge.append([now_edge[1]-1, now_edge[0]-1, now_edge[2], False])
    else:
        all_edge.append([now_edge[0]-1, now_edge[1]-1, now_edge[2], False])
all_edge.sort(key=lambda x: x[2])
now_active_vertex = [False for _ in range(V)]
now_active_vertex[0] = True
now_active_vertex_fig = 1
now_edge_len = 0
while now_active_vertex_fig < V:
    for edge in all_edge:
        if edge[3]:
            continue
        if not (now_active_vertex[edge[0]] and now_active_vertex[edge[1]]) \
                and not(not now_active_vertex[edge[0]] and not now_active_vertex[edge[1]]):
            now_active_vertex[edge[0]] = True
            now_active_vertex[edge[1]] = True
            edge[3] = True
            now_active_vertex_fig += 1
            now_edge_len += edge[2]
            break
        if now_active_vertex[edge[0]] and now_active_vertex[edge[1]]:
            edge[3] = True

print(now_edge_len)

