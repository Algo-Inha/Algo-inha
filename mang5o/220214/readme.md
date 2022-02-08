# Solving
## 동전 바꿔주기
https://www.acmicpc.net/problem/2624
### 문제풀이
```python
import sys
now_val = int(sys.stdin.readline().rstrip())
now_in = int(sys.stdin.readline().rstrip())
all_figure = 0
wallet = []
for i in range(now_in):
    vals, nums = map(int, sys.stdin.readline().rstrip().split())
    if vals <= now_val:
        wallet.append((vals, nums))
        all_figure += nums
wallet.sort(reverse=True, key=lambda money: money[0])
dp_table = [[0 for _ in range(now_val + 1)] for _ in range(now_in + 1)]
dp_table[0][0] = 1
# print(dp_table)
for i in range(now_in):
    for j in range(now_val + 1):
        # now_cursor -> dp_table[i+1][j]
        tmp_add = 0
        for k in [tmp_idx * wallet[i][0] for tmp_idx in range(wallet[i][1] + 1)]:
            if j - k >= 0:
                tmp_add += dp_table[i][j - k]
        dp_table[i + 1][j] += tmp_add

print(dp_table[-1][-1])
```
`dp_table[i][j]` 의 경우 i 종류의 동전을 썼을 때 j 원을 구성할 수 있는 경우의 수를 나타낸다. 다만 i가 1일 때엔 동전의 맨 첫종류만, 2일 때엔 앞에서 부터 두 종류만 사용한다는 뜻이다.
처음에 Greedy 알고리즘으로 경우의 수를 만든 뒤 모든 경우에 대해서 계산하였지만 timeout이 발생하여 위와 같이 DP로 구현하였다.

### 의견
DP가 아니라 모든 경우의 수에 대해 진행하여도 시간초과가 나지 않는다는 글도 있었으나, 파이썬의 특성상 최대한 빠른 알고리즘을 구현하려 DP로 구현하였다.
추가적으로, input 함수를 `sys.stdin.readline().rstrip()`으로 변경하여 사용했는데, 여기서 타임아웃이 없어지며 통과된 것으로 보아 앞으로도 백준 문제 제출에서는 위 함수를 사용해야할 것으로 보인다.

## 뉴스 클러스터링
https://programmers.co.kr/learn/courses/30/lessons/17677
### 문제풀이
```python
def solution(str1, str2):
    str1 = str1.lower()
    str2 = str2.lower()
    str1_set = set()
    str2_set = set()
    for i in range(len(str1)-1):
        if 'a' <= str1[i] <= 'z' and 'a' <= str1[i + 1] <= 'z':
            tmp_cnt = 0
            while True:
                if not str1[i:i + 2]+str(tmp_cnt) in str1_set:
                    str1_set.add(str1[i:i + 2]+str(tmp_cnt))
                    break
                else:
                    tmp_cnt += 1
    for i in range(len(str2) - 1):
        if 'a' <= str2[i] <= 'z' and 'a' <= str2[i + 1] <= 'z':
            tmp_cnt = 0
            while True:
                if not str2[i:i + 2] + str(tmp_cnt) in str2_set:
                    str2_set.add(str2[i:i + 2] + str(tmp_cnt))
                    break
                else:
                    tmp_cnt += 1
    and_set = str1_set & str2_set
    or_set = str1_set | str2_set
    if len(and_set) == 0 and len(or_set) == 0:
        answer = 65536
    else:
        answer = math.floor(65536 * (len(and_set) / len(or_set)))
    # print(str1_set)
    # print(str2_set)
    return answer
    ```
파이썬의 특성상 집합 클래스인 `set()`을 사용하여 손쉽게 합집합, 교집합 등을 풀었으나 문제가 되는 것은 중복 원소의 경우였다. 실제 집합에서는 중복 원소가 존재하지 않기 때문에 `set()`의 사용을 포기해야하나 싶었으나, 원소 뒤에 몇 번째 원소인지 표기하는 방식으로 구현하였다.
예를들어 `fr`이라는 원소가 3개가 들어온다면, `fr1` `fr2` `fr3` 등의 이름으로 집합에 넣은 뒤 연산을 진행한 것이다.
추가적으로 string에 대해 lower case로 변경하는 작업을 진행하였다.

### 의견
문자열파싱 및 비교, 집합 연산 두 곳에서 모두 언어적 특성으로 편하게 구현한 모습이다.

