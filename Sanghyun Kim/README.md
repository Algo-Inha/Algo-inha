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