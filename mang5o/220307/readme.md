# Solving
## 숫자 문자열과 영단어
https://programmers.co.kr/learn/courses/30/lessons/81301
### 문제풀이
```python
def solution(s): # 이게뭐야  
  answer = s.replace("zero", "0").replace("one", "1").replace("two", "2").replace("three", "3").replace("four", "4") \  
        .replace("five", "5").replace("six", "6").replace("seven", "7").replace("eight", "8").replace("nine", "9")  
    return int(answer)
```
### 의견
?

## 비밀지도
https://programmers.co.kr/learn/courses/30/lessons/17681
### 문제풀이
```python
def make_binary(num, rep):  
    tmp_num = num  
    arr = [0 for i in range(rep)]  
    for i in range(rep):  
        arr[-1 - i] = tmp_num % 2  
  tmp_num //= 2  
  return arr  
  
  
def solution(n, arr1, arr2):  
    answer = [["#" for i in range(n)] for j in range(n)]  
    map_1 = [make_binary(arr1[i], n) for i in range(n)]  
    map_2 = [make_binary(arr2[i], n) for i in range(n)]  
    for i in range(n):  
        for j in range(n):  
            if map_1[i][j] == 0 and map_2[i][j] == 0:  
                answer[i][j] = " "  
  str_answer = []  
    for i in range(n):  
        now_str = ""  
  for j in range(n):  
            now_str += answer[i][j]  
        str_answer.append(now_str)  
  
    return str_answer
```
### 의견
처음으로 프로그래머스 자체에서 코딩테스트를 본다는 느낌으로 (IDE를 사용하지 않고) 진행해보았다. 

## 벽 부수고 이동하기
https://www.acmicpc.net/problem/2206
### 문제풀이
```python
import sys  
from collections import deque  
  
dir_matrix = ((0, 1), (0, -1), (1, 0), (-1, 0))  
N, M = map(int, sys.stdin.readline().rstrip().split())  
map_input = []  
for i in range(N):  
    map_input.append(list(map(int, sys.stdin.readline().rstrip()[::1])))  
  
if N == 1 and M == 1:  
    print(1)  
else:  
    visited_matrix = [[[1000000, 1000000] for i in range(M)] for j in range(N)]  
    visited_matrix[0][0] = [1, 1]  
    bfs_queue = deque()  
    bfs_queue.append((0, 0, 0))  # y행, x열, 현재 벽 넘어간 수  
  now_step = 2 # 시작 및 끝 포함  
  end_flag = False  
 while len(bfs_queue) != 0:  
        now_stage = len(bfs_queue)  
        for i in range(now_stage):  
            tmp_queue_elem = bfs_queue.popleft()  
            for dir_fig in range(4):  
                tmp_y = tmp_queue_elem[0] + dir_matrix[dir_fig][0]  
                tmp_x = tmp_queue_elem[1] + dir_matrix[dir_fig][1]  
                if 0 <= tmp_y < N and 0 <= tmp_x < M:  
                    if tmp_y == N - 1 and tmp_x == M - 1:  
                        end_flag = True  
 break elif map_input[tmp_y][tmp_x] == 0:  
                        if visited_matrix[tmp_y][tmp_x][tmp_queue_elem[2]] > now_step:  
                            visited_matrix[tmp_y][tmp_x][tmp_queue_elem[2]] = now_step  
                            bfs_queue.append((tmp_y, tmp_x, tmp_queue_elem[2]))  
                    else:  
                        if visited_matrix[tmp_y][tmp_x][1] > now_step and tmp_queue_elem[2] == 0:  
                            visited_matrix[tmp_y][tmp_x][1] = now_step  
                            bfs_queue.append((tmp_y, tmp_x, 1))  
            if end_flag:  
                break  
 if end_flag:  
            break  
  now_step += 1  
  
  if end_flag:  
        print(now_step)  
    else:  
        print(-1)
```

3차원 배열을 사용해서 `visitied_matrix[y][x][k]` 의 형태를 띄는데, (x,y) 좌표에서 k번 벽을 넘었을 경우 얼마나 걸렸는지 값을 넣는 방식이다.
다만 벽을 넘거나, 넘지 않거나 둘 중에 하나라도 도착을 먼저 한다면 가장 빠른 길이므로 그 즉시 while을 종료하고 그 때의 시간을 정답으로 한다.

