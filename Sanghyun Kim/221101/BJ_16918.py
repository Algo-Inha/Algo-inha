# https://www.acmicpc.net/problem/16918
# 봄버맨- BJ_16918

import sys
input = sys.stdin.readline

r, c, n = map(int, input().split())
board = [list(input().strip()) for i in range(r)]

if n<=1 :
    for li in board : print(''.join(li))
elif n%2==0 :
    for i in range(r): print('O'*c)
else :
    # 첫번째 폭탄이 터진 상태
    bombs1 = [['O']*c for i in range(r)]
    for y in range(r):
        for x in range(c):
            if board[y][x]=='O': bombs1[y][x] = '.'
            else :
                for i, j in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    if y+i>=0 and y+i<r and x+j>=0 and x+j<c and board[y+i][x+j]=='O':
                        bombs1[y][x] = '.'
                        break

    # 두번째 폭탄이 터진 상태
    bombs2 = [['O']*c for i in range(r)]
    for y in range(r):
        for x in range(c):
            if bombs1[y][x]=='O' : bombs2[y][x] = '.'
            else :
                for i, j in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    if y+i>=0 and y+i<r and x+j>=0 and x+j<c and bombs1[y+i][x+j]=='O':
                        bombs2[y][x] = '.'
                        break

    if n%4==3:
        for li in bombs1 : print(''.join(li))
    if n%4==1:
        for li in bombs2 : print(''.join(li))