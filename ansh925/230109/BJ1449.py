# https://www.acmicpc.net/problem/1449
# 수리공 항승

n, l = map(int, input().split())
lst = list(map(int, input().split()))
lst.sort()

s = lst[0]
e = lst[0] + l

cnt = 1
for i in range(n):
    if s <= lst[i] < e:
        continue
    else:
        s = lst[i]
        e = lst[i] + l
        cnt += 1
print(cnt)