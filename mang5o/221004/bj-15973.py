# https://www.acmicpc.net/problem/15973
# 두 박스

import sys
position_1 = list(map(int, sys.stdin.readline().split()))
position_2 = list(map(int, sys.stdin.readline().split()))
double_position = [max(position_1[0], position_2[0]), max(position_1[1], position_2[1]),
                   min(position_1[2], position_2[2]), min(position_1[3], position_2[3])]

# POINT, LINE, FACE, NULL ("그렇지않고" 조건 활용)
if double_position[0]==double_position[2] and double_position[1]==double_position[3]:
    print("POINT")
elif double_position[0]==double_position[2] and double_position[1] < double_position[3]:
    print("LINE")
elif double_position[1]==double_position[3] and double_position[0] < double_position[2]:
    print("LINE")
elif double_position[0]<double_position[2] and double_position[1]<double_position[3]:
    print("FACE")
else:
    print("NULL")
