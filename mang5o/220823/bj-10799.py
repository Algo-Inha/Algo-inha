# https://www.acmicpc.net/problem/10799
# 쇠막대기

import sys
all_str = sys.stdin.readline().rstrip()
all_str = all_str.replace("()","R") # 레이져
now_depth = 0  # 현재의 깊이
now_all_fig = 0  # 모든 쇠조각의 개수
for i in range(len(all_str)):
    if all_str[i] == "(":
        now_depth += 1
    elif all_str[i] == ")":
        now_all_fig += 1
        now_depth -= 1
    else:
        now_all_fig += now_depth
print(now_all_fig)