# Solving
##  N-Queen
https://www.acmicpc.net/problem/9663
### 문제풀이
```python
N = int(sys.stdin.readline().rstrip())  
# 모든 퀸은 위에서부터 각 행에 하나씩 존재함  
backtracking_deque = deque()  
backtracking_deque.append([])  
all_case = 0  
while len(backtracking_deque)>0:  
    now_elem = backtracking_deque.pop() # Queue가 아닌 Stack을 사용하여 메모리 초과 해결  
  now_y = len(now_elem)  
    if now_y==N:  
        all_case += 1  
  else:  
        for now_x in range(N):  
            now_can_flag = True  
 for previous_y in range(now_y):  
                # now y,x = now_y, now_x  
 # previous y,x = previous_y, now_elem[previous_y]  check_float = (now_elem[previous_y]-now_x)/(previous_y-now_y)  
                if check_float==-1 or check_float==0 or check_float==1:  
                    now_can_flag = False  
 break if now_can_flag:  
                new_elem = [now_elem[i] for i in range(len(now_elem))]  
                new_elem.append(now_x)  
                backtracking_deque.append(new_elem)  
  
print(all_case)
```
퀸은 한 행에 1개씩만 존재해야 하므로 맨 윗 행부터 아래로 나려가며 퀸이 존재하는 열을 가진 array를 가지고 계산을 하는 과정이다. 
메모리 관리를 위해 `Queue를 사용한 BFS` 보다 `Stack을 사용한 DFS`로 풀이를 진행했으며, 다음에 올 퀸에 대해서 `대각선, 같은 열의 퀸`을 비교해야 하므로 (같은 행에는 퀸이 있을 수 없다.) 이전의 모든 퀸과 아래의 검증 작업을 진행한다.
```python
for previous_y in range(now_y):  
    # now y,x = now_y, now_x  
 # previous y,x = previous_y, now_elem[previous_y]  check_float = (now_elem[previous_y]-now_x)/(previous_y-now_y)  
    if check_float==-1 or check_float==0 or check_float==1:  
        now_can_flag = False  
 break
```
현재 `y,x`와 다른 퀸의 `y,x`를 가지고 서로 기울기가 -1이나 1일 경우 대각선에, 0일 경우 같은 열에 있다는 것을 알 수 있다.

### 의견
처음엔 완전탐색을 사용해 풀어야하나 생각해서 N길이에 대한 combination을 진행하려고 하였으나, 시간초과가 나는 것을 보고 경우의 수를 줄여야 겠다는 생각을 했다. 이 문제에선 이전의 퀸 위치를 모두 생각하며 놓을 수 있는 위치에만 퀸을 넣어 DFS를 진행하였는데, 찾아보니 `가능한 경우만을 가지치기 하며 모두 검증해보는 작업`을 `비트마스킹`이라고 하는 것 같다.

##  종이조각
https://www.acmicpc.net/problem/14391
### 문제풀이
```python
N, M = map(int, sys.stdin.readline().rstrip().split())  
map_matrix = []  
for i in range(N):  
    now_line = sys.stdin.readline().rstrip()  
    now_line_arr = []  
    for j in now_line:  
        now_line_arr.append(int(j))  
    map_matrix.append(now_line_arr)  
now_search_deque = deque()  
now_search_deque.append([map_matrix,0])  
max_cost = 0  
while len(now_search_deque)>0:  
    tmp_search_elem = now_search_deque.pop()  
    tmp_map = tmp_search_elem[0]  
    tmp_cost = tmp_search_elem[1]  
    all_flag = True  
  min_y = -1  
  min_x = -1  
  for y in range(N):  
        for x in range(M):  
            if tmp_map[y][x] > 0:  
                all_flag = False  
 if min_y == -1 or min_y >= y:  # 시간절약부분  
  min_y = y  
                    # 아래로 쭉  
  now_tmp_map = [[tmp_map[i][j] for j in range(M)] for i in range(N)]  
                    now_str = ""  
  tmp_y = y  
                    tmp_x = x  
                    while tmp_y < N and now_tmp_map[tmp_y][tmp_x] >= 0:  
                        now_str += str(now_tmp_map[tmp_y][tmp_x])  
                        now_tmp_map[tmp_y][tmp_x] = -1  
  tmp_y += 1  
  now_search_deque.append([now_tmp_map, tmp_cost + int(now_str)])  
                if min_x == -1 or min_x >= x:  # 시간절약부분  
  min_x = x  
                    # start : {y,x}  
 # 오른쪽으로 쭉  
  now_tmp_map = [[tmp_map[i][j] for j in range(M)] for i in range(N)]  
                    now_str = ""  
  tmp_y = y  
                    tmp_x = x  
                    while tmp_x < M and now_tmp_map[tmp_y][tmp_x] >= 0:  
                        now_str += str(now_tmp_map[tmp_y][tmp_x])  
                        now_tmp_map[tmp_y][tmp_x] = -1  
  tmp_x += 1  
  now_search_deque.append([now_tmp_map, tmp_cost + int(now_str)])  
    if all_flag:  
        max_cost = max(max_cost, tmp_cost)  
print(max_cost)
```
이 문제에서 세로로 자르거나 가로로 자르는 등의 작업의 모든 경우의 수를 구하면 당연히 타임아웃이 일어난다. 따라서 각 계산에 대한 경우는 `가로나 세로로 자를 때에 가장 길게 자른다` 라는 조건을 두고 진행했다. 실제로는 꼭 가장 길게 자를 필요는 없지만, 어떤 경우에서든지 가장 큰 값을 만들어야하기 때문에 가장 길게 자르는 부분은 무조건 존재하고, 이렇게 되면 무조건 최고 점수가 포함되기 때문이다.

