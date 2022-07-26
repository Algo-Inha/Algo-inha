# Solving

## 크레인 인형뽑기 게임- PG_64061
https://school.programmers.co.kr/learn/courses/30/lessons/64061
### 문제풀이
```python
def solution(board, moves):
    answer = 0
    temp = []
    len_1 = 0
    # moves 리스트 값에 해당하는 수에 대해
    for i in moves:
        i -= 1
        for j in range(len(board[0])):
            # board 리스트 값이 0이면 다음 board 리스트 값 비교
            # 0이 아니면 temp 스택에 넣고, board 리스트 값 0으로
            if board[j][i] == 0:
                continue
            temp.append(board[j][i])
            board[j][i] = 0
            # temp 스택의 크기가 2 이상이면
            # 스택의 가장 윗 원소 2개의 값이 같으면
            # len_1보다 스택의 길이가 길 때까지
            # 같은 원소 2개 지우고 answer 2 키우기
            if len(temp) >= 2:
                if temp[-1] == temp[-2]:
                    while len_1 < len(temp):
                        temp.pop()
                        temp.pop()
                        answer += 2
                        len_1 = len(temp)
            break
    return answer

board = []
for i in range(int(input())):
    board.append(list(map(int, input().split())))
moves = list(map(int, input().split()))
print(solution(board, moves))
```
moves 리스트 값에 해당하는 board 리스트 값 중 0이 아닌 가장 위에 있는 값을 temp 스택에 넣는다. 
스택의 크기가 2보다 클 때 가장 마지막에 들어온 2개의 값이 같으면 지우고, answer를 2 증가시킨다. 
더이상 지워지지 않을 때 까지 지우기를 반복한다. 
### 의견
list와 stack을 잘 이용하여 어렵지 않았던 문제였다.


## 다리놓기- BJ_1010
https://www.acmicpc.net/problem/1010
### 문제풀이
```python
def factorial(num):
    total = 1
    for i in range(1, num + 1):
        total *= i
    return total

for _ in range(int(input())):
    n, m = map(int, input().split())
    if m - n == 0:
        print(1)
    else:
        print(factorial(m) // (factorial(m - n) * factorial(n)))    
```
m 콤비네이션 n
### 의견
다리가 겹치면 안된다 하여 다리 위에 다리가 놓이면 안되는 문제인줄 알았다. 하지만 예제 출력을 보니 너무 터무니 없는 숫자를 봤고, 조금 다시 생각해보니 단순히 다리 자체가 겹치지만 않으면 된다. 다리가 겹쳐도 되는 경우는 퍼뮤테이션을 사용하면 되고, 겹치면 안되므로 콤비네이션만 사용하면 간단하게 풀리는 문제였다.


## 기타리스트- BJ_1495
https://www.acmicpc.net/problem/1495
### 문제풀이
```python
from collections import deque
import sys
input = sys.stdin.readline

n, s, m = map(int, input().split())
v = list(map(int, input().split()))
# (n x m) 의 deque으로 만든 n줄짜리 list
temp = deque([[False for _ in range(m + 1)] for _ in range(n + 1)])
temp[0][s] = True

# list 한줄씩 넘어가면서 v[i - 1] 빼고, 더하며 
# 조건 만족하면 True 체크
for i in range(1, n + 1):
    for j in range(m + 1):
        if temp[i - 1][j] == True:
            if j - v[i - 1] >= 0:
                temp[i][j - v[i - 1]] = True
            if j + v[i - 1] <= m:
                temp[i][j + v[i - 1]] = True

total = deque()
# 가장 마지막 list에 대해 True 일 경우 total list에 입력
for i in range(m + 1):
    if temp[-1][i] == True:
        total.append(i)
# total list의 최댓값 출력
if total:
    print(max(total))
# total이 비어있으면, -1 출력
else:
    print(-1)

```
n x m의 n줄짜리 list를 만들어 n번 돌 동안 list 한 줄씩 넘어가며 조건 만족하면 길이 m의 list에 True 체크한다. 이후 가장 마지막 list에 대해 True일 경우 total list에 입력하여 total list의 최댓값을 출력한다. total list가 비어있을 경우 -1을 출력한다.
### 의견
스택을 사용하여 조건을 만족하는 경우 스택에 넣고 하나씩 뽑아서 조건 비교하여 스택을 채우는 방법으로 코딩을 진행했었는데, 메모리 초과가 발생하여 고민하다가 반례를 찾아봤다. 반례를 적용시킨 결과 너무 오래 걸려 결국 모범 답안을 찾아봤는데.. 전혀 생각지도 못한 메모리 활용... 감탄이 나온다...


## 리모컨- BJ_1107
https://www.acmicpc.net/problem/1107
### 문제풀이
```python
from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
broken = deque(map(int, input().split()))
min_count = abs(100 - n)

# 가능한 모든 경우의 수에 대해
# 고장난 숫자가 포함된 채널을 제외하고
# 가장 적게 리모콘을 누른 경우
for i in range(1000001):
    i = str(i)
    for j in range(len(i)):
        if int(i[j]) in broken:
            break
        elif j == len(i) - 1:
            min_count = min(min_count, abs(int(i) - n) + len(i))
print(min_count)
```
고장난 숫자가 포함된 채널을 제외한 가능한 모든 경우의 수에 대해 가장 리모콘을 적게 누른 경우를 찾는 브루트포스 알고리즘이다.
### 의견
브루트포스 알고리즘으로 풀어야겠다는 생각을 하기까지 시간이 조금 걸렸고, 거르고 거른 이후의 경우의 수가 아닌 정말 전체의 경우의 수를 모두 비교하여 풀어야겠다는 생각을 하기가 쉽지 않았다.


## 킹- BJ_1063
https://www.acmicpc.net/problem/1063
### 문제풀이
```python
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
```
x, y 축 각각으로 이동하는 dx, dy 리스트, 각 이동하는 방향을 의미하는 temp 딕셔너리를 사용해 이동했을 경우 체스판을 넘어가는 경우와 넘어가지 않는 경우로 나눈다.
넘어갔을 경우에는 돌의 좌표와 비교해 같은 좌표일 경우 돌이 왕과 동일한 방향으로 이동해야 하는데 이 때에도 체스판을 넘어가는 경우와 넘어가지 않는 경우로 나눠 해결한다.
### 의견
구현 문제인 것은 문제를 읽고 바로 알았지만, 문제의 조건들을 모두 일일히 구현하려다 보니 빼먹는 조건들이 있었다. 
좌표계에서 좌표를 이동시키는 문제인 만큼 dx, dy 리스트를 활용해 조건을 모두 만족할 수 있게끔 코드를 효율적으로 짜는데 시간이 좀 필요한 문제였다.