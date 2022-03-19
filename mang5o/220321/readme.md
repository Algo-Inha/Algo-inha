# Solving
##  달력
https://www.acmicpc.net/problem/20207
### 문제풀이
```python
import sys  
N = int(sys.stdin.readline().rstrip())  
max_day = 0  
schedules = []  
for i in range(N):  
    S, E = map(int, sys.stdin.readline().rstrip().split())  
    max_day = max(E + 1, max_day)  
    schedules.append([S, E])  
schedules.sort(key=lambda x: x[0] * 366 + -x[1] + x[0])  
  
schedule_matrix = [[False for i in range(max_day + 1)] for j in range(N)]  
for sche in schedules:  
    for y in range(N):  
        now_can = True  
 for x in range(sche[0], sche[1] + 1):  
            if schedule_matrix[y][x]:  
                now_can = False  
 break if now_can:  
            for x in range(sche[0], sche[1] + 1):  
                schedule_matrix[y][x] = True  
 break
```
이 부분은 실제 문제에서 제시했던 표(달력)의 모양으로 만들어주는 작업이다. 스케줄을 정렬하는 부분은 `schedules.sort(key=lambda x: x[0] * 366 + -x[1] + x[0])` 처럼 진행햇는데, x[0]에 대해 우선순위를 더 주는 방법으로 `x[1]-x[0]`의 최대치가 365이기 때문에 x[0]에 366을 곱한뒤 sorting하는 방법을 사용하였다.

```python
schedule_matrix = [[False for i in range(max_day + 1)] for j in range(N)]  
for sche in schedules:  
    for y in range(N):  
        now_can = True  
 for x in range(sche[0], sche[1] + 1):  
            if schedule_matrix[y][x]:  
                now_can = False  
 break if now_can:  
            for x in range(sche[0], sche[1] + 1):  
                schedule_matrix[y][x] = True  
 break  
schedule_min_max= []  
for x in range(max_day + 1):  
    min_y = N  
    max_y = 0  
  flag = False  
 for y in range(N):  
        if schedule_matrix[y][x]:  
            min_y = min(min_y, y)  
            max_y = max(max_y, y)  
            flag = True  
 if flag:  
        schedule_min_max.append([min_y,max_y])  
    else:  
        schedule_min_max.append([-1,-1])  
schedule_min_max.append([-1,-1]) # 마지막 점
```
실제로 코팅지가 얼마나 사용되는지 계산하는 곳이다. 이미 달력을 구현했기 때문에, 코팅지는 `연결된 스케줄`에서 계산하면 되며, 코팅지가 모든 스케줄을 덮어야하기 때문에 스케줄끼리의 최대 및 최소값만 가지고 계산하였다.
```python
blocks = []  
now_flag = False  
tmp_block = []  
for x in range(max_day + 1):  
    if schedule_min_max[x][0]==-1:  
        if now_flag:  
            now_flag = False  
  tmp_block.sort()  
            blocks.append(tmp_block)  
            tmp_block = []  
    else:  
        if not now_flag:  
            now_flag = True  
  tmp_block.append(schedule_min_max[x][0])  
            tmp_block.append(schedule_min_max[x][1])  
        else:  
            tmp_block.append(schedule_min_max[x][0])  
            tmp_block.append(schedule_min_max[x][1])  
  
all_area = 0  
for i in range(len(blocks)):  
    all_area += (len(blocks[i])//2) * (blocks[i][-1]-blocks[i][0]+1)
```
최대 및 최소값을 가지고 계싼하는 부분이다.

### 의견
문제를 풀고난 뒤에서야 문제 분류를 봤는데, 구현 및 그리디 알고리즘이라고 표기되어있었다. 스케줄은 달력 내에 `어느곳이든` 있을수 있고 `코팅지의 최소크기`를 구하는 문제였다면 그리디로 풀어야하지만, 이렇게 규칙이 명확할 때에는 단순한 구현으로 문제를 풀 수 있었다.


