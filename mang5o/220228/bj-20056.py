# https://www.acmicpc.net/problem/20056
# 마법사 상어와 파이어볼
import sys, math

dir_matrix = ((-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1))

N, M, K = map(int, sys.stdin.readline().rstrip().split())
fireball_dict = dict()