### 의견
N-Queen과 마찬가지로 경우에 대해 가지치기를 진행한다고 생각했으나, 깊이 들어가보면 약간 다른 것 같다는 생각을 했다. N-Queen의 경우 모든 경우에 대해 `그 케이스가 가능하다면 stack에 넣는다`는 느낌이라면, 종이조각 문제는 맨 처음에 `답이 될 수 있는 경우의 조건`을 생각하고 이 조건을 만족하는 모든 경우를 비교한다는 느낌이었다.


##  마법사 상어와 블리자드
https://www.acmicpc.net/problem/21611
### 문제풀이
```python
import sys  
from collections import deque  
  
# 굳이 N*N 행렬로 문제를 풀 이유가 없다  
dir_matrix = ((0, -1), (1, 0), (0, 1), (-1, 0))  
N, M = map(int, sys.stdin.readline().rstrip().split())  
tmp_map_matrix = []  
for i in range(N):  
    tmp_map_matrix.append(list(map(int, sys.stdin.readline().rstrip().split())))  
blizzard_matrix = []  
for i in range(M):  
    blizzard_matrix.append(list(map(int, sys.stdin.readline().rstrip().split())))  
  
all_map = ""  
tmp_y = N // 2  
tmp_x = N // 2  
now_dir = 0  
now_second = False  
now_step = 1  
end_flag = False  
while not end_flag: # 맵을 일자로 바꿔줌  
  for steps in range(now_step):  
        tmp_y += dir_matrix[now_dir][0]  
        tmp_x += dir_matrix[now_dir][1]  
        all_map += str(tmp_map_matrix[tmp_y][tmp_x])  
        if tmp_x == 0 and tmp_y == 0:  
            end_flag = True  
 break  now_dir = (now_dir + 1) % 4  
  if now_second:  
        now_step += 1  
  now_second = not now_second  
  
# 파이어볼  
# 위쪽방향이라면 인덱스 6,21,44,75 diff 15,23,31 (8씩 증가)...  
# 아래방향이라면 인덱스 2,13,32,.. diff 11,19,   (8씩 증가)...  
# 왼쪽방향이라면 인덱스 0,9,26,51  diff 9,17,25  (8씩 증가)...  
# 오른방향이라면 인덱스 4,17,38... diff 13,21,   (8씩 증가)...  
blizzard_dir_matrix = ((), (6,15),(2,11),(0,9),(4,13)) # 첫 인덱스, diff시작  
  
# 터뜨린 양 저장  
exploded = [-1,0,0,0]  
for blizzard in range(M):  
    # 볼 터뜨리기  
  tmp_idx = blizzard_matrix[blizzard][0]  
    tmp_step = blizzard_matrix[blizzard][1]  
    now_idx = blizzard_dir_matrix[tmp_idx][0]  
    now_diff = blizzard_dir_matrix[tmp_idx][1]  
    for i in range(tmp_step): # 처음 구슬 지우기  
  all_map = all_map[:now_idx] + "D" + all_map[now_idx + 1:]  
        now_idx += now_diff  
        now_diff += 8  
  if now_idx > N ** 2 - 2:  
            break  
  all_map = all_map.replace("D","")  
    # 볼 터뜨리기  
  while True:  
        all_map += "0"  
  now_flag = False  
  now_figure = "0"  
  now_cursor_start = 0  
  del_index_mat = deque()  
        for idx in range(len(all_map)):  
            if all_map[idx] == now_figure:  
                continue  
 else:  
                if idx  - now_cursor_start >= 4:  
                    del_index_mat.append((now_cursor_start, idx - 1, all_map[idx - 1]))  
                now_figure = all_map[idx]  
                now_cursor_start = idx  
        while len(del_index_mat) > 0:  
            tmp_del_idx = del_index_mat.pop()  
            now_flag = True  
  now_del_len = tmp_del_idx[1] - tmp_del_idx[0] + 1  
  now_del_figure = int(tmp_del_idx[2])  
            exploded[now_del_figure] += now_del_len  
            all_map = all_map[:tmp_del_idx[0]] + all_map[tmp_del_idx[1] + 1:]  
        all_map = all_map[:len(all_map)-2]  
        if not now_flag:  
            break  
  # 볼 그룹화  
  all_map = all_map.replace("0","")  
    all_map = all_map.replace("12","1S2")  
    all_map = all_map.replace("13","1S3")  
    all_map = all_map.replace("21","2S1")  
    all_map = all_map.replace("23","2S3")  
    all_map = all_map.replace("31","3S1")  
    all_map = all_map.replace("32","3S2")  
    all_grouped = all_map.split("S")  
    # 그룹화한 볼 다시 일렬로  
  all_map = ""  
  for i in range(len(all_grouped)):  
        if len(all_grouped[i])>0:  
            all_map += str(len(all_grouped[i])) + all_grouped[i][0]  
    all_map += "0" * ((N**2-1) - len(all_map)) # 부족한 길이만큼 0 채우기  
  all_map = all_map[:N**2-1] # 넘은만큼 지우기  
  
del_output = exploded[1]*1 + exploded[2]*2 + exploded[3]*3  
print(del_output)
```
해당 문제를 N*N 행렬로 두고 포인터를 움직이며 문제를 풀기보단, 실제 N*N 행렬이란 점이 중요한 부분은 `한 줄로 구슬을 파괴할 때` 뿐만이었기 때문에, N*N행렬이 아닌 N**2 array로 만들어 진행하였다.
```python
# 볼 그룹화  
all_map = all_map.replace("0","")  
all_map = all_map.replace("12","1S2")  
all_map = all_map.replace("13","1S3")  
all_map = all_map.replace("21","2S1")  
all_map = all_map.replace("23","2S3")  
all_map = all_map.replace("31","3S1")  
all_map = all_map.replace("32","3S2")  
all_grouped = all_map.split("S")
```
이런 풀이법을 좋아하는데, 위의 코드의 경우 숫자가 바뀌는 것을 기점으로 split하는 방식이다. `"11122133"`이라는 string이 `["111", "22", "1", "33"]`으로 나눠지게 하는 코드인데, string에 등장하는 숫자가 많다면 포인터를 맨 앞에서부터 유지하며 비교할테지만 숫자가 적은 경우 빠르게 코드를 구현하는 데 이런 식의 방식도 편리하다고 생각한다.

### 의견
요즘 코딩테스트에서 보는 시뮬레이션(구현) 문제를 보면 실제 문제에서 제시된 형태로 문제를 풀기보다 아예 다르게 접근하면 쉽게 풀릴 것 같은 문제가 많다고 느꼈다. 물론 문제의 특성상 풀이 자체도 복잡해지기 마련이지만 자신이 직접 바꾼 접근방법에 맞춰 풀이도 모두 변경할 수 있다면 문제없다고 생각한다.

## 어항정리
https://www.acmicpc.net/problem/23291
### 의견
현재 문제를 풀어보고 있으나 풀이를 아예 갈아엎고 다시 3번이나 풀었지만 값이 조금씩 다르게 출력되어 접근방식에 문제가 있다고 생각한다. 다음 주 풀이에 시간이 된다면 다시 한번 풀이에 도전해 볼 예정이다.


