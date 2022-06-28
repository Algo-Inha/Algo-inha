# Solving﻿  
## 절댓값 힙
https://www.acmicpc.net/problem/11286
### 문제풀이  
```python  
N = int(sys.stdin.readline().rstrip())  
all_list = []  
heapq.heapify(all_list)  
heapq_size = 0  
return_list = []  
for i in range(N):  
    tmp_elem = float(sys.stdin.readline().rstrip())  
    if tmp_elem != 0:  
        if tmp_elem > 0:  
            heapq_size += 1  
  heapq.heappush(all_list, tmp_elem + 0.5)  
        else:  
            heapq_size += 1  
  heapq.heappush(all_list, tmp_elem*(-1))  
    else:  
        if heapq_size == 0:  
            return_list.append(0)  
        else:  
            heapq_size += -1  
  smallest = heapq.heappop(all_list)  
            if smallest % 1 == 0.5:  
                return_list.append(int(smallest))  
            else:  
                return_list.append(int(smallest*(-1)))  
for i in return_list:  
    print(i)
```  
Python의 특성상 Float 자료형만 넣을 수 있는 우선순위큐를 사용하여 진행하였다. `절댓값이 가장 작은 값이 여러개일 때는, 가장 작은 수를 출력하고` 라는 구문에서 음수를 뽑아야한다는 것을 알 수 있기 때문에, 양수가 들어올 경우 0.5를 더해주고 음수가 들어올 경우 양수로 바꾸어 그냥 넣어준다. 여기서 `heappop()`을 사용하면 원하는 수를 받으며, 소숫점 밑을 확인하여 음수양수를 구분할 수 있다.

### 의견  
문제에서 말하는 대로 그대로 구현하면 되지만 최소에 관한 정의를 따로 할 수 없는 heapq의 특성상 어떤 식으로 수를 변형시켜 넣어야하는지 생각해봐야하는 문제였던것 같다.

# Solving﻿  
## 줄 서는 방법 
https://programmers.co.kr/learn/courses/30/lessons/12936
### 문제풀이  
```python  
def solution(n, k):  
    fact_table = [(x+1) for x in range(n)]  
    for i in range(n-1):  
        fact_table[i+1] *= fact_table[i]  # Make factorial  
  now_figures = [(x+1) for x in range(n)]  
  
    all_list = []  
    now_fig_idx = k-1  
  fact_table.pop()  
    for i in range(n-1):  
        now_idx = now_fig_idx // fact_table[-i-1]  
        now_fig_idx %= fact_table[-i-1]  
        all_list.append(now_figures[now_idx])  
        del now_figures[now_idx]  # 정말 비효율적인 방법  
  all_list += now_figures  
  
    return all_list
```  
팩토리얼로 나누어 몫의 인덱스를 하나씩 리스트에 넣는 식으로 반복하여 구현하였다. `4개의 숫자로 이루어진 행렬`의 경우 `(4-1)!` , 즉 6개의 인덱스 마냥 맨 앞의 수가 바뀌는데 이를 통해 팩토리얼 결과값을 operand로 두고 몫을 계산한 뒤 몫에 해당하는 인덱스의 수를 빼와서 앞에서 부터 채워넣는 식이다. 

### 의견  
전체 리스트에서 하나씩 빼서 return을 위한 리스트를 채우는 방식인데, 여기서 어쩔 수 없이 del 기능을 사용하였다. 사실상 O(n)의 복잡도를 가지므로 시간적으로 매우 불리하지만 이를 사용하지 않고 구현해도 동일하게 느릴 것 같아 채용하였고, 사용해도 문제 없이 통과했다.


# Solving﻿  
## 입국심사 
https://programmers.co.kr/learn/courses/30/lessons/43238
### 문제풀이  
```python  
def get_count(tmp_time):  
    # print("get_count : {}".format(tmp_time))  
  if tmp_time in all_count_dict:  
        return all_count_dict[tmp_time]  
    else:  
        tmp_cnt = 0  
  for pers in all_times:  
            tmp_cnt += tmp_time//pers  
        all_count_dict[tmp_time] = tmp_cnt  
        return tmp_cnt  
  
def solution(n, times):  
    global all_times  
    global all_count_dict  
    all_times = [times[x] for x in range(len(times))]  
    all_count_dict = dict()  
  
    # 좌측 우측 boundary 설정  
  min_fig = 0  
  tmp_max_fig = max(times) * n  
    now_add_fig = 1  
  max_fig = 1  
  while max_fig < tmp_max_fig:  
        max_fig += now_add_fig  
        now_add_fig *= 2  
  # 이분탐색  
  while True:  
        mid_fig = (min_fig + max_fig)//2  
  now_count = get_count(mid_fig)  
        if mid_fig == min_fig or mid_fig == max_fig:  
            break  
 if now_count < n:  
            min_fig = mid_fig  
        else:  
            max_fig = mid_fig  
    return_fig = min_fig  
    for i in range(min_fig-1, max_fig+1):  
        if get_count(i) < n:  
            if get_count(i+1) >= n:  
                return_fig = i+1  
  break  
 return return_fig
```  
get_count 함수는 주어진 시간에 몇 명의 사람이 심사를 받을 수 있는지에 관한 return을 넘겨주는 함수이다. 다만 solution함수 밑 부분에서 for문을 통해 get_count가 중복된 time에 대해 호출되는 부분이 있어서 한번 호출한 값은 dict에 넣어 다시 호출할 때에 계산을 하지 않도록 처리하였다.

### 의견  
주어진 time에 대해 몇 명이 심사를 받는지 확인하는 방식은 금방 기억났지만, time에 대한 탐색을 1부터 1씩 늘려가며 진행하였던 것이 시간초과의 주 원인이었다. 이런 식의 이분탐색이 익숙하지 않았기 때문인지는 모르겠지만 time 탐색이 잘못됐었다는 생각보단 이 방식이 틀렸는지 생각하는 시간이 오래 걸렸다.


# Solving﻿  
## 튜플 
https://programmers.co.kr/learn/courses/30/lessons/64065
### 문제풀이  
```python  
def solution(s):
    out = eval(s.replace("{","[").replace("}","]"))  # Parsing
    out.sort(key = lambda x : len(x))
    all_list = []
    for i in out:
        for j in i:
            if not j in all_list:
                all_list.append(j)
    return all_list
```  
파이썬에서만 날먹이 가능한 풀이가 좀 있었는데, 첫 번째는 input을 실제 파이썬 자료형으로 변경하는 `eval`함수였고, 이를 통해 간단하게 string의 input을 바로 list로 바꾸었다. (파이썬의 문법상 list 선언은 대괄호를 사용하기 때문에 replace를 사용하였다)
두 번째로, 입력받은 list들을  길이 기준으로 sorting한 것이다. sorting에 대해 대소관계 (정렬기준)를 손쉽게 설정하였다.