### 의견
`시작하는 곳과 도착하는 곳도 포함해서 거리를 계산`한다는 것은 테스트데이터를 통해 바로 확인했으나, 꾸준한 시간초과가 발생하였고, 아무리 봐도 저 코드보다 더 빠른 알고리즘이 없다고 확신한 나는 코드적으로 잘못하고 있는 것이 있는지 확인했다.
충격적이었던 것은, `queue.Queue()` 보다 `collections.deque()`가 더 빠르다는 것이었다. 당연히 양방향큐가 더 느릴것이라 생각했지만 멀티쓰레드 환경 등을 지원하지 않는 `deque`가 더 빠르다고 써있는 글을 보고 queue를 단순히 deque로 바꾸는 작업을 통해 시간초과에서 벗어났다.
이 문제 이후부턴 queue를 사용하는 알고리즘도 모두 deque를 사용해 풀어야겠다고 생각했다.

## 미세먼지 안녕!
https://www.acmicpc.net/problem/17144
### 문제풀이
```python
# 미세먼지가 확산된다. 확산은 미세먼지가 있는 모든 칸에서 동시에 일어난다.
for y in range(R):
    for x in range(C):
        if map_matrix[y][x] != -1:
            tmp_now_dust = map_matrix[y][x]  # 처음 그 곳의 dust
            spread_dust = int(math.floor(tmp_now_dust / 5))  # 퍼지는 양
            tmp_now_dust_diff = 0  # 한 스탭에 그 dust의 변화량
            for i in range(4):
                tmp_y = y + dir_matrix[i][0]
                tmp_x = x + dir_matrix[i][1]
                if 0 <= tmp_y < R and 0 <= tmp_x < C:
                    if map_matrix[tmp_y][tmp_x] != -1:
                        tmp_matrix[tmp_y][tmp_x] += spread_dust
                        tmp_now_dust_diff -= spread_dust
            tmp_matrix[y][x] += tmp_now_dust_diff
for y in range(R):
    for x in range(C):
        if map_matrix[y][x] != -1:
            map_matrix[y][x] += tmp_matrix[y][x]
            tmp_matrix[y][x] = 0
```
미세먼지의 확산 부분이다. y와 x에 따라 순차적으로 진행하는데 같은 행렬 내에서 계산할 경우 `동일 단계의 다른 칸으로의 영향`을 받기 때문에, 새로운 행렬을 사용하였다. diff행렬의 역할을 하는 이 행렬에 먼지의 증감을 다 구해두고 map_matrix와 서로 합치는 식의 방식으로 단계단계를 넘어갔다.

```python
# 공기청정기가 작동한다.
# stable하게 matrix를 사용하기 위해선 공기청정기로 들어가는 부분부터 역순으로 들어가는게 필요함
# upper circular cycle
for tmp_y in range(1, conditioner[0]):
    now_y = conditioner[0] - tmp_y
    map_matrix[now_y][0] = map_matrix[now_y - 1][0]
for tmp_x in range(C - 1):
    map_matrix[0][tmp_x] = map_matrix[0][tmp_x + 1]
for tmp_y in range(conditioner[0]):
    map_matrix[tmp_y][C - 1] = map_matrix[tmp_y + 1][C - 1]
for tmp_x in range(C - 2):
    now_x = C - tmp_x - 1
    map_matrix[conditioner[0]][now_x] = map_matrix[conditioner[0]][now_x - 1]
map_matrix[conditioner[0]][0] = -1
map_matrix[conditioner[0]][1] = 0
# lower circular cycle
for tmp_y in range(conditioner[1] + 1, R - 1):
    map_matrix[tmp_y][0] = map_matrix[tmp_y + 1][0]
for tmp_x in range(C - 1):
    map_matrix[R - 1][tmp_x] = map_matrix[R - 1][tmp_x + 1]
for tmp_y in range(R - conditioner[1] - 1):
    now_y = R - tmp_y - 1
    map_matrix[now_y][C - 1] = map_matrix[now_y - 1][C - 1]
for tmp_x in range(C - 2):
    now_x = C - tmp_x - 1
    map_matrix[conditioner[1]][now_x] = map_matrix[conditioner[1]][now_x - 1]
map_matrix[conditioner[1]][0] = -1
map_matrix[conditioner[1]][1] = 0
```
공기청정기의 작동 부분이다. 생각보다 정말 더러운 방식으로 구했는데, general하게 짜기에는 좀 어려운 것 같다. 먼지의 이동에는 공기청정기의 출발방향부터 계산하게 되면 이전의 이동이 영향을 주기 때문에 반대방향으로 계산해야한다.

