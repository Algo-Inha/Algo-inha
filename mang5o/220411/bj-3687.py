# https://www.acmicpc.net/problem/3687
# 성냥개비
import sys

T = int(sys.stdin.readline().rstrip())
all_input = []
max_input = 0
for i in range(T):
    now_input = int(sys.stdin.readline().rstrip())
    all_input.append(now_input)
    max_input = max(max_input, now_input) # dp테이블을 최대값까지만 만들기 위해서

# 성냥개비 필요 개수
# 1  2  3  4  5  6  7  8  9  0
# 2, 5, 5, 4, 5, 6, 3, 7, 6, 6

dp_min = [0, 0, 1, 7, 4, 2, 6, 8] # ~7까지
dp_max = [0, 0, 1, 7, 11, 71, 111, 711] # ~7까지

min_diff = [0, 0, 1, 7, 4, 2, 0, 8]
max_diff = [0, 0, 1, 7, 4, 5, 9, 8]
for i in range(8, max_input+1):
    # min value 생성
    now_min = -1
    for diff in range(2, 8): # 2~7
        if i-diff>=2:
            if now_min==-1:
                now_min = dp_min[i-diff]*10 + min_diff[diff]
            else:
                now_min = min(now_min, dp_min[i-diff]*10 + min_diff[diff])
    dp_min.append(now_min)
    # max value 생성
    now_max = 0
    for diff in range(2, 8): # 2~7
        if i-diff >= 2:
            now_max = max(now_max, dp_max[i-diff]*10 + max_diff[diff])
    dp_max.append(now_max)

# print(dp_min)
# print(dp_max)

for step in range(T):
    print("{} {}".format(dp_min[all_input[step]], dp_max[all_input[step]]))