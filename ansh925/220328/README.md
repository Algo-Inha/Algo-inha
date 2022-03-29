## N-Queen
### BJ 9663
- https://www.acmicpc.net/problem/9663

```python
n=int(input())
ans=0
col=[0]*n

def check(x):
    for i in range(x):
        if col[x]==col[i] or abs(col[i]-col[x])==x-i:
	        # 같은 열에 퀸이 있거나, 왼쪽,오른쪽 대각선에 퀸이 있는 경우 -> 불가
            return False
    return True

def dfs(x):
    global ans
    if x==n:
        ans+=1
        return
    for i in range(n):
        col[x]=i
        if check(x):
            dfs(x+1)
            
dfs(0)
print(ans)
```
> - 문제를 봤을 때, 이전에 재완이형이 알설에서 프로젝트로 N-Queen 문제를 풀었던게 기억나서 cpp 코드를 보며 재귀로 풀어야겠다는 생각을 했다. 대각선 방향을 체크하는 방법은 풀이를 참고했다.
> - 한 줄에 퀸 2개가 들어가지 못하므로 열을 기준으로 체스판을 돌며 퀸을 하나씩 두면서 재귀를 통해 퀸이 오지 못하는 자리를 체크하는 방식으로 해결했다.
> - ``col[x]=i`` 는 (x, i)에 퀸을 놓겠다는 의미로 볼 수 있고, 퀸을 놓을 수 있는지 ``check()`` 한 뒤 놓을 수 없으면 ``dfs(x+1)`` 함수를 호출하여 다음 열로 넘어가 반복한다.   
   


```python
def dfs(x):
    global ans
    if x==n:
        ans+=1
        return

    for i in range(n):
        if visit[i]:
            continue
        col[x]=i
        if check(x):
            visit[i]=True
            dfs(x+1)
            visit[i]=False
```
> - 풀이를 참고하여 푼 문제인데 제출 시 시간 초과가 발생해서 이유를 찾아보니 ``python``의 언어적 특성 때문이라고 한다.
> - 시간 초과 문제를 해결하기 위해 퀸을 뒀었는지 확인하기 위한 visit[] 배열을 선언 True인 경우에만 dfs 재귀를 돌리고 ``pypy3``로 실행하면 통과 가능하다.    


---
## 종이 조각
### BJ 14391
- https://www.acmicpc.net/problem/14391

```python
# https://www.acmicpc.net/problem/14391
# 종이 조각

N, M = map(int, input().split())
arr = [list(map(int, input())) for _ in range(N)]
ans=0

def bitmask():
    global ans
    for i in range(1 << N * M):
        total = 0

        # 가로조각 합 계산
        for row in range(N):
            sum_row = 0
            for col in range(M):
                idx = row * M + col

                if i & (1 << idx) != 0:
                    sum_row = sum_row * 10 + arr[row][col]    # 가로일때, 각 자리수 계산
                else:                   
                    total += sum_row    # 세로일때, 자리수를 계산한 값을 total에 더하고
                    sum_row = 0         # sum_row 초기화
            total += sum_row

        # 세로조각 합 계산  
        for col in range(M):
            sum_col = 0
            for row in range(N):
                idx = row * M + col

                if i & (1 << idx) == 0:
                    sum_col = sum_col * 10 + arr[row][col]    # 세로일때, 각 자리수 계산
                else:
                    total += sum_col    # 가로일때, 자리수를 계산한 값을 total에 더하고
                    sum_col = 0         # sum_col 초기화
            total += sum_col

        ans = max(ans, total)           # 가장 큰 값 출력

bitmask()
print(ans)
```
   
> - 조각을 자르는 모든 경우를 따져서 합의 최대값을 구하면 되는 문제라고 생각했고, 조각의 합을 더하는 것보다는 조각을 나누는 방법을 어떤식으로 짜야될지 모르겠어서 결국 풀이를 참고했다.
> - 여러 풀이들을 봤는데, 대부분의 경우가 비트마스크로 해결했다. 비트마스크를 들어는 봤지만 정확히 어떤것인지 몰랐다.
> - `비트마스크(BitMask)`는 정수의 이진수 표현을 활용하여 부분집합을 배열이 아닌 정수를 통해 나타내는 방법으로, 메모리를 더 효율적으로 사용한다.
> - AND연산(&)과 shift연산(<<)을 사용한것 같은데, 아직 shift연산에 대해서는 정확히 이해하지 못했다.
> - 비트연산자를 사용하는 것을 제외하고는 다른 코드 부분은 아직 스스로 생각해내지는 못하겠지만 풀이를 보고 이런식으로 해결하면 되겠구나 까지는 이해가 가능한것 같다.   

#### 기타
상어 문제랑 플레티넘 문제는 아직 무리인거 같습니다...ㅜ
