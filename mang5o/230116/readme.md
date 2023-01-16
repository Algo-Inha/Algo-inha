
# Solving﻿  

## 게임
https://www.acmicpc.net/problem/1072
### 문제풀이  
```python  
import sys, math  
X, Y = map(int, sys.stdin.readline().rstrip().split())  
if Y*100 >= 99*X:  
    print(-1)  
else:  
    now_ratio = math.floor(round(100*Y/X, 10))/100  
  # (Y+n)/(X+n) 이 now_ratio+0.01보다 크거나 같다  
  # (Y+n)/(X+n) = now_ratio+0.01  
 # (Y+n) = (now_ratio+0.01)*X + (now_ratio+0.01)*n # Y - (now_ratio+0.01)*X = (now_ratio+0.01 - 1) * n  n = (Y - (now_ratio+0.01)*X) / (now_ratio - 0.99)  
    n = round(n, 3)  
    print(math.ceil(n))
```
수학적으로 N의 값을 풀어서 정리한 뒤 계산하였다.

### 의견
정확한 수치가 필요한 코딩테스트에 확률 등의 float 값이 들어가는 문제는 깔끔한 문제가 아니라고 생각한다. 이 문제도 float의 정확성때문에 `round` 등을 사용해서 강제적으로 계산의 정확성을 높였는데, 이 또한 합리적인 추론에 의한 오류 수정보다는 정답이 아니라고 출력됐으니 이곳 저곳을 들쑤시며 정확도를 높였다는 느낌이 든다.
참신했지만 아쉬웠던 문제이다.


## 정사각형
https://www.acmicpc.net/problem/1485
### 문제풀이  
```python  
import sys  
T = int(sys.stdin.readline().rstrip())  
all_query = []  
for i in range(T):  
    tmp_query = []  
    for j in range(4):  
        tmp_query.append(list(map(int, sys.stdin.readline().rstrip().split())))  
    tmp_query.sort(key=lambda x:(x[0], x[1]))  
    all_query.append(tmp_query)  
  
for query in all_query:  
    all_length = []  
    for i in range(4):  
        for j in range(i+1, 4):  
            all_length.append(  
                (query[i][0] - query[j][0])*(query[i][0] - query[j][0])  
                + (query[i][1] - query[j][1])*(query[i][1] - query[j][1])  
            )  
    all_length.sort()  
    if all_length[0] == all_length[1] == all_length[2] == all_length[3] \  
            and all_length[0]*2 == all_length[4] == all_length[5]:  
        print(1)  
    else:  
        print(0)
```
각 점과 점 사이의 거리를 구한다. 총 6개의 선이 출력되며, 각 크기순으로 정렬했을 때에 `같은 길이의 짧은 4개의 선`과 `같은 길이의 긴 2개의 선`이 나와야 한다. 또한 피타고라스의 정리도 만족해야한다.


## N과 M
https://www.acmicpc.net/problem/15649
### 문제풀이  
```python  
import sys, itertools  
N, M = map(int, sys.stdin.readline().rstrip().split())  
perm = itertools.permutations([x+1 for x in range(N)], M)  
for i in perm:  
    print(str(i).replace("(","").replace(")","").replace(",",""))
```
조합의 수


## 문제이름
https://www.acmicpc.net/problem/16926
### 문제풀이  
```python  
import sys  
  
N, M, R = map(int, sys.stdin.readline().rstrip().split())  
matrix = [list(map(int, sys.stdin.readline().rstrip().split())) for _ in range(N)]  
for rotate in range(R):  
    x1, x2, y1, y2 = 0, M - 1, 0, N - 1  
  while x1 < x2 and y1 < y2:  
        left_top = matrix[y1][x1]  
        # upper  
  for xx in range(x1, x2):  
            matrix[y1][xx] = matrix[y1][xx+1]  
        # right  
  for yy in range(y1, y2):  
            matrix[yy][x2] = matrix[yy+1][x2]  
        # lower  
  for xx in range(x2 - x1):  
            tmp_xx = x2 - xx  
            matrix[y2][tmp_xx] = matrix[y2][tmp_xx-1]  
        # left  
  for yy in range(y2 - y1):  
            tmp_yy = y2 - yy  
            matrix[tmp_yy][x1] = matrix[tmp_yy-1][x1]  
        # left_top  
  matrix[y1+1][x1] = left_top  
        x1, x2, y1, y2 = x1 + 1, x2 - 1, y1 + 1, y2 - 1  
for line in range(N):  
    print(' '.join(list(map(str,matrix[line]))))
```
배열을 돌릴 때에 돌릴 범위를 지정하고 이 범위 내에서 점점 한 칸씩 안으로 들어가며 반시계방향으로 돌리는 방식이다. 이런식의 문제에서 중요한 것은 항상 한 자리의 값은 덮어씌워져서 회전 이전에 미리 확보한 후(`left_top`), 마지막에 이 값을 넣어주는 부분인 것 같다.

### 의견
막상 풀고 제출을 눌러보니 이미 푼 문제였다.

## 랭킹전 대기열
https://www.acmicpc.net/problem/20006
### 문제풀이  
```python  
import sys  
p, m = map(int, sys.stdin.readline().rstrip().split())  
all_users = [  
    list(sys.stdin.readline().rstrip().split()) for _ in range(p)  
]  
all_rooms = []  
for i in range(len(all_users)):  
    tmp_user = [int(all_users[i][0]), all_users[i][1]]  
    now_room = False  
 for j in range(len(all_rooms)):  
        if all_rooms[j][0][0]-10 <= tmp_user[0] <= all_rooms[j][0][0]+10 and len(all_rooms[j]) < m:  
            now_room = True  
  all_rooms[j].append(tmp_user)  
            break  
 if not now_room:  
        all_rooms.append(  
            [tmp_user]  
        )  
for room in all_rooms:  
    if len(room) == m:  
        print("Started!")  
    else:  
        print("Waiting!")  
    room.sort(key=lambda x:x[1])  
    for user in room:  
        print("{} {}".format(user[0], user[1]))
```
일반적인 구현 문제였다.
