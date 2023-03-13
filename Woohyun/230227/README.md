# Solving

## 틱택토
https://www.acmicpc.net/problem/7682
### 문제풀이
```python
import sys
input = sys.stdin.readline

graph = []

while(1):
    board = input().rstrip()
    graph.append(board)
    if graph[-1] == "end":
        graph.pop()
        break


for i in graph:
    if ((i.count("X") == 5 and i.count("O") == 4)
        and not
        (i[:3] == "OOO" or i[3:6] == "OOO" or i[6:] == "OOO" 
        or (i[0] == "O" and i[4] == "O" and i[8] == "O") 
        or (i[2] == "O" and i[4] == "O" and i[6] == "O")
        or (i[0] == "O" and i[3] == "O" and i[6] == "O")
        or (i[1] == "O" and i[4] == "O" and i[7] == "O")
        or (i[2] == "O" and i[5] == "O" and i[8] == "O"))):
        print("valid")
    elif i.count("X") == i.count("O"):
        if ((i[:3] == "OOO" or i[3:6] == "OOO" or i[6:] == "OOO" 
            or (i[0] == "O" and i[4] == "O" and i[8] == "O") 
            or (i[2] == "O" and i[4] == "O" and i[6] == "O")
            or (i[0] == "O" and i[3] == "O" and i[6] == "O")
            or (i[1] == "O" and i[4] == "O" and i[7] == "O")
            or (i[2] == "O" and i[5] == "O" and i[8] == "O"))
            and not 
            (i[:3] == "XXX" or i[3:6] == "XXX" or i[6:] == "XXX" 
            or (i[0] == "X" and i[4] == "X" and i[8] == "X") 
            or (i[2] == "X" and i[4] == "X" and i[6] == "X")
            or (i[0] == "X" and i[3] == "X" and i[6] == "X")
            or (i[1] == "X" and i[4] == "X" and i[7] == "X")
            or (i[2] == "X" and i[5] == "X" and i[8] == "X"))):
            print("valid")
        else:
            print("invalid")
    elif (i.count("X") == (i.count("O") + 1)):
        if ((i[:3] == "XXX" or i[3:6] == "XXX" or i[6:] == "XXX" 
            or (i[0] == "X" and i[4] == "X" and i[8] == "X") 
            or (i[2] == "X" and i[4] == "X" and i[6] == "X")
            or (i[0] == "X" and i[3] == "X" and i[6] == "X")
            or (i[1] == "X" and i[4] == "X" and i[7] == "X")
            or (i[2] == "X" and i[5] == "X" and i[8] == "X"))
            and not
            (i[:3] == "OOO" or i[3:6] == "OOO" or i[6:] == "OOO" 
            or (i[0] == "O" and i[4] == "O" and i[8] == "O") 
            or (i[2] == "O" and i[4] == "O" and i[6] == "O")
            or (i[0] == "O" and i[3] == "O" and i[6] == "O")
            or (i[1] == "O" and i[4] == "O" and i[7] == "O")
            or (i[2] == "O" and i[5] == "O" and i[8] == "O"))):
            print("valid")
        else:
            print("invalid")

    else:
        print("invalid")


```
조건을 잘 생각해서 구현하는 문제였다. 말판이 9칸 밖에 없기 때문에 모든 조건을 직접 입력해서 분류하면 된다.
### 의견
조건을 고려하는 과정에서 생각치도 못한 조건이 많기 때문에 세세하게 조건을 확인해야 풀 수 있다.

## 용액
https://www.acmicpc.net/problem/2467
### 문제풀이
```python
import sys
input = sys.stdin.readline

n = int(input())

li = list(map(int,input().split()))

li.sort()

min_left, min_right = 0, n-1
left = 0
right = n - 1
min = abs(li[0] + li[-1])

if li[0] > 0:
    print(li[0],li[1],end=" ")

elif li[-1] < 0:
    print(li[-2], li[-1],end=" ")

else:
    while(left<right):
        temp = li[left] + li[right]



        if abs(temp) < min:
            min_left = left
            min_right = right
            min = abs(temp)

        if temp == 0:
            break


        if temp < 0:
            left += 1
        else:
            right -= 1

print(li[min_left], li[min_right], end=" ")
            
```

### 의견


