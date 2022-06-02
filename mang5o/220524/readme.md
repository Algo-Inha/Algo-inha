# Solving﻿
##  적록색약
https://www.acmicpc.net/problem/10026
### 문제풀이
```python
import sys  
from collections import deque  
  
dir_matrix = ((0, -1), (0, 1), (1, 0), (-1, 0))  
N = int(sys.stdin.readline().rstrip())  
all_map = []  
all_RG_map = []  
for i in range(N):  
    tmp_str = sys.stdin.readline().rstrip()  
    tmp_list = []  # 일반 행렬  
  tmp_RG_list = []  # 적록색약 행렬  
  for j in range(N):  
        if tmp_str[j] == 'R':  
            tmp_list.append(0)  
            tmp_RG_list.append(0)  
        elif tmp_str[j] == 'G':  
            tmp_list.append(1)  
            tmp_RG_list.append(0)  
        else:  
            tmp_list.append(2)  
            tmp_RG_list.append(1)  
    all_map.append(tmp_list)  
    all_RG_map.append(tmp_RG_list)  
  
visited_list = [[False for x in range(N)] for y in range(N)]  
visited_RG_list = [[False for x in range(N)] for y in range(N)]  
  
normal_group = 0  
RG_group = 0  
for y in range(N):  
    for x in range(N):  
        if not visited_list[y][x]:  
            tmp_deque = deque()  
            tmp_deque.append([y, x])  
            now_color = all_map[y][x]  
            visited_list[y][x] = True  
  normal_group += 1  
  while tmp_deque:  
                tmp_elem = tmp_deque.pop()  
                for dir_idx in range(4):  
                    tmp_y = tmp_elem[0] + dir_matrix[dir_idx][0]  
                    tmp_x = tmp_elem[1] + dir_matrix[dir_idx][1]  
                    if 0<=tmp_y<N and 0<=tmp_x<N:  
                        if not visited_list[tmp_y][tmp_x] and all_map[tmp_y][tmp_x] == now_color:  
                            visited_list[tmp_y][tmp_x] = True  
  tmp_deque.append([tmp_y, tmp_x])  
  
for y in range(N):  
    for x in range(N):  
        if not visited_RG_list[y][x]:  
            tmp_deque = deque()  
            tmp_deque.append([y, x])  
            now_color = all_RG_map[y][x]  
            visited_RG_list[y][x] = True  
  RG_group += 1  
  while tmp_deque:  
                tmp_elem = tmp_deque.pop()  
                for dir_idx in range(4):  
                    tmp_y = tmp_elem[0] + dir_matrix[dir_idx][0]  
                    tmp_x = tmp_elem[1] + dir_matrix[dir_idx][1]  
                    if 0<=tmp_y<N and 0<=tmp_x<N:  
                        if not visited_RG_list[tmp_y][tmp_x] and all_RG_map[tmp_y][tmp_x] == now_color:  
                            visited_RG_list[tmp_y][tmp_x] = True  
  tmp_deque.append([tmp_y, tmp_x])  
  
print("{} {}".format(normal_group,RG_group))
```
### 의견
간단한 탐색 문제였으나, BFS를 두 번 실행하는 과정이 생각보다 매우 지저분해 보였다. 지금 코드상에서는 `visited_list`와 `visited_RG_list`로 나누어서 진행했는데, `visited_list`의 0번 인덱스와 1번 인덱스에 각각 matrix를 저장한다면 훨씬 보기 깔끔했을 것 같다.

