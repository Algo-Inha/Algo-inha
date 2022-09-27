
# Solving﻿  

## 듣보잡
https://www.acmicpc.net/problem/1764
### 문제풀이  
```python  
import sys  
N, M = map(int, sys.stdin.readline().rstrip().split())  
N_set, M_set = set(), set()  
for _ in range(N):  
    N_set.add(sys.stdin.readline().rstrip())  
for _ in range(M):  
    M_set.add(sys.stdin.readline().rstrip())  
union = list(N_set & M_set)  
union.sort()  
  
print(len(union))  
for name in union:  
    print(name)
```
파이썬의 교집합 기능 사용

### 의견
👍


## 나이트의 이동
https://www.acmicpc.net/problem/7562
### 문제풀이  
```python  
import sys  
from collections import deque  
  
  
mov_dir = (  
    (-1,-2), (-2,-1), (1,-2), (2,-1),  
  (-1,2), (-2,1), (1,2), (2,1)  
)  
answers = []  
  
  
cases = int(sys.stdin.readline().rstrip())  
for case in range(cases):  
    map_size = int(sys.stdin.readline().rstrip())  
    map_visited = [[False for x in range(map_size)] for y in range(map_size)]  
    start_ptr = list(map(int, sys.stdin.readline().rstrip().split()))  
    end_ptr = list(map(int, sys.stdin.readline().rstrip().split()))  
    if start_ptr[0] == end_ptr[0] and start_ptr[1] == end_ptr[1]:  
        answers.append(0)  
        continue  
  map_visited[start_ptr[0]][start_ptr[1]] = True  
  start_ptr.append(0)  
    end_ptr.append(0)  
    path_deque = deque()  # for BFS  
  path_deque.append(start_ptr)  
    path_interval = 0  
  while len(path_deque) > 0:  
        tmp_elem = path_deque.popleft()  
        for dir_idx in range(8):  
            tmp_y = tmp_elem[0] + mov_dir[dir_idx][0]  
            tmp_x = tmp_elem[1] + mov_dir[dir_idx][1]  
            # 도착점일때  
  if tmp_y == end_ptr[0] and tmp_x == end_ptr[1]:  
                path_interval = tmp_elem[2] + 1  
  break  
 elif 0<=tmp_y<map_size and 0<=tmp_x<map_size:  
                if not map_visited[tmp_y][tmp_x]:  
                    map_visited[tmp_y][tmp_x] = True  
  path_deque.append([tmp_y,tmp_x, tmp_elem[2]+1])  
        if path_interval>0:  
            break  
  answers.append(path_interval)  
  
for answer in answers:  
    print(answer)
```
BFS를 사용한 거리 측정 알고리즘이다.

### 의견
이런 문제에서 여러개의 input이 들어가도록 출제되는 이유를 잘 모르겠다.

## 올림픽
https://www.acmicpc.net/problem/8979
### 문제풀이  
```python  
import sys  
N, K = map(int, sys.stdin.readline().rstrip().split())  
all_order = []  
for _ in range(N):  
    tmp_order = list(map(int, sys.stdin.readline().rstrip().split()))  
    tmp_order.append(-1)  
    all_order.append(tmp_order)  
all_order.sort(key=lambda x : (x[1], x[2], x[3]), reverse=True)  
all_order[0][4] = 1  
if all_order[0][0] == K:  
    print(1)  
else:  
    for i in range(1,N):  
        if all_order[i][1] == all_order[i-1][1] and all_order[i][2] == all_order[i-1][2] and all_order[i][3] == all_order[i-1][3]:  
            all_order[i][4] = all_order[i-1][4]  
        else:  
            all_order[i][4] = i+1  
  if K == all_order[i][0]:  
            print(all_order[i][4])  
            break
```
여러개의 key를 가지고 list를 sorting하는 부분이 들어갔다. 다만 이 문제에서 한번 더 생각해야 하는 부분은 공동순위에 대한 점인데, 해당 부분은 sorting한 list를 순회하면서 `이전 인덱스의 나라와 메달 수가 같다면 이전 인덱스의 순위를 가져온다` 라는 내용을 추가함으로 해결했다. 메달 수가 다르면 `인덱스+1`의 순위를 가진다.

