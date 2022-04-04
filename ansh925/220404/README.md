## 최대 힙
### BJ 11279
- https://www.acmicpc.net/problem/11279   
```python
import heapq
import sys
input=sys.stdin.readline

lst=[]
n=int(input())
for _ in range(n):
    x=int(input())
    
    if x==0:
        if lst:
            print(-1*heapq.heappop(lst))
            # heappush에서 반대로 넣어줬으므로, pop할 때도 다시 -를 붙여준다
        else:
            print(0)
    else:
        heapq.heappush(lst,-x)
        # heap에 push할 때, -를 붙여줌으로써 실제 우선순위와 반대로 들어가게함
```

> - 문제 이름이 최대 '힙'인 것은 알지만 파이썬에서 heap을 구현하는 법을 몰라 일단 처음에는 생각나는대로 짜봤다. 많이 어렵지 않게 코드를 작성했고, 답은 맞게 나왔지만 당연하게도 시간 초과가 발생했다.
> - 찾아보니 `heapq`를 import함으로써 힙을 구현할 수 있었고, queue나 deque와 유사하게 pop과 push 문법으로 사용되는 것으로 보인다. 
> - 주의할점은 기본적으로 heapq는 최소힙이므로 push 또는 pop을 할 때 우선순위를 반대로 해주기 위해 -를 붙여주어 최대힙으로 사용해야한다.   
   

## 강의실 배정
### BJ 11000
- https://www.acmicpc.net/problem/11000

```python
import sys
import heapq
input=sys.stdin.readline

heap,lst=[],[]
n=int(input())
for i in range(n):
    a, b = map(int, input().split())
    lst.append([a, b])

lst.sort(key=lambda x: x[0])    # 강의시작시간 기준으로 sort
                                # 각 배열에서 0번째를 기준으로 정렬. ex) [[a,b],[c,d],[e,f]] -> a,c,e를 기준으로 정렬

heapq.heappush(heap, lst[0][1])
cnt=1

for i in range(1, n):
    if heap[0] > lst[i][0]:
        heapq.heappush(heap, lst[i][1])     # heap에 push할때마다 cnt++
        cnt+=1
    else:
        heapq.heappop(heap)
        heapq.heappush(heap, lst[i][1])     # 이때는 pop한 뒤 push이므로 cnt++ 안함

print(cnt)
```
> -  이전에 여러 트럭이 하중을 버티며 다리를 건너는 형태의 유사한 문제를 풀어본 적이 있어서 같은 풀이법으로 list에 강의 시작시간과 종료시간을 (key, value)로 묶어서 넣어준 후 시작 시간을 기준으로 정렬해서 해결해야겠다고 생각을 했다. 테스트 케이스로 실행했을 때는 원하는 답이 나오지만, 제출 시 시간초과 나와 결국 풀이를 참고했다.
> - 앞선 문제처럼 heap을 사용해서 시간 초과 문제를 해결할 수 있었다. 기존에 작성한 list 풀이에 heap으로 대체 해주는 것만으로 시간 초과가 해결되었다. 주의할 점은 lst의 경우 for문을 돌때마다 다시 정렬을 해줘야했는데, heap은 기본적으로 최소힙을 유지하므로 지속적인 정렬이 필요가 없다.
> - 두 문제 연속으로 heap을 사용하면서 heap의 활용도에 대해 알 수 있는 기회였다.   

## 연구소
### BJ 14502
- https://www.acmicpc.net/source/40291923   

```python
def bfs():
    global ans
    graph2=[[0]*m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            graph2[i][j]=graph[i][j]

    cnt=0
    tmp=[]
    for i in range(n):
        for j in range(m):
            if graph2[i][j]==2:
                tmp.append([i,j])
    
    while tmp:
        x,y=tmp[0][0],tmp[0][1]
        del tmp[0]
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            if 0<=nx<n and 0<=ny<m:
                if graph2[nx][ny]==0:
                    graph2[nx][ny]=2
                    tmp.append([nx,ny])
    
    for s in graph2:
        for k in s:
            if k==0:
                cnt+=1
    ans=max(ans,cnt)
```   
```python
def new_wall(t):
    if t==3:
        bfs()
        return
    for i in range(n):
        for j in range(m):
            if graph[i][j]==0:
                graph[i][j]=1
                new_wall(t+1)
                graph[i][j]=0
```

> - 이전에 bfs와 dfs 탐색 문제들을 연습할때 시도해봤던 문제였고 혼자 해결하지 못해서 풀이를 참고했었다. 이번에는 풀이를 안보고 해결해보려고 노력했으나 한 번 풀어본 문제임에도 풀이법을 잘생각해내지 못해서 다시 또 풀이를 참고했다.
> - bfs를 돌며 탐색하는 코드까지는 전체적인 틀이 비슷해서 작성했는데, 벽을 세우는 방식을 잘 구현하지 못해서 결국 실패했다.    	

#### 기타
- 다다음주에 중간고사라서 다음주 스터디까지 시간을 많이는 투자 못할것 같습니다..! 3설계를 이해해주십쇼..
