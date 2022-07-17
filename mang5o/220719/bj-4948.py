# 베르트랑 공준
# https://www.acmicpc.net/problem/4948

import sys

all_mat = []
while True:
    tmp_inp = int(sys.stdin.readline().rstrip().rstrip())
    if tmp_inp == 0:
        break
    all_mat.append(tmp_inp)

max_fig = max(all_mat) * 2
fig_mat = [True for _ in range(max_fig+1)]
fig_mat[0] = False
fig_mat[1] = False # 1은 소수가 아니다
for i in range(max_fig+1):
    if fig_mat[i]:
        start_cursor = i*2
        interval_cursor = i
        while True:
            if start_cursor <= max_fig:
                fig_mat[start_cursor] = False
                start_cursor += interval_cursor
            else:
                break

acc_mat = []
acc_start = 0
for i in range(max_fig+1):
    acc_start += fig_mat[i]
    acc_mat.append(acc_start)


for query in all_mat:
    print(acc_mat[query*2] - acc_mat[query])