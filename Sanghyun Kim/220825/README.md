# Solving

## 숨바꼭질
https://www.acmicpc.net/problem/1697
### 문제풀이
```python
from collections import deque

n, k = map(int, input().split())
visited = [False for _ in range(100001)]

temp = deque([(n, 0)])
visited[n] = True

while temp:
    # x: 수빈이 위치
    # cnt: 수빈이가 x위치에 있을 때까지 흐른 시간
    x, cnt = temp.popleft()
    # 가장 처음에 수빈이와 동생의 위치가 같을 경우 0초
    if x == k:
        print(0)
        break
    if x + 1 == k or x - 1 == k or x * 2 == k:
        print(cnt + 1)
        break
    else:
        if 0 <= x - 1 <= 100000 and visited[x - 1] == False:
            temp.append((x - 1, cnt + 1))
            visited[x - 1] = True
        if 0 <= x + 1 <= 100000 and visited[x + 1] == False:
            temp.append((x + 1, cnt + 1))
            visited[x + 1] = True
        if 0 <= x * 2 <= 100000 and visited[x * 2] == False:
            temp.append((x * 2, cnt + 1))
            visited[x * 2] = True
```
bfs 알고리즘을 사용해 수빈이의 위치에 대해 1초 후에 이동할 수 있는 위치를 모두 queue에 넣는다. 이 때, 얼마만큼의 시간이 흘렀는지 확인하기 위해 수빈이의 위치와 그 위치에 있을 때까지 흐른 시간을 함께 입력한다.
### 의견
처음에 그리디 알고리즘인줄 알고 접근하다가 점점 복잡해지는 것을 느꼈다. 문제 자체의 힌트를 보고 bfs 알고리즘으로 접근했는데, 수빈이가 x의 위치에 있을 때 몇 초가 흘렀는지를 확인할 방법을 찾기가 까다로웠다. 
전형적인 그래프 탐색 문제인 것 같은데 아직 숙련도가 좀 부족한 것 같다. 예외처리의 경우에도 처음에 수빈이와 동생의 위치가 같을 경우, 수빈이의 위치가 0에서 시작할 경우를 고려하지 않았어서 이를 해결하는데 시간이 좀 걸렸다.