##  로봇청소기
https://www.acmicpc.net/problem/14503
### 문제풀이
```python
import sys  
  
dir_matrix = ((-1, 0), (0, 1), (1, 0), (0, -1))  # 북 동 남 서  
N, M = map(int, sys.stdin.readline().rstrip().split())  
R, C, dir_idx = map(int, sys.stdin.readline().rstrip().split())  
all_map = []  
all_map_cleaned = [[False for x in range(M)] for y in range(N)]  
for i in range(N):  
    all_map.append(list(map(int, sys.stdin.readline().rstrip().split())))  
  
start_ptr = [R, C, dir_idx, 0]  # 현재 행, 열, 방향, 청소한 칸 수  
# 좌표에 관한 설명이 없지만 그래도 TC로 파악 가능  
while True:  
    # print(start_ptr)  
 # 현재 위치를 청소한다.  
  if not all_map_cleaned[start_ptr[0]][start_ptr[1]]:  
        all_map_cleaned[start_ptr[0]][start_ptr[1]] = True  
  start_ptr[3] += 1  
  # 현재 위치에서 다음을 반복하면서 인접한 칸을 탐색한다.  
  now_2a_step = 0  
  while True:  
        left_idx = (start_ptr[2] - 1) % 4  
  left_y = start_ptr[0] + dir_matrix[left_idx][0]  
        left_x = start_ptr[1] + dir_matrix[left_idx][1]  
        # 현재 위치의 바로 왼쪽에 아직 청소하지 않은 빈 공간이 존재한다면  
  if all_map[left_y][left_x] == 0 and not all_map_cleaned[left_y][left_x]:  
            # 왼쪽 방향으로 회전한 다음 한 칸을 전진하고 1번으로 돌아간다  
  now_2a_step = 0  
  start_ptr = [left_y, left_x, left_idx, start_ptr[3]]  
            break  
 else:  
            now_2a_step += 1  
  start_ptr[2] = left_idx  
            if now_2a_step == 4:  
                break  
 if now_2a_step == 4:  
        back_idx = (start_ptr[2] - 2) % 4  
  back_y = start_ptr[0] + dir_matrix[back_idx][0]  
        back_x = start_ptr[1] + dir_matrix[back_idx][1]  
        if all_map[back_y][back_x] == 1:  # 바로 뒤쪽이 벽이라면  
  break  
 else:  # 그렇지 않다면  
  start_ptr[0] = back_y  
            start_ptr[1] = back_x  
    # print(now_2a_step)  
  
print(start_ptr[3])
```
### 의견
구현 문제에선 위와같이 주석으로 각 부분에 해당하는 구현 부분을 써놓는 것 만으로도 훨씬 풀이가 빨라진다는 것을 느끼고, 귀찮더라도 결과적으로 도움이 되는 일이기 때문에 진행하고자 이런 식으로 주석을 달아놓았다.

##  구명보트
https://programmers.co.kr/learn/courses/30/lessons/42885
### 문제풀이
```python
import bisect  
def solution(people, limit):  
    people.sort()  # 오름차순 정렬  
  now_return = 0  
  while len(people) > 0:  
        if len(people) > 1:  
            if people[0] + people[1] > limit:  
                now_return += len(people)  
                break  
  tmp_people = people.pop()  
        if len(people) == 0:  
            now_return += 1  
  break  
 elif tmp_people == limit:  
            now_return += 1  
  else:  
            max_val = limit - tmp_people  
            bisect_left_idx = bisect.bisect_left(people, max_val)  
            if bisect_left_idx == len(people):  
                people.pop()  
                now_return += 1  
  elif people[bisect_left_idx] == max_val:  
                del people[bisect_left_idx]  
                now_return += 1  
  else:  
                if bisect_left_idx == 0:  
                    now_return += 1  
  else:  
                    del people[bisect_left_idx - 1]  
                    now_return += 1  
  
  return now_return
```
### 의견
Python에 대해서 time limit이 너무 불리하게 잡혀있다는 생각을 했다. 아무리 더 빠른 풀이를 생각하려고 해도 안되는 상황이어서 질문 게시판을 확인해봤지만 여기서 말해준 부분이 아래 부분이었다.
```python
if people[0] + people[1] > limit:  
    now_return += len(people)  
    break
```
(정렬된) 맨 앞 2명의 무게의 합이 limit보다 크다면 남은 사람들은 모두 보트에 1명씩 타야하므로 이를 한번에 처리해주는 코드였다. 이는 전체적으로 사람의 무게가 높은 test case에 대해서는 더 유리하게 작용할 수 있으나, 그렇지 않는 case에 대해서는 오히려 합연산을 매번 해주고 비교하기 때문에 더 느려지는 결과를 초래할 수 있다. 하지만 이 문제의 test case에는 유효하였고, 효율성에서 60 -> 75점으로 올라갔다.
하지만 이는 특정 test case에 대해서만 유효한 처리이고, 특정 case에선 더 느린 결과를 초래할 수 있다. 이를 증명하는 부분은 아래 부분이다.
```python
if people[-1] + people[-2] < limit:  
    now_return += len(people)//2 + len(people)%2  
    break
```
만일 가장 무거운 사람 2명의 합이 limit보다 작을 경우, 모든 사람들은 보트에 2명씩 탈 수 있으며 이로 인해 한번에 계산할 수 있는 코드이다. 이 원리 또한 위 block과 같으며, 반대의 경우에 대해서 시간을 압축하는 방식이다. 하지만 해당 코드를 추가한 뒤에 효율성은 오히려 점수가 낮아졌으며, 결과적으로 아래와 같은 생각을 해볼 수 있다.

