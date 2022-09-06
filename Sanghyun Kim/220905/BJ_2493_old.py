# https://www.acmicpc.net/problem/2493
# 탑- BJ_2493

from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
top = list(map(int, input().split()))
answer = list()

if n==1:
    print(0)
else:
    for i in range(len(top)):
        none = True
        if i==0:
            answer.append(0)
        else:
            if answer[-1] == 0:
                for j in reversed(range(answer[-1], i)):
                    if top[j] >= top[i]:
                        answer.append(j + 1)
                        none = False
                        break
                if none:
                    answer.append(0)
            else:
                for j in reversed(range(answer[-1] - 1, i)):
                    if top[j] >= top[i]:
                        answer.append(j + 1)
                        none = False
                        break
                if none:
                    answer.append(0)

    for i in answer:
        print(i, end=' ')