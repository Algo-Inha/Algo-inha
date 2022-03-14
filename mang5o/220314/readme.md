# Solving
## Z
https://www.acmicpc.net/problem/1074
### 문제풀이
```python
import sys  
  
N, r, c = map(int, sys.stdin.readline().rstrip().split())  
now_area = [[0, 2 ** N], [0, 2 ** N]]  # height, width  
now_step = 0  
while now_area[0][1] - now_area[0][0] > 1:  
    tmp_height_width = (now_area[0][1] - now_area[0][0])//2  
  tmp_area = [  
        [[now_area[0][0], now_area[0][0] + tmp_height_width], [now_area[1][0], now_area[1][0] + tmp_height_width]],  
  [[now_area[0][0], now_area[0][0] + tmp_height_width], [now_area[1][0] + tmp_height_width, now_area[1][1]]],  
  [[now_area[0][0] + tmp_height_width, now_area[0][1]], [now_area[1][0], now_area[1][0] + tmp_height_width]],  
  [[now_area[0][0] + tmp_height_width, now_area[0][1]], [now_area[1][0] + tmp_height_width, now_area[1][1]]]  
    ]  
    for i in range(4):  
        if tmp_area[i][0][0] <= r < tmp_area[i][0][1] and tmp_area[i][1][0] <= c < tmp_area[i][1][1]:  
            now_area = tmp_area[i]  
            continue_flag = True  
 break else:  
            now_step += tmp_height_width ** 2  
if now_area[0][0] == r and now_area[1][0] == c:  
    now_step += 0  
elif now_area[0][0] == r and now_area[1][1] == c:  
    now_step += 1  
elif now_area[0][1] == r and now_area[1][0] == c:  
    now_step += 2  
elif now_area[0][1] == r and now_area[1][1] == c:  
    now_step += 3  
  
print(now_step)
```
중요한 것은 흔히 함수에서 말하는 Recursion 형태의 코드 운영인데, 전체 맵에 대해서 1/4로 나누고 그 중 어디에 있는지 확인한다. 그 다음 또 있는 부분에 대해서 1/4로 나누는 작업이 진행되며, 결과적으로 2*2크기만 남을 경우 아래 부분에서 위치에 따른 step 계산을 진행한다.

```python
if now_area[0][0] == r and now_area[1][0] == c:  
    now_step += 0  
elif now_area[0][0] == r and now_area[1][1] == c:  
    now_step += 1  
elif now_area[0][1] == r and now_area[1][0] == c:  
    now_step += 2  
elif now_area[0][1] == r and now_area[1][1] == c:  
    now_step += 3
```
다만 처음에 1/4씩 나눈 뒤 3번째 블록에 해당 숫자가 존재한다면, 이전의 2개 블록의 크기만큼 step을 더해주는 작업이 선행되어야 한다.

### 의견
이 문제를 풀어놓고 보니, 내가 코테에선 함수를 지나치게 안 쓰는 경향이라고 느꼈다.

## 마법사 상어와 파이어스톰
https://www.acmicpc.net/problem/20058
### 문제풀이
문제에서 중요한 것은 `Rotate -> Melting`이 한 스탭마다 이루어진다는 것이다.
```python
if firestorm != 0:  
    # 회전  
  tmp_matrix = [[0 for i in range(N)] for j in range(N)]  
    now_grid = 2 ** firestorm  
    now_y_grid = N//now_grid  
    now_x_grid = N//now_grid  
    for y_grid in range(now_y_grid):  
        for x_grid in range(now_x_grid):  
            for y in range(now_grid):  
                for x in range(now_grid):  
                    tmp_y = now_grid * y_grid + y  
                    tmp_x = now_grid * x_grid + x  
                    tmp_rotated_y = now_grid * y_grid + x  
                    tmp_rotated_x = now_grid * x_grid + now_grid - 1 - y  
                    tmp_matrix[tmp_rotated_y][tmp_rotated_x] = map_matrix[tmp_y][tmp_x]  
  
    map_matrix = tmp_matrix  # shallow copy라 assign에 시간이 오래걸리지 않음
```
GRID 대로 나누어서 회전을 진행하기 때문에 4중 for문이 존재하고 매우 끔찍해보이지만, 사실 4개의 for문을 합쳐도 O(size*size) 만큼만 돌기 때문에 느리지 않다. 또한 `map_matrix = tmp_matrix`에서 매 스탭마다 copy를 하는데에 오래걸리지 않냐고 생각할 수 있겠지만, list자체를 `=` operator로 복사할 경우 파이썬에서는 shallow copy가 진행된다. 장점이 될 수 있지만 deepcopy를 원할 수 있어서 만약 deepcopy를 하고싶은 상황이라면 아래와 같이 진행할 수 있다.
`map_matrix = [[tmp_matrix[y][x] for x in range(width)] for y in range(height)]`

