
# Solving﻿  

## 괄호의 값
https://www.acmicpc.net/problem/2504
### 문제풀이  
```python  
import sys  
  
inp = sys.stdin.readline().rstrip()  
# Validation  
test_stack = []  
val_flag = True  
for i in range(len(inp)):  
    if inp[i] == "(":  
        test_stack.append(0)  
    elif inp[i] == ")":  
        if len(test_stack) == 0:  
            val_flag = False  
 break if test_stack[-1] == 0:  
            test_stack.pop()  
        else:  
            val_flag = False  
 break elif inp[i] == "[":  
        test_stack.append(2)  
    else:  
        if len(test_stack) == 0:  
            val_flag = False  
 break if test_stack[-1] == 2:  
            test_stack.pop()  
        else:  
            val_flag = False  
 break  
# Calculation  
if val_flag:  
    inp = inp.replace("()", "+2").replace("[]", "+3").replace("(", "+2*(").replace("[", "+3*(").replace("]", ")")  
    try:  
        now_val = eval(inp)  
        print(int(now_val))  
    except:  
        print(0)  
else:  
    print(0)
```  
많은 사람들이 비추천하는 `eval()`을 사용한 풀이이다.  사실 `항상 제대로 된 input만 들어온다`라고 할 경우 #calculation 부분만 있으면 될 정도로 간단하게 계산되지만, 몇 가지의 괄호 패턴으로 인해 유효성 검사가 필요하여 코드가 길어졌다.
괄호가 들어온 순서대로 스택에 넣고, 닫는 괄호가 들어올 때엔 스택의 최상단을 확인한 뒤 맞는 괄호라면 넘어가는 방식이다.

### 의견  
일반적으로 코드에서의 수식 진행이나, 여러 메모리 상의 프로세스도 stack을 사용하여 이같은 원리로 진행이 되는 것으로 알고 있다.
사실 eval()을 비추천하는 블로그 포스트 등이 존재하는데, 여기서 제시하는 이유 중 하나는 `비정상적인 input에 대한 처리`가 큰 이유이다. 어차피 본인의 논리에 빈틈이 있다면 문제풀이가 실패할 것이고, 그게 코딩테스트에서의 큰 결함이 된다고 생각하진 않는다. 추가적인 메모리를 많이 할당하는 작업도 아니기 때문에 문제풀이 차원에서는 크게 문제가 되진 않는다 생각한다.
오히려 위와같은 문제에서 괄호가 항상 옳은 방식으로 들어오는 문제라면 10줄도 안되는 내용으로 값을 도출할 수 있으며, 코드를 보는 입장에서 흥미롭다고 느낄 만 하다고 생각한다. 


## 퇴사2
https://www.acmicpc.net/problem/15486
### 문제풀이  
```python  
import sys  
N = int(sys.stdin.readline().rstrip())  
all_list = []  
for i in range(N):  
    tmp_elem = list(map(int, sys.stdin.readline().rstrip().split()))  
    tmp_elem.append(0)  
    all_list.append(tmp_elem)  
all_list.append([0,0,0])  
  
max_value = 0 # 최대 이익  
  
for i in range(N):  
    now_cost = all_list[i][2]  
    max_cost = now_cost + all_list[i][1]  
    for j in range(all_list[i][0]):  
        if i + j <= N:  
            all_list[i+j][2] = max(now_cost, all_list[i+j][2])  
            max_value = max(max_value,all_list[i+j][2])  
    if all_list[i][0] + i <= N:  
        all_list[all_list[i][0] + i][2] = max(all_list[all_list[i][0] + i][2], max_cost)  
        max_value = max(max_value,all_list[all_list[i][0] + i][2])  
  
print(max_value)
```  
일반적인 DP문제로 작업하였는데, 특정 시간에 가장 많은 이익을 매 행렬 위치에 집어넣는 식의 문제풀이이다. 다만 최대한 시간을 줄이기 위해 아래와 같은 코드 구현을 진행하였다.

```
1. N day에 M의 일자를 소모하는 상담에서 N+M까지의 time을 계산한다.
2. 이런 식으로의 프로세싱은 N+M의 최대값이 마지막 인덱스가 아닐경우, 모든 인덱스를 돌며 최대값을 파악해야 한다.
3. 따라서 매 계산에 max_value값의 갱신을 진행하여 마지막엔 해당 값을 바로 가져오도록 유도하였다.
```

