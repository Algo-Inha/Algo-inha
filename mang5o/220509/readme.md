# Solving﻿
##  개똥벌레
https://www.acmicpc.net/problem/3020
### 문제풀이
```python
import sys  
N, H = map(int, sys.stdin.readline().rstrip().split())  
all_disable = []  
for i in range(N):  
    all_disable.append(int(sys.stdin.readline().rstrip()))  
all_map_up = [0 for x in range(H)]  
all_map_down = [0 for x in range(H)]  
for i in range(N):  
    if i%2 == 0:  
        all_map_up[H - 1 - (all_disable[i]-1)] += 1  
  else:  
        all_map_down[H - 1 - (all_disable[i]-1)] += 1  
  
for i in range(H-1):  
    all_map_down[i+1] += all_map_down[i]  
    all_map_up[i+1] += all_map_up[i]  
  
all_map = [all_map_up[y] + all_map_down[H-y-1] for y in range(H)]  
# print(all_map)  
  
min_val = 999999999  
min_pos = 0  
for i in range(H):  
    if min_val > all_map[i]:  
        min_val = all_map[i]  
        min_pos = 1  
  elif min_val == all_map[i]:  
        min_pos += 1  
  
print("{} {}".format(min_val, min_pos))
```
처음엔 종유석의 길이만큼 for문을 돌며 각각 값을 1씩 더해주는 식으로 진행했는데, 이 for문의 방식이 생각보다 느려서 타임아웃이 났다. 따라서 
```python
for i in range(H-1):  
    all_map_down[i+1] += all_map_down[i]  
    all_map_up[i+1] += all_map_up[i]
```
과 같이 누적의 개념으로 값을 계산하였다.


##  꽃길
https://www.acmicpc.net/problem/14620
### 문제풀이
```python
import sys  
N = int(sys.stdin.readline().rstrip())  
all_map = []  
for i in range(N):  
    all_map.append(list(map(int, sys.stdin.readline().rstrip().split())))  
all_added = [[all_map[y][x] + all_map[y - 1][x] + all_map[y][x - 1] + all_map[y + 1][x] + all_map[y][x + 1]  
              for x in range(1, N - 1)] for y in range(1, N - 1)]  
  
all_case = (N - 2) ** 2  
min_cost = -1  
for flower_1 in range(all_case - 4):  
    for flower_2 in range(flower_1 + 2, all_case - 2):  
        for flower_3 in range(flower_2 + 2, all_case):  
            flower_1_yx = [flower_1 % (N-2), flower_1 // (N-2)]  
            flower_2_yx = [flower_2 % (N-2), flower_2 // (N-2)]  
            flower_3_yx = [flower_3 % (N-2), flower_3 // (N-2)]  
            if abs(flower_1_yx[0] - flower_2_yx[0]) + abs(flower_1_yx[1] - flower_2_yx[1]) < 3:  
                continue  
 elif abs(flower_1_yx[0] - flower_3_yx[0]) + abs(flower_1_yx[1] - flower_3_yx[1]) < 3:  
                continue  
 elif abs(flower_3_yx[0] - flower_2_yx[0]) + abs(flower_3_yx[1] - flower_2_yx[1]) < 3:  
                continue  
 else:  
                all_cost = 0  
  all_cost += all_added[flower_1_yx[0]][flower_1_yx[1]] + \  
                            all_added[flower_2_yx[0]][flower_2_yx[1]] + \  
                            all_added[flower_3_yx[0]][flower_3_yx[1]]  
                if min_cost==-1:  
                    min_cost = all_cost  
                else:  
                    min_cost = min(min_cost, all_cost)  
print(min_cost)
```
완전탐색 느낌으로 문제풀이를 진행하였다. 다만 flower_1부터 flower_3이 최소 3칸은 떨어져야 하기 때문에 최대한 경우의 수를 줄이고자 range선언에서 조금씩 범위를 축소시켰다.
매번 5칸의 값을 더하는 작업이 귀찮아서 모든 칸에 대해 주변 칸의 값을 더해서 넣어줬고, 꽃이 가장자리에 중심을 잡을 수 없기 때문에 가장자리도 1칸씩 날려주었다.



##  톱니바퀴
https://www.acmicpc.net/problem/14891
### 문제풀이
```python
import sys  
all_map = []  
for i in range(4):  
    tmp_map = sys.stdin.readline().rstrip()  
    tmp_list = []  
    for j in range(8):  
        tmp_list.append(int(tmp_map[j]))  
    all_map.append(tmp_list)  
N = int(sys.stdin.readline().rstrip())  
all_rotate = []  
for i in range(N):  
    all_rotate.append(list(map(int, sys.stdin.readline().rstrip().split())))  
  
left_right = [[6,2],[6,2],[6,2],[6,2]]  
  
for i in range(N):  
    # print("*"*10)  
  start_gear = all_rotate[i][0]-1  
  clockwise = all_rotate[i][1]  
    tmp_rotate = [999,999,999,999]  
    tmp_rotate[start_gear] = clockwise  
    for j in range(start_gear):  
        now_gear = start_gear-j-1  
  # print("now_gear1 : {}".format(now_gear))  
  if all_map[now_gear][left_right[now_gear][1]] != all_map[now_gear + 1][left_right[now_gear+1][0]]:  
            tmp_rotate[now_gear] = tmp_rotate[now_gear+1] * (-1)  
        else:  
            tmp_rotate[now_gear] = 0  
  for j in range(start_gear+1, 4):  
        now_gear = j  
        # print("now_gear2 : {}".format(now_gear))  
  if all_map[now_gear][left_right[now_gear][0]] != all_map[now_gear-1][left_right[now_gear-1][1]]:  
            tmp_rotate[now_gear] = tmp_rotate[now_gear - 1] * (-1)  
        else:  
            tmp_rotate[now_gear] = 0  
  for j in range(4):  
        left_right[j][0] -= tmp_rotate[j]  
        left_right[j][1] -= tmp_rotate[j]  
        left_right[j][0] = left_right[j][0] % 8  
  left_right[j][1] = left_right[j][1] % 8  
  # print(tmp_rotate)  
  
score = 0  
if all_map[0][(left_right[0][0]+2)%8] == 1:  
    score += 1  
if all_map[1][(left_right[1][0]+2)%8] == 1:  
    score += 2  
if all_map[2][(left_right[2][0]+2)%8] == 1:  
    score += 4  
if all_map[3][(left_right[3][0]+2)%8] == 1:  
    score += 8  
  
print(score)
```
실제로 톱니바퀴를 돌리진 않았고. 현재 톱니바퀴의 왼쪽과 오른쪽이 몇번 인덱스인지 가지고 계산을 진행하였다.

### 의견
순차적으로 회전을 계산하는 부분 때문에 조금 코드가 길어지긴 했으나, 그래도 나름 재미있는 구현이었다.

##  타겟 넘버
https://programmers.co.kr/learn/courses/30/lessons/43165
### 문제풀이
```python
def solution(numbers, target):  
    all_case = [[] for x in range(len(numbers) + 1)]  
    all_case[0] = [0]  
    for i in range(len(numbers)):  
        next_case = []  
        for cases in all_case[i]:  
            next_case.append(cases + numbers[i])  
            next_case.append(cases - numbers[i])  
        all_case[i+1] = next_case  
    target_n = 0  
  for i in range(len(all_case[-1])):  
        if all_case[-1][i] == target:  
            target_n += 1  
  return target_n
```
### 의견
numbers를 K번까지 써서 만들 수 있는 수를 all_case[K+1]에 집어넣는 방식을 반복하여 진행하였다.