## 치킨배달
https://www.acmicpc.net/problem/15686
### 문제풀이
```python
N, M = map(int, sys.stdin.readline().rstrip().split())
houses = []
chickens = []
houses_num = 0
chickens_num = 0

for i in range(N):
    tmp_input = list(map(int, sys.stdin.readline().rstrip().split()))
    for j in range(len(tmp_input)):
        if tmp_input[j] == 1:
            houses.append((i, j))
            houses_num += 1
        elif tmp_input[j] == 2:
            chickens.append((i, j))
            chickens_num += 1

all_distances = [[(abs(houses[i][0] - chickens[j][0]) + abs(houses[i][1] - chickens[j][1]))
                  for j in range(chickens_num)] for i in range(houses_num)]
# all_distances[i][j] -> i번째 집과 j번째 치킨집과의 거리

all_iters = itertools.combinations([i for i in range(len(chickens))], M)
all_min_path = 1000000
for ai in all_iters:
    now_path_sum = 0
    for house in range(houses_num):
        min_path = 1000000
        for chic_idx in ai:
            tmp_path = all_distances[house][chic_idx]
            if min_path>tmp_path:
                min_path = tmp_path
        now_path_sum += min_path
    if all_min_path>now_path_sum:
        all_min_path = now_path_sum

print(all_min_path)
```
이 문제 또한 계속 맞게 푸는 것 같은 느낌이었는데도 계속 시간초과가 났는데, 두 가지의 방면에서 코드를 풀어 보았다.
처음 방법은 `map_matrix`를 구현하고 치킨집과의 거리를 구할 때에 각 집에서 BFS를 통해 최단거리 치킨집을 구하는 방식이다. `(bj-15686-old.py에 코드 수록)` 또 하나는 위와 같이 치킨집의 경우의 수를 조합으로 모두 뽑아 일종의 brute-force 알고리즘을 푸는 방식이었다.
일반적인 문제라면 처음 생각한 방법이 더 빨리 풀 수 있었을 테지만, 문제 조건에서 주어줬듯이 지도에 비해 치킨집이 매우 적은 문제이기 때문에 위 풀이의 방법만이 시간초과를 통과한 것으로 보인다.

### 의견
시간을 정말 많이 소모한 문제 중 하나였다. 정말 여러 풀이가 존재하고 모두 답이 도출되지만 그 중 더 빠른 방식이 있고, 그 방식을 직접 돌리기 전까지 무엇이 더 빠른지 풀기 애매한 문제인 것 같았다. 지금은 결과를 알기 때문에 지도 크기에 비해 치킨집이 적다는 이유가 도출되지만, 결과가 나오기 전까진 정말 많은 `시간초과`를 겪으며 풀었기에, 직관적으로 어떤 방식이 더 효율적일지 생각하는 경험이 더 필요하다고 생각한다.

## 핀볼게임
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRF8s6ezEDFAUo
### 문제풀이
```python
from queue import Queue

direction_arr = [  # 오 아래 왼 위
    (0, 1), (1, 0), (0, -1), (-1, 0)
]
change_direc = [  # change_direc[i][j] = i방향을 가진 게 j블록을 만났을 때 바뀌는 direction
    [0, 2, 2, 1, 3, 2, 0, 0, 0, 0, 0],
    [1, 0, 3, 3, 2, 3, 1, 1, 1, 1, 1],
    [2, 3, 1, 0, 0, 0, 2, 2, 2, 2, 2],
    [3, 1, 0, 2, 1, 1, 3, 3, 3, 3, 3]
]

T = int(input())
for test_case in range(1, T + 1):
    N = int(input())
    map_matrix = [
        [5 for i in range(N + 2)]
    ]
    start_point = Queue()
    warm_hole = [[], [], [], [], [], [], [], [], [], [], []]
    for i in range(N):
        tmp_input_arr = [5]
        tmp_input = list(map(int, input().split()))
        for j in range(len(tmp_input)):
            tmp_input_arr.append(tmp_input[j])
            if tmp_input[j] <= 0:  # -1이나 0일 때에
                for k in (0, 1, 2, 3):
                    start_point.put((i + 1, j + 1, k))
            elif tmp_input[j] >= 6:
                warm_hole[tmp_input[j]].append((i + 1, j + 1))
        tmp_input_arr.append(5)
        map_matrix.append(tmp_input_arr)
    map_matrix.append([5 for i in range(N + 2)])
    max_score = 0
    while start_point.qsize() > 0:
        tmp_black_hole = start_point.get()
        tmp_score = 0
        start_y = tmp_black_hole[0]
        start_x = tmp_black_hole[1]
        tmp_y = start_y
        tmp_x = start_x
        tmp_dir = tmp_black_hole[2]
        if map_matrix[tmp_y + direction_arr[tmp_dir][0]][tmp_x + direction_arr[tmp_dir][1]] != 0\
                and map_matrix[tmp_y][tmp_x] == -1:
            continue
        while True:
            # moving
            tmp_y += direction_arr[tmp_dir][0]
            tmp_x += direction_arr[tmp_dir][1]
            # 제자리
            if tmp_y == start_y and tmp_x == start_x:
                break
            # direction
            tmp_dir = change_direc[tmp_dir][map_matrix[tmp_y][tmp_x]]
            # 웜홀
            if map_matrix[tmp_y][tmp_x] >= 6:
                now_warm_hole = warm_hole[map_matrix[tmp_y][tmp_x]]
                if tmp_y == now_warm_hole[0][0] and tmp_x == now_warm_hole[0][1]:
                    tmp_y = now_warm_hole[1][0]
                    tmp_x = now_warm_hole[1][1]
                else:
                    tmp_y = now_warm_hole[0][0]
                    tmp_x = now_warm_hole[0][1]
            elif map_matrix[tmp_y][tmp_x] > 0:  # 블록 만났을 때
                tmp_score += 1
            elif map_matrix[tmp_y][tmp_x] == -1:
                break
        if max_score < tmp_score:
            max_score = tmp_score
    print("#{} {}".format(test_case, max_score))
```
시뮬레이션 문제인 만큼 코드 라인수가 좀 길어졌지만 딱히 내용에 어려운 점은 없었다고 생각한다. 다만 아래의 몇 가지 문제가 발생하였고, 아래와 같이 해결하였다.

