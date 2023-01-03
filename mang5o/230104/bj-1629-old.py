import sys
A, B, C = map(int, sys.stdin.readline().rstrip().split())
now_val = A % C
all_pattern = [now_val]
cycle_start = -1
check_set = set()
for i in range(B):
    tmp_val = (all_pattern[-1] * A) % C
    if tmp_val in check_set:
        for ii in range(len(all_pattern)):
            if all_pattern[ii] == tmp_val:
                cycle_start = ii
                cycle_end = i+1
                break
    if cycle_start >= 0:
        break
    all_pattern.append(tmp_val)
    check_set.add(tmp_val)

if cycle_start == -1:
    print(all_pattern[-1])
else:
    cycle_len = cycle_end - cycle_start
    pattern_idx = (B-cycle_start)%cycle_end + cycle_start
    print(all_pattern[pattern_idx])