
# Solving﻿  

## 전깃줄
https://www.acmicpc.net/problem/2565
### 문제풀이  
```python  
import sys  
N = int(sys.stdin.readline().rstrip())  
all_line = []  
for i in range(N):  
    all_line.append(list(map(int, sys.stdin.readline().rstrip().split())))  
all_line.sort(key=lambda x:x[0])  
all_second = []  
for i in range(N):  
    all_second.append(all_line[i][1])  
  
LIS_DP = [1]  
LIS_list = [all_second[0]]  
max_ans = 0  
for i in range(1, N):  
    LIS_max = 0  
  for j in range(i):  
        if all_second[j] < all_second[i]:  
            LIS_max = max(LIS_max, LIS_DP[j])  
    LIS_DP.append(LIS_max + 1)  
    max_ans = max(LIS_max + 1, max_ans)  
  
print(N-max_ans)
```
LIS (최장 증가 부분수열) 풀이법

### 의견
LIS라는 풀이법을 처음 접하게 된 문제였다. O(nlogn)과 O(n^2)의 방법이 있다고는 하지만, 전봇대의 블록이 생각보다 최대 개수가 적어서 O(n^2) 로 풀었다.
풀이법은 검색했을 때에 나오는 여러 블로그를 참고했으며, 시간이 될때 O(nlogn)의 방식도 익혀서 구현해봐야겠다.


## 테트리스
https://www.acmicpc.net/problem/3019
### 문제풀이  
```python  
C, P = map(int, sys.stdin.readline().split())  
all_height = list(map(int, sys.stdin.readline().split()))  
all_case = 0  
  
if P == 1:  
    # block 1 vertical  
  all_case += C  
  
    # block 1 horizontal  
  for i in range(C - 3):  
        if all_height[i] == all_height[i + 1] == all_height[i + 2] == all_height[i + 3]:  
            all_case += 1  
elif P == 2:  
    # block 2  
  for i in range(C - 1):  
        if all_height[i] == all_height[i + 1]:  
            all_case += 1  
elif P == 3:  
    # block 3 vertical  
  for i in range(C - 1):  
        if all_height[i] == all_height[i + 1]+1:  
            all_case += 1  
  
  # block 3 horizontal  
  for i in range(C - 2):  
        if all_height[i] + 1 == all_height[i + 1] + 1 == all_height[i + 2]:  
            all_case += 1  
elif P == 4:  
    # block 4 vertical  
  for i in range(C - 1):  
        if all_height[i]+1 == all_height[i + 1]:  
            all_case += 1  
  
  # block 4 horizontal  
  for i in range(C - 2):  
        if all_height[i] == all_height[i + 1] + 1 == all_height[i + 2] + 1:  
            all_case += 1  
elif P == 5:  
    # block 5 ㅗ  
  for i in range(C - 2):  
        if all_height[i] == all_height[i + 1] == all_height[i + 2]:  
            all_case += 1  
  
  # block 5 ㅓ  
  for i in range(C - 1):  
        if all_height[i] + 1 == all_height[i + 1]:  
            all_case += 1  
  
  # block 5 ㅜ  
  for i in range(C - 2):  
        if all_height[i] == all_height[i + 1] + 1 == all_height[i + 2]:  
            all_case += 1  
  
  # block 5 ㅏ  
  for i in range(C - 1):  
        if all_height[i] == all_height[i + 1] + 1:  
            all_case += 1  
elif P == 6:  
    # block 6 degree 0 (clockwise)  
  for i in range(C - 2):  
        if all_height[i] == all_height[i + 1] == all_height[i + 2]:  
            all_case += 1  
  
  # block 6 degree 90 (clockwise)  
  for i in range(C - 1):  
        if all_height[i] == all_height[i + 1]:  
            all_case += 1  
  
  # block 6 degree 180 (clockwise)  
  for i in range(C - 2):  
        if all_height[i] + 1 == all_height[i + 1] == all_height[i + 2]:  
            all_case += 1  
  
  # block 6 degree 270 (clockwise)  
  for i in range(C - 1):  
        if all_height[i] == all_height[i + 1] + 2:  
            all_case += 1  
else:  
    # block 7 degree 0 (clockwise)  
  for i in range(C - 2):  
        if all_height[i] == all_height[i + 1] == all_height[i + 2]:  
            all_case += 1  
  
  # block 7 degree 90 (clockwise)  
  for i in range(C - 1):  
        if all_height[i]+2 == all_height[i + 1]:  
            all_case += 1  
  
  # block 7 degree 180 (clockwise)  
  for i in range(C - 2):  
        if all_height[i] == all_height[i + 1] == all_height[i + 2] + 1:  
            all_case += 1  
  
  # block 7 degree 270 (clockwise)  
  for i in range(C - 1):  
        if all_height[i] == all_height[i + 1]:  
            all_case += 1  
  
print(all_case)
```
각 블록이 들어맞을 때의 경우의 수를 구하였다. 생각보다 매우 지저분하지만 풀이를 제출하는 데에는 문제가 없었다.

