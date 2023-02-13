# Solving

## 청소년 상어
https://www.acmicpc.net/problem/19236
### 문제풀이
```python
import sys
input = sys.stdin.readline
import copy

# 물고기 좌표 찾는 함수
def find_fish(graph, fish):
    for i in range(N):
        for j in range(N):
            if graph[i][j][0] == fish:
                return (i, j)

# 모든 물고기 이동시키는 함수
def move_fish(x_shark, y_shark, graph):
    # 번호가 낮은 물고기부터 순차 이동
    for fish in range(1, 17):
        # 물고기 좌표 찾기
        position = find_fish(graph, fish)
        # 해당 물고기가 살아있는 경우
        if position:
            x_fish, y_fish = position[0], position[1] # 좌표 리턴받기
            direction = graph[x_fish][y_fish][1]
            # 반시계 방향으로 45도씩 최대 360도(1바퀴)까지 회전
            for _ in range(len(d)):
                # 해당 방향으로 진행
                nx_fish = x_fish + d[direction][0]
                ny_fish = y_fish + d[direction][1]
                # 맵 내부 위치한 경우
                if 0 <= nx_fish < N and 0 <= ny_fish < N:
                    # 진행할 곳에 상어가 없는 경우
                    if not (nx_fish == x_shark and ny_fish == y_shark):
                        # 해당 방향을 진행방향으로 확정
                        graph[x_fish][y_fish][1] = direction
                        # 물고기 간 위치 변경
                        graph[nx_fish][ny_fish], graph[x_fish][y_fish] = graph[x_fish][y_fish], graph[nx_fish][ny_fish]
                        break # 진행방향이 확정되었기 때문에 진행 방향을 더 이상 바꿀 필요 없음
                direction = (direction + 1) % len(d)

# 상어의 이동가능한 좌표 찾는 함수
def get_movable_position(x_shark, y_shark, graph):
    direction = graph[x_shark][y_shark][1] # 상어 진행방향
    position = []
    # 최대 (맵 크기 -1)까지 이동 가능
    for _ in range(N-1):
        # 진행방향으로 전진
        x_shark += d[direction][0]
        y_shark += d[direction][1]
        # 진행 후 맵 내부에 위치해 있으며 물고기가 존재하는 경우
        if 0 <= x_shark < N and 0 <= y_shark < N and graph[x_shark][y_shark][0] != -1:
            position.append((x_shark, y_shark))
    return position

# 물고기를 모두 먹을 때까지 물고기와 상어를 이동시키는 재귀함수
def dfs(x_shark, y_shark, eat, graph):
    global answer
    graph = copy.deepcopy(graph)
    # 상어가 해당 물고기 잡아먹음
    eat += graph[x_shark][y_shark][0]
    graph[x_shark][y_shark][0] = -1 # 해당 위치 물고기 잡아먹힘 표시
    move_fish(x_shark, y_shark, graph) # 모든 물고기 이동
    # 상어의 이동가능한 좌표(=물고기 위치) 리턴받기
    position = get_movable_position(x_shark, y_shark, graph)

    # 이동가능한 좌표가 남은 경우
    if position:
        for nx_shark, ny_shark in position:
            dfs(nx_shark, ny_shark, eat, graph)
    else:
        answer = max(answer, eat)
        return

if __name__ == '__main__':
    N = 4
    graph = [[None]*N for _ in range(N)]
    for i in range(N):
        data = list(map(int, input().split()))
        for j in range(N):
            # 물고기 번호, 방향 정보 저장
            # 방향 정보 값에 1을 뺀 이유: 진행방향을 저장한 리스트(d)의 값이 인덱스 0부터 시작하기 떄문
            graph[i][j] = [data[2*j], data[2*j+1]-1]

    # 진행방향: 상, 좌상, 좌, 좌하, 하, 우하, 우, 우상
    d = [(-1, 0), (-1, -1), (0, -1), (1, -1), (1, 0), (1, 1), (0, 1), (-1, 1)]
    # (0, 0)에서 시작
    x_shark = y_shark = 0
    answer = 0
    dfs(x_shark, y_shark, 0, graph)
    print(answer)
```
dfs와 구현을 요구하는 삼성 기출 문제이다.
### 의견
문제를 보자마자 삼성 기출문제 같은 생각이 들었다. 구현과 탐색을 요구하는 문제였는데 기존에 풀어보았던 탐색문제와 graph형태가 복잡하여 결국 구글링을 하였고, 도전한다기 보다는 배우는 시간이었다. 가장 설명이 잘 되어있는 블로그에서 코드를 가져왔다. 아직 완벽하게 이해된 것 같진 않지만, 탐색과 구현실력을 키워 다시 도전해보아야 겠다.


