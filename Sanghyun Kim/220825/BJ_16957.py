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

# 각 칸의 공 수
num_table = [[0 for _ in range(c)] for _ in range(r)]
# 가장 작은 정수의 칸으로 즉시 이동 가능한 메모라이제이션 list
dest_table = [[[] for _ in range(c)] for _ in range(r)]

# 동, 남동, 남, 남서, 서, 북서, 북, 북동
dr = [0, 1, 1, 1, 0, -1, -1, -1] # y
dc = [1, 1, 0, -1, -1, -1, 0, 1] # x


# 체스판의 모든 칸에 대해
for i in range(r):
    for j in range(c):
        min_val = chess_table[i][j]
        dfs = deque([(i, j)])
        min_dy, min_dx = i, j
        while dfs:
            temp = False
            y, x = dfs.popleft()

            # 가장 작은 정수의 칸으로 즉시 이동 가능하다면 이동하여
            # while문에서 탈출
            if dest_table[y][x]:
                y, x = dest_table[y][x][0], dest_table[y][x][1]
                min_val = chess_table[y][x]
                min_dy, min_dx = y, x
                break
            
            # 이동 가능한 8 방향에 대해
            # 이동가능하면
            # 현재 min_val보다 작은 값일 경우
            # min_dy, min_dx 값 변경
            # temp = True로 하여 min 값을 변경했다는 표시

            # 8번 다 돌고, min 값을 변경했을 경우
            # 바뀐 min 값에 대한 dy, dx 값을 dfs에 append
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
        
        # while문 끝나고 가장 작은 값의 위치 +1
        # i, j 일 경우 가장 작은 값의 위치 메모라이제이션
        num_table[min_dy][min_dx] += 1
        dest_table[i][j] = [min_dy, min_dx]

for i in range(r):
    print(*num_table[i])

# 70% 에서 시간초과