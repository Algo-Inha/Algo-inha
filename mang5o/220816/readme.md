
# Solving﻿  

## 요세푸스 문제
https://www.acmicpc.net/problem/1158
### 문제풀이  
```python  
import sys  
from collections import deque  
N, K = map(int, sys.stdin.readline().rstrip().split())  
order_queue = deque()  
ret_str = "<"  
for i in range(N):  
    order_queue.append(i+1)  
while order_queue:  
    for i in range(K-1):  
        tmp_elem = order_queue.popleft()  
        order_queue.append(tmp_elem)  
    ret_str += "{}, ".format(order_queue.popleft())  
ret_str = ret_str[:-2] + ">"  
print(ret_str)
```
list로 구현한다면 무조건 delete 연산이 들어가야 하기 때문에 비효율적이라고 생각했다. 3명씩 건너뛴다면 2번 queue에서 빼고 다시 넣은 뒤 pop을 한 번 더 해서 그 사람을 빼는 식으로 진행했다.

### 의견  
list로 구현한 뒤 커서를 움직이며 확인하는 방법으로 생각을 해봐도 이 풀이와의 Big-O notation으로는 차이가 나지 않을 것 같지만 worst case에 대해서 연산 횟수가 꽤 많이 차이날 것이라고 생각한다.

## 외계인의 기타 연주
https://www.acmicpc.net/problem/2841
### 문제풀이  
```python  
import sys  
N, P = map(int, sys.stdin.readline().rstrip().split())  
all_querys = []  
for i in range(N):  
    n, p = map(int, sys.stdin.readline().rstrip().split())  
    all_querys.append([n-1,p])  
finger_status = [[0], [0], [0], [0], [0], [0]]  
movement_fig = 0  
for query in all_querys:  
    while True:  
        if finger_status[query[0]][-1] > query[1]:  
            finger_status[query[0]].pop()  
            movement_fig += 1  
  else:  
            break  
 if finger_status[query[0]][-1] < query[1]:  
        finger_status[query[0]].append(query[1])  
        movement_fig += 1  
print(movement_fig)
```
6개의 Stack을 통해 문제풀이를 진행했다. 더 높은 플랫을 누르고 있는 것이 Stack의 top에 위치하도록 구현하였으며, top을 비교하고 손을 몇 개를 떼야하는지 확인하며 진행했다.

### 의견  
문제 자체 텍스트가 좀 이해하기 어려워서 글을 두세번 읽었다.

## 무기 공학
https://www.acmicpc.net/problem/18430
### 문제풀이  
```python  
import sys  
  
N, M = map(int, sys.stdin.readline().rstrip().split())  
map_matrix = []  
dir_matrix = (  
    ((1,0), (0,-1)),  
  ((-1,0), (0,-1)),  
  ((-1,0), (0,1)),  
  ((1,0), (0,1))  
)  
for i in range(N):  
    map_matrix.append(list(map(int, sys.stdin.readline().rstrip().split())))  
if N == 1 or M == 1:  
    print(0)  
else:  
    max_score = 0  
  all_dfs = [  
        [  
            [[False for x in range(M)] for y in range(N)], # Visited matrix  
  [0, 0, 0]  # start y, x, now_score  
  ]  
    ]  
    while len(all_dfs) > 0:  
        now_elem = all_dfs.pop()  
        now_visited = now_elem[0]  
        now_board = now_elem[1]  
        max_score = max(max_score, now_board[2])  
        for yy in range(N):  
            if yy < now_board[0]:  
                continue  
 for xx in range(M):  
                if yy == now_board[0] and xx < now_board[1]:  
                    continue  
 if now_visited[yy][xx]:  
                    continue  
  now_center = map_matrix[yy][xx]  
                for dir_idx in range(4):  
                    now_1 = [yy + dir_matrix[dir_idx][0][0], xx + dir_matrix[dir_idx][0][1]]  
                    now_2 = [yy + dir_matrix[dir_idx][1][0], xx + dir_matrix[dir_idx][1][1]]  
                    if 0<=now_1[0]<N and 0<=now_2[0]<N and 0<=now_1[1]<M and 0<=now_2[1]<M:  
                        if not now_visited[now_1[0]][now_1[1]] and not now_visited[now_2[0]][now_2[1]]:  
                            tmp_visited = [[now_visited[yyy][xxx] for xxx in range(M)] for yyy in range(N)]  
                            tmp_visited[now_1[0]][now_1[1]] = True  
  tmp_visited[now_2[0]][now_2[1]] = True  
  tmp_visited[yy][xx] = True  
  tmp_board = [yy, xx, now_board[2]]  
                            tmp_board[2] += 2*now_center + map_matrix[now_1[0]][now_1[1]] + map_matrix[now_2[0]][now_2[1]]  
                            all_dfs.append([tmp_visited, tmp_board])  
  
    print(max_score)
```
DFS를 통해 모든 경우의 수를 계산하여 진행했다.

