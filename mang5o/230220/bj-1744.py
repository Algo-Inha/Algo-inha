# https://www.acmicpc.net/problem/1744
# 수 묶기

import sys
N = int(sys.stdin.readline().rstrip())
minus_fig = []
plus_fig = []
zeros = 0
for i in range(N):
    fig = int(sys.stdin.readline().rstrip())
    if fig > 0:
        plus_fig.append(fig)
    elif fig < 0:
        minus_fig.append(fig)
    else:
        zeros += 1
minus_fig.sort(reverse=True)
plus_fig.sort()

all_figs = 0
while len(minus_fig) >= 2:
    all_figs += minus_fig.pop() * minus_fig.pop()
while len(plus_fig) >= 2:
    if plus_fig[-1]*plus_fig[-2] < plus_fig[-1]+plus_fig[-2]:
        all_figs += plus_fig.pop() + plus_fig.pop()
    else:
        all_figs += plus_fig.pop() * plus_fig.pop()
all_figs += sum(plus_fig)
if zeros == 0:
    all_figs += sum(minus_fig)
print(all_figs)