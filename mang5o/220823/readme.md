
# Solving﻿  

## 숨바꼭질
https://www.acmicpc.net/problem/1697
### 문제풀이  
```python  
import sys  
from collections import deque  
N,K = map(int, sys.stdin.readline().rstrip().split())  
max_idx = max(N,K)+1  
step_val = [-1 for _ in range(max_idx*2)]  
all_bfs_deque = deque()  
all_bfs_deque.append(N)  
step_val[N] = 0  
while len(all_bfs_deque) > 0:  
    tmp_elem = all_bfs_deque.popleft()  
    if tmp_elem-1 >= 0:  
        if step_val[tmp_elem-1] == -1:  
            step_val[tmp_elem - 1] = step_val[tmp_elem] + 1  
  all_bfs_deque.append(tmp_elem - 1)  
    if tmp_elem+1 <= K*2:  
        if step_val[tmp_elem+1] == -1:  
            step_val[tmp_elem + 1] = step_val[tmp_elem] + 1  
  all_bfs_deque.append(tmp_elem + 1)  
    if 0<=tmp_elem*2<=K*2:  
        if step_val[tmp_elem*2] == -1:  
            step_val[tmp_elem*2] = step_val[tmp_elem] + 1  
  all_bfs_deque.append(tmp_elem*2)  
print(step_val[K])
```
BFS를 활용한 거리구하기 문제이다. 항상 풀었던 2차원 맵이 아니라 1차원의 맵이라는 것이 다르지만, 전체적인 원리는 같았다.

### 의견 
위에서 언급한 듯이 같은 방식인데 형태가 달라서 갈피를 잘 못잡을 수 있다고 생각한다. 생각보다 오답이 한두개씩 나와서 이해를 못했는데, 2배로 이동할 때에 무조건 K 보다 작을 때에만 queue에 넣었기 때문이었다. K보다 크게 이동한 뒤 왼쪽으로 이동한다는 생각을 못 해서 시간을 많이 썼던 문제였다.


## 줄어들지 않아
https://www.acmicpc.net/problem/2688
### 문제풀이  
```python  
import sys  
from itertools import combinations_with_replacement  
T = int(sys.stdin.readline().rstrip())  
queries = []  
for i in range(T):  
    queries.append(int(sys.stdin.readline().rstrip()))  
  
# 중복된 input이 들어올 경우 다시 계산하지 않고 이를 사용  
unique_dict = dict()  
# 계산에 사용할 팩토리얼을 미리 선언 (factorials[n] =>> n!)factorials = [1]  
for i in range(max(queries)+10):  
    factorials.append(factorials[i]*(i+1))  
  
  
# n자리수에서 "증가"가 가능한 위치는 총 n+1개 (맨 앞자리 왼쪽과 맨 뒷자리 오른쪽을 포함)  
# "증가"의 개수는 0부터 9까지의 수로 9개이다  
# 따라서 n+1의 위치에 9개의 "증가"가 들어갈 수 있는 중복조합의 개수 (n+1)H9 = (n+9)C9for i in range(T):  
    if i in unique_dict:  
        print(unique_dict[i])  
    else:  
        tmp_query = queries[i]  
        all_fig_count = factorials[tmp_query+9] // (factorials[9] * factorials[tmp_query])  
        unique_dict[i] = all_fig_count  
        print(all_fig_count)
```
중복조합을 이용하여 풀어보았다. 카테고리가 DP여서 이 방법은 사실 일반적인 방법이 아닐 것 같은데, 숫자가 들어갈 공간 사이사이에 `숫자를 올리는 것`을 몇 번씩 할지 경우의 수를 구하였다.

### 의견  
사실 이 문제를 DP로 풀기가 나는 더 힘들 것 같았다. 속도를 줄이기 위해 factorial는 미리 저장해놓는 등의 방법을 사용했다.


