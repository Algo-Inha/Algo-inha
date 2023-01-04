# https://www.acmicpc.net/problem/11047
# 동전 0

import sys
N, K = map(int, sys.stdin.readline().rstrip().split())
all_coin = []
for i in range(N):
    cost = int(sys.stdin.readline().rstrip())
    if cost <= K:
        all_coin.append(cost)

# (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)
coins = 0
for i in range(len(all_coin)):
    now_coin_idx = len(all_coin) - i - 1
    K_diff = K - (K % all_coin[now_coin_idx])
    coins += K_diff // all_coin[now_coin_idx]
    K -= K_diff

print(coins)