
# Solving﻿  

## 동전 1
https://www.acmicpc.net/problem/2293
### 문제풀이  
```python  
import sys  
N, K = map(int, sys.stdin.readline().rstrip().split())  
all_cost = []  
for i in range(N):  
    all_cost.append(int(sys.stdin.readline().rstrip()))  
  
dp_table = [0 for x in range(K+1)]  
dp_table[0] = 1  
for coin in range(N):  
    for cost in range(all_cost[coin], K+1):  
        dp_table[cost] += dp_table[cost - all_cost[coin]]  
  
print(dp_table[-1])
```
DFS를 통한 백트래킹으로 문제를 풀었는데 시간초과가 나서 배낭문제와 비슷하게 DP를 사용해서 풀이를 진행하였다.

## 로또
https://www.acmicpc.net/problem/6603
### 문제풀이  
```python  
# https://www.acmicpc.net/problem/6603  
# 로또  
import sys  
import itertools  
  
  
all_query = []  
while True:  
    inp_str = sys.stdin.readline().rstrip().split()  
    if inp_str[0] == '0':  
        break  
  all_query.append(inp_str[1:])  
  
for query in range(len(all_query)):  
    comb = itertools.combinations(all_query[query], 6)  
    for case in comb:  
        print(" ".join(case))  
    if query < len(all_query) - 1:  
        print("")
```
Python의 조합 기능을 통해 문제를 풀었다. 파이썬이 아니더라도 어려운 문제는 아니었겠지만 충분히 귀찮을 수 있는 문제라고 생각한다.

### 의견 
`itertools`


## 주사위 굴리기
https://www.acmicpc.net/problem/14499
### 문제풀이  
```python  
import sys  
  
now_dice = [  
    [0],  
  [0, 0, 0],  
  [0],  
  [0]  
]  
N, M, X, Y, K = map(int, sys.stdin.readline().rstrip().split())  
all_map = []  
for i in range(N):  
    all_map.append(list(map(int, sys.stdin.readline().rstrip().split())))  
all_mov = list(map(int, sys.stdin.readline().rstrip().split()))  
  
for move in all_mov:  
    if move == 1:  # Mov right  
  if Y < M - 1:  
            Y += 1  
  new_dice = [  
                [now_dice[0][0]],  
  [now_dice[3][0], now_dice[1][0], now_dice[1][1]],  
  [now_dice[2][0]],  
  [now_dice[1][2]]  
            ]  
            now_dice = new_dice  
            print(now_dice[1][1])  
            if all_map[X][Y] == 0:  
                all_map[X][Y] = now_dice[3][0]  
            else:  
                now_dice[3][0] = all_map[X][Y]  
                all_map[X][Y] = 0  
  
  elif move == 2:  # Mov left  
  if Y > 0:  
            Y -= 1  
  new_dice = [  
                [now_dice[0][0]],  
  [now_dice[1][1], now_dice[1][2], now_dice[3][0]],  
  [now_dice[2][0]],  
  [now_dice[1][0]]  
            ]  
            now_dice = new_dice  
            print(now_dice[1][1])  
            if all_map[X][Y] == 0:  
                all_map[X][Y] = now_dice[3][0]  
            else:  
                now_dice[3][0] = all_map[X][Y]  
                all_map[X][Y] = 0  
  
  elif move == 3:  # Mov up  
  if X > 0:  
            X -= 1  
  new_dice = [  
                [now_dice[1][1]],  
  [now_dice[1][0], now_dice[2][0], now_dice[1][2]],  
  [now_dice[3][0]],  
  [now_dice[0][0]]  
            ]  
            now_dice = new_dice  
            print(now_dice[1][1])  
            if all_map[X][Y] == 0:  
                all_map[X][Y] = now_dice[3][0]  
            else:  
                now_dice[3][0] = all_map[X][Y]  
                all_map[X][Y] = 0  
  
  else:  # Mov down  
  if X < N - 1:  
            X += 1  
  new_dice = [  
                [now_dice[3][0]],  
  [now_dice[1][0], now_dice[0][0], now_dice[1][2]],  
  [now_dice[1][1]],  
  [now_dice[2][0]]  
            ]  
            now_dice = new_dice  
            print(now_dice[1][1])  
            if all_map[X][Y] == 0:  
                all_map[X][Y] = now_dice[3][0]  
            else:  
                now_dice[3][0] = all_map[X][Y]  
                all_map[X][Y] = 0
```
일반적인 구현 문제이며, new_dice를 만들고 이를 now_dice에 넣는 이동 과정을 함수화했으면 코드가 깔끔해질 것 같다.

