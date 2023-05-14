# Solving   

## 내려가기
https://www.acmicpc.net/problem/2096
### 문제풀이
```python
import sys  
N = int(sys.stdin.readline().rstrip())  
now_line = list(map(int, sys.stdin.readline().rstrip().split()))  
min_dp = [now_line[x] for x in range(3)]  
max_dp = [now_line[x] for x in range(3)]  
for i in range(N-1):  
    now_line = list(map(int, sys.stdin.readline().rstrip().split()))  
    min_dp_tmp = [  
        min(min_dp[0], min_dp[1]) + now_line[0],  
  min(min_dp[0], min_dp[1], min_dp[2]) + now_line[1],  
  min(min_dp[1], min_dp[2]) + now_line[2]  
    ]  
    max_dp_tmp = [  
        max(max_dp[0], max_dp[1]) + now_line[0],  
  max(max_dp[0], max_dp[1], max_dp[2]) + now_line[1],  
  max(max_dp[1], max_dp[2]) + now_line[2]  
    ]  
    min_dp = min_dp_tmp  
    max_dp = max_dp_tmp  
print("{} {}".format(max(max_dp), min(min_dp)))
```  

### 의견  
일반적인 dp문제와 같이 풀었지만, 처음 풀었을 때에 메모리초과가 발생하여 기존의 행렬을 유지하지 않은 채 계속 값을 덮어씌우며 풀었다.


## 팰린드롬?
https://www.acmicpc.net/problem/10942
### 문제풀이
```python
import sys  
N = int(sys.stdin.readline().rstrip())  
N_list = list(map(int, sys.stdin.readline().rstrip().split()))  
M = int(sys.stdin.readline().rstrip())  
  
all_quary = []  
for _ in range(M):  
    all_quary.append(list(map(int, sys.stdin.readline().rstrip().split())))  
  
dp_table = [[False for _ in range(N)] for __ in range(N)]  
for i in range(N):  
    dp_table[i][i] = True  
for i in range(N-1):  
    if N_list[i] == N_list[i+1]:  
        dp_table[i][i+1] = True  
  
for interval in range(2, N):  
    for j in range(N-interval):  
        start_ptr = j  
        end_ptr = j+interval  
        if N_list[start_ptr] == N_list[end_ptr] and dp_table[start_ptr+1][end_ptr-1]:  
            dp_table[start_ptr][end_ptr] = True  
  
all_answer = []  
for i in range(M):  
    start_ptr = all_quary[i][0]-1  
  end_ptr = all_quary[i][1]-1  
  if dp_table[start_ptr][end_ptr]:  
        all_answer.append(1)  
    else:  
        all_answer.append(0)  
  
for answer in all_answer:  
    print(answer)
```
`i번째와 j번째의 원소가 같고, (i+1) ~ (j-1) 의 문자열이 이미 펠린드롬일때 i~j는 펠린드롬이다` 라는 내용을 가지고 코드로 구현하였다.

## 카드 합체 놀이
https://www.acmicpc.net/problem/15903
### 문제풀이
```python
import sys  
from queue import PriorityQueue  
n, m = map(int, sys.stdin.readline().rstrip().split())  
all_list = list(map(int, sys.stdin.readline().rstrip().split()))  
p_que = PriorityQueue()  
for i in all_list:  
    p_que.put(i)  
  
for i in range(m):  
    tmp_elem = p_que.get() + p_que.get()  
    p_que.put(tmp_elem)  
    p_que.put(tmp_elem)  
  
all_sum = 0  
while not p_que.empty():  
    all_sum += p_que.get()  
  
print(all_sum)
```  
 가장 작은 값 2개를 뽑아 서로 더하고 다시 집어넣는다. 이를 반복하여 마지막에 총 합을 구한다.
 
### 의견  
풀이법은 알았지만 어떤 자료구조를 사용할까 고민하다가, 문제의 카테고리에 있는 우선순위큐를 보고 이를 이용해 풀었다... 많이 사용하지 않는 자료구조라서 생각이 잘 나지 않았던 것 같다.

