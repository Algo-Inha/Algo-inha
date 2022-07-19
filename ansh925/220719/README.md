## 베르트랑 공준
### BJ 4948
```python
def sol(x):
    if x ==1:                           # 1 제외
        return False
    for i in range(2, int(x**0.5)+1):   # 2부터 루트(x)까지
        if x%i==0:					    # 약수가 있는 경우 제외
            return False
    return True						    # 위 두 경우가 아닌 경우가 소수

lst = list(range(2,246912))   # 문제의 조건에 해당하는 범위만 지정
prime_num = []
for i in lst:
    if sol(i):
        prime_num.append(i)  # 소수인 경우만 새로운 list에 저장

while True:
    n = int(input())
    count=0
    if n==0 :						    # 0 입력시 종료
        break
    for i in prime_num:
        if n < i < 2*n+1:
            count += 1      # n~2n 범위에 소수인 경우(sol) count++ 
    print(count)
```
> - 소수를 찾는 방법인 '에라토스테네스의 체' 방법 사용
> - 처음 시도 시 시간 초과 발생
> - 모든 입력에 대해 소수인지를 판별하는 것 때문으로 생각되어
   문제에서 주어진 범위에서 소수로 판별된 경우만 새로운 list에 저장
> - n~2n 범위에서 소수인 경우만 count 후 출력


## 괄호의 값
### BJ 2504
```python
stack=[]
tmp=1; ans=0

lst=list(input())

for i in range(len(lst)):       
    if lst[i]=='(':             # '(' 이면 2곱하고 stack에 저장
        tmp *= 2
        stack.append(lst[i])
    elif lst[i]=='[':           # '[' 이면 3곱하고 stack에 저장
        tmp *= 3
        stack.append(lst[i])

    elif lst[i]==')':           # ')' 일 때,
        if not stack or stack[-1]=='[':
            ans=0
            break               # 매칭 안되면 0 출력
        if lst[i-1]=='(':
            ans += tmp          # 이전 '('와 매칭되면 ans에 누적
        tmp //= 2
        stack.pop()             # '()' 이므로 2 나눠주고 stack pop

    else:                       # ']' 일 때,
        if not stack or stack[-1]=='(':
            ans=0
            break               # 매칭 안되면 0 출력
        if lst[i-1]=='[':
            ans += tmp          # 이전 '['와 매칭되면 ans에 누적
        tmp //= 3
        stack.pop()             # '[]' 이므로 3 나눠주고 stack pop

if stack:       # stack에 괄호가 남았으면 매칭 안된거이므로 0 출력
    ans=0

print(ans)
```
> - 괄호 문제를 stack으로 풀어야하는건 이전에 비슷한 문제를 풀어봐서 빠르게 캐치함
> - 소괄호, 대괄호 조건에 따라 stack에 저장해주며 짰고, testcase는 잘 돌아갔지만 제출 시 틀림
> - 풀이 코드를 참고해서 비교해봄   
  (1) list 탐색 시 range로 돌려서 이전꺼와 비교해서 매칭이 되는지 확인할 수 있도록   
  (2) 여는 괄호에서 곱해주고 append 했으면, 닫는 괄호에서는 나눠주고 pop 하는 것   
  이 부분에서 차이가 나는 것으로 보임

## 퇴사2
### BJ 15486
```python
import sys
input=sys.stdin.readline

n = int(input())
T,P=[],[]
dp=[0]*(n+1)

for _ in range(n):
    t,p = map(int,input().split())
    T.append(t)             # 상담 일수
    P.append(p)             # 상담 수익

tmp=0                       # 수익을 저장할 변수 선언
for i in range(n):
    tmp = max(tmp,dp[i])    # 이전까지 수익(tmp)과 dp 중 큰값 update
    if i+T[i] > n:          # 퇴사일을 넘기면 pass
        continue
    
    #print(i+1, dp[i+T[i]], tmp+P[i])
    # (이번 상담이 끝나는 시점의 수익)과 (이전까지 수익 + 이번 수익) 중 큰값 update
    dp[i+T[i]] = max(dp[i+T[i]], tmp+P[i])  

print(max(dp))
```
> - 지난주 부분수열 문제와 유사하게 DP로 해결하려고 여러 시도
> - 최댓값 설정해주는 부분에서 헷갈림
> - 풀이 참고해서 디버깅 하면서 확인했음에도 헷갈리는 부분 있음  
  풀이에는 (이번 상담이 끝나는 시점의 수익)과 (이전까지 수익 + 이번 수익) 중 큰값 update 라고 되어 있는데, 디버깅 해보면 첫번째 예제의 4일차(i=3)에서
(이번 상담이 끝나는 시점의 수익)이 0이 나옴. 4일차 상담은 1일짜리므로 20 나오는게 맞지 않나하는 의문.

