import sys
N = int(sys.stdin.readline().rstrip())
fig_lst = list(map(int, sys.stdin.readline().rstrip().split()))
max_fig = 0
new_lst = [0] * N
for i_diff in range(N):
    i = N-i_diff-1
    now_val = -1
    max_fig = max(max_fig, fig_lst[i])
    if fig_lst[i] < max_fig:
        for j in range(i+1,N):
            if fig_lst[i] < fig_lst[j]:
                now_val = fig_lst[j]
                break
    new_lst[i] = now_val

ret_str = ""
for i in range(N):
    ret_str += str(new_lst[i])
    if i != N-1:
        ret_str += " "

print(ret_str)