## 쇠막대기
https://www.acmicpc.net/problem/10799
### 문제풀이  
```python  
import sys  
all_str = sys.stdin.readline().rstrip()  
all_str = all_str.replace("()","R") # 레이져  
now_depth = 0 # 현재의 깊이  
now_all_fig = 0 # 모든 쇠조각의 개수  
for i in range(len(all_str)):  
    if all_str[i] == "(":  
        now_depth += 1  
  elif all_str[i] == ")":  
        now_all_fig += 1  
  now_depth -= 1  
  else:  
        now_all_fig += now_depth  
print(now_all_fig)
```
스택은 사용하지 않고 `(를 만날때 깊이 +1`, `)를 만날때 깊이 -1` 계산을 반복하며 레이져를 쏠 때 깊이만큼 값을 더해주었다. 다만 쇠막대가 끝나는 시점에 한 조각이 더 생기니 +1의 값을 해주었다.

### 의견  
처음엔 `(를 만난 직후의 )`를 구하려고 이전 인덱스를 참조해볼까 했지만 `()`를 한번에 다른 문자로 바꾸어 풀었다.

## 체스판
https://www.acmicpc.net/problem/16957
### 문제풀이  
```python  
import sys  
  
dir_matrix = [[-1, -1], [-1, 0], [-1, 1], [0, -1], [0, 0], [0, 1], [1, -1], [1, 0], [1, 1]]  
R, C = map(int, sys.stdin.readline().split())  
map_matrix = []  
for i in range(R):  
    map_matrix.append(list(map(int, sys.stdin.readline().split())))  
now_ball = [[1 for x in range(C)] for y in range(R)]  
end_point = [[[-1, -1] for x in range(C)] for y in range(R)]  
for y in range(R):  
    for x in range(C):  
        if now_ball[y][x] > 0:  
            now_cursor = [y, x]  
            all_route = [[y,x]]  
            now_ball_fig = now_ball[y][x]  
            while True:  
                if end_point[now_cursor[0]][now_cursor[1]][0] != -1:  
                    tmp_end_point = end_point[now_cursor[0]][now_cursor[1]]  
                    if tmp_end_point[0] == now_cursor[0] and tmp_end_point[1] == now_cursor[1]:  
                        break  
 else:  
                        now_ball[tmp_end_point[0]][tmp_end_point[1]] += now_ball[now_cursor[0]][now_cursor[1]]  
                        now_ball[now_cursor[0]][now_cursor[1]] = 0  
  break  
  min_dir = 0  
  min_fig = 300001  
  tmp_yy = 0  
  tmp_xx = 0  
  for dir_idx in range(9):  
                    tmp_yy = now_cursor[0] + dir_matrix[dir_idx][0]  
                    tmp_xx = now_cursor[1] + dir_matrix[dir_idx][1]  
                    if 0 <= tmp_yy < R and 0 <= tmp_xx < C:  
                        if map_matrix[tmp_yy][tmp_xx] < min_fig:  
                            min_fig = map_matrix[tmp_yy][tmp_xx]  
                            min_dir = dir_idx  
                if min_dir == 4:  
                    while len(all_route)>0:  
                        tmp_route = all_route.pop()  
                        end_point[tmp_route[0]][tmp_route[1]] = now_cursor  
                    break  
 else:  
                    tmp_yy = now_cursor[0] + dir_matrix[min_dir][0]  
                    tmp_xx = now_cursor[1] + dir_matrix[min_dir][1]  
                    now_ball[tmp_yy][tmp_xx] += now_ball[now_cursor[0]][now_cursor[1]]  
                    now_ball[now_cursor[0]][now_cursor[1]] = 0  
  now_cursor = [tmp_yy, tmp_xx]  
                    all_route.append([tmp_yy, tmp_xx])  
  
for i in range(R):  
    print(" ".join(map(str, now_ball[i])))
```
공이 지나가며 이동한 칸의 공을 가지고 함께 이동한다. [y,x]에 멈추게 된다면 공이 지나온 길을 하나하나 확인하며 `그 위치의 도착점은 [y,x]이다` 라는 의미로 `end_point`를 지정해주었으며, 다른 위치에서 공이 지나가다가 `end_point`가 지정된 칸을 가면 바로 도착점으로 이동하도록 구현했다.

