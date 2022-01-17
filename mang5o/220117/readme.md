# Solving

## 빙산
### 문제 풀이

```python
import copy  # to process deep copy

row_col = input()  # input
row_num, col_num = row_col.split(" ")
row_num = int(row_num)  # type casting
col_num = int(col_num)  # type casting

map_matrix = []
not_zero = []
for y in range(row_num):
    map_line = input().split(" ")
    for x in range(len(map_line)):
        map_line[x] = int(map_line[x])  # type casting
        if map_line[x] != 0:
            not_zero.append((y, x))
    map_matrix.append(map_line)

year_count = 0
divided = False
while True:
    tmp_matrix = copy.deepcopy(map_matrix)
    now_zeros = True
    for nz in not_zero:
        y, x = nz
        if tmp_matrix[y][x] != 0:
            now_zeros = False
            for xy_diff in ((y, x - 1), (y, x + 1), (y - 1, x), (y + 1, x)):
                if map_matrix[xy_diff[0]][xy_diff[1]] == 0:
                    tmp_matrix[y][x] = tmp_matrix[y][x] - 1
                if tmp_matrix[y][x] == 0:
                    break
    if now_zeros:
        year_count = 0
        break
    map_matrix = copy.deepcopy(tmp_matrix)
    year_count = year_count + 1

    now_group = 0
    now_x = 0
    while True:
        # check group
        check_queue = []
        now_zeros = True
        for nz in not_zero:
            y, x = nz
            if tmp_matrix[y][x] != 0:
                now_zeros = False
                tmp_matrix[y][x] = 0
                check_queue.append((y, x))
                break
        if now_zeros:
            break
        now_group = now_group + 1
        now_queue_count = 0
        while len(check_queue) > now_queue_count:
            y, x = check_queue[now_queue_count]
            for xy_diff in ((y, x - 1), (y, x + 1), (y - 1, x), (y + 1, x)):
                if tmp_matrix[xy_diff[0]][xy_diff[1]] != 0:
                    tmp_matrix[xy_diff[0]][xy_diff[1]] = 0
                    check_queue.append(xy_diff)
            now_queue_count = now_queue_count + 1
    if now_group > 1:
        print(year_count)
        divided = True
        break
if not divided:
    print(0)
```

### 알고리즘 설명

코드가 두 가지의 부분으로 구현되어있는데, 첫 번째는 매 해마다 빙하가 녹는 것에 대한 처리이며, 두 번째는 녹은 직후 빙하가 몇 개의 그룹으로 이루어져 있는가에 관한 그루핑 작업이다.

```python
# 빙하가 녹는것에 대한 처리부분
        if tmp_matrix[y][x] != 0:
            now_zeros = False
            for xy_diff in ((y, x - 1), (y, x + 1), (y - 1, x), (y + 1, x)):
                if map_matrix[xy_diff[0]][xy_diff[1]] == 0:
                    tmp_matrix[y][x] = tmp_matrix[y][x] - 1
                if tmp_matrix[y][x] == 0:
                    break
```
위와 같이 자신의 상하좌우의 상태를 확인한 후 0의 개수만큼 자신의 값을 빼주면 되는데, 문제는 1개의 matrix에서 작업을 진행한다면 같은 해에 녹는 빙하들이 순차적으로 계산되고, 이 때문에 이후에 계산하는 블럭에 이전 계산이 합산되어 들어가는 현상이 생긴다.
따라서 위 코드에서 보이듯이 `tmp_matrix = copy.deepcopy(map_matrix)` 로 deep copy를 수행하여 비교와 계산을 서로 다른 matrix에서 진행하였다.

```python
# Grouping process
 while True:
        # check group
        check_queue = []
        now_zeros = True
        for nz in not_zero:
            y, x = nz
            if tmp_matrix[y][x] != 0:
                now_zeros = False
                tmp_matrix[y][x] = 0
                check_queue.append((y, x))
                break
        if now_zeros:
            break
        now_group = now_group + 1
        now_queue_count = 0
        while len(check_queue) > now_queue_count:
            y, x = check_queue[now_queue_count]
            for xy_diff in ((y, x - 1), (y, x + 1), (y - 1, x), (y + 1, x)):
                if tmp_matrix[xy_diff[0]][xy_diff[1]] != 0:
                    tmp_matrix[xy_diff[0]][xy_diff[1]] = 0
                    check_queue.append(xy_diff)
            now_queue_count = now_queue_count + 1
    if now_group > 1:
        print(year_count)
        divided = True
        break
```

