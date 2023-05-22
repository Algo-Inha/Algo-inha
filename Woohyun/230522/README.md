# Solving

## 볼모으기
https://www.acmicpc.net/problem/17615
### 문제풀이
```python
import sys
input = sys.stdin.readline

n = int(input())
str_balls = str(input().strip())
cnt = []

right_red = str_balls.rstrip('R')
cnt.append(right_red.count('R'))

right_blue = str_balls.rstrip('B')
cnt.append(right_blue.count('B'))

left_red = str_balls.lstrip('R')
cnt.append(left_red.count('R'))

left_blue = str_balls.lstrip('B')
cnt.append(left_blue.count('B'))

print(min(cnt))

```
그리디 문제
### 의견
처음에 생각해내는데 시간이 좀 걸렸다. 빨간색 공 왼쪽, 오른쪽 파란색 공 왼쪽,  오른쪽 몰리는 경우 4가지를 생각해 해결하였다.

## 내려가기
https://www.acmicpc.net/problem/17615
### 문제풀이
```python
import sys
input = sys.stdin.readline

N = int(input())

dp_max = dp_min = list(map(int, input().split()))

for _ in range(1, N):
    numbers = list(map(int, input().split()))
    
    new_dp_max = [0]*3
    new_dp_min = [0]*3

    # 최대 점수
    new_dp_max[0] = max(dp_max[0], dp_max[1]) + numbers[0]
    new_dp_max[1] = max(dp_max) + numbers[1]
    new_dp_max[2] = max(dp_max[1], dp_max[2]) + numbers[2]

    # 최소 점수
    new_dp_min[0] = min(dp_min[0], dp_min[1]) + numbers[0]
    new_dp_min[1] = min(dp_min) + numbers[1]
    new_dp_min[2] = min(dp_min[1], dp_min[2]) + numbers[2]

    dp_max, dp_min = new_dp_max, new_dp_min

print(max(dp_max), min(dp_min))

```
dp문제
### 의견
전형적인 dp문제였지만, 메모리 초과가 발생하였다. 그래서 gpt한테 물어봐 해결했다. 이차원리스트를 여러개 만드는게 아니라 그냥 리스트로 초기화 시키며 해결하였다.



## 카드 합체 놀이
https://www.acmicpc.net/problem/15903
### 문제풀이
```python
import sys
input = sys.stdin.readline

n, m = map(int, input().split())

cards = list(map(int, input().split()))


for i in range(m):
    cards.sort()
    min_first = cards[0]
    min_second = cards[1]
    cards[0] = min_first + min_second
    cards[1] = min_first + min_second

print(sum(cards))

```
그리디 문제
### 의견
보자마자 가장 작은 값을 두개를 합쳐야겠다고 생각했다. 그래서 sorting을 해 작은 두 수를 계속 합쳐지도록 하여 구현하였다.

