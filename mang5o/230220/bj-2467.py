# https://www.acmicpc.net/problem/2467
# 용액

import sys
N = int(sys.stdin.readline().rstrip())
all_fig = list(map(int, sys.stdin.readline().rstrip().split()))
start_ptr = 0
end_ptr = N-1
min_abs = 999999999999999
ptr_position = [start_ptr, end_ptr]
while start_ptr < end_ptr:
    val_diff = all_fig[end_ptr] + all_fig[start_ptr]
    if abs(val_diff) < min_abs:
        ptr_position = [start_ptr, end_ptr]
        min_abs = abs(val_diff)
    if val_diff < 0:
        start_ptr += 1
    elif val_diff > 0:
        end_ptr -= 1
    else:
        break
print("{} {}".format(all_fig[ptr_position[0]], all_fig[ptr_position[1]]))