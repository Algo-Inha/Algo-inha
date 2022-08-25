# https://www.acmicpc.net/problem/2688
# 줄어들지 않아- BJ_2688

n = [[1,1,1,1,1,1,1,1,1,1]]
n_sum = [10]

for i in range(64):
    n_sub = []
    for j in range(10):
        sub_total = 0
        for k in range(j, 10):
            sub_total += n[i][k]
        n_sub.append(sub_total)
    n.append(n_sub)
    n_sum.append(sum(n_sub))

t = int(input())
for _ in range(t):
    print(n_sum[int(input()) - 1])