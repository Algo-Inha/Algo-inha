# 220712

## 잃어버린 괄호
### BJ 1541
```python
# 연산 결과가 최소가 되기 위해서는 (-)를 기준으로 괄호를 치면 됨
math=input().split('-')

num=[]
for i in math:          # (-)를 기준으로 split해서 입력 받은 string을 기준으로,
    sum=0
    m = i.split('+')    # (+)를 기준으로 다시 split해서 int형으로 더해줌
    for j in m:
        sum += int(j)    
    num.append(sum)     # 더한 값들을 num list에 넣어줌

ans=num[0]              # 맨 처음의 값은 기본적으로 추가하고,
for k in range(1,len(num)):
    ans -= num[k]       # 이후의 값들은 전부 빼주고 출력하면 연산 결과 최소.

print(ans)
```
> - 연산 결과가 최소가 되기 위해서는 (-)를 기준으로 괄호를 치면 됨
> - (-)를 기준으로 split해서 입력 받은 string을 기준으로, (+)가 있으면 int형으로 더해줌
> - 더한 값들을 num list에 넣어줌
> - 맨 처음의 값은 기본적으로 추가하고, 이후의 값들은 전부 빼주고 출력하면 연산 결과 최소.

## 좌표 압축
### BJ 18870
```python
import sys
input = sys.stdin.readline

n=int(input())
lst=list(map(int,input().split()))
lst2=sorted(set(lst))       # 중복 제거한 lst를 정렬해서 lst2에 저장

# 'lst2:index' 형태의 dictionary 사용해서 시간 초과 해결
ans = {lst2[i] : i for i in range(len(lst2))}

for i in lst:
    print(ans[i], end=' ')
```
> - 최초 시도 시 성공, but 시간 초과
> - 풀이 참고해서 dictionary 사용해서 O(N) -> O(1)로 줄이는 방법 알게됨

## 가장 긴 증가하는 부분 수열
### BJ 11053
```python
import sys
input = sys.stdin.readline

n=int(input())
lst=list(map(int,input().split()))

dp=[0] * n
for i in range(n):
    for j in range(i):
        if lst[i] > lst[j] and dp[i] < dp[j]:
            dp[i] = dp[j]   
    dp[i] += 1
    # print(dp)

print(max(dp))
```
> - 처음에 부분 수열 구하는 걸 모르고 그냥 전체에서 증가하기만 하면 count를 해줘서 오답
> - dp로 증가하는 부분 수열의 길이를 구하는 풀이 참고
> - dp는 조금 더 익숙해질 필요 있음


## 랜선 자르기
### BJ 1654
```python
import sys
input=sys.stdin.readline

k,n = map(int,input().split())
lan = [int(input()) for _ in range(k)]
start=1; end=max(lan)       # 이분 탐색 처음,끝 설정

while start <= end:
    mid = (start+end)//2    # 이분 탐색 중간 설정
    cnt=0
    for i in lan:
        cnt += i//mid       # 나눠진 랜선의 수

    if cnt >= n:
        start = mid+1
    else:
        end = mid-1

print(end)
```
> - 지난주 나무 자르기와 마찬가지로 이분 탐색 활용

## 124 나라의 숫자
### PG 12899
```python
# 풀이(1)
def solution(n):
    arr=['1','2','4']
    answer=''

    while n > 0:
        n -= 1
        answer = arr[n%3] + answer
        n //= 3

    return answer
```
> - 1,2,4 list 선언, 3진법 형태로 arr list에서 1,2,4를 돌아가며 값 부여
> - n//3 -> 예를들어 n=3인 경우 3//3에서 n=1이 되고, 다시 n-=1으로 n=0이므로 1이 됨
	이때, 이전의 1이 뒤로, 이번 1이 앞으로 오게 string 형태로 설정해서 4-> 11 변환
> - 코드는 간단하지만 방법을 생각해내는게 매우 어려움

```python
# 풀이(2)
def solution(n):
    if n<=3:
        return '124'[n-1]
    else:        
        q,r = (n-1)//3, (n-1)%3         # q,r = divmod(n-1, 3) 동일!
        return solution(q) + '124'[r]
```
> - 몫과 나머지를 따로 구해서 재귀를 사용하여 해결한 방법
> - 이 또한 재귀로 몫 부분만 한번 더 돌리는걸 어떻게 생각해낸건지 신기할 따름
> 
