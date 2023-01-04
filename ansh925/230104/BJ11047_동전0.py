# https://www.acmicpc.net/problem/11047
# 동전0

n,k = map(int,input().split())
lst=[]
for _ in range(n):
    lst.append(int(input()))

cnt = 0
for i in range(n-1,0,-1):   # 역순 탐색
    if k==0:                # 잔액 0이면 종료
        break
    cnt = cnt + k//lst[i]   # 몫만큼 cnt++
    k = k % lst[i]          # 나머지만큼 k 유지
print(cnt)