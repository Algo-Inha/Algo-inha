import sys
input = sys.stdin.readline

N = int(input())

dp_max = dp_min = list(map(int, input().split()))

for _ in range(1, N):
    numbers = list(map(int, input().split()))
    
    new_dp_max = [0]*3
    new_dp_min = [0]*3

    # 최대 점수
    new_dp_max[0] = max(dp_max[0], dp_max[1]) + numbers[0]
    new_dp_max[1] = max(dp_max) + numbers[1]
    new_dp_max[2] = max(dp_max[1], dp_max[2]) + numbers[2]

    # 최소 점수
    new_dp_min[0] = min(dp_min[0], dp_min[1]) + numbers[0]
    new_dp_min[1] = min(dp_min) + numbers[1]
    new_dp_min[2] = min(dp_min[1], dp_min[2]) + numbers[2]

    dp_max, dp_min = new_dp_max, new_dp_min

print(max(dp_max), min(dp_min))
