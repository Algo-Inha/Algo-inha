# https://www.acmicpc.net/problem/15486
# 퇴사 2
import sys
input=sys.stdin.readline

n = int(input())
T,P=[],[]
dp=[0]*(n+1)

for _ in range(n):
    t,p = map(int,input().split())
    T.append(t)             # 상담 일수
    P.append(p)             # 상담 수익

tmp=0                       # 수익을 저장할 변수 선언
for i in range(n):
    tmp = max(tmp,dp[i])    # 이전까지 수익(tmp)과 dp 중 큰값 update
    if i+T[i] > n:          # 퇴사일을 넘기면 pass
        continue
    
    #print(i+1, dp[i+T[i]], tmp+P[i])
    # (이번 상담이 끝나는 시점의 수익)과 (이전까지 수익 + 이번 수익) 중 큰값 update
    dp[i+T[i]] = max(dp[i+T[i]], tmp+P[i])  

print(max(dp))