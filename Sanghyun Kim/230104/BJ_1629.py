# https://www.acmicpc.net/problem/1629
# 곱셈- BJ_1629

import sys
input = sys.stdin.readline

a, b, c = map(int, input().split())

def multi (a,n):
  if n == 1:
      return a%c
  else:
      tmp = multi(a,n//2)
      if n %2 ==0:
          return (tmp * tmp) % c
      else:
          return (tmp  * tmp *a) %c
          
print(multi(a,b))