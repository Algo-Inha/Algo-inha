# https://www.acmicpc.net/problem/1654
# 랜선 자르기

import sys


def check_lan(dividend, param_arr):
    all_fig = 0
    for par in param_arr:
        all_fig += (par // dividend)
    return all_fig


K, N = map(int, sys.stdin.readline().rstrip().split())
all_arr = []
for i in range(K):
    all_arr.append(int(sys.stdin.readline().rstrip()))

# 끝점을 2의 제곱수로 맞춤
max_val = max(all_arr)
end_ptr = 1
while max_val > end_ptr:
    end_ptr *= 2

start_ptr = 0
while end_ptr - start_ptr >= 2:
    center_ptr = (end_ptr + start_ptr) // 2
    if check_lan(center_ptr, all_arr) >= N:
        start_ptr = center_ptr
    else:
        end_ptr = center_ptr

if check_lan(end_ptr, all_arr) < N:
    print(start_ptr)
else:
    print(end_ptr)