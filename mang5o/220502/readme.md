# Solving﻿
##  멀티탭 스케줄링
https://www.acmicpc.net/problem/1700
### 문제풀이
```python
import sys  
N, K = map(int, sys.stdin.readline().rstrip().split())  
all_schedule = list(map(int, sys.stdin.readline().rstrip().split()))  
schedule_map = dict()  
  
max_device = 0  
min_device = 100  
for idx in range(K):  
    max_device = max(all_schedule[idx], max_device)  
    min_device = min(all_schedule[idx], min_device)  
max_device -= min_device - 1  
for schedule in range(K):  
    all_schedule[schedule] -= min_device  
# 0번 device 부터 max_device 번 까지의 deviceall_schedule_diff = []  
for i in range(K-1):  
    now_start = i  
    now_added = False  
 for j in range(i+1, K):  
        if all_schedule[i] == all_schedule[j]:  
            all_schedule_diff.append([all_schedule[i], j-1])  
            now_added = True  
 break if not now_added:  
        all_schedule_diff.append([all_schedule[i], 999])  
all_schedule_diff.append([all_schedule[-1], 999])  
# print(all_schedule_diff)  
all_multitab = [False for i in range(max_device)] # 멀티탭 철자가 이게 맞나  
now_multitab = []  
now_multitab_with_diff = []  
change_fig = 0  
for i in range(K):  
    # print("\n\n}}")  
  tmp_multitab = [now_multitab[x]+min_device for x in range(len(now_multitab))]  
    tmp_multitab.append([all_schedule[i] + min_device])  
    # print(tmp_multitab)  
  if all_schedule[i] in now_multitab:  
        # 실수했던 부분  
  now_idx = 0  
  for sdx in range(len(now_multitab)):  
            if now_multitab[sdx] == all_schedule[i]:  
                now_idx = sdx  
                break  
  now_multitab_with_diff[sdx][1] = all_schedule_diff[i][1]  
        continue  
 else:  
        for idx in range(len(now_multitab_with_diff)):  
            now_multitab_with_diff[idx][1] -= 1  
  if len(now_multitab) < N:  
            now_multitab.append(all_schedule[i])  
            now_multitab_with_diff.append([all_schedule[i], all_schedule_diff[i][1]])  
            all_multitab[all_schedule[i]] = True  
 else:  
            now_longest_device = -1 # 뺄 장비  
  now_longest_slot = -1 # 뺄 콘센트 번호  
  now_longest_val = -1  
  for now_div in range(N):  
                if now_multitab_with_diff[now_div][1] > now_longest_val:  
                    now_longest_device = now_multitab[now_div]  
                    now_longest_slot = now_div  
                    now_longest_val = now_multitab_with_diff[now_div][1]  
            # print("뺄 장비, 뺄 콘센트 : {}, {}".format(now_longest_device, now_longest_slot))  all_multitab[now_longest_device] = False  
  all_multitab[all_schedule[i]] = True  
  now_multitab[now_longest_slot] = all_schedule_diff[i][0]  
            now_multitab_with_diff[now_longest_slot] = all_schedule_diff[i]  
            # print("changed >>")  
  change_fig += 1  
print(change_fig)
```
문제 해결의 핵심은 `가장 이후에 쓰이는 장치에 관한 콘센트를 빼는 것`의 반복이다. 콘센트가 꽉 차있을 때, 다른 장치가 들어와서 콘센트를 빼야한다면 꽂혀있는 콘센트 중 `가장 나중에 사용하게 되는 장치`부터 빼는 것이다.
문제 풀이에 대해서 실수했던 부분은 Line 41부터 진행되는 아래의 부분인데
```python
for sdx in range(len(now_multitab)):  
    if now_multitab[sdx] == all_schedule[i]:  
        now_idx = sdx  
        break
```
문제 풀이에 대해서 `all_schedule_diff`라는 array에서 해당 인덱스에서 얼마나 이후에 그 장치가 쓰이는지 저장하는 변수로 활용을 한 시점에 `만약 이미 장치가 꽂혀있다면 넘어가는 부분`에서 실수를 했다. 그냥 지나가더라도 꽂혀있는 장치들의 `얼마나 이후에 쓰이는지`를 저장한 변수를 1씩 낮춰야 하는데 (시간이 1스텝 넘어가므로) 이를 하지 않고 계속 진행하여 조금씩 답이 다르게 나왔었다.

