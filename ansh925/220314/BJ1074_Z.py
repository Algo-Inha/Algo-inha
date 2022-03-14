# https://www.acmicpc.net/problem/1074
# Z

n,r,c=map(int,input().split())

ans=0
while n!=0:
    n-=1

    if r<2**n and c<2**n:
        ans+=(2**n)*(2**n)*0
    elif r<2**n and c>=2**n:
        ans+=(2**n)*(2**n)*1
        c-=2**n
    elif r>=2**n and c<2**n:
        ans+=(2**n)*(2**n)*2
        r-=2**n
    else:
        ans+=(2**n)*(2**n)*3
        c-=2**n
        r-=2**n
    
print(ans)