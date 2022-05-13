# Solving﻿
##  암호 만들기
https://www.acmicpc.net/problem/1759
### 문제풀이
```python
import sys, itertools  
L, C = map(int, sys.stdin.readline().rstrip().split())  
all_letters = list(map(str, sys.stdin.readline().rstrip().split()))  
all_conso = []  # 자음  
all_vowel = []  # 모음  
for i in range(C):  
    if all_letters[i] == 'a' or all_letters[i] == 'e' \  
            or all_letters[i] == 'i' or all_letters[i] == 'o' or all_letters[i] == 'u':  
        all_vowel.append(all_letters[i])  
    else:  
        all_conso.append(all_letters[i])  
all_cases = []  
for i in range(L-2):  
    now_conso = 2+i  # 최소 2개의 자음  
  now_vowel = L-now_conso # 최소 1개의 모음  
  comb_conso = list(itertools.combinations(all_conso, now_conso))  
    comb_vowel = list(itertools.combinations(all_vowel, now_vowel))  
    for cc in comb_conso:  
        for cv in comb_vowel:  
            now_tmp = list(cc+cv)  
            now_tmp.sort()  
            now_str = ""  
  for ns in now_tmp:  
                now_str += ns  
            all_cases.append(now_str)  
all_cases.sort()  
for ac in all_cases:  
    print(ac)
```
`itertools.combinations`를 사용하여 모음과 자음을 각각 뽑아와서 sorting하는 작업이 들어간 문제이다. 모음1개와 자음2개가 최소 조건이므로, `n`개의 암호라면 `n-1-2`의 경우의 수가 존재한다. 해당 경우를 나누는 부분은 Line 16에 들어가있다.

### 의견
생각보다 Sorting이 비효율적으로 들어가서 뭔가 시간초과가 나지않을까 싶었지만 이 이상으로 더 효율적으로 만들 방식이 생각나지 않았다. 다행히 통과되었다.

##  초콜릿 자르기
https://www.acmicpc.net/problem/2163
### 문제풀이
```python
import sys  
N, M = map(int, sys.stdin.readline().rstrip().split())  
print(N-1 + N*(M-1))
```
### 의견
사실 `최소횟수`를 구하는 문제이기 때문에 알고리즘이 따로 필요한 문제인가 싶긴 했으나, 실제 노트에 이리저리 그려봐도 항상 자르는 경우의 수가 같다는 것을 깨닫고 위와같이 간단하게 나타낼 수 있다는 것을 알았다.
이렇게 간단한 문제가 나오면 종종 숏코딩 탭을 확인하는데, 이 문제 숏코딩탭 `GolfScript` 보니까 진짜 너무 놀라버렸다. (3바이트)

##  보물섬
https://www.acmicpc.net/problem/2589
### 문제풀이
```python
import sys  
from collections import deque  
  
dir_matrix = ((-1, 0), (1, 0), (0, -1), (0, 1))  
H, W = map(int, sys.stdin.readline().rstrip().split())  
all_map = []  # True는 땅  
for i in range(H):  
    tmp_map = sys.stdin.readline().rstrip()  
    tmp_map_list = [(tmp_map[x] == 'L') for x in range(W)]  
    all_map.append(tmp_map_list)  
  
all_max = 0  
for y in range(H):  
    for x in range(W):  
        if all_map[y][x]:  
            tmp_visited = [[False for xx in range(W)] for yy in range(H)]  
            tmp_visited[y][x] = True  
  tmp_deque = deque()  
            tmp_deque.append([y, x, 0])  
            max_distance = 0  
  while len(tmp_deque) > 0:  
                tmp_elem = tmp_deque.popleft()  
                tmp_distance = tmp_elem[2]  
                max_distance = max(max_distance, tmp_distance)  
                for dir_idx in range(4):  
                    tmp_y = tmp_elem[0] + dir_matrix[dir_idx][0]  
                    tmp_x = tmp_elem[1] + dir_matrix[dir_idx][1]  
                    if 0 <= tmp_y < H and 0 <= tmp_x < W:  
                        if not tmp_visited[tmp_y][tmp_x] and all_map[tmp_y][tmp_x]:  
                            tmp_visited[tmp_y][tmp_x] = True  
  tmp_deque.append([tmp_y, tmp_x, tmp_distance + 1])  
            all_max = max(all_max, max_distance)  
  
print(all_max)
```
모든 `(y,x)`에 대해서 BFS로 모든 좌표와의 거리를 구하고, 그 거리의 최댓값을 구하는 간단한 문제였다.
### 의견
처음에 Space complexity를 생각해서 DFS로 했고 거리가 잘못 계산되는 상황이었는데, `거리를 재기 위해 BFS를 사용해야한다`는걸 분명 생각해뒀는데 DFS로 코드를 짜두는 상황이었다. 다시한번 맑은 정신이 중요하다고 생각했다.


