# https://www.acmicpc.net/problem/16957
# 체스판 위의 공- BJ_16957

from collections import deque
import sys
input = sys.stdin.readline

# 체스판 정수 입력
r, c = map(int, input().split())
chess_table = []
for _ in range(r):
    chess_table.append(list(map(int, input().split())))

num_table = [[0 for _ in range(c)] for _ in range(r)]

# 동, 남동, 남, 남서, 서, 북서, 북, 북동
dr = [0, 1, 1, 1, 0, -1, -1, -1] # y
dc = [1, 1, 0, -1, -1, -1, 0, 1] # x


for i in range(r):
    for j in range(c):
        min_val = chess_table[i][j]
        dfs = deque([(i, j)])
        min_dy, min_dx = i, j
        while dfs:
            temp = False
            y, x = dfs.popleft()
            for k in range(len(dr)):
                dy = y + dr[k]
                dx = x + dc[k]
                if 0 <= dy < r and 0 <= dx < c:
                    if min_val > chess_table[dy][dx]:
                        min_val = chess_table[dy][dx]
                        min_dy, min_dx = dy, dx
                        temp = True

                if k == len(dr) - 1 and temp == True:
                    dfs.append((min_dy, min_dx))
            
        num_table[min_dy][min_dx] += 1

for i in range(r):
    print(*num_table[i])

# 70% 에서 시간초과