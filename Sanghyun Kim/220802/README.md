# Solving

## 거리두기 확인하기- PG_81302
https://school.programmers.co.kr/learn/courses/30/lessons/81302
### 문제풀이
```python
from collections import deque

places = [  ["XOXPX", "OOPXX", "XXXXX", "XXXXX", "XXXXX"], 
            ["POOPX", "OXPXX", "XXXXX", "OXXXO", "OOOXP"], 
            ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"], 
            ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], 
            ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]  ]

def solution(places):
    answer = []
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    temp = [[False for _ in range(5)] for _ in range(5)]

    for i in range(5):
        found_error = False
        for row in range(5):
            if found_error == True:
                break
            for col in range(5):
                if found_error == True:
                    break
                # 면접자에 대해 dfs 알고리즘 적용
                if places[i][row][col] == 'P':
                    dfs = deque([(row, col)])
                    temp[row][col] = True
                
                    while dfs:
                        if found_error == True:
                            break
                        y, x = dfs.popleft()
                        # 맨해튼 거리 넘어가면 break
                        dist = abs(row - y) + abs(col - x)
                        if dist >= 2:
                            break
                        # 맨해튼 거리 넘어가지 않으면
                        # 면접자가 존재하지 않을 때 queue에 추가, 지나간 경로 표시
                        # 면접자가 존재할 때 found_error = True, answer에 0을 담는다.
                        for j in range(4):
                            nx = x + dx[j]
                            ny = y + dy[j]
                            if nx >= 0 and nx < 5 and ny >= 0 and ny < 5 and temp[ny][nx] == False:
                                if places[i][ny][nx] == 'O':
                                    dfs.append((ny, nx))
                                    temp[ny][nx] = True
                                elif places[i][ny][nx] == 'P':
                                    answer.append(0)
                                    found_error = True
                                    break
                    temp = [[False for _ in range(5)] for _ in range(5)]
        # 5 x 5 크기의 대기실을 모두 돌았음에도 answer에 0이 추가되지 않을 경우
        # answer에 1을 담는다.
        if len(answer) == i:
            answer.append(1)
    return answer

print(solution(places))
```
5 x 5 크기의 대기실을 모두 돌며 면접자에 대해 dfs 알고리즘 적용한다. 
맨해튼 거리를 넘어갈 경우 break 하고,
맨해튼 거리를 넘어가지 않으면 면접자가 존재하지 않을 때 queue에 추가하고, 지나간 경로를 True로 표시한다. 면접자가 존재할 때 found_error = True, answer에 0을 담고 다음 대기실로 넘어간다.
5 x 5 크기의 대기실을 모두 돌았음에도 answer에 0이 추가되지 않을 경우 answer에 1을 담고 다음 대기실로 넘어간다.
### 의견
처음 코딩을 완료했을 때 테스트 케이스 10, 17, 18번이 통과되지 않아 이를 찾는데 애를 좀 먹었다. 결과적으로 맨핸튼 거리를 넘어가지 않았을 때 면접자가 존재하면 found_error = True로 바꾸고, 다음 대기실로 넘어가기 전까지의 모든 for, while 문을 break 했어야 하는데 while문을 break하지 않아 발생한 오류였다. 
위처럼 깜빡했던 문제를 제외하고는 어렵지 않았던 dfs 문제였다.


## 회의실 배정- BJ_1931
https://www.acmicpc.net/problem/1931
### 문제풀이
```python
import sys
input = sys.stdin.readline

n = int(input())
q = []
count = 0
end = 0
for _ in range(n):
    q.append(list(map(int, input().split())))

q = sorted(q, key = lambda x:x[0])
q = sorted(q, key = lambda x:x[1])

for i, j in q:
    if i >= end:
        count += 1
        end = j
print(count)
```
회의가 시작하자마자 끝나는 경우도 있으므로 시작하는 시간 기준 정렬을 먼저 진행하고 이후 끝나는 시간 기준 정렬을 한다. end를 기준으로 end보다 이후에 시작하는 회의를 선택해 count 및 회의 끝나는 시간을 end로 지정한다.
### 의견
그리디 알고리즘, 아직 익숙하지 않은 알고리즘으로 많은 유형의 문제를 풀어봐야 할 것 같다. 
탐욕적인 알고리즘 자체를 왜 사용하는지 아직 이해가 잘 안된다...


