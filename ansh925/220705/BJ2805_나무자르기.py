# https://www.acmicpc.net/problem/2805
# 나무 자르기
import sys
input=sys.stdin.readline

n,m =map(int,input().split())
tree=list(map(int,input().split()))

left=1; right=sum(tree)     # 이분 탐색

while left <= right:
    mid=(left+right)//2
    cnt=0
    for i in tree:
        if i > mid:
            cnt += i-mid

    if cnt >= m:
        left = mid+1
    else:
        right = mid-1
print(right)