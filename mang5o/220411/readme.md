# Solving
##  ACM Craft
https://www.acmicpc.net/problem/1005
### 문제풀이
```python
import sys  
T = int(sys.stdin.readline().rstrip())  
overall_result = []  
for all_step in range(T):  
    N, K = map(int, sys.stdin.readline().rstrip().split())  
    all_d = list(map(int, sys.stdin.readline().rstrip().split()))  
    all_edge = [[False for x in range(N)] for y in range(N)]  
    for i in range(K):  
        A, B = map(int, sys.stdin.readline().rstrip().split())  
        A -= 1 # 번호 시작을 0번으로 옮김  
  B -= 1 # 번호 시작을 0번으로 옮김  
  all_edge[A][B] = True # A번이 완성되어야 B가 완성된다  
  W = int(sys.stdin.readline().rstrip()) -1 # 마지막으로 만들어야 할 건물  
  
  all_times = [-1 for i in range(N)]  
    while True:  
        if all_times[W] != -1:  
            break  
  now_build = False  
 for i in range(N):  
            if all_times[i] == -1:  
                now_building = i  
                now_can_flag = True  
  max_time = -1  
  for j in range(N):  
                    if all_edge[j][i]: # i보다 j가 먼저 완성되어야 할 경우  
  if all_times[j] == -1:  
                            now_can_flag = False # 하나라도 만들어지지 않았을 때  
  break  
 else:  
                            max_time = max(max_time, all_times[j] + all_d[i])  
                if now_can_flag: # 만들 수 있을 경우  
  if max_time==-1:  
                        max_time = all_d[i]  
                    all_times[i] = max_time  
                    now_build = True  
  # print(all_times)  
  overall_result.append(all_times[W])  
for i in range(T):  
    print(overall_result[i])
```
Worst case에서 O(N^2)의 속도를 가진다. 이 문제 풀이에서의 가장 큰 핵심은 `all_edge`라는 행렬이며, 비대칭 함수이고 `all_edge[A][B] = True # A번이 완성되어야 B가 완성된다` 라는 의미를 가지고 있게 된다. 초기 입력을 받을 때에 정립한다.
while문 안에 for문이 자리잡고 있는데, while문의 종료 조건은 W에 대한 시간이 결정났을 때이다 (이것이 결과이기 때문에). 0~(n-1) 번의 건물이 있다고 가정했을 때에, 0번 건물부터 자신보다 선행되어야 하는 건물을 모두 탐색한다. `선행되어야 하는 건물들의 건축 시간의 최대값 + 자신의 건축 시간`을 변수에 집어넣는다. 선행 건물 중에 아직 건축되지 않은 건물이 단 한개라도 있으면 이 건물은 일단 넘어간 뒤 다음 while로 인해 도착했을 때에 다시 시도한다.

### 의견
시간이 가장 소모되는 부분은 `건축을 제일 먼저 할 수 있는 건물은 무엇인가?`에 관한 것이다. 만일 건축 시간에 따라 (n-1), (n-2), (n-3).... 2 1 0 순서대로 건축을 할 수 있다면 while문과 for문에 의해 각 while 스텝마다 다른 모든 건축물과 비교하게 되므로 O(N^2)의 시간복잡도가 소요된다.

##  성냥개비
https://www.acmicpc.net/problem/3687
### 문제풀이
```python
import sys  
  
T = int(sys.stdin.readline().rstrip())  
all_input = []  
max_input = 0  
for i in range(T):  
    now_input = int(sys.stdin.readline().rstrip())  
    all_input.append(now_input)  
    max_input = max(max_input, now_input) # dp테이블을 최대값까지만 만들기 위해서  
  
# 성냥개비 필요 개수  
# 1  2  3  4  5  6  7  8  9  0  
# 2, 5, 5, 4, 5, 6, 3, 7, 6, 6  
  
dp_min = [0, 0, 1, 7, 4, 2, 6, 8] # ~7까지  
dp_max = [0, 0, 1, 7, 11, 71, 111, 711] # ~7까지  
  
min_diff = [0, 0, 1, 7, 4, 2, 0, 8]  
max_diff = [0, 0, 1, 7, 4, 5, 9, 8]  
for i in range(8, max_input+1):  
    # min value 생성  
  now_min = -1  
  for diff in range(2, 8): # 2~7  
  if i-diff>=2:  
            if now_min==-1:  
                now_min = dp_min[i-diff]*10 + min_diff[diff]  
            else:  
                now_min = min(now_min, dp_min[i-diff]*10 + min_diff[diff])  
    dp_min.append(now_min)  
    # max value 생성  
  now_max = 0  
  for diff in range(2, 8): # 2~7  
  if i-diff >= 2:  
            now_max = max(now_max, dp_max[i-diff]*10 + max_diff[diff])  
    dp_max.append(now_max)  
  
# print(dp_min)  
# print(dp_max)  
  
for step in range(T):  
    print("{} {}".format(dp_min[all_input[step]], dp_max[all_input[step]]))
```
일반적인 선형DP의 느낌이 났다 (2*n타일링 문제와 같은 느낌이었다). `dp_min[A]`의 경우 `A개의 성냥개비로 만들 수 있는 가장 작은 숫자 `를 나타내고, `dp_max[B]`는 그 반대의 개념이다. 성냥개비의 개수가 2~7개 만족하므로 dp_min과 dp_max를 처음 7개까지는 채워두고 dp table을 만들기 시작하였다.

### 의견
문제를 보고 가장 먼저 떠오른 생각은 `다른 언어를 사용했다면 최소값 숫자를 숫자가 아니라 string으로 써야겠구나`였다. N이 100까지 가능한데 이를 실제 int값으로 넣기에는 범위가 너무 커지기 때문이다. 하지만 파이썬이었기 때문에 그냥 했다.


