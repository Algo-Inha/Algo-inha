# https://www.acmicpc.net/problem/4948
# 베르트랑 공준

# 에라토스테네스의 체
from math import sqrt
import sys
input = sys.stdin.readline

# 소수 list
num = []

# 시간 초과 나서 범위 내의 n에 대해 소수를 판별하고 실행한다.
for i in range(2, 123456 * 2 + 1):
    count = 0
    # 소수와 약수의 성질
    # 소수의 성질: 1과 자기 자신을 제외한 약수를 갖지 않는다.
    # 약수를 갖는 수의 성질: 1부터 자기 자신의 제곱근 사이에 약수의 절반을 갖는다.
    # -> 2n의 제곱근보다 작거나 같은 수까지 에라토스테네스의 체를 이용해 소수 판별
    for j in range(2, int(sqrt(i)) + 1):
        if i % j == 0:
            count += 1
            break

    if count == 0:
        num.append(i)

while 1:
    n = int(input())
    sosu = 0
    if n == 0:
        break
    for i in num:
        if n < i <= 2*n:
            sosu += 1
    print(sosu)

