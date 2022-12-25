# Solving

## 감소하는 수
https://www.acmicpc.net/problem/1038
### 문제풀이
```python
import sys
from itertools import combinations

input = sys.stdin.readline

n = int(input())

temp = list()
for i in range(1, 11):  # 1부터 10까지
    for j in combinations(range(0, 10), i): # 10개 중 i개씩 모든 경우의 수
        comb = list(j)
        comb.sort(reverse=True) # 각 내림차순 정렬
        temp.append(int("".join(map(str, comb))))   # string으로 바꿔 합치고 다시 int로

temp.sort() # 전체 정렬

if n >= len(temp):  # 9876543210보다 큰 수는 없음
    print(-1)
else:
    print(temp[n])
```
전체 경우의 수 모두 combinations를 사용해 구한다. 
9876543210보다 큰 수는 없으므로 해당 경우를 제외하고 n번째 index 값 출력
### 의견
감소하는 수이므로 9876543210보다 큰 경우가 존재하지 않는다는 것을 파악하여 접근했다.
0 ~ 9까지 10개의 수 중에 1개부터 10개까지 모두 combinations를 사용해 경우의 수를 구해 정렬하면 모든 경우의 수 또한 쉽게 구할 수 있다는 판단을 했다.


## 흙길 보수하기
https://www.acmicpc.net/problem/1911
### 문제풀이
```python
import sys
input = sys.stdin.readline

n, l = map(int, input().split())
p = list()
for _ in range(n):
    p.append(list(map(int, input().split())))
p.sort(key=lambda x:x[0])

loc = 0     # 마지막 널빤지 위치
cnt = 0   # 널빤지 수

for start, end in p:    
    if loc > start: # 이전 웅덩이 덮고 남은 널빤지가 현재 웅덩이 덮을 경우
        start = loc
    while start < end:  # 널빤지 개수 count
        start += l
        cnt += 1
    loc = start

print(cnt)
```
전체 웅덩이 경우를 흙길 순서대로 정렬한다.
첫 웅덩이부터 마지막 웅덩이까지 널빤지가 다음 웅덩이까지 덮을 경우를 생각해 널빤지의 개수를 count 한다.
### 의견
문제에서 제시한 대로 문제 풀이를 진행하였더니 시간 초과가 발생했다.
while문을 좀 손봐야 할 듯 하다.

## 오르막 수
https://www.acmicpc.net/problem/11057
### 문제풀이
```python
import sys
input = sys.stdin.readline

num = int(input())
temp = [[] for _ in range(num + 1)]
temp[0].append(0)
temp[1].append(10)

#   1   1   1   1   1   1   1   1   1   1   += 10
#   1   2   3   4   5   6   7   8   9   10  += 55
#   1   3   6   10  15  21  28  36  45  55  += ...
#   ...

if num > 1:
    for i in range(1, 11):
        temp[2].append(i)
    # [[0], [10], [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], [], [], ...]

    if num > 2:
        for i in range(3, num + 1):
            total = 0
            for j in range(10):
                total += temp[i-1][j]
                temp[i].append(total)
            print(temp)

print(sum(temp[-1])%10007)
```
수의 길이까지 모든 가능한 오르막수의 경우의 수를 구한다.
가능한 경우의 수를 적어가며 규칙을 찾는다.
### 의견
모든 경우의 수를 적어가다 보면 쉽게 규칙을 찾을 수 있다.

## 두 큐 합 같게 만들기
https://school.programmers.co.kr/learn/courses/30/lessons/118667
### 문제풀이
```python
from collections import deque
def solution(queue1, queue2):
    answer = 0
    queue1, queue2 = deque(queue1), deque(queue2)
    sum1, sum2 = sum(queue1), sum(queue2)
    
    for _ in range(3*len(queue1)):  # 큐 크기 x 3 횟수 실행!!
        if sum1 > sum2:
            sum1 -= queue1[0]
            sum2 += queue1[0]
            queue2.append(queue1.popleft())
        elif sum1 < sum2:
            sum1 += queue2[0]
            sum2 -= queue2[0]
            queue1.append(queue2.popleft())
        else:
            return answer
        answer += 1
    return -1
```
두 개의 큐 값들의 합을 비교하며 큰 쪽에서 작은 쪽으로 하나씩 pop and insert 한다.
큐 크기의 3배만큼의 횟수를 진행해도 큐 값들의 합이 같아지지 않을 경우 -1 출력한다.
### 의견
큐 크기의 3배만큼 횟수를 진행할 생각을 하지 못했다.
센스의 부족.