## 상근이의 여행
### BJ 9372
```python
def bfs(x):
    q=[x]
    visit[x]=1
    cnt=0
    while q:
        tmp=q.pop()
        for nx in lst[tmp]:
            if visit[nx]==0:
                visit[nx]=1
                cnt += 1
                q.append(nx)
    return cnt

t=int(input())
for _ in range(t):
    n,m = map(int,input().split())
    lst = [[] for _ in range(n+1)]
    visit = [0 for _ in range(n+1)]
    for _ in range(m):
        a,b = map(int,input().split())
        lst[a].append(b)
        lst[b].append(a)
    
    ans=0
    for i in range(1,n+1):
        if visit[i]==0:
            ans += bfs(i)
    print(ans)
```

```python
def bfs(x):
    q = deque([x])
    visit[x] = 1
    cnt = 0

    while q:
        q.popleft()
        for i in range(1, n + 1):
            if visit[i] == 0:
                q.append(i)
                visit[i] = 1
                cnt += 1
    return cnt

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    graph = [[0] * (n + 1) for i in range(n + 1)]

    for i in range(m):
        a, b = map(int, input().split())
        graph[b][a] = 1
    visit = [0] * (n + 1)

    print(bfs(1))
```
> - bfs를 이용해 전체 나라를 탐색하는 방식으로 해결
> - deque를 이용해서 풀었는데, 풀고난 뒤 다른 사람들의 풀이를 보니 비슷하지만 queue를 사용해서 풀면 실행 속도가 더 빠른것을 확인해서 queue 풀이도 디버깅해봄
> - 그 어이없게도 모든 나라가 연결되어있는 연결그래프 이어서 사실 (나라 수n -1) 해주면 답임

## 소수&팰린드롬
### BJ 1747
```python
def sosu(x):
    if x == 1:
        return False
    for i in range(2, int(x**0.5)+1):
        if x%i==0:
            return False
    return True	

# 팰린드롬 판별
def pallindrom(xx):
    x=str(xx)
    if len(x) % 2==0:
        front = x[:len(x)//2]
        back = x[len(x)//2:]
        bback = back[::-1]
        if front==bback:
            return True
    else:
        front = x[:len(x)//2+1]
        back = x[len(x)//2:]
        bback = back[::-1]
        if front==bback:
            return True

n=int(input())
while 1:
    if sosu(n) and pallindrom(n):
        break
    n+=1
print(n)
```

```python
# 소수 판별
def sosu(x):
    if x == 1:
        return False
    for i in range(2, int(x**0.5)+1):
        if x%i==0:
            return False
    return True	

# 팰린드롬 판별
n=int(input())
ans=0
for i in range(n,1000001):
    if str(i) == str(i)[::-1]:
        if sosu(i):
            ans=i
            break
if ans==0:
    ans=1003001
print(ans)
```
> - 이전에 썼었던 '에라토스테네스의 체' 방법으로 소수를 판별
> - 팰린드롬 판별 방법은 수 전체를 앞,뒤로 비교할 수도, 절반으로 나눠서 앞,뒤를 비교할 수도 있음
> - 최대 범위를 입력받았을 때 1003001을 강제 출력하는 것은 생각 못함
> - 풀긴했지만 실행 시간을 줄이는 방향으로 좀 더 공부 필요


## 키패드 누르기
### PG 2020 카카오 인턴십
```python
def solution(numbers, hand):
    answer = ''

    # dictionary에 키패드의 위치 정보를 좌표로 미리 저장
    keypad = {  '1':(0,0), '2':(0,1), '3':(0,2),
                '4':(1,0), '5':(1,1), '6':(1,2),
                '7':(2,0), '8':(2,1), '9':(2,2),
                '*':(3,0), '0':(3,1), '#':(3,2)
            }

    # 시작 위치
    L = keypad['*']
    R = keypad['#']

    for num in numbers: 

        # 왼쪽 손 사용 1,4,7   
        if num == 1 or num == 4 or num == 7:
            answer += 'L'           # answer에 'L' 추가
            L = keypad[str(num)]    # 위치 저장

        # 오른쪽 손 사용 3,6,9
        elif num == 3 or num == 6 or num == 9:
            answer += 'R'
            R = keypad[str(num)]

        # 가운데 부분 2,5,8,0
        else:
            # 2,5,8,0에서 왼손,오른손까지의 거리 측정
            L_dist = abs(L[0] - keypad[str(num)][0]) + abs(L[1] - keypad[str(num)][1])
            R_dist = abs(R[0] - keypad[str(num)][0]) + abs(R[1] - keypad[str(num)][1])

            if L_dist < R_dist:
                answer += 'L'
                L = keypad[str(num)]
            elif L_dist > R_dist:
                answer += 'R'
                R = keypad[str(num)]

            # 거리 같은 경우 오른,왼손잡이 따라 판단
            else:
                if hand == 'right':
                    answer += 'R'
                    R = keypad[str(num)]
                else:
                    answer += 'L'
                    L = keypad[str(num)]
    return answer

print(solution([1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5], "right"))
```
> - 키패드의 위치를 dictionary에 미리 저장해두고 해결하는 방법을 떠올리지 못함. dictionary보다는 list가 더 친숙해서 잘 안쓰게 되는데, dictionary도 자주 써보면서 익숙해져야할 필요가 있음
> - dictionary를 활용한 점 외에 풀이 자체는 간단한 편. 주어진 조건대로 코드 작성


## 이진 변환 반복하기
### PG 월간 코드 챌린지 시즌1
```python
def solution(x):
    answer = []
    a,b = 0,0

    while 1:
        if x == '1':
            break
        b += x.count('0')

        x = x.replace('0','')
        c = len(x)
        x = bin(c)[2:]
        
        a += 1
    answer = [a,b]
    return answer
```
> - 최종 답이 1이 될때까지 while문을 돌며 반복
> - while 한번마다 0 개수 세서 저장(b), 0 제거(replace)하고 문자열 길이(len)를 2진수로 변환(bin)
> - 총 while문 돌아간 횟수 저장(a)하고 [a,b] 출력


## 탑
### BJ 2493
```python
n=int(input())
height = list(map(int,input().split()))
s=[]
ans=[0]*n

for i in range(n):
    while s:
        if height[s[-1]] < height[i]:
            s.pop()
        else:
            ans[i] = s[-1] + 1
            break
    s.append(i)
print(*ans)
```
> - 앞쪽(왼쪽) 건물부터 순서대로 그 다음의 건물들의 높이와 비교해서 앞 건물이 더 낮은 경우 레이저가 통과하므로 pop, 더 높은 경우 레이저를 수신하므로 해당 건물의 ans 위치에 수신 건물 위치 저장
> - 골드 단계 치고는 단순했던 문제, 처음에 너무 어렵게 생각해서 꽤 오래 해메다가 쉬운 방법으로 돌아와서 해결할 수 있었음
