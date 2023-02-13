# https://www.acmicpc.net/problem/2502
# 떡 먹는 호랑이- BJ_2502

import sys
input = sys.stdin.readline

d, k = map(int, input().split())

temp = [0 for _ in range(d)]
temp[0] = 'x'
temp[1] = 'y'
for i in range(2, d):
    temp[i] = temp[i - 2] + temp[i - 1]

firNum = temp[-1].count('x')    # 첫째날 count
secNum = temp[-1].count('y')    # 둘째날 count

a = 1   # 첫째날 개수
b = 0   # 둘째날 개수
while 1:
    if (k - firNum * a) % secNum == 0:  # 1차 방정식 풀기
        b = (k - firNum * a) // secNum
        break
    a += 1

print(a)
print(b)