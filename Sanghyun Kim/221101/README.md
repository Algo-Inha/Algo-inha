# Solving

## 가장 긴 증가하는 부분 수열
https://www.acmicpc.net/problem/11053
### 문제풀이
```python
import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
a_ = [0 for _ in range(n)]

for i in range(n):
    for j in range(i):
        if a[i]>a[j] and a_[i]<a_[j]:
            a_[i] = a_[j]
    a_[i] += 1
print(max(a_))
```
a_ 리스트를 만들어 전체를 돌며 자신보다 작은 숫자들 중에 큰 길이에 1을 더한다.
### 의견
DP 문제, 생각하기 까다로운 문제였다.


## 시그널
https://www.acmicpc.net/problem/16113
### 문제풀이
```python
import sys
input = sys.stdin.readline

zero = ['#','#','#','#','#','#','.','.','.','#','#','#','#','#','#']
one = ['#','#','#','#','#']
two = ['#','.','#','#','#','#','.','#','.','#','#','#','#','.','#']
three = ['#','.','#','.','#','#','.','#','.','#','#','#','#','#','#']
four = ['#','#','#','.','.','.','.','#','.','.','#','#','#','#','#']
five = ['#','#','#','.','#','#','.','#','.','#','#','.','#','#','#']
six = ['#','#','#','#','#','#','.','#','.','#','#','.','#','#','#']
seven = ['#','.','.','.','.','#','.','.','.','.','#','#','#','#','#']
eight = ['#','#','#','#','#','#','.','#','.','#','#','#','#','#','#']
nine = ['#','#','#','.','#','#','.','#','.','#','#','#','#','#','#']
blank = ['.','.','.','.','.']

n = int(input())
data = list(input().rstrip())
length = len(data)
# list comprehension
number = [data[i * (length//5) : (i+1) *(length//5)] for i in range((length + (length//5) - 1)//(length//5))]
temp = []
ans = []
for i in range(length//5):
    for j in range(5):
        temp.append(number[j][i])
        #0과 1 구분해준다.
        if temp == zero:
            ans.append(0)
            temp = []
        elif temp == one and i<(length//5)-1:
            if number[j][i+1] == '.' :
                ans.append(1)
                temp = []
        elif temp == one and i == (length//5)-1 and j == 4:
            ans.append(1)
            temp = []
        elif temp == two:
            ans.append(2)
            temp = []
        elif temp == three:
            ans.append(3)
            temp = []
        elif temp == four:
            ans.append(4)
            temp = []
        elif temp == five:
            ans.append(5)
            temp = []
        elif temp == six:
            ans.append(6)
            temp = []
        elif temp == seven:
            ans.append(7)
            temp = []
        elif temp == eight:
            ans.append(8)
            temp = []
        elif temp == nine:
            ans.append(9)
            temp = []
        elif temp == blank:
            temp = []
for i in ans:
    print(int(i),end="")
```
0부터 9까지 숫자를 표시하는 값을 정의하여 같으면 값을 추가한다.
### 의견
열이 5로 동일한 2차원 배열을 만들수 있으면 풀 수 있는 문제였다.


## iSharp
https://www.acmicpc.net/problem/3568
### 문제풀이
```python
string = input()
string_list = string.split(' ')

basic_type = string_list[0]
del string_list[0]

for s in string_list:
    s = s.replace(",", '').replace(";", '')

    print(basic_type, end='')

    for i in range(len(s) - 1, 0, -1):
        if not s[i].isalpha():
            if s[i] == ']':
                print('[', end='')
            elif s[i] == '[':
                print(']', end='')
            else:
                print(s[i], end='')

    print(' ', end='')

    for i in range(len(s)):
        if s[i].isalpha():
            print(s[i], end='')

    print(';')
```
기본 변수형을 출력하고, 추가적인 변수형을 거꾸로 뒤집어 출력한다. 삭제했던 세미콜론을 마지막에 변수명과 함께 출력한다.
### 의견
파이썬 최고


## 봄버맨
https://www.acmicpc.net/problem/16918
### 문제풀이
```python
import sys
input = sys.stdin.readline

r, c, n = map(int, input().split())
board = [list(input().strip()) for i in range(r)]

if n<=1 :
    for li in board : print(''.join(li))
elif n%2==0 :
    for i in range(r): print('O'*c)
else :
    # 첫번째 폭탄이 터진 상태
    bombs1 = [['O']*c for i in range(r)]
    for y in range(r):
        for x in range(c):
            if board[y][x]=='O': bombs1[y][x] = '.'
            else :
                for i, j in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    if y+i>=0 and y+i<r and x+j>=0 and x+j<c and board[y+i][x+j]=='O':
                        bombs1[y][x] = '.'
                        break

    # 두번째 폭탄이 터진 상태
    bombs2 = [['O']*c for i in range(r)]
    for y in range(r):
        for x in range(c):
            if bombs1[y][x]=='O' : bombs2[y][x] = '.'
            else :
                for i, j in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    if y+i>=0 and y+i<r and x+j>=0 and x+j<c and bombs1[y+i][x+j]=='O':
                        bombs2[y][x] = '.'
                        break

    if n%4==3:
        for li in bombs1 : print(''.join(li))
    if n%4==1:
        for li in bombs2 : print(''.join(li))
```
짝수초 후엔 모든칸이 폭탄,
3, 7, 11, ... 초 후엔 처음 폭탄이 터지는 범위 밖에 폭탄
5, 9, 13, ... 초 후엔 두번째 폭탄 터지는 범위 밖에 폭탄
### 의견
까다로운 구현 문제