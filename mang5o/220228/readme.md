# Solving
## 이항계수
https://www.acmicpc.net/problem/11051
### 문제풀이
```python
# 날먹on (DP x)  
import sys  
N, K = map(int, sys.stdin.readline().rstrip().split())  
if N/2 > float(K):  
    K = N-K  
up_fig = 1  
down_fig = 1  
for i in range(K+1,N+1):  
    up_fig *= i  
for i in range(N-K):  
    down_fig *= i+1  
print((up_fig//down_fig)%10007)
```
### 의견
처음 풀이를 시작할 때엔 2차원 DP테이블을 구현하려고 하였으나, Question이 (n과 k) 여러 쌍으로 들어올 때만 그렇게 두는게 맞다고 생각했다. cpp나 java 등에서도 variable overflow때문에 DP 테이블을 구현하며 10007로 나눌테지만, 파이썬에서의 변수는 최대값이 딱히 정해져있지 않으므로 그냥 팩토리얼대로 직접 구현하였다.

## 연구소 3
https://www.acmicpc.net/problem/17142
### 문제풀이
```python
# time_matrix : 3차원 array (2차원의 MAP 형태에서 Elements가 각 바이러스에 의한 확산속도)  
time_matrix = [[[100000 for i in range(virus_fig)] for j in range(N)] for k in range(N)]  
  
if now_zero_flag:  
    for i in range(len(virus_array)):  
        # 바이러스 하나하나에 의해 몇 시간 만에 퍼지는지에 관해 계산  
  tmp_visited_matrix = [[False for i in range(N)] for j in range(N)]  # deep copy  
  virus_queue = Queue()  
        unactivated_virus_queue = Queue()  
        virus_queue.put(virus_array[i])  
        tmp_visited_matrix[virus_array[i][0]][virus_array[i][1]] = True  
  time_matrix[virus_array[i][0]][virus_array[i][1]][i] = 0  
  now_step = 0  
  while virus_queue.qsize() != 0:  
            now_step += 1  
  tmp_virus_len = virus_queue.qsize()  
            for j in range(tmp_virus_len):  
                tmp_virus_elem = virus_queue.get()  
                for dir_elem in range(4):  
                    tmp_y = tmp_virus_elem[0] + dir_mat[dir_elem][0]  
                    tmp_x = tmp_virus_elem[1] + dir_mat[dir_elem][1]  
                    if 0 <= tmp_y < N and 0 <= tmp_x < N:  
                        if not tmp_visited_matrix[tmp_y][tmp_x]:  
                            if orig_map_matrix[tmp_y][tmp_x] == 0 or orig_map_matrix[tmp_y][tmp_x] == 2:  
                                virus_queue.put((tmp_y, tmp_x))  
                                tmp_visited_matrix[tmp_y][tmp_x] = True  
  time_matrix[tmp_y][tmp_x][i] = now_step
```
(후략)

`itertools.combination`을 사용해 바이러스의 경우의 수 대로 map을 만들어보고 각 map의 최대값을 구하는 식으로 진행하였으나, 다행히도 타임아웃이 발생하여 다시 구현하였다.
각 위치에 바이러스 위치 하나하나로 인한 감염 시간을 기록하고, combination에 따라 그 감염시간 리스트 중 최소값만을 취하는 식으로 진행하였다.

### 의견
생각보다 문제를 이해 못해서 시간을 쓰는 일이 좀 있었는데, `빈 칸이 바이러스로 꽉차는 시간`을 구하는 문제였는데, 바이러스가 들어가지 않은 `2(input)`을 빈칸으로 두고 풀어서 숫자가 조금씩 다르게 출력되었던 이슈가 있었다.
프로그래밍 적으로도 변수 이름이 실제 사용하는 단어와 혼동하지 않도록 하는 것이 중요한데, 문제에서 언급한 `빈칸`을 `0(input)`이 아니라 실제 빈칸으로 생각해서 생긴 문제였다. 문제를 잘 읽지 않은 내 잘못이라고 생각하지만, 문제에서 이를 깔끔하게 알려주지 않은 것도 사실이라고 생각한다.

