# https://www.acmicpc.net/problem/1654
# 랜선 자르기

k, n = map(int, input().split())
k_len = list()
rest = list()

for _ in range(k):
    k_len.append(int(input()))

x_min = 1
x_max = max(k_len)

while x_min <= x_max:
    count = 0
    x_mid = (x_min + x_max) // 2

    for i in range(k):
        count += k_len[i] // x_mid

    if count < n:
        x_max = x_mid - 1
    elif count >= n:
        x_min = x_mid + 1

print(x_max)