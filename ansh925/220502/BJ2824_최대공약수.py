# https://www.acmicpc.net/problem/2824
# 최대공약수

import sys
input = sys.stdin.readline

N = int(input())
N_lst = list(map(int,input().split()))
M = int(input())
M_lst = list(map(int,input().split()))

# 최대공약수 gcd함수 (유클리드 호제법)
def gcd(a,b) :
    while b > 0 :
        tmp = a%b
        a = b
        b = tmp
    return a

# N_lst, M_lst 전부 곱한값 A,B
A = 1; B = 1
for i in N_lst:  
    A *= i  
for j in M_lst:  
    B *= j  

ans = '%s' %str(gcd(A,B))[-9:]  # str형태로 최대공약수 9자리까지만 출력 제한
print(ans)