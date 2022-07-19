# https://www.acmicpc.net/problem/4948
# 베르트랑 공준

# 에라토스테네스의 체
from math import sqrt
import sys
input = sys.stdin.readline

while 1:
    n = int(input())
    count = 0
    if n == 0:
        break
    n_ = [False for _ in range(2 * n + 1)]
    # 소수와 약수의 성질
    # 소수의 성질: 1과 자기 자신을 제외한 약수를 갖지 않는다.
    # 약수를 갖는 수의 성질: 1부터 자기 자신의 제곱근 사이에 약수의 절반을 갖는다.
    # -> 2n의 제곱근보다 작거나 같은 수까지 에라토스테네스의 체를 이용해 소수 판별
    for i in range(2, int(sqrt(2 * n)) + 1):
        for j in range(n, 2 * n + 1):
            if n_[j] == False and j % i == 0:
                n_[j] = True

    for j in range(n + 1, 2 * n + 1):
        if n_[j] == False:
            count += 1
    print(count)

# 시간 초과