map matrix에서 0이 아닌 한 점을 시작점으로 설정한 뒤, 그 점과 이어져있는 점들 중 0이 아닌 점을 check_queue에 넣는다. visited 행렬을 다시 선언하기엔 메모리상 손해가 많아서 이전 프로세스에서 deep copy를 진행했던 `tmp_matrix` 행렬을 가지고 재활용한다. 방문할 때 해당 원소를 0으로 바꾸고 queue에 집어넣는다. 그루핑을 진행할 때 값이 0인 부분은 애초에 포함하지 않기 때문에 0으로 바꾸는것이 visited의 역할을 해준다.


## 나누기
### 문제풀이

```python
num = int(input())
figures = input().split(" ")
sum_of_all = 0
for i in range(len(figures)):
    now_num = int(figures[i])  # type casting
    sum_of_all = sum_of_all + now_num
    figures[i] = now_num

sum_of_each_block = sum_of_all / 4

block_arr = {-1: 1}
for i in range(4):
    tmp_ba = {}
    for ba in block_arr.items():
        now_sum = 0
        now_multi = ba[1]
        start_point = ba[0]
        for pointer in range(start_point + 1, num):
            now_sum = now_sum + figures[pointer]
            if now_sum == sum_of_each_block:
                if pointer in tmp_ba:
                    tmp_ba[pointer] = tmp_ba[pointer] + now_multi
                else:
                    tmp_ba[pointer] = now_multi
    block_arr = tmp_ba

method_count = 0
for i in block_arr.items():
    if i[0] == num - 1:
        method_count = i[1]
        break

print(method_count)
```

### 알고리즘 설명

행렬을 4 부분으로 합이 같게 나누는 작업이니만큼, 총 행렬의 합을 4로 나누어 각 부분이 가져야할 총합을 계산한 뒤 나누기 작업을 시작한다.
`block_arr = {-1: 1}` 해당 dictionary가 key 값으로 현재 스탭의 위치, value 값으로 도달할 수 있는 가짓수를 가지게 된다. 시작점이 -1인 것은 이전 스탭의 마지막 블럭이 -1이고, 그 다음 블럭의 시작점(인덱스)이 0부터이기 때문이다.
pointer는 현재 position index를 나타내며, 한 스탭마다 `sum_of_each_block' 값만큼 총 합을 가지도록 pointer를 오른쪽으로 끝까지 움직이면서 만족하는 pointer의 위치를 dictionary에 보관한다. 여기에 value값으로 가진 "가짓수" 는 아래와 같이 계산한다.
```
input (문제 예제)
10
4 -1 2 1 -3 1 2 2 1 3
each value of block_arr at each step
{1: 1, 4: 1} (첫 번째 블록의 끝점)
{3: 1, 6: 2} (두 번째 블록의 끝점)
{8: 3} (세 번째 블록의 끝점)
{9: 3} (네 번째 블록의 끝점)
```

# Discussion
정말 간단한 내용의 코딩이었으나, 빙산 문제에선 DFS나 BFS의 풀이, 나누기 문제에선 Dynamic Programming의 방식으로 문제를 풀 수 있어서 오랜만에 감을 잡는데 정말 도움이 됐다. 다만 Python으로 문제풀이를 진행하다보니 틀렸다는 채점 결과는 거의 나오지 않지만, 시간초과와 메모리초과로 인해 문제풀이 실패라는 결과창이 매우 많이 떴다. 이 때문에 빙산 문제에선 not_zero 행렬을 만들어 연산 횟수를 최대한 줄이기도 하고, 나누기 문제에선 Hashmap과 유사한 dictionary를 사용하여 최대한 빠르게 돌릴 수 있도록 수정하는 데에 시간을 많이 쏟았다. 또한 Pypy와 Python 구현체를 가지고 같은 코드를 각각 시도하며 시간을 비교하는 것도 생각보다 답답한 경험이었기 때문에 다음 문제부터는 익숙한 C++을 사용하여 문제풀이를 진행할 것 같다.