### 의견  
사실 처음엔 `N day에 M의 일자를 소모하는 상담`일 경우 N+M부터 마지막날까지 모두 비용을 더하고, 그 다음날부터 또 이를 반복하여 각 날의 비용 최대값을 계산하려고 했으나, 인덱스 접근이나 작업이 너무 수가 늘어난다고 생각되어 이와같이 구현하였다.


## 테트로미노
https://www.acmicpc.net/problem/14500
### 문제풀이  
```python  
import sys  
  
all_fig = [  
    # 4스텝동안 4방향으로 BFS등으로 처리하려 했으나 마지막 도형의 구조상 general하게 구현하기 지저분함  
  [[True, True, True, True]],  
  [[True], [True], [True], [True]],  
  [[True, True], [True, True]],  
  [[True, True, True], [True, False, False]],  
  [[True, True, True], [False, False, True]],  
  [[True, False, False], [True, True, True]],  
  [[False, False, True], [True, True, True]],  
  [[True, True], [True, False], [True, False]],  
  [[True, True], [False, True], [False, True]],  
  [[True, False], [True, False], [True, True]],  
  [[False, True], [False, True], [True, True]],  
  [[True, True, False], [False, True, True]],  
  [[False, True, True], [True, True, False]],  
  [[True, False], [True, True], [False, True]],  
  [[False, True], [True, True], [True, False]],  
  [[True, True, True], [False, True, False]],  
  [[False, True, False], [True, True, True]],  
  [[True, False], [True, True], [True, False]],  
  [[False, True], [True, True], [False, True]]  
]  
  
N, M = map(int, sys.stdin.readline().rstrip().split())  
all_map_list = []  
for i in range(N):  
    tmp_elem = list(map(int, sys.stdin.readline().rstrip().split()))  
    tmp_elem.append(-99999)  
    tmp_elem.append(-99999)  
    tmp_elem.append(-99999)  
    all_map_list.append(tmp_elem)  
for i in range(3):  
    all_map_list.append([-99999 for _ in range(M + 3)])  
  
max_val = 0  
for y in range(N):  
    for x in range(M):  
        for fig in all_fig:  
            tmp_val = 0  
  for fig_y in range(len(fig)):  
                for fig_x in range(len(fig[0])):  
                    if fig[fig_y][fig_x]:  
                        tmp_val += all_map_list[y + fig_y][x + fig_x]  
            max_val = max(max_val, tmp_val)  
  
print(max_val)
```  
사실 테트로미노 도형을 BFS나 DFS를 가지고 만들어내고 싶었으나, ㅏ 모양의 도형이 문제였다. 다른 모든 도형은 한 칸씩 정사각형이 이동하며 도형을 만들어낼 수 있는데, 이 도형은 지나가며 도형을 구현할 수 없기 때문이다. 이 때문에 별개의 조건을 구현해야했는데 이러면 코드 풀이의 일관성이 내려가 보기 어려울 것 같아 위처럼 빡센 구현을 통해 문제를 풀었다.

### 의견  
BFS나 DFS 등으로 도형을 구현하는 방식은 위 방식보다는 비효율적이라고 볼 수는 있다. 매 좌표에서 visited 함수를 만들어야 하고, 이를 queue나 stack에 넣어야 하며, 4방향으로 모두 체크를 진행하기 때문이다. 하지만 문제풀이에서 효율적인 방식이 실제 코딩에서 효율적이라고는 생각하지 않는다. 코딩환경에 대한 효율성과 실행환경에 대한 효율성의 협의점을 찾는 것이 중요하기 때문이다.


