## 절대값 힙
### BJ 11286
```python
import sys
import heapq
input=sys.stdin.readline

lst=[]
n=int(input())
for _ in range(n):
    x=int(input())
    if x==0:
        if lst:
            print(heapq.heappop(lst)[1])
        else:
            print(0)
    else:
        heapq.heappush(lst,(abs(x),x))
```
> - heap을 사용해서 입력값이 0일때 pop, 아닐때는 lst에서 x의 절대값을 push
> - push 할 때, 절대값이 가장 작은 것이 우선되도록 튜플 형식으로 heap에 추가
> - 시간 초과 발생 -> pypy3 사용


## 튜플
### PG 64065
```python
def solution(s):
    answer = []
    lst = [s.split(',') for s in s[2:-2].split('},{')]
    lst = sorted(lst,key=len)
    
    for l in lst:
        for s in l:
            if int(s) not in answer:
                answer.append(int(s))
                break
    return answer
```
> - 맨앞, 맨뒤 중괄호를 제거한 다음, '},{'을 기준으로 split
> - split한 각 list에서 ',' 기준으로 다시 split
> - list 정렬 후 하나씩 확인해가며 answer list에 없는 경우에만 append


## 입국심사
### PG 43238
```python
def solution(n, times):
    answer = 0
    left = 1
    right = max(times)*n

    while left <= right:
        mid = (left+right)//2
        total=0
        for t in times:
            total += mid//t        
        if total >= n:            
            right = mid-1
            answer = mid
        else:
            left = mid+1
    return answer
```
> - 입국심사 시간이 적게 걸리는 심사대에서 최대한 많은 심사를 해야함
> - 중간값과 현재값을 비교하는 이진 탐색 방법
> - 풀이 참고, 좀 더 이해 필요


## 줄서는 방법
### PG 12936
```python
def solution(n, k):
    answer = []
    lst = [i for i in range(1, n+1)]
    while (n != 0):
        tmp = math.factorial(n) // n
        index = k // tmp
        k = k % tmp
        if k == 0:
            answer.append(lst.pop(index-1))
        else :
             answer.append(lst.pop(index))
        n -= 1    
    return answer
```
> - 줄 설 수 있는 방법의 수 : math의 factorial 함수 사용
> - lst: 한 사람이 앞에 줄을 섰을 때의 경우의 수
> - index: k번째를 구하기 위해 한 사람이 앞에 줄을 섰을때의 경우의 수를 지나간 수
> - 풀이 참고, 아직 이해x


