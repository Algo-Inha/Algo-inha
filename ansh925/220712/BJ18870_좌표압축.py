# https://www.acmicpc.net/problem/18870
# 좌표 압축
import sys
input = sys.stdin.readline

n=int(input())
lst=list(map(int,input().split()))
lst2=sorted(set(lst))       # 중복 제거한 lst를 정렬해서 lst2에 저장

# 'lst2:index' 형태의 dictionary 사용해서 시간 초과 해결
ans = {lst2[i] : i for i in range(len(lst2))}

for i in lst:
    print(ans[i], end=' ')