
# Solving﻿  

## 가장 긴 증가하는 부분수열
https://www.acmicpc.net/problem/11053
### 문제풀이  
```python  
import sys  
  
N = int(sys.stdin.readline().rstrip())  
all_list = list(map(int, sys.stdin.readline().rstrip().split()))  
all_figs = [0 for _ in range(N)]  
all_figs[0] = 1  
  
max_count = 0  
  
for i in range(1,N):  
    max_fig = 0  
  for j in range(i):  
        if all_list[j] < all_list[i] and all_figs[j] > max_fig:  
            max_fig = all_figs[j]  
    all_figs[i] = max_fig + 1  
  
print(max(all_figs))
```  
인덱스를 앞부터 진행하며 자신의 숫자까지 지속될 수 있는 가장 긴 수열의 길이를 구한다. 이를 반복하여 DP형태로 문제풀이를 진행했다.

### 의견  
2차원 배열을 통해 문제를 풀면 조금 더 빨라지지 않을까 생각했었지만, 깊이 생각해보니 별다를게 없는 속도일 것 같았다. 


## 랜선 자르기
https://www.acmicpc.net/problem/1654
### 문제풀이  
```python  
import sys  
  
  
def check_lan(dividend, param_arr):  
    all_fig = 0  
  for par in param_arr:  
        all_fig += (par // dividend)  
    return all_fig  
  
  
K, N = map(int, sys.stdin.readline().rstrip().split())  
all_arr = []  
for i in range(K):  
    all_arr.append(int(sys.stdin.readline().rstrip()))  
  
# 끝점을 2의 제곱수로 맞춤  
max_val = max(all_arr)  
end_ptr = 1  
while max_val > end_ptr:  
    end_ptr *= 2  
  
start_ptr = 0  
while end_ptr - start_ptr >= 2:  
    center_ptr = (end_ptr + start_ptr) // 2  
  if check_lan(center_ptr, all_arr) >= N:  
        start_ptr = center_ptr  
    else:  
        end_ptr = center_ptr  
  
if check_lan(end_ptr, all_arr) < N:  
    print(start_ptr)  
else:  
    print(end_ptr)
```  
시작점과 끝점을 두고 중간점을 구한 뒤, 중간점보다 더 잘게 잘라야 하면 끝점을 중간점으로, 아니면 시작점을 중간점으로 두고 다시 이분탐색하는 방식으로 진행하였다. 이분탐색 계산에 편리성을 더하기 위해 가장 큰 수를 구하고, 이 수보다 큰 수중 가장 작은 2의 제곱수를 끝점으로 두고 시작한다.

### 의견  
정말 거의 보지 못한 이분탐색 문제인데, 최근에 딱 한문제 푼게 사실상 처음으로 풀어본 해당 유형의 문제였다. 물론 그 문제와 정말 비슷한 구조를 가진 문제였기 때문에 생각해낼 수 있었지만, 실제 문제로 이런 문제를 받는다면 생각해내기에 어려움을 느낄 것 같다.


## 124 나라의 숫자
https://school.programmers.co.kr/learn/courses/30/lessons/12899
### 문제풀이  
```python  
def solution(n):  
    answer = ''  
  while n > 0:  
        tmp_mod = n % 3  
        if tmp_mod == 0:  
            n -= 1  
        answer = ['4','1','2'][tmp_mod] + answer  
        n //= 3  
  return answer
```  
3진법으로 나타내는 수이지만, 0이 없다는 것이 다르게 다가오는 문제이다. 가장 큰 수에 대해서는 0이 존재하는 4진법 (0,1,2,4) 이라고 볼 수 있고, 그 외의 숫자들에서는 0이 없는 3진법 (1,2,4)라고 둘 수 있다고 생각했다. 

### 의견  
겉보기엔 정말 간단하고, 문제를 이해하기도 정말 쉬웠으나 접근하는데에 있어 큰 어려움이 있었던 문제였다. 수를 변환하는 방법을 정말 여러가지를 생각하며 풀이를 진행하였다.


## 좌표 압축
https://www.acmicpc.net/problem/18870
### 문제풀이  
```python  
import sys  
N = int(sys.stdin.readline().rstrip())  
X = list(map(int, sys.stdin.readline().rstrip().split()))  
sorted_X = list(set(X))  
sorted_X.sort()  
sorted_X_idx = dict()  
for i in range(len(sorted_X)):  
    sorted_X_idx[sorted_X[i]] = i  
  
ret_str = ''  
for x in X:  
    ret_str += str(sorted_X_idx[x]) + " "  
print(ret_str[:-1])
```  
중복처리를 진행한 리스트를 sorting한 뒤, 특정 숫자가 몇 번 인덱스에 들어있는지 확인하는 코드이다. 중복처리는 O(N), 그 뒤에 본인의 수가 몇 번째 인덱스에 들어있는지를 O(N) 알고리즘으로 사용하면 O(N^2)로 느린 코드가 나오는 상황이라서, 자신이 몇 번째 인덱스에 있는지 확인하기 위해 Dict (`sorted_X_idx`) 로 두고 확인하였다. 

### 의견  
이것보다 빠른 방식은 없다고 생각했는데 계속 시간초과가 떴었는데, Pypy가 아닌 Python으로 바꾸니 통과하였다. 시간제한이 이상하게 잡혀있었던 문제였는데 이 것 때문에 고민하느라 시간을 많이 쓴 것 같다.



## 잃어버린 괄호
https://www.acmicpc.net/problem/1541
### 문제풀이  
```python  
import sys  
  
operator_arr = []  
operand_arr = []  
  
# input 전처리  
fir_str = sys.stdin.readline().rstrip()  
inp_str = fir_str.replace("+",".+.").replace("-",".-.").split(".")  
for i in range(len(inp_str)):  
    if inp_str[i] == "-":  
        operator_arr.append("-")  
    elif inp_str[i] == "+":  
        operator_arr.append("+")  
    else:  
        operand_arr.append(int(inp_str[i]))  
  
if len(operator_arr) == 0:  
    print(operand_arr[0])  
else:  
    minus_idx = -1  
  for i in range(len(operator_arr)):  
        if operator_arr[i] == "-":  
            minus_idx = i  
            break  
  
 if minus_idx == -1:  
        print(sum(operand_arr))  
    else:  
        front_val = 0  
  back_val = 0  
  for i in range(minus_idx+1):  
            front_val += operand_arr[i]  
        if minus_idx>=0:  
            for i in range(minus_idx+1,len(operand_arr)):  
                back_val += operand_arr[i]  
  
        print(front_val - back_val)
```  
문제 해결의 핵심은 `-`가 등장한 이후의 숫자는 모두 음수로 바꿀 수 있다는 점을 캐치하는 것이다. 따라서 -가 등장하기 전의 모든 수의 합을 **A**, -가 등장한 후의 모든 수의 합을 **B**라고 두면 단순히 `A-B`를 구하는 문제로 바뀐다.

### 의견
old 버젼의 코드를 보면 알 수 있겠지만, 처음엔 모든 부호에 대해 순열을 구하고 실제로 계산 순서를 모두 구해 진행했다. 시간초과가 발생하는데 채점현황에서 다른 사람들은 시간초과가 거의 없는 것을 보고 내가 접근을 전혀 잘못하고 있다고 생각했다.


