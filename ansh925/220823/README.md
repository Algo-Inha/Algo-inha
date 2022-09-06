## 숨바꼭질
### BJ1697
```python
def bfs(x):
    q=deque()
    q.append(x)                   # 수빈이 위치에서 시작
    while q:
        x=q.popleft()

        if x==k:                  # 동생을 잡으면 return 
            return check[x]       # 방문 체크를 노드 깊이로 설정 시,
                                  # 여기까지 걸린 시간을 의미하기도 함
        for nx in (x-1,x+1,2*x):  # 뒤로, 앞으로, 순간이동 3가지 경우 고려
            if 0<=nx<100001 and not check[nx]:  # 범위 제한 & 방문 체크
                check[nx] = check[x]+1          # 방문 안했으면 이전 위치값 +1
                q.append(nx)      # deque에 다음 위치 push

check=[0]*100001
n,k=map(int,input().split())
print(bfs(n))
```


> - 격자 형식의 bfs가 아니라 한줄짜리 bfs라 더 쉬울줄  알았지만, 그래서 오히려 더 헤맸음
> - 반복문 및 조건문은 생각했는데, 수빈이가 동생을 잡았을때 어떻게 걸린시간을 구할지 못 찾음
> - bfs(너비우선탐색)에서 방문 체크를 노드의 깊이로 설정한 경우 체크된 값이 해당 위치까지 탐색하는데 걸린 시간을 의미하는 것을 다시 확인함

## 줄어들지않아
### BJ2688
> - 점화식 생각해보다가 못찾겠어서 풀이 참고
> - 점화식 풀이, 위 풀이 두 가지 방법을 찾았는데 이게 좀 더 간단하고 신박함
> - 마지막 자리에 올 0~9에 대한 10 사이즈 리스트를 만들어서 마지막 자리별로 줄어들지 않는 수의 개수를 저장. 마지막에 해당 리스트 합 구하면 그 자리수에서의 총 줄어들지 않는 수의 개수 파악 가능
> - 1부터 시작해서 앞부터 한칸씩 더해주고, 자리수 올라갈수록 더한 리스트의 값에 누적해서 반복
```python
t=int(input())
for _ in range(t):
    n=int(input())

    dp=[1 for _ in range(10)]
    for i in range(n-1):
        for j in range(10):
            dp[j] = sum(dp[j:])
    print(sum(dp))
```


## 쇠막대기
### BJ10799 
> - '()'가 레이저를 의미하므로 replace로 먼저 처리
> - 레이저를 제외한 후에는 모두 쇠막대기의 시작 또는 끝이므로 쇠막대기 시작할때 stack에 push, 끝날때 1개가 잘리므로 pop하고 ans +1
> - 레이저인 경우 모두 잘리므로 시작한 쇠막대기 수(stack수) 만큼 ans++ 
```python
lst=input().rstrip()
ray=lst.replace('()','#')       # 레이저 부분 replace

ans=0
stack=[]
for i in range(len(ray)):
    if ray[i]=='(':             # 쇠막대기 시작할때 stack push
        stack.append('*')
    elif ray[i]==')':           # 쇠막대기 끝날때 stack pop하고 1개 절단 ++
        stack.pop()
        ans += 1
    else:                       # 레이저면 stack에 쌓인 쇠막대기 수만큼 ++
        ans += len(stack)
print(ans)
```


## 표편집
### PG81303
> - linked list로 행들을 구현해야하는 걸 생각 못함
> - dictionary를 활용해서 key에는 현재 행 번호를, value에는 이전행과 다음행을 나타내도록 저장
> - answer 리스트에 행의 유무를 나타내는 O/X 저장
> - stack에 [이전행,현재행,다음행] 정보 저장
```python
def solution(n, k, cmd):
    # dictionary로 linked list 구현 -> key: 행 번호, value: [이전행,다음행]
    table = { i:[i - 1, i + 1] for i in range(n) }
    answer = ['O'] * n          # 행 존재 여부 O/X 표시
    table[0] = [None, 1]        # 처음 행 설정
    table[n - 1] = [n - 2, None]# 마지막 행 설정    
    stack = []    
    
    for c in cmd:        
        if c == "C":            # 행 삭제
            answer[k] = 'X'     # 행 삭제 후 X 표시       
            prev, next = table[k]            
            stack.append([prev, k, next])      

            if next == None:    # 마지막 행이면 윗 행 선택            
                k = table[k][0]            
            else:               # 그 외에는 다음 행 선택
                k = table[k][1]     

            if prev == None:           
                table[next][0] = None            
            elif next == None:                
                table[prev][1] = None            
            else:
                table[prev][1] = next    # 현재행 삭제 후 이전행과 다음행 연결            
                table[next][0] = prev         
        
        elif c == "Z":          # 행 복구
            prev, now, next = stack.pop()            
            answer[now] = 'O'   # 행 복구 후 O 표시
            if prev == None:                
                table[next][0] = now            
            elif next == None:                
                table[prev][1] = now            
            else:                
                table[next][0] = now                
                table[prev][1] = now   

        else:                   # 행 이동   
            UD, num = c.split(' ')            
            num = int(num)            
            if UD == 'D':       # 아래로        
                for _ in range(num):                    
                    k = table[k][1]            
            else:               # 위로 
                for _ in range(num):                    
                    k = table[k][0]    

    return ''.join(answer)

print(solution(8,2,["D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z"]))
```
