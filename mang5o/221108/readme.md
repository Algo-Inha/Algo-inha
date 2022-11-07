
# Solving﻿  

## 이차원 배열과 연산
https://www.acmicpc.net/problem/17140
### 문제풀이  
```python  
import sys  
  
def sort_arr(ats):  
    new_dict = dict()  
    for i in ats:  
        if i == 0:  
            continue  
 if i in new_dict:  
            new_dict[i] += 1  
  else:  
            new_dict[i] = 1  
  new_list = []  
    for i in new_dict.keys():  
        new_list.append([i, new_dict[i]])  
    new_list.sort(key=lambda x:(x[1], x[0]))  
    return_list = []  
    for elem in new_list:  
        return_list += elem  
    return return_list  
  
  
R, C, K = map(int, sys.stdin.readline().rstrip().split())  
A = [list(map(int, sys.stdin.readline().rstrip().split())) for _ in range(3)]  
  
now_time = 0  
while True:  
    if A[R-1][C-1] == K:  
        break  
 if now_time > 100:  
        now_time = -1  
  break  
  now_time += 1  
  width = len(A[0])  
    height = len(A)  
  
    if width <= height:  
        max_len = 0  
  for y in range(height):  
            A[y] = sort_arr(A[y])  
            max_len = max(max_len, len(A[y]))  
        for y in range(height):  
            if len(A[y]) != max_len:  
                A[y] += [0 for _ in range(max_len - len(A[y]))]  
    else:  
        for x in range(width):  
            new_vertical_arr = []  
            for y in range(height):  
                new_vertical_arr.append(A[y][x])  
            new_vertical_arr = sort_arr(new_vertical_arr)  
            for cnt in range(len(new_vertical_arr) - height):  
                A.append([0 for _ in range(width)])  
            for yy in range(len(new_vertical_arr)):  
                A[yy][x] = new_vertical_arr[yy]  
    for y in range(len(A)):  
        now_y = len(A)-y-1  
  if sum(A[now_y]) == 0:  
            del A[now_y]  
    for x in range(len(A[0])):  
        now_x = len(A[0])-x-1  
  del_flag = True  
 for y in range(len(A)):  
            if A[y][now_x] != 0:  
                del_flag = False  
 break if del_flag:  
            for y in range(len(A)):  
                del A[y][now_x]  
print(now_time)
```
구현에 관한 문제라고 볼 수 있을 것 같다. 매 스탭마다 최대 행의 수나 최대 열의 수를 측정하고 이를 통해 나머지 부분을 0으로 채워넣으며 직사각행렬을 만드는 부분이 생각보다 깔끔하지 않았던 것 같다.

### 의견
답이 몇 개씩 다르게 나와서 틀리는데, 코드상에서 잘못된 부분을 찾아봐야겠다


## 파이프 옮기기 1
https://www.acmicpc.net/problem/17070
### 문제풀이  
```python  
N = int(sys.stdin.readline().rstrip())  
all_matrix = [list(map(int, sys.stdin.readline().rstrip().split())) for _ in range(N)]  
all_dp_table = [[[0, 0, 0] for x in range(N)] for y in range(N)] # 차례대로 오른쪽, 오른쪽아래, 아래 방향으로 옴  
all_dp_table[0][1][0] = 1  
for y in range(N):  
    for x in range(N):  
        if x == 0:  
            continue  
 if all_matrix[y][x] == 1:  
            continue  
  # 오른쪽  
  if x>0: # always true  
  if all_matrix[y][x-1] == 0:  
                all_dp_table[y][x][0] += all_dp_table[y][x-1][0] + all_dp_table[y][x-1][1]  
        # 오른쪽 아래  
  if x>0 and y>0:  
            if all_matrix[y-1][x-1] == 0 and all_matrix[y][x-1] == 0 and all_matrix[y-1][x] == 0:  
                all_dp_table[y][x][1] += all_dp_table[y-1][x-1][0] + all_dp_table[y-1][x-1][1] + all_dp_table[y-1][x-1][2]  
        # 아래  
  if y>0:  
            if all_matrix[y-1][x] == 0:  
                all_dp_table[y][x][2] += all_dp_table[y-1][x][1] + all_dp_table[y-1][x][2]  
print(sum(all_dp_table[N-1][N-1]))
```
N*N*3 의 DP테이블을 사용해 문제를 풀었다. 바로 이전에 어느 방향으로 파이프가 왔는지 확인해야 하기 때문에 이렇게 해두었다. 파이프는 오른쪽 아래 방향으로 이동하기 때문에 인덱스 순서대로 채워도 문제가 없다.

### 의견
DP 중에는 나름 직관적인 문제였던것 같다.


## 사탕 게임
https://www.acmicpc.net/problem/3085
### 문제풀이  
```python  
import sys  
  
N = int(sys.stdin.readline().rstrip())  
all_matrix = [list(sys.stdin.readline().rstrip()) for i in range(N)]  
dir_matrix = (  
    (1,0), (0,1)  
)  
  
max_val = 0  
for y in range(N):  
    for x in range(N):  
        for dir_idx in range(len(dir_matrix)):  
            tmp_y = y + dir_matrix[dir_idx][0]  
            tmp_x = x + dir_matrix[dir_idx][1]  
            if tmp_y == N or tmp_x == N:  
                continue  
 if all_matrix[y][x] != all_matrix[tmp_y][tmp_x]:  
                all_matrix[y][x], all_matrix[tmp_y][tmp_x] = all_matrix[tmp_y][tmp_x], all_matrix[y][x]  
                # Calc Max Val  
  for now_y in range(N): # 가로로 이동하며 체크  
  tmp_val = "-1"  
  tmp_same = 0  
  for now_x in range(N):  
                        if all_matrix[now_y][now_x] == tmp_val:  
                            tmp_same += 1  
  max_val = max(max_val, tmp_same)  
                        else:  
                            tmp_val = all_matrix[now_y][now_x]  
                            tmp_same = 1  
  for now_x in range(N):  
                    tmp_val = "-1"  
  tmp_same = 0  
  for now_y in range(N):  
                        if all_matrix[now_y][now_x] == tmp_val:  
                            tmp_same += 1  
  max_val = max(max_val, tmp_same)  
                        else:  
                            tmp_val = all_matrix[now_y][now_x]  
                            tmp_same = 1  
  all_matrix[y][x], all_matrix[tmp_y][tmp_x] = all_matrix[tmp_y][tmp_x], all_matrix[y][x]  
  
print(max_val)
```
구현 문제이다. 생각보다 모든 경우의 수를 구해도 시간 관계없이 통과했다. 시간을 줄이기 위해 좌표를 돌긴 돌지만 해당 좌표의 우측과 하단만 서로 바꾸었다.



## 오픈채팅방
https://school.programmers.co.kr/learn/courses/30/lessons/42888
### 문제풀이  
```python  
def solution(record):  
    all_log = [record[i].split() for i in range(len(record))]  
    name_map = dict()  
    for i in range(len(record)):  
        if len(all_log[i]) == 3:  
            name_map[all_log[i][1]] = all_log[i][2]  
  
    answer = []  
    for i in range(len(record)):  
        if all_log[i][0] == "Enter":  
            answer.append("{}님이 들어왔습니다.".format(name_map[all_log[i][1]]))  
        elif all_log[i][0] == "Leave":  
            answer.append("{}님이 나갔습니다.".format(name_map[all_log[i][1]]))  
  
  
    return answer
```
dict를 통해 uid와 닉네임을 매칭시켰다. dict에선 value가 덮어씌워질 수 있으며, 효율적이기도 하다.

