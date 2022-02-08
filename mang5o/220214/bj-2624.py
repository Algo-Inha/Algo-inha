# https://www.acmicpc.net/problem/2624

# 어이없게도 sys.stdin 변환으로 타임아웃 해결
# 엄청난 시간초과 제출의 향연
import sys
now_val = int(sys.stdin.readline().rstrip())
now_in = int(sys.stdin.readline().rstrip())
all_figure = 0
wallet = []
for i in range(now_in):
    vals, nums = map(int, sys.stdin.readline().rstrip().split())
    if vals <= now_val:
        wallet.append((vals, nums))
        all_figure += nums
wallet.sort(reverse=True, key=lambda money: money[0])
dp_table = [[0 for _ in range(now_val + 1)] for _ in range(now_in + 1)]
dp_table[0][0] = 1
# print(dp_table)
for i in range(now_in):
    for j in range(now_val + 1):
        # now_cursor -> dp_table[i+1][j]
        tmp_add = 0
        for k in [tmp_idx * wallet[i][0] for tmp_idx in range(wallet[i][1] + 1)]:
            if j - k >= 0:
                tmp_add += dp_table[i][j - k]
        dp_table[i + 1][j] += tmp_add

print(dp_table[-1][-1])
