# https://www.acmicpc.net/problem/1806
# 부분합

import sys
N, S = map(int,sys.stdin.readline().rstrip().split())
all_arr = list(map(int, sys.stdin.readline().rstrip().split()))
all_acc = [0] # 누적합 행렬
all_ptr = 0
for i in range(N): # 누적합 만들기
    all_ptr += all_arr[i]
    all_acc.append(all_ptr)
# print(all_acc)

start_ptr = 0
end_ptr = 0
shortest_interval = N+10 # Maximum
while True:
    if all_acc[end_ptr]-all_acc[start_ptr] >= S:
        shortest_interval = min(shortest_interval, end_ptr-start_ptr)
        start_ptr += 1
    else:
        end_ptr += 1
    if end_ptr>N:
        break

if shortest_interval == N+10:
    print(0)
else:
    print(shortest_interval)