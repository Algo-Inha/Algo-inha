# https://www.acmicpc.net/problem/1063
# 킹- BJ_1063

king, rock, n = map(str, input().split())
n = int(n)

# 0 번째 행 = -1  / 7 번째 행 = -8    -->   y축
# 0 번째 열 = A:0 / 7 번째 열 = H:7   -->   x축
king_x = ord(king[0]) - 65
king_y = -int(king[1])
rock_x = ord(rock[0]) - 65
rock_y = -int(rock[1])

#     R,  L, B, T,  RT, LT, RB, LB 
dx = [1, -1, 0,  0,  1, -1,  1, -1]
dy = [0,  0, 1, -1, -1, -1,  1,  1]
temp = {'R':0, 'L':1, 'B':2, 'T':3, 'RT':4, 'LT':5, 'RB':6, 'LB':7}

for _ in range(n):
    moves = input()
    idx = temp[moves]
    # 이동했을 때 체스판을 넘어갈 경우 이동하지 않고,
    # 체스판을 넘어가지 않을 경우 이동
    if king_x + dx[idx] > 7 or king_x + dx[idx] < 0 or king_y + dy[idx] > -1 or king_y + dy[idx] < -8:
        continue
    king_x += dx[idx]
    king_y += dy[idx]

    # 이동했을 경우 돌과 같은 좌표에 위치할 경우 
    # 돌이 이동할 때 체스판을 넘어갈 경우 이동하지 않고, 왕 또한 이동하기 전으로 돌아가고,
    # 체스판을 넘어가지 않을 경우 이동
    if king_x == rock_x and king_y == rock_y:
        if rock_x + dx[idx] > 7 or rock_x + dx[idx] < 0 or rock_y + dy[idx] > -1 or rock_y + dy[idx] < -8:
            king_x -= dx[idx]
            king_y -= dy[idx]
            continue
        rock_x += dx[idx]
        rock_y += dy[idx]

print(chr(king_x + 65) + str(-king_y))
print(chr(rock_x + 65) + str(-rock_y))