### 의견  
이 방법보다 더 빠른 방법이 떠오르질 않는데, 70%에서 시간초과가 난다. 무한루프는 돌지 않을 것 같고 뭔가 더 시간을 단축하는 방법이 있는 것 같은데, 모임 때 확인하고 싶다.


## 표 편집
https://school.programmers.co.kr/learn/courses/30/lessons/81303
### 문제풀이  
```python  
def solution(n, k, cmd):  
    """  
  :param n: 처음 표의 행 개수를 나타내는 정수  
  :param k: 처음에 선택된 행의 위치를 나타내는 정수  
  :param cmd: 수행한 명령어들이 담긴 문자열 배열  
  :return: 행에 대한 계산 결과  
 """  table_to_cal = ["O" for x in range(n)]  
    first_cursor = k  
    deleted_stack = []  
    linked_idx = [[x-1, x+1] for x in range(n)]  
    for i in range(len(cmd)):  
        now_cmd = cmd[i]  
        if now_cmd[0] == "U":  
            for iter_fig in range(int(now_cmd.split()[1])):  
                first_cursor = linked_idx[first_cursor][0]  
        elif now_cmd[0] == "D":  
            for iter_fig in range(int(now_cmd.split()[1])):  
                first_cursor = linked_idx[first_cursor][1]  
        elif now_cmd[0] == "C":  
            table_to_cal[first_cursor] = "X"  
  if linked_idx[first_cursor][0]>=0:  
                linked_idx[linked_idx[first_cursor][0]][1] = linked_idx[first_cursor][1]  
            if linked_idx[first_cursor][1]<n:  
                linked_idx[linked_idx[first_cursor][1]][0] = linked_idx[first_cursor][0]  
            deleted_stack.append(first_cursor)  
            if linked_idx[first_cursor][1] >= n:  
                first_cursor = linked_idx[first_cursor][0]  
            else:  
                first_cursor = linked_idx[first_cursor][1]  
        else: # Z  
  fig = deleted_stack.pop()  
            table_to_cal[fig] = "O"  
  now_left = linked_idx[fig][0]  
            now_right = linked_idx[fig][1]  
  
            if now_left != -1:  
                linked_idx[now_left][1] = fig  
            if now_right != n:  
                linked_idx[now_right][0] = fig  
            linked_idx[fig] = [now_left, now_right]  
  
    answer = "".join(table_to_cal)  
    return answer
```

일반적인 리스트 풀이로 접근해도 작동에는 무리가 없었지만 효율성 부분에서 뒤 6~10번이 시간초과가 나는 상황이어서 어떻게 해야 더 빨리 진행할 수 있을지 고민하였고, `linked_idx`라는 값으로 현재 위치의 위쪽과 아래쪽의 값을 가지는 행렬을 구현하였다.
이동할 경우엔 해당 방향으로 n번 이동하는데, 이동할 위치는 linked_idx를 통해 한 번에 파악한다. 지우고 다시 살리는 것은 stack을 통해 구현하였다.
결과적으로 double linked list의 구조를 띄고있다.

### 의견  
사실 가장 신경쓰였던 부분은 Z였다. 지웠던걸 다시 살리는 상황인데, 여기에서 문제는 `다시 살린 인덱스의 위와 아래 인덱스를 어떻게 파악하느냐`였다. 처음엔 n번째 인덱스를 살렸다고 하면 1칸씩 위로 올라가며 이전 인덱스를 찾고, 1칸씩 아래로 내려가며 다음 인덱스를 찾았고 이것으로 위 아래 인덱스의 각각 아래 위 위치를 자신으로 두도록 하였는데 이 방식이 효율성 한 문제에서 시간초과가 계속 걸렸다.
아무리 생각해도 해답이 안 보였었는데, 지우고 살리는 것이 Stack을 통해서 FILO 구조를 가지고 있기 때문에 양쪽의 인덱스를 다시 찾는 작업을 하지 않아도 된다는 것을 깨달았다.
깔끔하고 좋은 문제라고 생각한다.


