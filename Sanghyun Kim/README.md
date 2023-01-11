### Python

## 이분 탐색
```python
def binary_search(arr, target, min, max):
  min, max = 0, len(arr) - 1
    while min <= max:
        mid = (min + max) // 2
        if arr[mid] > target:
            max = mid - 1
        if arr[mid] == target:
            return mid
        if arr[mid] < target:
            min = mid + 1
    return -1
```

## DFS
```python
from collections import deque
dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]
temp = [[False for _ in range(max_col)] for _ in range(max_row)]

def dfs(x, y, max_row, max_col):
    q = deque([(y, x)])
    while q:
        y_, x_ = q.popleft()
        temp[y_][x_] = True
        for i in range(4):
            ny = y_ + dy[i]
            nx = x_ + dx[i]
            if 0 <= ny < max_row and 0 <= nx < max_col and temp[ny][nx]:
                q.append(ny, nx)
                temp[ny][nx] = True
```


## Linked list
```python
class Node:
    def __init__(self):
        self.prev = -1 # 이전 노드 인덱스
        self.next = -1 # 다음 노드 인덱스
        self.is_delete = False # 삭제 여부

# 링크드리스트 초기화
node_list = [Node() for _ in range(n)] # 노드 리스트 생성
for i in range(n - 1):
    node_list[i].next = i + 1 # i 번째 노드의 next는 i+1
    node_list[i + 1].prev = i # i+1 번째 노드의 prev는 i
```


## 플로이드-워셜 알고리즘
모든 노드 간 최단 경로를 구하는 알고리즘
```python
for k in range(n): #경로 for문이 가장 상위 단계여야 누락되지 않는다
    for i in range(n):
        for j in range(n): 
            if graph[i][j] == 1 or (graph[i][k] == 1 and graph[k][j] == 1):
                graph[i][j] = 1
```


## 파이썬 최대 정수
```python
import sys
print(sys.maxsize)
```