## Puyo Puyo
https://www.acmicpc.net/problem/11559
### 문제풀이  
```python  
import sys  
from collections import deque  
  
dir_matrix = ((0, 1), (0, -1), (1, 0), (-1, 0))  
all_map = []  
for i in range(12):  
    tmp_inp = sys.stdin.readline().rstrip()  
    tmp_arr = []  
    for j in range(6):  
        if tmp_inp[j] == ".":  
            tmp_arr.append(0)  
        elif tmp_inp[j] == "R":  
            tmp_arr.append(1)  
        elif tmp_inp[j] == "G":  
            tmp_arr.append(2)  
        elif tmp_inp[j] == "B":  
            tmp_arr.append(3)  
        elif tmp_inp[j] == "P":  
            tmp_arr.append(4)  
        else:  
            tmp_arr.append(5)  
    all_map.append(tmp_arr)  
  
all_chain = 0  
visited_gc = []  
while True:  
    now_chain = False  
 for y in range(12):  
        for x in range(6):  
            if all_map[y][x] != 0:  
                visited_gc = [[False for xx in range(6)] for yy in range(12)]  
                visited_gc[y][x] = True  
  bfs_deque = deque()  
                bfs_deque.append([y,x])  
                now_block = 1  
  now_color = all_map[y][x]  
                while len(bfs_deque) > 0:  
                    tmp_elem = bfs_deque.popleft()  
                    for dir_idx in range(4):  
                        tmp_yy = tmp_elem[0] + dir_matrix[dir_idx][0]  
                        tmp_xx = tmp_elem[1] + dir_matrix[dir_idx][1]  
                        if 0<=tmp_yy<12 and 0<=tmp_xx<6:  
                            if visited_gc[tmp_yy][tmp_xx] == False and all_map[tmp_yy][tmp_xx] == now_color:  
                                visited_gc[tmp_yy][tmp_xx] = True  
  now_block += 1  
  bfs_deque.append([tmp_yy,tmp_xx])  
                if now_block >= 4:  
                    for yyy in range(12):  
                        for xxx in range(6):  
                            if visited_gc[yyy][xxx]:  
                                all_map[yyy][xxx] = 0  
  now_chain = True  
  
  
 if not now_chain:  
        break  
 else: # Gravity  
  all_chain += 1  
  for y_elem in range(12):  
            for x in range(6):  
                y = 11-y_elem  
                if all_map[y][x] == 0:  
                    for yy_elem in range(y):  
                        now_yy = y-yy_elem-1  
  if all_map[now_yy][x] != 0:  
                            all_map[y][x] = all_map[now_yy][x]  
                            all_map[now_yy][x] = 0  
  break  
print(all_chain)
```  
BFS를 통한 block을 만드는 코드와, 중력을 통한 블럭 이동이 반복되는 코드이다.

### 의견  
Gravity에서 y값이 높은 부분부터 확인해야 하므로 `y_elem`이나 `yy_elem`등을 사용하는 부분이 있는데, 이럴 때에 index의 시작점과 끝점 등이 명확하지 않으면 자주 실수를 하는데, 나도 이 실수 때문에 가장 윗 라인의 블록이 떨어지지 않는 현상이 일어났다. 집중이 필요하다.


## 베르트랑 공준
https://www.acmicpc.net/problem/4948
### 문제풀이  
```python  
import sys  
  
all_mat = []  
while True:  
    tmp_inp = int(sys.stdin.readline().rstrip().rstrip())  
    if tmp_inp == 0:  
        break  
  all_mat.append(tmp_inp)  
  
max_fig = max(all_mat) * 2  
fig_mat = [True for _ in range(max_fig+1)]  
fig_mat[0] = False  
fig_mat[1] = False # 1은 소수가 아니다  
for i in range(max_fig+1):  
    if fig_mat[i]:  
        start_cursor = i*2  
  interval_cursor = i  
        while True:  
            if start_cursor <= max_fig:  
                fig_mat[start_cursor] = False  
  start_cursor += interval_cursor  
            else:  
                break  
  
acc_mat = []  
acc_start = 0  
for i in range(max_fig+1):  
    acc_start += fig_mat[i]  
    acc_mat.append(acc_start)  
  
  
for query in all_mat:  
    print(acc_mat[query*2] - acc_mat[query])
```  
에라스토테네스의 체 원리를 사용한 문제이다. 처음 입력을 받은 뒤 해당 입력 중 가장 큰 숫자에 대해 행렬을 만들고 각 행렬의 원소는 해당 인덱스의 숫자가 소수인지 아닌지를 저장하는 값이다.

### 의견  
여러 input이 들어가지 않고 하나의 수가 소수인지 파악하는 등의 문제라면 굳이 이렇게 풀이를 할 필요가 없으나, 이런 문제의 특징은 질문이 여러개 들어오고 이에 계산했던 값을 다시 사용할 수 있는 구조를 가지고 있다는 것이다.


