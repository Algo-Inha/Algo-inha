
# Solving﻿  

## 회의실 배정
https://www.acmicpc.net/problem/1931
### 문제풀이  
```python  
import sys  
N = int(sys.stdin.readline().rstrip())  
all_meet = []  
for i in range(N):  
    all_meet.append(list(map(int, sys.stdin.readline().rstrip().split())))  
  
  
  
# Make output    
all_meet.sort(key = lambda x : x[1])  
now_time = 0  
now_idx = 0  
now_meet = 0  
while now_idx < len(all_meet):  
    if now_time <= all_meet[now_idx][0]:  
        now_time = all_meet[now_idx][1]  
        now_idx += 1  
  now_meet += 1  
  else:  
        now_idx += 1  
  
print(now_meet)
```
끝나는 시간을 기준으로 Sorting을 한 행렬에 대해서 앞에서부터 차례대로 진행하며 회의를 진행할 수 있는지 파악하는 과정이다. 

### 의견  
코드를 보면 생각보다 간단한 것 같지만, 실제로 생각하기엔 까다로웠던 문제였다. 


## 타일 채우기
https://www.acmicpc.net/problem/2133
### 문제풀이  
```python  
import sys  
N = int(sys.stdin.readline().rstrip())  
  
all_mat = [0 for _ in range(max(N+1,3))]  
all_mat[0], all_mat[2] = (1, 3)  
if N % 2 != 0:  
    print(0)  
else:  
    N_ptr = 3  
  while N_ptr < N:  
        N_ptr += 1  
  all_mat[N_ptr] = all_mat[N_ptr - 2] * 3  
  N_sub_ptr = 2  
  while N_sub_ptr <= N_ptr:  
            N_sub_ptr += 2  
  all_mat[N_ptr] += all_mat[N_ptr - N_sub_ptr] * 2  
  print(all_mat[N])
```

### 의견  
해당 문제는 이전의 "2*N 타일링"과는 조금 복잡한 문제였다. 점화식을 세우기 너무 까다로워서 고민을 오래하다가 어쩔 수 없이 검색을 통해 점화식을 이해하고 이를 코드로 변경하였다.

## 안전 영역
https://www.acmicpc.net/problem/2468
### 문제풀이  
```python  
import sys  
from collections import deque  
dir_matrix = ((0,1),(1,0),(0,-1),(-1,0))  
N = int(sys.stdin.readline().rstrip())  
all_map = []  
min_fig = 100  
max_fig = 0  
for i in range(N):  
    tmp_inp = list(map(int, sys.stdin.readline().rstrip().split()))  
    all_map.append(tmp_inp)  
    min_fig = min(min(tmp_inp), min_fig)  
    max_fig = max(max(tmp_inp), max_fig)  
  
max_groups = 1  
for now_water in range(min_fig, max_fig+1):  
    is_visited = [[False for x in range(N)] for y in range(N)]  
    all_group = 0  
  for y in range(N):  
        for x in range(N):  
            if not is_visited[y][x] and all_map[y][x]>=now_water:  
                now_deque = deque()  
                is_visited[y][x] = True  
  now_deque.append([y,x])  
                all_group += 1  
  while now_deque:  
                    tmp_elem = now_deque.popleft()  
                    for dir_idx in range(4):  
                        tmp_y = tmp_elem[0] + dir_matrix[dir_idx][0]  
                        tmp_x = tmp_elem[1] + dir_matrix[dir_idx][1]  
                        if 0<=tmp_y<N and 0<=tmp_x<N:  
                            if not is_visited[tmp_y][tmp_x] and all_map[tmp_y][tmp_x]>=now_water:  
                                is_visited[tmp_y][tmp_x] = True  
  now_deque.append([tmp_y,tmp_x])  
    max_groups = max(max_groups, all_group)  
  
print(max_groups)
```
BFS를 통한 그룹화 작업을 진행하였다. 처음에는 계속 답이 틀렸다고 나왔는데, `for now_water in range(min_fig, max_fig+1):` 부분에서 뒤 값을 `max_fig`로 두고 진행하여 최대 깊이만큼 물이 올라올 때의 경우를 계산하지 못 했기 때문이었다.

