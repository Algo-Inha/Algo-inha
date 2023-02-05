# https://www.acmicpc.net/problem/19236
# 청소년 상어

import sys
dir_matrix = ( # diff_y, diff_x
    (-1,0), (-1,-1), (0,-1), (1,-1),
    (1,0),  (1,1), (0,1), (-1,1)
)