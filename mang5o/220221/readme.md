# Solving
## 감시카메라
https://www.acmicpc.net/problem/5884
### 문제풀이
```c
import sys  
  
N = int(sys.stdin.readline().rstrip())  
positions = []  
for i in range(N):  
    cow_x, cow_y = map(int, sys.stdin.readline().rstrip().split())  
    positions.append((cow_x, cow_y))  # append with tuples  
  
while_cnt = 0  
while while_cnt < 3:  
    while_cnt += 1  
  max_xy = False # true : x, false : y  
  max_val = 0  
  max_idx = 0  
  dict_x = {}  
    dict_y = {}  
    for i in positions:  
        if i[0] in dict_x:  
            dict_x[i[0]] += 1  
  else:  
            dict_x[i[0]] = 1  
  if dict_x[i[0]] > max_val:  
            max_val = dict_x[i[0]]  
            max_xy = True  
  max_idx = i[0]  
        if i[1] in dict_y:  
            dict_y[i[1]] += 1  
  else:  
            dict_y[i[1]] = 1  
  if dict_y[i[1]] > max_val:  
            max_val = dict_y[i[1]]  
            max_xy = False  
  max_idx = i[1]  
    if max_xy:  
        positions = [p_item for p_item in positions if p_item[0]!=max_idx]  
    else:  
        positions = [p_item for p_item in positions if p_item[1]!=max_idx]  
    if len(positions)==0:  
        break  
  
if len(positions) == 0:  
    print(1)  
else:  
    print(0)
```
3번의 process 반복을 진행하며 (`while_cnt`) 한 번 진행할 때에 아래와 같은 프로세스를 진행한다.
```
1. 소의 x값과 y값을 모두 확인하여 최빈값을 구한다(x,y 모두 합쳐서)
2. 최빈값에 대해서 카메라를 설치한다
3. 설치한 카메라에 잡히던 모든 소를 제거한다.
```

### 의견
생각보다 시간 제한이 길었던건지, 소를 제거하고 다시 최빈값을 계산하는 작업을 진행하였지만 통과가 되었다. 다만 python으로 해당 문제를 통과한 사람이 한 명도 없었기 때문에 최대한 시간 소모가 적도록 x와y를 map(`dict`)을 통해 구현하였다.


## 신규 아이디 추천
https://programmers.co.kr/learn/courses/30/lessons/72410
### 문제풀이
```python
def solution(new_id):    
  new_id = new_id.lower()  
    ref_id = ""  
  for i in new_id:  
        if 'a' <= i <= 'z' or '0' <= i <= '9' or i == '_' or i == '-' or i == '.':  
            ref_id += i  
    while True:  
        if ".." in ref_id:  
            ref_id = ref_id.replace("..", ".")  
        else:  
            break  
 if len(ref_id) > 0:  
        if ref_id[0] == '.':  
            ref_id = ref_id[1:]  
    if len(ref_id) > 0:  
        if ref_id[-1] == '.':  
            ref_id = ref_id[:-1]  
    if len(ref_id) == 0:  
        ref_id = "a"  
  if len(ref_id) >= 16:  
        ref_id = ref_id[0:15]  
    if ref_id[-1] == '.':  
        ref_id = ref_id[:-1]  
    for cnt in range(3 - len(ref_id)):  
        ref_id += ref_id[-1]  
    return ref_id
```
문제에서 언급했던 순서를 그대로 지켜가면 크게 문제가 되지 않았다. 

연속된 마침표를 모두 마침표 하나로 바꿔야 하므로 아래와 같이 while문을 사용했으며
```python
while True:  
    if ".." in ref_id:  
        ref_id = ref_id.replace("..", ".")  
    else:  
        break
```

그 외에는 문자 그대로 진행하였다.

### 의견
손 댈 곳이 없는 문자에 대한 타임 리밋이 매우 빡빡하다면, 맨 처음에 regex를 통해 이 아이디가 적합한 아이디 인지 확인을 한 뒤에 진행할 계획이었다. 하지만 코딩테스트 도중 regex를 구현하기도 귀찮을 뿐더러, 다른 언어에서도 진행할 수 있도록 문제가 나왔을 거라는 생각에 regex는 사용하지 않고 진행하였다.

## 빗물
https://www.acmicpc.net/problem/14719
### 문제풀이
```python
import sys  
  
H, W = map(int, sys.stdin.readline().rstrip().split())  
blocks = list(map(int, sys.stdin.readline().rstrip().split()))  
map_matrix = []  
for i in blocks:  
    map_matrix.append(  
        [1 if idx < i else 0  
  for idx in range(H)]  
    )  # 1 : 블럭, 0 : 빈 공간,  
water_cnt = 0  
for y in range(W):  
    if y == 0:  
        continue # 맨 윗 라인 통과  
  for x in range(H):  
        if map_matrix[y - 1][x] == 1 and map_matrix[y][x] == 0:  
            tmp_flag = False  
  tmp_x_max = 0  
  for tmp_y in range(y, W):  
                if map_matrix[tmp_y][x] == 1:  
                    tmp_flag = True  
  tmp_x_max = tmp_y  
            for tmp_y in range(y, tmp_x_max):  
                if map_matrix[tmp_y][x] == 0:  
                    map_matrix[tmp_y][x] = 2  
  water_cnt += 1  
# for mm in map_matrix:  
#     print(mm)  
print(water_cnt)
```
풀이 방법으로 사용한 가장 큰 키워드는 블럭 오른쪽 빈 공간으로부터 시작한다는 개념이다. 블럭 바로 오른쪽 공간부터 시작하여 맵의 맨 오른쪽까지 이동하면서 블럭이 있을 경우 시작점부터 그 블럭까지를 모두 물로 채우는 작업을 진행하였으며, 빠르게 작동한 것 같다.

