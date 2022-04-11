## BJ 16234
### 인구이동
- https://www.acmicpc.net/problem/16234

```python
def bfs(a,b):
    q=deque()
    q.append([a,b])
    tmp=[]
    tmp.append([a,b])

    # deque가 빌때까지 4방향을 탐색하며 조건을 충족할 때 visit=1로 바꿔주고 q,tmp list에 좌표값 append
    while q:
        x,y=q.popleft()
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            if 0<=nx<n and 0<=ny<n and visit[nx][ny]==0:
                if l <= abs(lst[nx][ny]-lst[x][y]) <= r:
                    visit[nx][ny]=1
                    q.append([nx,ny])
                    tmp.append([nx,ny])
    return tmp

while True:
    visit=[[0]*n for _ in range(n)]
    check=False
    for i in range(n):
        for j in range(n):
            if visit[i][j]==0:
                visit[i][j]=1
                k=bfs(i,j)
                if len(k)>1:
                    check=True
                    num=sum(lst[x][y] for x,y in k)//len(k)
                    for x,y in k:
                        lst[x][y]=num
    if check==False:
        break
    cnt+=1
print(cnt)
```


## BJ 3687
### 성냥개비
- https://www.acmicpc.net/problem/3687

```python
t=int(input())
for _ in range(t):
    n=int(input())
    ans_min=[0, 0, 1, 7, 4, 2, 6, 8, 10, 18, 22]    # 성냥개비로 만들수있는 최소 수(0~7에서만 미리 선언)
    ansMax='7'*(n%2) + '1'*(n//2-(n%2))             # 성냥개비로 만들수있는 최대 수 구하는 식

    if n<=10:    # 한자리 수 일때는 그대로 출력
        print(ans_min[n], ansMax)
        continue

    ansMin=''
    while n>0:
        n=n-7
        if n>=0:
             ansMin=ansMin+'8'
        else: 
            n=n+7
            break

    small={6:6, 2:1, 5:2}
    if n in small: 
        ansMin=str(small[n])+ansMin
    else: 
        if n==1: 
            ansMin='10'+ansMin[1:]
        elif n==3: 
            ansMin='200'+ansMin[2:]
        elif n==4: 
            ansMin='20'+ansMin[1:]
    print(ansMin, ansMax)
```

> - 인구이동 문제는 deque를 이용해 bfs로 탐색하며 조건을 충족하는 경우에만 해당 좌표값을 deque 및 tmp list에 append합니다.
> 이후 visit list와 bool check를 통해 연합하는 나라인지 확인하고 연합인 경우 인구수를 분배합니다.
> - 성냥개비 문제는 DP문제처럼 최소수 초기 몇개의 값을 지정해주는 것과, 최대수를 구하는 식을 생각해내지 못했습니다.
> 풀이름 참고하였음에도 코드의 끝부분은 제대로 이해하지 못해서 추후에 다시 분석해보도록 하겠습니다.
> - 혼자 해결하려고 시도해봤으나 두 문제 모두 풀이를 참고했습니다. 시험 기간으로 인해 시간을 많이 투자하지 못한점 죄송합니다.
> 다음주는 중간고사 기간으로 인해 스터디를 진행하지 못할 것 같습니다. 그 다음주에 돌아오겠습니다.
