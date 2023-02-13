# https://www.acmicpc.net/problem/19236
# 청소년 상어- BJ_19236

from collections import deque
import copy
import sys
input = sys.stdin.readline

fishMap = [[] for _ in range(4)]
for i in range(4):
    # a: 물고기 번호, b: 물고기 방향(1부터 순서대로 ↑, ↖, ←, ↙, ↓, ↘, →, ↗)
    a1, b1, a2, b2, a3, b3, a4, b4 = map(int, input().split())
    fishMap[i] = [[a1,b1],[a2,b2],[a3,b3],[a4,b4]]

# 상어가 [0, 0] 으로 들어감: 상어 번호 = 0
nextR = 0
nextC = 0

moveR = [-1, -1, 0, 1, 1, 1, 0, -1]
moveC = [0, -1, -1, -1, 0, 1, 1, 1]

sharkQ = deque([(0, 0, fishMap[0][0][0], copy.deepcopy(fishMap))])

sharkR = -1
sharkC = -1
nextSharkR = 0
nextSharkC = 0
ans = 0
ansLi = []

# 해당 물고기가 이동할 행/열 지정 함수
def fishMove(r, c, n, fishM):  # r: row, c: col, n: 방향
    nextRow = r     # 이동할 행
    nextCol = c     # 이동할 열
    nextN = n - 1   # 방향 이동
    canMove = False # 이동 가능 판단
    cnt = 0

    while cnt < 8: # 8번 방향을 바꿔도 움직이지 못할 경우 이동 행/열 바꾸지 않고 리턴
        cnt += 1
        if 0 <= r + moveR[nextN] < 4 and 0 <= c + moveC[nextN] < 4:
            if fishM[r + moveR[nextN]][c + moveC[nextN]][0] != 0: # 물고기 움직일 수 있는 경우
                nextRow = r + moveR[nextN]
                nextCol = c + moveC[nextN]
                fishM[r][c][1] = nextN + 1    # 물고기 바뀐 방향 설정
                canMove = True
                break
        if not canMove:     # 물고기 움직이지 못할 경우 반시계 방향으로 회전
            if nextN == 7:
                nextN = 0
            else:
                nextN += 1

    return nextRow, nextCol

# 상어가 이동할 행/열 판단 함수
def sharkMove(r, c, n, sharkM, ans):     # r: row, c: col, n: 방향
    global sharkQ # sharkQ: 상어가 이동 가능한 모든 행/열 리스트
    nextRow = r
    nextCol = c
    nextN = n - 1
    cnt = 0

    while cnt < 3:
        cnt += 1
        nextRow += moveR[nextN]  # n 방향으로 행 이동
        nextCol += moveC[nextN]  # n 방향으로 열 이동
        if 0 <= nextRow < 4 and 0 <= nextCol < 4:
            if sharkM[nextRow][nextCol][0] != -1 and sharkM[nextRow][nextCol][0] != 0:
                sharkQ.append((nextRow, nextCol, ans + sharkM[nextRow][nextCol][0], copy.deepcopy(sharkM)))

while sharkQ:
    nextSharkR, nextSharkC, ans, fishMap = sharkQ.popleft()
    if sharkR == -1 and sharkC == -1:       # 첫 번째
        ansLi.append(ans)
        fishMap[nextSharkR][nextSharkC][0] = 0
    else:                                   # 첫 번째 이후
        fishMap[sharkR][sharkC][0] = -1
        fishMap[sharkR][sharkC][1] = -1
        ansLi.append(ans)
        fishMap[nextSharkR][nextSharkC][0] = 0

    # 번호 작은 물고기부터 마지막 물고기까지 이동 가능하다면 1칸씩 이동
    for i in range(1, 17):
        temp = False
        for row in range(4):
            if temp:
                break
            for col in range(4):
                if fishMap[row][col][0] == i:
                    nextR, nextC = fishMove(row, col, fishMap[row][col][1], fishMap)    # 물고기 이동 가능 판단
                    temp = True
                    if row == nextR and col == nextC:   # 이동 불가능: 이동 X
                        break
                    else:                                   # 이동 가능: swap
                        swapFish = fishMap[row][col]
                        fishMap[row][col] = fishMap[nextR][nextC]
                        fishMap[nextR][nextC] = swapFish
                        break
            

    sharkMove(nextSharkR, nextSharkC, fishMap[nextSharkR][nextSharkC][1], fishMap, ans)
    sharkR = nextSharkR
    sharkC = nextSharkC

print((ansLi))



# 1. 물고기 이동
# 2. 상어가 이동, 
# 이동한 자리 있던 물고기 번호 더하기,
# 이동한 자리 있던 물고기 방향 갖기
# ... 1, 2 반복하다 상어 이동 불가능할 경우
# 상어가 먹은 모든 물고기 번호 합의 최댓값...

# 어떤 알고리즘이었더라: 완전탐색(dfs)