# Solving

## 숫자의 표현
https://school.programmers.co.kr/learn/courses/30/lessons/12924
### 문제풀이
```python
def solution(n):
    count = 1
    x = 2   # 2부터
    if n > 3:
        while x < n//2:
            if x % 2 == 1:              # 홀수로 나눌 때
                if n == n//x * x:       # 나눠지면
                    if n//x - x//2 > 0:
                        count += 1
            else:                       # 짝수로 나눌 때
                if n/x - 0.5 == n//x: # 조건 만족하면
                    if x//2 < n/2 and n/x - x/2 > 0:
                        count += 1
            x += 1    
    elif n==3:
        count = 2
    return count
```
조건에 맞게 구현한다.
### 의견
문제 조건에 맞게끔 조건을 구현했다. 야매로 푼 문제, 깔끔하진 않다.


## 올림픽
https://www.acmicpc.net/problem/8979
### 문제풀이
```python
n, k = map(int, input().split())
country = [[] for _ in range(n)]

for i in range(n):
    c, gold, silver, bronze = map(int, input().split())
    country[c - 1] = [gold, silver, bronze, c]

# 금메달이 많은 순으로 정렬을 하고
# 금메달이 같다면 은메달,
# 은메달이 같다면 동메달이 많은 순으로 정렬
country.sort(key=lambda x: (-x[0], -x[1], -x[2]))

count = [1]

for i in range(n):
    if i > 0:
        if country[i][0]==country[i-1][0] and country[i][1]==country[i-1][1] and country[i][2]==country[i-1][2]:
            count.append(count[-1])
        else:
            count.append(i+1)
    if country[i][3] == k:
        print(count[i])
        break
```
country 리스트에 금메달 수, 은메달 수, 동메달 수, 국가를 나타내는 수를 차례로 넣는다. 금메달이 많은 순으로 정렬, 금메달이 같다면 은메달, 은메달이 같다면 동메달이 많은 순으로 정렬하여 국가를 나타내는 수가 k인 국가가 몇번째 있는지 구한다.
### 의견
lambda와 친해질 필요성을 절실히 느낀 문제였다.