### 의견
(으악!)

## 연산자 끼워넣기
https://www.acmicpc.net/problem/14888
### 문제풀이  
```python  
import sys  
from collections import deque  
  
N = int(sys.stdin.readline())  
figures = list(map(int, sys.stdin.readline().split()))  
operators = list(map(int, sys.stdin.readline().split()))  
  
all_queue = deque()  
all_queue.append([[], operators])  
  
min_cost = 1000000000  
max_cost = -1000000000  
while all_queue:  
    tmp_elem = all_queue.popleft()  
    if len(tmp_elem[0]) == N - 1:  
        now_cost = figures[0]  
        for i in range(N - 1):  
            if tmp_elem[0][i] == 0:  
                now_cost += figures[i + 1]  
            elif tmp_elem[0][i] == 1:  
                now_cost -= figures[i + 1]  
            elif tmp_elem[0][i] == 2:  
                now_cost *= figures[i + 1]  
            else:  
                now_plus = [True if now_cost >= 0 else False, True if figures[i + 1] >= 0 else False]  
                now_figs = [now_cost if now_plus[0] else -1*now_cost, figures[i+1] if now_plus[1] else -1*figures[i+1]]  
                now_cost = now_figs[0] // now_figs[1]  
                if not now_plus[0]: now_cost *= -1  
  if not now_plus[1]: now_cost *= -1  
  min_cost = min(min_cost, now_cost)  
        max_cost = max(max_cost, now_cost)  
        continue  
 for oper_idx in range(4):  
        if tmp_elem[1][oper_idx] > 0:  
            new_elem = [[tmp_elem[0][x] for x in range(len(tmp_elem[0]))], [tmp_elem[1][x] for x in range(4)]]  
            new_elem[0].append(oper_idx)  
            new_elem[1][oper_idx] -= 1  
  all_queue.append(new_elem)  
  
print(max_cost)  
print(min_cost)
```
백트래킹을 이용한 경우를 구한 뒤, 해당 경우에 대해 직접 계산을 진행하는 문제였다.

### 의견
사실 연산자의 우선순위가 없이 앞에서부터 계산한다는 내용이 오히려 약간 아쉬웠다. 파이썬에서의 `eval`을 사용하면 해당 부분은 바로 풀리기 때문이다.


## 두 박스
https://www.acmicpc.net/problem/15973
### 문제풀이  
```python  
import sys  
position_1 = list(map(int, sys.stdin.readline().split()))  
position_2 = list(map(int, sys.stdin.readline().split()))  
double_position = [max(position_1[0], position_2[0]), max(position_1[1], position_2[1]),  
  min(position_1[2], position_2[2]), min(position_1[3], position_2[3])]  
  
# POINT, LINE, FACE, NULL ("그렇지않고" 조건 활용)  
if double_position[0]==double_position[2] and double_position[1]==double_position[3]:  
    print("POINT")  
elif double_position[0]==double_position[2] and double_position[1] < double_position[3]:  
    print("LINE")  
elif double_position[1]==double_position[3] and double_position[0] < double_position[2]:  
    print("LINE")  
elif double_position[0]<double_position[2] and double_position[1]<double_position[3]:  
    print("FACE")  
else:  
    print("NULL")
```
교집합 범위의 사각형을 구한뒤, 해당 사각형이 어떤 꼴인지를 확인하여 print 해주는 함수이다. 다만 사각형을 구한 뒤에 `x1>x2` 혹은 `y1>y2`같은 경우가 발생한다면 이는 사각형이 형성되지 않은, NULL 의 경우라고 판단할 수 있다.

### 의견
처음에는 실제로 사각형을 2차원배열에 그린 뒤 겹치는 부분의 형태를 판단하려고 했지만, x와 y값의 제한이 말도 안 되게 거대했기 때문에 더 간단한 풀이법으로 풀었다.



## 에너지 모으기
https://www.acmicpc.net/problem/16198
### 문제풀이  
```python  
import sys  
from collections import deque  
  
N = int(sys.stdin.readline())  
marbles = list(map(int, sys.stdin.readline().split()))  
all_queue = deque()  
  
all_queue.append(([0] + [marbles[x] for x in range(N)]))  # + 현재 에너지  
  
max_val = 0  
while all_queue:  
    tmp_elem = all_queue.popleft()  
    if len(tmp_elem) == 3:  
        max_val = max(max_val, tmp_elem[0])  
        continue  
 for i in range(2, len(tmp_elem)-1):  
        new_elem = []  
        for idx in range(len(tmp_elem)):  
            if idx == i:  
                continue  
 else:  
                new_elem.append(tmp_elem[idx])  
        new_elem[0] += new_elem[i-1] * new_elem[i]  
        all_queue.append(new_elem)  
  
print(max_val)
```
백트래킹을 이용한 모든 경우를 구한 뒤, 해당 경우에 대한 Score를 구했다.

