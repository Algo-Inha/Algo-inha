# Solving

## 이모티콘 할인행사
https://school.programmers.co.kr/learn/courses/30/lessons/150368
### 문제풀이
```python
discounts = [10, 20, 30, 40]
answer = [-1, -1]

def solution(users, emoticons):
    n, m = len(users), len(emoticons)
    discount_list = [0]*m
    
    def search(idx):
        global answer
        if idx == m :
            sale_num, cost_num = 0, 0
            for i in range(n) :
                tmp = 0
                for j in range(m) :
                    if users[i][0] <= discount_list[j] :
                        tmp += emoticons[j] * ( 100 - discount_list[j] ) // 100
                if tmp >= users[i][1] :
                    sale_num += 1
                else :
                    cost_num += tmp
            if sale_num > answer[0] or sale_num == answer[0] and cost_num > answer[1] :
                answer = [sale_num, cost_num]
            return
        
        for i in range(4) :
            discount_list[idx] = discounts[i]
            search(idx+1)
    
    search(0)
    
    return answer

```
모든 경우를 모두 계산해 값을 도출해 내는 문제였다.
### 의견
카카오 문제라 좀 어렵긴 했다. 문제 아이디어는 금방 생각해냈지만, 스스로 풀지는 못하였다. 백트래킹 연습좀 더하자.

## 부등호
https://www.acmicpc.net/problem/2529
### 문제풀이
```python
import sys
input = sys.stdin.readline


n = int(input())
ineq = list(map(str,input().split()))

visited = [False] * 10
max = ""
min = ""

def check(a,b,i):
    if i == "<":
        return a < b
    else:
        return a > b
    
def dfs(depth,s):
    global max, min
    
    if depth == n + 1:
        if len(min) == 0:
            min = s
        else:
            max = s
        return
    
    for i in range(10):
        if not visited[i]:
            if(depth == 0 or check(s[-1], str(i), ineq[depth-1])):
                visited[i] = True
                dfs(depth + 1, s + str(i))
                visited[i] = False


dfs(0,"")
print(max)
print(min)
            
```
누가봐도 백트래킹 문제
### 의견
이번 스터디 문제중에서는 그나마 풀만한 문제였다. 그래도 백트래킹 실력은 더 키워야 겠다.



## 수 묶기
https://www.acmicpc.net/problem/2240
### 문제풀이
```python
import sys
input = sys.stdin.readline

T, W = map(int,input().split())
 
li = []
dp = [[0 for _ in range(W+1)] for _ in range(T)]
 
for _ in range(T):
    li.append(int(input()))
 
for i in range(T):
    for j in range(W+1):
        if j==0:
            if li[i] == 1:
                dp[i][0] = dp[i-1][0] + 1
            else:
                dp[i][0] = dp[i-1][0]
        else:
            if li[i] == 1 and j % 2 == 0:
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + 1
            elif li[i] == 2 and j%2 == 1:
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1])
print(max(dp[-1]))



```
dp문제
### 의견
dp문제라는것은 금방 알 수 있었지만, 점화식은 풀지 못하였다. 구글링을 통해 해결하였다. dp문제 안푼지 오래돼서 감이 벌써 다 떨어졌다. dp쉬운문제부터 다시 연습해야겠다.

