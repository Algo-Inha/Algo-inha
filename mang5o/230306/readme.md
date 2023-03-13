
# Solving﻿  

## 자두나무
https://www.acmicpc.net/problem/2240
### 문제풀이  
```python  
import sys  
T, W = map(int, sys.stdin.readline().rstrip().split())  
all_matrix = [int(sys.stdin.readline().rstrip())-1 for _ in range(T)] # 나무 번호를 0과 1로 변경  
# dp_table[A][B][C] -> A시간에 B나무에 있으며 C번 움직인 뒤에 최대점수  
dp_table = [[[-9999 for c in range(W+1)] for b in range(2)] for a in range(T+1)]  
  
if T >= 2:  
    if all_matrix[0] == 0:  
        dp_table[1][0][0] = 1  
  dp_table[1][1][0] = 0  
  else:  
        dp_table[1][1][1] = 1  
  dp_table[1][0][0] = 0  
  for a in range(2, T+1):  
        for b in range(2):  
            for c in range(W+1):  
                if all_matrix[a-1] == b:  
                    # 현재 위치로 사과가 떨어질 때  
  if c >= 1:  
                        dp_table[a][b][c] = max(  
                            dp_table[a - 1][1 - b][c - 1] + 1,  
  dp_table[a - 1][b][c] + 1  
  )  
                    else:  
                        dp_table[a][b][c] = dp_table[a - 1][b][c] + 1  
  else:  
                    # 반대 위치로 사과가 떨어질 때  
  if c >= 1:  
                        dp_table[a][b][c] = max(  
                            dp_table[a - 1][1 - b][c - 1],  
  dp_table[a - 1][b][c]  
                        )  
                    else:  
                        dp_table[a][b][c] = dp_table[a - 1][b][c]  
    # print(dp_table)  
  print(max(dp_table[-1][0] + dp_table[-1][1]))  
else:  
    print(1)
```
DP 테이블을 가지고 풀이를 진행했다. `dp_table[A][B][C] -> A시간에 B나무에 있으며 C번 움직인 뒤에 최대점수` 로 구현하였다.

### 의견
처음 시작점이 1번 나무라는 점을 문제를 통해 알고 시작했으나, 이를 문제에 어떻게 녹여야 좋을 지 고민을 하는 데에 시간을 소모했다.


## 부등호
https://www.acmicpc.net/problem/2529
### 문제풀이  
```python  
import sys  
k = int(sys.stdin.readline().rstrip())  
operators = sys.stdin.readline().rstrip().split()  
all_stack = [[[x], {x}] for x in range(10)]  
min_str = '9'*(len(operators)+1)  
max_str = '0'*(len(operators)+1)  
  
while all_stack:  
    tmp_elem = all_stack.pop()  
    if len(tmp_elem[0]) == len(operators)+1:  
        new_tmp_elem = ''  
  for ii in tmp_elem[0]:  
            new_tmp_elem += str(ii)  
        if min_str > new_tmp_elem:  
            min_str = new_tmp_elem  
        if max_str < new_tmp_elem:  
            max_str = new_tmp_elem  
        continue  
  tmp_elem_set = list(tmp_elem[1])  
    if operators[len(tmp_elem[0])-1] == '>':  
        for i in range(0, tmp_elem[0][-1]):  
            if not i in tmp_elem[1]:  
                tmp_tmp_elem = [[xx for xx in tmp_elem[0]], set([xx for xx in tmp_elem_set])]  
                tmp_tmp_elem[0].append(i)  
                tmp_tmp_elem[1].add(i)  
                all_stack.append(tmp_tmp_elem)  
    else:  
        for i in range(tmp_elem[0][-1]+1, 10):  
            if not i in tmp_elem[1]:  
                tmp_tmp_elem = [[xx for xx in tmp_elem[0]], set([xx for xx in tmp_elem_set])]  
                tmp_tmp_elem[0].append(i)  
                tmp_tmp_elem[1].add(i)  
                all_stack.append(tmp_tmp_elem)  
  
print(max_str)  
print(min_str)
```
각 상황에서 가능한 수의 조합을 백트래킹을 통해 구하여 문제를 풀었다.

### 의견
처음엔 부등호를 해석하여 최대한 수가 붙게 한 뒤, 모든 자리 수에 +/-1을 하여 수의 목록을 구했는데, 경우에 따라 값이 달라져 결국 모든 경우의 수를 구하는 방향으로 풀이를 진행했다.

