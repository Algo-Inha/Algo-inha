# https://www.acmicpc.net/problem/13458
# 시험 감독

import math
N = int(input())
persons = list(map(int, input().split()))
B, C = map(int, input().split())
sum_num = len(persons)
for i in range(len(persons)):
    persons[i] = max(persons[i]-B, 0)
for i in persons:
    sum_num += math.ceil(i / C)
print(sum_num)