### 의견
원론적으로 이 풀이가 유효한지 처음엔 확답을 지을 수 없었다. 맨 처음에도 이 방법으로 풀고난 뒤, 위의 오류를 알아채지 못하고 `bj-1700-old.py`의 방법마냥 완전탐색을 진행했는데, 완전탐색은 시간초과로 인해 다시 이 풀이로 돌아왔다.
첫 째로 느낀 의문은, 만일 콘센트가 비어있는 상황이라면 무조건 빈 슬롯에 장치를 꽂는게 맞는 것인지에 관한 내용이다. 계속 생각해본 바로는 `어차피 슬롯이 비어있을 때 무언가를 빼고 장치를 꽂는 행위`는 `나중에 슬롯이 차있을 때에 장치를 빼는 행위`와 `뽑는 행위`의 횟수가 동일하게 작용할 것이기 때문에 빈 슬롯에 장치를 꽂는게 최솟값이 될 수 있다고 생각했다. 이 말은 `콘센트가 비어있을 지라도 이미 있는 장치를 빼고 다른 장치를 꽂는 행위`도 최솟값이 될 수 있으나, 최솟값 중에는 콘센트가 비어있으면 거기에 장치를 먼저 채워넣는 경우가 존재하게 된다.
두 번째로 느낀 의문은, `가장 오래 뒤에 쓰일 장치를 뽑는것이 항상 옳은가?`이다. 가장 오래 쓰이지만 빈도수가 가장 많은 장치를 만들고, 가장 빨리 쓰이지만 빈도수가 가장 적은 장치를 만들어 반례를 만들어보려 했으나 이 풀이가 맞다는 것을 다시 한번 확인하는 일이었다.

##  최대공약수
https://www.acmicpc.net/problem/2824
### 문제풀이
```python
import sys  
N = int(sys.stdin.readline().rstrip())  
N_list = list(map(int, sys.stdin.readline().rstrip().split()))  
M = int(sys.stdin.readline().rstrip())  
M_list = list(map(int, sys.stdin.readline().rstrip().split()))  
  
A = 1  
B = 1  
for i in N_list:  
    A *= i  
for j in M_list:  
    B *= j  
  
while B>0:  
    mod = A % B  
    A = B  
    B = mod  
  
A = str(A)  
if len(A)>9:  
    A = A[-9:]  
print(A)
```
`에라스토테네스의 체`를 사용한 풀이법이다. 마지막엔 결과를 문자열로 바꾸어 길이를 가지고 자르는 작업을 진행했다.

### 의견
솔직히 input이 수의 그룹으로 되어있어 그 원소를 곱해버리지 않고 결과를 도출해보고 싶었지만, 각 원소에 대해 소인수분해를 진행하는 과정이 생각보다 시간이 많이 소비되는 상황이어서 그 풀이방법은 버리게 되었다. 파이썬이 아닐 경우 N과 M의 수를 모두 곱해버리면 자료형 크기 때문에 overflow가 발생할 것 같기도 하지만 파이썬이라서 별로 신경쓰지 않았다.


##  문제이름
문제주소
### 문제풀이

### 의견


