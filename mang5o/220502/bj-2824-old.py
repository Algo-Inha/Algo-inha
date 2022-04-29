# https://www.acmicpc.net/problem/2824
# 최대공약수
import sys
N = int(sys.stdin.readline().rstrip())
N_list = list(map(int, sys.stdin.readline().rstrip().split()))
M = int(sys.stdin.readline().rstrip())
M_list = list(map(int, sys.stdin.readline().rstrip().split()))

N_figures = []  # 소인수
M_figures = []  # 소인수

# N_list to N_figures
for fig in N_list:
    tmp_fig = fig
    now_divider = 2
    while tmp_fig != 1:
        if tmp_fig%now_divider ==0:
            N_figures.append(now_divider)
            tmp_fig = tmp_fig//now_divider
        else:
            now_divider += 1
# M_list to M_figures
for fig in M_list:
    tmp_fig = fig
    now_divider = 2
    while tmp_fig != 1:
        if tmp_fig%now_divider ==0:
            M_figures.append(now_divider)
            tmp_fig = tmp_fig//now_divider
        else:
            now_divider += 1

# N_figures와 M_figures 오름차순으로 정렬
N_figures.sort()
M_figures.sort()
now_N_cursor = 0
now_M_cursor = 0
max_fig = 1
while now_N_cursor < len(N_figures) and now_M_cursor < len(M_figures):
    N_cursor_fig = N_figures[now_N_cursor]
    M_cursor_fig = M_figures[now_M_cursor]
    if N_cursor_fig == M_cursor_fig:
        max_fig *= N_cursor_fig
        now_N_cursor += 1
        now_M_cursor += 1
    else:
        if N_cursor_fig < M_cursor_fig:
            now_N_cursor += 1
        else:
            now_M_cursor += 1

max_fig = str(max_fig)
if len(max_fig)>9:
    max_fig = max_fig[-9:]
print(max_fig)