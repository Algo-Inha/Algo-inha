# Solving﻿
##  정수 삼각형
https://www.acmicpc.net/problem/1932
### 문제풀이
```python
import sys  
N = int(sys.stdin.readline().rstrip())  
all_input = []  
all_output = []  
for i in range(N):  
    tmp_list = list(map(int, sys.stdin.readline().rstrip().split()))  
    tmp_list = [0] + tmp_list + [0]  # Padding  
  new_list = [tmp_list[x] for x in range(i+3)]  # Copy  
  all_input.append(tmp_list)  
    all_output.append(new_list)  
for i in range(N):  
    if i == 0:  
        all_output[0][0] = all_input[0][0]  
    else:  
        for j in range(1, i + 2):  
            for diff in range(2):  
                # diff == 0 : 왼쪽 위  
  # diff == 1 : 오른쪽 위  
  all_output[i][j] = max(all_output[i][j], all_input[i][j] + all_output[i-1][j + diff - 1])  
print(max(all_output[-1]))
```
DP 문제같은 느낌으로 DP table(`all_output`)을 만들어서 문제를 풀었다. line 9~13에서의 all_input과 all_output을 초기엔 동일하게 만드는 코드가 있는데, 맨 처음엔 all_input과 all_output에 모두 tmp_list를 넣으려고 했으나 identical한 리스트가 들어가서 값을 변경할 때 서로 같이 변경되는 문제가 있어 copy를 추가로 진행하고 넣어주었다.
10번 line에서는 padding을 진행하는데, 삼각형에서 맨 왼쪽과 맨 오른쪽의 경우 삼각형 바깥의 대각선을 참조하기 때문에 양쪽에 패딩을 넣어서 이를 해결했다.

### 의견
DP의 바이블같은 기초적인 문제였던 것 같다.

##  체스
https://www.acmicpc.net/problem/1986
### 문제풀이
```python
import sys  
# 말의 이동범위  
queen_dir = ((-1,-1), (1,-1), (-1,1), (1,1), (0,1), (0,-1), (1,0), (-1,0))  
knight_diff = (  
    (1,2), (1,-2), (-1,2), (-1,-2), (2,1), (-2,1), (2,-1), (-2,-1)  
)  
N, M = map(int, sys.stdin.readline().rstrip().split())  
map_matrix = [[-1 for i in range(M)] for j in range(N)]  # N이 행인지 N이 열인지 조건이 안주어짐  
# -1 = 안전구역, 0 = Queen, 1 = Knight, 2 = Pawn, 3 = 안전하지 않은 구역  
for i in range(3):  
    tmp_input = list(map(int, sys.stdin.readline().rstrip().split()))  
    for j in range(tmp_input[0]):  
        map_matrix[tmp_input[2*j + 1] - 1][tmp_input[2*j + 2] - 1] = i  
for y in range(N):  
    for x in range(M):  
        if map_matrix[y][x] == 0:  
            for diff in range(8):  
                tmp_y = y  
                tmp_x = x  
                while True:  
                    tmp_y += queen_dir[diff][0]  
                    tmp_x += queen_dir[diff][1]  
                    if 0<=tmp_y<N and 0<=tmp_x<M:  
                        if map_matrix[tmp_y][tmp_x] == -1:  
                            map_matrix[tmp_y][tmp_x] = 3  
  elif map_matrix[tmp_y][tmp_x] != 3:  
                            break  
 else:  
                        break  
 elif map_matrix[y][x] == 1:  
            for diff in range(8):  
                tmp_y = y + knight_diff[diff][0]  
                tmp_x = x + knight_diff[diff][1]  
                if 0<=tmp_y<N and 0<=tmp_x<M:  
                    if map_matrix[tmp_y][tmp_x]==-1:  
                        map_matrix[tmp_y][tmp_x] = 3  
  
all_count = 0  
for y in range(N):  
    for x in range(M):  
        if map_matrix[y][x] == -1:  
            all_count += 1  
  
print(all_count)
```
Knight의 경우 각 말이 8개의 목적지를 가지기 때문에 8번씩만 체크를 하면 됐지만 Queen은 장애물에 따라 일직선으로 가는 칸이 매번 바뀌기 때문에 좌표를 하나씩 옮겨가며 체크하였다.

