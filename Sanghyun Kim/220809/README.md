# Solving

## 양궁대회- PG_92342
https://school.programmers.co.kr/learn/courses/30/lessons/92342
### 문제풀이
```python
from itertools import combinations_with_replacement

def solution(n, info):
    answer = [-1]
    # x: 어피치, y: 라이언

    y_shoot = list(combinations_with_replacement(range(0, 11), n))
    max_score = 0

    for y in y_shoot:
        y_info = [0 for _ in range(11)]
        x_score = 0
        y_score = 0
        for i in y:
            y_info[10 - i] += 1
        for i in range(len(info)):
            if info[i] == y_info[i] == 0:
                continue
            elif info[i] >= y_info[i]:
                x_score += (10 - i)
            elif info[i] < y_info[i]:
                y_score += (10 - i)
        total_score = y_score - x_score
        if max_score < total_score:
            max_score = total_score
            answer = y_info
        elif max_score > 0 and max_score == total_score:
            for i in reversed(range(11)):
                if answer[i] > y_info[i]:
                    break
                elif answer[i] < y_info[i]:
                    answer = y_info
                    break
    return answer

info = [1,0,0,0,0,0,0,0,0,0,0]
n = sum(info)
print(solution(n, info))
```
11개의 점수 중 5개를 고르는 가능한 모든 경우의 수를 콤비네이션 연산을 통해 구해 y_info 리스트에 넣어 info 리스트와 비교하며 어피치, 라이언의 점수를 구하고, 점수가 커질 때마다 max_score 값, answer 리스트를 초기화한다. 이때 max_score 값과 라이언, 어피치 점수 차이가 같을 경우 answer, y_info 리스트를 뒤에서부터 비교하며 작은 점수의 수가 큰 경우를 answer 리스트로 택한다.
### 의견
브루트 포스 알고리즘으로 완전 탐색을 하는 문제라는 것은 파악하고 있었다. 하지만 어피치와 라이언의 info 리스트로 비교를 하려다 보니 오랜 삽질 끝에 해결하지 못하였고, 결국 어떤 방식으로 접근하는지에 대한 알고리즘을 봤다. 역시 카카오.. 문제를 정말 잘 만드는 것 같다. 활을 쏘는 경우의 수를 모두 구해 그에 맞는 라이언의 info 리스트를 만들어 비교하는 방법으로 해결할 수 있었다. 
여기에 더해 파이썬의 itertools 라이브러리를 알게 되었는데, 이는 조합과 순열을 푸는데 있어 모든 경우의 수를 알려주는 정말 유용한 라이브러리인 것 같다.


## 2개 이하로 다른 비트
https://school.programmers.co.kr/learn/courses/30/lessons/77885
### 문제풀이
```python
def solution(numbers):
    answer = []
    for i in numbers:
        if i % 2 == 0:
            answer.append(i + 1)
            continue
        
        # 10진수 2진수로 변환하여 list에 1개씩 입력
        temp = list('0' + bin(i)[2:])
        # 오른쪽부터 '0' 찾기
        idx = ''.join(temp).rfind('0')
        # 찾은 '0'의 값을 '1'로 바꿈
        temp[idx] = '1'
        # 다음 index의 값을 '0'으로 바꿈
        temp[idx + 1] = '0'
        # 2진수를 10진수로 변경
        answer.append(int(''.join(temp), 2))

    return answer
```
짝수인 경우 1 더하여 answer list에 입력한다.
홀수인 경우 10진수를 2진수로 변경하고, 자릿수가 바뀔 것을 고려하여 맨 앞에 '0'을 추가한다. 이후 오른쪽에서부터 가장 가까운 '0'을 찾아 '1'로 바꾸고, 다음 index 값을 '0'으로 바꾼다. 다시 10진수로 바꾸고 answer list에 입력한다.
### 의견
문제의 제한 사항에 numbers의 모든 수의 값이 10^15까지인 것을 봤을 때 시간 초과가 나는 문제인 것은 알고 있었지만.. 결국 혼자 시간 초과의 문제를 해결할 수는 없었다. 찾아보니 홀수의 경우 규칙이 있는 것을 알았고, 알고난 후 어렵지 않게 해결할 수 있었다.


## 게리맨더링 2
https://www.acmicpc.net/problem/17779
### 문제풀이
```python

```

### 의견
해결하지 못했습니다. 다시 해봐야할 것 같습니다.


## 최댓값과 최솟값
https://school.programmers.co.kr/learn/courses/30/lessons/12939
### 문제풀이
```python
def solution(s):
    answer = ''
    num_list = list(map(int, s.split(' ')))
    min_num = min(num_list)
    max_num = max(num_list)
    answer = str(min_num) + " " + str(max_num)
    return answer

s = input()
print(solution(s))
```
min, max 함수 사용, 출력할 때 str() 사용해 문자열로 바꾸고 ' ' 추가하여 출력한다.
### 의견
파이썬에서 정말 쉬운 문자열 문제


## 오큰수
https://www.acmicpc.net/problem/17298
### 문제풀이
```python
from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
A = list(map(int, input().split()))

big = [-1 for _ in range(n)]
stack = deque()

for i in range(n):
    while stack and (stack[-1][0] < A[i]):
        temp, temp_idx = stack.pop()
        big[temp_idx] = A[i]
    stack.append([A[i], i])

print(*big)
```
A 배열의 순서대로 넣는데, 넣는 수가 이미 들어있는 스택 값보다 클 경우 스택이 빌 때까지 pop하며 오큰수를 큰 값으로 바꾼다. pop할 때 pop 하는 값들의 오큰수는 앞의 큰 값이다.
### 의견
O(n^2) 의 문제를 O(n)에 가깝게 만드는 시간 복잡도를 해결하는데 있어서 까다로웠던 문제였다.