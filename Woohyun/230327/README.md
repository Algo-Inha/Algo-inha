# Solving

## 가장 큰 증가하는 부분 수열
https://www.acmicpc.net/problem/11055
### 문제풀이
```python
import sys
input = sys.stdin.readline

n = int(input())
A = list(map(int, input().split()))


dp = [0] * n 


dp[0] = A[0]
print(dp)
# DP
for i in range(1, n):
    for j in range(i):
        if A[j] < A[i] and dp[j] > dp[i]:
            dp[i] = dp[j] 
    dp[i] += A[i]


print(max(dp)) 
```
그나마 단순한 dp 문제였다.
### 의견
처음에 DP문제인 것을 눈치못채고 수학적으로 풀려다가 시간이 좀 걸렸다. 아래 알고리즘 분류를 확인하고 DP문제인 것을 알고난 후 좀 수월했다. 요즘 문제 많이 안풀어본 티가 너무 났다. 분발하자

## 신입사원
https://www.acmicpc.net/problem/1946
### 문제풀이
```python
import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())  # 지원자 수
    applicants = []  # 지원자 정보를 담을 리스트

    # 지원자 정보 입력 받기
    for i in range(N):
        document, interview = map(int, input().split())
        applicants.append([document, interview])

    # document 기준으로 오름차순 정렬
    applicants.sort(key=lambda x: x[0])

    # interview 순위가 현재까지의 최고 순위보다 높은 지원자들만 선발
    cnt = 1  # 첫 번째 지원자는 무조건 선발
    highest_interview = applicants[0][1]  # 현재까지의 최고 순위
    for i in range(1, N):
        if applicants[i][1] < highest_interview:  # 면접시험 순위가 높은 지원자만 선발
            highest_interview = applicants[i][1]  # 현재까지의 최고 순위 갱신
            cnt += 1

    print(cnt)  # 선발 가능한 신입사원 수 출력
```
단순한 greedy 문제
### 의견
어려운 문제는 아니었다. 서류나 면접 순위중 아무거나로 정렬해놓고 비교하는 문제였다. 처음에 문제 읽고 뭔소린지 이해 잘 못하다가 예제로 맞춰보니 이해가 됐다. 책좀 읽자. 