## 타일 채우기- BJ_2133
https://www.acmicpc.net/problem/2133
### 문제풀이
```python
n = int(input())
tile = [0 for _ in range(16)]

tile[2//2] = 3
tile[4//2] = 11

if n % 2 == 0:
    if n > 4:
        for i in range(3, n//2 + 1):
            tile[i] = 3 * tile[i - 1] + 2 * sum(tile[:i - 1]) + 2
    print(tile)
    print(tile[n//2])
else:
    print(0)
```
홀수일 경우 존재하지 않는다.
짝수일 경우만 따지므로 n // 2 로 index 따지는 규칙 찾는 dp 문제
dp[n - 2] * 3 + (dp[n - 4] + dp[n - 6] + dp[n - 8] + ... + dp[2]) * 2 + 2(뒤집어진 갈고리 2개씩 추가하는 형태)
### 의견
2개씩 더해지는 추가 형태의 규칙을 찾기가 까다로웠다.


## 단지번호붙이기- BJ_2667
https://www.acmicpc.net/problem/2667
### 문제풀이
```python
import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
home = list()
house = [[False for _ in range(n)] for _ in range(n)]
total_count = []

# 동 서 남 북
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

for i in range(n):
    home.append(input().rstrip())

for i in range(n):
    for j in range(n):
        count = 0
        if home[j][i] == '1' and house[j][i] == False:
            count += 1
            house[j][i] = True
            dfs = deque([(j, i)])
            while dfs:
                y, x = dfs.popleft()
                for k in range(4):
                    nx = x + dx[k]
                    ny = y + dy[k]
                    if nx >= 0 and nx < n and ny >= 0 and ny < n:
                        if home[ny][nx] == '1' and house[ny][nx] == False:
                            count += 1
                            dfs.append((ny, nx))
                            house[ny][nx] = True
        if count > 0:
            total_count.append(count)

total = sorted(total_count)
print(len(total))
if len(total) == 0:
    print(0)
else:
    for i in range(len(total)):
        print(total[i])

```
dfs 알고리즘을 통해 단지당 집 개수 구하여 총 단지 출력 후 단지당 집 개수를 오름차순으로 출력한다.
### 의견
단순한 dfs 알고리즘


## 안전 영역- BJ_2468
https://www.acmicpc.net/problem/2468
### 문제풀이
```python
import sys
from collections import deque

n = int(input())
area = []
min_h = 100
max_h = 1
water = [[False for _ in range(n)] for _ in range(n)]
count = [0 for _ in range(101)]

# 동 서 남 북
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

for i in range(n):
    area.append(list(map(int, input().split())))
    min_h = min(min(area[i]), min_h)
    max_h = max(max(area[i]), max_h)

# 가장 낮은 높이보다 적은 양의 비가 내릴 경우를 깜빡할 수 있음!!
for i in range(min_h - 1, max_h):
    for y in range(n):
        for x in range(n):
            if area[y][x] > i and water[y][x] == False:
                water[y][x] = True
                count[i] += 1
                # dfs
                dfs = deque([(y, x)])
                while dfs:
                    y_, x_ = dfs.popleft()
                    for j in range(4):
                        nx = x_ + dx[j]
                        ny = y_ + dy[j]
                        if nx >= 0 and nx < n and ny >= 0 and ny < n and area[ny][nx] > i and water[ny][nx] == False:
                            dfs.append((ny, nx))
                            water[ny][nx] = True
    water = [[False for _ in range(n)] for _ in range(n)]

print(max(count))
```
전체 지역에 대해 높이의 최소 - 1 부터 최대 높이 - 1 까지 안전한 영역이 몇 개가 만들어 지는 지 각각 count 리스트에 dfs 알고리즘을 통해 넣고, count 리스트의 최댓값을 출력한다.
### 의견
dfs 또는 bfs를 이용한 단순한 그래프 탐색문제였다. 하지만 가장 낮은 최소 높이보다 1 낮은 경우를 고려하는 경우를 깜빡할 수 있는 문제다. 이 경우 모든 지역이 물에 잠기지 않아 count = 1 이 되는데 이 경우 또한 고려해야 하는 문제였다. 