### 의견 
문제가 불친절 하고 이해가 안 되는 부분이 좀 많았다.
```
1. 주사위의 처음 상태를 명확하게 강조하지 않아 착각을 일으켰다.
  - 처음 전개도를 보여줄 때, "지도 위에 윗 면이 1이고, 동쪽을 바라보는 방향이 3인 상태로 놓여져 있으며" 라는 설명에서 "윗 면이 1이고" 대신 "위를 가리키고 있는 것이 1번 면이고" 등으로 제공한 숫자가 면의 호칭을 알려주는 것이 필요하다.
  - 다만 친절한 문제라면 숫자대신 전개도에 A~F를 넣어 설명하는 게 훨씬 좋을 것 같다.

2. 주사위의 좌표가 (X,Y) 이다.
  - 무엇이 행이고 무엇이 열인지는 문제 조건을 통해 파악해야 하는데, "주사위를 놓은 곳의 좌표 x, y(0 ≤ x ≤ N-1, 0 ≤ y ≤ M-1)" 이 부분이다.
  - "주사위는 X행 Y열에 존재한다" 라던지, "북쪽으로 이동하면 주사위는 (X-1, Y) 로 이동한다" 라는 식의 방향과 좌표의 상관관계가 문제 내에 존재하지 않는다.
```
이렇게 문제 설명이 불친절한 문제는 `풀기 좋고 어려운 문제`는 확실히 아닌 것 같다.


