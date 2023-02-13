# Solving

## 센서
https://www.acmicpc.net/problem/2212
### 문제풀이
```python

```
문제 이해를 못했다
### 의견
다시한번 꼼꼼히 읽어보자

## 효율적인 해킹
https://www.acmicpc.net/problem/1325
### 문제풀이
```python
import sys
input = sys.stdin.readline

from collections import deque

def bfs(s):
    cnt = 1
    q = deque()
    q.append(s)
    visit = [False for _ in range(n+1)]
    visit[s] = True
    
    while q:
        now = q.popleft()

        for next_node in graph[now]:
            if visit[next_node] == False:
                visit[next_node] = True
                cnt += 1
                q.append(next_node)
    
    return cnt

n, m = map(int,input().split())

max = 1
answer = []

graph = [[] for _ in range(n+1)]

for i in range(m):
    a,b = map(int,input().split())
    graph[b].append(a)

for i in range(1,n+1):
    cnt = bfs(i)
    if cnt > max:
        max = cnt
        answer = []
        answer.append(i)
    elif cnt == max:
        answer.append(i)
        

for i in answer:
    print(i,end=" ")
```
bfs문제라는 것을 바로 알았다. 신뢰관계를 간선으로 생각해 넓이우선탐색을 하였다.
### 의견
bfs문제를 굉장히 오랜만에 풀어서 다른 사람 코드를 좀 참고해서 해결하였다. 이전에 풀어본 문제중 도시사이에 간선이 있던 문제와 굉장히 유사한 문제였다.

## 물병
https://www.acmicpc.net/problem/1502
### 문제풀이
```python
import sys
input = sys.stdin.readline

# N,K = map(int,input().split())

# answer = 0
# count = 0
# while(1):
#     if N == K:
#         break
#     else:
#         if N % 2 == 0:
#             N = N//2
#         else:
#             N = N//2 + 1
#             answer += 2**count
#         count += 1

# print(answer)

import sys

n, k = map(int, input().split())

count = 0

while bin(n).count('1') > k:
    n = n + 1
    count = count + 1

print(count)
```
수학적인 사고가 필요한 문제였다.
### 의견
코드가 짧을 것 같다고 예상은 했다. 하지만 내가 생각한대로 풀면 예시만 생각하고 풀어서 반례가 많은 것 같았다. 다른사람 코드를 참고했지만 완벽하게 이해하지 못해 수학적인 사고로 좀 더 깊게 생각해보아야 겠다.

## N과M(12)
https://www.acmicpc.net/problem/15666
### 문제풀이
```python
#중복조합 사용

import sys
input = sys.stdin.readline

from itertools import combinations_with_replacement

n, m = map(int,input().split())

li = sorted(set(list(map(int,input().split()))))


for com in combinations_with_replacement(li, m):
        print(*com)
```
중복조합 문제였다.
### 의견
문제를 보고 리스트 값을 중복되지 않게 하고 sorting을 해서 중복조합 함수를 사용하면 될 것 같다고 생각했다. 파이썬 내장함수를 숙지하고 있진 못해서 검색을 통해 도움을 좀 받았다. 유용한 내장함수를 잘 숙지하고 있어야 겠다.

## 투에-모스 문자열
https://www.acmicpc.net/problem/18222
### 문제풀이
```python
import sys
input = sys.stdin.readline
# 시간초과 코드

# k = int(input())

# x = "0"

# while(1):
#     if len(x) == k:
#         break
#     for i in x:
#         if i == "0":
#             x += "1"
#         else:
#             x += "0"
#         if len(x) == k:
#             break
    

# print(x[k-1])

k = int(input())

def dp(x):
    if x == 0:
        return 0

    elif x == 1:
        return 1

    elif x % 2 == 0:
        return dp(x // 2)

    else:
        return 1 - dp(x // 2)


print(dp(k - 1))
```
점화식 문제였다.
### 의견
처음에는 주어진 k값에 따라 문자열을 만들어 해결하려고했다. 하지만 이런식으로 하면 시간초과가 발생하였다. 구글링을 해보니 점화식을 필요로하는 문제였다. 투에-모스 점화식을 모르면 풀기 힘들었던 것 같다.