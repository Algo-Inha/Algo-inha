# https://www.acmicpc.net/problem/14391
# 종이 조각

N, M = map(int, input().split())
arr = [list(map(int, input())) for _ in range(N)]
ans=0

def bitmask():
    global ans
    for i in range(1 << N * M):
        total = 0

        # 가로조각 합 계산
        for row in range(N):
            sum_row = 0
            for col in range(M):
                idx = row * M + col

                if i & (1 << idx) != 0:
                    sum_row = sum_row * 10 + arr[row][col]    # 가로일때, 각 자리수 계산
                else:                   
                    total += sum_row    # 세로일때, 자리수를 계산한 값을 total에 더하고
                    sum_row = 0         # sum_row 초기화
            total += sum_row

        # 세로조각 합 계산  
        for col in range(M):
            sum_col = 0
            for row in range(N):
                idx = row * M + col

                if i & (1 << idx) == 0:
                    sum_col = sum_col * 10 + arr[row][col]    # 세로일때, 각 자리수 계산
                else:
                    total += sum_col    # 가로일때, 자리수를 계산한 값을 total에 더하고
                    sum_col = 0         # sum_col 초기화
            total += sum_col

        ans = max(ans, total)           # 가장 큰 값 출력

bitmask()
print(ans)