## 퍼즐 조각 채우기
https://school.programmers.co.kr/learn/courses/30/lessons/84021
### 문제풀이
```python
dir_matrix = (  
    (-1, 0), (1, 0), (0, -1), (0, 1)  
)  
  
  
def solution(game_board, table):  
    comp_table = [game_board, table]  
    comp_blocks = [[], []]  
    len_side = len(game_board)  
    all_sum_size = 0  
  # Separate blocks  
  for comp_val in range(2):  
        visited_table = [[False for x in range(len(table[y]))] for y in range(len(table))]  
        for y in range(len(table)):  
            for x in range(len(table[0])):  
                if not visited_table[y][x] and comp_table[comp_val][y][x] == comp_val:  
                    tmp_dfs_area = []  
                    tmp_block_area = [[False for x in range(len(table[y]))] for y in range(len(table))]  
                    tmp_block_area[y][x] = True  
  visited_table[y][x] = True  
  tmp_dfs_area.append([y, x])  
                    while len(tmp_dfs_area) > 0:  
                        tmp_yx = tmp_dfs_area.pop()  
                        for dir_idx in range(4):  
                            tmp_yy = tmp_yx[0] + dir_matrix[dir_idx][0]  
                            tmp_xx = tmp_yx[1] + dir_matrix[dir_idx][1]  
                            if 0 <= tmp_yy < len(table) and 0 <= tmp_xx < len(table[0]):  
                                if not visited_table[tmp_yy][tmp_xx] and comp_table[comp_val][tmp_yy][tmp_xx] == comp_val:  
                                    tmp_block_area[tmp_yy][tmp_xx] = True  
  visited_table[tmp_yy][tmp_xx] = True  
  tmp_dfs_area.append([tmp_yy, tmp_xx])  
                    # Crop blocks (now block -> tmp_block_area)  
  y_min = len(table)  
                    y_max = 0  
  x_min = len(table[0])  
                    x_max = 0  
  for yyy in range(len(table)):  
                        for xxx in range(len(table[0])):  
                            if tmp_block_area[yyy][xxx]:  
                                y_min = min(y_min, yyy)  
                                y_max = max(y_max, yyy)  
                                x_min = min(x_min, xxx)  
                                x_max = max(x_max, xxx)  
                    tmp_block_cropped = [[tmp_block_area[yyy][xxx] for xxx in range(x_min, x_max+1)] for yyy in range(y_min, y_max+1)]  
                    comp_blocks[comp_val].append(tmp_block_cropped)  
    # Compare blocks  
  for board_blank in range(len(comp_blocks[0])):  
        now_same_break = -1  
  for table_block in range(len(comp_blocks[1])):  
            board_blank_elem = comp_blocks[0][board_blank]  
            table_block_elem = comp_blocks[1][table_block]  
            for dir_idx in range(4): # Just rotate comp_blocks  
  if dir_idx == 0 or dir_idx == 2: # 0 deg & 180 deg rotation  
  if len(board_blank_elem) != len(table_block_elem):  
                        continue  
 if len(board_blank_elem[0]) != len(table_block_elem[0]):  
                        continue  
 if dir_idx == 1 or dir_idx == 3: # 0 deg & 180 deg rotation  
  if len(board_blank_elem) != len(table_block_elem[0]):  
                        continue  
 if len(board_blank_elem[0]) != len(table_block_elem):  
                        continue  
  now_same_flag = True  
  now_break_flag = False  
 for yyy in range(len(board_blank_elem)):  
                    if now_break_flag:  
                        now_same_flag = False  
 break for xxx in range(len(board_blank_elem[0])):  
                        if dir_idx == 0:  # 0 clockwise deg direction  
  if board_blank_elem[yyy][xxx] != table_block_elem[yyy][xxx]:  
                                now_same_flag = False  
  now_break_flag = True  
 break if dir_idx == 1:  # 90 clockwise deg direction  
  if board_blank_elem[yyy][xxx] != table_block_elem[-1-xxx][yyy]:  
                                now_same_flag = False  
  now_break_flag = True  
 break if dir_idx == 2:  # 180 clockwise deg direction  
  if board_blank_elem[yyy][xxx] != table_block_elem[-1 -yyy][-1 - xxx]:  
                                now_same_flag = False  
  now_break_flag = True  
 break if dir_idx == 3:  # 270 clockwise deg direction  
  if board_blank_elem[yyy][xxx] != table_block_elem[xxx][-1 - yyy]:  
                                now_same_flag = False  
  now_break_flag = True  
 break if now_same_flag:  
                    now_same_break = table_block  
                    break  
 if now_same_break >= 0:  
                # Test print  
 # print("DELETED blank {}, block {}".format(board_blank, now_same_break)) # print(comp_blocks[0][board_blank]) # print(comp_blocks[1][now_same_break])  
  del comp_blocks[1][now_same_break]  
                # Calculate removed block size  
  now_block_size = 0  
  for yyy in range(len(comp_blocks[0][board_blank])):  
                    for xxx in range(len(comp_blocks[0][board_blank][0])):  
                        if comp_blocks[0][board_blank][yyy][xxx]:  
                            now_block_size += 1  
  all_sum_size += now_block_size  
  
                break  
  
 return all_sum_size
```
문제풀이가 깔끔하지는 않은 편이었다. 문제의 핵심은 `게임 판의 빈 공간과 정확히 일치하는 조각을 구분하기`인데, 게임판의 빈칸과 보드의 조각을 모두 하나하나 matrix로 만든 뒤 하나하나 비교하였다. 서로의 조각을 행렬로 만든 뒤 가장 작게 crop을 진행하였고, 90도씩 돌려가며 비교하여 코드가 약간 길어졌다.

### 의견 
`조각은 뒤집을 수는 없으나 회전할수 있다`는 조건이 사실 변형하며 비교하는 부분을 구현해야 하기 때문에 성가신 내용이었다. 
