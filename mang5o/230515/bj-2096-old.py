import sys
N = int(sys.stdin.readline().rstrip())
all_map = []
for _ in range(N):
    all_map.append(list(map(int, sys.stdin.readline().rstrip().split())))
min_dp = [[0, 0, 0] for _ in range(N)]
max_dp = [[0, 0, 0] for _ in range(N)]
min_dp[0] = all_map[0]
max_dp[0] = all_map[0]
for i in range(1, N):
    for j in range(3):
        if j == 0:
            min_dp[i][0] = min(min_dp[i - 1][0], min_dp[i - 1][1]) + all_map[i][0]
            max_dp[i][0] = max(max_dp[i - 1][0], max_dp[i - 1][1]) + all_map[i][0]
        elif j == 1:
            min_dp[i][1] = min(min_dp[i - 1][0], min_dp[i - 1][1], min_dp[i - 1][2]) + all_map[i][1]
            max_dp[i][1] = max(max_dp[i - 1][0], max_dp[i - 1][1], max_dp[i - 1][2]) + all_map[i][1]
        else:
            min_dp[i][2] = min(min_dp[i - 1][1], min_dp[i - 1][2]) + all_map[i][2]
            max_dp[i][2] = max(max_dp[i - 1][1], max_dp[i - 1][2]) + all_map[i][2]
print("{} {}".format(max(max_dp[-1]), min(min_dp[-1])))