##  마법사 상어와 비바라기
https://www.acmicpc.net/problem/21610
### 문제풀이
```python
import sys  
  
dir_matrix = ((0, 0), (0, -1), (-1, -1), (-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1))  # 1부터 사용  
cross_matrix = ((-1, -1), (1, 1), (-1, 1), (1, -1))  
N, M = map(int, sys.stdin.readline().rstrip().split())  
map_matrix = []  
mov_matrix = []  
for i in range(N):  
    tmp_line = list(map(int, sys.stdin.readline().rstrip().split()))  
    map_matrix.append(tmp_line)  
for i in range(M):  
    tmp_line = list(map(int, sys.stdin.readline().rstrip().split()))  
    mov_matrix.append(tmp_line)  
  
# 초기 구름 설정  
cloud_mat = [[N - 2, 0], [N - 1, 0], [N - 2, 1], [N - 1, 1]]  
cloud_check = [[False for i in range(N)] for j in range(N)]  
for steps in range(M):  
    now_mov = mov_matrix[steps]  
    # 비내리기  
  for cloud in range(len(cloud_mat)):  
        tmp_y = (cloud_mat[cloud][0] + dir_matrix[now_mov[0]][0] * now_mov[1]) % N  
        tmp_x = (cloud_mat[cloud][1] + dir_matrix[now_mov[0]][1] * now_mov[1]) % N  
        map_matrix[tmp_y][tmp_x] += 1  
  cloud_check[tmp_y][tmp_x] = True  
  # 물복사버그  
  for cloud in range(len(cloud_mat)):  
        tmp_y = (cloud_mat[cloud][0] + dir_matrix[now_mov[0]][0] * now_mov[1]) % N  
        tmp_x = (cloud_mat[cloud][1] + dir_matrix[now_mov[0]][1] * now_mov[1]) % N  
        tmp_add_cnt = 0  
  for dir_idx in range(4):  
            tmp_yy = tmp_y + cross_matrix[dir_idx][0]  
            tmp_xx = tmp_x + cross_matrix[dir_idx][1]  
            if 0<=tmp_yy<N and 0<=tmp_xx<N:  
                if map_matrix[tmp_yy][tmp_xx]>0:  
                    tmp_add_cnt+= 1  
  map_matrix[tmp_y][tmp_x] += tmp_add_cnt  
    # 다음 스탭의 구름위치  
  next_cloud = []  
    for y in range(N):  
         for x in range(N):  
             if map_matrix[y][x]>=2 and not cloud_check[y][x]:  
                next_cloud.append([y,x])  
                map_matrix[y][x] -= 2  
  cloud_check = [[False for i in range(N)] for j in range(N)]  
    cloud_mat = next_cloud  
  
    # print("Now step : {}".format(steps))  
 # for i in range(N): #     print(map_matrix[i])  
all_water = 0  
for y in range(N):  
    for x in range(N):  
        all_water += map_matrix[y][x]  
print(all_water)
```
### 의견
구현이라서 딱히 설명할 부분이 있진 않지만, 구름위치를 어느 시점까지 가지고있는지가 중요했던 문제였던것 같다. 다음 구름 생성에 이전 구름이 관여하기 때문에, shallow copy를 사용하여 임시적인 행렬을 들고 풀었다.


##  더 맵게
https://programmers.co.kr/learn/courses/30/lessons/42626
### 문제풀이
```python
import heapq # 최소값만 계속 확인하기 때문에 heapq 사용  
def solution(scoville, K):  
    heapq.heapify(scoville)  
    now_step = 0  
  mix_flag = False  
 while len(scoville) > 1:  
        now_step += 1  
  first_scov = heapq.heappop(scoville)  
        second_scov = heapq.heappop(scoville)  
        if first_scov>=K:  
            mix_flag = True  
 break  new_scoville = first_scov + second_scov * 2  
  heapq.heappush(scoville, new_scoville)  
    if mix_flag:  
        return now_step-1  
  else:  
        first_scov = heapq.heappop(scoville)  
        if first_scov >= K:  
            return now_step  
        return -1
```

### 의견
맨 처음 푸는 방법은 초기 input을 sort한 뒤 binary search를 사용하여 행렬의 [0] [1] 인덱스를 빼고 다시 넣는 순서대로 진행하였다. 시간초과로 막혔지만, 생각해보니 scoville 행렬에선 무조건 최소값만을 빼는 프로세스였기 때문에, 굳이 list를 활용할 필요가 없다고 생각하여 `heapq`를 사용하였다. Priority Queue와 비슷하게 작동하며, 최소값만을 뽑아내는 데에 좋은 효율을 낸다.

