# Solving

## 정사각형
https://www.acmicpc.net/problem/1485
### 문제풀이
```python
import sys
input = sys.stdin.readline

for _ in range(int(input())):
    ans = 0
    points = [[] for _ in range(4)]
    for i in range(4):
        points[i] = list(map(int, input().split()))
        
    points.sort(key = lambda x : x[1])
    points.sort(key = lambda x : x[0])

    diag1 = abs(points[-1][0] - points[0][0]) ** 2 + abs(points[-1][1] - points[0][1]) ** 2
    diag2 = abs(points[2][0] - points[1][0]) ** 2 + abs(points[1][1] - points[2][1]) ** 2
    len1 = abs(points[1][0] - points[0][0]) ** 2 + abs(points[1][1] - points[0][1]) ** 2
    len2 = abs(points[2][0] - points[0][0]) ** 2 + abs(points[2][1] - points[0][1]) ** 2

    # 두 변의 길이, 두 대각선의 길이가 같을 경우
    if diag1 == diag2 and diag1 > 0 and diag2 > 0 and len1 == len2 and len1 > 0 and len2 > 0:
        ans = 1
    print(ans)
```
한 점을 공유하는 두 변의 길이가 같고, 두 대각선의 길이가 같고, 모두 0보다 클 경우 정사각형으로 판별했다.
### 의견
정사각형으로 판별하는 기준을 그려보며 조건을 파악해 해결했다.


## 랭킹전 대기열
https://www.acmicpc.net/problem/20006
### 문제풀이
```python
import sys
input = sys.stdin.readline

p, m = map(int, input().split())
player = [[] for _ in range(p)]
graph = [False for _ in range(p)]
# 5명의 플레이어 들어갈 때 마다 게임 실행: Started!
# 전체 player 다 돌았는데 게임 실행 안될 경우: Waiting!
gameStk = []
for i in range(p):
    player[i] = list(map(str, input().split()))
    player[i][0] = int(player[i][0])

temp = False
for j in range(len(player)):
    if graph[j] == False:   # 방 만들기
        gameStk.append(player[j])
        graph[j] = True
        temp = True

        for i in range(j, len(player)):    # 만들어진 방에 플레이어 채우기
            if graph[i] == False and gameStk[0][0] - 10 <= player[i][0] <= gameStk[0][0] + 10:
                graph[i] = True
                gameStk.append(player[i])

            if len(gameStk) == m:   # 만들어진 방에 플레이어 모두 참
                break

    if temp:
        if len(gameStk) == m:   # 게임 시작
            print('Started!')
        else:                   # 게임 시작 못함
            print('Waiting!')
        
        gameStk.sort(key = lambda x : x[1])
        for i in range(len(gameStk)):
            print(*gameStk[i])
        gameStk = []
        temp = False
```
전체 플레이어를 돌면서 방에 들어가지 않은 플레이어에 대해 방을 만들어주고, 해당 플레이어부터 마지막 플레이어까지 전체적으로 돌며 조건을 만족시킬 경우 방에 플레이어를 넣었다. 전체 플레이어를 돌기 전에 방이 풀방이 될 경우 게임이 시작되고, 전체 플레이어를 돌때까지 풀방이 되지 않을 경우 게임이 시작하지 않도록 구성했다.
### 의견
문제에서 시키는대로 하면 되는 구현문제였다. 항상 구현문제를 풀면서 느끼지만 예외처리가 가장 중요한 것 같다. 테스트 케이스를 제외하고 생각해야 하는 조건이 꼭 있기 때문!


## 게임
https://www.acmicpc.net/problem/1072
### 문제풀이
```python
import sys
input = sys.stdin.readline

x, y = map(int, input().rsplit())
victory = y * 100 // x
ans = sys.maxsize   # 파이썬 최대 정수값: 9223372036854775807
l, r = 1, x

while l <= r:   # 이분탐색
    mid = (l + r) // 2

    curr_vic = (y + mid) * 100 // (x + mid)
   
    if curr_vic > victory:
        ans = min(mid,ans)
        r = mid - 1
    else:
        l = mid + 1

if ans == sys.maxsize:
    print(-1)
else:
    print(ans)
```
파이썬 최대 정수값(sys.maxsize)을 더해도 z가 바뀌지 않을 경우 -1 출력, 나머지 경우엔 해당 정수값을 출력한다. 이분탐색 알고리즘 사용.
### 의견
나름 많이 생각했다 생각했는데 10번 이상 실패가 뜨니 화가 났다... 구글링을 했더니 허무한 결과.. 이분탐색이라니... 신나게 구현문제를 풀다가 이분탐색과 같은 간단한 알고리즘 조차 기억이 안나서 풀지 못했다는 것이 화가나는 문제였다..


