# https://www.acmicpc.net/problem/1005
# ACM Craft

import sys
T = int(sys.stdin.readline().rstrip())
overall_result = []
for all_step in range(T):
    N, K = map(int, sys.stdin.readline().rstrip().split())
    all_d = list(map(int, sys.stdin.readline().rstrip().split()))
    all_edge = [[False for x in range(N)] for y in range(N)]
    for i in range(K):
        A, B = map(int, sys.stdin.readline().rstrip().split())
        A -= 1  # 번호 시작을 0번으로 옮김
        B -= 1  # 번호 시작을 0번으로 옮김
        all_edge[A][B] = True # A번이 완성되어야 B가 완성된다
    W = int(sys.stdin.readline().rstrip()) -1 # 마지막으로 만들어야 할 건물

    all_times = [-1 for i in range(N)]
    while True:
        if all_times[W] != -1:
            break
        now_build = False
        for i in range(N):
            if all_times[i] == -1:
                now_building = i
                now_can_flag = True
                max_time = -1
                for j in range(N):
                    if all_edge[j][i]: # i보다 j가 먼저 완성되어야 할 경우
                        if all_times[j] == -1:
                            now_can_flag = False # 하나라도 만들어지지 않았을 때
                            break
                        else:
                            max_time = max(max_time, all_times[j] + all_d[i])
                if now_can_flag: # 만들 수 있을 경우
                    if max_time==-1:
                        max_time = all_d[i]
                    all_times[i] = max_time
                    now_build = True
    # print(all_times)
    overall_result.append(all_times[W])
for i in range(T):
    print(overall_result[i])