### 의견  
풀이법을 떠올리기 어려운 문제는 아니었기 때문에 생각보다 간단했다.

## 단지 번호 붙이기
https://www.acmicpc.net/problem/2667
### 문제풀이  
```python  
import sys  
from collections import deque  
  
dir_matrix = ((0,1),(1,0),(0,-1),(-1,0))  
  
N = int(sys.stdin.readline().rstrip())  
all_map = []  
for i in range(N):  
    all_map.append(list(map(int, list(sys.stdin.readline().rstrip()))))  
is_visited = [[False for x in range(N)]for y in range(N)]  
  
all_group = 0  
size_list = []  
for y in range(N):  
    for x in range(N):  
        if all_map[y][x] == 1 and not is_visited[y][x]:  
            now_size = 1  
  all_group += 1  
  is_visited[y][x] = True  
  now_deque = deque()  
            now_deque.append([y,x])  
            while now_deque:  
                tmp_elem = now_deque.popleft()  
                for dir_idx in range(4):  
                    tmp_y = tmp_elem[0] + dir_matrix[dir_idx][0]  
                    tmp_x = tmp_elem[1] + dir_matrix[dir_idx][1]  
                    if 0<=tmp_y<N and 0<=tmp_x<N:  
                        if not is_visited[tmp_y][tmp_x] and all_map[tmp_y][tmp_x] == 1:  
                            is_visited[tmp_y][tmp_x] = True  
  now_deque.append([tmp_y,tmp_x])  
                            now_size += 1  
  if now_size>0:  
                size_list.append(now_size)  
size_list.sort()  
  
print(all_group)  
for size in size_list:  
    print(size)
```
BFS를 통한 그룹화 문제였다.

### 의견  
이전 문제인 "안전영역"과 그룹화 프로세스가 동일하다.

## 거리두기 확인하기
https://school.programmers.co.kr/learn/courses/30/lessons/81302
### 문제풀이  
```python  
from collections import deque  
  
dir_matrix = ((0,1),(1,0),(0,-1),(-1,0))  
def solution(places):  
    ret_list = []  
    for place in places:  
        now_map = place  
        now_flag = 1  
  for y in range(5):  
            for x in range(5):  
                if now_map[y][x] == "P":  
                    BFS_deque = deque()  
                    BFS_deque.append([y,x,0])  
                    while BFS_deque:  
                        tmp_BFS_deque = BFS_deque.popleft()  
                        for dir_idx in range(4):  
                            tmp_y = tmp_BFS_deque[0] + dir_matrix[dir_idx][0]  
                            tmp_x = tmp_BFS_deque[1] + dir_matrix[dir_idx][1]  
                            if 0 <= tmp_y < 5 and 0 <= tmp_x < 5:  
                                if now_map[tmp_y][tmp_x] == "O" and tmp_BFS_deque[2]==0:  
                                    BFS_deque.append([tmp_y, tmp_x, tmp_BFS_deque[2]+1])  
                                    continue  
 if now_map[tmp_y][tmp_x] == "P" and not (tmp_y==y and tmp_x==x):  
                                    now_flag = 0  
  break  
 if now_flag == 0: # Escape condition  
  break  
 if now_flag == 0: # Escape condition  
  break  
  ret_list.append(now_flag)  
    return ret_list
```
BFS를 통해 사람이 가장 가까운 다른 사람의 위치를 파악하는 코드이다. 딱히 visited를 처리하지 않았는데 이는 단 2번만 이동하여 체크해야할 곳이 매우 적기도 하며, 오히려 visited 행렬을 위한 메모리 사용이 더 경제적이지 않을 것 같기도 했다.

