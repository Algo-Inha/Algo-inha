# https://www.acmicpc.net/problem/14499
# 주사위 굴리기
import sys
input = sys.stdin.readline

dice = [0]*6
def move(direction):
    if direction == 1:      # 동
        dice[0],dice[2],dice[5],dice[3] = dice[3],dice[0],dice[2],dice[5]
    elif direction == 2:    # 서
        dice[3],dice[0],dice[2],dice[5] = dice[0],dice[2],dice[5],dice[3]
    elif direction == 3:    # 북
        dice[1],dice[5],dice[4],dice[0] = dice[0],dice[1],dice[5],dice[4]
    elif direction == 4:    # 남
        dice[0],dice[1],dice[5],dice[4] = dice[1],dice[5],dice[4],dice[0]

n,m,x,y,k = map(int,input().split())
board = []
for _ in range(n):
    board.append(list(map(int,input().split())))
move_order = list(map(int,input().split()))

board_move = [(0,0),(0,1),(0,-1),(-1,0),(1,0)]  # 정지,동,서,북,남

for order in move_order:
    dx,dy = board_move[order]
    dx = dx + x
    dy = dy + y
    # 게임보드 범위 안쪽인 경우만
    if n>dx>=0 and m>dy>=0:
        move(order)
        if not board[dx][dy]:
            board[dx][dy] = dice[5]
        else:
            board[dx][dy], dice[5] = 0, board[dx][dy]
        x,y = dx,dy

        print(dice[0])        