- SW Expert Academy에서의 코딩 테스트 환경 적응
	- 실제로 경험해보지 못 했던 홈페이지였으며, 코드 업로드를 위해 제출 칸을 보았더니 어떻게 해야할 지 애매했던 상황이었다.
	- 오류로 `import sys` 만 출력되었는데, 제출 코드에 sys 함수가 사용되는 것을 모두 없앤 뒤에 (input()으로 사용) 그 부분을 지웠더니 해결되었다.
	- 다행히 출력 텍스트도 다 나왔으며 익숙해지면 친절한 플랫폼인 것 같다.
- 문제 접근 방법
	- 처음에 문제 종료 조건이 `블랙홀에 도착했을 때에` 만인줄 알아서 `if tmp_input[j] <= 0:  # -1이나 0일 때에` 부분이 원래는 -1일 때에만 작동하는 부분이었다.
	- 블랙홀에 도착했을 때에만 종료된다면 끝이 무조건 블랙홀일 것이기 때문에 시작점을 블랙홀로만 정하였다.
	- 조건을 제대로 확인한 후 정정하였다.

조건이나 문제가 전체적으로 눈에 안 들어오는 경향이 있었으나 반례 등을 직접 손으로 input 데이터를 입력해볼 수 있는 문제였기 때문에 다행스럽게 해결하였다.

### 의견
글 자체를 읽는 데에 비문학 지문을 보는 것 마냥 오래 걸렸던 문제였지만, 시뮬레이션 문제의 특성상 문제 읽는 시간이 길더라도 구현시간은 생각보다는 짧았던 것 같다.

## 시험감독
https://www.acmicpc.net/problem/13458
### 문제풀이
```python
import math  
N = int(input())  
persons = list(map(int, input().split()))  
B, C = map(int, input().split())  
sum_num = len(persons)  
for i in range(len(persons)):  
    persons[i] = max(persons[i]-B, 0)  
for i in persons:  
    sum_num += math.ceil(i / C)  
print(sum_num)
```
기본적으로 총감독관이 방마다 1개씩 들어가기 때문에, 각 방에 대해 B로 뺀 뒤에 계산하였다.

### 의견
첫 문제 이해에 뭔가 이상한 점이 있다고 생각했던게 `각각의 시험장에 총감독관은 오직 1명만 있어야 하고, 부감독관은 여러 명 있어도 된다.` 부분이었다. 총감독관이 무조건 1명이 있어야 하는지, 아니면 없어도 되는지에 대한 부분이었는데, 이 때문에 처음 문제 접근에는 `총감독관은 있으려면 1명만 있어야 하고,` 라는 자의적 해석을 가지고 문제를 풀어서 답이 다르게 나왔다. 문제 풀이를 시작할 때에 애매한 문장이라고 이미 생각을 했기 때문에 다른 해석을 통해 바로 문제를 풀 수 있었다.

## 1,2,3 더하기
https://www.acmicpc.net/problem/9095
### 문제풀이
```python
def get_output(now_figure):
    if now_figure < 0:
        return 0
    elif now_figure <= 1:
        return 1
    else:
        return get_output(now_figure - 1) + get_output(now_figure - 2) + get_output(now_figure - 3)


outputs = []
for i in range(int(input())):
    outputs.append(get_output(int(input())))
for i in outputs:
    print(i)
```
전에 풀었던 2*n 타일링 문제와 크게 다를 게 없는 문제였다.

### 의견
이렇게 간단한 DP의 경우 바로 풀이법이 떠오르지만 조금 더 복잡한 DP의 경우 너무 오랜시간이 걸린다고 판단했다. DP의 특성상 조금 많이 접해보다보면 익숙해 질 것이라 생각해서 매주 DP문제는 지속적으로 풀어주는 것이 좋다고 생각한다.
