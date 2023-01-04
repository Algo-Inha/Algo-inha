
# Solving﻿  

## 유기농 배추
https://www.acmicpc.net/problem/1012
### 문제풀이  
```python  
import sys  
from collections import deque  
T = int(sys.stdin.readline().rstrip())  
dir_matrix = (  
    (0,-1), (0,1), (1,0), (-1,0)  
)  
all_result = []  
for i in range(T):  
    M, N, K = map(int, sys.stdin.readline().rstrip().split())  
    all_map = [[0 for x in range(M)] for y in range(N)]  
    for cab in range(K):  
        tmp_inp = list(map(int, sys.stdin.readline().rstrip().split()))  
        all_map[tmp_inp[1]][tmp_inp[0]] = 1  
  all_cluster = 0  
  for y in range(N):  
        for x in range(M):  
            if all_map[y][x] == 1:  
                all_cluster += 1  
  tmp_deque = deque()  
                tmp_deque.append((y,x))  
                while tmp_deque:  
                    pop_elem = tmp_deque.popleft()  
                    for dir_idx in range(4):  
                        tmp_y = pop_elem[0] + dir_matrix[dir_idx][0]  
                        tmp_x = pop_elem[1] + dir_matrix[dir_idx][1]  
                        if 0<=tmp_y<N and 0<=tmp_x<M:  
                            if all_map[tmp_y][tmp_x] == 1:  
                                tmp_deque.append((tmp_y, tmp_x))  
                                all_map[tmp_y][tmp_x] = 0  
  all_result.append(all_cluster)  
  
for result in all_result:  
    print(result)
```
BFS + 그룹화 문제


## 곱셈
https://www.acmicpc.net/problem/1629
### 문제풀이  
```python  
import sys  
A, B, C = map(int, sys.stdin.readline().rstrip().split())  
B_binary = str(format(B, 'b'))[::-1] # Reverse  
all_mod, now_fig = A%C, 1  
for i in range(len(B_binary)):  
    if B_binary[i] == '1':  
        now_fig = (now_fig*all_mod)%C  
    all_mod = (all_mod*all_mod)%C  
print(now_fig)
```
`(A^(a+b))%C => ((A^a)%C * (A^b)%C)%C` 의 변환 방법으로 문제를 풀었다. 일반적인 분할정복의 문제풀이 방법이 아닌 풀이라서 간단히 설명을 하자면

```
# 예제 > 10, 11, 12
11(10) == 1011(2) 와 같이 2진법으로 바꾼 뒤 이를 풀어보면
(A^(2^0 + 2^1 + 2^3))%C = (A^(2^0) * A^(2^1) * A^(2^3))%C = A^(2^0)%C * A^(2^1)%C * A^(2^3)%C
의 형태로 정리가 가능하다.
A^(2^1)%C 의 경우 ((A^(2^0)%C)*(A^(2^0)%C))%C 이므로 계산 횟수를 log 수준으로 감소시킬 수 있다. 
```

### 의견
처음에는 나머지가 일정한 반복패턴을 띄기 때문에 이 패턴의 사이클 길이를 구해서 계산했지만, 시간이나 메모리 초과로 실패했다. 분할정복이라는 흔하지 않은 주제의 문제라서 흥미로웠다.

## NBA 농구
https://www.acmicpc.net/problem/2852
### 문제풀이  
```python  
import sys  
N = int(sys.stdin.readline().rstrip())  
all_goals = [list(sys.stdin.readline().rstrip().split()) for _ in range(N)]  
for i in range(N):  
    all_goals[i][0] = int(all_goals[i][0])  
    tmp_time = list(map(int,all_goals[i][1].split(":")))  
    tmp_time_converted = tmp_time[0] * 60 + tmp_time[1]  
    all_goals[i][1] = tmp_time_converted  
  
now_score = [0, 0, 0] # padd, team1, team2  
times = [0, 0, 0] # now_time, team1, team2  
for goal in all_goals:  
    if now_score[1] < now_score[2]:  
        times[2] += goal[1] - times[0]  
    elif now_score[1] > now_score[2]:  
        times[1] += goal[1] - times[0]  
    times[0] = goal[1]  
    now_score[goal[0]] += 1  
if now_score[1] < now_score[2]:  
    times[2] += 48*60 - times[0]  
elif now_score[1] > now_score[2]:  
    times[1] += 48*60 - times[0]  
  
print("{}:{}\n{}:{}".format(str(times[1]//60).zfill(2), str(times[1]%60).zfill(2), str(times[2]//60).zfill(2), str(times[2]%60).zfill(2)))
```
String으로 들어온 시간을 Second로 바꾸어 풀었다. 



## 파도반 수열
https://www.acmicpc.net/problem/9461
### 문제풀이  
```python  
import sys  
T = int(sys.stdin.readline().rstrip())  
all_case = [int(sys.stdin.readline().rstrip()) for _ in range(T)]  
max_val = max(all_case)  
  
all_triangle = [1,1,1,2,2]  
for i in range(max_val):  
    if i < 5:  
        continue  
 else:  
        all_triangle.append(all_triangle[i-1] + all_triangle[i-5])  
  
for i in range(T):  
    print(all_triangle[all_case[i]-1])
```
점화식인 `N[i] = N[i-1] + N[i-5]` 를 확인한 뒤에 손쉽게 풀린 문제였다.

### 의견
점화식 문제라고 하기엔 규칙을 찾기 어려운 문제였다. 다행히 문제 자체에서 수열을 어느정도 충분히 제시해주어서 도움이 되었다.

## 동전 0
https://www.acmicpc.net/problem/11047
### 문제풀이  
```python  
import sys  
N, K = map(int, sys.stdin.readline().rstrip().split())  
all_coin = []  
for i in range(N):  
    cost = int(sys.stdin.readline().rstrip())  
    if cost <= K:  
        all_coin.append(cost)  
  
# (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)  
coins = 0  
for i in range(len(all_coin)):  
    now_coin_idx = len(all_coin) - i - 1  
  K_diff = K - (K % all_coin[now_coin_idx])  
    coins += K_diff // all_coin[now_coin_idx]  
    K -= K_diff  
  
print(coins)
```
`(1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수) `  라는 문제의 조건이 DP가 아닌 그리디 문제로 바꿀 수 있는 키워드였다. 가장 비싼 코인부터 몇 개가 들어갈 수 있는지 나눠주는 작업을 반복했다.

### 의견
문제 조건을 눈여겨 봐야겠다.
