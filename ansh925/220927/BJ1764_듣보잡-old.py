import sys
input=sys.stdin.readline

n,m = map(int,input().split())

d_name=[input() for _ in range(n)]
b_name=[input() for _ in range(m)]

cnt=0
ans=[]
for i in range(n):
    if d_name[i] in b_name:
        cnt += 1
        ans.append(d_name[i])

ans.sort()
print(cnt)
print(*ans, sep='\n')