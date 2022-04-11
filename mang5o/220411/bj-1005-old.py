import sys
from collections import deque
N, K = map(int, sys.stdin.readline().rstrip().split())
all_d = list(map(int, sys.stdin.readline().rstrip().split()))
all_edge = [[False for x in range(N)] for y in range(N)]
for i in range(K):
    A, B = map(int, sys.stdin.readline().rstrip().split())
    A -= 1  # 번호 시작을 0번으로 옮김
    B -= 1  # 번호 시작을 0번으로 옮김
    all_edge[A][B] = True
    all_edge[B][A] = True  # 대칭
W = int(sys.stdin.readline().rstrip()) -1 # 마지막으로 만들어야 할 건물
all_time = [9999999999 for i in range(N)]
all_deque = deque()
all_deque.append(0)
all_time[0] = all_d[0]
while len(all_deque)>0:
    now_building = all_deque.popleft()
    now_time = all_d[now_building]
    for i in range(N):
        if all_edge[now_building][i]:
            tmp_time = now_time + all_d[i]
            if all_time[i] > tmp_time:
                all_time[i] = min(all_time[i], now_time + all_d[i])
                all_deque.append(i)

print(all_time[W] + all_d[W])