### 의견
문제 조건에서, `첫 째줄에 체스판의 크기인 n과 m이 주어진다` 라는 말이 전부이기 때문에 n이 행인지 열인지에 관해 설명이 부족한 것 같다. 물론 그 뒤에 들어오는 좌표에 대해선 각각 행과 열이라고 표시가 되어있기 때문에 문제가 없고, 이를 보고 유추하여 n이 행, m이 열으로 생각하고 풀면 문제없이 해결된다. `첫째줄에 체스판의 크기인 n과 m이 주어지고, 체스판은 n행 m열의 크기를 가진다` 등의 설명이 있었으면 좋겠다.

##  양
https://www.acmicpc.net/problem/3184
### 문제풀이
```python
import sys  
from collections import deque  
  
dir_matrix = ((0, 1), (0, -1), (1, 0), (-1, 0))  
R, C = map(int, sys.stdin.readline().rstrip().split())  
map_matrix = []  
for i in range(R):  
    map_matrix.append(  
        list(  # input parsing  
  map(int,  
  sys.stdin.readline().rstrip()  
                .replace(".", " 0")  
                .replace("#", " 1")  
                .replace("o", " 2")  
                .replace("v", " 3")[1:]  
                .split())))  
visited_matrix = [[False for x in range(C)] for y in range(R)]  # Make visited  
  
now_sheep = 0  
now_wolves = 0  
for y in range(R):  
    for x in range(C):  
        if not visited_matrix[y][x] and map_matrix[y][x] != 1:  
            grouping_deque = deque()  
            grouping_deque.append((y, x))  
            tmp_sheep = 0  
  tmp_wolves = 0  
  now_boundary = False  
 while len(grouping_deque) > 0:  
                tmp_yx = grouping_deque.popleft()  
                if visited_matrix[tmp_yx[0]][tmp_yx[1]]:  
                    continue # 중복처리 (visited를 설정하는 시점 문제)  
  if tmp_yx[0] == 0 or tmp_yx[0] == R - 1 or tmp_yx[1] == 0 or tmp_yx[1] == C - 1:  
                    now_boundary = True  
 break  visited_matrix[tmp_yx[0]][tmp_yx[1]] = True  
 if map_matrix[tmp_yx[0]][tmp_yx[1]] == 2:  
                    tmp_sheep += 1  
  elif map_matrix[tmp_yx[0]][tmp_yx[1]] == 3:  
                    tmp_wolves += 1  
  for dir_idx in range(4):  
                    tmp_y = tmp_yx[0] + dir_matrix[dir_idx][0]  
                    tmp_x = tmp_yx[1] + dir_matrix[dir_idx][1]  
                    if 0 <= tmp_y < R and 0 <= tmp_x < C:  
                        if map_matrix[tmp_y][tmp_x] != 1 and not visited_matrix[tmp_y][tmp_x]:  
                            grouping_deque.append((tmp_y, tmp_x))  
            if not now_boundary:  
                # print("Sheep : {}, Wolves : {}".format(tmp_sheep, tmp_wolves))  
  if tmp_sheep > tmp_wolves:  
                    now_sheep += tmp_sheep  
                else:  
                    now_wolves += tmp_wolves  
  
print("{} {}".format(now_sheep, now_wolves))
```
visited 상태가 아닌 모든 (y,x)값에서 BFS를 진행하도록 하며 한 덩어리가 `가장자리와 연결되지 않은 덩어리일 경우` (Line 36), 그 덩어리의 양과 늑대의 수를 가지고 카운팅한다. 일반적으론 Line28에 deque에 append를 진행하며 visited를 True로 바꾸는 방법을 사용하지만 (Line 49에서도 마찬가지), append하는 부분이 2개로 나뉘어져 있는데 이로 인해 append하는 칸이 늑대인지 양인지 처리해주는 부분까지 2배로 넣어야 하므로 코드가 길어질 것 같아 pop할 때에 이를 처리하도록 코드를 구현하였다.
문제는 append를 하며 visited를 바꾸지 않아 겹치는 좌표값이 들어갈 수 있다는 것인데, 이를 처리하기 위해 Line 35처럼 pop하는 순간 visitied를 확인하도록 코드를 추가하였다.