## 수 묶기
https://www.acmicpc.net/problem/1744
### 문제풀이
```python
import sys
input = sys.stdin.readline


n = int(input())

li = []
minus_li = []
zero_li = []
one_li = []
plus_li = []

answer = 0

for i in range(n):
    li.append(int(input()))



for i in li:
    if i < 0:
        minus_li.append(i)
    elif i == 0:
        zero_li.append(i)
    elif i == 1:
        one_li.append(i)
    else:
        plus_li.append(i)

li.sort()
minus_li.sort()
plus_li.sort()

if plus_li:
    if len(plus_li)%2 == 0:
        for i in range(len(plus_li)):
            if i%2 == 0:
                temp = plus_li[i]
            else:
                answer += temp*plus_li[i]
    else:
        if len(plus_li) == 1:
            answer += plus_li[0]
        else:
            answer += plus_li[0]
            for i in range(1,len(plus_li)):
                if i%2 == 1:
                    temp = plus_li[i]
                else:
                    answer += temp*plus_li[i]

if minus_li:
    if len(minus_li)%2 == 0:
        for i in range(len(minus_li)):
            if i%2 == 0:
                temp = minus_li[i]
            else:
                answer += temp*minus_li[i]
    else:
        if len(minus_li) == 1:
            if not zero_li:
                answer += minus_li[0]
        else:
            if zero_li:
                for i in range(len(minus_li) - 1):
                    if i%2 == 0:
                        temp = minus_li[i]
                    else:
                        answer += temp*minus_li[i]
            else:
                answer += minus_li[-1]
                for i in range(len(minus_li) - 1):
                    if i%2 == 0:
                        temp = minus_li[i]
                    else:
                        answer += temp*minus_li[i]

if one_li:
    for i in one_li:
        answer += i



print(answer)
```
조건을 잘생각해 줘야하는 문제였다. 우선 음수,0,1,양수를 각각 리스트만다 분류해서 풀었다.
1. 0은 양수랑 곱하지 않는다.
2. 음수 되도록 음수끼리 두개씩 곱하고, 안되면 0이 있을 경우는 곱하고 없을 경우는 그냥 더한다.
3. 양수는 큰수끼리 곱한다.
4. 1은 그냥 더한다.
### 의견
조건대로 일단 구현만 시키면 된다는 생각으로 코드를 작성했더니 코드가 좀 지저분하긴 하였다. 답은 맞았지만 좀 더 간단히 구현할 수 있을 것 같다.

## 상어 초등학교
https://www.acmicpc.net/problem/21608
### 문제풀이
```python
#중복조합 사용
import sys
input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


n = int(input())

graph = [[0]*n for _ in range(n)]

students = []

for _ in range(n**2):
    students.append(list(map(int,input().split())))


# 학생 수 만큼 for문을 돌며 자리에 앉혀 줌.
for order in range(n**2):
    student = students[order]
    # 여기다가 가능한 자리를 다 담아서 정렬 후 앉힘
    tmp = []
    for i in range(n):
        for j in range(n):
            if graph[i][j] == 0:
                like = 0
                blank = 0
                for k in range(4):
                    nx, ny = i + dx[k], j + dy[k]
                    if 0 <= nx < n and 0 <= ny < n:
                        if graph[nx][ny] in student[1:]:
                            like += 1
                        if graph[nx][ny] == 0:
                            blank += 1
                tmp.append([like, blank, i, j])
    # like, blank는 내림차순 행과 열 번호는 오름차순 정렬
    tmp.sort(key= lambda x:(-x[0], -x[1], x[2], x[3]))
    # 정렬 후 젤 앞에 있는 리스트의 행과 열의 번호에 학생 앉히기 
    graph[tmp[0][2]][tmp[0][3]] = student[0]

result = 0
# 점수를 매길 때는 학생 순서대로 점수 주기 위해 정렬
students.sort()

for i in range(n):
    for j in range(n):
        ans = 0
        for k in range(4):
            nx, ny = i + dx[k], j + dy[k]
            if 0 <= nx < n and 0 <= ny < n:
                if graph[nx][ny] in students[graph[i][j]-1]:
                    ans += 1
        if ans != 0:
            result += 10 ** (ans-1)
print(result)
```
빡구현 문제였다. 학생이 앉을 때마다 dx,dy 리스트를 이용해 bfs풀듯이 조건을 확인하며 풀어야 했다.
### 의견
상어 문제여서 시작부터 좀 어렵다고 생각했다. 막막해서 구글링을 좀 하였다. 다름 사람 코드를 보면서 풀어보니 좀 어렵긴 했지만, 상어 문제치고는 풀만하다고 생각되는 문제였다.

