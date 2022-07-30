# https://www.acmicpc.net/problem/2133
# 타일 채우기- BJ_2133

n = int(input())
tile = [0 for _ in range(16)]

tile[2//2] = 3
tile[4//2] = 11

if n % 2 == 0:
    if n > 4:
        for i in range(3, n//2 + 1):
            tile[i] = 3 * tile[i - 1] + 2 * sum(tile[:i - 1]) + 2
    print(tile)
    print(tile[n//2])
else:
    print(0)

# 홀수일 경우 존재하지 않는다.
# 짝수일 경우만 따지므로 n // 2 로 index 따짐

# dp[n - 2] * 3 + (dp[n - 4] + dp[n - 6] + dp[n - 8] + ... + dp[2]) * 2 + 2(뒤집어진 갈고리 2개씩 추가하는 형태)