```python
all_dust = 0  
map_matrix[conditioner[0]][0] = 0  
map_matrix[conditioner[1]][0] = 0  
for y in range(R):  
    for x in range(C):  
        all_dust += map_matrix[y][x]
```
마지막으로 모든 인덱스를 돌며  합을 구해주는 작업이다. 

### 의견
시뮬레이션 문제라서 코드가 길어지긴 하였지만, 생각하기 어려운 부분이 있는 것이 아니라 다행이었다. 공기의 이동을 역순으로 한다는 아이디어는 바로 떠오르긴 했는데, `list를 한 칸씩 옮기거나, list에서 여러 인덱스를 삭제하는 방식` 등에서 이전의 프로세스가 다음 프로세스에 영향을 끼치지 않도록 역순으로 하는 것을 해봤기 때문에 생각이 났다고 본다.

## 상어 초등학교
https://www.acmicpc.net/problem/21608
### 문제풀이
```python
for i in range(N ** 2):  
    tmp_input = list(map(int, sys.stdin.readline().rstrip().split()))  
    order_index_map[tmp_input[0]] = i  
    max_y = -1  
  max_x = -1  
  adj_score = 0 # 주변 친구 점수  
  blank_score = 0 # 주변 빈칸 점수  
  for y in range(N):  
        for x in range(N):  
            if map_matrix[y][x] == 0:  
                tmp_adj_score = 0  
  tmp_blank_score = 0  
  for j in range(4):  
                    tmp_y = y + dir_matrix[j][0]  
                    tmp_x = x + dir_matrix[j][1]  
                    if 0 <= tmp_y < N and 0 <= tmp_x < N:  
                        if map_matrix[tmp_y][tmp_x] == 0:  
                            tmp_blank_score += 1  
  elif map_matrix[tmp_y][tmp_x] in tmp_input:  
                            tmp_adj_score += 1  
  if max_y == -1: # 맨 처음 빈 칸  
  max_y = y  
                    max_x = x  
                    adj_score = tmp_adj_score  
                    blank_score = tmp_blank_score  
                elif adj_score < tmp_adj_score:  
                    max_y = y  
                    max_x = x  
                    adj_score = tmp_adj_score  
                    blank_score = tmp_blank_score  
                elif adj_score == tmp_adj_score and blank_score < tmp_blank_score:  
                    max_y = y  
                    max_x = x  
                    adj_score = tmp_adj_score  
                    blank_score = tmp_blank_score  
    map_matrix[max_y][max_x] = tmp_input[0]  
    order_index_map[tmp_input[0]] = i  
    input_matrix.append(tmp_input)
```
학생들의 자리를 찾아주는 부분이다. 맨 먼저 입력된 학생부터 자리를 잡는다. 

```python
for y in range(N):  
    for x in range(N):  
        tmp_adj_calc = 0  
  for i in range(4):  
            tmp_y = y + dir_matrix[i][0]  
            tmp_x = x + dir_matrix[i][1]  
            if 0 <= tmp_y < N and 0 <= tmp_x < N:  
                # 인접한 학생 : map_matrix[tmp_y][tmp_x]  tmp_idx =  order_index_map[map_matrix[y][x]]  
                if map_matrix[tmp_y][tmp_x] in input_matrix[tmp_idx]:  
                    tmp_adj_calc += 1  
  now_all_score += adj_score_table[tmp_adj_calc]
```
마지막에 점수를 다시 계산하는 부분이다. 사실 초기에는 학생들의 배치에도 점수계산 작업이 들어가니 배치를 하는 동시에 점수를 점점 더하는 방식을 생각했으나, 뒤에 들어오는 학생이 이미 배치된 학생이 좋아하는 학생일 수 있기 때문에 점수변동이 생긴다.

### 의견
```python
order_index_map = {}  # order_index_map[K] => K 학생이 몇 번째로 입력을 받았는지
```
이 부분이 속도 감소에 큰 영향을 미쳤다고 생각한다. 좋아하는 학생은 `학생번호`로 제공되지만, 입력받는 학생의 목록은 학생번호 순서대로 들어오지 않기 때문에 위와 같이 dictionary를 사용하였다.
