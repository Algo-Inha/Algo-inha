# https://www.acmicpc.net/problem/2212
# 센서

import sys
N = int(sys.stdin.readline().rstrip())
K = int(sys.stdin.readline().rstrip())
sensor_position = sorted(list(map(int, sys.stdin.readline().rstrip().split())))
diff_list = sorted([(sensor_position[x+1] - sensor_position[x]) for x in range(len(sensor_position)-1)])
print(sum(diff_list[:N-K]))

