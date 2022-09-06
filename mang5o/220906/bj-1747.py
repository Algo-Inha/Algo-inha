# https://www.acmicpc.net/problem/1747
# 소수&팰린드롬
import sys
N = int(sys.stdin.readline())
max_fig = 10**(len(str(N))) + 2
max_fig *= 2 # 제한점을 어디로 둬야하나....
all_fig = [True for x in range(max_fig)] # 소수라면 True
for i in range(max_fig):
    if i<=1:
        all_fig[i] = False
    else:
        if all_fig[i]:
            now_cursor = 2*i
            while now_cursor < max_fig:
                all_fig[now_cursor] = False
                now_cursor += i
for i in range(max_fig):
    if i<N:
        continue
    if all_fig[i]: # 일단 소수 확인
        now_fig_str = str(i)
        check_len = len(now_fig_str)//2
        now_sym_flag = True
        for idx in range(check_len):
            if now_fig_str[idx] != now_fig_str[-1-idx]:
                now_sym_flag = False
                break
        if now_sym_flag:
            print(i)
            break
