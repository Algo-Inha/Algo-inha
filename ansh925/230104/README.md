## 동전0
- https://www.acmicpc.net/problem/11047
```python
n,k = map(int,input().split())
lst=[]
for _ in range(n):
    lst.append(int(input()))

cnt = 0
for i in range(n-1,0,-1):   # 역순 탐색
    if k==0:                # 잔액 0이면 종료
        break
    cnt = cnt + k//lst[i]   # 몫만큼 cnt++
    k = k % lst[i]          # 나머지만큼 k 유지
print(cnt)
```
- 코드 자체는 짧은데, 연산식을 생각해내는데 시간이 굉장히 오래 걸렸습니다.

## 파도반 수열
- https://www.acmicpc.net/problem/9461
```python
dp = [0 for _ in range(101)]
dp[1]=1; dp[2]=1; dp[3]=1
for i in range(4,101):
    dp[i] = dp[i-3] + dp[i-2]

t = int(input())
for _ in range(t):
    n = int(input())
    print(dp[n])
```
- 1 1 1 2 2 3 4 5 7 9
- (1)번째+(2)번째 => (4)번째 규칙성을 가지고 있어서 점화식으로 해결했습니다.

## 곱셈
- https://www.acmicpc.net/problem/1629
```python
a,b,c = map(int,input().split())

def DnC(x,y):
    if y==1:
        return x % c
    tmp = DnC(x, y//2)
    
    if y % 2 == 0:
        return tmp * tmp % c
    else:
        return tmp * tmp * x % c

print(DnC(a,b))
```
- 당연히 그냥은 시간초과가 났고, 풀이법을 모르겠어서 풀이를 참고했습니다.
- 분할정복을 쓰는거라던데 제곱/나머지의 분할정복 공식을 모르면 풀지 못할 것 같고, 풀이를 참고했는데도 여전히 재귀는 이해하기 쉽지 않습니다.
- 재귀는 디버깅하기도 어려워서 재귀가 아닌 다른 풀이로 풀려는 경향이 항상 있는데, 천천히 재귀도 이해 해가야할것 같습니다.

## 유기농배추
- https://www.acmicpc.net/problem/1012
```python
dx = [-1,1,0,0]
dy = [0,0,-1,1]

def bfs(x,y):
    q = [(x,y)]
    visit[x][y] = 0
    while q:
        x,y = q.pop(0)
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]            
            if 0<=nx<m and 0<=ny<n and visit[nx][ny] == 1:
                    q.append((nx,ny))
                    visit[nx][ny] = 0

t = int(input())
for _ in range(t):
    m,n,k = map(int,input().split())
    visit = [[0]*n for _ in range(m)]
    
    for _ in range(k):
        a,b = map(int,input().split())
        visit[a][b] = 1
        
    cnt = 0
    for i in range(m):
        for j in range(n):
            if visit[i][j] == 1:
                bfs(i,j)
                cnt += 1
    print(cnt)
```
- 오랜만이라 잘 기억은 안났지만, 전에 bfs 문제를 많이 풀었어서 다행히 보통의 bfs문제와 비슷한 형태로 풀 수 있었습니다.
- 다만, 역시나 같은 이유로 재귀를 활용한 dfs풀이는 익숙치 않아서 연습이 필요할 것으로 보입니다.