##  불량 사용자
https://programmers.co.kr/learn/courses/30/lessons/64064
### 문제풀이
```python
def solution(user_id, banned_id):  
    user_len = len(user_id)  
    banned_len = len(banned_id)  
  
    match = [[] for i in range(len(banned_id))]  
    for i in range(banned_len):  
        now_banned_id = banned_id[i]  
        for j in range(user_len):  
            now_id = user_id[j]  
            if len(now_id) == len(now_banned_id):  
                tmp_match = True  
 for idx in range(len(now_id)):  
                    if now_banned_id[idx] != "*":  
                        if now_banned_id[idx] != now_id[idx]:  
                            tmp_match = False  
 break if tmp_match:  
                    match[i].append(j)  
  
    match_len = len(match)  
  
    all_case_deque = deque()  
    all_case_deque.append(set())  
    all_cases = []  
    while len(all_case_deque) > 0:  
        tmp_case = all_case_deque.popleft()  
        if len(tmp_case)<match_len:  
            for ii in range(len(match[len(tmp_case)])):  
                tmp_tmp_case = copy.copy(tmp_case)  
                if not match[len(tmp_case)][ii] in tmp_tmp_case:  
                    tmp_tmp_case.add(match[len(tmp_case)][ii])  
                    all_case_deque.append(tmp_tmp_case)  
        else:  
            set_case = set(tmp_case)  
            if len(set_case) == banned_len:  
                if not set_case in all_cases:  
                    all_cases.append(set(tmp_case))  
  
    return len(all_cases)
```
### 의견
파이썬에 문자열 문제였지만, 생각보다 파이썬의 장점을 활용하지 못했다. 사실상 `*`가 있는 부분은 인덱스별로 예외처리가 진행되는 느낌이기때문에 인덱스 접근이 강제되기 때문이었다.
하지만 그 뒤에 생각해보니 `banned_id`로 들어온 string값에서 *을 regex를 사용할 수 있도록 변경해주면 `re.match`를 사용하여 손쉽게 찾을수 있다고 생각이 들었다.

##  보물상자 비밀번호
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRUN9KfZ8DFAUo&categoryId=AWXRUN9KfZ8DFAUo&categoryType=CODE&&&
### 문제풀이

```python
T = int(input())  
outputs_arr = []  
for step in range(T):  
    N, K = map(int, input().split())  
    now_str = input()  
    for i in range(N//4):  
        now_str += now_str[i]  
    tmp_arr = [now_str[i:i+N//4] for i in range(N)]  
    tmp_arr = list(set(tmp_arr))  
    tmp_arr.sort(reverse=True)  
    now_return = tmp_arr[K-1]  
    now_return_fig = 0  
  for i in range(N//4):  
        now_num = 0  
  if '0'<=now_return[i]<='9':  
            now_num = int(now_return[i])  
        else:  
            if now_return[i]=='A':  
                now_num = 10  
  elif now_return[i]=='B':  
                now_num = 11  
  elif now_return[i]=='C':  
                now_num = 12  
  elif now_return[i]=='D':  
                now_num = 13  
  elif now_return[i]=='E':  
                now_num = 14  
  elif now_return[i]=='F':  
                now_num = 15  
  now_multiple = 1  
  for cnt in range(N//4-1):  
            now_multiple *= 16  
  for cnt in range(i):  
            now_multiple /= 16  
  now_return_fig += now_num*now_multiple  
    outputs_arr.append(int(now_return_fig))  
for step in range(T):  
    print("#{} {}".format(step+1, outputs_arr[step]))
```
만일 `ABCDE`라는 문자가 있고 3글자씩 끊어 비밀번호를 만든다고 하면, `(3-1)`번 뒤로 이어붙이고 (`ABCDEAB`) 그 뒤에 인덱스를 하나씩 넘기며 ABC,BCD,CDE....EAB 의 패스워드를 만드는 식으로 풀이하였다. 오히려 16진수를 10진수로 바꾸는게 귀찮은 작업이었다.

