# https://www.acmicpc.net/problem/2493
# 탑
import sys
input=sys.stdin.readline

n=int(input())
height = list(map(int,input().split()))
s=[]
ans=[0]*n

for i in range(n):
    while s:
        if height[s[-1]] < height[i]:
            s.pop()
        else:
            ans[i] = s[-1] + 1
            break
    s.append(i)
print(*ans)