## 볼 모으기
https://www.acmicpc.net/problem/17615
### 문제풀이
```python
import sys  
N = int(sys.stdin.readline().rstrip())  
balls = list(sys.stdin.readline().rstrip())  
balls_check = [  
    [1 if balls[x] == 'R' else 0 for x in range(N)],  
  [1 if balls[-x-1] == 'R' else 0 for x in range(N)],  
  [0 if balls[x] == 'R' else 1 for x in range(N)],  
  [0 if balls[-x-1] == 'R' else 1 for x in range(N)]  
]  
  
min_val = 9999999999  
for i in range(4):  
    now_case = 0  
  now_balls = balls_check[i]  
    now_1 = False  
 for j in range(N):  
        if now_balls[j] == 1:  
            now_1 = True  
 else:  
            if now_1:  
                now_case += 1  
  min_val = min(min_val, now_case)  
print(min_val)
``` 
`R을 왼쪽으로 몰아두는 방법`, `R을 오른쪽으로 몰아두는 방법`, `G을 왼쪽으로 몰아두는 방법`, `G을 오른쪽으로 몰아두는 방법` 총 4개의 방식대로 문제풀이를 진행하였다. 각 방식마다 코드를 나누면 지저분해질 것 같아 input value를 변형하는 식으로 풀이를 진행했다.

### 의견  
풀이는 어렵지  않지만 이를 생각해내기가 쉽지 않았던 문제였던 것 같다.

## 마법사 상어와 토네이도
https://www.acmicpc.net/problem/20057
### 문제풀이
```python
import math  
import sys  
  
dir_mv = [[  # 왼 아래 오른 위 순서  
  [0, 0, 2, 0, 0],  
  [0, 10, 7, 1, 0],  
  [5, 55, 0, 0, 0],  
  [0, 10, 7, 1, 0],  
  [0, 0, 2, 0, 0]  
], [  
    [0, 0, 0, 0, 0],  
  [0, 1, 0, 1, 0],  
  [2, 7, 0, 7, 2],  
  [0, 10, 55, 10, 0],  
  [0, 0, 5, 0, 0]  
  
], [  
    [0, 0, 2, 0, 0],  
  [0, 1, 7, 10, 0],  
  [0, 0, 0, 55, 5],  
  [0, 1, 7, 10, 0],  
  [0, 0, 2, 0, 0]  
], [  
    [0, 0, 5, 0, 0],  
  [0, 10, 55, 10, 0],  
  [2, 7, 0, 7, 2],  
  [0, 1, 0, 1, 0],  
  [0, 0, 0, 0, 0]  
]]  
  
dir_mv_pix = [  
    (0, -1), (1, 0), (0, 1), (-1, 0)  
]  
  
N = int(sys.stdin.readline().rstrip())  
map_matrix = [[0 for i in range(N + 4)] for j in range(2)]  
for i in range(N):  
    map_matrix.append(  
        list(map(int, ("0 0 " + sys.stdin.readline().rstrip() + " 0 0").split()))  
    )  
map_matrix.append([0 for i in range(N + 4)])  
map_matrix.append([0 for i in range(N + 4)])  
  
tmp_x = int((N + 3) / 2)  
tmp_y = int((N + 3) / 2)  
mv_step = 1  
mv_flag = 0 # mv_step만큼 이동하는 카운트  
mv_secn = 0 # 2번마다 step을 늘리기 위한 카운트  
now_dir = 0 # 0,1,2,3  
while True:  
    if tmp_x == 2 and tmp_y == 2:  
        break  
  next_x = tmp_x + dir_mv_pix[now_dir][1]  
    next_y = tmp_y + dir_mv_pix[now_dir][0]  
    # print("{},{} to {},{}, dir:{}".format(tmp_x - 2, tmp_y - 2, next_x - 2, next_y - 2, now_dir))  
  
  now_y_sand = map_matrix[next_y][next_x]  
    now_y_sand_cnt = 0  
  for y in range(5):  
        for x in range(5):  
            tmp_mv_sand = math.floor(now_y_sand * dir_mv[now_dir][y][x] / 100)  
            map_matrix[next_y - 2 + y][next_x - 2 + x] += tmp_mv_sand  
            now_y_sand_cnt += tmp_mv_sand  
    map_matrix[next_y][next_x] = 0  
  map_matrix[next_y + dir_mv_pix[now_dir][0]][next_x + dir_mv_pix[now_dir][1]] += now_y_sand - now_y_sand_cnt  
  
    # make next step & direction  
  mv_flag += 1  
  if mv_flag >= mv_step:  
        mv_flag = 0  
  mv_secn += 1  
  now_dir = (now_dir + 1) % 4  
  if mv_secn == 2:  
        mv_secn = 0  
  mv_step += 1  
  tmp_x = next_x  
    tmp_y = next_y  
  
all_cnt = 0  
for i in range(N+4):  
    for j in range(N+4):  
        if i < 2 or i >= N + 2 or j < 2 or j >= N + 2:  
            all_cnt += map_matrix[i][j]  
print(all_cnt)
```  

