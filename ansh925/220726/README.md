
## 다리 놓기
### BJ 1010
```python
t=int(input())
for _ in range(t):
    n,m=map(int,input().split())
    dp=[[0]*(m+1) for _ in range(n+1)]  # 2차원 리스트 생성

    for i in range(1,n+1):
        for j in range(1,m+1):          # 리스트를 전부 돌며
            if i==1:
                dp[i][j] = j            # 첫번째는 순서대로 채워주고
            elif i==j:
                dp[i][j] = 1            # i=m인 경우는 1로 채우줌
            elif i<j:
                dp[i][j] = dp[i][j-1] + dp[i-1][j-1]
                                        # 나머지는 점화식에 의해 채워줌
    print(dp[n][m])
```
> - DP 점화식 사용
> - (n:m) -> (n:m-1) + (n-1:m-1) 로 표현 가능

## 킹
### BJ 1063
```python
king,rock,n = input().split()

# 킹,돌 위치 알파벳 아스키로 변경 후 list에 저장
k = list(map(int,[ord(king[0])-64, king[1]]))
r = list(map(int,[ord(rock[0])-64, rock[1]]))

# 8 방향 -> dictionary로 지정
move = {'R':[1,0], 'L':[-1,0], 'B':[0,-1], 'T':[0,1], 
        'RT':[1,1], 'LT':[-1,1], 'RB':[1,-1], 'LB':[-1,-1]} 

for _ in range(int(n)):
    m=input()
    k_nx = k[0] + move[m][0]
    k_ny = k[1] + move[m][1]            # 킹 이동

    if 0<k_nx<=8 and 0<k_ny<=8:         # 킹이 map 안벗어나고,
        if k_nx==r[0] and k_ny==r[1]:   # 이동 시 돌에 부딪히면
            r_nx = r[0] + move[m][0]
            r_ny = r[1] + move[m][1]    # 돌 이동
            if 0<r_nx<=8 and 0<r_ny<=8: # 돌이 map 안벗어나면
                k = [k_nx,k_ny]         # 킹 위치 저장
                r = [r_nx,r_ny]         # 돌 위치 저장
        else:
            k = [k_nx,k_ny]             # 돌 안부딪히면 킹 위치만 저장

print(f'{chr(k[0]+64)}{k[1]}')          # 아스키 다시 문자로 돌리고,
print(f'{chr(r[0]+64)}{r[1]}')          # 문자+숫자 붙여서 킹,돌 위치 출력
```
> - 킹,돌의 위치를 알파벳 따로, 숫자 따로 비교해서 2차원 리스트에서 위치를 표현하려고 함
> - 8*8 좌표를 하나씩 비교하는 방법으로는 해결하기 어렵다고 판단하여 풀이 참고
> - 아스키코드를 사용하여 위치를 숫자 형태로 표현했고, 8방향은 dictionary로 미리 설정해줌
> - 풀이 코드 자체는 어렵지 않지만 '아스키코드 변환, 방향 index화' 이 두가지 방법을 떠올리는게 어렵다고 생각됨
> - + 아스키코드 변환 코드는 익숙하지 않아서 자주 접해볼 필요가 있음

## 기타리스트
### BJ 1495
```python
n,s,m = map(int,input().split())
vol=list(map(int,input().split()))

dp = [[0]*(m+1) for _ in range(n+1)]    # dp 2차원 리스트 선언 [곡,볼륨] (1:가능/0:불가능)
dp[0][s] = 1                            # 처음 곡은 가능 체크v

for i in range(n):                      # 곡 개수 만큼
    for j in range(m+1):                # 볼륨 범위 만큼
        if dp[i][j]==1:                 # 가능 체크v 이면
            vol_up = j + vol[i]
            vol_down = j - vol[i]       # 볼륨 키우고 줄이기

            if 0<=vol_up<=m:            # 키운게 범위 안쪽이면 
                dp[i+1][vol_up] = 1     # 가능 체크v
            if 0<=vol_down<=m:          # 줄인게 범위 안쪽이면
                dp[i+1][vol_down] = 1   # 가능 체크v

ans = -1                                # 기본으로(가능 체크v 없으면) -1 출력
for k in range(m+1):
    if dp[n][k]==1:                     # 마지막 곡에서 볼륨 0부터 최대 m까지 중,
        ans = k                         # 볼륨 조절 가능한 경우 해당 dp의 m값(=볼륨) 출력
print(ans)    
```
> - 곡과 볼륨을 기준으로 2차원 리스트를 선언한 방법을 생각해내지 못함
> - 2차원 리스트의 0/1을 통해 볼륨 조절이 가능한지 안한지 여부를 체크
> - dp[][] 형태로 나머지는 문제의 조건에 따라서 작성하고 마지막에 최대값만 출력
> - 늘 그렇듯 어떻게 풀어내야 할지 생각해내는게 제일 까다롭다고 생각한다

## 리모컨
### BJ 1107
```python
n=int(input())
m=int(input())
b=list(map(int,input().split()))

ans = abs(100-n)                # +/- 로만 이동하는 경우

for num in range(1000001):
    num=str(num)
    
    for j in range(len(num)):
        if int(num[j]) in b:    # 고장난 버튼인지 확인
            break
        elif j==len(num)-1:     # 정상 버튼만으로 마지막까지 오면
            ans=min(ans, abs(int(num)-n)+len(num))  # 최소값 비교해서 갱신
print(ans)
```
> - 고장난 버튼을 체크할 때 숫자를 str형태로 바꿔서 체크
> - 정상인 버튼만으로 오면 이전까지의 값과 최소 비교해서 갱신
> - 코드 자체는 짧고 간단하지만 떠올리기 쉽지 않아보임, 디버깅도 하기 어려워서 조금 더 이해가 필요함

## 크레인 인형뽑기 기계
### PG 64061
```python
def solution(board, moves):
    answer = 0
    bucket = []

    for j in range(len(moves)):
        for i in range(len(board)):
            if board[i][moves[j]-1] != 0:
                bucket.append(board[i][moves[j]-1])
                board[i][moves[j]-1] = 0

                if len(bucket) > 1:
                    if bucket[-1] == bucket [-2]:
                        bucket.pop(-1)
                        bucket.pop(-1)
                        answer += 2
                break
    return answer
```
> - 크레인이 이동하는 경우(moves)와 인형의 위치(board)를 통해 돌며 bucket list에 인형들을 채움
> - bucket list에서 같은 인형이 연속되는 경우 pop하고 answer++
> - 풀이법과 코드 둘 다 어렵지 않았던 문제
