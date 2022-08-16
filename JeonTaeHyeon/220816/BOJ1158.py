#요세푸스 문제
#https://www.acmicpc.net/problem/1158
n,k=map(int,input().split())

arr=[i for i in range(1,n+1)]
res=[]
cur=0

for j in range(n):
    cur+=k-1
    if(cur>=len(arr)):
        cur=cur%len(arr)
    res.append(str(arr.pop(cur)))

print("<",", ".join(res)[:],">",sep='')

