# https://www.acmicpc.net/problem/11057
# 오르막 수- BJ_11057

import sys
input = sys.stdin.readline

num = int(input())
temp = [[] for _ in range(num + 1)]
temp[0].append(0)
temp[1].append(10)

#   1   1   1   1   1   1   1   1   1   1
#   1   2   3   4   5   6   7   8   9   10
#   1   3   6   10  15  21  28  36  45  55
#   ...

if num > 1:
    for i in range(1, 11):
        temp[2].append(i)
    # [[0], [10], [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], [], [], ...]

    if num > 2:
        for i in range(3, num + 1):
            total = 0
            for j in range(10):
                total += temp[i-1][j]
                temp[i].append(total)
            print(temp)

print(sum(temp[-1])%10007)