### 의견
`모든 좌표에 대해 왼쪽과 오른쪽으로 이동하면서 블럭이 있을 경우 물이 찬다` 라는 프로세스를 모든 빈 칸에 대해 진행하려 했으나, 너무 비효율적이라 생각하여 위와 같은 풀이로 진행하였다.

## 바이러스
https://www.acmicpc.net/problem/2606
### 문제풀이
```python
nodes = int(sys.stdin.readline().rstrip())  
edges = int(sys.stdin.readline().rstrip())  
now_queue = Queue()  
  
adj_matrix = [[False for i in range(nodes)] for j in range(nodes)]  
visited_matrix = [False for i in range(nodes)]  
for eg in range(edges):  
    tmp_a, tmp_b = map(int, sys.stdin.readline().rstrip().split())  
    adj_matrix[tmp_a-1][tmp_b-1] = True  
  adj_matrix[tmp_b-1][tmp_a-1] = True  
  
now_queue.put(0)  
visited_matrix[0] = True  
  
while now_queue.qsize() > 0:  
    tmp_queue = now_queue.get()  
    for i in range(nodes):  
        if adj_matrix[tmp_queue][i] and not visited_matrix[i]:  
            visited_matrix[i] = True  
  now_queue.put(i)  
  
cnt = 0  
for eg in range(nodes):  
    if visited_matrix[eg]:  
        cnt += 1  
print(cnt-1)
```
가장 간단한 탐색 문제였다. DFS나 BFS 모두 풀 수 있다고 생각했으며, 해당 풀이는 BFS로 풀이되었다.
BFS로 Searching작업을 끝낸 뒤, visited의 수를 세어 print해주었다.

### 의견
정말 간단한 문제였으나, 맨 처음엔 자기 자신을 포함하여 정답을 체크해서 +1이 나왔다. 이 때문에 샘플 데이터가 중요하다고 다시 한 번 생각했다.

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
처음에 `dir_mv` 행렬을 어떻게 구현할 지 생각했다. 사실 np array로 구현되어 있다면 rotate를 통해 손쉽게 회전 행렬을 구할 수 있을 테지만, 코딩테스트 특성상 numpy를 import하기에도 부담스러웠고 rotate에 사용되는 메모리 또한 아까워서 그 메모리를 내 머리로 대신하였다.
패딩을 2씩 넣은 이유는 매 이동마다 확인해야 할 커널이 5*5 사이즈 이기 때문이다. 

### 의견
처음에 왜 alpha로 가는 모래가 따로 명시되어 있지 않은지 궁금했다. 나머지 %를 다 합해서 남은 양이 55%였는데, 그래서 처음엔 55%로 계산을 하였다. 하지만 답이 다르게 나와서 확인해보니 `나머지 모래의 총량이 alpha로 간다`는 내용이 이해가 되었다. 매 연산마다 `floor`(내림) 연산이 있으므로 여기에서 버려지는 값들도 모두 결국엔 alpha로 이동한다는 것을 알았다.

## 피아노 체조
https://www.acmicpc.net/problem/21318
### 문제풀이
```python
import sys  
N = int(sys.stdin.readline().rstrip())  
stage = list(map(int, sys.stdin.readline().rstrip().split()))  
Q = int(sys.stdin.readline().rstrip())  
questions = []  
for i in range(Q):  
    questions.append(  
        list(map(int, sys.stdin.readline().rstrip().split()))  
    )  
mistake_cnt = [0]  
for i in range(N-1):  
    if stage[i] > stage[i+1]:  
        mistake_cnt.append(mistake_cnt[-1] + 1)  
    else:  
        mistake_cnt.append(mistake_cnt[-1])  
  
for i in range(Q):  
    print(mistake_cnt[questions[i][1]-1]- mistake_cnt[questions[i][0]-1])
```
누적합을 모두 구해서 Question에서 나오는 두 숫자를 index로 하여 서로 차이를 반환해주었다.

### 의견
주석으로도 필기했지만, 처음에는 누적합이 아니라 직접 Question에 대해서 계산하였는데, 시간초과가 발생하여 다시 한번 문제를 보니 `곡 난이도 행렬`은 한 번만 주지만, Question은 여러개가 있어서 미리 실수 횟수를 계산해놓아야 한다는 것으로 느꼈다. 이것이 누적합으로 구현되었다.
다만 Question이 하나만 존재한다면 누적합보다 그 때 직접 계산하는 것이 더 빠른데, 이는 누적합의 경우 모든 에러 경우를 `곡 난이도 행렬` 전체에 대해 계산한 뒤 꺼내 쓰지만, 직접 계산한다면 이보다 계산에 메모리 소모가 적을 것이기 때문이다.

