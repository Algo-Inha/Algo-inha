# https://www.acmicpc.net/problem/2841
# 외계인의 기타 연주- BJ_2841.py

n, p = map(int, input().split())
flat = [[False for _ in range(p + 1)] for _ in range(n + 1)]
max_p = [0 for _ in range(n + 1)]

count = 0
for _ in range(n):
    n_, p_ = map(int, input().split())
    if max_p[n_] < p_:
        count += 1
        max_p[n_] = p_
        flat[n_][p_] = True
    elif max_p[n_] == p_:
        continue
    else:
        for i in range(p_ + 1, max_p[n_] + 1):
            if flat[n_][i] == True:
                flat[n_][i] = False
                count += 1
        if flat[n_][p_] == False:
            flat[n_][p_] = True
            count += 1
        max_p[n_] = p_

print(count)

# 메모리 초과