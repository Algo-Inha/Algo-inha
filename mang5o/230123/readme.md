
# Solving﻿  

## 물병
https://www.acmicpc.net/problem/1052
### 문제풀이  
```python  
N, K = map(int, sys.stdin.readline().rstrip().split())  
diff = 0  
  
now_fig = list(map(int,list(format(N, 'b')[::-1])))  
all_one = 0 # 1의 개수  
for i in range(len(now_fig)):  
    if now_fig[i] == 1:  
        all_one += 1  
  
while all_one > K:  
    # 1 더하기  
  diff += 1  
  if now_fig[-1] == 1:  
        now_fig.append(0)  
    if now_fig[0] == 0:  
        all_one += 1  
  now_fig[0] += 1  
  for idx in range(len(now_fig)-1):  
        if now_fig[idx] == 2:  
            all_one -= 1  
  now_fig[idx] = 0  
  if now_fig[idx+1] == 0:  
                all_one += 1  
  now_fig[idx+1] += 1  
  else:  
            break  
  
print(diff)
```
이 문제는 2진수로 변경했을 때의 수를 가지고 비교하면 이해하기 쉬울 수 있다. 각 물병은 `같은 양의 물병끼리 서로 합칠 수 있기 때문`에, 2의 거듭제곱꼴의 양만큼을 담을 수 있다. 예를들어 총 12리터의 물이 있다면, `12(10) = 1100(2)` 이고, 4리터와 8리터의 물병, 총 2개의 물병만 차지하게 된다. 따라서 이 문제는 `N 이상의 수 중에, 1의 숫자가 K개 이하인 최소값이 M일때, M-N 값을 구하기` 라는 문제이다.
파이썬에서 integer를 binary로 바꾸는 손쉬운 방법이 있어서 이를 이용했으며, 현재 2진수로 바꾼 수에서의 `1의 개수`를 구할 때, 물병을 1개씩 늘리며 매번 2진수 전체에서 1의 개수를 확인하기에 느릴 것 같아 처음에만 1의 개수를 구하고, 1을 더할 때마다 바뀌는 숫자에 따라 1의 개수를 계산하도록 구현했다.

### 의견
뭔가 내가 문제 지문을 점점 이해를 못 하게 독해력이 떨어지는건지... 이 문제가 뭔가 난해했던건지 잘 모르겠지만 문제를 이해하는 데에 시간이 좀 걸렸다. 풀이는 나름 금방 진행했다.

## 효율적인 해킹
https://www.acmicpc.net/problem/1325
### 문제풀이  
```python  
import sys  
from collections import deque  
N, M = map(int, sys.stdin.readline().rstrip().split())  
all_matrix = [[] for _ in range(N)]  
for case in range(M):  
    tmp_case = list(map(int, sys.stdin.readline().rstrip().split()))  
    all_matrix[tmp_case[1]-1].append(tmp_case[0]-1)  
all_surround = []  
max_visited = 0  
for start in range(N):  
    now_visited = [False for _ in range(N)]  
    now_visited[start] = True  
  visited_fig = 1  
  inj_deque = deque()  
    inj_deque.append(start)  
    while inj_deque:  
        tmp_elem = inj_deque.popleft()  
        for tmp_idx in all_matrix[tmp_elem]:  
            if not now_visited[tmp_idx]:  
                now_visited[tmp_idx] = True  
  visited_fig += 1  
  inj_deque.append(tmp_idx)  
    all_surround.append(visited_fig)  
    max_visited = max(max_visited, visited_fig)  
  
for i in range(N):  
    if all_surround[i] == max_visited:  
        print(i+1, end=' ')
```
각 컴퓨터에서 모든 컴퓨터와의 접근 가능성을 DFS나 BFS로 확인하면 되는 문제였다. 다만 인접행렬이 아니라 단방향 행렬이기 때문에 기존의 그래프 알고리즘을 쓸 수는 없었다.

### 의견
처음엔 인접행렬을 N*N으로 무식하게 만들어뒀는데, 생각해보니 전혀 그럴필요 없었다. 방식을 바꿔서 다시 풀이를 진행했다.

## 센서
https://www.acmicpc.net/problem/2212
### 문제풀이  
```python  
import sys  
N = int(sys.stdin.readline().rstrip())  
K = int(sys.stdin.readline().rstrip())  
sensor_position = sorted(list(map(int, sys.stdin.readline().rstrip().split())))  
diff_list = sorted([(sensor_position[x+1] - sensor_position[x]) for x in range(len(sensor_position)-1)])  
print(sum(diff_list[:N-K]))
```
한 개의 기지국을 설치한다고 보면, 센서의 맨 왼쪽에서 맨 오른쪽 안에 어느 곳에 기지국이 있어도 거리의 합으로는 모두 같은 값을 가진다. 따라서 기지국의 수 만큼 `센서의 집합`을 만들어낼 수 있으며, 센서끼리의 거리차이를 구한 뒤 가장 긴 차이를 무시할 수 있도록 집합을 구성하는 방식으로 풀이했다.

### 의견
어려울거라고 생각했는데 물골드 문제였나보다

## N과 M(12)
https://www.acmicpc.net/problem/15666
### 문제풀이  
```python  
import sys  
from itertools import combinations_with_replacement  
N, M = map(int, sys.stdin.readline().rstrip().split())  
fig_list = list(map(int, sys.stdin.readline().rstrip().split()))  
  
all_list = set()  
for case in combinations_with_replacement(fig_list, M):  
    sorted_case = list(case)  
    sorted_case.sort()  
    for case_idx in range(len(sorted_case)):  
        sorted_case[case_idx] = '{0:06d}'.format(sorted_case[case_idx])  
    tmp_case = str(sorted_case).replace("(","").replace(")","").replace(" ","")  
    if not tmp_case in all_list:  
        all_list.add(tmp_case)  
all_list = list(all_list)  
all_list.sort()  
for elem in all_list:  
    tmp_replaced = elem.replace("[","").replace("]","").replace("'","")  
    tmp_list = list(map(str, map(int, tmp_replaced.split(","))))  
    print(' '.join(tmp_list))
```
파이썬의 중복조합

### 의견
굳

## 투에-모스 문자열
https://www.acmicpc.net/problem/18222
### 문제풀이  
```python  
import sys  
k = int(sys.stdin.readline().rstrip()) -1  
minus_flag = False  
  
# 점화식  
# f(x*2) = f(x)  
# f(x*2 + 1) = !f(x)  
  
while k != 0:  
    if k%2 == 1:  
        k //= 2  
  minus_flag = not minus_flag  
    else:  
        k //= 2  
  
if minus_flag:  
    print(1)  
else:  
    print(0)
```
점화식을 확인하는게 제일 어려웠다.
