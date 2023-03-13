# https://www.acmicpc.net/problem/2240
# 자두나무

import sys
T, W = map(int, sys.stdin.readline().rstrip().split())
all_matrix = [int(sys.stdin.readline().rstrip())-1 for _ in range(T)] # 나무 번호를 0과 1로 변경
# dp_table[A][B][C] -> A시간에 B나무에 있으며 C번 움직인 뒤에 최대점수
dp_table = [[[-9999 for c in range(W+1)] for b in range(2)] for a in range(T+1)]

if T >= 2:
    if all_matrix[0] == 0:
        dp_table[1][0][0] = 1
        dp_table[1][1][0] = 0
    else:
        dp_table[1][1][1] = 1
        dp_table[1][0][0] = 0
    for a in range(2, T+1):
        for b in range(2):
            for c in range(W+1):
                if all_matrix[a-1] == b:
                    # 현재 위치로 사과가 떨어질 때
                    if c >= 1:
                        dp_table[a][b][c] = max(
                            dp_table[a - 1][1 - b][c - 1] + 1,
                            dp_table[a - 1][b][c] + 1
                        )
                    else:
                        dp_table[a][b][c] = dp_table[a - 1][b][c] + 1
                else:
                    # 반대 위치로 사과가 떨어질 때
                    if c >= 1:
                        dp_table[a][b][c] = max(
                            dp_table[a - 1][1 - b][c - 1],
                            dp_table[a - 1][b][c]
                        )
                    else:
                        dp_table[a][b][c] = dp_table[a - 1][b][c]
    # print(dp_table)
    print(max(dp_table[-1][0] + dp_table[-1][1]))
else:
    print(1)