```python
# 얼음 녹기  
now_all_melted = True  
for y in range(N):  
    for x in range(N):  
        now_surrounding = 0  
  for dir_idx in range(4):  
            tmp_y = y + dir_matrix[dir_idx][0]  
            tmp_x = x + dir_matrix[dir_idx][1]  
            if 0<=tmp_y<N and 0<=tmp_x<N:  
                if map_matrix[tmp_y][tmp_x]>0:  
                    now_surrounding += 1  
  if now_surrounding<3:  
            diff_matrix[y][x] = True  
 else:  
            diff_matrix[y][x] = False  
for y in range(N):  
    for x in range(N):  
        if diff_matrix[y][x] and map_matrix[y][x]>0:  
            map_matrix[y][x] -= 1  
  if map_matrix[y][x] > 0:  
            now_all_melted = False  
if now_all_melted:  
    break
```
얼음이 녹는 부분이다. 주변 칸에 얼음이 있을 경우 diff_matrix에 True값을 넣어주며, 이건 `계산 이후에 얼음이 녹을 칸`이라는 뜻이다.

```python
# 총 얼음량 및 덩어리 구하기  
deque_bfs = deque()  
visited_matrix = [[False for i in range(N)] for j in range(N)]  
for y in range(N):  
    for x in range(N):  
        if map_matrix[y][x] == 0:  
            visited_matrix[y][x] = True  
  
max_area = 0  
all_ice = 0  
for y in range(N):  
    for x in range(N):  
        if map_matrix[y][x] != 0 and not visited_matrix[y][x]:  
            now_area = 1  
  all_ice += map_matrix[y][x]  
            deque_bfs.append((y,x))  
            visited_matrix[y][x] = True  
 while len(deque_bfs) > 0:  
                tmp_position = deque_bfs.popleft()  
                for dir_idx in range(4):  
                    tmp_y = tmp_position[0] + dir_matrix[dir_idx][0]  
                    tmp_x = tmp_position[1] + dir_matrix[dir_idx][1]  
                    if 0<=tmp_y<N and 0<=tmp_x<N:  
                        if not visited_matrix[tmp_y][tmp_x]:  
                            visited_matrix[tmp_y][tmp_x] = True  
  deque_bfs.append((tmp_y,tmp_x))  
                            all_ice += map_matrix[tmp_y][tmp_x]  
                            now_area += 1  
  if max_area < now_area:  
                max_area = now_area
```
모든 (y,x)를 시작점으로 두고 DFS나 BFS를 진행하여 얼음의 크기를 구하는 작업이다.

### 의견
회전이 까다롭긴 했지만 새로운 개념이라고 생각하긴 어렵다. 대신 얼음의 크기를 구하는 부분이 일반적으로 그룹화 시키는 클러스터링 문제의 느낌이 났고, 두 개념이 합쳐져서 생각보다 재밌는 문제였다.
다만 처음에 착각해서 문제의 설명 그림을 잘못 이해해서 회전 방식에 대해 잘못 코딩해서 시간을 소모했다.

## 카카오 프렌즈 컬러링북
https://programmers.co.kr/learn/courses/30/lessons/1829
### 문제풀이
```python
dir_matrix = ((0,1),(0,-1),(-1,0),(1,0))  
  
def solution(m,n,picture):  
    visited_matrix = [[False for i in range(n)] for j in range(m)]  
    fig_area = 0 # 범위의 개수  
  max_color_area = 0  
  for i in range(m):  
        for j in range(n):  
            if picture[i][j]==0:  
                visited_matrix[i][j] = True  
 for y in range(m):  
        for x in range(n):  
            if not visited_matrix[y][x]:  
                tmp_deque = deque()  
                tmp_deque.append((y,x))  
                visited_matrix[y][x] = True  
  now_color = picture[y][x]  
                now_color_area = 1  
  fig_area += 1  
  while len(tmp_deque)>0:  
                    tmp_elem = tmp_deque.popleft()  
                    for dir_idx in range(4):  
                        tmp_y = tmp_elem[0] + dir_matrix[dir_idx][0]  
                        tmp_x = tmp_elem[1] + dir_matrix[dir_idx][1]  
                        if 0<=tmp_y<m and 0<=tmp_x<n:  
                            if not visited_matrix[tmp_y][tmp_x] and picture[tmp_y][tmp_x]==now_color:  
                                visited_matrix[tmp_y][tmp_x] = True  
  now_color_area += 1  
  tmp_deque.append((tmp_y,tmp_x))  
                max_color_area = max(max_color_area, now_color_area)  
    return [fig_area,max_color_area]
```

위 문제인 "마법사 상어와 파이어스톰"에서 얼음을 나누는 느낌의 문제였지만, 시작점의 color를 가지고 주변 점 중에 해당 color만 가져온다는 추가적인 조건이 붙었다.

