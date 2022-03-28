# https://www.acmicpc.net/problem/9663
# N-Queen
import sys
input=sys.stdin.readline

n=int(input())
ans=0
col=[0]*n
visit=[0]*n

def check(x):
    for i in range(x):
        if col[x]==col[i] or abs(col[i]-col[x])==x-i:
            # 같은 열에 퀸이 있거나, 왼쪽,오른쪽 대각선에 퀸이 있는 경우 -> 불가
            return False
    return True

def dfs(x):
    global ans
    if x==n:
        ans+=1
        return

    for i in range(n):
        if visit[i]:
            continue
        col[x]=i
        if check(x):
            visit[i]=True
            dfs(x+1)
            visit[i]=False

dfs(0)
print(ans)