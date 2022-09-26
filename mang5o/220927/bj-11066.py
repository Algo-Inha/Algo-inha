# https://www.acmicpc.net/problem/11066
# 파일 합치기

import sys
T = int(sys.stdin.readline().rstrip())
answers = []
for _ in range(T):
    K = int(sys.stdin.readline().rstrip())
    all_data = list(map(int, sys.stdin.readline().rstrip().split()))
    all_data_acc = [0]
    for i in range(K):
        all_data_acc.append(all_data_acc[-1] + all_data[i])  # n~m의 합은 [m+1] - [n]
    all_data_dp = [[0 for x in range(K)] for y in range(K)]
    for interval in range(1,K):
        for start_ptr in range(0,K):
            if start_ptr + interval >= K:
                continue
            min_val = 99999999999
            for tmp_cursor in range(start_ptr, start_ptr+interval):
                min_val = min(min_val,
                              all_data_dp[start_ptr][tmp_cursor]\
                              + all_data_dp[tmp_cursor+1][start_ptr+interval]\
                              + all_data_acc[start_ptr+interval+1] - all_data_acc[start_ptr])
            all_data_dp[start_ptr][start_ptr + interval] = min_val
    answers.append(all_data_dp[0][-1])
for answer in answers:
    print(answer)

