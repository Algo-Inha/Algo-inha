# Solving

## 무기 공학
https://www.acmicpc.net/problem/18430
### 문제풀이
```python
def dfs(i, j, sum):
    global answer
    # 열을 다 탐색할 경우 오른쪽 열 탐색
    if j == m:
        i += 1
        j = 0
    # (m, n)까지 모두 탐색하고 큰 값을 answer로
    # 모든 가능한 경우의 수를 체크하고 구해진 부메랑들의 강도 합
    if i == n:
        answer = max(answer, sum)
        return
    # 사용하지 않은 나무일 경우
    # 가능한 부메랑 모양이 존재할 때
    # 부메랑으로 사용하고 가능한 모든 경우의 수를 dfs를 사용해 탐색
    if not visited[i][j]:
        for k in range(4):
            a,b,c,d = shape[k]
            x, y, xx, yy = i+a, j+b, i+c, j+d
            if 0 <= x < n and 0 <= xx < n and 0 <= y < m and 0 <= yy < m and not visited[x][y] and not visited[xx][yy]:
                visited[x][y] = visited[xx][yy] = visited[i][j] = True
                dfs(i, j + 1, sum + board[i][j] * 2 + board[x][y] + board[xx][yy])
                visited[i][j] = visited[x][y] = visited[xx][yy] = False
    dfs(i, j + 1, sum)

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
visited = [[False for _ in range(m)] for _ in range(n)]
shape = {0 : [0, -1, 1, 0], 1 : [-1, 0, 0, -1], 2 : [-1, 0, 0, 1], 3 : [0, 1, 1, 0]}
answer = 0
dfs(0, 0, 0)
print(answer)
```
브루트 포스 알고리즘을 이용한다. 열마다 돌면서 가능한 네 가지 부메랑 모양에 대해 부메랑으로 사용하고 가능한 모든 경우의 수를 dfs 알고리즘을 사용해 탐색한다. answer로 현재 answer 값과 부메랑으로 만든 나무들의 강도 합을 비교해 큰 값을 answer로 지정하고 다시 사용하지 않은 나무로 변경하여 다른 경우에 대해 탐색한다. 모든 경우의 수를 돌고 최댓값이 저장되어 있는 answer를 출력한다.
### 의견
브루트 포스 알고리즘으로 모든 경우의 수를 돌고 가능한 부메랑 강도의 최대값을 출력하는 방향으로 코드를 구성해야 한다는 것은 알았지만 모든 경우를 구성하는 방법을 생각하지 못했다. 부족한.. 브루트 포스, 재귀 알고리즘을 많이 공부해야할 것 같다.


## 기지국 설치
https://school.programmers.co.kr/learn/courses/30/lessons/12979
### 문제풀이
```python
from math import ceil

def solution(n, stations, w):
    answer = 0
    # 기지국이 전파 전달 가능한 범위
    w_range = 2 * w + 1
    start = 1

    # 기지국 전파 전달이 안되는 범위에 대해
    # 전달 가능한 범위로 나눈 값을 올림해 answer에 더하고, 
    # 시작 지점을 전파 전달 가능한 범위의 끝으로 옮긴다.
    for s in stations:
        answer += max(ceil((s - w - start)/w_range), 0)
        start = s + w + 1
    
    # 기존에 있던 모든 기지국에 대해
    # 기지국들 앞의 전파 전달을 마친 이후
    # 뒤의 남아있는 아파트들에 대해 전파 전달이 안되는 경우
    # 전달 가능한 범위로 나눈 값을 올림해 answer에 더한다.
    if n >= start:
        answer += ceil((n - start + 1)/w_range)

    return answer

n, w = map(int, input().split())
stations =[4, 11]
print(solution(n, stations, w))
```
기지국이 전파 전달 가능한 범위를 구해 기존에 설치되어 있는 기지국들 사이의 아파트들에 대해 전파 전달 가능한 범위로 나눈 값을 올림 하여 더한다. 기존해 설치되었던 기지국 중 마지막 기지국에 대해서는 전체 아파트 수보다 작을 경우 끝에 남은 아파트들에 대해 전파 전달 가능한 범위로 나눈 값을 올림해 한번 더 더한다.
### 의견
시간복잡도를 해결하는 문제였다. 접근 방식이 틀렸던 것은 아니었지만 프로그래머스 Level 3 인만큼 어려운 문제일 것이다라는 생각에 지배되어 돌아돌아 생각하게 된 문제였다. 알고보니 전파 전달이 안되는 아파트들에 대해 전파 전달 가능한 범위로 나눠 올림한 값들을 더하면 해결되는 어렵지 않은 문제였다.