## 파일 합치기
https://www.acmicpc.net/problem/11066
### 문제풀이  
```python  
import sys  
T = int(sys.stdin.readline().rstrip())  
answers = []  
for _ in range(T):  
    K = int(sys.stdin.readline().rstrip())  
    all_data = list(map(int, sys.stdin.readline().rstrip().split()))  
    all_data_acc = [0]  
    for i in range(K):  
        all_data_acc.append(all_data_acc[-1] + all_data[i])  # n~m의 합은 [m+1] - [n]  all_data_dp = [[0 for x in range(K)] for y in range(K)]  
    for interval in range(1,K):  
        for start_ptr in range(0,K):  
            if start_ptr + interval >= K:  
                continue  
  min_val = 99999999999  
  for tmp_cursor in range(start_ptr, start_ptr+interval):  
                min_val = min(min_val,  
  all_data_dp[start_ptr][tmp_cursor]\  
                              + all_data_dp[tmp_cursor+1][start_ptr+interval]\  
                              + all_data_acc[start_ptr+interval+1] - all_data_acc[start_ptr])  
            all_data_dp[start_ptr][start_ptr + interval] = min_val  
    answers.append(all_data_dp[0][-1])  
for answer in answers:  
    print(answer)
```
`all_data_dp[n][m]`이 `n부턴 m번째까지의 수를 합칠 때의 최소값`이라는 의미를 가지고 점점 `m-n`을 늘려가며 dp 테이블을 채워가는 식으로 진행했다.

### 의견
머리속으로는 방식을 금방 떠올리긴 했지만 누적합을 통한 계산 간소화까지 같이 포함된 문제라서 색다른 느낌이었다.

## 계란으로 계란치기
https://www.acmicpc.net/problem/16987
### 문제풀이  
```python  
import sys  
  
N = int(sys.stdin.readline().rstrip())  
dfs_stack = [[list(map(int, sys.stdin.readline().rstrip().split())) for _ in range(N)] + [0]] # 마지막 : 다음에 칠 계란위치  
max_broken = 0  
while len(dfs_stack) > 0:  
    tmp_elem = dfs_stack.pop()  
  
    if tmp_elem[-1] == N:  
        now_broken = 0  
  for egg in range(N):  
            if tmp_elem[egg][0] <= 0:  
                now_broken += 1  
  max_broken = max(max_broken, now_broken)  
        if max_broken == N:  
            break  
 continue  
 if tmp_elem[tmp_elem[-1]][0] < 0:  
        new_list = [[tmp_elem[x][s] for s in range(2)] for x in range(N)] + [tmp_elem[-1]]  
        new_list[-1] += 1  
  dfs_stack.append(new_list)  
        continue  
  
  crushed = False  
 for egg_idx in range(N):  
        if tmp_elem[-1] != egg_idx and tmp_elem[egg_idx][0] > 0 and tmp_elem[tmp_elem[-1]][0] > 0:  
            new_list = [[tmp_elem[x][s] for s in range(2)] for x in range(N)] + [tmp_elem[-1]]  
            # new_list[egg_idx]와 new_list[tmp_elem[-1]]의 충돌  
  new_list[egg_idx][0] -= new_list[new_list[-1]][1]  
            new_list[new_list[-1]][0] -= new_list[egg_idx][1]  
            new_list[-1] += 1  
  dfs_stack.append(new_list)  
            crushed = True  
  
 if not crushed:  
        new_list = [[tmp_elem[x][s] for s in range(2)] for x in range(N)] + [tmp_elem[-1]]  
        new_list[-1] += 1  
  dfs_stack.append(new_list)  
  
print(max_broken)
```
백트래킹을 통한 경우의 수 구하기

### 의견
생각 외로 시간을 많이 쏟았던 부분이 `new_list`를 만들어내는 부분인데, 원소 하나하나가 list가 들어가기 때문에  `[[tmp_elem[x][s] for s in range(2)] for x in range(N)] + [tmp_elem[-1]]` 같은 식으로 2차원 복사를 진행하여 문제를 해결했다.

## 숫자의 표현
https://school.programmers.co.kr/learn/courses/30/lessons/12924
### 문제풀이  
```python  
def solution(n):  
    acc_sum = [0]  # 누적합 행렬  
  for idx in range(n):  
        acc_sum.append(acc_sum[-1] + idx + 1)  
  
    start_ptr = 0  
  end_ptr = 0  
  answer = 0  
  while end_ptr <= n:  
        if acc_sum[end_ptr] - acc_sum[start_ptr] == n:  
            # print("{} ~ {}".format(start_ptr + 1, end_ptr))  
  answer += 1  
  end_ptr += 1  
  elif acc_sum[end_ptr] - acc_sum[start_ptr] < n:  
            end_ptr += 1  
  else:  
            start_ptr += 1  
  
  return answer
```
누적합을 구해둔 뒤, 투 포인터 풀이를 생각해서 이 풀이로 커서를 오른쪽으로 넘겨가며 그 사이의 총 합을 구하는 방식으로 문제를 해결했다.

### 의견
문제풀이 이후 풀이를 봤더니 수학적으로 간단하게 풀이하신 분들이 많아 신기했다.
