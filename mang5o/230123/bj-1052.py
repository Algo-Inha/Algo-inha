# https://www.acmicpc.net/problem/1052
# 물병

import sys
# 2진수로 변경했을 때의 1의 개수 -> 병의 개수
# N 이상의 수 중에, 1의 숫자가 K개 이하인 최소값이 M일때, M-N 값을 구하기
N, K = map(int, sys.stdin.readline().rstrip().split())
diff = 0

now_fig = list(map(int,list(format(N, 'b')[::-1])))
all_one = 0 # 1의 개수
for i in range(len(now_fig)):
    if now_fig[i] == 1:
        all_one += 1

while all_one > K:
    # 1 더하기
    diff += 1
    if now_fig[-1] == 1:
        now_fig.append(0)
    if now_fig[0] == 0:
        all_one += 1
    now_fig[0] += 1
    for idx in range(len(now_fig)-1):
        if now_fig[idx] == 2:
            all_one -= 1
            now_fig[idx] = 0
            if now_fig[idx+1] == 0:
                all_one += 1
            now_fig[idx+1] += 1
        else:
            break

print(diff)