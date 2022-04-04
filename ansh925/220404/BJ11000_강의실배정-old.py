# https://www.acmicpc.net/problem/11000
# 강의실 배정
import sys
input=sys.stdin.readline

lst,lst2=[],[]
n=int(input())
for i in range(n):
    a, b = map(int, input().split())
    lst.append([a, b])

lst2.append(lst[0][1])
cnt=1

for i in range(1, n):
    lst.sort(key=lambda x: x[0])
    if lst2[0] > lst[i][0]:
        lst2.append(lst[i][1]) 
        cnt+=1
    else:
        lst2.pop()
        lst2.append(lst[i][1]) 

print(cnt)