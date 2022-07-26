# https://www.acmicpc.net/problem/1107
# 리모컨
import sys
input=sys.stdin.readline

n=int(input())
m=int(input())
b=list(map(int,input().split()))

ans = abs(100-n)                # +/- 로만 이동하는 경우

for num in range(1000001):
    num=str(num)
    
    for j in range(len(num)):
        if int(num[j]) in b:    # 고장난 버튼인지 확인
            break
        elif j==len(num)-1:     # 정상 버튼만으로 마지막까지 오면
            ans=min(ans, abs(int(num)-n)+len(num))  # 최소값 비교해서 갱신
print(ans)