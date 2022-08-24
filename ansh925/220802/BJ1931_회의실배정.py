# https://www.acmicpc.net/problem/1931
# 회의실 배정
import sys
input = sys.stdin.readline

n = int(input())
lst=[]
for _ in range(n):
    a,b = map(int,input().split())
    lst.append([a,b])

lst=sorted(lst,key=lambda x:x[0])   # 회의 시작시간 기준 정렬(1)
lst=sorted(lst,key=lambda x:x[1])   # 회의 종료시간 기준 정렬(2)

end_time=0; cnt=0
for start,end in lst:               # 회의시간 중
    if start >= end_time:           # 시작시간이 종료시간보다 큰 경우 (사용 가능)
        end_time = end              # 종료시간 갱신
        cnt += 1                    # 회의++
print(cnt)