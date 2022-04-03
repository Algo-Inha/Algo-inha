# Solving
##  강의실 배정
https://www.acmicpc.net/problem/11000
### 문제풀이
```python
import sys, heapq  
N = int(sys.stdin.readline().rstrip())  
all_case = []  
heapq.heapify(all_case)  
for i in range(N):  
    tmp_case = list(map(int, sys.stdin.readline().rstrip().split()))  
    tmp_elem = tmp_case[0]*10000000000 + tmp_case[1]  
    heapq.heappush(all_case, tmp_elem)  
  
all_classes = []  
heapq.heapify(all_classes)  
while len(all_case)>0:  
    now_fastest = heapq.heappop(all_case)  
    now_start = now_fastest//10000000000  
  now_end = now_fastest % 10000000000  
  
  if len(all_classes) == 0:  
        heapq.heappush(all_classes, now_end)  
    else:  
        now_fastest_class = heapq.heappop(all_classes)  
        if now_fastest_class <= now_start:  
            heapq.heappush(all_classes, now_end)  
        else:  
            heapq.heappush(all_classes, now_end)  
            heapq.heappush(all_classes, now_fastest_class)  
  
print(len(all_classes))
```
코드에서 주요 쟁점 중 하나는 `수업 시작시간을 가지고 오름차순으로 정렬`이며, `같은 시작 시간이라면 종료 시간이 짧은 것이 먼저 오도록 정렬`하는 기능도 필요하다. heapq를 통해 우선순위큐를 만들었으며, 아래와 같은 값을 넣어줌으로서 해결하였다.
`tmp_elem = tmp_case[0]*10000000000 + tmp_case[1]`
이를 다시 원래의 값으로 가져오기 위해 아래와 같이 나누었다.
```
now_fastest = heapq.heappop(all_case)  
now_start = now_fastest//10000000000  
now_end = now_fastest % 10000000000
```
시간 입력의 범위가 10**9 이기 때문에, 시작시간에 곱해주는 수는 이보다 더 커야한다. 

우선순위큐에 위 내용을 모두 넣었다면, 이제 강의실을 위한 우선순위큐를 다시 구현해준다. 여기에선 `강의가 끝나는 시간`만을 가지고 원소로 넣어준다.

모든 수업이 처리될 때 까지 아래와 같은 작업을 반복한다.
```
강의실 우선순위큐 (class_queue)

class_queue에 최소값을 가져온다 (종료시간이 가장 빠른 것)
그 값보다 현재 수업의 시작시간이 빠르면, class_queue에 있는 모든 강의실이 아직 사용중인 것이므로 아래와 같이 진행한다.
1. 현재 뽑아낸 최소값은 다시 큐에 넣는다 (수업이 안 끝난 것)
2. 새로운 강의실을 만든다 (큐에 현재 수업이 끝나는 시간을 넣는다)

만일 class_queue의 최소값이 현재 수업시간보다 빠르면, 그 강의실의 강의는 이미 끝난 것이므로 해당 강의실을 사용하도록 한다.
1. 현재 뽑아낸 최소값은 다시 사용하지 않는다 (수업이 끝났음)
2. 큐에 현재 수업이 끝나는 시간을 넣는다
```
모든 작업이 끝난 뒤 강의실의 개수를 센다

### 의견
Greedy한 완전탐색 문제인줄 알고 시작해보려고 했으나, 최악의 경우엔 강의실을 비교하고 추가하는 과정이 O(n) 이 걸릴것 같아 전체적으로 O(n^2)가 될 느낌이어서 다른 풀이를 고민해보았다.

##  최대 힙
https://www.acmicpc.net/problem/11279
### 문제풀이
```python
import sys, heapq  
N = int(sys.stdin.readline().rstrip())  
pq = []  
heapq.heapify(pq)  
for case in range(N):  
    x = int(sys.stdin.readline().rstrip())  
    if x == 0:  
        if len(pq)==0:  
            print(0)  
        else:  
            print(heapq.heappop(pq)*(-1))  
    else:  
        heapq.heappush(pq, x*(-1))
```
### 의견
생각보다 너무 직관적이고 간단한 문제였다.


