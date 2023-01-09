# Solving

## 경로 찾기
https://www.acmicpc.net/problem/11403
### 문제풀이
```python
import sys
input = sys.stdin.readline

n = int(input())
graph = []
for _ in range(n):
    graph.append(list(map(int, input().split())))
    
#플로이드-워셜 알고리즘
for k in range(n): #경로 for문이 가장 상위 단계여야 누락되지 않는다
    for i in range(n):
        for j in range(n): 
            if graph[i][j] == 1 or (graph[i][k] == 1 and graph[k][j] == 1):
                graph[i][j] = 1

for i in range(n):
    print(*graph[i])
```
플로이드-워셜 알고리즘을 사용한다.
### 의견
처음 시도에는 입력 행렬에서 각 간선을 n번까지 타는 재귀함수를 사용하여 각 정점에서 다른 정점으로 가는 경로를 모두 탐색했다. 하지만 시간 초과가 발생하여 다른 알고리즘을 생각하다 플로이드-워셜 알고리즘을 발견하여 해당 알고리즘을 사용해 해결했다.


## 수리공 항승
https://www.acmicpc.net/problem/1449
### 문제풀이
```python
import sys
input = sys.stdin.readline

n, l = map(int, input().split())
graph = [False for _ in range(1001)]
cnt = 1

water = list(map(int, input().split()))
water.sort()

for i in water:
    graph[i] = True

end = water[0] + l - 1
for i in range(1, len(water)):
    if water[i] > end:
        end = water[i] + l - 1
        cnt += 1
print(cnt)
```
테이프를 사용한 end 지점을 기준으로 물이 새는 곳보다 end가 더 0과 가깝다면 테이프를 하나 더 사용했다.
### 의견
물이 새는 곳이 한 칸이어서 문제에서 말하는대로 코드를 구성하여 해결했다.


## 카드2
https://www.acmicpc.net/problem/2164
### 문제풀이
```python
from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
card = deque((i + 1) for i in range(n))

while len(card) > 1:
    card.popleft()
    x = card.popleft()
    card.append(x)

print(*card)
```
card 이름의 큐를 만들어 맨 앞 수를 버리고 그 다음 수를 맨 뒤에 넣는 과정을 큐의 크기가 1이 될 때까지 반복한다.
### 의견
큐를 사용하여 해결했다.


## 스위치 켜고 끄기
https://www.acmicpc.net/problem/1244
### 문제풀이
```python
import sys
input = sys.stdin.readline
n = int(input())    # 100 이하 자연수
switch = list(map(int, input().split()))    # n개 스위치 상태
nStu = int(input())     # 학생 수
for i in range(nStu):
    s, num = map(int, input().split())    # 성별, 받은 수
    num -= 1
    if s == 1:  # 남학생일 경우
        for j in range(num, n, num + 1):
            if switch[j] == 1:
                switch[j] = 0
            elif switch[j] == 0:
                switch[j] = 1
    elif s == 2:    # 여학생일 경우
        temp = 0
        while (0 <= num - temp and num + temp < n):
            if switch[num - temp] == switch[num + temp]:
                if switch[num - temp] == 1:
                    switch[num - temp] = 0
                    switch[num + temp] = 0
                elif switch[num - temp] == 0:
                    switch[num - temp] = 1
                    switch[num + temp] = 1
            else:
                break
            temp += 1
if len(switch) <= 20:   # 스위치 길이 21보다 작을 때
    print(*switch)
else:   # 스위치 길이 20보다 클 때
    for i in range(len(switch)):
        print(switch[i], end=' ')
        if (i + 1) % 20 == 0:
            print()
```
남학생일 경우 for문에서 선택한 자연수 크기만큼 더해가며 상태를 변경했고, 여학생일 경우 while문 조건에 맞을 때 temp 값을 더하고 뺀 값의 상태가 같을 경우 상태를 변경하고 temp 값을 1씩 키웠다. 
마지막으로 출력할 때 20보다 스위치 개수가 많을 경우 20개씩 끊어서 출력할 수 있도록 구성했다.
### 의견
구현 문제, 자연수 n 값, num 값을 다룰 때 주의가 필요함.


## 회의실 배정 2
https://www.acmicpc.net/problem/19621
### 문제풀이
```python
import sys
input = sys.stdin.readline

n = int(input())
time = [0]  # 회의 진행 시간
total = [0]     # 최대 인원
for _ in range(n):
    a, b, t = map(int, input().split())
    time.append(t)
time.append(0)

# i 번째 회의를 진행할 경우 
# (i - 1)번째 최댓값이었던 회의 시간과 비교하여 
# 큰 경우를 i번째 회의 시간의 최댓값으로 
total.append(time[1])
for i in range(2, n + 1):   
    total.append(max(total[i - 2] + time[i], total[i - 1]))

print(total[-1])
```
점화식을 세워 회의 진행 가능한 최대 인원을 구한다.
### 의견
많이 접했던 문제였지만, 매번 점화식을 생각하지 못해 구글의 힘을 빌렸던 문제였다. 하지만 이번 기회에 끝까지 생각해보며 풀어보고 싶은 마음에 계속 고민과 고민을 반복한 끝에 점화식을 생각해낼 수 있었고, 다음에 이런 문제가 나온다면 더욱 빠른 시간 안에 해결할 수 있을 것 같다.