## 표 편집
https://school.programmers.co.kr/learn/courses/30/lessons/81303
### 문제풀이
```python
from collections import deque

class Node:
    def __init__(self):
        self.prev = -1 # 이전 노드 인덱스
        self.next = -1 # 다음 노드 인덱스
        self.is_delete = False # 삭제 여부

def solution(n, k, cmd):
 
    # 1. 링크드리스트 초기화
    node_list = [Node() for _ in range(n)] # 노드 리스트 생성
    for i in range(n - 1):
        node_list[i].next = i + 1 # i 번째 노드의 next는 i+1
        node_list[i + 1].prev = i # i+1 번째 노드의 prev는 i
 
    # 2. 삭제된 노드를 저장할 스택
    del_stack = deque()
 
    # 3. 명령어 처리
    cur = k # 현재 가리키고 있는 노드의 인덱스
    for c in cmd:
 
        if len(c) > 1:
            c, move_size = c.split(' ')
            move_size = int(move_size)
 
        if c == "U":
            for i in range(move_size):
                cur = node_list[cur].prev # cur을 cur 노드의 prev로 교체
        elif c == "D":
            for i in range(move_size):
                cur = node_list[cur].next # cur을 cur 노드의 next로 교체
        elif c == "C":
            node_list[cur].is_delete = True # 현재 노드에 삭제 표시
            del_stack.append(cur) # 스택에 삭제된 노드 번호 추가
 
            prev_node = node_list[cur].prev # 이전 노드 번호
            next_node = node_list[cur].next # 다음 노드 번호
 
            if prev_node != -1: # 이전 노드가 있는 경우
                node_list[prev_node].next = next_node # 이전 노드의 next를 삭제된 노드가 가리키던 next로 교체
            if next_node != -1: # 다음 노드가 있는 경우
                node_list[next_node].prev = prev_node # 다음 노드의 prev를 삭제된 노드가 가리키던 prev로 교체
                cur = next_node # 가리키고 있는 노드를 next_node로 갱신
            else: # 만약 다음 노드가 없는 경우
                cur = prev_node # 가리키고 있는 노드를 prev_node로 갱신
 
        elif c == "Z":
            del_node = del_stack.pop() # stack의 가장 상위 요소를 가져옴
            node_list[del_node].is_delete = False # 해당 노드의 is_delete = False로 변경
 
            prev_node = node_list[del_node].prev # 삭제된 노드의 이전 노드
            next_node = node_list[del_node].next # 삭제된 노드의 다음 노드
 
            if prev_node != -1: # 이전 노드가 존재하는 경우
                node_list[prev_node].next = del_node # 이전 노드의 next를 현재 노드로 지정
            if next_node != -1:
                node_list[next_node].prev = del_node # 다음 노드의 prev를 현재 노드로 지정
 
    # 4. 삭제된 노드 판별
    answer = []
    for i in range(n):
        if node_list[i].is_delete: answer.append("X")
        else: answer.append("O")
    return "".join(answer)
```
linked-list를 만들어 모든 노드를 연결시킨다. 명령어에 따라 'U', 'D'일 경우 move_size만큼 가리키는 노드의 인덱스를 이동시킨다. 'C'일 경우 현재 가리키는 노드를 삭제하여 스택에 쌓고, 이전 노드와 다음 노드를 서로 연결시킨다. 'Z'일 경우 스택 가장 위 노드를 가져와 다시 연결시킨다. 마지막으로 삭제된 노드 판별을 위해 각 노드별로 삭제 여부를 판별한다.
### 의견
list를 만들어 pop(), insert(index, value) 를 사용해 구현했었다. 하지만 시간 복잡도와 효율성이 모두 너무 안좋게 나와 해결법을 찾기 위해 구글링을 했다. 결과는 링크드 리스트의 사용... 알고 있던 알고리즘이지만 너무 오랜만에 사용하고, 다시 느끼지만 카카오는 아직은 높은 벽인 것 같다.