## 마법사 상어와 파이어스톰
https://www.acmicpc.net/problem/20058
### 문제풀이  
```python  
import sys  
from collections import deque  
  
dir_matrix = ((0,1),(0,-1),(1,0),(-1,0))  
N, Q = map(int, sys.stdin.readline().rstrip().split())  
N = 2**N  
map_matrix = []  
for i in range(N):  
    map_matrix.append(list(map(int, sys.stdin.readline().rstrip().split())))  
questions = list(map(int, sys.stdin.readline().rstrip().split()))  
diff_matrix = [[False for i in range(N)] for j in range(N)]  # True일 경우 녹는다  
for firestorm in questions:  
    if firestorm != 0:  
        # 회전  
  tmp_matrix = [[0 for i in range(N)] for j in range(N)]  
        now_grid = 2 ** firestorm  
        now_y_grid = N//now_grid  
        now_x_grid = N//now_grid  
        for y_grid in range(now_y_grid):  
            for x_grid in range(now_x_grid):  
                for y in range(now_grid):  
                    for x in range(now_grid):  
                        tmp_y = now_grid * y_grid + y  
                        tmp_x = now_grid * x_grid + x  
                        tmp_rotated_y = now_grid * y_grid + x  
                        tmp_rotated_x = now_grid * x_grid + now_grid - 1 - y  
                        tmp_matrix[tmp_rotated_y][tmp_rotated_x] = map_matrix[tmp_y][tmp_x]  
  
        map_matrix = tmp_matrix  # shallow copy라 assign에 시간이 오래걸리지 않음  
  
  # 얼음 녹기  
  now_all_melted = True  
 for y in range(N):  
        for x in range(N):  
            now_surrounding = 0  
  for dir_idx in range(4):  
                tmp_y = y + dir_matrix[dir_idx][0]  
                tmp_x = x + dir_matrix[dir_idx][1]  
                if 0<=tmp_y<N and 0<=tmp_x<N:  
                    if map_matrix[tmp_y][tmp_x]>0:  
                        now_surrounding += 1  
  if now_surrounding<3:  
                diff_matrix[y][x] = True  
 else:  
                diff_matrix[y][x] = False  
 for y in range(N):  
        for x in range(N):  
            if diff_matrix[y][x] and map_matrix[y][x]>0:  
                map_matrix[y][x] -= 1  
  if map_matrix[y][x] > 0:  
                now_all_melted = False  
 if now_all_melted:  
        break  
  
# 총 얼음량 및 덩어리 구하기  
deque_bfs = deque()  
visited_matrix = [[False for i in range(N)] for j in range(N)]  
for y in range(N):  
    for x in range(N):  
        if map_matrix[y][x] == 0:  
            visited_matrix[y][x] = True  
  
max_area = 0  
all_ice = 0  
for y in range(N):  
    for x in range(N):  
        if map_matrix[y][x] != 0 and not visited_matrix[y][x]:  
            now_area = 1  
  all_ice += map_matrix[y][x]  
            deque_bfs.append((y,x))  
            visited_matrix[y][x] = True  
 while len(deque_bfs) > 0:  
                tmp_position = deque_bfs.popleft()  
                for dir_idx in range(4):  
                    tmp_y = tmp_position[0] + dir_matrix[dir_idx][0]  
                    tmp_x = tmp_position[1] + dir_matrix[dir_idx][1]  
                    if 0<=tmp_y<N and 0<=tmp_x<N:  
                        if not visited_matrix[tmp_y][tmp_x]:  
                            visited_matrix[tmp_y][tmp_x] = True  
  deque_bfs.append((tmp_y,tmp_x))  
                            all_ice += map_matrix[tmp_y][tmp_x]  
                            now_area += 1  
  if max_area < now_area:  
                max_area = now_area  
  
print(all_ice)  
print(max_area)
```
### 의견
코드는 가장 길지만 구현 문제가 시간은 그렇게 오래 걸리지는 않는 것 같다.


## 이모티콘 할인행사
https://school.programmers.co.kr/learn/courses/30/lessons/150368
### 문제풀이  
```python  
from itertools import product  
def solution(users, emoticons):  
    all_result = []  
    perm = product([10, 20, 30, 40], repeat=len(emoticons))  
    for perm_elem in perm:  
        all_cost = 0  
  all_plus_user = 0  
  for user in users:  
            tmp_result = 0  
  for perm_idx in range(len(emoticons)):  
                if perm_elem[perm_idx] >= user[0]:  
                    tmp_result += (emoticons[perm_idx] * (100 - perm_elem[perm_idx])) // 100  
  if tmp_result >= user[1]:  
                all_plus_user += 1  
  else:  
                all_cost += tmp_result  
        all_result.append([all_plus_user, all_cost])  
    all_result.sort(key=lambda x:(x[0], x[1]), reverse=True)  
    return all_result[0]
```
각 이모티콘이 할인 가능한 경우의 수를 모두 가지고 계산했다. 효율성 검사가 통과 못하진 않을까 했지만 이게 최선인 것 같다.

### 의견
중복순열을 까먹고 계속 풀다가 뭔가 이상해서 perm를 출력해보고 잘못 진행하고 있다는 걸 보고 `product`로 수정하였다. 중복순열은 처음 써보는 것 같다.
