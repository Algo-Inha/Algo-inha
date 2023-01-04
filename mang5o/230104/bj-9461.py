# https://www.acmicpc.net/problem/9461
# 파도반 수열

import sys
T = int(sys.stdin.readline().rstrip())
all_case = [int(sys.stdin.readline().rstrip()) for _ in range(T)]
max_val = max(all_case)

all_triangle = [1,1,1,2,2]
for i in range(max_val):
    if i < 5:
        continue
    else:
        all_triangle.append(all_triangle[i-1] + all_triangle[i-5])

for i in range(T):
    print(all_triangle[all_case[i]-1])