특정 환경에서만 실행시간이 줄어들도록 설계된 코드는 사용하지 못 하는 코드는 아니라고 생각한다. 상용 모델에서도 실제 계산되는 값이 어떠한 경향성을 가지는지 파악한다면 이를 통해 해당 값들에 대해서 효율성을 높이는 과정이 크게 문제될 것은 없기 때문이다. 다만 코딩테스트에서 위와 같은 코드로 특정 test case에 대해서만 효율을 높인다면, 이는 특별히 도움될 것 같지 않다는 생각이다.

프로그래머스 문제를 풀더라도 정확도와 효율성이 모두 만점이 나오지 않으면 오답이라고 생각하고 계속 풀이하려고 해보는 사람이지만, 해당 문제는 정확도에는 문제가 없었지면 효율성이 만점은 아닌 상태이다(90점). 다른 이들의 풀이를 공유하는 스터디가 이럴 때에 도움이 되는 부분이니 다른 풀이도 보고 내가 놓친 부분이 있었는지 다시한번 고려해 볼 생각이다.

##  문자열 압축
https://programmers.co.kr/learn/courses/30/lessons/60057
### 문제풀이
```python
def solution(s):  
    s_len = len(s)  
    min_str = 9999999999  
  min_string = ""  
  for i in range(s_len):  
        all_matrix = []  
        start_ptr = 0  
  while True:  
            end_idx = start_ptr + i  
            if end_idx > s_len:  
                if start_ptr != s_len:  
                    all_matrix.append(s[start_ptr:])  
                break  
 else:  
                all_matrix.append(s[start_ptr:end_idx+1])  
                start_ptr += i + 1  
  for del_idx in range(len(all_matrix)):  
            tmp_idx = len(all_matrix)-del_idx-1  
  if len(all_matrix[tmp_idx]) == 0:  
                del all_matrix[tmp_idx]  
            else:  
                break  
  
  all_str = ""  
  tmp_str = ""  
  tmp_num = 0  
  for mat_idx in range(len(all_matrix)):  
            if all_matrix[mat_idx] != tmp_str:  
                if tmp_num > 0:  
                    if tmp_num > 1:  
                        all_str += str(tmp_num) + tmp_str  
                    else:  
                        all_str += tmp_str  
                tmp_str = all_matrix[mat_idx]  
                tmp_num = 1  
  else:  
                tmp_num += 1  
  if tmp_num > 1:  
            all_str += str(tmp_num) + tmp_str  
        else:  
            all_str += tmp_str  
        if len(all_str) < min_str:  
            min_str = len(all_str)  
            min_string = all_str  
    # print(min_string)  
  return min_str
```
### 의견
인덱스별 접근이 필요한 문제여서 파이썬이었음에도 불구하고 약간 쉽게 풀이하지 못한 것이 아쉽긴 하지만, 그래도 문제 자체가 복잡하지 않아 나름 깔끔하게 푼 문제인 것 같다.

##  테트로미노
https://www.acmicpc.net/problem/14500
### 의견
월요일(22.05.30)에 기말고사 시험을 본 뒤 다음날인 오늘이 스터디날이어서 급하게 문제를 다 풀어보려 했으나 해당 문제가 생각보다 복잡해서 아직 풀이를 만들지 못 했다. 다음 주 모임 이전에 이 문제를 같이 풀어보는 게 좋을 것 같다.