##  부분합
https://www.acmicpc.net/problem/1806
### 문제풀이
```python
import sys  
N, S = map(int,sys.stdin.readline().rstrip().split())  
all_arr = list(map(int, sys.stdin.readline().rstrip().split()))  
all_acc = [0] # 누적합 행렬  
all_ptr = 0  
for i in range(N): # 누적합 만들기  
  all_ptr += all_arr[i]  
    all_acc.append(all_ptr)  
# print(all_acc)  
  
start_ptr = 0  
end_ptr = 0  
shortest_interval = N+10 # Maximum  
while True:  
    if all_acc[end_ptr]-all_acc[start_ptr] >= S:  
        shortest_interval = min(shortest_interval, end_ptr-start_ptr)  
        start_ptr += 1  
  else:  
        end_ptr += 1  
  if end_ptr>N:  
        break  
  
if shortest_interval == N+10:  
    print(0)  
else:  
    print(shortest_interval)
```
누적합 행렬을 만든 뒤, 2개의 포인터를 만든다 (시작포인터, 끝포인터). 시작 포인터부터 큰 포인터까지의 합을 `부분 합`이라고 할 때, 이 부분합은 `all_acc[end_ptr] - all_acc[start_ptr]`로 계산할 수 있다. 부분 합이 S보다 크거나 같을 경우 start_ptr를 우측으로 이동시켜 포인터간의 거리를 줄이고, S보다 작을 경우 end_ptr를 우측으로 이동시켜 포인터 간의 거리를 늘린다. 부분 합이 S보다 크거나 같을 경우엔 해당 범위가 조건을 만족하기 때문에 `shortest_interval`과 비교하여 최소값 계산에 사용한다.

### 의견
투 포인터 문제를 처음 풀어봐서 풀이법을 생각하는 데에 하루가 넘게 걸렸던 문제였다. 다만 풀이법을 생각하더라도 다음에 비슷한 문제가 나올 경우가 문제인데, 이 풀이법이 필요한 다른 문제라도 정말 형태가 비슷하게 나올 것 같다는 생각이 들었다.

##  연구소
https://www.acmicpc.net/problem/14502
### 문제풀이
```python
import sys, itertools  
from collections import deque  
  
dir_mat = (  
    (-1,0), (0,1), (1,0), (0,-1)  
)  
  
N, M = map(int, sys.stdin.readline().rstrip().split())  
all_map = []  
for i in range(N):  
    all_map.append(list(map(int, sys.stdin.readline().rstrip().split())))  
  
all_blank = []  
all_virus = []  
for y in range(N):  
    for x in range(M):  
        if all_map[y][x]==0:  
            all_blank.append((y,x))  
        elif all_map[y][x]==2:  
            all_virus.append((y,x))  
  
all_blank_len = len(all_blank)  
all_virus_len = len(all_virus)  
  
all_comb = itertools.combinations([i for i in range(all_blank_len)], 3)  
max_safety = 0  
for ac in all_comb:  
    tmp_queue = deque()  
    for i in range(3): # 임시로 벽 만들기  
  all_map[all_blank[ac[i]][0]][all_blank[ac[i]][1]] = 1  
  for vir in range(all_virus_len): # 바이러스 모두 Queue에 넣어주기  
  tmp_queue.append(all_virus[vir])  
    while len(tmp_queue)>0: # 퍼뜨려주기  
  tmp_vir = tmp_queue.popleft()  
        for dir_idx in range(4):  
            tmp_y = tmp_vir[0] + dir_mat[dir_idx][0]  
            tmp_x = tmp_vir[1] + dir_mat[dir_idx][1]  
            if 0<=tmp_y<N and 0<=tmp_x<M:  
                if all_map[tmp_y][tmp_x] == 0:  
                    tmp_queue.append((tmp_y,tmp_x))  
                    all_map[tmp_y][tmp_x] = 1  
  # 행렬 리셋하면서 안전영역 크기 확인  
  safety = 0  
  for ab in range(all_blank_len):  
        if all_map[all_blank[ab][0]][all_blank[ab][1]] == 0:  
            safety += 1  
  else:  
            all_map[all_blank[ab][0]][all_blank[ab][1]] = 0  
  max_safety = max(max_safety, safety)  
  
  
print(max_safety)
```
완전탐색 문제로 간단히 풀었다. 다른 곳엔 딱히 특이한 부분이 없지만 시간을 줄이기 위한 부분이 여러군데 있는데, 첫 번째로는 `매 경우의 수에 map을 새로 만들지 않는것`이다. 어차피 벽을 지을 공간은 0인 공간 중 3개이므로 맨 처음에 0인 공간의 좌표 리스트를 만들었다. 따라서 바이러스가 퍼지거나 벽을 세우는 등 경우에 따른 프로세스를 진행한 뒤 "처음에 맵 상에서 0이었던 곳"을 다시 0으로 만들어 주는것으로 맵 보존을 진행할 수 있었다. 두 번째는 `안전구역을 세는 법`이다. 위에서 말했듯이 0이었던 곳의 목록을 가지고 초기화를 하는 동시에 초기화하여 시간을 절약했다.

### 의견
아무리 N과 M의 범위가 작다고 해도 설마 완전탐색으로 풀어야하나? 싶었고 실제로 테스트케이스를 굴려보았을 때도 시간이 좀 걸려서 싸했지만 제출해보니 정답이라고 나와 안심이었다. 
