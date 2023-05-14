# https://www.acmicpc.net/problem/10942
# 팰린드롬?

import sys
N = int(sys.stdin.readline().rstrip())
N_list = list(map(int, sys.stdin.readline().rstrip().split()))
M = int(sys.stdin.readline().rstrip())

all_quary = []
for _ in range(M):
    all_quary.append(list(map(int, sys.stdin.readline().rstrip().split())))

dp_table = [[False for _ in range(N)] for __ in range(N)]
for i in range(N):
    dp_table[i][i] = True
for i in range(N-1):
    if N_list[i] == N_list[i+1]:
        dp_table[i][i+1] = True

for interval in range(2, N):
    for j in range(N-interval):
        start_ptr = j
        end_ptr = j+interval
        if N_list[start_ptr] == N_list[end_ptr] and dp_table[start_ptr+1][end_ptr-1]:
            dp_table[start_ptr][end_ptr] = True

all_answer = []
for i in range(M):
    start_ptr = all_quary[i][0]-1
    end_ptr = all_quary[i][1]-1
    if dp_table[start_ptr][end_ptr]:
        all_answer.append(1)
    else:
        all_answer.append(0)

for answer in all_answer:
    print(answer)