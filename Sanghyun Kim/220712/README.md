# Solving

## 가장 긴 증가하는 부분수열
https://www.acmicpc.net/problem/11053
### 문제풀이
```python
n = int(input())
num = list(map(int, input().split()))
count = [1 for _ in range(len(num))]

for i in range(len(num)):
    for j in range(i):
        if num[j] < num[i]:
            count[i] = max(count[i], count[j] + 1)
print(max(count))
```
전체 수열에 대해 돌면서 자신(i)보다 앞의 수들에 대해 자신(i)을 포함해 만들 수 있는 부분 수열의 크기를 저장한다. 이때 앞의 수들에 대해서 또한 부분 수열에 자신(j)를 포함한 증가하는 부분수열과 길이를 비교하여 더 큰 값을 선택하는 DP 알고리즘을 사용한다.

### 의견
전체 수열에 대해 돌면서 자신(i)보다 앞의 수들에 대해 자신(i)을 포함해 만들 수 있는 부분 수열의 크기를 저장해 나가며 DP 알고리즘을 사용하는 것 까지는 생각했지만, 뒤에 가장 중요한 자신의 앞 수들에 대한 부분수열과 비교하여 더 큰 값을 선택하는 부분까지는 생각하지 못했다. 생각할 수 있는 모든 경우의 수를 코드로 모두 구현하려다 보니 놓치는 부분이 계속 나와 결국 구글링을 진행하여 문제 해결했다. 찾아본 결과 LIS(Longest Increasing Subsequence) 라는 유명한 DP 알고리즘 문제라고 했는데, 비슷한 유형의 문제들을 접해봐야 할 것 같다.


## 랜선 자르기
https://www.acmicpc.net/problem/1654
### 문제풀이
```python
k, n = map(int, input().split())
k_len = list()
rest = list()

for _ in range(k):
    k_len.append(int(input()))

x_min = 1
x_max = max(k_len)

while x_min <= x_max:
    count = 0
    x_mid = (x_min + x_max) // 2

    for i in range(k):
        count += k_len[i] // x_mid

    if count < n:
        x_max = x_mid - 1
    elif count >= n:
        x_min = x_mid + 1

print(x_max)
```
1을 처음 최솟값으로 두고, 랜선 list의 최댓값을 최댓값으로 두어 이분탐색 알고리즘을 진행하여 최대 랜선 길이로 자른 랜선 개수를 출력한다. 

### 의견
이분 탐색 문제인 것은 알았지만, 문제 조건으로 N개보다 많이 만드는 것도 N개를 만드는 것에 포함된다는 말에 문제를 접근하는데 어려움이 있었다.


## 124 나라의 숫자
https://school.programmers.co.kr/learn/courses/30/lessons/12899
### 문제풀이
```python
def solution(n):
    answer = ''
    n_arr = ['1', '2', '4']

    while n > 0:
        n -= 1
        answer += n_arr[n % 3]
        n //= 3
    answer = answer[::-1]
    return answer
```
3진법에서 0 : 1, 1 : 2, 2 : 4로 생각하여 문제를 해결한다. 0부터 시작하기 위해 1을 빼는데, 4일 경우 11이 나와야 하므로 나머지 0이 나오기 위해 1을 빼고, 자리수가 늘어날 수록 1씩 빼며 answer list에 넣어 마지막에 뒤집어 출력한다.

### 의견
1, 2, 4가 아닌 0, 2, 4 혹은 0이 포함된 나라의 숫자였다면 1을 지속해서 빼지 않아도 올바른 수가 나왔을 것을 생각하여 문제 풀이를 진행하는데 있어서 많은 고민을 필요로 했다. 결국 1을 빼며 연산하는 방법을 생각하지 못해 구글링을 하여 문제를 해결할 수 있었다.


## 좌표 압축
https://www.acmicpc.net/problem/18870
### 문제풀이
```python
# import sys
# input = sys.stdin.readline

# n = int(input())
# x = list(map(int, input().split()))
# x_ = [0 for _ in range(n)]

# # min, max 정해
# min, max = min(x), max(x)
# # min이 0보다 작을 경우 max - min 크기의 list를 만들어
# # (-) index로 접근 가능하도록
# if min < 0:
#   coordinate = [0 for _ in range(max - min + 1)]
# else:
#   coordinate = [0 for _ in range(max + 1)]

# # 존재하는 원소 위치 ++
# for i in range(n):
#   coordinate[x[i]] += 1

# # 하나씩 비교하며 min부터 max 까지
# # 존재할 경우 count 1씩 증가시키며 좌표 압축
# count = 0 
# for i in range(min, max + 1):
#   if coordinate[i] != 0:
#     for j in range(n):
#       if x[j] == i:
#         x_[j] = count
#     count += 1

# print(*x_)
# # 메모리 초과 뜸...

import sys
input = sys.stdin.readline

n = int(input())
x = list(map(int, input().split()))

# set : 중복 제거
# sorted : 오름차순
x_ = sorted(list(set(x)))

# dictionary 사용 {원소, 원소 index}
dic_x = {x_[i] : i for i in range(len(x_))}
# list x의 원소에 대해
for i in x:
  # key i에 대한 value 값 출력 후 띄어쓰기
  print(dic_x[i], end = ' ')
```
파이썬의 set 함수를 이용해 중복 제거를 하고, 오름차순이든 내림차순이든 정렬한 후 dictionary를 사용해 key, value 값을 각각 원소, 원소에 해당하는 index로 지정해 기존 순서대로 원소에 해당하는 index를 출력한다.

### 의견
파이썬의 set 함수 존재를 몰라 기존에 다른 방법을 사용해 진행했다. (-) index로 접근 가능한 list를 만들어 전체를 비교해가며 count를 증가시키는 방법으로 코딩했는데, 메모리 초과로 인해 해결할 수 없었다. 
set, dictionary를 활용하여 중복 제거를 하고, key, value 값을 저장해 쉽게 접근하여 해결할 수 있었다.


## 잃어버린 괄호
https://www.acmicpc.net/problem/1541
### 문제풀이
```python
# (-) 만나면, 다음 (-) 만날 때까지 괄호
# (-) 기준으로 나누기
arr = input().split('-')
total = 0

# 맨 처음 문자는 숫자이므로
for i in arr[0].split('+'):
  total += int(i)

# 모두 더해서 빼기
for i in arr[1:]:
  for j in i.split('+'):
    total -= int(j)
print(total)
```
(-) 기호 기준으로 나누어 다음 (-) 기호를 만날 때까지 더하여 빼는 방식으로 진행한다. 이 때, 첫 문자는 숫자로 시작하므로 가장 처음 숫자는 더하고 시작한다.

### 의견
식의 값을 최소로 만들기 위해 (-) 기호 이후에 다음 (-) 기호 전까지 있는 모든 기호, 숫자를 괄호로 묶어 빼면 최솟값을 구할 수 있을 것이라 생각했다. 하지만 가장 처음 기호는 숫자인 조건과 (-) 기준으로 나누었으므로 첫 (-) 전까지의 숫자를 모두 더하여 진행했다.