## PuyoPuyo
### BJ 11559
```python
from collections import deque
import sys
input=sys.stdin.readline

lst=[list(input().rstrip()) for _ in range(12)]
dx=[-1,0,1,0]
dy=[0,1,0,-1]

# (1) 뿌요 탐색하는 bfs 함수
def bfs(x,y):
    q=deque()
    q.append((x,y))                     # deque인 q에 해당 좌표 저장
    tmp.append((x,y))                   # tmp 리스트에도 저장
    while q:
        a,b=q.popleft()
        for i in range(4):
            nx = a + dx[i]
            ny = b + dy[i]              # 동서남북 4방향 돌면서

            if 0<=nx<12 and 0<=ny<6 and lst[nx][ny]==lst[x][y] and visit[nx][ny]==0:
                q.append((nx,ny))
                tmp.append((nx,ny))     # 4방향중 같은 문자가 있거나 방문 안했으면 
                visit[nx][ny] = 1       # q, tmp에 저장 및 방문 체크
                                        # 같은 문자가 있는 좌표로부터 4방향 도는거 반복 수행

# (2) 뿌요 지우는 함수
def erase(tmp):
    for a,b in tmp:                     # tmp 리스트에 저장된 좌표들 전부
        lst[a][b] = '.'                 # '.'으로 바꿔주기

# (3) 뿌요 아래로 내리는 함수
def pull_down():
    for i in range(6):                  # 열 기준으로
        for j in range(10,-1,-1):
            for k in range(11,j,-1):    # 같은 열에서 아래가 '.' 위가 '문자'가 있으면
                if lst[j][i] != '.' and lst[k][i] == '.':
                    lst[k][i] = lst[j][i]  # '.' 있던 자리를 '문자'로 바꿔주고
                    lst[j][i] = '.'     # '문자' 있던 자리는 '.'으로 변경
                    break

# (4) main 함수
row=0; ans=0
while True:
    flag=False                          # 4칸 되는지 체크
    visit=[[0]*6 for _ in range(12)]    # 방문했는지 체크
    for i in range(row,12):
        if lst[i] == ['.', '.', '.', '.', '.', '.',]:
            row += 1
            visit[i] = [1, 1, 1, 1, 1, 1]
            continue                    # 모든 행이 '.'이면 pass 처리
        for j in range(6):
            if lst[i][j] != '.' and visit[i][j] == 0:
                visit[i][j] = 1         # '.'이 아니고 방문 안했으면
                tmp=[]                  # tmp 리스트 선언 및 초기화하고
                bfs(i,j)                # 해당 좌표에서 bfs함수 호출 -> bfs()

                if len(tmp) >= 4:       # tmp 리스트에 4개이상 저장되면
                    flag=True
                    erase(tmp)          # flag 처리하고 지우기 -> erase()
    
    if flag == False:                   # tmp 리스트에 4개이상 없으면
        break                           # 더이상 연쇄 안일어나므로 break

    pull_down()                         # 4개 찾고 지웠으니까 내리기 -> pull_down()
    ans += 1                            # 연쇄 횟수++

print(ans)
```
> - 크게 봤을때 방향은 얼추 맞게 생각했지만 구현하는데 있어서 생각 못한 부분이 많음
> - 풀이 코드를 보고 디버깅하며 생각해서 코드 자체는 이해가 됨 (주석 설명)
> - 유사한 형태의 구현 문제를 더 풀어보고 싶음

## 테트로미노
### BJ 14500
```python
import sys
input=sys.stdin.readline

def dfs(x, y, idx, total):
    global ans
    if ans >= total+tmp*(3-idx):
        return
    if idx==3:
        ans = max(ans, total)
        return
    else:
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0<=nx<n and 0<=ny<m and visit[nx][ny] == 0:
                if idx==1:
                    visit[nx][ny] = 1
                    dfs(x, y, idx+1, total + lst[nx][ny])
                    visit[nx][ny]= 0
                
                visit[nx][ny] = 1
                dfs(nx, ny, idx+1, total + lst[nx][ny])
                visit[nx][ny] = 0

n,m=map(int,input().split())
lst=[list(map(int,input().split())) for _ in range(n)]

dx=[-1,0,1,0]
dy=[0,1,0,-1]
visit=[([0]*m) for _ in range(n)]
ans=0
tmp=max(map(max,lst))

for x in range(n):
    for y in range(m):
        visit[x][y] = 1
        dfs(x, y, 0, lst[x][y])
        visit[x][y] = 0

print(ans)
```
> - 5가지 테트로미노를 어떻게 표현할지부터 막힌, 풀이법 자체를 생각 못해냄
> - dfs로 돌면서 블럭 모양을 탐색하는 것까지는 이해했는데, 풀이를 봐도 잘 이해가 안감
> - 여러 풀이를 보며 천천히 다시 디버깅 해봐야함

#### 총평
- 아직 골드는 벽이 느껴짐

