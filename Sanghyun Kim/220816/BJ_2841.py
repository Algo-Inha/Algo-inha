# https://www.acmicpc.net/problem/2841
# 외계인의 기타 연주- BJ_2841.py

import sys
input = sys.stdin.readline

n, p = map(int, input().split())
push = [[0] for _ in range(n + 1)]
count = 0

for _ in range(n):
    n_, p_ = map(int, input().split())
    # n_, p_ 에 대해
    # n_번째 줄의 가장 높은 프렛보다 p_ 번째 프렛이 높다면
    # p_ 번째 프랫을 누르고, count 추가한다.
    if p_ > push[n_][-1]:
        push[n_].append(p_)
        count += 1
    # n_번째 줄의 가장 높은 프렛보다 p_번째 프랫이 낮다면
    # p_번째 프랫이 더 커질 때까지 누르고 있던 프랫을 떼고, count를 추가한다.
    else:
        while push[n_][-1] > p_:
            push[n_].pop()
            count += 1
    # 마지막 프랫이 p_ 프랫보다 낮다면
    # p_ 프랫을 누르고, count 추가한다.
        if push[n_][-1] != p_:
            push[n_].append(p_)
            count += 1

print(count)

# 960ms