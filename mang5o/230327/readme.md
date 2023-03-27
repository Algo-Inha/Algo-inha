
# Solving﻿  

## 농장 관리
https://www.acmicpc.net/problem/1245
### 문제풀이  
```python  
import sys  
from collections import deque  
# dir_matrix = [[1,0],[1,1],[1,-1],[0,-1],[0,1],[-1,-1],[-1,0],[-1,1]]  
dir_matrix = [[1,0],[0,-1],[0,1],[-1,0]]  
N, M = map(int, sys.stdin.readline().rstrip().split())  
all_matrix = [list(map(int, sys.stdin.readline().rstrip().split())) for _ in range(N)]  
  
all_figs = 0  
for yy in range(N):  
    for xx in range(M):  
        if all_matrix[yy][xx] != 0:  
            all_figs += 1  
  all_matrix[yy][xx] = 0  
  tmp_deque = deque()  
            tmp_deque.append([yy,xx])  
            while tmp_deque:  
                tmp_elem = tmp_deque.popleft()  
                for dir_idx in range(len(dir_matrix)):  
                    tmp_yy = tmp_elem[0] + dir_matrix[dir_idx][0]  
                    tmp_xx = tmp_elem[1] + dir_matrix[dir_idx][1]  
                    if 0 <= tmp_yy < N and 0 <= tmp_xx < M:  
                        if all_matrix[tmp_yy][tmp_xx] != 0:  
                            all_matrix[tmp_yy][tmp_xx] = 0  
  tmp_deque.append([tmp_yy, tmp_xx])  
  
print(all_figs)
```

### 의견
솔직히 몇 번을 봐도 무슨 소리인지 잘 모르겠다.... 다른 풀이를 보고 문제가 이해가 되면 다시 풀어봐야겠다


## 신입사원
https://www.acmicpc.net/problem/1946
### 문제풀이  
```python  
import sys  
T = int(sys.stdin.readline().rstrip())  
all_figs = []  
for i in range(T):  
    N = int(sys.stdin.readline().rstrip())  
    all_people = [list(map(int, sys.stdin.readline().rstrip().split())) for _ in range(N)]  
    all_people.sort(key = lambda x : x[0])  
    fig = 0  
  min_2nd = 999999  
  for ii in range(N):  
        if min_2nd > all_people[ii][1]:  
            min_2nd = all_people[ii][1]  
            fig += 1  
  all_figs.append(fig)  
for i in range(T):  
    print(all_figs[i])
```
1개의 순위에 대해 정렬하고 나머지 1개에 대해서 자신 이전의 사람보다 순위가 높다면 통과하는 식으로 풀이를 진행했다.

### 의견
처음엔 순위가 아니라 점수를 input으로 받는 줄 알아서 약간 헤맸던 것 같다.


## 영역 구하기
https://www.acmicpc.net/problem/2583
### 문제풀이  
```python  
import sys  
from collections import deque  
  
M, N, K = map(int, sys.stdin.readline().rstrip().split())  
all_matrix = [[False for x in range(N)] for y in range(M)]  
for _ in range(K):  
    # 위아래로 바뀔 필요없음  
  x1, y1, x2, y2 = map(int, sys.stdin.readline().rstrip().split())  
    for yy in range(y1, y2):  
        for xx in range(x1, x2):  
            all_matrix[yy][xx] = True  
  
all_cluster = 0  
dir_matrix = [[0,1],[1,0],[0,-1],[-1,0]]  
size_arr = []  
for yy in range(M):  
    for xx in range(N):  
        if not all_matrix[yy][xx]:  
            all_cluster += 1  
  now_area = 1  
  graph_deque = deque()  
            graph_deque.append([yy,xx])  
            all_matrix[yy][xx] = True  
 while graph_deque:  
                tmp_elem = graph_deque.popleft()  
                for dir_idx in range(4):  
                    tmp_yy = tmp_elem[0] + dir_matrix[dir_idx][0]  
                    tmp_xx = tmp_elem[1] + dir_matrix[dir_idx][1]  
                    if 0<=tmp_yy<M and 0<=tmp_xx<N:  
                        if not all_matrix[tmp_yy][tmp_xx]:  
                            all_matrix[tmp_yy][tmp_xx] = True  
  now_area += 1  
  graph_deque.append([tmp_yy,tmp_xx])  
            size_arr.append(now_area)  
size_arr.sort()  
size_arr = list(map(str, size_arr))  
size_print = ' '.join(size_arr)  
print(all_cluster)  
print(size_print)
```
그래프 탐색으로 영역 그룹화하기


