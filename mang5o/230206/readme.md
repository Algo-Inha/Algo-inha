
# Solving﻿  

## 떡 먹는 호랑이
https://www.acmicpc.net/problem/2502
### 문제풀이  
```python  
import sys  
D, K = map(int, sys.stdin.readline().rstrip().split())  
all_days = [[1,0], [0,1]] # Element -> [첫째날 준 떡의 개수, 둘째날 준 떡의 개수]  
while len(all_days) < D:  
    all_days.append([  
        all_days[-1][0]+all_days[-2][0],  
  all_days[-1][1]+all_days[-2][1]  
    ])  
x = all_days[-1] # 수학적으로 보면 x[0]*n + x[1]*m = K 가 된다  
for i in range(1,K):  
    # n이 i일 때 tmp_x1 = x[1]*m  tmp_x1 = K - x[0]*i  
    # tmp_x1 가 x[1]로 나누어 떨어지면 됨  
  if tmp_x1 % x[1] == 0:  
        if 1 <= i <= tmp_x1//x[1]:  
            print(i)  
            print(tmp_x1//x[1])  
            break
```
DP를 활용해 `D` 날에 몇 개의 떡을 줘야하는지 첫째날과 둘째날의 떡 수에 관한 방정식을 만들고, 가능한 상수 조합을 확인하는 작업이다.

### 의견
결과가 여러개가 있을 수 있어서 스페셜저지로 된 문제였던 것 같다. 제공된 TC와도 다른 값이 나와서 이게 맞나 싶었다.


## 꽃길
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
두 꽃이 접했는지 확인할 때, diff_y와 diff_x의 합이 3보다 작으면 접했다고 확인할 수 있으며, 아닐 경우 계산을 진행하며 완전탐색 느낌으로 진행했다.


## 이름
https://www.acmicpc.net/problem/
### 문제풀이  
```python  
import sys  
  
H, W = map(int, sys.stdin.readline().rstrip().split())  
map_input = list(map(int, sys.stdin.readline().rstrip().split()))  
map_matrix = [[1 if idx < i else 0 for idx in range(H)] for i in map_input]  
water_cnt = 0  
for y in range(1, W):  
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
print(water_cnt)
```
검정 블록 우측이 비어있다면, 이 곳에 물이 찰 수 있다. 따라서 모든 검정 블록 우측부터 시작해서 오른쪽으로 이동하며 다른 검정 블록을 만나면, 그 일직선에 물이 찰 수 있다.


## 청소년 상어
https://www.acmicpc.net/problem/19236
### 의견
미리 문제를 풀지못해  문제를 풀지 못했습니다 ㅠ
