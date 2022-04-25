# https://www.acmicpc.net/problem/1932
# 정수 삼각형

import sys
N = int(sys.stdin.readline().rstrip())
all_input = []
all_output = []
for i in range(N):
    tmp_list = list(map(int, sys.stdin.readline().rstrip().split()))
    tmp_list = [0] + tmp_list + [0]  # Padding
    new_list = [tmp_list[x] for x in range(i+3)]  # Copy
    all_input.append(tmp_list)
    all_output.append(new_list)
for i in range(N):
    if i == 0:
        all_output[0][0] = all_input[0][0]
    else:
        for j in range(1, i + 2):
            for diff in range(2):
                # diff == 0 : 왼쪽 위
                # diff == 1 : 오른쪽 위
                all_output[i][j] = max(all_output[i][j], all_input[i][j] + all_output[i-1][j + diff - 1])
print(max(all_output[-1]))