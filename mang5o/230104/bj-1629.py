# https://www.acmicpc.net/problem/1629
# 곱셈

import sys
A, B, C = map(int, sys.stdin.readline().rstrip().split())
B_binary = str(format(B, 'b'))[::-1] # Reverse
all_mod, now_fig = A%C, 1
for i in range(len(B_binary)):
    if B_binary[i] == '1':
        now_fig = (now_fig*all_mod)%C
    all_mod = (all_mod*all_mod)%C
print(now_fig)