## 마법사 상어와 파이어볼
https://www.acmicpc.net/problem/20056
### 문제풀이
```python
N, M, K = map(int, sys.stdin.readline().rstrip().split())  
map_matrix = [[list() for i in range(N)] for j in range(N)]  
for i in range(M):  
    tmp_r, tmp_c, tmp_m, tmp_s, tmp_d = map(int, sys.stdin.readline().rstrip().split())  
    tmp_r -= 1  
  tmp_c -= 1  
  map_matrix[tmp_r][tmp_c].append([tmp_m, tmp_s, tmp_d, 0])
  ```
input을 통해 `map_matrix`를 구현하고 시작하였다.
```
스탭 시작  
1. d 방향대로 이동  
 - idx(3)값인 step과 현재 스탭이 같을 경우만 이동  
 - 이동시에 step을 ++2. 같은 칸에 여러개가 존재할 경우  
 4방향으로 나누어 그 칸에 다시 append
 ```
문제풀이의 방향은 위와 같이 진행하였다. (코드가 생각보다 길어서 여기엔 첨부하지 않음)

### 의견
처음 진행할 때엔 `map_matrix`를 구현하지 않고 단순히 list만 활용하여 진행하려고 하였다. 이렇게 진행하였을 때에 `파이어볼`이 수가 많을 수록 리스트 내에서 같은 좌표의 볼 여부 확인에 대해서 `O(n^2)`의 시간복잡도가 형성되어 너무 느리다고 판단하였다.
문제 조건에서 N이 생각보다 작았으므로 `map_matrix`를 구현하였고, 각 원소를 리스트로 활용하여 풀이하였다.

## 메뉴 리뉴얼
https://programmers.co.kr/learn/courses/30/lessons/72411
### 문제풀이
```python
import itertools  
def solution(orders, course):  
    order_dict = [dict() for i in range(len(course))]  
    for i in orders:  
    # 진짜 악질인게 주문 order는 오름차순이 아님  
    # 그 부분도 잡아줘야함
  now_orders = []  
        for j in i:  
            now_orders.append(j)  
        now_orders.sort()  
        now_text = ""  
  for j in now_orders:  
            now_text += j  
        for j in range(len(course)):  
            # 각 주문에 대해서 조합의 경우를 뽑아 dict에 주문 횟수와 함께 저장  
  now_combination = itertools.combinations(now_text,course[j])  
            for nc in now_combination:  
                tmp_order = ""  
  for ncc in nc:  
                    tmp_order += ncc  
                if tmp_order in order_dict[j]:  
                    order_dict[j][tmp_order] += 1  
  else:  
                    order_dict[j][tmp_order] = 1  
  max_arr = [0 for i in range(len(course))]  
    for i in range(len(course)):  
        for j in order_dict[i].keys():  
            if max_arr[i] < order_dict[i][j]:  
                max_arr[i] = order_dict[i][j]  
  
  
    all_courses = []  
    for i in range(len(course)):  
        for j in order_dict[i].keys():  
            if order_dict[i][j] == max_arr[i] and order_dict[i][j]>1:  
                all_courses.append(j)  
    all_courses.sort()  
    return all_courses
```

### 의견
주석에서도 설명했듯이 주문은 오름차순으로 들어오지 않기 때문에 각 주문에 대해서 오름차순 정렬이 필요하다. 또한 각 주문을 `itertools.combination`을 통해 조합으로 나누어 경우의 수를 계산하였고, 해당 경우의 수는 `dictionary`를 활용하였다.