## 가장 큰 증가하는 부분 수열
https://www.acmicpc.net/problem/11055
### 문제풀이  
```python  
import sys  
  
N = int(sys.stdin.readline().rstrip())  
all_matrix = list(map(int, sys.stdin.readline().rstrip().split()))  
all_dp = [-1 for _ in range(N)]  
all_dp[0] = all_matrix[0]  
  
for i in range(1,N):  
    max_val = -1  
  for j in range(i):  
        if max_val < all_dp[j] and all_matrix[i] > all_matrix[j]:  
            max_val = all_dp[j]  
    if max_val == -1:  
        all_dp[i] = all_matrix[i]  
    else:  
        max_val += all_matrix[i]  
        all_dp[i] = max_val  
  
print(max(all_dp))
```
DP 테이블을 이용해서 현재 값을 포함했을 때 이전 행렬들을 포함해서 최대의 수열값을 모두 저장하며 진행했다. 마지막에 DP table에서 가장 큰 값을 가져와서 결과를 도출했다.

### 의견
전에 거의 동일한 문제를 풀었던 것 같아서 바로 풀이를 진행했다.

## 마법사 상어와 파이어볼
https://www.acmicpc.net/problem/20056
### 문제풀이  
```python  
import sys, math  
  
dir_matrix = ((-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1))  
  
N, M, K = map(int, sys.stdin.readline().rstrip().split())  
map_matrix = [[list() for i in range(N)] for j in range(N)]  
for i in range(M):  
    tmp_r, tmp_c, tmp_m, tmp_s, tmp_d = map(int, sys.stdin.readline().rstrip().split())  
    tmp_r -= 1  
  tmp_c -= 1  
  map_matrix[tmp_r][tmp_c].append([tmp_m, tmp_s, tmp_d, 0])  
  
for step in range(K):  
    # 스탭 1. d방향대로 이동  
  for yy in range(N):  
        for xx in range(N):  
            for balls in range(len(map_matrix[yy][xx])):  
                if map_matrix[yy][xx][balls][3] == step:  
                    now_ball_info = map_matrix[yy][xx][balls]  
                    now_dir = dir_matrix[now_ball_info[2]]  
                    tmp_yy = yy + now_dir[0] * now_ball_info[1]  
                    tmp_xx = xx + now_dir[1] * now_ball_info[1]  
                    tmp_yy = tmp_yy % N  
                    tmp_xx = tmp_xx % N  
                    map_matrix[tmp_yy][tmp_xx].append([  
                        now_ball_info[0], now_ball_info[1], now_ball_info[2], step + 1  
  ])  
            # 그 칸의 현재 스탭 원소 지우기 (뒤부터 지우기)  
  tmp_len = len(map_matrix[yy][xx])  
            for balls in range(tmp_len):  
                tmp_idx = tmp_len - balls - 1  
  if map_matrix[yy][xx][tmp_idx][3] == step:  
                    del map_matrix[yy][xx][tmp_idx]  
    # 스탭 2. 같은 칸에 여러개가 존재할 경우  
  for yy in range(N):  
        for xx in range(N):  
            if len(map_matrix[yy][xx]) > 1:  
                tmp_equal_flag = True  
  tmp_even = True  
 if map_matrix[yy][xx][0][2] % 2 == 1:  
                    tmp_even = False  
  # 방향 지정  
  if tmp_even:  
                    for i in map_matrix[yy][xx]:  
                        if i[2] % 2 == 1:  
                            tmp_equal_flag = False  
 break if not tmp_even:  
                    for i in map_matrix[yy][xx]:  
                        if i[2] % 2 == 0:  
                            tmp_equal_flag = False  
 break  all_m = 0  
  all_s = 0  
  for i in map_matrix[yy][xx]:  
                    all_m += i[0]  
                    all_s += i[1]  
                all_m = int(math.floor(all_m/5))  
                all_s = int(math.floor(all_s/len(map_matrix[yy][xx])))  
                if all_m != 0:  
                    if tmp_equal_flag:  
                        map_matrix[yy][xx] = [[all_m, all_s, dir_tmp, step + 1] for dir_tmp in [0, 2, 4, 6]]  
                    else:  
                        map_matrix[yy][xx] = [[all_m, all_s, dir_tmp, step + 1] for dir_tmp in [1, 3, 5, 7]]  
                else:  
                    map_matrix[yy][xx] = []  
sum_of_m = 0  
for yy in range(N):  
    for xx in range(N):  
        for i in map_matrix[yy][xx]:  
            sum_of_m += i[0]  
  
print(sum_of_m)
```