##  배열 돌리기
https://www.acmicpc.net/problem/16926
### 문제풀이
```python
import sys  
N, M, R = map(int, sys.stdin.readline().rstrip().split())  
all_map = []  
for i in range(N):  
    tmp_line = list(map(int, sys.stdin.readline().rstrip().split()))  
    all_map.append(tmp_line)  
  
for rotate_idx in range(R):  
    start_y = 0  
  end_y = N-1  
  start_x = 0  
  end_x = M-1  
  while True:  
        # Rotate  
  left_top = all_map[start_y][start_x]  
        for dir_idx in range(4):  
            # now rotate to [start_y, start_x, end_y, end_x]  
  if dir_idx == 0:  
                for tmp_x in range(start_x, end_x):  
                    all_map[start_y][tmp_x] = all_map[start_y][tmp_x + 1]  
            elif dir_idx == 1:  
                for tmp_y in range(start_y, end_y):  
                    all_map[tmp_y][end_x] = all_map[tmp_y + 1][end_x]  
            elif dir_idx == 2:  
                for tmp_x in range(end_x-start_x):  
                    tmp_tmp_x = end_x - tmp_x  
                    all_map[end_y][tmp_tmp_x] = all_map[end_y][tmp_tmp_x-1]  
            else:  
                for tmp_y in range(end_y-start_y):  
                    tmp_tmp_y = end_y - tmp_y  
                    all_map[tmp_tmp_y][start_x] = all_map[tmp_tmp_y-1][start_x]  
        all_map[start_y + 1][start_x] = left_top  
        # move cursor  
  start_y += 1  
  end_y   -= 1  
  start_x += 1  
  end_x   -= 1  
  if start_y>=end_y or start_x>=end_x:  
            break  
  
for y in range(N):  
    tmp_str = ""  
  for x in range(M):  
        tmp_str += str(all_map[y][x])  
        if x != M-1:  
            tmp_str += " "  
  print(tmp_str)
```
### 의견
저번주에 사용했던 행렬 돌리기를 사용하고 싶어서 조금 가져왔다. 해당 문제처럼 테두리만 돌리는 작업을 진행하며 그 테두리를 점점 작게 만드는 과정을 통해 사각영역 전체를 뒤집을 수 있었다.

