# https://www.acmicpc.net/problem/2493
# 탑
import sys
N = int(sys.stdin.readline())
all_list = list(map(int, sys.stdin.readline().split()))
all_answer = [0 for x in range(N)]
all_stack = []

for i in range(N):
    now_idx = N-i-1
    while len(all_stack)>0:
        if all_stack[-1][0] < all_list[now_idx]:
            all_answer[all_stack[-1][1]] = now_idx + 1
            all_stack.pop()
        else:
            break
    all_stack.append([all_list[now_idx], now_idx])

print(" ".join(list(map(str,all_answer))))
