# https://www.acmicpc.net/problem/18870
# 좌표 압축
import sys
input = sys.stdin.readline

n=int(input())
lst=list(map(int,input().split()))
lst2=set(lst)           # set함수로 중복 제거

ans=[]
for i in lst:           # lst를 돌며
    cnt=0
    for j in lst2:      # 중복을 제거한 lst2에서
        if i > j:       # lst가 lst2보다 큰 경우에 cnt++
            cnt += 1
    ans.append(cnt)     # 큰 경우의 횟수를 ans list에 append
print(*ans)