## 외계인의 기타 연주
https://www.acmicpc.net/problem/2841
### 문제풀이
```python
import sys
input = sys.stdin.readline

n, p = map(int, input().split())
push = [[0] for _ in range(n + 1)]
count = 0

for _ in range(n):
    n_, p_ = map(int, input().split())
    # n_, p_ 에 대해
    # n_번째 줄의 가장 높은 프렛보다 p_ 번째 프렛이 높다면
    # p_ 번째 프랫을 누르고, count 추가한다.
    if p_ > push[n_][-1]:
        push[n_].append(p_)
        count += 1
    # n_번째 줄의 가장 높은 프렛보다 p_번째 프랫이 낮다면
    # p_번째 프랫이 더 커질 때까지 누르고 있던 프랫을 떼고, count를 추가한다.
    else:
        while push[n_][-1] > p_:
            push[n_].pop()
            count += 1
    # 마지막 프랫이 p_ 프랫보다 낮다면
    # p_ 프랫을 누르고, count 추가한다.
        if push[n_][-1] != p_:
            push[n_].append(p_)
            count += 1

print(count)

# 960ms
```
누르고자 하는 프랫이 기존 눌려져있던 프랫중 가장 높은 프랫보다 높으면 누르고자 하는 프랫을 누른다. 낮으면 낮아질 때까지 누르고 있던 프랫을 뗀다. 떼거나 누를 때 count를 센다.
### 의견
어렵지 않은 문제라고 판단하여 전체 음과 음에 대한 프렛을 2차원 리스트로 만들어 누른 프렛에 대해 True를 걸어주는 방식으로 접근했다. 하지만 메모리 초과로 실패.. 프렛을 누를 때마다 리스트에 프렛을 추가해주는 방식으로 방식을 변경했다. 변경했더니 시간초과... 하지만 시간 초과의 문제는 쉽게 해결할 수 있었다. 당연히 가장 마지막 리스트에 눌려져 있는 프렛 값이 최대 프렛 값이므로 최댓값을 따로 비교해주지 않아도 된다는 것을 알고, 오름차순 정렬을 해주지 않아도 자동으로 오름차순 정렬 순으로 리스트가 정렬되어 있는 것을 알아 시간 복잡도를 줄이는데 도움이 되었다.


## 쿼드압축 후 개수 세기
https://school.programmers.co.kr/learn/courses/30/lessons/68936
### 문제풀이
```python
def quad(x, y, temp, answer, arr):
    bin_val = arr[x][y]    
    break_ = False
    for i in range(x, x + temp):
        if break_:
            break
        for j in range(y, y + temp):
            # bin_val과 값이 같지 않을 경우 break
            if arr[i][j] != bin_val:
                break_ = True
                break
    # 정사각형 영역을 4등분 하여 각 영역에 대해 다시 quad() 함수 실행
    if break_:
        temp_2 = temp // 2
        for i in range(x, x + temp, temp_2):
            for j in range(y, y + temp, temp_2):
                quad(i, j, temp_2, answer, arr)
    else:
        answer[bin_val] += 1
                

def solution(arr):
    answer = [0, 0]

    temp = len(arr)
    quad(0, 0, temp, answer, arr)


    return answer

arr = [[1,1,1,1,1,1,1,1],[0,1,1,1,1,1,1,1],[0,0,0,0,1,1,1,1],[0,1,0,0,1,1,1,1],[0,0,0,0,0,0,1,1],[0,0,0,0,0,0,0,1],[0,0,0,0,1,0,0,1],[0,0,0,0,1,1,1,1]]
print(solution(arr))
```
quad() 함수를 만들어 정사각형 영역에 대해 모든 수가 같지 않을 경우 정사각형 영역의 크기를 가로, 세로 모두 반으로 4개의 영역으로 나누어 각 영역에 대해 영역 안의 모든 수가 같을 때 까지 반복하여 사용한다.
### 의견
어렵지 않은 재귀함수를 사용한 문제였다.
하지만 파이썬에서 함수를 사용할 때 전역변수(global) 사용과, 함수 파라미터 설정이 아직 미숙하다. quad() 함수에 사용된 함수 파라미터로 x, y, temp, answer, arr의 모든 변수를 입력했는데.. 더욱 효율적으로 함수를 만들 수 있는 방법이 있을 것 같다..


## 요세푸스 문제
https://www.acmicpc.net/problem/1158
### 문제풀이
```python
n, k = map(int, input().split())
k -= 1
temp = [(i + 1) for i in range(n)]
answer = []
num = 0

for i in range(n):
    num += k
    # num이 남은 사람의 수보다 많다면
    # 사람의 수로 나눈 나머지 번째 사람이 다음 제거 타겟
    if num >= len(temp):
        num %= len(temp)
    answer.append(str(temp.pop(num)))
print("<",", ".join(answer)[:],">", sep='')
```
### 의견
어렵지 않은 알고리즘 문제였다.
하지만 출력 방식이 좀 까다로운 문제였다.