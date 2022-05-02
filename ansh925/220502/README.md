## 최대공약수
### BJ 2824

```python
import sys
input = sys.stdin.readline

N = int(input())
N_lst = list(map(int,input().split()))
M = int(input())
M_lst = list(map(int,input().split()))

def gcd(a,b) :
    while b > 0 :
        tmp = a%b
        a = b
        b = tmp
    return a

A = 1; B = 1
for i in N_lst:  
    A *= i  
for j in M_lst:  
    B *= j  

ans = '%s'%str(gcd(A,B))[-9:]
print(ans)
```
> - 유클리드 호제법을 사용한 최대공약수 구하는 gcd함수
> - N,M list를 전부 곱한 값에 대하여 gcd함수에 적용한 것을 str형태로 변형한 뒤, 9자리로 끊어서 출력

## 배열돌리기1
### BJ 16926
```python
import sys
input = sys.stdin.readline

n,m,r = map(int,input().split())
graph = [list(map(int,input().split())) for _ in range(n)]

for _ in range(r):
    for i in range(min(n, m) // 2):
        x, y = i, i
        tmp = graph[x][y]

        for j in range(i + 1, n - i):  # 아래 방향 이동
            x = j
            prev_value = graph[x][y]
            graph[x][y] = tmp
            tmp = prev_value
        for j in range(i + 1, m - i):  # 오른쪽 방향 이동
            y = j
            prev_value = graph[x][y]
            graph[x][y] = tmp
            tmp = prev_value
        for j in range(i + 1, n - i):  # 위 방향 이동
            x = n - j - 1
            prev_value = graph[x][y]
            graph[x][y] = tmp
            tmp = prev_value
        for j in range(i + 1, m - i):  # 왼쪽 방향 이동
            y = m - j -1
            prev_value = graph[x][y]
            graph[x][y] = tmp
            tmp = prev_value
    # 바깥 사각형 다 돌린 후, 안쪽 사각형에서 반복 수행

for i in range(n):
    for j in range(m):
        print(graph[i][j], end=' ')
    print()
```

> - 문제에서 주어진 대로 바깥 사각형부터 각 방향에 따라 배열을 돌려주고, 안쪽 사각형으로 들어가며 반복적으로 돌리기를 수행
> - pypy3로 실행해야 시간 초과 발생 안함

   
## 주차 요금 계산
### PG 92341

```python
import math

def dateToMinutes(date):                # hh:mm 형태의 시간을 분 단위로 변경하는 함수
    h, m = map(int, date.split(':'))
    return h*60 + m
    
def solution(fees, records):
    answer = []
    dt, df, ut, uf = fees   # 기본시간, 기본요금, 단위시간, 단위요금    
    dic = dict()

    for r in records:
        time, number, history = r.split()
        number = int(number)
        
        if number in dic:
            dic[number].append([dateToMinutes(time), history])
        else:
            dic[number] = [[dateToMinutes(time), history]]
        # dictionary 자료형은 sort()를 쓰지 못하기 때문에 (key,value) 꼴 list로 변환 

    rList = list(dic.items())
    rList.sort(key=lambda x : x[0])
    
    for r in rList:
        t = 0
        for rr in r[1]:
            if rr[1] == "IN":
                t -= rr[0]
            else:
                t += rr[0]

        if r[1][-1][1] == "IN":
            t += dateToMinutes('23:59')
        # 예외 처리

        if t <= dt:
            answer.append(df)
        else:
            answer.append(df + math.ceil((t-dt) / ut) * uf)        

    return answer
```
> - 인터넷의 풀이 참고. 코드를 읽고 어떤식으로 해결했는지 이해는 할수있지만 시간을 분으로 바꾸는것부터 distionary와 list를 변환해가며 쓰는것 등 혼자서는 풀이 생각해내지 못함.

