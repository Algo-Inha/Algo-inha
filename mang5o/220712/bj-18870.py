# https://www.acmicpc.net/problem/18870
# 좌표 압축

import sys
N = int(sys.stdin.readline().rstrip())
X = list(map(int, sys.stdin.readline().rstrip().split()))
sorted_X = list(set(X))
sorted_X.sort()
sorted_X_idx = dict()
for i in range(len(sorted_X)):
    sorted_X_idx[sorted_X[i]] = i

ret_str = ''
for x in X:
    ret_str += str(sorted_X_idx[x]) + " "
print(ret_str[:-1])