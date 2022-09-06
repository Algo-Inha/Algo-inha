# https://www.acmicpc.net/problem/1747
# 소수&팰린드롬- BJ_1747

import math

n = int(input())
max_pal = 0

if n > 1:
    for i in range(n, 1000000000001):
        br = False

        # 소수 판별
        for j in range(2, int(math.sqrt(i)) + 1):
            if i % j == 0:
                br = True
                break
        if br:
            continue
        
        # 팰린드롬인 수 판별
        temp = str(i)
        if len(temp) > 1:
            for j in range(len(temp)//2 + 1):
                if temp[j] != temp[-(j + 1)]:
                    br = True
                    break
        if br:
            continue
        max_pal = i
        break
else:
    max_pal = 2

print(max_pal)