### 의견  
생각나는 풀이가 이거밖에 없었고, 아니 이렇게 해도 메모리가 안터진다고? 라고 생각했지만 생각보다 N,M의 제한이 매우 작아서 통과했다고 생각한다.

## 기지국 설치
https://school.programmers.co.kr/learn/courses/30/lessons/12979
### 문제풀이  
```python  
import math  
  
  
def solution(n, stations, w):  
    cover_scope = 2 * w + 1  
  all_station = 0  
  if stations[0] - 1 - w > 0:  # left scope  
  all_station += math.ceil((stations[0] - 1 - w) / cover_scope)  
    for i in range(len(stations) - 1):  # middle scope  
  if stations[i] + w < stations[i + 1] - w - 1:  
            all_station += math.ceil((stations[i + 1] - w - 1 - stations[i] - w) / cover_scope)  
    if stations[-1] + w < n:  # right scope  
  all_station += math.ceil((n - stations[-1] - w) / cover_scope)  
    return all_station
```
기지국끼리의 거리를 구한 뒤 범위를 제외한 범위 (커버해야 하는 범위) 에 몇 개의 기지국이 들어가는지 나눗셈을 통해 계산하였다. 코드상으로는 기지국 좌측과 우측의 빈공간은 따로 계산을 한 번씩 더하여 계산했다.


## 쿼드압축 후 개수 세기
https://school.programmers.co.kr/learn/courses/30/lessons/68936
### 문제풀이  
```python  
def solution(arr):  
    size = len(arr)  
    now_width = size  
    block_fig = [0,0]  # how many block  
  while True:  
        # Check all block  
  for y_idx in range(size//now_width):  
            for x_idx in range(size//now_width):  
                # check Block {start_y~end_y, start_x~end_x}  
  start_y = y_idx * now_width  
                end_y = (y_idx + 1) * now_width - 1  
  start_x = x_idx * now_width  
                end_x = (x_idx + 1) * now_width - 1  
  if arr[start_y][start_x] == 2:  
                    continue  
  now_flag = True  
 for yy in range(start_y, end_y+1):  
                    for xx in range(start_x, end_x + 1):  
                        if arr[yy][xx] != arr[start_y][start_x]:  
                            now_flag = False  
 break if not now_flag:  
                        break  
 if now_flag:  
                    block_fig[arr[start_y][start_x]] += 1  
  for yy in range(start_y, end_y + 1):  
                        for xx in range(start_x, end_x + 1):  
                            arr[yy][xx] = 2  
  if now_width == 1:  
            break  
 else:  
            now_width //= 2  
  
  return block_fig
```

### 의견  
점점 블록을 나누는 그리드를 좁히는 작업이 제일 중요한 문제였다고 생각한다. 코드상으로는 난해하지만 시간 제한은 여유로운 것 같았다.