## N과 M (1)
https://www.acmicpc.net/problem/15649
### 문제풀이
```python
from itertools import permutations
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
li = permutations(range(n), m)

for i in li:
    for j in i:
        print(j + 1, end=' ')
    print()
```
itertools의 permutations로 모든 가능한 경우의 수 출력
### 의견
파이썬 사기


## 배열 돌리기1
https://www.acmicpc.net/problem/16926
### 문제풀이
```python
from collections import deque
import sys
input = sys.stdin.readline

n, m, r = map(int, input().split())
graph = []
for i in range(n):
    graph.append(list(map(int, input().split())))

q = [deque() for _ in range(min(n, m) // 2)]

# queue에 넣기
for i in range(min(n, m) // 2):     # queue 개수: min(n, m) // 2 개

    for j in range(i, n - i - 1):    # (0, 0)부터 (n-1 (-1), 0) 까지 넣기
        q[i].append(graph[j][i])
    
    for j in range(i, m - i - 1):    # (n-1, 0)부터 (n-1, m-1 (-1)) 까지 넣기
        q[i].append(graph[(n - 1) - i][j])

    for j in range(i, n - i - 1):     # (n-1, m-1)부터 (1, m-1) 까지 넣기
        q[i].append(graph[(n - 1) - j][(m - 1) - i])
    
    for j in range(i, m - i - 1):     # (0, m-1)부터 (0, 1) 까지 넣기
        q[i].append(graph[i][(m - 1) - j])
# print(q)

# r 주기
decade = 1
for i in range(len(q)):
    decade *= len(q[i])
R = r % decade

for _ in range(R):  # R 만큼 돌리기
    for i in range(len(q)):
        x = q[i].pop()
        q[i].appendleft(x)
    
# print(q)

# 다시 list로 뿌리기
ans = [[0 for _ in range(m)] for _ in range(n)]
for i in range(len(q)):
    temp = 0
    for j in range(i, n - i - 1):    # (0, 0)부터 (n-1 (-1), 0) 까지 넣기
        ans[j][i] = q[i][temp]
        temp += 1
    
    for j in range(i, m - i - 1):    # (n-1, 0)부터 (n-1, m-1 (-1)) 까지 넣기
        ans[(n - 1) - i][j] = q[i][temp]
        temp += 1

    for j in range(i, n - i - 1):     # (n-1, m-1)부터 (1, m-1) 까지 넣기
        ans[(n - 1) - j][(m - 1) - i] = q[i][temp]
        temp += 1
       
    for j in range(i, m - i - 1):     # (0, m-1)부터 (0, 1) 까지 넣기
        ans[i][(m - 1) - j] = q[i][temp]
        temp += 1

for i in range(len(ans)):
    print(*ans[i])
```
min(n, m) // 2 개수만큼 queue를 만들어 각 queue에 값을 채운다. 
이후 R만큼 반시계방향으로 돌리는데, 맨 뒤 값을 빼 맨 앞으로 가져오게 된다. 
R 값의 경우 r 주기에 해당하는 각 queue 크기들의 곱의 나머지 값에 해당하는 만큼 적용했다.
마지막으로 다시 list에 뿌렸는데, 각 queue에 값을 채울 때 사용했던 for문 4개를 그대로 사용해 값을 넣어줬다.
### 의견
queue에 값을 채우고, 다시 list에 값을 넣어주는 과정에서 index 값에 대한 혼동이 올 수 있는 문제였다.
직접 손으로 하나하나 써가며 따라가야 헷갈리지 않고 해결할 수 있는 구현 문제였다. 
내 생각에 구현 문제중에 정말 좋은 문제인 것 같다.