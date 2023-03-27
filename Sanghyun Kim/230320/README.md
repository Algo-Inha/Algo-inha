# Solving

## 가장 큰 증가하는 부분 수열
https://www.acmicpc.net/problem/11055
### 문제풀이
```python
import sys
input = sys.stdin.readline

n = int(input().strip())
a = [int(x) for x in input().split()]
dp = a[:]

for i in range(n):
    for j in range(i):
        if a[i] > a[j]:
            dp[i] = max(dp[i], dp[j] + a[i])    # dp문제

print(max(dp))
```
### 의견
많이 접해본 문제지만, 접할 때마다 헷갈리는 문제


## 영역 구하기
https://www.acmicpc.net/problem/2583
### 문제풀이
```python
from collections import deque
import sys
input = sys.stdin.readline

y, x, num = map(int, input().split())
# x, y 크기 직사각형
graph = [[0] * (y + 1) for _ in range(x + 1)]

for i in range(num):
    x0, y0, x1, y1 = map(int, input().split())
    for j in range(x0 + 1, x1 + 1):
        for k in range(y0 + 1, y1 + 1):
            graph[j][k] = -1

# 서 동 남 북
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# 넓이 list
count_li = []
count = 0

q = deque()
for i in range(1, x + 1):
    for j in range(1, y + 1):
        count = 0
        if graph[i][j] == 0:
            count += 1
            q.append([i, j])
            graph[i][j] = 1

            while q:
                x_, y_ = q.popleft()
                for k in range(4):
                    nx = x_ + dx[k]
                    ny = y_ + dy[k]

                    if nx > 0 and ny > 0 and nx <= x and ny <= y:
                        if graph[nx][ny] == 0:
                            count += 1
                            q.append([nx, ny])
                            graph[nx][ny] = 1
        if count > 0:
            count_li.append(count)
count_li = sorted(count_li)
print(len(count_li))
print(*count_li)
```
### 의견
dfs 문제


## 마법사 상어와 파이어볼
https://www.acmicpc.net/problem/20056
### 문제풀이
```python

```
### 의견
풀지 못했습니다.


## 농장 관리
https://www.acmicpc.net/problem/1245
### 문제풀이
```python

```
### 의견
dfs 문제, 어렵지 않은 문제일 것 같은데 시간이 부족하여 풀지 못했습니다.


## 신입 사원
https://www.acmicpc.net/problem/1946
### 문제풀이
```python
import sys
input = sys.stdin.readline
t = int(input())

for i in range(t) :
    n = int(input())
    personLi = [0 for _ in range(n)]
    for j in range(n) :
            t1 ,t2 = map(int,input().split())
            personLi[j] = [t1,t2]

    personLiSort = sorted(personLi, key = lambda x : x[0])  # 서류 기준 정렬
    hired = 1
    man = personLiSort[0][1]
    for j in range(1,n) :
        if personLiSort[j][1] < man :   # 앞 지원자 보다 면접 성적 높으면 채용
            man = personLiSort[j][1]
            hired += 1

    print(hired)
```
서류 기준 정렬 후 앞 지원자와 비교하며 면접 성적 비교해 채용 결정.
### 의견
그리디 문제, 2중 포문을 사용할 경우 시간 초과 발생.