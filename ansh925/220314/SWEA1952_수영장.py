# https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpFQaAQMDFAUq&categoryId=AV5PpFQaAQMDFAUq&categoryType=CODE&problemTitle=1952&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1&&&&&&&&&
# 수영장

t=int(input())
for _ in range(1,t+1):
    cost=list(map(int,input().split()))
    plan=list(map(int,input().split()))

    dp=[0]*12

    dp[0]=min(cost[0]*plan[0], cost[1])
    dp[1]=dp[0]+min(cost[0]*plan[1], cost[1])
    dp[2]=min(dp[1]+min(cost[0]*plan[2], cost[1]), cost[2])
    for i in range(3,12):
        dp[i]=min(dp[i-3]+cost[2], dp[i-1]+min(cost[0]*plan[i], cost[1]))
    
    dp[-1]=min(dp[-1], cost[3])

    print('#%d %d' %(_,dp[-1]))