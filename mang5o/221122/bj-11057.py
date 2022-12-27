# https://www.acmicpc.net/problem/11057
# 오르막 수

import sys
N = int(sys.stdin.readline().rstrip())
# N자리수 일 때 U(Up)이 들어갈 수 있는 자리 N+1, U의 개수 9개
# N+1개의 자리에 U 9개를 넣는 방법의 수 -> (N+1+9-1 (N+9 중에 9개 선택하기))
# (N+9)!/(N)!/(9)!
# 9! = 362880

fact = 1
for i in range(N+1, N+10):
    fact *= i
fact //= 362880
print(fact%10007)