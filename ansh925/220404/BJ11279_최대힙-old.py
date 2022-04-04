# https://www.acmicpc.net/problem/11279
# 최대 힙

import sys
input=sys.stdin.readline

lst=[]

n=int(input())
for _ in range(n):
    x=int(input())
    
    if x!=0:
        lst.append(x)
    elif len(lst)==0:
        print(0)
    else:
        lst.sort()
        print(lst[-1])
        lst.pop()