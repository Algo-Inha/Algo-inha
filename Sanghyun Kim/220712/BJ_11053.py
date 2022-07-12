# https://www.acmicpc.net/problem/11053
# 가장 긴 증가하는 부분 수열

n = int(input())
num = list(map(int, input().split()))
count = [1 for _ in range(len(num))]

for i in range(len(num)):
    for j in range(i):
        if num[j] < num[i]:
            count[i] = max(count[i], count[j] + 1)
print(max(count))