### 의견
안타깝게도 문제 자체가 C++과 JAVA만 오픈되어있어서 개인적으로 테스트케이스는 실행해보았으나 실제스코어 계산에 사용하는 케이스에 대해서 실험하지 못한게 아쉬웠다.

## 다트게임
https://programmers.co.kr/learn/courses/30/lessons/17682
### 문제풀이
```python
def solution(dartResult):  
    # 보너스 이후 옵션이 없으면 X로 만들기  
  dartResult = dartResult.replace("10","A")  
    dartResult += "0" # IndexError 처리 (i==2일 경우)  
  for i in range(3):  
        if '0' <= dartResult[3*i + 2] <= '9' or dartResult[3*i + 2] == 'A':  
            dartResult = dartResult[:3*i+2] + "X" + dartResult[3*i+2:]  
    dartResult = dartResult[:len(dartResult)-1] # 맨 뒤 0 제거  
  now_result_arr = []  
    for i in range(3): # 숫자 입력  
  if dartResult[3*i] == "A":  
            now_result_arr.append(10)  
        else:  
            now_result_arr.append(int(dartResult[3*i]))  
    for i in range(3): # 보너스  
  if dartResult[3*i + 1] == "D":  
            now_result_arr[i] **= 2  
  elif dartResult[3*i + 1] == "T":  
            now_result_arr[i] **= 3  
  for i in range(3): # 상  
  if dartResult[3*i + 2] == "*":  
            if i-1 >= 0:  
                now_result_arr[i-1] *= 2  
  now_result_arr[i] *= 2  
  elif dartResult[3*i + 2] == "#":  
            now_result_arr[i] *= -1  
  all_score = sum(now_result_arr)  
    return all_score
```
핵심은 3글자씩 끊어서 읽을 수 있도록 만든 것이라고 생각한다. 다르게 해도 되겠지만 코드가 그나마 깔끔하게 만들어질 수 있는 방법이다. 점수가 0~10점이기 때문에 10점일 경우 A로 변경하였고, 상을 받지 않았을 경우 X를 삽입하는 형태로 진행하여 결과적으로 모든 시도가 3개의 인덱스를 차지하도록 구현하였다.

### 의견
간만에 호감가는 문제였고, 문자열 처리가 또 들어와서 간단하게 해결했다.

## 수영장
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpFQaAQMDFAUq&categoryId=AV5PpFQaAQMDFAUq&categoryType=CODE&problemTitle=195
### 문제풀이
```python
for t_elem in range(T):  
    prices = list(map(int, input().split()))  
    days = list(map(int, input().split()))  
    deque_ticket = deque()  
    first_elem = [False for i in range(12)]  
    first_elem.append(0)  
    deque_ticket.append([False for i in range(12)])  # False : 1일 및 1달 이용권, True: 3달 이용권  
  min_cost = -1  
  while len(deque_ticket) > 0:  
        tmp_elem = deque_ticket.popleft()  
        # tmp_elem에 따라 계산  
  tmp_elem_cost = 0  
  
  now_cursor = 0  
  while now_cursor < 12:  
            if tmp_elem[now_cursor]:  
                tmp_elem_cost += prices[2]  
                now_cursor += 3  
  else:  
                tmp_elem_cost += min(days[now_cursor] * prices[0], prices[1])  
                now_cursor += 1  
  
  if min_cost == -1:  
            min_cost = tmp_elem_cost  
        elif min_cost > tmp_elem_cost:  
            min_cost = tmp_elem_cost  
  
        # 탐색  
  for i in range(tmp_elem[-1], 10):  
            if tmp_elem[i] == False and tmp_elem[i + 1] == False and tmp_elem[i + 2] == False:  
                tmp_tmp_elem = [tmp_elem[idx] for idx in range(12)]  
                tmp_tmp_elem[i] = True  
  tmp_tmp_elem[i + 1] = True  
  tmp_tmp_elem[i + 2] = True  
  tmp_tmp_elem.append(i + 2)  
                deque_ticket.append(tmp_tmp_elem)  
    # 1년권이랑 비교하는걸 안넣어서 한번 틀렸다...  
  if min_cost > prices[3]:  
        min_cost = prices[3]  
  
    all_min_cost.append(min_cost)
```
deque를 써서 3달 이용권을 쓰는 모든 경우의 수를 구했다. 사실 1달 이용권인지 1일 이용권인지는 중요하지 않은데, 마지막에 계산할 경우 `3달 이용권을 쓰는 달이 아닌경우 1달 혹은 1일로 계산하여 최소값을 쓰면 된다`고 생각했기 때문이다. 

### 의견
마지막에 1년권이랑 비교하는 부분을 빼먹어서 한 번 오답이 나왔으나, 금방 수정하여 통과했다.