## 순위검색
https://programmers.co.kr/learn/courses/30/lessons/72412
### 문제풀이
```python
import bisect  
def solution(info, query):  
    answer = []  
    # cpp,java,python  : 123  
 # backend,frontend : 12 # junior,senior    : 12 # chicken,pizza    : 12  info_dict = {  
        "cbjc": [], "cbjp": [], "cbsc": [], "cbsp": [],  
  "cfjc": [], "cfjp": [], "cfsc": [], "cfsp": [],  
  "jbjc": [], "jbjp": [], "jbsc": [], "jbsp": [],  
  "jfjc": [], "jfjp": [], "jfsc": [], "jfsp": [],  
  "pbjc": [], "pbjp": [], "pbsc": [], "pbsp": [],  
  "pfjc": [], "pfjp": [], "pfsc": [], "pfsp": []  
    }  
    check_list = (  
        ('c', 'j', 'p'),  
  ('b', 'f'),  
  ('j', 's'),  
  ('c', 'p')  
    )
```
 `info_dict`를 보면 모든 경우에 맞게 `dictionary`를 선언한 것을 볼 수 있는데, 각 value는 해당 조건의 점수의 값을 가지는 list이다.
```python
for i in info:  
    now_key = ""  
  tmp_elem = i.split()  
    for j in range(4):  
        now_key += tmp_elem[j][0]  
    info_dict[now_key].append(-1*int(tmp_elem[4]))  
for i in info_dict.keys():  
    info_dict[i].sort(reverse=False)
```
각 list에 점수를 넣고 이를 `bisect function`을 사용하기 위해 정렬해둔다.

```python
for qr in query:  
    tmp_qr = qr.split()  
    tmp_key = [[" "],[],[],[],[]]  
    qr_elem = [tmp_qr[0], tmp_qr[2], tmp_qr[4], tmp_qr[6]]  
    for i in range(4):  
        if qr_elem[i][0] == '-':  
            for j in range(len(check_list[i])):  
                for k in range(len(tmp_key[i])):  
                    tmp_key[i+1].append(tmp_key[i][k]+check_list[i][j])  
        else:  
            for j in range(len(tmp_key[i])):  
                tmp_key[i + 1].append(tmp_key[i][j]+qr_elem[i][0])  
  
    now_answer = 0  
  for key in tmp_key[4]:  
        now_key = key.lstrip()  
        # 이부분의 이진탐색으로 인해 효율성 통과함  
  # 사용법 정리해두기  
  now_answer += bisect.bisect_right(info_dict[now_key],-1*int(tmp_qr[7]))  
       answer.append(now_answer)  
return answer
```
들어온 조건에 의해 dictionary의 list에 접근하게 되는데, 여기서 input 점수보다 높은 점수의 수를 `bisect_right`를 통해 빠르게 계산하였다.

### 의견
한 input에 대해서 여러번의 쿼리가 나오기 때문에 find 작업에서의 효율성이 중요했던 것 같다. 파이썬 이진검색에 대해서 확인하는 좋은 기회가 되었다.

## k진수에서 소수 개수 구하기
https://programmers.co.kr/learn/courses/30/lessons/92335
### 문제풀이
```python
import math  
def solution(n, k):  
    answer = 0  
  ref_n = ""  
  now_n = n  
    while now_n != 0:  
        ref_n = str(now_n % k) + ref_n  
        now_n = int(math.floor(now_n / k))  
    ref_n = ref_n.split("0")  
    now_fig = {}  
    for i in ref_n:  
        if len(i)>0:  
            now_figure = int(i)  
            if now_figure > 1:  
                if now_figure in now_fig:  
                    now_fig[now_figure] += 1  
  else:  
                    now_fig[now_figure] = 1  
  for i in now_fig.keys():  
        tmp_key = i  
        prime_flag = True  
 for j in range(math.ceil(math.sqrt(tmp_key)+1)):  
            if j <= 1:  
                continue  
 if j == i:  
                break  
 elif tmp_key % j == 0:  
                prime_flag = False  
 break if prime_flag:  
            answer += now_fig[tmp_key]  
  
    return answer
```

### 의견
일단 문제를 확인하면 0을 기준으로 `split`을 한 뒤, 각 원소가 소수인지 확인하면 되는 문제였다. 다만 `십진법으로 볼 때에 소수`라는 조건을 처음에 잘못 해석하여 답이 틀리게 나왔지만, 바로 수정하였다.
