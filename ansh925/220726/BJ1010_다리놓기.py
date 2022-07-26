# https://www.acmicpc.net/problem/1010
# 다리 놓기

t=int(input())
for _ in range(t):
    n,m=map(int,input().split())
    dp=[[0]*(m+1) for _ in range(n+1)]  # 2차원 리스트 생성

    for i in range(1,n+1):
        for j in range(1,m+1):          # 리스트를 전부 돌며
            if i==1:
                dp[i][j] = j            # 첫번째는 순서대로 채워주고
            elif i==j:
                dp[i][j] = 1            # i=m인 경우는 1로 채우줌
            elif i<j:
                dp[i][j] = dp[i][j-1] + dp[i-1][j-1]
                                        # 나머지는 점화식에 의해 채워줌
    print(dp[n][m])