##  인구 이동
https://www.acmicpc.net/problem/16234
### 문제풀이
```python
import sys  
from collections import deque  
dir_matrix = ((0,1), (1,0), (0,-1), (-1,0))  
N, L, R = map(int, sys.stdin.readline().rstrip().split())  
map_matrix = []  
for i in range(N):  
    tmp_map = list(map(int, sys.stdin.readline().rstrip().split()))  
    map_matrix.append(tmp_map)  
  
step_counter = 0  
while True:  
    step_counter += 1  
  group_people = [] # 그룹 별 인구수  
  now_group = -1  
  now_group_map = [[-1 for x in range(N)] for y in range(N)]  
    for y in range(N):  
        for x in range(N):  
            if now_group_map[y][x] == -1:  
                now_group += 1  
  now_group_map[y][x] = now_group  
                tmp_deque = deque()  
                tmp_deque.append([y,x])  
                now_group_sum = map_matrix[y][x] # 현재 그룹의 총 인구 수 합  
  now_group_cont = 1 # 현재 그룹의 구역 수  
  while len(tmp_deque) >0:  
                    tmp_elem = tmp_deque.popleft()  
                    for dir_idx in range(4):  
                        tmp_y = tmp_elem[0] + dir_matrix[dir_idx][0]  
                        tmp_x = tmp_elem[1] + dir_matrix[dir_idx][1]  
                        if 0<=tmp_y<N and 0<=tmp_x<N:  
                            if now_group_map[tmp_y][tmp_x] == -1 and L<= abs(map_matrix[tmp_elem[0]][tmp_elem[1]]- map_matrix[tmp_y][tmp_x]) <= R:  
                                now_group_map[tmp_y][tmp_x] = now_group  
                                tmp_deque.append([tmp_y,tmp_x])  
                                now_group_sum += map_matrix[tmp_y][tmp_x]  
                                now_group_cont += 1  
  group_people.append(now_group_sum//now_group_cont)  
    now_moved = False  
 for y in range(N):  
        for x in range(N):  
            # 인구 이동이 있는지 확인  
  now_area_people = group_people[now_group_map[y][x]]  
            if map_matrix[y][x] != now_area_people:  
                now_moved = True  
  map_matrix[y][x] = now_area_people  
    # print("*"*10)  
 # for y in range(N): #     print(map_matrix[y])  if not now_moved:  
        break  
print(step_counter-1)
```
매 스탭마다 벽이 열리는 구역을 묶어 "그룹"으로 만들고, 그 그룹 내 인구를 모두 더하고 구역으로 나누어 평균 인구를 계산한다. 그 인구를 각 구역에 대입한다.
인구를 구역에 대입하는 순간 이전의 인구와 값이 같다면 인구가 변하지 않았다고 판단하고, 모든 구역이 이렇다면 while문을 종료했다.

### 의견
클러스터링 문제는 항상 어떤 식으로 그 그룹에 대한 정보를 유지하고 있느냐가 중요하다고 생각한다. 

##  자물쇠와 열쇠
https://programmers.co.kr/learn/courses/30/lessons/60059
### 문제풀이
```python
def solution(key, lock):  
    key_size = len(key)  
    lock_size = len(lock)  
    return_val = False  
 for dir_change in range(4):  
        for y in range(-1*key_size+1, lock_size):  
            for x in range(-1*key_size+1, lock_size):  
                # key_size의 맨 좌측상단이 존재하는 (y,x)값 (lock 기준)  
  match_flag = True  
 for lock_y in range(lock_size):  
                    for lock_x in range(lock_size):  
                        # (lock_y, lock_x) 좌표에서의 key값과 lock값  
  now_lock_add = lock[lock_y][lock_x]  
                        now_key_add_y = lock_y - y  
                        now_key_add_x = lock_x - x  
                        now_key_add = 0  
  if 0<=now_key_add_y<key_size and 0<=now_key_add_x<key_size:  
                            if dir_change==0:  
                                now_key_add = key[now_key_add_y][now_key_add_x]  
                            elif dir_change==1: # 시계방향 90도  
  now_key_add = key[now_key_add_x][key_size-1-now_key_add_y]  
                            elif dir_change==2: # 시계방향 180도  
  now_key_add = key[key_size-1-now_key_add_y][key_size-1-now_key_add_x]  
                            else: # 시계방향 270도  
  now_key_add = key[key_size-1-now_key_add_x][now_key_add_y]  
                        if now_lock_add + now_key_add != 1:  
                            match_flag = False  
 break if not match_flag:  
                        break  
 if match_flag:  
                    return_val = True  
 break if return_val:  
                break  
 if return_val:  
            break  
 return return_val
```
key와 lock에 대해서 서로 한 칸씩 움직이며 모두 덮게 되는지 확인하는 방식이다. 실제로 key나 lock을 움직이지 않고 좌표값 수치를 통해 계산하였다. `now_lock_add`와 `now_key_add`는 각각 lock의 특정 점의 값과 key의 특정 점의 값을 나타내는데, 둘 중 하나는 1이고 하나는 0이어야 하므로 (lock이 0이라면 자물쇠가 이 부분을 채워야 하므로 1이어야 함, 반대로 자물쇠의 걸쇠 부분이 lock의 평면과 만날 수도 없음) 두 값을 더했을 때 1일 경우만 통과했다.

### 의견
솔직히 이번 주 4문제중에 가장 번거로워 보이는 문제여서 마지막으로 미뤄서 풀었는데, 코드 짜고 한 번에 통과가 돼서 정말 기분이 좋았다. 
