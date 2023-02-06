# Solving

## 청소년 상어
https://www.acmicpc.net/problem/19236
### 문제풀이
```python
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
```
(1) 물고기 이동
(2) 상어가 이동, 
이동한 자리 있던 물고기 번호 더하기,
이동한 자리 있던 물고기 방향 갖기
... 1, 2 반복하다 상어 이동 불가능할 경우
상어가 먹은 모든 물고기 번호 합의 최댓값 dfs 완전탐색으로
### 의견
구현적으로는 이해하고 풀었다고 생각했는데, 답이 틀렸다.
구글링을 하여 코드를 비교했는데, 다른 사람이 생각했던 예외처리를 빠짐없이 했는데도 답이 틀렸다. 
구현 실력이 아직 많이 부족한 것 같다. 


## 빗물
https://www.acmicpc.net/problem/14719
### 문제풀이
```python
import sys
input = sys.stdin.readline

h, w = map(int, input().split())
temp = list(map(int, input().split()))

ans = 0
for i in range(1, w - 1):   # i 기준 
    leftMax = max(temp[:i])        # 왼쪽으로 가장 높은
    rightMax = max(temp[i+1:])     # 오른쪽으로 가장 높은

    comp = min(leftMax, rightMax)    # 왼쪽, 오른쪽 중 더 낮은

    if temp[i] < comp:      # i번째보다 낮으면 빗물 존재
        ans += comp - temp[i]

print(ans)
```
i번째 칸에서 빗물이 존재할 조건으로 유무를 판단해 값을 계산한다.
### 의견
i번째 칸별로 나눠 존재할지를 따지면 쉽게 풀리는데 칸별로 나눌 생각을 하는데 오래걸렸다.

## 떡 먹는 호랑이
https://www.acmicpc.net/problem/2502
### 문제풀이
```python
import sys
input = sys.stdin.readline

d, k = map(int, input().split())

temp = [0 for _ in range(d)]
temp[0] = 'x'
temp[1] = 'y'
for i in range(2, d):
    temp[i] = temp[i - 2] + temp[i - 1]

firNum = temp[-1].count('x')    # 첫째날 count
secNum = temp[-1].count('y')    # 둘째날 count

a = 1   # 첫째날 개수
b = 0   # 둘째날 개수
while 1:
    if (k - firNum * a) % secNum == 0:  # 1차 방정식 풀기
        b = (k - firNum * a) // secNum
        break
    a += 1

print(a)
print(b)
```
첫째날 떡 count와 둘째날 떡 count를 구해 1차 방정식을 풀어 해결한다.
### 의견
1차 방정식을 구해 수를 대입해보며 방정식에 맞는 해를 구하는 문제


## 꽃길
https://www.acmicpc.net/problem/14620
### 문제풀이
```python
from itertools import combinations
import sys
input = sys.stdin.readline

n = int(input())
graph = [[] for _ in range(n)]
for i in range(n):
    graph[i] = list(map(int, input().split()))
# 동 서 남 북 으로 체크
dxdy = [(1, 0), (-1, 0), (0, 1), (0, -1)]

# 가능한 모든 좌표 경우의수
dot = list(combinations([(x, y) for x in range(1, n - 1) for y in range(1, n - 1)], 3))
ans = []

for i in range(len(dot)):
    flower = [[False for _ in range(n)] for _ in range(n)]  # 꽃이 있는 자리: True
    subAns = 0
    temp = False
    for x, y in dot[i]:
        if flower[x][y] == False:   # 꽃 씨앗 없을 경우
            flower[x][y] = True
            subAns += graph[x][y]
            for dx, dy in dxdy:     
                if flower[x + dx][y + dy] == False:     # 꽃잎 없을 경우
                    flower[x + dx][y + dy] = True
                    subAns += graph[x + dx][y + dy]
                else:                                   # 꽃잎 이미 있을 경우
                    temp = True
        else:                       # 꽃 씨앗 이미 있는 경우
            temp = True
        if temp:
            break
    if not temp:        # 꽃이 지지 않고 모두 필 경우
        ans.append(subAns)

if ans:
    print(min(ans))
else:
    print(0)
```
브루트포스 알고리즘 사용해 꽃이 필 수 있는 모든 경우의 수를 구해 최소 비용 구한다.
### 의견
코테는 파이썬