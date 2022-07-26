# https://www.acmicpc.net/problem/1495
# 기타리스트

n,s,m = map(int,input().split())
vol=list(map(int,input().split()))

dp = [[0]*(m+1) for _ in range(n+1)]    # dp 2차원 리스트 선언 [곡,볼륨] (1:가능/0:불가능)
dp[0][s] = 1                            # 처음 곡은 가능 체크v

for i in range(n):                      # 곡 개수 만큼
    for j in range(m+1):                # 볼륨 범위 만큼
        if dp[i][j]==1:                 # 가능 체크v 이면
            vol_up = j + vol[i]
            vol_down = j - vol[i]       # 볼륨 키우고 줄이기

            if 0<=vol_up<=m:            # 키운게 범위 안쪽이면 
                dp[i+1][vol_up] = 1     # 가능 체크v
            if 0<=vol_down<=m:          # 줄인게 범위 안쪽이면
                dp[i+1][vol_down] = 1   # 가능 체크v

ans = -1                                # 기본으로(가능 체크v 없으면) -1 출력
for k in range(m+1):
    if dp[n][k]==1:                     # 마지막 곡에서 볼륨 0부터 최대 m까지 중,
        ans = k                         # 볼륨 조절 가능한 경우 해당 dp의 m값(=볼륨) 출력
print(ans)    