### 의견
전에도 이런 그루핑 문제를 자주 풀었던 것 같은데, 비슷한 유형이더라도 조건이 조금씩이라도 바뀌면 코드가 상당부분 바뀌는 유형인 것 같다.

##  행렬 테두리 회전하기
https://programmers.co.kr/learn/courses/30/lessons/77485
### 문제풀이
```python
def solution(rows, columns, queries):  
    all_smallest = []  
    all_map = [[y*columns + x + 1 for x in range(columns)] for y in range(rows)]  # Base matrix  
  for query in queries: # 행렬에 대해 언급이 이상하게 되어있음  
  right_top_figure = all_map[query[0] - 1][query[3] - 1]  
        smallest_val = right_top_figure  
        for dir_now in range(4):  
            if dir_now==0:  
                for x_diff in range(query[3]-query[1]):  
                    now_x = query[3]-x_diff-1  
  all_map[query[0]-1][now_x] = all_map[query[0]-1][now_x-1]  
                    smallest_val = min(smallest_val,all_map[query[0]-1][now_x])  
            elif dir_now==1:  
                for y_diff in range(query[2]-query[0]):  
                    now_y = query[0] + y_diff -1  
  all_map[now_y][query[1]-1] = all_map[now_y+1][query[1]-1]  
                    smallest_val = min(smallest_val,all_map[now_y][query[1]-1])  
            elif dir_now==2:  
                for x_diff in range(query[3]-query[1]):  
                    now_x = query[1] + x_diff -1  
  all_map[query[2]-1][now_x] = all_map[query[2]-1][now_x+1]  
                    smallest_val = min(smallest_val,all_map[query[2]-1][now_x])  
            else:  
                for y_diff in range(query[2]-query[0]):  
                    now_y = query[2] - y_diff -1  
  all_map[now_y][query[3]-1] = all_map[now_y-1][query[3]-1]  
                    smallest_val = min(smallest_val,all_map[now_y][query[3]-1])  
        all_map[query[0]][query[3]-1] = right_top_figure  
        all_smallest.append(smallest_val)  
    return all_smallest
```
Line 11-15는 사각형의 위, Line 16~20은 사각형의 왼쪽, Line 21~25는 사각형의 아래, Line 26~30은 사각형의 오른쪽 부분의 이동을 나타낸다. 사실 조금 편한 방법으로는 옮기기 전의 Matrix를 복사해서 그 값을 바라보며 이동하는 것이지만, 매 스탭마다 matrix를 만들기엔 Space complexity 쪽으로도 문제가 생길 것 같았고 복사하는데에 들어가는 시간도 신경이 쓰여서 행렬을 유지하며 옮기는 것을 진행하였다.
회전하는 사각형의 각 변에 대해서 A->B->C->D...순으로 숫자가 이동한다면 코드의 진행순서는 D-C-B-A로 두어야 한다. A-B-C-D순서로 진행한다면 모두 같은 값으로 덮이기 때문이다.
시작할 때에 우측상단의 값은 따로 저장해두고 그 값에 대한 이동을 가장 마지막으로 진행하였다.


### 의견
`x1 행 y1 열부터 x2 행 y2 열까지의 영역에 해당하는 직사각형에서 테두리에 있는 숫자들을 한 칸씩 시계방향으로 회전합니다` 라는 문제의 조건을 보고 머리가 어지러워졌다. 행을 x로 두고 열을 y로 두는 게.... 다행히도 예제 이미지가 있어서 이 이상함을 바로 감지할 수 있었다.

