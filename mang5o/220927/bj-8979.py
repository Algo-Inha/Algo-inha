# https://www.acmicpc.net/problem/8979
# 올림픽

import sys
N, K = map(int, sys.stdin.readline().rstrip().split())
all_order = []
for _ in range(N):
    tmp_order = list(map(int, sys.stdin.readline().rstrip().split()))
    tmp_order.append(-1)
    all_order.append(tmp_order)
all_order.sort(key=lambda x : (x[1], x[2], x[3]), reverse=True)
all_order[0][4] = 1
if all_order[0][0] == K:
    print(1)
else:
    for i in range(1,N):
        if all_order[i][1] == all_order[i-1][1] and all_order[i][2] == all_order[i-1][2] and all_order[i][3] == all_order[i-1][3]:
            all_order[i][4] = all_order[i-1][4]
        else:
            all_order[i][4] = i+1
        if K == all_order[i][0]:
            print(all_order[i][4])
            break