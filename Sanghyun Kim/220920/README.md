# Solving

## 동전 1
https://www.acmicpc.net/problem/2293
### 문제풀이
```python
n, k = map(int, input().split())
coin = [int(input()) for _ in range(n)] # 코인의 종류
dp = [0 for _ in range(k + 1)]
dp[0] = 1 # index 0은 동전을 1개만 쓸 때 경우의 수를 고려

for i in coin:
    for j in range(i, k + 1):
        if j - i >= 0:
            dp[j] += dp[j - i]
print(dp[k])
```
특정 동전을 썼을 때 가치의 합이 i(1 <= i <= k)원이 되는 경우의 수
### 의견
난 멍청이... DP 너무 어렵다... 도저히 생각이 나질 않는다...


## 로또
https://www.acmicpc.net/problem/6603
### 문제풀이
```python
from itertools import combinations
from collections import deque
import sys
input = sys.stdin.readline

while 1:
    k_s = deque(deque(map(int, input().split())))
    if k_s[0] == 0:
        break

    k = k_s[0]
    k_s.popleft()
    sCombK = list(combinations(k_s, 6))
    for i in sCombK:
        print(*i)
    print()
```
순열을 import 하여 가능한 모든 경우의 수 출력한다.
### 의견
순열을 사용한 간단한 문제였다. 모든 경우의 수를 직접 출력해볼까 생각도 했지만 다음에 비슷한 문제가 나오면 해보는걸로..


## 로또
https://www.acmicpc.net/problem/6603
### 문제풀이
```python
from itertools import combinations
from collections import deque
import sys
input = sys.stdin.readline

while 1:
    k_s = deque(deque(map(int, input().split())))
    if k_s[0] == 0:
        break

    k = k_s[0]
    k_s.popleft()
    sCombK = list(combinations(k_s, 6))
    for i in sCombK:
        print(*i)
    print()
```
순열을 import 하여 가능한 모든 경우의 수 출력한다.
### 의견
순열을 사용한 간단한 문제였다. 모든 경우의 수를 직접 출력해볼까 생각도 했지만 다음에 비슷한 문제가 나오면 해보는걸로..


## 주사위 굴리기
https://www.acmicpc.net/problem/14499
### 문제풀이
```python
import sys
input = sys.stdin.readline

n, m, x, y, k = map(int, input().split())
graph = [[] for _ in range(n)]
for i in range(n):
    graph[i] = list(map(int, input().split()))

# x: row, y: col
# 동 서 북 남
dx = [0, 0, 0, -1, 1]
dy = [0, 1, -1, 0, 0]

dice = [0 for _ in range(6)]

moves = list(list(map(int, input().split())))
for move in moves:
    # 지도를 벗어나면 바로 다음 move로
    if x + dx[move] < 0 or x + dx[move] > n-1 or y + dy[move] < 0 or y + dy[move] > m-1:
        continue

    nx = x + dx[move]
    ny = y + dy[move]

    # 주사위 Index 값 변경을 위한
    # swap용 변수
    diceIdx_0 = dice[0]
    diceIdx_1 = dice[1]
    diceIdx_2 = dice[2]
    diceIdx_3 = dice[3]
    diceIdx_4 = dice[4]
    diceIdx_5 = dice[5]
    
    # 주사위 Index 값 변경
    if   move==1: # 동
        dice[0]=diceIdx_2
        dice[1]=diceIdx_0
        dice[2]=diceIdx_5
        dice[5]=diceIdx_1
    elif move==2: # 서
        dice[0]=diceIdx_1
        dice[1]=diceIdx_5
        dice[2]=diceIdx_0
        dice[5]=diceIdx_2
    elif move==3: # 북
        dice[0]=diceIdx_4
        dice[3]=diceIdx_0
        dice[4]=diceIdx_5
        dice[5]=diceIdx_3
    elif move==4: # 남
        dice[0]=diceIdx_3
        dice[3]=diceIdx_5
        dice[4]=diceIdx_0
        dice[5]=diceIdx_4
    
    # 지도 칸의 조건
    if graph[nx][ny]==0:
        graph[nx][ny]=dice[0]
    else:
        dice[0]=graph[nx][ny]
        graph[nx][ny]=0
    
    print(dice[5])
    x, y = nx, ny
```
주사위가 동, 서, 북, 남으로 이동할 때 주사위의 각 Index 값이 어떻게 바뀌는지 파악하여 dice list에 [아랫값, 동, 서, 북, 남, 윗값] 으로 초기화 시켜 지도 칸의 조건에 따라 지도 값을 변경하고, dice[5]인 윗값을 출력한다.
### 의견
주사위 문제라서 너무 헷갈렸다. 처음에 모든 경우를 구현하면 될 것 같아 구현했지만, 주사위 방향이 돌아갈 상황을 고려하지 않았고, 주사위를 직접 만져보며 동, 서, 북, 남으로 이동할 때 Index 값이 바뀌는지 파악해 하드코딩하여 해결할 수 있었다. 찝찝한 결말..


