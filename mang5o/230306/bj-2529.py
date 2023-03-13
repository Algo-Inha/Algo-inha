# https://www.acmicpc.net/problem/2529
# 부등호

import sys
k = int(sys.stdin.readline().rstrip())
operators = sys.stdin.readline().rstrip().split()
all_stack = [[[x], {x}] for x in range(10)]
min_str = '9'*(len(operators)+1)
max_str = '0'*(len(operators)+1)

while all_stack:
    tmp_elem = all_stack.pop()
    if len(tmp_elem[0]) == len(operators)+1:
        new_tmp_elem = ''
        for ii in tmp_elem[0]:
            new_tmp_elem += str(ii)
        if min_str > new_tmp_elem:
            min_str = new_tmp_elem
        if max_str < new_tmp_elem:
            max_str = new_tmp_elem
        continue
    tmp_elem_set = list(tmp_elem[1])
    if operators[len(tmp_elem[0])-1] == '>':
        for i in range(0, tmp_elem[0][-1]):
            if not i in tmp_elem[1]:
                tmp_tmp_elem = [[xx for xx in tmp_elem[0]], set([xx for xx in tmp_elem_set])]
                tmp_tmp_elem[0].append(i)
                tmp_tmp_elem[1].add(i)
                all_stack.append(tmp_tmp_elem)
    else:
        for i in range(tmp_elem[0][-1]+1, 10):
            if not i in tmp_elem[1]:
                tmp_tmp_elem = [[xx for xx in tmp_elem[0]], set([xx for xx in tmp_elem_set])]
                tmp_tmp_elem[0].append(i)
                tmp_tmp_elem[1].add(i)
                all_stack.append(tmp_tmp_elem)

print(max_str)
print(min_str)