## 빗물
https://www.acmicpc.net/problem/14719
### 문제풀이
```python
import sys
input = sys.stdin.readline

h, w = map(int,input().split())
li = list(map(int,input().split()))


total = 0
l_max = 0
r_max = 0


for i in range(1, len(li) - 1):
    l_max = max(li[:i])
    r_max = max(li[i+1:])

    if li[i] < min(l_max,r_max):
        total += min(l_max,r_max) - li[i]

print(total)
```
빗물이 채워지는 양을 매 칸마다 구해서 더해 해결하였다.
### 의견
처음에 골드문제여서 꽤나 복잡할 줄 알았다. 그래서 고려해야할 조건이 많다고 생각해 시간을 많이 낭비했다. 근데 계속 보다보니 이전에 swea에서 풀었던 문제와 비슷한 것 같았다. 좀 쉬웠던 문제였던 걸로 기억해 쉽게 접근해 보았더니 금방 해결하였다. 이제 문제풀기 전에 문제등급을 차라리 안보는게 좋을 것 같다. 

## 떡 먹는 호랑이
https://www.acmicpc.net/problem/2502
### 문제풀이
```python
import sys
input = sys.stdin.readline

d, k = map(int,input().split()) # d = 할머니가 넘어온 날, k = 호랑이에게 준 떡의 개수

A_Coef = 0
B_Coef = 0

f1, f2 = 1, 2

first = 0
second = 0

if d == 3:
    A_Coef = 1
    B_Coef = 1
elif d == 4:
    A_Coef = 1
    B_Coef = 2
else:
    for i in range(d-4):
        f1, f2 = f2, f1 + f2


    A_Coef = f1
    B_Coef = f2

for A in range(1, 100001):
    for B in range(2, 100001):
        if (A_Coef*A + B_Coef*B) == k:
            first = A
            second = B
            break
    if (A_Coef*A + B_Coef*B) == k:
        break

print(first)
print(second)
```
첫날의 준 떡의 개수와 둘째 날에 준 떡의 개수를 A와B로 미지수로 놓고 연립방정식을 푸는 방식으로 해결하였다. F(1) = A, F(2) = B, F(3) = A+B, F(4) = A+2B, F(5) = 2A+3B, F(6) = 3A+5B, F(7) = 5A + 8B ... 이런 식으로 써내려 갔더니 A와 B의 계수가 피보나치 수열 인 것을 알게 되었다. d = 3 부터 이므로 d=3, d=4일 때만 A,B 계수를 정해주고 나머지 경우일 때는 피보나치 수열을 직접 구해 계수를 정해주었다. A, B의 미지수를 구해야 하는데 A가 무조건 더 작으므로 A부터 for문을 돌려 k값에 맞는 A,B값을 구해 해결하였다.
### 의견
이전에 풀어보았던 피보나치 수열 문제를 응용한 문제였다. 그래서 자연스럽게 DP문제라고 생각했다. 첫날과 둘째 날 떡의 개수를 A와 B로 미지수로 놓고 손으로 써내려갔더니 A와B

## 꽃길
https://www.acmicpc.net/problem/14620
### 문제풀이
```python
import sys
input = sys.stdin.readline



def check(a, b):
    for i in range(5):
        x = a + di[i]
        y = b + dj[i]
        if visited[x][y] == 1:
            return False
    return True
 
 
def recur(cur):
    global total, answer
    
    # 꽃을 3개 다 심었을 때 최소 코스트 갱신
    if cur == 3:
        answer = min(answer, total)
        return
 
    for i in range(1, n - 1):
        for j in range(1, n - 1):
            # 5 공간에 이미 심지 않았다면
            if check(i, j):
                for k in range(5):
                    x = i + di[k]
                    y = j + dj[k]
                    visited[x][y] = 1
                    total += g[x][y]
 
                recur(cur + 1)
                
                # 다음 재귀를 위해 초기화
                for k in range(5):
                    x = i + di[k]
                    y = j + dj[k]
                    visited[x][y] = 0
                    total -= g[x][y]
 
n = int(input())

g = []
for _ in range(n):
    g.append(list(map(int,input().split())))
 
di = [0, -1, 1, 0, 0]
dj = [0, 0, 0, -1, 1]
 
visited = [[0] * n for i in range(n)]
answer = 99999999
total = 0
recur(0)
print(answer)

```
재귀함수를 이용한 DFS문제였다.
### 의견
아직 탐색문제 실력이 많이 부족한 것 같다. 나름 시도해보려 했지만 잘 되지 않아 구글링을 하였다. 탐색무넺를 적어도 50문제 이상을 풀어보아야 될 것 같다.
