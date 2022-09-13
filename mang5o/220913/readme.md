
# Solving﻿  

## 최소 스패닝 트리
https://www.acmicpc.net/problem/1197
### 문제풀이  
```python  
import sys  
  
# PRIM  
V, E = map(int, sys.stdin.readline().rstrip().split())  
all_edge = []  
for _ in range(E):  
    now_edge = list(map(int, sys.stdin.readline().rstrip().split()))  
    if now_edge[0] > now_edge[1]:  # 문제엔 경우가 나오지 않았지만 두 정점이 오름차순이 아닐 수 있어서  
  
  all_edge.append([now_edge[1]-1, now_edge[0]-1, now_edge[2], False])  
    else:  
        all_edge.append([now_edge[0]-1, now_edge[1]-1, now_edge[2], False])  
all_edge.sort(key=lambda x: x[2])  
now_active_vertex = [False for _ in range(V)]  
now_active_vertex[0] = True  
now_active_vertex_fig = 1  
now_edge_len = 0  
while now_active_vertex_fig < V:  
    for edge in all_edge:  
        if edge[3]:  
            continue  
 if not (now_active_vertex[edge[0]] and now_active_vertex[edge[1]]) \  
                and not(not now_active_vertex[edge[0]] and not now_active_vertex[edge[1]]):  
            now_active_vertex[edge[0]] = True  
  now_active_vertex[edge[1]] = True  
  edge[3] = True  
  now_active_vertex_fig += 1  
  now_edge_len += edge[2]  
            break  
 if now_active_vertex[edge[0]] and now_active_vertex[edge[1]]:  
            edge[3] = True  
  
print(now_edge_len)
```
PRIM 알고리즘을 통한 최소 스패닝 트리를 구하는 방법이다. 한 점을 랜덤으로 찍고, 이를 `현재 포함한 정점의 집합`에 넣는다. 현재 포함한 정점들에 이어진 간선들 중 가장 짧은 선을 항상 포함하는데, 이 때 이 간선은 `한 점은 이미 연결되어있고 한 점은 연결되어 있지 않는다`는 조건을 만족할 때만 이를 통해 또 다른 정점을 추가한다.

### 의견 
Edge의 목록을 우선순위큐에 넣고 최소값을 계속 뽑아낼까 생각했지만, 정점에 비해 간선이 꽤 있는 것 같아 보여서 우선순위큐에서 빼고 이 간선이 조건에 부합하는지 확인하는 작업이 많이 반복될 것 같아 이를 사용하지 않았다. 어차피 최소 거리의 간선부터 고려하므로 맨 처음 입력을 받을 때 sorting한 뒤에 이를 계속 이용하였다.

## 골드바흐의 추측
https://www.acmicpc.net/problem/9020
### 문제풀이  
```python  
import sys  
  
T = int(sys.stdin.readline().rstrip())  
all_query = []  
for _ in range(T):  
    all_query.append(int(sys.stdin.readline().rstrip()))  
all_result = []  
  
max_n = max(all_query)  
all_fig = [True for _ in range(max_n + 1)]  
all_fig[0] = False  
all_fig[1] = False  
for i in range(max_n + 1):  
    if not all_fig[i]:  
        continue  
  interval = i  
    now_start = i  
    while True:  
        now_start += interval  
        if now_start <= max_n:  
            all_fig[now_start] = False  
 else:  
            break  
  
for query in all_query:  
    now_insert = [0,0]  
    min_ptr = 2  
  max_ptr = query-2  
  while min_ptr <= max_ptr:  
        if all_fig[min_ptr] and all_fig[max_ptr]:  
            now_insert = [min_ptr, max_ptr]  
        min_ptr += 1  
  max_ptr -= 1  
  all_result.append(now_insert)  
  
for result in all_result:  
    print("{} {}".format(result[0], result[1]))
```
에라스토테네스의 체를 사용해 소수 여부에 대한 계산을 미리 진행한 뒤 풀이하였다. 두 개의 숫자를 가리키는 포인터를 만들고, 각 포인터를 점점 한 칸씩 접근시키며 두 포인터의 수가 소수인지 확인하는 일을 반복하였다.


## 구간 합 구하기 5
https://www.acmicpc.net/problem/11660
### 문제풀이  
```python  
import sys  
  
N, M = map(int, sys.stdin.readline().rstrip().split())  
all_map = []  
for _ in range(N):  
    all_map.append(list(map(int, sys.stdin.readline().rstrip().split())))  
  
all_query = []  
for _ in range(M):  
    all_query.append(list(map(int, sys.stdin.readline().rstrip().split())))  
  
all_accum = [[0 for _ in range(N+1)]]  
for y in range(N):  
    now_line = [0]  
    for x in range(N):  
        now_line.append(now_line[-1] + all_accum[-1][x+1] + all_map[y][x] - all_accum[-1][x])  
    all_accum.append(now_line)  
  
for query in all_query:  
    now_answer = all_accum[query[2]][query[3]] - all_accum[query[2]][query[1]-1] - all_accum[query[0]-1][query[3]] + all_accum[query[0]-1][query[1]-1]  
    print(now_answer)
```
누적합을 넣은 `all_accum`이라는 행렬을 만들고 이를 사용했다. 누적합을 구할 때에 `(y-1, x-1)`의 값을 사용하므로 왼쪽과 위의 공간에 0으로 채워 계산하기 용이하도록 수정하였다.

### 의견 
누적합에 대한 기본적인 문제였던 것 같다.

## 스킬트리
https://school.programmers.co.kr/learn/courses/30/lessons/49993
### 문제풀이  
```python  
  
def solution(skill, skill_trees):  
    skill = list(skill)  
    skill_dict = dict()  
  
    for i in range(len(skill)):  
        skill_dict[skill[i]] = i  
  
    answer = 0  
  for tree in skill_trees:  
        now_flag = [False for _ in range(len(skill))] # 현재의 스킬 상태  
  now_flag[0] = True # 첫 번째 스킬은 바로 배울 수 있음  
  now_tree_list = list(tree)  
        for tree_skill in now_tree_list:  
            if not tree_skill in skill_dict:  
                continue  
 if not now_flag[skill_dict[tree_skill]]:  
                now_flag = False  
 break  # 스킬을 배울 수 있을 때  
  if skill_dict[tree_skill] < len(skill) - 1:  
                now_flag[skill_dict[tree_skill] + 1] = True  
 if now_flag:  
            answer += 1  
  
  return answer
```


### 의견 
처음엔 위상정렬을 통해 풀지 고민하였는데, 전체적인 경향성은 위상정렬에 맞긴 하지만 스킬의 순서가 선형적이기 때문에 현재 배울수 있는 스킬의 목록을 들고 비교하며 문제를 풀도록 했다.

## 최소 직사각형
https://school.programmers.co.kr/learn/courses/30/lessons/86491
### 문제풀이  
```python  
def solution(sizes):  
    min_list = [0,0]  
    for size in sizes:  
        min_list = [max(max(size), min_list[0]), max(min(size), min_list[1])]  
    return min_list[0]*min_list[1]
```
각 직사각형을 가로로 길게 둔다고 생각하고 이 모든 직사각형을 커버할 수 있는 최소 크기의 직사각형을 구하는 문제이다.

### 의견 
뭔가 어딘가에서 본 것 같은 문제다.