##  상어 중학교
https://www.acmicpc.net/problem/21609
### 문제풀이
```python
import sys  
from collections import deque  
  
dir_matrix = ((1, 0), (0, 1), (-1, 0), (0, -1))  
  
N, M = map(int, sys.stdin.readline().rstrip().split())  
all_map = []  # 빈 칸은 -2for y in range(N):  
    all_map.append(list(map(int, sys.stdin.readline().rstrip().split())))  
  
all_score = 0  
  
while True:  
  
    max_block_size = 0  
  max_yx = [0, 0]  
    max_color = 0  
  max_rainbow_block = 0  
  visited_map = [[False for x in range(N)] for y in range(N)]  
  
    for y in range(N):  # 기준블록 : [y,x]  for x in range(N): # 이거때문에 4번을 틀렸다... N을 M으로 써서  
  if all_map[y][x] > 0 and not visited_map[y][x]:  # 일반 블록이 무조건 하나는 있어야 하므로 시작점은 일반블록  
  now_deque = deque()  
                visited_map[y][x] = True  
  now_color = all_map[y][x]  
                now_block_size = 1  
  now_deque.append([y, x])  
                now_rainbow_block = 0  
  while len(now_deque) > 0:  
                    now_elem = now_deque.pop()  
                    for dir_idx in range(4):  
                        tmp_y = now_elem[0] + dir_matrix[dir_idx][0]  
                        tmp_x = now_elem[1] + dir_matrix[dir_idx][1]  
                        if 0 <= tmp_y < N and 0 <= tmp_x < N:  
                            if not visited_map[tmp_y][tmp_x]:  
                                if all_map[tmp_y][tmp_x] == now_color:  
                                    visited_map[tmp_y][tmp_x] = True  
  now_block_size += 1  
  now_deque.append([tmp_y,tmp_x])  
                                elif all_map[tmp_y][tmp_x] == 0:  
                                    visited_map[tmp_y][tmp_x] = True  
  now_block_size += 1  
  now_deque.append([tmp_y, tmp_x])  
                                    now_rainbow_block += 1  
  
  if now_block_size > max_block_size:  # 크기가 가장 큰 블록  
  max_block_size = now_block_size  
                    max_yx = [y, x]  
                    max_color = now_color  
                    max_rainbow_block = now_rainbow_block  
                elif now_block_size == max_block_size:  
                    if now_rainbow_block > max_rainbow_block:  # 포함된 무지개 블록 수가 많은 블록  
  max_block_size = now_block_size  
                        max_yx = [y, x]  
                        max_color = now_color  
                        max_rainbow_block = now_rainbow_block  
                    elif now_rainbow_block == max_rainbow_block:  
                        if max_yx[0] < y:  # 행이 가장 큰 것  
  max_block_size = now_block_size  
                            max_yx = [y, x]  
                            max_color = now_color  
                            max_rainbow_block = now_rainbow_block  
                        elif max_yx[0] == y:  
                            if max_yx[1] < x: # 열이 가장 큰 것  
  max_block_size = now_block_size  
                                max_yx = [y, x]  
                                max_color = now_color  
                                max_rainbow_block = now_rainbow_block  
                # 무지개 블록 visited 초기화  
  for tmp_tmp_y in range(N):  
                    for tmp_tmp_x in range(N):  
                        if all_map[tmp_tmp_y][tmp_tmp_x] == 0:  
                            visited_map[tmp_tmp_y][tmp_tmp_x] = False  
  
 if max_block_size < 2:  # 블록이 만들어지지 않았을 때  
  break  
  
  # 시작점이 max_yx인 block을 제거하기  
  now_deque = deque()  
    now_deque.append(max_yx)  
    all_map[max_yx[0]][max_yx[1]] = -2  
  visited_map = [[False for x in range(N)] for y in range(N)]  
    visited_map[max_yx[0]][max_yx[1]] = True  
 while len(now_deque) > 0:  
        tmp_elem = now_deque.popleft()  
        for dir_idx in range(4):  
            tmp_y = tmp_elem[0] + dir_matrix[dir_idx][0]  
            tmp_x = tmp_elem[1] + dir_matrix[dir_idx][1]  
            if 0 <= tmp_y < N and 0 <= tmp_x < N:  
                if not visited_map[tmp_y][tmp_x]:  
                    if all_map[tmp_y][tmp_x] == max_color or all_map[tmp_y][tmp_x] == 0:  
                        all_map[tmp_y][tmp_x] = -2  
  visited_map[tmp_y][tmp_x] = True  
  now_deque.append([tmp_y, tmp_x])  
    # 점수 추가  
  all_score += max_block_size ** 2  
  # print(max_block_size ** 2)  
  
 # all_map 중력적용  
  for y in range(N):  
        tmp_y = N - y - 1 # 최대한 아래에 있는 블록부터 이동해야하기 때문에  
  for x in range(N):  
            if all_map[tmp_y][x] > -1:  # 검은 블록이거나 빈 칸이 아닐 경우  
  tmp_tmp_y = tmp_y  
                while True:  
                    tmp_tmp_y += 1  
  if tmp_tmp_y == N:  
                        tmp_tmp_y -= 1  
  break  
 elif all_map[tmp_tmp_y][x] != -2:  
                        tmp_tmp_y -= 1  
  break  
 if tmp_tmp_y != tmp_y:  
                    all_map[tmp_tmp_y][x] = all_map[tmp_y][x]  
                    all_map[tmp_y][x] = -2  
  
  # all_map 회전  
  all_rotated_map = [[all_map[x][N-y-1] for x in range(N)] for y in range(N)]  
    all_map = all_rotated_map  
  
    # all_map 다시 중력 적용  
  for y in range(N):  
        tmp_y = N - y - 1 # 최대한 아래에 있는 블록부터 이동해야하기 때문에  
  for x in range(N):  
            if all_map[tmp_y][x] > -1:  # 검은 블록이거나 빈 칸이 아닐 경우  
  tmp_tmp_y = tmp_y  
                while True:  
                    tmp_tmp_y += 1  
  if tmp_tmp_y == N:  
                        tmp_tmp_y -= 1  
  break  
 elif all_map[tmp_tmp_y][x] != -2:  
                        tmp_tmp_y -= 1  
  break  
 if tmp_tmp_y != tmp_y:  
                    all_map[tmp_tmp_y][x] = all_map[tmp_y][x]  
                    all_map[tmp_y][x] = -2  
  
print(all_score)
```