##  카드게임
https://www.acmicpc.net/problem/11062
### 문제풀이
```python
all_querys = int(sys.stdin.readline().rstrip())  
all_answer = []  
for query in range(all_querys):  
    cases = int(sys.stdin.readline().rstrip())  
    all_figure = list(map(int, sys.stdin.readline().rstrip().split()))  
    acc_figure = [0]  
  
    now_fig = 0  
  for i in range(cases):  
        now_fig += all_figure[i]  
        acc_figure.append(now_fig)  
    # acc_figure[j+1] - acc_figure[i] => i인덱스부터 j인덱스까지의 합  
  
  dp_table = [[-999 for x in range(cases)] for y in range(cases)]  
    # dp_table[y][x] -> y~x 번째의 카드가 있을때의 시작하는 사람의 최대점  
  
  # 처음엔 i==j, 그다음엔 i+1 == j, 그 다음엔 i+2 == j 순서  
  for idx in range(cases):  
        dp_table[idx][idx] = all_figure[idx]  
    for interval in range(1, cases):  
        for i in range(cases):  
            j = i+interval  
            if j < cases:  
                dp_table[i][j] = max(acc_figure[j+1] - acc_figure[i] - dp_table[i][j-1], acc_figure[j+1] - acc_figure[i] - dp_table[i+1][j])  
  
    all_answer.append(dp_table[0][cases-1])  
  
for aa in all_answer:  
    print(aa)
```
### 의견
처음엔 여러가지 풀이 방법을 생각했었다.
```
1. 완전탐색 (좌, 우의 조합을 통해 모든 경우의 수 구하기)
2. 근우가 뽑는 수를 제외하고 나머지 수의 좌우 최대값을 통해 계속 탐색
```
사실 2번으로 풀면 풀릴거라고 생각했지만, 생각못한 반례가 꽤 많았다. 다행히 Test case에서도 이 알고리즘이 잘못됐다는 것을 시사해주었기 때문에 풀이를 수정하였다.

##  수식 최대화
https://programmers.co.kr/learn/courses/30/lessons/67257
### 문제풀이
```python
case_tuple = (('*','+','-'),('*','-','+'),('+','*','-'),('+','-','*'),('-','*','+'),('-','+','*'))  
def solution(expression):  
    ret_max = 0  
  expr = expression.replace("+","a+a").replace("-","a-a").replace("*","a*a").split("a")  
    nums = []  
    operators = []  
    for i in range(len(expr)):  
        if i%2==0:  
            nums.append(int(expr[i]))  
        else:  
            operators.append(expr[i])  
    num_len = len(nums)  # 같은 연산자 끼리는 앞의 우선순위가 더 높음  
  oper_len = len(operators)  # 같은 연산자 끼리는 앞의 우선순위가 더 높음  
  nums.reverse()  
    operators.reverse()  
    for case in range(6):  
        tmp_nums = [nums[x] for x in range(num_len)]  
        tmp_opers = [operators[x] for x in range(oper_len)]  
        for oper_3 in range(3):  
            tmp_len_tmp_opers = len(tmp_opers)  
            for op_idx in range(tmp_len_tmp_opers):  
                if tmp_opers[tmp_len_tmp_opers - op_idx - 1] == case_tuple[case][oper_3]:  
                    tmp_nums[tmp_len_tmp_opers - op_idx - 1] = eval(  
                        "(" + str(tmp_nums[tmp_len_tmp_opers - op_idx]) + ")"  
  + tmp_opers[tmp_len_tmp_opers - op_idx - 1]  
                        + "(" + str(tmp_nums[tmp_len_tmp_opers - op_idx - 1]) + ")"  
  )  
                    del tmp_nums[tmp_len_tmp_opers - op_idx]  
                    del tmp_opers[tmp_len_tmp_opers - op_idx - 1]  
        ret_max = max(ret_max, abs(tmp_nums[0]))  
    return ret_max
```
사실 모든 우선순위의 경우는 6개밖에 안 되기 때문에 모든 경우에 따라 계산을 진행한 결과이다. 처음 시작할 때 operator과 operand를 나누어 각 행렬에 넣어두고, 계산을 하며 각 계산을 통한 del작업을 진행했다.
`eval(str)` 함수는 str의 수식을 계산해주는 함수인데, 이를 통해 +,-,*를 경우로 따로 나누어 직접 계산해주지 않아도 편하게 계산되는 부분이 있다. (`Line 26-30`)

### 의견
사실 이 풀이에서 정말 날먹 풀이가 가능할까 싶었었는데, 실제 파이썬에서의 계산 우선순위를 바꾸는 걸 찾아봤다. 실제 계산순위를 조절할 수 있다면 이를 조절한 뒤, eval 함수를 진행만 해보면 바로 끝나버리는 문제이기 때문이다.
언어적 특성상 operator 우선순위는 바꾸지 못한다는 검색결과를 보고 아깝지만 각 경우에 대해 직접 계산하였다.