## 체스판 위의 공
https://www.acmicpc.net/problem/16957
### 문제풀이
```python
from collections import deque
import sys
input = sys.stdin.readline

# 체스판 정수 입력
r, c = map(int, input().split())
chess_table = []
for _ in range(r):
    chess_table.append(list(map(int, input().split())))

# 각 칸의 공 수
num_table = [[0 for _ in range(c)] for _ in range(r)]
# 가장 작은 정수의 칸으로 즉시 이동 가능한 메모라이제이션 list
dest_table = [[[] for _ in range(c)] for _ in range(r)]

# 동, 남동, 남, 남서, 서, 북서, 북, 북동
dr = [0, 1, 1, 1, 0, -1, -1, -1] # y
dc = [1, 1, 0, -1, -1, -1, 0, 1] # x


# 체스판의 모든 칸에 대해
for i in range(r):
    for j in range(c):
        min_val = chess_table[i][j]
        dfs = deque([(i, j)])
        min_dy, min_dx = i, j
        while dfs:
            temp = False
            y, x = dfs.popleft()

            # 가장 작은 정수의 칸으로 즉시 이동 가능하다면 이동하여
            # while문에서 탈출
            if dest_table[y][x]:
                y, x = dest_table[y][x][0], dest_table[y][x][1]
                min_val = chess_table[y][x]
                min_dy, min_dx = y, x
                break
            
            # 이동 가능한 8 방향에 대해
            # 이동가능하면
            # 현재 min_val보다 작은 값일 경우
            # min_dy, min_dx 값 변경
            # temp = True로 하여 min 값을 변경했다는 표시

            # 8번 다 돌고, min 값을 변경했을 경우
            # 바뀐 min 값에 대한 dy, dx 값을 dfs에 append
            for k in range(len(dr)):
                dy = y + dr[k]
                dx = x + dc[k]
                if 0 <= dy < r and 0 <= dx < c:
                    if min_val > chess_table[dy][dx]:
                        min_val = chess_table[dy][dx]
                        min_dy, min_dx = dy, dx
                        temp = True

                if k == len(dr) - 1 and temp == True:
                    dfs.append((min_dy, min_dx))
        
        # while문 끝나고 가장 작은 값의 위치 +1
        # i, j 일 경우 가장 작은 값의 위치 메모라이제이션
        num_table[min_dy][min_dx] += 1
        dest_table[i][j] = [min_dy, min_dx]

for i in range(r):
    print(*num_table[i])
```
체스판 전체를 돌며 각 위치에서 8방향으로 가장 작은 값으로 공을 이동시키며 최종적으로 8방향에서 가장 작은 값일 경우 num_table list에서 해당 위치의 값을 +1 하는 방식으로 진행한다. 여기에 이미 가장 작은 정수가 있는 칸으로 이동한 경험이 있는 좌표의 경우 바로 가장 작은 정수의 위치로 이동할 수 있게 메모라이제이션 list를 따로 만들어 좌표를 저장한다.
### 의견
문제를 읽고 푸는데 어렵지 않은 문제일 것이라 생각하여 dfs로 접근했다. 하지만 70%에서 시간초과가 발생했고, 시간을 줄이기 위해 가장 작은 정수가 있는 칸으로 이동한 경험이 있는 좌표의 경우 메모라이제이션 하여 따로 list에 가장 작은 정수 위치의 좌표를 저장하는 방식으로 다시 진행했지만 시간 초과 문제를 해결할 수는 없었다. 


## 줄어들지 않아
https://www.acmicpc.net/problem/2688
### 문제풀이
```python
n = [[1,1,1,1,1,1,1,1,1,1]]
n_sum = [10]

for i in range(64):
    n_sub = []
    for j in range(10):
        sub_total = 0
        for k in range(j, 10):
            sub_total += n[i][k]
        n_sub.append(sub_total)
    n.append(n_sub)
    n_sum.append(sum(n_sub))

t = int(input())
for _ in range(t):
    print(n_sum[int(input()) - 1])
```
n list에 10개로 이루어진 list를 모두 더하면 n list의 index + 1에 해당하는 줄어들지 않는 자리 수의 개수이다. 10개로 이루어진 list는 이전 10개짜리 list에서 10개 모두 더한 값부터 맨 앞 index의 값부터 하나씩 빼가며 마지막에는 마지막 index의 값 만을 list에 넣어 총 10개짜리의 list를 만들어 n list에 넣는다. n의 범위가 64까지이므로 문제 입력 전에 미리 만들어 놓고 테스트 케이스를 진행한다. 
### 의견
규칙을 찾기가 좀 까다로웠다. 헷갈렸다.. 시간 복잡도는 이전에 비슷한 문제를 풀어봤기에 64까지의 모든 경우를 먼저 만들어 놓고 테스크 케이스를 진행하여 해결했다.


## 쇠막대기
https://www.acmicpc.net/problem/10799
### 문제풀이
```python
fe = list(input())
stk = []
count = 0

for i in range(len(fe)):
    if fe[i] == '(':
        stk.append('(')
    else:
        if fe[i - 1] == '(':
            stk.pop()
            count += len(stk)
        else:
            stk.pop()
            count += 1
print(count)
```
'(' 일 때마다 stack에 넣어 ')'를 만날 경우 이전이 '('일 때와 ')' 일 때로 나눠 각각 stack을 pop 하고, '('일 때는 남은 stack 수만큼 count, ')'일 때는 1만큼 count한다.
### 의견
문제를 이해하기 까다로웠다. 또한 문제를 이해했음에도 접근법이 쉽지않아 고민을 만이 한 문제다.