### 의견
문제 풀이에 대해서 계속 오답이 나왔는데, 다른 사람들은 오답이 `무지개 블록에 대해 visited를 초기화 하지 않아서` 오답이라고 했지만, 나는 처음 풀이부터 그 부분은 제대로 진행해서 오답의 이유를 잘 몰랐다. 실제로 오픈테케에서는 모두 맞아서 이유를 계속 생각해봤지만, 이후에 확인한 것은 
```python
for y in range(N):  # 기준블록 : [y,x]
  for x in range(N): # 이거때문에 4번을 틀렸다... N을 M으로 써서
```
이 부분이 문제였다.  N과 M이 너무 비슷하게 생기기도 했고 다른 문제에선 N,M이 일반적인 행렬의 행과 열을 나타내는 값이었기 때문에 왜 그런지 찾기 어려웠던 것 같다. 피곤할 때엔 코테를 풀지 말고, 코테를 풀어야 하면 상쾌한 상태를 만들어놔야겠다.

##  주차 요금 계산
https://programmers.co.kr/learn/courses/30/lessons/92341
### 문제풀이
```python
def solution(fees, records):  
    cost_list = dict()  
    now_car = dict()  
    for record in records:  
        record_splited = record.split()  
        if record_splited[2]=="IN":  
            if not record_splited[1] in now_car:  
                now_car[record_splited[1]] = record_splited[0]  
        else:  
            if record_splited[1] in now_car:  
                now_time = record_splited[0].split(":")  
                start_time = now_car[record_splited[1]].split(":")  
                start_min = int(start_time[0])*60 + int(start_time[1])  
                end_min = int(now_time[0])*60 + int(now_time[1])  
                min_interval = end_min - start_min  
                now_car.pop(record_splited[1])  
                if record_splited[1] in cost_list:  
                    cost_list[record_splited[1]] = cost_list[record_splited[1]] + min_interval  
                else:  
                    cost_list[record_splited[1]] = min_interval  
  
    out_records = []  
    for rec in now_car.keys():  
        out_records.append("23:59 {} OUT".format(rec))  
  
    for record in out_records:  
        record_splited = record.split()  
        now_time = record_splited[0].split(":")  
        start_time = now_car[record_splited[1]].split(":")  
        start_min = int(start_time[0]) * 60 + int(start_time[1])  
        end_min = int(now_time[0]) * 60 + int(now_time[1])  
        min_interval = end_min - start_min  
        now_car.pop(record_splited[1])  
        if record_splited[1] in cost_list:  
            cost_list[record_splited[1]] = cost_list[record_splited[1]] + min_interval  
        else:  
            cost_list[record_splited[1]] = min_interval  
  
    costs = []  
    for i in cost_list.keys():  
        now_key = i  
        now_time = cost_list[now_key]  
  
        tmp_cost = fees[1]  
        if now_time > fees[0]:  
            tmp_cost += (math.ceil((now_time-fees[0])/fees[2]))*fees[3]  
        costs.append([now_key,tmp_cost])  
    costs.sort(key=lambda x : x[0])  
  
    all_cost = []  
    for i in costs:  
        all_cost.append(i[1])  
  
    return all_cost
```
`now_car`에는 현재 들어가있는 차를 확인할 수 있으며, 27 Line까지 query에 관한 계산을 진행하고, 쿼리에 관한 작동이 끝난 뒤에도 남아이는 차는 해당 부분부터 강제로 쿼리를 집어넣어 주고 진행했다.
그렇기 때문에 31Line부터 42Line은 위의 처리 부분을 그대로 가져왔다.

### 의견
`records는 하루 동안의 입/출차된 기록만 담고 있으며, 입차된 차량이 다음날 출차되는 경우는 입력으로 주어지지 않습니다.` 라는 말이 약간 오해의 소지가 있는데, 입차된 차량이 다음날 출차되는 경우는 입력으로 주어진다. 다만 `record`가 "특정 일자"의 기록이라고 한다면 설명이 아래와 같게 된다.
`records는 특정 날짜의 입/출차된 기록만 담고 있으며, 해당 날짜의 전날 입차된 차량이 특정 날짜에 출차되는 경우는 입력으로 주어지지 않습니다`
이러면 직관적이고 맞는 것 같은데... 그래도 위 내용처럼 생각하고 풀긴 했다.
