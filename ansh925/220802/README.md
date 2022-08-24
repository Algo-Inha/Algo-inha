# 문제 풀이

## 단지번호 붙이기
### BJ 2667
```python
from collections import deque

n = int(input())
graph = [list(map(int,input().rstrip())) for _ in range(n)]

dx = [1,-1,0,0]
dy = [0,0,1,-1]

def bfs(x,y):
    q=deque()
    q.append((x,y))
    graph[x][y] = 0         # 방문하면 0으로 갱신
    cnt = 1                 # 처음 집부터 count 1

    while q:
        x,y=q.popleft()     # deque(q)에서 하나씩 빼며
        for i in range(4):  # 4방향 돌면서
            nx = x + dx[i]
            ny = y + dy[i]

            if 0<=nx<n and 0<=ny<n and graph[nx][ny] == 1:  # 범위 안에서 graph=1 이면
                graph[nx][ny] = 0       # 방문하면 0으로 갱신
                q.append((nx,ny))       # 집이 있으므로(graph=1) 해당 위치 deque에 push 
                cnt += 1                # cnt++
    return cnt

ans=[]
for i in range(n):
    for j in range(n):
        if graph[i][j]==1:              # 집이 있는 경우
            ans.append(bfs(i,j))        # bfs 실행

ans.sort()                  # 정렬하고
print(len(ans))             # 단지 수 출력
print(*ans, sep='\n')       # 각 단지의 집 수 출력
```
> - BFS를 이용해 해결, deque 사용
> - 격자형 그래프가 있는 문제들을 bfs, dfs를 이용해 풀 때는 대체로 유사한 풀이 형태를 보임
> - 4방향을 돌며 집이 있는 경우에 bfs를 통해 방문 처리해주고 count 해주는 방식으로 해결
> - 정렬 후 단지 수와 단지별 집 수 출력

## 안전영역
### BJ 2468
```python
from collections import deque

n = int(input())
graph = [list(map(int,input().split())) for _ in range(n)]
dx = [-1,1,0,0]
dy = [0,0,-1,1]


def bfs(x,y,rain):
    q=deque()
    q.append((x,y))
    visit[x][y] = 1         # 방문했는지 체크하는 배열, 방문하면 1로 갱신

    while q:
        x,y = q.popleft()
        for i in range(4):  # 4방향 돌며
            nx = x + dx[i]
            ny = y + dy[i]

            # 범위 안쪽이면서, 방문하지 않았고, 지역의 높이가 강수량 이상일 때
            if 0<=nx<n and 0<=ny<n and visit[nx][ny]==0 and graph[nx][ny] > rain:
                visit[nx][ny] = 1       # 방문 체크
                q.append((nx,ny))       # 해당 위치 저장

max_g=0
for i in range(n):
    for j in range(n):
        max_g = max(max_g, graph[i][j])     # 가장 높은 지역의 높이 -> 최대 강수량

ans=[]
for k in range(max_g):
    visit = [[0]*n for _ in range(n)]
    cnt=0

    for i in range(n):
        for j in range(n):
            if graph[i][j] > k and visit[i][j]==0:  # 방문 안했고, 강수량보다 높은 지역
                bfs(i,j,k)      # bfs돌면서 안전지대 파악
                cnt += 1        # 안전지대 갯수 count
    ans.append(cnt)

print(max(ans))                 # 안전지대 최대치 출력
```
> - BFS를 이용해 해결, deque 사용
> - 격자형 그래프 문제인만큼, 특정 조건을 제외하고 큰 틀에서는 유사함
> - 지역 높이의 최대값까지 범위만큼 비가 올 수 있다고 가정하고, 가능한 전체 강수량에 대해서 강수량보다 높은 지역을 bfs를 통해 탐색 및 안전지대 갯수 파악
> - 자세한 설명 주석 참고


## 회의실 배정
### BJ 1931
```python
n = int(input())
lst=[]
for _ in range(n):
    a,b = map(int,input().split())
    lst.append([a,b])

lst=sorted(lst,key=lambda x:x[0])   # 회의 시작시간 기준 정렬(1)
lst=sorted(lst,key=lambda x:x[1])   # 회의 종료시간 기준 정렬(2)

end_time=0; cnt=0
for start,end in lst:               # 회의시간 중
    if start >= end_time:           # 시작시간이 종료시간보다 큰 경우 (사용 가능)
        end_time = end              # 종료시간 갱신
        cnt += 1                    # 회의++
print(cnt)
```
> - 이전에 C++로 풀었었던 문제
> - 어떤문제였는지 기억이 대략적으로 나서, 종료시간으로 한번 더 정렬해줘야하는 것 파악
> - 시작시간과 종료시간이 겹칠 수 있으므로 시작시간으로 한번, 종료시간으로 한번 더 정렬 필요
> - 정렬 후, 시작시간이 다른 회의 종료시간보다 큰 경우(늦은 경우) 회의가 가능하므로 지금 회의 종료시간으로 갱신 및  cnt++


## 타일 채우기
### BJ 2133
```python
n = int(input())

dp=[0]*31
dp[2]=3

for i in range(4,n+1,2):
    dp[i] = dp[2] * dp[i-2]
    for j in range(4,i,2):
        dp[i] += 2 * dp[i-j]
    dp[i] += 2

print(dp[n])
```
> - 점화식 : 'dp[n] = dp[2]*dp[n-2] + 2*dp[n-4] + 2*dp[n-6] + ... + 2*dp[2] + 2'
> - 점화식을 발견하고 계산 과정에 맞게 작성함
> - 질문: dp 리스트 선언할때 31말고 []*(n+1)으로 선언하면 리스트 크기가 더 작은데 왜 런타임 에러가 발생하는지


## 거리두기 확인하기
### PG 81302
```python
from collections import deque

dx = [-1,1,0,0]
dy = [0,0,-1,1]

def bfs(x,y,p):
    visit = [[0]*5 for _ in range(5)]
    q = deque()
    q.append((x,y,0))
    visit[x][y] = 1

    while q:
        x,y,dist = q.popleft()

        if 0<dist<=2 and p[x][y]=='P':
            return 0
        if dist>2:
            break

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            ndist = dist + 1
            if 0<=nx<5 and 0<=ny<5 and p[nx][ny]!='X' and visit[nx][ny]==0:
                q.append((nx,ny,ndist))
                visit[nx][ny] = 1
    return 1


def solution(places):
    answer = []
    for p in places:
        tmp=0
        for i in range(5):
            for j in range(5):
                if p[i][j]=='P':
                    if bfs(i,j,p)==0:
                        answer.append(0)
                        tmp=1
                        break
            if tmp==1:
                break
        else:
            answer.append(1)
    return answer
```
> - BFS를 이용해 해결, deque 사용
> - 다른 풀이 참고, 전체적인 코드 진행은 비슷했지만 0을 return하는 과정을 잘 표현하지 못함
> - 개발자(P)가 있는 경우마다 bfs를 돌며 멘하탄 거리만큼 떨어져 있는지 확인
> - 거리 2 이내에 한명이라도 있으면 바로 0 return하고 ans에 0 push
> - 거리 2 이내에 아무도 없으면 1 return하고 ans에 1 push
