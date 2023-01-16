# Solving

## 정사각형
https://www.acmicpc.net/problem/1485
### 문제풀이
```python
import sys
input = sys.stdin.readline

T = int(input())



for test in range(T):
    li = [[] for _ in range(4)]
    length_li = []
    for i in range(4):
        x, y = map(int,input().split())
        li[i].append(x)
        li[i].append(y)


    for i in range(1,4):
        a = (li[0][0] - li[i][0])**2 + (li[0][1] - li[i][1])**2
        length_li.append(a)

    for i in range(2,4):
        a = (li[1][0] - li[i][0])**2 + (li[1][1] - li[i][1])**2
        length_li.append(a)

    for i in range(3,4):
        a = (li[2][0] - li[i][0])**2 + (li[2][1] - li[i][1])**2
        length_li.append(a)

    length_li.sort() 

    if length_li.count(length_li[0]) == 4 and length_li.count(length_li[-1]) == 2 and (0 not in length_li):
        print(1)
    else:
        print(0)
```
사각형이 네변의 길이가 같고 대각선의 길이가 같으면 정사각형이다 라는 조건을 사용했다.
### 의견
다른 정사각형 정의로도 풀 수 있기 때문에 여러 풀이방법이 있을 것 같다.


## 게임
https://www.acmicpc.net/problem/1072
### 문제풀이
```python
# 시도했었던 코드

# import sys
# input = sys.stdin.readline

# x, y = map(int,input().split())

# z = int(y/x * 100)
# new_z = 0
# count = 0
# while(1):
#     count += 1
#     x += 1
#     y += 1
#     new_z = int(y/x * 100)
#     if new_z != z or x == y:
#         break

# if x == y:
#     print(-1)
# else:
#     print(count)

import sys
input = sys.stdin.readline

N , M = map(int,input().rstrip().split())

Z = (M *100)//N
ans = 0

if Z >= 99:
    print(-1)
else:
    ans = 0
    start =1
    end = 1000000000

    while start <= end:
        mid = (start+end)//2
        if (M+mid)*100 // (N+mid) > Z:
            ans = mid
            end = mid -1
        else:
            start = mid+1
    print(ans)
```
이분탐색 알고리즘을 사용하였고, (100*a//b) int( a / b)*100 의 차이점 고려(부동소수점)
### 의견
처음 문제를 보고 쉬울 것 같다고 생각했지만  시간초과가 발생했었다. greedy알고리즘에 익숙해져서 그런지 이분탐색은 생각도 못하고 있었다. 시간 초과가 발생했을 때 이분탐색 방법도 고려를 해봐야겠다. 

## N과 M (1)
https://www.acmicpc.net/problem/15649
### 문제풀이
```python
import sys
input = sys.stdin.readline

def dfs():
    if len(li) == M:
        for i in li:
            print(i,end=" ")
        print()
        return
    
    for i in range(N):
        if (i+1) not in li:
            li.append(i+1)
            dfs()
            li.pop()

N, M = list(map(int, input().split()))

li = []
 
dfs()
```
백트래킹 문제이기 때문에 dfs로 접근
### 의견
재귀에 익숙하지 않아 백트래킹 공부후 접근하였다. 위처럼 dfs로 직접 구현하는게 아니라 permutations를 이용해 더 간단하게 풀이한 방법도 보았다. 파이썬에서 쓰이는 기능을 잘 사용해야겠다.

## 배열 돌리기1
https://www.acmicpc.net/problem/16926
### 문제풀이
```python
import sys
input = sys.stdin.readline

n, m, r = map(int, input().split())
graph = []
for i in range(n):
    graph.append(list(map(int,input().split())))


for rotate in range(r):
    for i in range(int(min(n, m) / 2)):
        x, y = i, i
        value = graph[x][y]

        for j in range(i+1, n-i):  #왼쪽
            x = j
            value_temp = graph[x][y]
            graph[x][y] = value
            value = value_temp

        for j in range(i+1, m-i):  #아래
            y = j
            value_temp = graph[x][y]
            graph[x][y] = value
            value = value_temp

        for j in range(i+1, n-i):  #오른쪽
            x = n - j - 1
            value_temp = graph[x][y]
            graph[x][y] = value
            value = value_temp

        for j in range(i+1, m-i):  #위
            y = m - j - 1
            value_temp = graph[x][y]
            graph[x][y] = value
            value = value_temp

for i in range(n):
    for j in range(m):
        print(graph[i][j], end=' ')
    print()
```
배열을 돌릴 때 좌,우,위,아래마다 옮겨서 구현하였고, 이전 값을 미리 저장해 두면서 값을 Update하는 방식으로 해결, min(n,m)//2는 안으로 들어가서 배열을 돌리는 수와 같다.
### 의견
처음 얼마만큼 배열 안으로 들어가 배열을 돌려야 되는지 고민을 하다가 min(n,m)//2는 안으로 들어가서 배열을 돌리는 수와 같다는 힌트를 보고 다시 구현하였다. 배열을 돌리는 방식은 한쪽 한쪽 부분만 구현하면 전체다 똑같은 방식이기 때문에 금방 구현할 수 있었다.