# https://www.acmicpc.net/problem/2824
# 최대공약수
import sys
N = int(sys.stdin.readline().rstrip())
N_list = list(map(int, sys.stdin.readline().rstrip().split()))
M = int(sys.stdin.readline().rstrip())
M_list = list(map(int, sys.stdin.readline().rstrip().split()))

A = 1
B = 1
for i in N_list:
    A *= i
for j in M_list:
    B *= j

while B>0:
    mod = A % B
    A = B
    B = mod

A = str(A)
if len(A)>9:
    A = A[-9:]
print(A)