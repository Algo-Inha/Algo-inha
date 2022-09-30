# https://www.acmicpc.net/problem/1764
# 듣보잡
import sys
input=sys.stdin.readline

n,m = map(int,input().split())

d_name=[input() for _ in range(n)]
b_name=[input() for _ in range(m)]

ans=list(set(d_name) & set(b_name))

ans.sort()
print(len(ans))
print(''.join(ans))