## 퍼즐 조각 채우기
https://school.programmers.co.kr/learn/courses/30/lessons/84021
### 문제풀이
```python
from collections import deque
import copy

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def rotate_a_matrix_by_90_degree(a):
    row_length = len(a)
    column_length = len(a[0])
    
    res = [[0] * row_length for _ in range(column_length)]
    for r in range(row_length):
        for c in range(column_length):
            res[c][row_length-1-r] = a[r][c]
    
    return res

def get_new_locations(location):
    new_locations = []
    for loc in location:
        x_min = int(1e9)
        x_max = 0
        y_min = int(1e9)
        y_max = 0
        for x, y in loc:
            x_min = min(x_min, x)
            x_max = max(x_max, x)
            y_min = min(y_min, y)
            y_max = max(y_max, y)
        new_locations.append([x_min, x_max, y_min, y_max])
    return new_locations

def bfs(table, q, location, n):
    while q:
        x, y  = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < n:
                if table[nx][ny] == 1:
                    location.append([nx, ny])
                    table[nx][ny] = 0
                    q.append([nx, ny])
    return location

def get_piece_or_space(table, new_locations):
    pieces = []
    for x_min, x_max, y_min, y_max in new_locations:
        piece = []
        for x in range(x_min, x_max+1):
            row = table[x]
            piece.append(row[y_min:y_max+1])
        pieces.append(piece)
    return pieces

def solution(game_board, table):
    answer = 0
    n = len(table)

    # game_board 1, 0 반전
    for x in range(n):
        for y in range(n):
            if game_board[x][y] == 0:
                game_board[x][y] = 1
            else:
                game_board[x][y] = 0

    puzzle = []
    # 새로운 table 생성
    new_table = copy.deepcopy(table)
    # 새로운 table의 조각 찾기
    for x in range(n):
        for y in range(n):
            if new_table[x][y] == 1:
                new_table[x][y] = 0
                q = deque([[x, y]])
                location = [[x, y]]
                puzzle.append(bfs(new_table, q, location, n))
    
    # 좌표 가공
    new_locations = get_new_locations(puzzle)
    pieces = get_piece_or_space(table, new_locations)
    empty = []
    
    # 가공한 조각들을 90도씩 회전하며 game_board의 빈 공간과 같은지 비교
    for _ in range(4):
        new_pieces = []
        for piece in pieces:
            new_pieces.append(rotate_a_matrix_by_90_degree(piece))
        new_game_board = copy.deepcopy(game_board)
        for x in range(n):
            for y in range(n):
                if new_game_board[x][y] == 1:
                    new_game_board[x][y] = 0
                    q = deque([[x, y]])
                    location = [[x, y]]
                    new_location = get_new_locations([bfs(new_game_board, q, location, n)])
                    space = get_piece_or_space(game_board, new_location)[0]
                    if space in new_pieces:
                        new_pieces.remove(space)
                        for x_min, x_max, y_min, y_max in new_location:
                            for x in range(x_min, x_max+1):
                                for y in range(y_min, y_max+1):
                                    if game_board[x][y] == 1:
                                        game_board[x][y] = 0
                                        answer += 1
        pieces = new_pieces

    return answer

game_board = [[1,1,0,0,1,0],[0,0,1,0,1,0],[0,1,1,0,0,1],[1,1,0,1,1,1],[1,0,0,0,1,0],[0,1,1,1,0,0]]
table = [[1,0,0,1,1,0],[1,0,1,0,1,0],[0,1,1,0,1,1],[0,0,1,0,0,0],[1,1,0,1,1,0],[0,1,0,0,0,0]]
print(solution(game_board, table))
```
BFS를 이용해 table의 조각 좌표를 탐색하고, 좌표들을 가공한다. 가공한 조각들을 90도씩 회전하며 game_board의 빈공간과 동일한지 비교한다.
### 의견
세칸 이상부터 해결할 방법이 생각나질 않았다...
